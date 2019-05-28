/*
 Copyright (C) 2018 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "util.h"

#define XC_GGA_X_CHACHIYO     298 /* Chachiyo exchange */

#pragma omp declare target

#include "maple2c/gga_exc/gga_x_chachiyo.c"
#include "work_gga_new.c"

const xc_func_info_type xc_func_info_gga_x_chachiyo = {
  XC_GGA_X_CHACHIYO,
  XC_EXCHANGE,
  "Chachiyo exchange",
  XC_FAMILY_GGA,
  {&xc_ref_Chachiyo2017, NULL, NULL, NULL, NULL},
  XC_FLAGS_3D | XC_FLAGS_I_HAVE_ALL,
  1e-25,
  0, NULL, NULL,
  NULL, NULL,
  NULL, work_gga, NULL
};

#pragma omp end declare target
