/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/gga_c_wi.mpl
  Type of functional: work_gga_c
*/

void XC(gga_c_wi_func)
  (const XC(func_type) *p, XC(gga_work_c_t) *r)
{
  double t1, t2, t4, t6, t7, t10, t12, t13;
  double t14, t15, t16, t21, t22, t25, t27, t28;
  double t29, t33, t34, t35, t37, t39, t42, t49;
  double t51, t52, t55, t59, t60, t61, t62, t63;
  double t66, t67, t70, t72, t76, t86, t128, t132;
  double t136;

  gga_c_wi_params *params;

  assert(p->params != NULL);
  params = (gga_c_wi_params * )(p->params);

  t1 = r->xt * r->xt;
  t2 = params->b * t1;
  t4 = exp(-params->k * t1);
  t6 = t2 * t4 + params->a;
  t7 = pow(r->xt, 0.35000000000000000000e1);
  t10 = 0.10e1 + 0.16119919540164696407e1 * params->d * t7;
  t12 = r->rs * t10 + params->c;
  t13 = 0.1e1 / t12;
  r->f = t6 * t13;

  if(r->order < 1) return;

  t14 = t12 * t12;
  t15 = 0.1e1 / t14;
  t16 = t6 * t15;
  r->dfdrs = -t16 * t10;
  r->dfdz = 0;
  t21 = params->b * t1 * r->xt;
  t22 = params->k * t4;
  t25 = 0.2e1 * params->b * r->xt * t4 - 0.2e1 * t21 * t22;
  t27 = r->rs * params->d;
  t28 = pow(r->xt, 0.25000000000000000000e1);
  t29 = t27 * t28;
  r->dfdxt = t25 * t13 - 0.56419718390576437424e1 * t16 * t29;
  r->dfdxs[0] = 0;
  r->dfdxs[1] = 0;

  if(r->order < 2) return;

  t33 = 0.1e1 / t14 / t12;
  t34 = t6 * t33;
  t35 = t10 * t10;
  r->d2fdrs2 = 0.2e1 * t34 * t35;
  r->d2fdrsz = 0;
  t37 = t25 * t15;
  t39 = t34 * t10;
  t42 = params->d * t28;
  r->d2fdrsxt = -t37 * t10 + 0.11283943678115287485e2 * t39 * t29 - 0.56419718390576437424e1 * t16 * t42;
  r->d2fdrsxs[0] = 0;
  r->d2fdrsxs[1] = 0;
  r->d2fdz2 = 0;
  r->d2fdzxt = 0;
  r->d2fdzxs[0] = 0;
  r->d2fdzxs[1] = 0;
  t49 = t1 * t1;
  t51 = params->k * params->k;
  t52 = t51 * t4;
  t55 = 0.4e1 * params->b * t49 * t52 - 0.10e2 * t2 * t22 + 0.2e1 * params->b * t4;
  t59 = r->rs * r->rs;
  t60 = params->d * params->d;
  t61 = t59 * t60;
  t62 = pow(r->xt, 0.50000000000000000000e1);
  t63 = t61 * t62;
  t66 = pow(r->xt, 0.15000000000000000000e1);
  t67 = t27 * t66;
  r->d2fdxt2 = t55 * t13 - 0.11283943678115287485e2 * t37 * t29 + 0.63663692465438981328e2 * t34 * t63 - 0.14104929597644109356e2 * t16 * t67;
  r->d2fdxtxs[0] = 0;
  r->d2fdxtxs[1] = 0;
  r->d2fdxs2[0] = 0;
  r->d2fdxs2[1] = 0;
  r->d2fdxs2[2] = 0;

  if(r->order < 3) return;

  t70 = t14 * t14;
  t72 = t6 / t70;
  r->d3fdrs3 = -0.6e1 * t72 * t35 * t10;
  r->d3fdrs2z = 0;
  r->d3fdrsz2 = 0;
  r->d3fdrszxt = 0;
  r->d3fdrszxs[0] = 0;
  r->d3fdrszxs[1] = 0;
  t76 = t25 * t33;
  r->d3fdrs2xt = 0.2e1 * t76 * t35 - 0.33851831034345862454e2 * t72 * t35 * t29 + 0.22567887356230574970e2 * t34 * t10 * params->d * t28;
  t86 = t55 * t15;
  r->d3fdrsxt2 = -t86 * t10 + 0.22567887356230574970e2 * t76 * t10 * t29 - 0.11283943678115287485e2 * t37 * t42 - 0.19099107739631694398e3 * t72 * t10 * t63 + 0.12732738493087796266e3 * t34 * t60 * t62 * r->rs + 0.28209859195288218712e2 * t39 * t67 - 0.14104929597644109356e2 * t16 * params->d * t66;
  r->d3fdrsxtxs[0] = 0;
  r->d3fdrsxtxs[1] = 0;
  r->d3fdrs2xs[0] = 0;
  r->d3fdrs2xs[1] = 0;
  r->d3fdrsxs2[0] = 0;
  r->d3fdrsxs2[1] = 0;
  r->d3fdrsxs2[2] = 0;
  r->d3fdz3 = 0;
  r->d3fdz2xt = 0;
  r->d3fdzxt2 = 0;
  r->d3fdzxtxs[0] = 0;
  r->d3fdzxtxs[1] = 0;
  r->d3fdz2xs[0] = 0;
  r->d3fdz2xs[1] = 0;
  r->d3fdzxs2[0] = 0;
  r->d3fdzxs2[1] = 0;
  r->d3fdzxs2[2] = 0;
  t128 = pow(r->xt, 0.75000000000000000000e1);
  t132 = pow(r->xt, 0.40000000000000000000e1);
  t136 = pow(r->xt, 0.5000000000000000000e0);
  r->d3fdxt3 = (-0.8e1 * params->b * t49 * r->xt * t51 * params->k * t4 - 0.24e2 * params->b * params->k * r->xt * t4 + 0.36e2 * t21 * t52) * t13 - 0.16925915517172931227e2 * t86 * t29 + 0.19099107739631694399e3 * t76 * t63 - 0.42314788792932328068e2 * t37 * t67 - 0.10775662801812990807e4 * t72 * t59 * r->rs * t60 * params->d * t128 + 0.47747769349079235996e3 * t34 * t61 * t132 - 0.21157394396466164034e2 * t16 * t27 * t136;
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
#define maple2c_func  XC(gga_c_wi_func)
