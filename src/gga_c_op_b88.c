/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"

#define XC_GGA_C_OP_B88      87 /* one-parameter progressive functional (B88 version)     */

#pragma omp declare target

#include "maple2c/gga_exc/gga_c_op_b88.c"
#include "work_gga_new.c"

const xc_func_info_type xc_func_info_gga_c_op_b88 = {
  XC_GGA_C_OP_B88,
  XC_CORRELATION,
  "one-parameter progressive functional (B88 version)",
  XC_FAMILY_GGA,
  {&xc_ref_Tsuneda1999_10664, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-32,
  0, NULL, NULL,
  NULL, NULL, 
  NULL, work_gga, NULL
};

#pragma omp end declare target
