#ifndef __CORAL_CONSTANTS_H__
#define __CORAL_CONSTANTS_H__

#include <cmath>
#include <complex>

const double c = 1; //2.99e23;    // c = 2.99792458 [fm/s]
const double fm = 10e-15; 
const double ZERO         = 0.0;
const double HBARC        = 197.3269718;       // hbar times c
const double ALPHA        = 1.0/137.03599976;   // fine structure constant
const double PI           = 3.14159265; 
const double SQRTPI       = 1.772453850905516;
const double SQRTFOURPI   = 3.544907702;
const double DEGRAD       = 57.29577951308232;
const double AMU          = 931.494;          // atomic mass unit
const double ProtonMass   = 938.272;
const double KaonMass     = 493.677;
const double PionMass     = 139.57018;
const double Pion0Mass    = 134.9766;
const double LambdaMass   = 1115.7;
const double NeutronMass  = 939.565;
const double RhoMass      = 771.1;
const double XiMass       = 1321.3;
const double XiStarMass   = 1530.0;
const std::complex< double > ci = std::complex< double >(0.0,1.0);
const double m1 = PionMass;  
const double m2 = PionMass;
const double e = 1.6e-19; // 2.56e-38  
const double Z1 =  e;
const double Z2 =  e;
double k = 8.99e9;
const double dt = 0.001; 
const double M = m1*m2 / (m1 + m2);
#endif
