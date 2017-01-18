#!/usr/bin/env perl

my $srcdir     = $ARGV[0];
my $functional = $ARGV[1];
my $max_order  = $ARGV[2];

# Find out the type of functional
my $mathfile = "$srcdir/maple/$functional.mpl";
open my $in, '<', $mathfile or die "File $mathfile does not exist\n";

my $functype = "";
my $prefix   = "";
while($_ = <$in>){
  if(/^\(\* type:\s(\S*)\s/){
    $functype = $1;
  };
  if(/^\(\* prefix:/){
    while( ($_ = <$in>) && ! /^\*\)/ ){
      $prefix .= $_;
    }
  }
}
close($in);

open my $out, '>', "$srcdir/src/maple2c/$functional.c" or 
    die "Could not open file $srcdir/maple2c/$functional.c for writing\n";

print $out "/* 
  This file was generated automatically with $0.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : $mathfile
  Type of functional: $functype
*/
";

my %commands = (
  "work_lda"     => \&work_lda,
  "work_gga_x"   => \&work_gga_x,
  "work_mgga_x"  => \&work_mgga_x,
    );

if ($commands{$functype}) {
  $commands{$functype}->($max_order, $prefix);
} else {
  die "No such type: $string\n";
} 

sub math_replace {
  # The replacements have to be made in order, so
  # we can not use a hash table
  my @math_replace = (
    "_s_"    , "*",
    "_a_"    , "->",
    "_d_"    , ".",
    "Warning.*", "",
  );
  my ($text) = @_;

  for(my $j=0; $j<$#math_replace; $j+=2){
    $text =~ s/$math_replace[$j]/$math_replace[$j+1]/g;
  }

  return $text;
}

sub math_work {
  my ($info, $out, $order, $text_order) = @_;

  my $i = 0;
  my $cmd = "[";
  foreach my $ninfo (@{$info}){
    last if($i > $order);

    # generate the derivatives to generate
    foreach my $der (@{$ninfo}){
      $cmd .= ", " if($cmd ne "[");
      $cmd .= @{$der}[0]." = ".@{$der}[1];
    }

    $i++;
  }
  $cmd .= "]";

  # save maple file
  open($mfile, ">/tmp/$$.mpl");
  printf $mfile "%s", "
Digits := 20:
\$include <util.mpl>

\$include <$functional.mpl>

with(CodeGeneration):
  C($cmd, optimize, defaulttype=numeric, precision=double, resultname=result_f);
";
  close($mfile);

  # run maple
  my $c_code = `maple -q -u /tmp/$$.mpl`;
  #unlink "/tmp/$$.mpl";

  # find all variables defined
  my $new_c_code = "";
  my $variables  = "";
  my $n_var = 0;

  for (split /^/, $c_code) {
    my $found = 0;
    my $i = 1;
    foreach my $ninfo (@{$info}){
      if(/@{@{$ninfo}[-1]}[0]\s+=/){
        $new_c_code .= "  ".$_."\n  if($text_order < $i) return;\n\n";
        $found = 1;
      }
      $i++;
    }

    if(($found == 0) && ($_ =~ /^(t\d+) =/)){
      if($n_var % 8 == 0){
        $variables .= ";\n" if($n_var != 0);
        $variables .= "  double ";
      }else{
        $variables .= ", ";
      }
      $n_var++;

      $variables .= "$1";
      $new_c_code .= "  ".$_;
    }elsif($found == 0){
      $new_c_code .= "  ".$_;
    }	
  }
  $variables .= ";\n" if($n_var != 0);

  return ($variables, math_replace($new_c_code));
}

sub work_lda {
  ($order, $prefix) = @_;

  for(my $ispin=0; $ispin<2; $ispin++){
    my $f = ($ispin==0) ? "f(r_a_rss, 0.0)" : "f(r_a_rss, r_a_zeta)";
    my $info = [
      [
       ["r_a_zk", "$f"]
      ], [
        ["r_a_dedrs", "diff($f, r_a_rss)"],
        ["r_a_dedz",  "diff($f, r_a_z)"]
      ], [
        ["r_a_d2edrs2", "diff($f, r_a_rss\$2)"], 
        ["r_a_d2edz2",  "diff($f, r_a_z\$2 )"],
        ["r_a_d2edrsz", "diff($f, r_a_rss, r_a_z)"]
      ], [
        ["r_a_d3edrs3",  "diff($f, r_a_rss\$3)"], 
        ["r_a_d3edz3",   "diff($f, r_a_z\$3 )"],
        ["r_a_d3edrs2z", "diff($f, r_a_rss\$2, r_a_z)"],
        ["r_a_d3edrsz2", "diff($f, r_a_rss, r_a_z\$2)"]
      ]
    ];

    ($variables, $c_code) = math_work($info, $out, $order, "r->order");

    print $out "
static void
func$ispin(const XC(func_type) *p, XC(lda_work_t) *r)
{
$variables
$prefix
$c_code
}
";
  }

  # now we print the c file
  print $out "
void 
XC(${functional}_func)(const XC(func_type) *p, XC(lda_work_t) *r)
{
  if(p->nspin == XC_UNPOLARIZED)
    func0(p, r);
  else
    func1(p, r);
}

#define maple2c_order $max_order
#define maple2c_func  XC(${functional}_func)
";
}


sub work_gga_x {
  ($order, $prefix) = @_;

  my $info = [
    [['_s_f',      'f(x)']], 
    [['_s_dfdx',   'diff(f(x),x)']], 
    [['_s_d2fdx2', 'diff(f(x),x$2)']], 
    [['_s_d3fdx3', 'diff(f(x),x$3)']],
    [['_s_d4fdx4', 'diff(f(x),x$4)']]
  ];

  ($variables, $c_code) = math_work($info, $out, $order, "order");

  # now we print the c file
  print $out "
void XC(${functional}_enhance)
  (const XC(func_type) *p, int order, 
   FLOAT x, FLOAT *f, FLOAT *dfdx, FLOAT *d2fdx2, FLOAT *d3fdx3)
{
$variables
$prefix
$c_code
}

#define maple2c_order $max_order
#define maple2c_func  XC(${functional}_enhance)
";
}

sub work_mgga_x {
  ($order, $prefix) = @_;

  my $f = "f(r_a_rs, r_a_x, r_a_t, r_a_u)";
  my $info = [
    [
      ["r_a_f", "$f"]
    ], [
      ["r_a_dfdrs", "diff($f, r_a_rs)"],
      ["r_a_dfdx",  "diff($f, r_a_x)"], 
      ["r_a_dfdt",  "diff($f, r_a_t)"], 
      ["r_a_dfdu",  "diff($f, r_a_u)"]
    ], [
      ["r_a_d2fdrs2", "diff($f, r_a_rs\$2)"], 
      ["r_a_d2fdx2",  "diff($f, r_a_x\$2 )"], 
      ["r_a_d2fdt2",  "diff($f, r_a_t\$2 )"], 
      ["r_a_d2fdu2",  "diff($f, r_a_u\$2 )"], 
      ["r_a_d2fdrsx", "diff($f, r_a_rs, r_a_x)"], 
      ["r_a_d2fdrst", "diff($f, r_a_rs, r_a_t)"], 
      ["r_a_d2fdrsu", "diff($f, r_a_rs, r_a_u)"], 
      ["r_a_d2fdxt",  "diff($f,  r_a_x, r_a_t)"], 
      ["r_a_d2fdxu",  "diff($f,  r_a_x, r_a_u)"], 
      ["r_a_d2fdtu",  "diff($f,  r_a_t, r_a_u)"], 
    ]
  ];

  ($variables, $c_code) = math_work($info, $out, $order, "r->order");

  # now we print the c file
  print $out "
static void 
XC(${functional}_enhance)(const XC(func_type) *pt, XC(mgga_work_x_t) *r)
{
$variables
$prefix
$c_code
}

#define maple2c_order $max_order
#define maple2c_func  XC(${functional}_enhance)
";
}


