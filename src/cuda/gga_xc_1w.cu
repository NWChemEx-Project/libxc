/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_XC_XLYP       166  /* XLYP functional */
#define XC_GGA_XC_PBE1W      173  /* Functionals fitted for water */
#define XC_GGA_XC_MPWLYP1W   174  /* Functionals fitted for water */
#define XC_GGA_XC_PBELYP1W   175  /* Functionals fitted for water */

#pragma omp declare target

DEVICE
static void
dvc_gga_xc_xlyp_init(xc_func_type *p)
{
  static int   funcs_id  [4] = {XC_LDA_X, XC_GGA_X_B88, XC_GGA_X_PW91, XC_GGA_C_LYP};
  static double funcs_coef[4] = {1.0 - 0.722 - 0.347, 0.722, 0.347, 1.0};

  dvc_xc_mix_init(p, 4, funcs_id, funcs_coef);
}

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_xc_xlyp = {
  XC_GGA_XC_XLYP,
  XC_EXCHANGE_CORRELATION,
  "XLYP",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Xu2004_2673, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  dvc_gga_xc_xlyp_init, 
  NULL, NULL, NULL, NULL
};


DEVICE
static void
dvc_gga_xc_pbe1w_init(xc_func_type *p)
{
  static int   funcs_id  [3] = {XC_LDA_C_VWN, XC_GGA_X_PBE, XC_GGA_C_PBE};
  static double funcs_coef[3] = {1.0 - 74.0/100.0, 1.0, 74.0/100.0};

  dvc_xc_mix_init(p, 3, funcs_id, funcs_coef);
}

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_xc_pbe1w = {
  XC_GGA_XC_PBE1W,
  XC_EXCHANGE_CORRELATION,
  "PBE1W",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Dahlke2005_15677, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  dvc_gga_xc_pbe1w_init, 
  NULL, NULL, NULL, NULL
};


DEVICE
static void
dvc_gga_xc_mpwlyp1w_init(xc_func_type *p)
{
  static int   funcs_id  [3] = {XC_LDA_C_VWN, XC_GGA_X_MPW91, XC_GGA_C_LYP};
  static double funcs_coef[3] = {1.0 - 88.0/100.0, 1.0, 88.0/100.0};

  dvc_xc_mix_init(p, 3, funcs_id, funcs_coef);
}

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_xc_mpwlyp1w = {
  XC_GGA_XC_MPWLYP1W,
  XC_EXCHANGE_CORRELATION,
  "mPWLYP1w",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Dahlke2005_15677, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  dvc_gga_xc_mpwlyp1w_init, 
  NULL, NULL, NULL, NULL
};


DEVICE
static void
dvc_gga_xc_pbelyp1w_init(xc_func_type *p)
{
  static int   funcs_id  [3] = {XC_LDA_C_VWN, XC_GGA_X_PBE, XC_GGA_C_LYP};
  static double funcs_coef[3] = {1.0 - 74.0/100.0, 1.0, 74.0/100.0};

  dvc_xc_mix_init(p, 3, funcs_id, funcs_coef);
}

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_xc_pbelyp1w = {
  XC_GGA_XC_PBELYP1W,
  XC_EXCHANGE_CORRELATION,
  "PBELYP1W",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Dahlke2005_15677, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  dvc_gga_xc_pbelyp1w_init, 
  NULL, NULL, NULL, NULL
};

#pragma omp end declare target
