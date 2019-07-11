#include "traj.h"     
#include <cmath>
#include <cstdlib>
#include <array>
#include <random>

#include <cstdio> 
//#include <stdlib.h> 
#include <ctime>
#include <math.h>
#include <string.h>


#include <fstream>
#include <iostream>

#include "random.cc"
#include "constants.h"
#include "misc.h"
#include "misc.cc"
//#include "bess.cc"

/*******************************************************************************
                             Emission Function => S(r, phi, tau, eta)  
********************************************************************************/

void Emission_Function() {
   
    Pstatus pts[1000];
    double r[1000];
     
    for (int i=0; i<1000; i++){
       double temp1 = rando();    
       double temp2 = rando(); 
       double mt = PionMass;  
       double Pt = 0;
               
       double phi = 2*PI * temp1;
       double theta = PI * temp2;  
             
       r[i] = pow ((pow((cos(phi)/Rx), 2) + pow((sin(phi)/Ry), 2)), -0.5);      
       pts[i].t = 0;               
       pts[i].p.x = r[i]*cos(phi) ;              // x-position 
       pts[i].p.y = pts[i].p.x*tan(phi) ;        // y-position
       pts[i].p.z = r[i]*cos(theta) ;                // z-position       ????????????????????????????
       
       pts[i].phi_s = atan(pts[i].p.y/pts[i].p.x);       /* spatial azimuthal angle of the boost */
       pts[i].phi_b = atan((pow(Rx/Ry , 2))*tan(pts[i].phi_s)) ;     /* azimuthal direction of the boost- the boost is perpendicular to 
                                                                        the elliptical subshell on which the source element is found*/
       
       pts[i].r_norm = pow((pow(r[i]*(cos(pts[i].phi_s))/Rx , 2) + pow(r[i]*(cos(pts[i].phi_s))/Ry , 2)), 0.5); // Normalized elliptic radius
       pts[i].tau = sqrt(pow(pts[i].t, 2) + pow(pts[i].p.z, 2));          
       pts[i].rho = pts[i].r_norm * (rho_0 + rho_2*cos(2*pts[i].phi_b));  /* Flow rapidity : incorporating the possible dependance of the flow   
                                                                                             strength on azimuthal angle (source anisotropy) */
       
       pts[i].alpha = Pt * sinh(pts[i].rho)/T ;
       pts[i].beta = mt * cosh(pts[i].rho)/T ;
       
       pts[i].Omega = 1 / exp((pts[i].r_norm -1)/a_s) ;    // Omega:Source elements & a_s is surface diffusness of the source emission
       
       
       pts[i].eta = 0.5*((pts[i].t + pts[i].p.z)/(pts[i].t - pts[i].p.z)) ; 
       pts[i].S = mt*cosh(pts[i].eta -Y)*pts[i].Omega*exp(-pow((pts[i].tau - tau_0), 2)/2*pow(delta_tau, 2));  //  *Bessel::K1(pts[i].beta);
       cout<< pts[i].Omega <<"  "<< pts[i].r_norm<<"  "<<pts[i].S <<"\n";  
   }
}

/************************************************************************************
                      Calling the emission function
*************************************************************************************/

int main() {
     //double tau;             
     
     Emission_Function();
   
  return 0;
}
