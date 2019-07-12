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

void Emission_Function(unsigned tau, unsigned Rx, unsigned Ry) {
   
    Pstatus pts[1000];
    double r[1000];
    double series;
    int series_sum=0;
     
    for (int i=0; i<1000; i++){
       double temp1 = rando();    
       double temp2 = rando();       
       double Pt = 0.6;  // total momentum of pair in Gev/c
               
       double phi = 2*PI * temp1;
       double theta = PI * temp2;  
       double mt = sqrt(Pt*Pt + PionMass*PionMass);        //     
       
       r[i] = pow ((pow((cos(phi)/Rx), 2) + pow((sin(phi)/Ry), 2)), -0.5);      

       pts[i].p.x = r[i]*cos(phi) ;                  // x-position 
       pts[i].p.y = pts[i].p.x*tan(phi) ;            // y-position
       pts[i].p.z = r[i]*cos(theta) ;                // z-position       
       pts[i].r = sqrt(pow(pts[i].p.x, 2) + pow(pts[i].p.x, 2));
       
       pts[i].phi_s = atan(pts[i].p.y/pts[i].p.x);       /* spatial azimuthal angle of the boost */
       pts[i].phi_b = atan((pow(Rx/Ry , 2))*tan(pts[i].phi_s)) ;     /* azimuthal direction of the boost- the boost is perpendicular to 
                                                                        the elliptical subshell on which the source element is found*/
       
     pts[i].r_norm = pow((pow((pts[i].r*cos(pts[i].phi_s)/Rx) , 2) + pow(pts[i].r*(cos(pts[i].phi_s)/Ry) , 2)), 0.5);//Normalized elliptic radius
       
              
       pts[i].rho = pts[i].r_norm * (rho_0 + rho_2*cos(2*pts[i].phi_b));  /* Flow rapidity : incorporating the possible dependance of the flow   
                                                                                             strength on azimuthal angle (source anisotropy) */
       
       pts[i].alpha = Pt * sinh(pts[i].rho)/T ;
       pts[i].beta  = mt * cosh(pts[i].rho)/T ;
       
       pts[i].Omega = 1 / exp((pts[i].r_norm -1)/a_s) ;         /* Omega: Source elements weighting function  & a_s is surface diffusness of 
                                                                   the source emission  */   
       pts[i].t = sqrt (tau*tau + pow(pts[i].p.z, 2));     // tau = sqrt(t^2 - z^2)                                                             
       pts[i].eta = 0.5*log((pts[i].t + pts[i].p.z)/(pts[i].t - pts[i].p.z)) ; // pts[i].eta2 = atanh(pts[i].p.z/pts[i].t);
       
       
       for (int n=1 ; n<10 ; n++){
         series = pow(1, n+1)*exp(n*pts[i].alpha*cos(pts[i].phi_b - pts[i].phi_s))*exp(-n*pts[i].phi_b*cosh(pts[i].eta - Y)); //
         series_sum = series_sum + series;
       }
       
       pts[i].S = mt*cosh(pts[i].eta -Y)*pts[i].Omega*exp(-pow((tau - tau_0), 2)/2*pow(delta_tau, 2))*series_sum ;  //  emission fun S
       
       cout<< pts[i].Omega <<"  "<< pts[i].r_norm<<"  "<<pts[i].S << "      "<<pts[i].eta <<"\n";   //just checking 
   }
}

/************************************************************************************
                      Calling the emission function
*************************************************************************************/

int main() {
     double tau= 12; 
     double Rx = 11;           
     double Ry = 13;            
     
     Emission_Function(tau, Rx, Ry);
         
  return 0;
}
