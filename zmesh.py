#! /usr/bin/env python

from random import random
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
            
            print  x,"   ",y

def zmesh():

	grid_max = 5.0
        nsteps = 100
        xymax = grid_max*(1 - 1/nsteps)
    	s = np.s_[-xymax:xymax:nsteps*1j]
    	Y, X = np.mgrid[s, s]	


	grid_max = 200
	u = np.linspace(-200, 200, 400)
	X, Y = np.meshgrid(u, u)
        '''for j in range (1,400):
		xymax = 200 - 200/j
		print xymax '''
	print  X,Y

	
	# we compute the Z values
	#R = (X**2 + Y**2)*0.5
	#Z = sin(R)

                
def move():
     new_x += x
     new_y += y

if __name__ == '__main__':
    greetings()
   # location()
    zmesh()
   
   


        
   
