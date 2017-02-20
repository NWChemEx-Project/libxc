/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/lda_c_vwn_rpa.mpl
  Type of functional: work_lda
*/

static void
func0(const XC(func_type) *p, XC(lda_work_t) *r)
{
  double t1, t3, t4, t6, t9, t12, t14, t15;
  double t17, t19, t20, t22, t24, t26, t27, t28;
  double t31, t32, t35, t36, t39, t41, t43, t44;
  double t45, t51, t53, t58, t59, t62, t63, t64;
  double t70, t75, t79, t81, t83, t84, t89, t90;
  double t95, t100, t101, t105, t106, t107, t127, t136;
  double t146, t147, t149, t175, t191;


  t1 = sqrt(r->rs);
  t3 = r->rs + 0.130720e2 * t1 + 0.427198e2;
  t4 = 0.1e1 / t3;
  t6 = log(r->rs * t4);
  t9 = 0.20e1 * t1 + 0.130720e2;
  t12 = atan(0.44899888641287296627e-1 / t9);
  t14 = t1 + 0.409286e0;
  t15 = t14 * t14;
  t17 = log(t15 * t4);
  r->f = 0.3109070e-1 * t6 + 0.20521972937837502661e2 * t12 + 0.44313737677495382697e-2 * t17;

  if(r->order < 1) return;

  t19 = t3 * t3;
  t20 = 0.1e1 / t19;
  t22 = 0.1e1 / t1;
  t24 = 0.1e1 + 0.65360000000000000000e1 * t22;
  t26 = -r->rs * t20 * t24 + t4;
  t27 = 0.1e1 / r->rs;
  t28 = t26 * t27;
  t31 = t9 * t9;
  t32 = 0.1e1 / t31;
  t35 = 0.20160000000000000000e-2 * t32 + 0.1e1;
  t36 = 0.1e1 / t35;
  t39 = t14 * t4;
  t41 = t15 * t20;
  t43 = t39 * t22 - t41 * t24;
  t44 = 0.1e1 / t15;
  t45 = t43 * t44;
  r->dfdrs = 0.3109070e-1 * t28 * t3 - 0.92143429960841537844e0 * t32 * t22 * t36 + 0.44313737677495382697e-2 * t45 * t3;

  if(r->order < 2) return;

  t51 = 0.1e1 / t19 / t3;
  t53 = t24 * t24;
  t58 = -0.2e1 * t20 * t24 + 0.2e1 * r->rs * t51 * t53 + 0.32680000000000000000e1 * t22 * t20;
  t59 = t58 * t27;
  t62 = r->rs * r->rs;
  t63 = 0.1e1 / t62;
  t64 = t26 * t63;
  t70 = 0.1e1 / t31 / t9;
  t75 = 0.1e1 / t1 / r->rs;
  t79 = t31 * t31;
  t81 = 0.1e1 / t79 / t9;
  t83 = t35 * t35;
  t84 = 0.1e1 / t83;
  t89 = t14 * t20;
  t90 = t22 * t24;
  t95 = t15 * t51;
  t100 = t27 * t4 / 0.2e1 - 0.2e1 * t89 * t90 - t39 * t75 / 0.2e1 + 0.2e1 * t95 * t53 + 0.32680000000000000000e1 * t41 * t75;
  t101 = t100 * t44;
  t105 = 0.1e1 / t15 / t14;
  t106 = t43 * t105;
  t107 = t3 * t22;
  r->d2fdrs2 = 0.3109070e-1 * t59 * t3 - 0.3109070e-1 * t64 * t3 + 0.3109070e-1 * t28 * t24 + 0.18428685992168307569e1 * t70 * t27 * t36 + 0.46071714980420768922e0 * t32 * t75 * t36 - 0.37152230960211308059e-2 * t81 * t27 * t84 + 0.44313737677495382697e-2 * t101 * t3 - 0.44313737677495382697e-2 * t106 * t107 + 0.44313737677495382697e-2 * t45 * t24;

  if(r->order < 3) return;

  t127 = 0.1e1 / t1 / t62;
  t136 = t15 * t15;
  t146 = t19 * t19;
  t147 = 0.1e1 / t146;
  t149 = t53 * t24;
  t175 = t79 * t79;
  t191 = t75 * t24;
  r->d3fdrs3 = 0.22156868838747691348e-2 * t106 * t3 * t75 - 0.6218140e-1 * t58 * t63 * t3 + 0.6218140e-1 * t26 / t62 / r->rs * t3 - 0.27643028988252461353e1 * t70 * t63 * t36 - 0.69107572470631153383e0 * t32 * t127 * t36 - 0.88627475354990765394e-2 * t100 * t105 * t107 - 0.88627475354990765394e-2 * t106 * t90 + 0.66470606516243074046e-2 * t43 / t136 * t3 * t27 + 0.3109070e-1 * (0.6e1 * t51 * t53 + 0.49020000000000000000e1 * t20 * t75 - 0.6e1 * r->rs * t147 * t149 - 0.19608000000000000000e2 * t22 * t51 * t24) * t27 * t3 + 0.6218140e-1 * t59 * t24 - 0.6218140e-1 * t64 * t24 - 0.55286057976504922707e1 / t79 * t75 * t36 + 0.26006561672147915642e-1 / t79 / t31 * t75 * t84 + 0.55728346440316962088e-2 * t81 * t63 * t84 - 0.29959559046314398819e-4 / t175 * t75 / t83 / t35 + 0.44313737677495382697e-2 * (-0.3e1 / 0.4e1 * t63 * t4 - 0.3e1 / 0.2e1 * t27 * t20 * t24 + 0.6e1 * t14 * t51 * t22 * t53 + 0.3e1 / 0.2e1 * t89 * t191 + 0.98040000000000000000e1 * t89 * t63 + 0.3e1 / 0.4e1 * t39 * t127 - 0.6e1 * t15 * t147 * t149 - 0.19608000000000000000e2 * t95 * t191 - 0.49020000000000000000e1 * t41 * t127) * t44 * t3 + 0.88627475354990765394e-2 * t101 * t24 - 0.14481729473005491065e-1 * t45 * t75 - 0.10160440760000000000e0 * t26 * t127;

  if(r->order < 4) return;


}

