/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/gga_c_lm.mpl
  Type of functional: work_gga_c
*/

void XC(gga_c_lm_func)
  (const XC(func_type) *p, XC(gga_work_c_t) *r)
{
  double t3, t4, t6, t7, t9, t10, t12, t15;
  double t16, t18, t19, t21, t23, t25, t26, t31;
  double t33, t34, t35, t36, t38, t39, t40, t41;
  double t42, t43, t44, t47, t50, t53, t57, t58;
  double t60, t62, t67, t71, t76, t77, t78, t79;
  double t82, t84, t86, t89, t90, t92, t94, t95;
  double t102, t105, t108, t111, t113, t116, t120, t121;
  double t122, t125, t126, t127, t128, t129, t130, t132;
  double t139, t140, t141, t144, t149, t150, t151, t153;
  double t154, t160, t161, t166, t169, t172, t174, t176;
  double t178, t180, t182, t184, t185, t186, t189, t191;
  double t193, t194, t201, t208, t216, t219, t225, t227;
  double t229, t230, t231, t234, t236, t241, t260, t284;
  double t287, t327, t329, t344, t346;


  t3 = r->rs * r->rs;
  t4 = t3 * r->rs;
  t6 = 0.10e1 + 0.37037037037037037036e-4 * t4;
  t7 = 0.1e1 / r->rs;
  t9 = 0.10e1 + 0.30000000000000000000e2 * t7;
  t10 = log(t9);
  t12 = 0.252e-1 * t6 * t10;
  t15 = 0.10e1 + r->z;
  t16 = pow(t15, 0.13333333333333333333e1);
  t18 = 0.10e1 - r->z;
  t19 = pow(t18, 0.13333333333333333333e1);
  t21 = 0.19236610509315363199e1 * t16 + 0.19236610509315363199e1 * t19 - 0.38473221018630726398e1;
  t23 = 0.10e1 + 0.23703703703703703702e-5 * t4;
  t25 = 0.10e1 + 0.75000000000000000002e2 * t7;
  t26 = log(t25);
  t31 = -0.127e-1 * t23 * t26 - 0.25742222222222222222e-4 * t3 + 0.33533333333333333332e-3 * r->rs - 0.41666666666666666666e-2 + t12;
  t33 = r->xt * r->xt;
  t34 = sqrt(r->rs);
  t35 = 0.1e1 / t34;
  t36 = r->xt * t35;
  t38 = exp(-0.20635730928973273164e0 * t36);
  t39 = t33 * t38;
  t40 = pow(t15, 0.16666666666666666667e1);
  t41 = pow(t18, 0.16666666666666666667e1);
  t42 = t40 + t41;
  t43 = sqrt(t42);
  t44 = 0.1e1 / t43;
  t47 = r->xs[0] * r->xs[0];
  t50 = r->xs[1] * r->xs[1];
  t53 = 0.14142135623730950488e1 * t39 * t44 - 0.24498464859066978203e0 * t47 * t16 - 0.24498464859066978203e0 * t50 * t19;
  r->f = -t12 + 0.28000000000000000000e-4 * t3 - 0.41999999999999999998e-3 * r->rs + 0.83999999999999999999e-2 + t21 * t31 + 0.13297572090754734799e-2 * t7 * t53;

  if(r->order < 1) return;

  t57 = 0.28000000000000000000e-5 * t3 * t10;
  t58 = 0.1e1 / t3;
  t60 = 0.1e1 / t9;
  t62 = 0.75600000000000000000e0 * t6 * t58 * t60;
  t67 = 0.1e1 / t25;
  t71 = -0.90311111111111111105e-7 * t3 * t26 + 0.95250000000000000003e0 * t23 * t58 * t67 - 0.51484444444444444444e-4 * r->rs + 0.33533333333333333332e-3 + t57 - t62;
  t76 = 0.1e1 / t34 / t3;
  t77 = t33 * r->xt;
  t78 = t76 * t77;
  t79 = t38 * t44;
  r->dfdrs = -t57 + t62 + 0.56000000000000000000e-4 * r->rs - 0.41999999999999999998e-3 + t21 * t71 - 0.13297572090754734799e-2 * t58 * t53 + 0.19403372091339501186e-3 * t78 * t79;
  t82 = pow(t15, 0.3333333333333333333e0);
  t84 = pow(t18, 0.3333333333333333333e0);
  t86 = 0.25648814012420484265e1 * t82 - 0.25648814012420484265e1 * t84;
  t89 = 0.1e1 / t43 / t42;
  t90 = pow(t15, 0.6666666666666666667e0);
  t92 = pow(t18, 0.6666666666666666667e0);
  t94 = 0.16666666666666666667e1 * t90 - 0.16666666666666666667e1 * t92;
  t95 = t89 * t94;
  t102 = -0.70710678118654752440e0 * t39 * t95 - 0.32664619812089304270e0 * t47 * t82 + 0.32664619812089304270e0 * t50 * t84;
  r->dfdz = t86 * t31 + 0.13297572090754734799e-2 * t7 * t102;
  t105 = r->xt * t38;
  t108 = t33 * t35;
  t111 = 0.28284271247461900976e1 * t105 * t44 - 0.29183330549235950682e0 * t108 * t79;
  r->dfdxt = 0.13297572090754734799e-2 * t7 * t111;
  t113 = t7 * r->xs[0];
  r->dfdxs[0] = -0.65154020515252935349e-3 * t113 * t16;
  t116 = t7 * r->xs[1];
  r->dfdxs[1] = -0.65154020515252935349e-3 * t116 * t19;

  if(r->order < 2) return;

  t120 = 0.56000000000000000000e-5 * r->rs * t10;
  t121 = 0.16800000000000000000e-3 * t60;
  t122 = 0.1e1 / t4;
  t125 = 0.15120000000000000000e1 * t6 * t122 * t60;
  t126 = t3 * t3;
  t127 = 0.1e1 / t126;
  t128 = t6 * t127;
  t129 = t9 * t9;
  t130 = 0.1e1 / t129;
  t132 = 0.22680000000000000000e2 * t128 * t130;
  t139 = t23 * t127;
  t140 = t25 * t25;
  t141 = 0.1e1 / t140;
  t144 = -0.18062222222222222221e-6 * r->rs * t26 + 0.13546666666666666666e-4 * t67 - 0.19050000000000000001e1 * t23 * t122 * t67 + 0.71437500000000000004e2 * t139 * t141 - 0.51484444444444444444e-4 + t120 - t121 + t125 - t132;
  t149 = 0.1e1 / t34 / t4;
  t150 = t149 * t77;
  t151 = t150 * t79;
  t153 = t33 * t33;
  t154 = t127 * t153;
  r->d2fdrs2 = -t120 + t121 - t125 + t132 + 0.56000000000000000000e-4 + t21 * t144 + 0.26595144181509469598e-2 * t122 * t53 - 0.67911802319688254151e-3 * t151 + 0.20020138279581568346e-4 * t154 * t79;
  t160 = t38 * t89;
  t161 = t160 * t94;
  r->d2fdrsz = t86 * t71 - 0.13297572090754734799e-2 * t58 * t102 - 0.97016860456697505930e-4 * t78 * t161;
  t166 = t76 * t33;
  t169 = t122 * t77;
  r->d2fdrsxt = -0.13297572090754734799e-2 * t58 * t111 + 0.58210116274018503558e-3 * t166 * t79 - 0.40040276559163136692e-4 * t169 * t79;
  t172 = t58 * r->xs[0];
  r->d2fdrsxs[0] = 0.65154020515252935349e-3 * t172 * t16;
  t174 = t58 * r->xs[1];
  r->d2fdrsxs[1] = 0.65154020515252935349e-3 * t174 * t19;
  t176 = pow(t15, -0.6666666666666666667e0);
  t178 = pow(t18, -0.6666666666666666667e0);
  t180 = 0.85496046708068280875e0 * t176 + 0.85496046708068280875e0 * t178;
  t182 = t42 * t42;
  t184 = 0.1e1 / t43 / t182;
  t185 = t94 * t94;
  t186 = t184 * t185;
  t189 = pow(t15, -0.3333333333333333333e0);
  t191 = pow(t18, -0.3333333333333333333e0);
  t193 = 0.11111111111111111112e1 * t189 + 0.11111111111111111112e1 * t191;
  t194 = t89 * t193;
  t201 = 0.10606601717798212866e1 * t39 * t186 - 0.70710678118654752440e0 * t39 * t194 - 0.10888206604029768089e0 * t47 * t176 - 0.10888206604029768089e0 * t50 * t178;
  r->d2fdz2 = t180 * t31 + 0.13297572090754734799e-2 * t7 * t201;
  t208 = -0.14142135623730950488e1 * t105 * t95 + 0.14591665274617975341e0 * t108 * t161;
  r->d2fdzxt = 0.13297572090754734799e-2 * t7 * t208;
  r->d2fdzxs[0] = -0.86872027353670580463e-3 * t113 * t82;
  r->d2fdzxs[1] = 0.86872027353670580463e-3 * t116 * t84;
  t216 = t33 * t7;
  t219 = 0.28284271247461900976e1 * t79 - 0.11673332219694380273e1 * t36 * t79 + 0.60221935682531888672e-1 * t216 * t79;
  r->d2fdxt2 = 0.13297572090754734799e-2 * t7 * t219;
  r->d2fdxtxs[0] = 0;
  r->d2fdxtxs[1] = 0;
  r->d2fdxs2[0] = -0.65154020515252935349e-3 * t7 * t16;
  r->d2fdxs2[1] = 0;
  r->d2fdxs2[2] = -0.65154020515252935349e-3 * t7 * t19;

  if(r->order < 3) return;

  t225 = 0.56000000000000000000e-5 * t10;
  t227 = 0.75600000000000000000e-2 * t130 * t58;
  t229 = 0.45360000000000000000e1 * t128 * t60;
  t230 = t126 * r->rs;
  t231 = 0.1e1 / t230;
  t234 = 0.13608000000000000000e3 * t6 * t231 * t130;
  t236 = 0.1e1 / t126 / t3;
  t241 = 0.13608000000000000000e4 * t6 * t236 / t129 / t9;
  t260 = 0.1e1 / t34 / t126;
  r->d3fdrs3 = -t225 + t227 + t229 - t234 + t241 + t21 * (-0.18062222222222222221e-6 * t26 + 0.15240000000000000000e-2 * t141 * t58 + 0.57150000000000000003e1 * t139 * t67 - 0.42862500000000000003e3 * t23 * t231 * t141 + 0.10715625000000000001e5 * t23 * t236 / t140 / t25 + t225 - t227 - t229 + t234 - t241) - 0.79785432544528408794e-2 * t127 * t53 + 0.27649805230158789190e-2 * t260 * t77 * t79 - 0.15015103709686176260e-3 * t231 * t153 * t79 + 0.20656509334914157207e-5 / t34 / t230 * t153 * r->xt * t79;
  r->d3fdrs2z = t86 * t144 + 0.26595144181509469598e-2 * t122 * t102 + 0.33955901159844127076e-3 * t150 * t161 - 0.10010069139790784173e-4 * t154 * t161;
  t284 = t38 * t184 * t185;
  t287 = t160 * t193;
  r->d3fdrsz2 = t180 * t71 - 0.13297572090754734799e-2 * t58 * t201 + 0.14552529068504625890e-3 * t78 * t284 - 0.97016860456697505930e-4 * t78 * t287;
  r->d3fdrszxt = -0.13297572090754734799e-2 * t58 * t208 - 0.29105058137009251779e-3 * t166 * t161 + 0.20020138279581568346e-4 * t169 * t161;
  r->d3fdrszxs[0] = 0.86872027353670580463e-3 * t172 * t82;
  r->d3fdrszxs[1] = -0.86872027353670580463e-3 * t174 * t84;
  r->d3fdrs2xt = 0.26595144181509469598e-2 * t122 * t111 - 0.20373540695906476245e-2 * t149 * t33 * t79 + 0.22022152107539725180e-3 * t127 * t77 * t79 - 0.41313018669828314414e-5 * t260 * t153 * t79;
  r->d3fdrsxt2 = -0.13297572090754734799e-2 * t58 * t219 + 0.11642023254803700712e-2 * t76 * r->xt * t79 - 0.24024165935497882016e-3 * t122 * t33 * t79 + 0.82626037339656628829e-5 * t151;
  r->d3fdrsxtxs[0] = 0;
  r->d3fdrsxtxs[1] = 0;
  r->d3fdrs2xs[0] = -0.13030804103050587070e-2 * t122 * r->xs[0] * t16;
  r->d3fdrs2xs[1] = -0.13030804103050587070e-2 * t122 * r->xs[1] * t19;
  r->d3fdrsxs2[0] = 0.65154020515252935349e-3 * t58 * t16;
  r->d3fdrsxs2[1] = 0;
  r->d3fdrsxs2[2] = 0.65154020515252935349e-3 * t58 * t19;
  t327 = pow(t15, -0.16666666666666666667e1);
  t329 = pow(t18, -0.16666666666666666667e1);
  t344 = pow(t15, -0.13333333333333333333e1);
  t346 = pow(t18, -0.13333333333333333333e1);
  r->d3fdz3 = (-0.56997364472045520586e0 * t327 + 0.56997364472045520586e0 * t329) * t31 + 0.13297572090754734799e-2 * t7 * (-0.26516504294495532165e1 * t39 / t43 / t182 / t42 * t185 * t94 + 0.31819805153394638598e1 * t39 * t184 * t94 * t193 - 0.70710678118654752440e0 * t39 * t89 * (-0.37037037037037037036e0 * t344 + 0.37037037037037037036e0 * t346) + 0.72588044026865120597e-1 * t47 * t327 - 0.72588044026865120597e-1 * t50 * t329);
  r->d3fdz2xt = 0.13297572090754734799e-2 * t7 * (0.21213203435596425732e1 * t105 * t186 - 0.21887497911926963012e0 * t108 * t284 - 0.14142135623730950488e1 * t105 * t194 + 0.14591665274617975341e0 * t108 * t287);
  r->d3fdzxt2 = 0.13297572090754734799e-2 * t7 * (-0.14142135623730950488e1 * t161 + 0.58366661098471901364e0 * t36 * t161 - 0.30110967841265944336e-1 * t216 * t161);
  r->d3fdzxtxs[0] = 0;
  r->d3fdzxtxs[1] = 0;
  r->d3fdz2xs[0] = -0.28957342451223526818e-3 * t113 * t176;
  r->d3fdz2xs[1] = -0.28957342451223526818e-3 * t116 * t178;
  r->d3fdzxs2[0] = -0.86872027353670580463e-3 * t7 * t82;
  r->d3fdzxs2[1] = 0;
  r->d3fdzxs2[2] = 0.86872027353670580463e-3 * t7 * t84;
  r->d3fdxt3 = 0.13297572090754734799e-2 * t7 * (-0.17509998329541570409e1 * t35 * t38 * t44 + 0.36133161409519133203e0 * r->xt * t7 * t79 - 0.12427236607666624783e-1 * t33 / t34 / r->rs * t79);
  r->d3fdxt2xs[0] = 0;
  r->d3fdxt2xs[1] = 0;
  r->d3fdxtxs2[0] = 0;
  r->d3fdxtxs2[1] = 0;
  r->d3fdxtxs2[2] = 0;
  r->d3fdxs3[0] = 0;
  r->d3fdxs3[1] = 0;
  r->d3fdxs3[2] = 0;
  r->d3fdxs3[3] = 0;

  if(r->order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_c_lm_func)
