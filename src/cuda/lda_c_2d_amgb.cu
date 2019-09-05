/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

/************************************************************************
 Correlation energy per particle and potentials for a homogeneous electron
 gas in 2D, as parametrized by Attaccalite et al.
************************************************************************/

#define XC_LDA_C_2D_AMGB  15   /* Attaccalite et al             */

#pragma omp declare target

#include "maple2c/lda_exc/lda_c_2d_amgb.c"
#include "work_lda_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_lda_c_2d_amgb = {
  XC_LDA_C_2D_AMGB,
  XC_CORRELATION,
  "AMGB (for 2D systems)",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Attaccalite2002_256601, NULL, NULL, NULL, NULL},
  XC_FLAGS_2D | XC_FLAGS_I_HAVE_ALL,
  1e-9,
  0, NULL, NULL,
  NULL, NULL,
  dvc_work_lda, NULL, NULL
};
#pragma omp end declare target
