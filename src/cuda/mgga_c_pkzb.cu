/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_MGGA_C_PKZB          239 /* Perdew, Kurth, Zupan, and Blaha */

#pragma omp declare target

#include "maple2c/mgga_exc/mgga_c_pkzb.c"
#include "work_mgga_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_mgga_c_pkzb = {
  XC_MGGA_C_PKZB,
  XC_CORRELATION,
  "Perdew, Kurth, Zupan, and Blaha",
  XC_FAMILY_MGGA,
  {&dvc_xc_ref_Perdew1999_2544, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-13, /* densities smaller than 1e-26 give NaNs */
  0, NULL, NULL,
  NULL, NULL, 
  NULL, NULL, dvc_work_mgga,
};

#pragma omp end declare target

