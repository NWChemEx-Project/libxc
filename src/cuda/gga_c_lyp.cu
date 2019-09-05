/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_GGA_C_LYP    131  /* Lee, Yang & Parr */
#define XC_GGA_C_TM_LYP 559  /* Takkar and McCarthy reparametrization */

#pragma omp declare target

typedef struct{
  double A, B, c, d;
} gga_c_lyp_params;

DEVICE
void dvc_xc_gga_c_lyp_init(xc_func_type *p)
{
  gga_c_lyp_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(gga_c_lyp_params));
  params = (gga_c_lyp_params *) (p->params);      

  /* values of constants in standard LYP functional */
  switch(p->info->number){
  case XC_GGA_C_LYP:
    /* default set by set_ext_params */
    break;
  case XC_GGA_C_TM_LYP:
    params->A = 0.0393;
    params->B = 0.21;
    params->c = 0.41;
    params->d = 0.15;
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in gga_c_lyp\n");
    exit(1);
    #endif
    break;
  }
}

DEVICE
static const func_params_type dvc_ext_params[] = {
  {"_A", 0.04918, "Parameter A of LYP"},
  {"_B", 0.132,   "Parameter B of LYP"},
  {"_c", 0.2533,  "Parameter c of LYP"},
  {"_d", 0.349,   "Parameter d of LYP"},
};

DEVICE
static void 
dvc_set_ext_params(xc_func_type *p, const double *ext_params)
{
  gga_c_lyp_params *params;

  assert(p != NULL && p->params != NULL);
  params = (gga_c_lyp_params *) (p->params);

  params->A = dvc_get_ext_param(p->info->ext_params, ext_params, 0);
  params->B = dvc_get_ext_param(p->info->ext_params, ext_params, 1);
  params->c = dvc_get_ext_param(p->info->ext_params, ext_params, 2);
  params->d = dvc_get_ext_param(p->info->ext_params, ext_params, 3);
}

#include "maple2c/gga_exc/gga_c_lyp.c"
#include "work_gga_new.cu"

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_c_lyp = {
  XC_GGA_C_LYP,
  XC_CORRELATION,
  "Lee, Yang & Parr",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Lee1988_785, &dvc_xc_ref_Miehlich1989_200, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  4, dvc_ext_params, dvc_set_ext_params,
  dvc_xc_gga_c_lyp_init, NULL,
  NULL, dvc_work_gga, NULL
};

DEVICE
const xc_func_info_type dvc_xc_func_info_gga_c_tm_lyp = {
  XC_GGA_C_TM_LYP,
  XC_CORRELATION,
  "Takkar and McCarthy reparametrization",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Thakkar2009_134109, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  dvc_xc_gga_c_lyp_init, NULL,
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
