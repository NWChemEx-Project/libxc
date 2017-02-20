/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.
  
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.
  
 You should have received a copy of the GNU Lesser General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


#include "util.h"

void 
XC(lda_stoll) (const XC(func_type) *pw, XC(lda_func_type) lda_func,
  FLOAT dens, FLOAT zeta, int order, XC(lda_work_t) res[3])
{
  static const FLOAT sign[2] = {1.0, -1.0};
  int is;
  FLOAT opz[2] = {1.0 + zeta, 1.0 - zeta};

  res[2].rs  = RS(dens);

  /* first we get the parallel contributions */
  for(is=0; is<2; is++){
    FLOAT opz13;

    if(opz[is] < pw->info->min_zeta){
      res[is].f = 0.0;
      if(order >= 1) res[is].dfdz = res[is].dfdrs = 0.0;
      if(order >= 2) res[is].d2fdrs2 = res[is].d2fdrsz = res[is].d2fdz2 = 0.0;
    }else{
      FLOAT drssdrs, drssdz, d2rssdrsz, d2rssdz2;
      FLOAT LDA_f, LDA_dfdrs, LDA_d2fdrs2;

      opz13 = CBRT(opz[is]);

      res[is].rs    = RS(dens*opz[is]/2.0);
      res[is].z     = sign[is];
      res[is].order = order;
  
      lda_func(pw, &(res[is]));

      LDA_f = res[is].f;

      res[is].f *= opz[is]/2.0;
      
      if(order < 1) continue;

      LDA_dfdrs = res[is].dfdrs;
      drssdrs   = M_CBRT2/opz13;
      drssdz    = -sign[is]*res[is].rs/(3.0*opz[is]);

      res[is].dfdrs = LDA_dfdrs*drssdrs*opz[is]/2.0;
      res[is].dfdz  = LDA_f*sign[is]/2.0 + LDA_dfdrs*drssdz*opz[is]/2.0;

      if(order < 2) continue;

      LDA_d2fdrs2 = res[is].d2fdrs2;
      d2rssdrsz   = -sign[is]*M_CBRT2/(3.0*opz13*opz[is]);
      d2rssdz2    = res[is].rs*4.0/(9.0*opz[is]*opz[is]);

      res[is].d2fdrs2 = LDA_d2fdrs2*drssdrs*drssdrs*opz[is]/2.0;
      res[is].d2fdrsz = sign[is]*LDA_dfdrs*drssdrs/2.0 + (LDA_d2fdrs2*drssdrs*drssdz + LDA_dfdrs*d2rssdrsz)*opz[is]/2.0;
      res[is].d2fdz2  = sign[is]*LDA_dfdrs*drssdz + (LDA_d2fdrs2*drssdz*drssdz + LDA_dfdrs*d2rssdz2)*opz[is]/2.0;
    }
  }

  /* and now the perpendicular */
  res[is].z     = zeta;
  res[is].order = order;

  lda_func(pw, &(res[2]));

  res[2].f -= res[0].f + res[1].f;

  if(order < 1) return;

  res[2].dfdrs -= res[0].dfdrs + res[1].dfdrs;
  res[2].dfdz  -= res[0].dfdz  + res[1].dfdz;

  if(order < 2) return;

  res[2].d2fdrs2 -= res[0].d2fdrs2 + res[1].d2fdrs2;
  res[2].d2fdrsz -= res[0].d2fdrsz + res[1].d2fdrsz;
  res[2].d2fdz2  -= res[0].d2fdz2  + res[1].d2fdz2;
}


