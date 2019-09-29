/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "xc_device.h"
#include "xc_extern.h"

#define XC_GGA_K_LLP          522 /* Lee, Lee & Parr */
#define XC_GGA_K_FR_B88       514 /* Fuentealba & Reyes (B88 version) */

typedef struct{
  double beta, gamma;
} gga_k_llp_params;


static void 
gga_k_llp_init(xc_func_type *p)
{
  gga_k_llp_params *params;

  assert(sizeof(gga_k_llp_params) <= XC_MAX_FUNC_PARAMS*sizeof(double));
  assert(p!=NULL);
  //p->params = malloc(sizeof(gga_k_llp_params));
  params = (gga_k_llp_params *) (p->params);
  
  /* value of beta in standard Becke 88 functional */
  switch(p->info->number){
  case XC_GGA_K_LLP:
    params->beta  = X_FACTOR_C*0.0044188;
    params->gamma = 0.0253/(X_FACTOR_C*0.0044188);
    break;
  case XC_GGA_K_FR_B88:
    params->beta  = X_FACTOR_C*0.004596;
    params->gamma = 0.02774/(X_FACTOR_C*0.004596);
    break;
  default:
    fprintf(stderr, "Internal error in gga_k_llp\n");
    exit(1);
  }
}

#include "maple2c/gga_exc/gga_k_llp.c"
#include "work_gga_new.c"
#include "work_gga_new.cu"

EXTERN const xc_func_info_type xc_func_info_gga_k_llp = {
  XC_GGA_K_LLP,
  XC_KINETIC,
  "Lee, Lee & Parr",
  XC_FAMILY_GGA,
  {&xc_ref_Lee1991_768, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-25,
  0, NULL, NULL,
  gga_k_llp_init, NULL,
  NULL, work_gga, NULL,
#ifndef __CUDACC__
  NULL, NULL, NULL
#else
  NULL, work_gga_offload, NULL
#endif
};

EXTERN const xc_func_info_type xc_func_info_gga_k_fr_b88 = {
  XC_GGA_K_FR_B88,
  XC_KINETIC,
  "Fuentealba & Reyes (B88 version)",
  XC_FAMILY_GGA,
  {&xc_ref_Fuentealba1995_31, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-25,
  0, NULL, NULL,
  gga_k_llp_init, NULL,
  NULL, work_gga, NULL,
#ifndef __CUDACC__
  NULL, NULL, NULL
#else
  NULL, work_gga_offload, NULL
#endif
};
