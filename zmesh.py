""" Creat the mesh and work on it""""

import numpy as np
import scipy.interpolate as interp
import bpy


# Settings
name = 'zmesh'
rows = 200
columns = 200
width = 200
size = 1

class zmesh(object):
  
  
  def __init__(self,grid_max, time):
    
    xymax = grid_max*(1 - 1/nsteps) # the midpoint of a cell
   

  def vert(column, row, width):
      """ Create a single vert """

    return (column * size, row * size, width*size)

  # creating the grid
    verts = [vert(x, y, z) for x in range(columns) for y in range(rows) for z in range(width)]
 
  # Create Mesh Datablock
    mesh = bpy.data.meshes.new(name)
   
  # Create Object and link to scene
   obj = bpy.data.objects.new(name, mesh)
   bpy.context.scene.objects.link(obj)

  # Select the object
   bpy.context.scene.objects.active = obj
   obj.select = True


        
   