void 
XC(pbe_c_stoll) (const XC(func_type) *pbe, int get_max, const XC(mgga_work_c_t) *in, XC(gga_work_c_t) out[3])
{
  static const FLOAT sign[2] = {1.0, -1.0};
  int is;
  FLOAT opz[2] = {1.0 + in->zeta, 1.0 - in->zeta};

  /* first we get the perpendicular contributions */
  out[2].order = in->order;
  out[2].dens  = in->dens;
  out[2].rs    = in->rs;
  out[2].z     = in->zeta;
  out[2].xt    = in->xt;
  out[2].xs[0] = in->xs[0];
  out[2].xs[1] = in->xs[1];

  if(pbe->info->number == XC_GGA_C_PBELOC)
    XC(gga_c_pbeloc_func) (pbe, &(out[2]));
  else if(pbe->info->number == XC_GGA_C_REGTPSS)
    XC(gga_c_regtpss_func) (pbe, &(out[2]));
  else
    XC(gga_c_pbe_func) (pbe, &(out[2]));

  /* and now the parallel contributions */
  for(is=0; is<2; is++){
    FLOAT opz13;

    if(in->ds[is] < pbe->info->min_dens){
      out[is].f = 0.0;
      if(in->order >= 1){
	out[is].dfdrs = out[is].dfdz = out[is].dfdxt = 0.0;
	out[is].dfdxs[0] = out[is].dfdxs[1] = 0.0;
      }
    }else{
      FLOAT drssdrs, drssdz;
      FLOAT GGA_f, GGA_dfdrs;

      opz13 = CBRT(opz[is]);

      out[is].order = in->order;
      out[is].dens  = in->ds[is];
      out[is].rs    = RS(out[is].dens);
      out[is].z     = sign[is];
      out[is].xt    = (is == 0) ? in->xs[0] : in->xs[1];
      out[is].xs[0] = (is == 0) ? in->xs[0] : 0.0;
      out[is].xs[1] = (is == 1) ? in->xs[1] : 0.0;
  
      if(pbe->info->number == XC_GGA_C_PBELOC)
        XC(gga_c_pbeloc_func) (pbe, &(out[is]));
      else if(pbe->info->number == XC_GGA_C_REGTPSS)
        XC(gga_c_regtpss_func) (pbe, &(out[is]));
      else
        XC(gga_c_pbe_func) (pbe, &(out[is]));

      if(get_max && out[is].f < out[2].f){
	/* perform maximum operation */
	out[is].f = out[2].f;

	if(in->order >= 1){
	  out[is].dfdrs    = out[2].dfdrs;
	  out[is].dfdz     = out[2].dfdz;
	  out[is].dfdxs[0] = out[2].dfdxs[0];
	  out[is].dfdxs[1] = out[2].dfdxs[1];
	  out[is].dfdxt    = out[2].dfdxt;
	}
      }else{
	if(in->order >= 1){
	  GGA_dfdrs = out[is].dfdrs;

	  drssdrs   = M_CBRT2/opz13;
	  drssdz    = -sign[is]*out[is].rs/(3.0*opz[is]);
	
	  out[is].dfdrs = GGA_dfdrs*drssdrs;
	  out[is].dfdz  = GGA_dfdrs*drssdz;
	  if(is == 0){
	    out[is].dfdxs[0] += out[is].dfdxt;
	    out[is].dfdxs[1]  = 0.0;
	  }else{
	    out[is].dfdxs[0]  = 0.0;
	    out[is].dfdxs[1] += out[is].dfdxt;
	  }
	  out[is].dfdxt = 0.0;
	}
      }

      /* take care of the opz[is]/2 factor */
      GGA_f = out[is].f;

      out[is].f *= opz[is]/2.0;
      
      if(in->order < 1) continue;

      out[is].dfdrs    = out[is].dfdrs*opz[is]/2.0;
      out[is].dfdz     = GGA_f*sign[is]/2.0 + out[is].dfdz*opz[is]/2.0;
      out[is].dfdxs[0] = out[is].dfdxs[0]*opz[is]/2.0;
      out[is].dfdxs[1] = out[is].dfdxs[1]*opz[is]/2.0;
      out[is].dfdxt    = out[is].dfdxt*opz[is]/2.0;

      if(in->order < 2) continue;
    }
  }
}