static void
func1(const XC(func_type) *p, XC(lda_work_t) *r)
{
  double t1, t3, t4, t6, t8, t9, t12, t14;
  double t15, t17, t19, t20, t21, t22, t23, t24;
  double t25, t26, t29, t30, t32, t34, t37, t39;
  double t40, t42, t44, t45, t47, t48, t50, t52;
  double t54, t55, t56, t59, t60, t63, t64, t67;
  double t69, t71, t72, t73, t76, t78, t79, t82;
  double t84, t85, t88, t89, t92, t93, t96, t98;
  double t100, t101, t102, t105, t107, t109, t111, t113;
  double t118, t120, t125, t126, t129, t130, t131, t137;
  double t142, t146, t148, t150, t151, t156, t157, t162;
  double t167, t168, t172, t173, t174, t179, t184, t186;
  double t191, t192, t195, t201, t208, t210, t212, t213;
  double t218, t219, t224, t229, t230, t234, t235, t236;
  double t241, t245, t247, t249, t251, t260, t268, t277;
  double t287, t288, t290, t316, t332, t356, t378, t388;
  double t389, t391, t417, t433, t457, t463, t465, t467;


  t1 = sqrt(r->rs);
  t3 = r->rs + 0.130720e2 * t1 + 0.427198e2;
  t4 = 0.1e1 / t3;
  t6 = log(r->rs * t4);
  t8 = 0.20e1 * t1;
  t9 = t8 + 0.130720e2;
  t12 = atan(0.44899888641287296627e-1 / t9);
  t14 = t1 + 0.409286e0;
  t15 = t14 * t14;
  t17 = log(t15 * t4);
  t19 = 0.310907e-1 * t6 + 0.20521972937837502661e2 * t12 + 0.44313737677495382697e-2 * t17;
  t20 = 0.10e1 + r->z;
  t21 = pow(t20, 0.13333333333333333333e1);
  t22 = 0.19236610509315363199e1 * t21;
  t23 = 0.10e1 - r->z;
  t24 = pow(t23, 0.13333333333333333333e1);
  t25 = 0.19236610509315363199e1 * t24;
  t26 = 0.48473221018630726398e1 - t22 - t25;
  t29 = r->rs + 0.201231e2 * t1 + 0.101578e3;
  t30 = 0.1e1 / t29;
  t32 = log(r->rs * t30);
  t34 = t8 + 0.201231e2;
  t37 = atan(0.11716852777089929792e1 / t34);
  t39 = t1 + 0.743294e0;
  t40 = t39 * t39;
  t42 = log(t40 * t30);
  t44 = 0.1554535e-1 * t32 + 0.61881802979060631482e0 * t37 + 0.26673100072733151594e-2 * t42;
  t45 = t22 + t25 - 0.38473221018630726398e1;
  r->f = t19 * t26 + t44 * t45;

  if(r->order < 1) return;

  t47 = t3 * t3;
  t48 = 0.1e1 / t47;
  t50 = 0.1e1 / t1;
  t52 = 0.1e1 + 0.65360000000000000000e1 * t50;
  t54 = -r->rs * t48 * t52 + t4;
  t55 = 0.1e1 / r->rs;
  t56 = t54 * t55;
  t59 = t9 * t9;
  t60 = 0.1e1 / t59;
  t63 = 0.20160000000000000000e-2 * t60 + 0.1e1;
  t64 = 0.1e1 / t63;
  t67 = t14 * t4;
  t69 = t15 * t48;
  t71 = t67 * t50 - t69 * t52;
  t72 = 0.1e1 / t15;
  t73 = t71 * t72;
  t76 = 0.310907e-1 * t56 * t3 - 0.92143429960841537844e0 * t60 * t50 * t64 + 0.44313737677495382697e-2 * t73 * t3;
  t78 = t29 * t29;
  t79 = 0.1e1 / t78;
  t82 = 0.1e1 + 0.10061550000000000000e2 * t50;
  t84 = -r->rs * t79 * t82 + t30;
  t85 = t84 * t55;
  t88 = t34 * t34;
  t89 = 0.1e1 / t88;
  t92 = 0.13728463900000000000e1 * t89 + 0.1e1;
  t93 = 0.1e1 / t92;
  t96 = t39 * t30;
  t98 = t40 * t79;
  t100 = t96 * t50 - t98 * t82;
  t101 = 0.1e1 / t40;
  t102 = t100 * t101;
  t105 = 0.1554535e-1 * t85 * t29 - 0.72505997508653845050e0 * t89 * t50 * t93 + 0.26673100072733151594e-2 * t102 * t29;
  r->dfdrs = t105 * t45 + t76 * t26;
  t107 = pow(t20, 0.3333333333333333333e0);
  t109 = pow(t23, 0.3333333333333333333e0);
  t111 = -0.25648814012420484265e1 * t107 + 0.25648814012420484265e1 * t109;
  t113 = -t111;
  r->dfdz = t19 * t111 + t44 * t113;

  if(r->order < 2) return;

  t118 = 0.1e1 / t47 / t3;
  t120 = t52 * t52;
  t125 = -0.2e1 * t48 * t52 + 0.2e1 * r->rs * t118 * t120 + 0.32680000000000000000e1 * t50 * t48;
  t126 = t125 * t55;
  t129 = r->rs * r->rs;
  t130 = 0.1e1 / t129;
  t131 = t54 * t130;
  t137 = 0.1e1 / t59 / t9;
  t142 = 0.1e1 / t1 / r->rs;
  t146 = t59 * t59;
  t148 = 0.1e1 / t146 / t9;
  t150 = t63 * t63;
  t151 = 0.1e1 / t150;
  t156 = t14 * t48;
  t157 = t50 * t52;
  t162 = t15 * t118;
  t167 = t55 * t4 / 0.2e1 - 0.2e1 * t156 * t157 - t67 * t142 / 0.2e1 + 0.2e1 * t162 * t120 + 0.32680000000000000000e1 * t69 * t142;
  t168 = t167 * t72;
  t172 = 0.1e1 / t15 / t14;
  t173 = t71 * t172;
  t174 = t3 * t50;
  t179 = 0.310907e-1 * t126 * t3 - 0.310907e-1 * t131 * t3 + 0.310907e-1 * t56 * t52 + 0.18428685992168307569e1 * t137 * t55 * t64 + 0.46071714980420768922e0 * t60 * t142 * t64 - 0.37152230960211308059e-2 * t148 * t55 * t151 + 0.44313737677495382697e-2 * t168 * t3 - 0.44313737677495382697e-2 * t173 * t174 + 0.44313737677495382697e-2 * t73 * t52;
  t184 = 0.1e1 / t78 / t29;
  t186 = t82 * t82;
  t191 = -0.2e1 * t79 * t82 + 0.2e1 * r->rs * t184 * t186 + 0.50307750000000000000e1 * t50 * t79;
  t192 = t191 * t55;
  t195 = t84 * t130;
  t201 = 0.1e1 / t88 / t34;
  t208 = t88 * t88;
  t210 = 0.1e1 / t208 / t34;
  t212 = t92 * t92;
  t213 = 0.1e1 / t212;
  t218 = t39 * t79;
  t219 = t50 * t82;
  t224 = t40 * t184;
  t229 = t55 * t30 / 0.2e1 - 0.2e1 * t218 * t219 - t96 * t142 / 0.2e1 + 0.2e1 * t224 * t186 + 0.50307750000000000000e1 * t98 * t142;
  t230 = t229 * t101;
  t234 = 0.1e1 / t40 / t39;
  t235 = t100 * t234;
  t236 = t29 * t50;
  t241 = 0.1554535e-1 * t192 * t29 - 0.1554535e-1 * t195 * t29 + 0.1554535e-1 * t85 * t82 + 0.14501199501730769010e1 * t201 * t55 * t93 + 0.36252998754326922525e0 * t89 * t142 * t93 - 0.19907919386620884987e1 * t210 * t55 * t213 + 0.26673100072733151594e-2 * t230 * t29 - 0.26673100072733151594e-2 * t235 * t236 + 0.26673100072733151594e-2 * t102 * t82;
  r->d2fdrs2 = t179 * t26 + t241 * t45;
  r->d2fdrsz = t105 * t113 + t76 * t111;
  t245 = pow(t20, -0.6666666666666666667e0);
  t247 = pow(t23, -0.6666666666666666667e0);
  t249 = -0.85496046708068280875e0 * t245 - 0.85496046708068280875e0 * t247;
  t251 = -t249;
  r->d2fdz2 = t19 * t249 + t44 * t251;

  if(r->order < 3) return;

  t260 = 0.1e1 / t129 / r->rs;
  t268 = 0.1e1 / t1 / t129;
  t277 = t15 * t15;
  t287 = t47 * t47;
  t288 = 0.1e1 / t287;
  t290 = t120 * t52;
  t316 = t146 * t146;
  t332 = t142 * t52;
  t356 = 0.22156868838747691348e-2 * t173 * t3 * t142 - 0.621814e-1 * t125 * t130 * t3 + 0.621814e-1 * t54 * t260 * t3 - 0.27643028988252461353e1 * t137 * t130 * t64 - 0.69107572470631153383e0 * t60 * t268 * t64 - 0.88627475354990765394e-2 * t167 * t172 * t174 - 0.88627475354990765394e-2 * t173 * t157 + 0.66470606516243074046e-2 * t71 / t277 * t3 * t55 + 0.310907e-1 * (0.6e1 * t118 * t120 + 0.49020000000000000000e1 * t48 * t142 - 0.6e1 * r->rs * t288 * t290 - 0.19608000000000000000e2 * t50 * t118 * t52) * t55 * t3 + 0.621814e-1 * t126 * t52 - 0.621814e-1 * t131 * t52 - 0.55286057976504922707e1 / t146 * t142 * t64 + 0.26006561672147915642e-1 / t146 / t59 * t142 * t151 + 0.55728346440316962088e-2 * t148 * t130 * t151 - 0.29959559046314398819e-4 / t316 * t142 / t150 / t63 + 0.44313737677495382697e-2 * (-0.3e1 / 0.4e1 * t130 * t4 - 0.3e1 / 0.2e1 * t55 * t48 * t52 + 0.6e1 * t14 * t118 * t50 * t120 + 0.3e1 / 0.2e1 * t156 * t332 + 0.98040000000000000000e1 * t156 * t130 + 0.3e1 / 0.4e1 * t67 * t268 - 0.6e1 * t15 * t288 * t290 - 0.19608000000000000000e2 * t162 * t332 - 0.49020000000000000000e1 * t69 * t268) * t72 * t3 + 0.88627475354990765394e-2 * t168 * t52 - 0.14481729473005491065e-1 * t73 * t142 - 0.10160440760000000000e0 * t54 * t268;
  t378 = t40 * t40;
  t388 = t78 * t78;
  t389 = 0.1e1 / t388;
  t391 = t186 * t82;
  t417 = t208 * t208;
  t433 = t142 * t82;
  t457 = 0.13336550036366575797e-2 * t235 * t29 * t142 - 0.3109070e-1 * t191 * t130 * t29 + 0.3109070e-1 * t84 * t260 * t29 - 0.21751799252596153515e1 * t201 * t130 * t93 - 0.54379498131490383788e0 * t89 * t268 * t93 - 0.53346200145466303188e-2 * t229 * t234 * t236 - 0.53346200145466303188e-2 * t235 * t219 + 0.40009650109099727391e-2 * t100 / t378 * t29 * t55 + 0.1554535e-1 * (0.6e1 * t184 * t186 + 0.75461625000000000000e1 * t79 * t142 - 0.6e1 * r->rs * t389 * t391 - 0.30184650000000000000e2 * t50 * t184 * t82) * t55 * t29 + 0.3109070e-1 * t192 * t82 - 0.3109070e-1 * t195 * t82 - 0.43503598505192307030e1 / t208 * t142 * t93 + 0.13935543570634619491e2 / t208 / t88 * t142 * t213 + 0.29861879079931327481e1 * t210 * t130 * t213 - 0.10932206104933398501e2 / t417 * t142 / t212 / t92 + 0.26673100072733151594e-2 * (-0.3e1 / 0.4e1 * t130 * t30 - 0.3e1 / 0.2e1 * t55 * t79 * t82 + 0.6e1 * t39 * t184 * t50 * t186 + 0.3e1 / 0.2e1 * t218 * t433 + 0.15092325000000000000e2 * t218 * t130 + 0.3e1 / 0.4e1 * t96 * t268 - 0.6e1 * t40 * t389 * t391 - 0.30184650000000000000e2 * t224 * t433 - 0.75461625000000000000e1 * t98 * t268) * t101 * t29 + 0.53346200145466303188e-2 * t230 * t82 - 0.13418636501840412071e-1 * t102 * t142 - 0.78205158146250000000e-1 * t84 * t268;
  r->d3fdrs3 = t356 * t26 + t457 * t45;
  r->d3fdrs2z = t179 * t111 + t241 * t113;
  r->d3fdrsz2 = t105 * t251 + t76 * t249;
  t463 = pow(t20, -0.16666666666666666667e1);
  t465 = pow(t23, -0.16666666666666666667e1);
  t467 = 0.56997364472045520586e0 * t463 - 0.56997364472045520586e0 * t465;
  r->d3fdz3 = t19 * t467 - t44 * t467;

  if(r->order < 4) return;


}

void 
XC(lda_c_vwn_rpa_func)(const XC(func_type) *p, XC(lda_work_t) *r)
{
  if(p->nspin == XC_UNPOLARIZED)
    func0(p, r);
  else
    func1(p, r);
}

#define maple2c_order 3
#define maple2c_func  XC(lda_c_vwn_rpa_func)
