/*
 Copyright (C) 2017 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"
#include "xc_device.h"
#include "xc_extern.h"

#define XC_GGA_C_REGTPSS       83 /* Regularized TPSS correlation (ex-VPBE)             */

#include "maple2c/gga_exc/gga_c_regtpss.c"
#include "work_gga_new.c"
#include "work_gga_new.cpp"

EXTERN const xc_func_info_type xc_func_info_gga_c_regtpss = {
  XC_GGA_C_REGTPSS,
  XC_CORRELATION,
  "regularized TPSS correlation",
  XC_FAMILY_GGA,
  {&xc_ref_Perdew2009_026403, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-16,
  0, NULL, NULL,
  NULL, NULL, 
  NULL, work_gga, NULL,
#ifndef __CUDACC__
  NULL, NULL, NULL
#else
  NULL, work_gga_offload, NULL
#endif
};
