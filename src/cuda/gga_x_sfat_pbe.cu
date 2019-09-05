/*
 Copyright (C) 2013 Rolf Wuerdemann, M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_GGA_X_SFAT_PBE 601 /* short-range recipe for PBE functional */
/* see
   Savin, Flad, Int. J. Quant. Chem. Vol. 56, 327-332 (1995)
   Akinaga, Ten-no, Chem. Phys. Lett. 462 (2008) 348-351
*/

#pragma omp declare target

DEVICE
static const func_params_type dvc_ext_params[] = {
  {"_omega", 0.44, "Screening parameter"},
};

DEVICE
static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  p->cam_omega = dvc_get_ext_param(p->info->ext_params, ext_params, 0);
}

#include "maple2c/gga_exc/gga_x_sfat_pbe.c"
#include "work_gga_new.cu"

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_sfat_pbe = {
  XC_GGA_X_SFAT_PBE,
  XC_EXCHANGE,
  "Short-range recipe for PBE functional - Yukawa",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Savin1995_327, &dvc_xc_ref_Akinaga2008_348, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-19,
  1, dvc_ext_params, dvc_set_ext_params,
  NULL, NULL,
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target

