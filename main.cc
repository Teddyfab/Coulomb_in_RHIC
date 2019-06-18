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
//#include "randy.cc"
#include "random.cc"
#include "constants.h"
#include "misc.h"
#include "misc.cc"

/*******************************************************************************
   Calculates the force between the charges in evry time step
********************************************************************************/
void best(VecR3<double> initial[], Pstatus5 result[]);
auto force(Pstatus5 s) {                                        
        VecR3<double> f;
        double r=0, ff=0; 
	for(int i=0;i<5;i++)
	{
	        r  = sqrt((s.pa[i].x-s.p.x)*(s.pa[i].x-s.p.x) + (s.pa[i].y-s.p.y)*(s.pa[i].y-s.p.y) +(s.pa[i].z-s.p.z)*(s.pa[i].z-s.p.z)) ;
	        ff = (k * Z1 * Z2 ) / (r*r*r);
	        f.x += ff*(s.pa[i].x-s.p.x);
	        f.y += ff*(s.pa[i].y-s.p.y);
	        f.z += ff*(s.pa[i].z-s.p.z);
	}
	        	// cout << f.x<<"    "<<f.y<<"    "<<f.z<<"\n\n\n";
	return  f; 
}

/*******************************************************************************
   Calculates every next steps of both the position and the velocity of the 
 two particles on the x direction taking the electric force effect in to account.
********************************************************************************/

auto every_step(Pstatus s, VecR3<double> accel) {
  Pstatus next;
  next.t = s.t + dt;                  // dt = 0.001 fs ;  time step 

  next.p = s.p + (s.v * dt) + (accel * dt*dt* 0.5);
  next.v = s.v + (accel*dt);
  
  return next;
}

/*******************************************************************************
  called by the main and 
   make sure every step is running plus calls the print function on the .h file.
********************************************************************************/

void coulomb(unsigned n,Pstatus pts[]) {
    
    /*for (int i=0; i<1000; i++){
        cout<<i <<"     ";
        print_pstatus(pts[i]);}*/
    double px=0, py=0;   
    double u[4], p[4];
    double gamma = 1.091089451;
    double gm1 = gamma * m1;
    VecR3<double> initial[1000];
    auto state = pts;       
     
    Pstatus5 ptd[1000];
    
    for (int i=0; i<1000; i++){
        initial[i] = pts[i].p; }
       
        best(initial, ptd);                  // takes 'initial' and gives back as 'ptd' 
          
    for (unsigned k = 0; k < n; k++) {  
         for (int i=0; i<1000; i++){
                 state[i] = every_step(state[i],force(ptd[i]) / m1); /* calculates the force then divide it with the mass before calling   
                                                                         every_step */
               // print_pstatus(state[i]);
     }
     
     u[0]= c*state->t;
     u[1]= 0.4*state->p.x;
     u[2]= 0.4*state->p.y;
     u[3]= 0.4*state->p.z;
     p[0]= gm1*c;
     p[1]= gm1*0.4*c;
     p[2]= gm1*0.4*state->v.y*c;
     p[3]= gm1*0.4*state->v.z*c;
     
     px +=p[1];
     py +=p[2];
    
     //cout <<  (px - py)/(px + py) ;  // Thinking of calculating the elliptic flow for each particles here
    
     Boost(u, p, px, py);          // calling Boost from misc.cc
    }
     
   // print_pstatus(state);
}


void best(VecR3<double> initial[], Pstatus5 result[]){            // bubble sort (calculate the distance b/n particles and sort them out)
 
        int best[1000][5]={-1,-1};
        double distance[1000][1000], temp;
        for (int j=0; j<1000; j++)
          {
          
        for(int k=0; k<1000; k++)
        {
                
                if(k==j)
                        distance[j][k]=1000000000;
                else
                {                  
                   distance[j][k] = sqrt((initial[k].x - initial[j].x)*(initial[k].x - initial[j].x) + (initial[k].y - initial[j].y)*(initial[k].y - initial[j].y) + (initial[k].z - initial[j].z)*(initial[k].z - initial[j].z));
//                        cout<<distance[j][k]<<"\n";
                }                                 
         }
    }
              
        for (int l=0, norm[1000]; l<1000; l++)
        { 
           for(int i=0;i<1000;i++)
                norm[i]=i;
           for(int i=0;i<5;i++)
                for(int n=0; n<(999-i); n++)
                 {
                   if(distance[l][norm[n]] < distance[l][norm[n+1]])
                     {
                        temp = norm[n];
                        norm[n+1]=norm[n];
                        norm[n]=temp;
                     }
                 }
           for(int i=0;i<5;i++)
//           if(distance[l][norm[999-i]] < treshold)
                best[l][i]=norm[999-i];
  //              else
    //            break;
        }                                                  
    for(int i=0,j=0;i<1000;i++)
        {
        Pstatus5 tem;
        tem.p=initial[i];
        for( j=0; j<5;j++)
            tem.pa[j]=initial[best[i][j]];
             result[i]=tem;
        }
}
/************************************************************************************
 Takes in the arguments :    x1, y1, z1, p1x, p1y, p1z, x2, y2, z2, p2x, p2y, p2z
    and returns    : x1f, y1f, z1f, p1xf, p1yf, p1zf, x2f, y2f, z2f, p2xf, p2yf, p2zf
*************************************************************************************/

int main() {
  double p = 17 ;               // MeV/c        default initial momentum value
  //1double x[1000], y[1000], z[1000];
  Pstatus pts[1000];
  double r[1000]; 
  
 // int best[1000][5]={-1,-1,-1};    //choosing best five affecting particles ***** with defoult NONE(ive index)
  
  float a = 2; //*f;
  float b = 3; //*f;
  float c = 2; //*f;
  for (int i=0; i<1000; i++){
       double temp = rando();    
                   
       double theta = 2*PI * temp;
       double phi = PI * temp;  
             
       r[i] = pow ((pow((cos(theta)/a), 2) + pow((sin(theta)/b), 2) + pow((cos(phi)/c), 2)), -0.5);      
       pts[i].t = 0;               
       pts[i].p.x = r[i]*cos(theta) ;
       pts[i].p.y = pts[i].p.x*tan(theta) ;
       pts[i].p.z = r[i]*cos(phi) ;
       pts[i].v.x = p*cos(theta);
       pts[i].v.y = p*pts[i].p.y/r[i];
       pts[i].v.z = p*cos(phi);
   }
     coulomb(15000, pts);      // t = 15 fm/c
  return 0;
}
