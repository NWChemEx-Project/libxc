/*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "xc_device.h"
#include "xc_extern.h"

#define XC_GGA_X_HJS_B88_V2   46 /* HJS screened exchange corrected B88 version */

typedef struct{
  double omega;
} gga_x_hjs_b88_v2_params;

static void
gga_x_hjs_init(xc_func_type *p)
{
  assert(sizeof(gga_x_hjs_b88_v2_params) <= XC_MAX_FUNC_PARAMS*sizeof(double));
  assert(p != NULL);
  //p->params = malloc(sizeof(gga_x_hjs_b88_v2_params));
}

static func_params_type ext_params[] = {
  {"_omega", 0.11, "Screening parameter for HF"},
};

static void 
set_ext_params(xc_func_type *p, const double *ext_params)
{
  gga_x_hjs_b88_v2_params *params;

  assert(sizeof(gga_x_hjs_b88_v2_params) <= XC_MAX_FUNC_PARAMS*sizeof(double));
  assert(p != NULL);
  params = (gga_x_hjs_b88_v2_params *) (p->params);

  params->omega = get_ext_param(p->info->ext_params, ext_params, 0);
}

#include "maple2c/gga_exc/gga_x_hjs_b88_v2.c"
#include "work_gga_new.c"
#include "work_gga_new.cpp"

EXTERN const xc_func_info_type xc_func_info_gga_x_hjs_b88_v2 = {
  XC_GGA_X_HJS_B88_V2,
  XC_EXCHANGE,
  "HJS screened exchange B88 corrected version",
  XC_FAMILY_GGA,
  {&xc_ref_Weintraub2009_754, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-6, /* densities smaller than 1e-6 yield NaNs */
  1, ext_params, set_ext_params,
  gga_x_hjs_init, NULL, 
  NULL, work_gga, NULL,
#ifndef __CUDACC__
  NULL, NULL, NULL
#else
  NULL, work_gga_offload, NULL
#endif
};
