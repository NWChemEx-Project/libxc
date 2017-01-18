/* 
  This file was generated automatically with ../scripts/maple2c.pl.
  Do not edit this file directly as it can be overwritten!!

  Maple source      : ../maple/gga_x_pw91.mpl
  Type of functional: work_gga_x
*/

void XC(gga_x_pw91_enhance)
  (const XC(func_type) *p, int order, 
   FLOAT x, FLOAT *f, FLOAT *dfdx, FLOAT *d2fdx2, FLOAT *d3fdx3)
{
  double t1, t4, t5, t6, t10, t11, t12, t13;
  double t16, t19, t20, t22, t23, t24, t32, t33;
  double t35, t36, t37, t40, t43, t44, t45, t49;
  double t54, t55, t56, t62, t63, t66, t69, t70;
  double t72, t76, t77, t78, t85, t87, t91, t105;
  double t108, t111, t114, t125, t139, t141;

  gga_x_pw91_params *params;
 
  assert(p->params != NULL);
  params = (gga_x_pw91_params * )(p->params);

  t1 = x * x;
  t4 = exp(-0.16455307846020557507e-1 * params->alpha * t1);
  t5 = params->d * t4;
  t6 = params->c + t5;
  t10 = pow(0.12827824385304219430e0 * x, params->expo);
  t11 = params->f * t10;
  t12 = 0.16455307846020557507e-1 * t6 * t1 - t11;
  t13 = x * params->a;
  t16 = log(0.12827824385304219430e0 * params->b * x + sqrt(pow(0.12827824385304219430e0 * params->b * x, 0.2e1) + 0.1e1));
  t19 = 0.10e1 + 0.12827824385304219430e0 * t13 * t16 + t11;
  t20 = 0.1e1 / t19;
  *f = 0.10e1 + t12 * t20;

  if(order < 1) return;

  t22 = params->d * params->alpha;
  t23 = t1 * x;
  t24 = t23 * t4;
  t32 = 0.10000000000000000000e1 * t11 * params->expo / x;
  t33 = -0.54155431261461143986e-3 * t22 * t24 + 0.32910615692041115014e-1 * t6 * x - t32;
  t35 = t19 * t19;
  t36 = 0.1e1 / t35;
  t37 = t12 * t36;
  t40 = params->b * params->b;
  t43 = 0.16455307846020557507e-1 * t40 * t1 + 0.1e1;
  t44 = sqrt(t43);
  t45 = 0.1e1 / t44;
  t49 = 0.12827824385304219430e0 * params->a * t16 + 0.16455307846020557507e-1 * t13 * params->b * t45 + t32;
  *dfdx = t33 * t20 - t37 * t49;

  if(order < 2) return;

  t54 = params->alpha * params->alpha;
  t55 = params->d * t54;
  t56 = t1 * t1;
  t62 = params->expo * params->expo;
  t63 = 0.1e1 / t1;
  t66 = 0.10000000000000000000e1 * t11 * t62 * t63;
  t69 = 0.10000000000000000000e1 * t11 * params->expo * t63;
  t70 = -0.27077715630730571993e-2 * t22 * t1 * t4 + 0.17822885858826970814e-4 * t55 * t56 * t4 + 0.32910615692041115014e-1 * params->c + 0.32910615692041115014e-1 * t5 - t66 + t69;
  t72 = t33 * t36;
  t76 = 0.1e1 / t35 / t19;
  t77 = t12 * t76;
  t78 = t49 * t49;
  t85 = t40 * params->b;
  t87 = 0.1e1 / t44 / t43;
  t91 = 0.32910615692041115014e-1 * params->a * params->b * t45 - 0.27077715630730571993e-3 * t1 * params->a * t85 * t87 + t66 - t69;
  *d2fdx2 = t70 * t20 - t37 * t91 - 0.2e1 * t72 * t49 + 0.2e1 * t77 * t78;

  if(order < 3) return;

  t105 = 0.1e1 / t23;
  t108 = 0.10000000000000000000e1 * t11 * t62 * params->expo * t105;
  t111 = 0.30000000000000000000e1 * t11 * t62 * t105;
  t114 = 0.20000000000000000000e1 * t11 * params->expo * t105;
  t125 = t35 * t35;
  t139 = t40 * t40;
  t141 = t43 * t43;
  *d3fdx3 = (-0.64986517513753372783e-2 * t22 * x * t4 + 0.16040597272944273733e-3 * t55 * t24 - 0.58656214702296859059e-6 * params->d * t54 * params->alpha * t56 * x * t4 - t108 + t111 - t114) * t20 - 0.3e1 * t70 * t36 * t49 + 0.6e1 * t33 * t76 * t78 - 0.3e1 * t72 * t91 - 0.6e1 * t12 / t125 * t78 * t49 + 0.6e1 * t77 * t49 * t91 - t37 * (-0.10831086252292228797e-2 * params->a * t85 * t87 * x + 0.13367164394120228111e-4 * t23 * params->a * t139 * params->b / t44 / t141 + t108 - t111 + t114);

  if(order < 4) return;


}

#define maple2c_order 3
#define maple2c_func  XC(gga_x_pw91_enhance)
