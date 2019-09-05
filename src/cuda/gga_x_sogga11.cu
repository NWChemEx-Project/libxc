/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "dvc_util.h"

#define XC_GGA_X_SOGGA11        151 /* Second-order generalized gradient approximation 2011 */
#define XC_HYB_GGA_X_SOGGA11_X  426 /* Hybrid based on SOGGA11 form */

#pragma omp declare target

typedef struct{
  double kappa, mu, a[6], b[6];
} gga_x_sogga11_params;

DEVICE
static const gga_x_sogga11_params dvc_par_sogga11 = {
  0.552, MU_GE, 
  {0.50000, -2.95535,  15.7974, -91.1804,  96.2030, 0.18683},
  {0.50000,  3.50743, -12.9523,  49.7870, -33.2545, -11.1396}
};

/* These coefficients include the factor (1-X) in the functional definition. */
DEVICE
static const gga_x_sogga11_params dvc_par_sogga11_x = {
  0.552, MU_GE, 
  {0.29925,  3.21638, -3.55605,  7.65852, -11.2830, 5.25813},
  {0.29925, -2.88595,  3.23617, -2.45393, -3.75495,  3.96613}
};

DEVICE
static void 
dvc_gga_x_sogga11_init(xc_func_type *p)
{
  gga_x_sogga11_params *params;

  assert(p!=NULL && p->params == NULL);
  p->params = malloc(sizeof(gga_x_sogga11_params));
  params = (gga_x_sogga11_params *) (p->params);

  switch(p->info->number){
  case XC_GGA_X_SOGGA11:
    memcpy(params, &dvc_par_sogga11, sizeof(gga_x_sogga11_params));
    break;
  case XC_HYB_GGA_X_SOGGA11_X:
    memcpy(params, &dvc_par_sogga11_x, sizeof(gga_x_sogga11_params));
    p->cam_alpha = 0.4015;
    break;
  default:
    #ifndef __CUDACC__
    fprintf(stderr, "Internal error in gga_x_sogga11\n");
    exit(1);
    #endif
    break;
  }
}

#include "maple2c/gga_exc/gga_x_sogga11.c"
#include "work_gga_new.cu"


DEVICE
const xc_func_info_type dvc_xc_func_info_gga_x_sogga11 = {
  XC_GGA_X_SOGGA11,
  XC_EXCHANGE,
  "Second-order generalized gradient approximation 2011",
  XC_FAMILY_GGA,
  {&dvc_xc_ref_Peverati2011_1991, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  dvc_gga_x_sogga11_init, NULL,
  NULL, dvc_work_gga, NULL
};

DEVICE
const xc_func_info_type dvc_xc_func_info_hyb_gga_x_sogga11_x = {
  XC_HYB_GGA_X_SOGGA11_X,
  XC_EXCHANGE,
  "Hybrid based on SOGGA11 form",
  XC_FAMILY_HYB_GGA,
  {&dvc_xc_ref_Peverati2011_191102, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  dvc_gga_x_sogga11_init, NULL,
  NULL, dvc_work_gga, NULL
};

#pragma omp end declare target
