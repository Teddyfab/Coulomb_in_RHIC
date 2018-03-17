#! /usr/bin/env python

from random import random
import matplotlib.pyplot as plt
import scipy.interpolate as interp
import numpy as np
import math


new_x = 0
new_y = 0

def __init__(self, x, y, z, norm):
	self.x = x
	self.y = y
        self.z = z
        self.norm = norm

def greetings():
       
        print(r"""  Halu Teddo       """)
	
def location():
        for i in range (0,1000):
            x = random()*2
            y = random()
            
           # print  x,"   ",y

def zmesh():
        time = 1.0
	
	grid_max = 5.0
    	nsteps = 100
    	xymax = grid_max*(1 - 1/nsteps)
    	s = np.s_[-xymax:xymax:nsteps*1j]

    	Y, X = np.mgrid[s, s] 
	
	initial = np.exp(-(X*X + Y*Y)/(2*0.5**2))
	nsteps = initial.shape[0]

	print xymax
	
	print """                                                     =====  ====     ==      ==    ==  ==
                                                       =    ====  =====   =====     ===
                                                       =    ====  =====   =====      =                                                   """

	
	xy = np.linspace(-xymax, xymax, nsteps)
        spline1, spline3 = (
            interp.RectBivariateSpline(xy, xy, initial.T, kx=k, ky=k)
            for k in [1, 3]
        )
	

	npoints = min(max(int(np.ceil(np.pi*1.0*nsteps/grid_max)), 30), 100)
        phi = np.linspace(0, 2*np.pi, npoints, endpoint=False)
        cos_phi = np.cos(phi)
        sin_phi = np.sin(phi)

	X = np.subtract.outer(xy, 1.0*cos_phi)
        Y = np.subtract.outer(xy, 1.0*sin_phi)
	
	u, v, K = zip(*[
            (0, 0, np.ones_like(phi)),
            (0, 1, cos_phi),
            (0, 2, sin_phi),
            (1, 1, cos_phi*cos_phi),
            (1, 2, cos_phi*sin_phi),
            (2, 2, sin_phi*sin_phi),
        ])

	K = np.array(K)
        K /= phi.size

	Tuv = np.empty((nsteps, nsteps, 3, 3))
	for row, y in zip(Tuv, Y):
		Z1 = spline1(X, y, grid=False)
            	Z3 = spline3(X, y, grid=False)
            	Z3 = np.where((Z1 > 0) & (Z3 > 0), Z3, 0)


		row[:, u, v] = np.inner(Z3, K)

	u, v = zip(*[(0, 1), (0, 2), (1, 2)])
        Tuv[..., v, u] = Tuv[..., u, v]

	Tuv /= time


	print """                                  

                                                  Life was given to us billion yrs ago;
                                                                   what have we done with it ??   Lucy                              """

	              
        

                
def move():
     new_x += x
     new_y += y

if __name__ == '__main__':
    greetings()
   # location()
    zmesh()
   
    




   
   


        
   
