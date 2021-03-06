/*
 Copyright (C) 2006-2007 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef _LDA_H
#define _LDA_H

/* These are generic header files that are needed basically everywhere */
#include <math.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "xc.h"
#include "xc_funcs_worker.h"

/* we include the references also */
#include "references.h"

/* need config to figure out what needs to be defined or not */
#include "config.h"

/* This takes care of disabling specific derivatives from the info structures */
#ifdef XC_DONT_COMPILE_VXC
# define XC_FLAGS_I_HAVE_VXC 0
#else
# define XC_FLAGS_I_HAVE_VXC XC_FLAGS_HAVE_VXC
#endif

#ifdef XC_DONT_COMPILE_FXC
# define XC_FLAGS_I_HAVE_FXC 0
#else
# define XC_FLAGS_I_HAVE_FXC XC_FLAGS_HAVE_FXC
#endif

#ifdef XC_DONT_COMPILE_KXC
# define XC_FLAGS_I_HAVE_KXC 0
#else
# define XC_FLAGS_I_HAVE_KXC XC_FLAGS_HAVE_KXC
#endif

#define XC_FLAGS_I_HAVE_ALL (XC_FLAGS_HAVE_EXC   | XC_FLAGS_I_HAVE_VXC | \
                             XC_FLAGS_I_HAVE_FXC | XC_FLAGS_I_HAVE_KXC)

/* Useful mathematical expressions */
#ifndef M_E
# define M_E            2.7182818284590452354   /* e */
#endif
#ifndef M_PI
# define M_PI           3.14159265358979323846  /* pi */
#endif
#ifndef M_SQRT2
# define M_SQRT2        1.41421356237309504880  /* sqrt(2) */
#endif

#define POW_2(x) ((x)*(x))
#define POW_3(x) ((x)*(x)*(x))

#define POW_1_2(x) sqrt(x)
#define POW_1_4(x) sqrt(sqrt(x))
#define POW_3_2(x) ((x)*sqrt(x))

#ifdef HAVE_CBRT
#define CBRT(x)    cbrt(x)
#define POW_1_3(x) cbrt(x)
#define POW_2_3(x) (cbrt(x)*cbrt(x))
#define POW_4_3(x) ((x)*cbrt(x))
#define POW_5_3(x) ((x)*cbrt(x)*cbrt(x))
#define POW_7_3(x) ((x)*(x)*cbrt(x))
#else
#define CBRT(x) pow((x), 1.0/3.0)
#define POW_1_3(x) pow((x), 1.0/3.0)
#define POW_2_3(x) pow((x), 2.0/3.0)
#define POW_4_3(x) pow((x), 4.0/3.0)
#define POW_5_3(x) pow((x), 5.0/3.0)
#define POW_7_3(x) pow((x), 7.0/3.0)
#endif

/* this is the piecewise function used in maple */
#define my_piecewise3(c, x1, x2) ((c) ? (x1) : (x2))
#define my_piecewise5(c1, x1, c2, x2, x3) ((c) ? (x1) : ((c2) ? (x2) : (x3)))

#define M_SQRTPI        1.772453850905516027298167483341145182798L
#define M_CBRTPI        1.464591887561523263020142527263790391739L
#define M_SQRT3         1.732050807568877293527446341505872366943L
#define M_CBRT2         1.259921049894873164767210607278228350570L
#define M_CBRT3         1.442249570307408382321638310780109588392L
#define M_CBRT4         1.587401051968199474751705639272308260391L
#define M_CBRT5         1.709975946676696989353108872543860109868L
#define M_CBRT6         1.817120592832139658891211756327260502428L
#define M_CBRT7         1.912931182772389101199116839548760282862L
#define M_CBRT9         2.080083823051904114530056824357885386338L

/* Very useful macros */
#ifndef min
#define min(x,y)  (((x)<(y)) ? (x) : (y))
#endif
#ifndef max
#define max(x,y)  (((x)<(y)) ? (y) : (x))
#endif

