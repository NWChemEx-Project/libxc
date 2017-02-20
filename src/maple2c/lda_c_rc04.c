/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/lda_c_rc04.mpl
  Type of functional: work_lda
*/

static void
func0(const XC(func_type) *p, XC(lda_work_t) *r)
{
  double t2, t3, t5, t6, t8, t9, t10, t13;
  double t14, t17, t18, t19, t21, t27, t33, t42;


  t2 = 0.4888270e1 + 0.3177037e1 * r->rs;
  t3 = atan(t2);
  t5 = -0.655868e0 * t3 + 0.897889e0;
  t6 = 0.1e1 / r->rs;
  r->f = 0.1000e1 * t5 * t6;

  if(r->order < 1) return;

  t8 = t2 * t2;
  t9 = t8 + 0.1e1;
  t10 = 0.1e1 / t9;
  t13 = r->rs * r->rs;
  t14 = 0.1e1 / t13;
  r->dfdrs = -0.2083716903116000e1 * t10 * t6 - 0.1000e1 * t5 * t14;

  if(r->order < 2) return;

  t17 = t9 * t9;
  t18 = 0.1e1 / t17;
  t19 = t18 * t6;
  t21 = 0.31060429311980e2 + 0.20187128198738e2 * r->rs;
  t27 = 0.1e1 / t13 / r->rs;
  r->d2fdrs2 = 0.2083716903116000e1 * t19 * t21 + 0.4167433806232000e1 * t10 * t14 + 0.2000e1 * t5 * t27;

  if(r->order < 3) return;

  t33 = t21 * t21;
  t42 = t13 * t13;
  r->d3fdrs3 = -0.4167433806232000e1 / t17 / t9 * t6 * t33 - 0.6251150709348000e1 * t18 * t14 * t21 + 0.42064260253080020739e2 * t19 - 0.12502301418696000e2 * t10 * t27 - 0.6000e1 * t5 / t42;

  if(r->order < 4) return;


}

static void
func1(const XC(func_type) *p, XC(lda_work_t) *r)
{
  double t1, t2, t4, t5, t7, t8, t9, t11;
  double t12, t14, t15, t16, t17, t18, t19, t20;
  double t23, t24, t26, t27, t29, t31, t32, t34;
  double t35, t36, t38, t39, t45, t48, t51, t54;
  double t55, t56, t59, t61, t63, t64, t70, t81;
  double t112, t114;


  t1 = 0.10e1 + r->z;
  t2 = pow(t1, 0.66666666666666666667e0);
  t4 = 0.10e1 - r->z;
  t5 = pow(t4, 0.66666666666666666667e0);
  t7 = 0.5e0 * t2 + 0.5e0 * t5;
  t8 = t7 * t7;
  t9 = t8 * t7;
  t11 = 0.4888270e1 + 0.3177037e1 * r->rs;
  t12 = atan(t11);
  t14 = -0.655868e0 * t12 + 0.897889e0;
  t15 = t9 * t14;
  t16 = 0.1e1 / r->rs;
  r->f = t15 * t16;

  if(r->order < 1) return;

  t17 = t11 * t11;
  t18 = t17 + 0.1e1;
  t19 = 0.1e1 / t18;
  t20 = t9 * t19;
  t23 = r->rs * r->rs;
  t24 = 0.1e1 / t23;
  r->dfdrs = -0.2083716903116e1 * t20 * t16 - t15 * t24;
  t26 = t8 * t14;
  t27 = pow(t1, -0.33333333333333333333e0);
  t29 = pow(t4, -0.33333333333333333333e0);
  t31 = 0.33333333333333333334e0 * t27 - 0.33333333333333333334e0 * t29;
  t32 = t16 * t31;
  r->dfdz = 0.3e1 * t26 * t32;

  if(r->order < 2) return;

  t34 = t18 * t18;
  t35 = 0.1e1 / t34;
  t36 = t9 * t35;
  t38 = 0.31060429311980e2 + 0.20187128198738e2 * r->rs;
  t39 = t16 * t38;
  t45 = 0.1e1 / t23 / r->rs;
  r->d2fdrs2 = 0.2083716903116e1 * t36 * t39 + 0.4167433806232e1 * t20 * t24 + 0.2e1 * t15 * t45;
  t48 = t8 * t19;
  t51 = t24 * t31;
  r->d2fdrsz = -0.6251150709348e1 * t48 * t32 - 0.3e1 * t26 * t51;
  t54 = t7 * t14;
  t55 = t31 * t31;
  t56 = t16 * t55;
  t59 = pow(t1, -0.13333333333333333333e1);
  t61 = pow(t4, -0.13333333333333333333e1);
  t63 = -0.11111111111111111111e0 * t59 - 0.11111111111111111111e0 * t61;
  t64 = t16 * t63;
  r->d2fdz2 = 0.3e1 * t26 * t64 + 0.6e1 * t54 * t56;

  if(r->order < 3) return;

  t70 = t38 * t38;
  t81 = t23 * t23;
  r->d3fdrs3 = -0.4167433806232e1 * t9 / t34 / t18 * t16 * t70 - 0.6251150709348e1 * t36 * t24 * t38 + 0.42064260253080020739e2 * t36 * t16 - 0.12502301418696e2 * t20 * t45 - 0.6e1 * t15 / t81;
  r->d3fdrs2z = 0.6251150709348e1 * t8 * t35 * t39 * t31 + 0.12502301418696e2 * t48 * t51 + 0.6e1 * t26 * t45 * t31;
  r->d3fdrsz2 = -0.12502301418696e2 * t7 * t19 * t56 - 0.6251150709348e1 * t48 * t64 - 0.6e1 * t54 * t24 * t55 - 0.3e1 * t26 * t24 * t63;
  t112 = pow(t1, -0.23333333333333333333e1);
  t114 = pow(t4, -0.23333333333333333333e1);
  r->d3fdz3 = 0.6e1 * t55 * t31 * t14 * t16 + 0.18e2 * t54 * t32 * t63 + 0.3e1 * t26 * t16 * (0.14814814814814814814e0 * t112 - 0.14814814814814814814e0 * t114);

  if(r->order < 4) return;


}

void 
XC(lda_c_rc04_func)(const XC(func_type) *p, XC(lda_work_t) *r)
{
  if(p->nspin == XC_UNPOLARIZED)
    func0(p, r);
  else
    func1(p, r);
}

#define maple2c_order 3
#define maple2c_func  XC(lda_c_rc04_func)
