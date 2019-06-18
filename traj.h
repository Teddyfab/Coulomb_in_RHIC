//#ifndef _TRAJ_H_
//#define _TRAJ_H_

#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <gsl/gsl_sf.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include <gsl/gsl_poly.h>
#include "constants.h"

typedef double FourVector[4];

template <typename P>         
struct VecR3 {
  P x{0};
  P y{0};
  P z{0};
};

template <typename P>
auto operator+(VecR3<P> a, VecR3<P> b) {
  return VecR3<P>{a.x + b.x, a.y + b.y, a.z + b.z};
}

template <typename P>
auto operator*(VecR3<P> a, P c) {
  return VecR3<P>{c * a.x, c * a.y, c*a.z};
}

template <typename P>
auto operator*(P c, VecR3<P> a) {
  return a * c;
}

template <typename P>
auto operator/(VecR3<P> a, P c) {
  return VecR3<P>{a.x / c, a.y / c, a.z/c};
}

struct Pstatus {
  double t{0};
  VecR3<double> p{0, 0, 0};      // to say : position of particle 1
  VecR3<double> v{0, 0, 0};      //          velocity of particle 1
};
 struct Pstatus5 {
  double t{0};
  VecR3<double> p{0, 0, 0};      // to say : position of particle 1
  //VecR3<double> v{0, 0, 0};      //          velocity of particle 1
  VecR3<double> pa[5]{{0, 0, 0},{0, 0, 0},{0, 0, 0},{0, 0, 0},{0, 0, 0}};
 };
 
 
void print_pstatus(Pstatus s) {
  printf("%f  %f  %f   %f    %f    %f     %f       %f     %f\n", 
              s.t ,s.p.x, s.p.y, s.p.z, m1*s.v.x, m1*s.v.y, m1*s.v.z, sqrt(pow(m1*s.v.x, 2) + pow(m1*s.v.y, 2) + pow(m1*s.v.z, 2)), (0.1*m1*s.v.x - m1*s.v.y)/(m1*s.v.x + m1*s.v.y)); 
                   
}