/* some useful constants */
#define LOG_DBL_MIN        (log(DBL_MIN))
#define LOG_DBL_MAX        (log(DBL_MAX))
#define SQRT_DBL_EPSILON   (sqrt(DBL_EPSILON))

/* special functions */
#define Heaviside(x) (((x) >= 0) ? 1.0 : 0.0)
double LambertW(double z);
double xc_dilogarithm(const double x);

/* we define this function here, so it can be properly inlined by all compilers */
static inline double
xc_cheb_eval(const double x, const double *cs, const int N)
{
  int i;
  double twox, b0, b1, b2;

  b2 = b1 = b0 = 0.0;

  twox = 2.0*x;
  for(i=N-1; i>=0; i--){
    b2 = b1;
    b1 = b0;
    b0 = twox*b1 - b2 + cs[i];
  }

  return 0.5*(b0 - b2);
}

double xc_bessel_I0_scaled(const double x);
double xc_bessel_I0(const double x);
double xc_bessel_K0_scaled(const double x);
double xc_bessel_K0(const double x);
double xc_bessel_K1_scaled(const double x);
double xc_bessel_K1(const double x);

double xc_expint_e1_impl(double x, const int scale);
static inline double expint_e1(const double x)         { return  xc_expint_e1_impl( x, 0); }
static inline double expint_e1_scaled(const double x)  { return  xc_expint_e1_impl( x, 1); }
static inline double expint_Ei(const double x)         { return -xc_expint_e1_impl(-x, 0); }
#define Ei(x) expint_Ei(x)
static inline double expint_Ei_scaled(const double x)  { return -xc_expint_e1_impl(-x, 1); }

/* integration */
typedef void integr_fn(double *x, int n, void *ex);
double xc_integrate(integr_fn func, void *ex, double a, double b);
void xc_rdqagse(integr_fn f, void *ex, double *a, double *b, 
	     double *epsabs, double *epsrel, int *limit, double *result,
	     double *abserr, int *neval, int *ier, double *alist__,
	     double *blist, double *rlist, double *elist, int *iord, int *last);
  
typedef struct xc_functional_key_t {
  char name[256];
  int  number;
} xc_functional_key_t;


#define M_C 137.0359996287515 /* speed of light */

#define RS_FACTOR      0.6203504908994000166680068120477781673508     /* (3/(4*Pi))^1/3        */
#define X_FACTOR_C     0.9305257363491000250020102180716672510262     /* 3/8*cur(3/pi)*4^(2/3) */
#define X_FACTOR_2D_C  1.504505556127350098528211870828726895584      /* 8/(3*sqrt(pi))        */
#define K_FACTOR_C     4.557799872345597137288163759599305358515      /* 3/10*(6*pi^2)^(2/3)   */
#define MU_GE          0.1234567901234567901234567901234567901235     /* 10/81                 */
#define MU_PBE         0.2195149727645171 /* mu = beta*pi^2/3, beta = 0.06672455060314922 */
#define X2S            0.1282782438530421943003109254455883701296     /* 1/(2*(6*pi^2)^(1/3))  */
#define X2S_2D         0.1410473958869390717370198628901931464610     /* 1/(2*(4*pi)^(1/2))    */
#define FZETAFACTOR    0.5198420997897463295344212145564567011405     /* 2^(4/3) - 2           */

#define RS(x)          (RS_FACTOR/CBRT(x))
#define FZETA(x)       ((pow(1.0 + (x),  4.0/3.0) + pow(1.0 - (x),  4.0/3.0) - 2.0)/FZETAFACTOR)
#define DFZETA(x)      ((CBRT(1.0 + (x)) - CBRT(1.0 - (x)))*(4.0/3.0)/FZETAFACTOR)
#define D2FZETA(x)     ((4.0/9.0)/FZETAFACTOR)* \
  (fabs(x)==1.0 ? (FLT_MAX) : (pow(1.0 + (x), -2.0/3.0) + pow(1.0 - (x), -2.0/3.0)))
