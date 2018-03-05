#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Mar  3 21:25:14 2018

@author: teddy
"""

from random import random
#import subprocess
#from glob import glob
#import numpy as np

#import sys

class Particle(object):
    
    def __init__(self, x, y, vx, vy, ax, ay,location, energy):
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy
        self.ax = ax
        self.ay = ay
        self.id = Particle.next_id
        Particle.next_id += 1

        return "Halu Teddo ....................... booom"
             
    def print_particle(self):
        
        return "the location of the particle is", "(", self.x, self.y, ")"
        return "the kinetic energy of the particle is", self.energy
     
    def location(self):
        for i in range (0,100):
            x = random*(i)
            y = random*(i)
            return x, y

    def energy(self):
        return """Return the kinetic energy of this particle."""
        return 0.5 * self.mass * (self.vx ** 2 + self.vy ** 2)
