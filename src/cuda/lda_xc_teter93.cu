/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#include "util.h"
#include "dvc_util.h"

#define XC_LDA_XC_TETER93     20   /* Teter 93 parametrization                */

#pragma omp declare target

#include "maple2c/lda_exc/lda_xc_teter93.c"
#include "work_lda_new.cu"

DEVICE const xc_func_info_type dvc_xc_func_info_lda_xc_teter93 = {
  XC_LDA_XC_TETER93,
  XC_EXCHANGE_CORRELATION,
  "Teter 93",
  XC_FAMILY_LDA,
  {&dvc_xc_ref_Goedecker1996_1703, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-24,
  0, NULL, NULL,
  NULL,     /* init */
  NULL,     /* end  */
  dvc_work_lda, /* lda  */
  NULL,
  NULL
};

#pragma omp end declare target