#define D3FZETA(x)     (-(8.0/27.0)/FZETAFACTOR)* \
  (fabs(x)==1.0 ? (FLT_MAX) : (pow(1.0 + (x), -5.0/3.0) - pow(1.0 - (x), -5.0/3.0)))


/* The following inlines confuse the xlc compiler */
void xc_rho2dzeta(int nspin, const double *rho, double *d, double *zeta);

/* Functions to handle the internal counters */
void internal_counters_set_lda (int nspin, xc_dimensions *dim);
void internal_counters_lda_next
(const xc_dimensions *dim, int offset,
 const double **rho, double **zk, double **vrho, double **v2rho2, double **v3rho3
 );
void internal_counters_lda_prev
(const xc_dimensions *dim, int offset,
 const double **rho, double **zk, double **vrho, double **v2rho2, double **v3rho3
 );

void internal_counters_set_gga (int nspin, xc_dimensions *dim);
void internal_counters_gga_next
(const xc_dimensions *dim, int offset,
 const double **rho, const double **sigma,
 double **zk,
 double **vrho, double **vsigma,
 double **v2rho2, double **v2rhosigma, double **v2sigma2,
 double **v3rho3, double **v3rho2sigma, double **v3rhosigma2, double **v3sigma3
 );

void internal_counters_gga_prev
(const xc_dimensions *dim, int offset,
 const double **rho, const double **sigma,
 double **zk,
 double **vrho, double **vsigma,
 double **v2rho2, double **v2rhosigma, double **v2sigma2,
 double **v3rho3, double **v3rho2sigma, double **v3rhosigma2, double **v3sigma3
);

/* This are the derivatives of a mgga */
#define MGGA_OUT_PARAMS_NO_EXC(PTYPE)                                     \
 PTYPE vrho, PTYPE vsigma, PTYPE vlapl, PTYPE vtau,                       \
 PTYPE v2rho2, PTYPE v2rhosigma, PTYPE v2rholapl, PTYPE v2rhotau,         \
 PTYPE v2sigma2, PTYPE v2sigmalapl, PTYPE v2sigmatau,                     \
 PTYPE v2lapl2, PTYPE v2lapltau,                                          \
 PTYPE v2tau2,                                                            \
 PTYPE v3rho3, PTYPE v3rho2sigma, PTYPE v3rho2lapl, PTYPE v3rho2tau,      \
 PTYPE v3rhosigma2, PTYPE v3rhosigmalapl, PTYPE v3rhosigmatau,            \
 PTYPE v3rholapl2, PTYPE v3rholapltau,                                    \
 PTYPE v3rhotau2,                                                         \
 PTYPE v3sigma3, PTYPE v3sigma2lapl, PTYPE v3sigma2tau,                   \
 PTYPE v3sigmalapl2, PTYPE v3sigmalapltau,                                \
 PTYPE v3sigmatau2,                                                       \
 PTYPE v3lapl3, PTYPE v3lapl2tau,                                         \
 PTYPE v3lapltau2,                                                        \
 PTYPE v3tau3

void internal_counters_set_mgga(int nspin, xc_dimensions *dim);

void internal_counters_mgga_next
(const xc_dimensions *dim, int offset,
 const double **rho, const double **sigma, const double **lapl, const double **tau,
 double **zk, MGGA_OUT_PARAMS_NO_EXC(double **));

void internal_counters_mgga_prev
(const xc_dimensions *dim, int offset,
 const double **rho, const double **sigma, const double **lapl, const double **tau,
 double **zk, MGGA_OUT_PARAMS_NO_EXC(double **));

/* Functionals that are defined as mixtures of others */
void xc_mix_init(xc_func_type *p, int n_funcs, const int *funcs_id, const double *mix_coef);
void xc_mix_func
  (const xc_func_type *func, int np,
   const double *rho, const double *sigma, const double *lapl, const double *tau,
   double *zk, MGGA_OUT_PARAMS_NO_EXC(double *));

/* Some useful functions */
const char *get_kind(const xc_func_type *func);
const char *get_family(const xc_func_type *func);
double get_ext_param(const func_params_type *params, const double *values, int index);

#endif
