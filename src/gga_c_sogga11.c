/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "xc_device.h"
#include "xc_extern.h"

#define XC_GGA_C_SOGGA11       152 /* Second-order generalized gradient approximation 2011 */
#define XC_GGA_C_SOGGA11_X     159 /* To be used with HYB_GGA_X_SOGGA11_X  */

typedef struct {
  double sogga11_a[6], sogga11_b[6];
} gga_c_sogga11_params;

static const gga_c_sogga11_params par_sogga11 = {
  {0.50000, -4.62334,  8.00410, -130.226,  38.2685,   69.5599},
  {0.50000,   3.62334, 9.36393, 34.5114, -18.5684,   -0.16519}
};

static const gga_c_sogga11_params par_sogga11_x = {
  {0.50000, 78.2439,  25.7211,   -13.8830, -9.87375, -14.1357},
  {0.50000, -79.2439, 16.3725,   2.08129,  7.50769, -10.1861}
};

static void 
gga_c_sogga11_init(xc_func_type *p)
{
  gga_c_sogga11_params *params;

  assert(sizeof(gga_c_sogga11_params) <= XC_MAX_FUNC_PARAMS*sizeof(double));
  //assert(p!=NULL && p->params == NULL);
  //p->params = malloc(sizeof(gga_c_sogga11_params));
  params = (gga_c_sogga11_params *) (p->params);

  switch(p->info->number){
  case XC_GGA_C_SOGGA11:
    memcpy(params, &par_sogga11, sizeof(gga_c_sogga11_params));
    break;
  case XC_GGA_C_SOGGA11_X:
    memcpy(params, &par_sogga11_x, sizeof(gga_c_sogga11_params));
    break;
  default:
    fprintf(stderr, "Internal error in gga_c_sogga11\n");
    exit(1);
  } 
}

#include "maple2c/gga_exc/gga_c_sogga11.c"
#include "work_gga_new.c"
#include "work_gga_new.cpp"

EXTERN const xc_func_info_type xc_func_info_gga_c_sogga11 = {
  XC_GGA_C_SOGGA11,
  XC_CORRELATION,
  "Second-order generalized gradient approximation 2011",
  XC_FAMILY_GGA,
  {&xc_ref_Peverati2011_1991, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-23,
  0, NULL, NULL,
  gga_c_sogga11_init, NULL, 
  NULL, work_gga, NULL,
#ifndef __CUDACC__
  NULL, NULL, NULL
#else
  NULL, work_gga_offload, NULL
#endif
};

EXTERN const xc_func_info_type xc_func_info_gga_c_sogga11_x = {
  XC_GGA_C_SOGGA11_X,
  XC_CORRELATION,
  "To be used with HYB_GGA_X_SOGGA11_X",
  XC_FAMILY_GGA,
  {&xc_ref_Peverati2011_191102, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-23,
  0, NULL, NULL,
  gga_c_sogga11_init, NULL, 
  NULL, work_gga, NULL,
#ifndef __CUDACC__
  NULL, NULL, NULL
#else
  NULL, work_gga_offload, NULL
#endif
};
