/*
 Copyright (C) 2013 Rolf Wuerdemann, M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define  XC_HYB_GGA_XC_LCY_PBE 467  /* PBE with yukawa screening */

DEVICE void
dvc_xc_hyb_gga_xc_lcy_pbe_init(xc_func_type *p)
{
  static int   funcs_id  [2] = {XC_GGA_X_SFAT_PBE, XC_GGA_C_PBE};
  static double funcs_coef[2];

  double gamma = 0.75;

  funcs_coef[0] = 1.0;
  funcs_coef[1] = 1.0;

  dvc_xc_mix_init(p, 2, funcs_id, funcs_coef);

  dvc_xc_func_set_ext_params(p->func_aux[0], &gamma);
  
  p->cam_omega = gamma;
  p->cam_alpha = 1.0;
  p->cam_beta  = -1.0;
}

DEVICE
const xc_func_info_type dvc_xc_func_info_hyb_gga_xc_lcy_pbe = {
  XC_HYB_GGA_XC_LCY_PBE,
  XC_EXCHANGE_CORRELATION,
  "LCY version of PBE",
  XC_FAMILY_HYB_GGA,
  {&dvc_xc_ref_Seth2012_901, &dvc_xc_ref_Seth2013_2286, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_HYB_LCY | XC_FLAGS_HAVE_EXC | XC_FLAGS_I_HAVE_VXC,
  1e-32,
  0, NULL, NULL,
  dvc_xc_hyb_gga_xc_lcy_pbe_init, NULL,
  NULL, NULL, NULL
};
