#!/usr/bin/env python3

"""

Imagine you are working on a 3D adaptation of the classical video game Asteroids. Your task is to write an algorithm that can create a random 3D asteroid.

This is a popularity contest, not code golf. Write nice code and create interesting results. Add other cool features if you want.

Rules:

Your algorithm must actually create the model, not just load it from an external source or similar.
The results must be (pseudo-)random. Running the algorithm several times must create different results.
Real-time capability is desirable, but not necessary.
Low or high polygon count? Realistic or stylized? You decide...
The output must be a mesh, either in memory or as a file such as Wavefront OBJ. In either case you need to render it in some way.
Explain your algorithm, so that everybody can learn from it.
Show some images of your results.

"""

import bpy
import random

"""

Ported from @r3mainer solution

Blender's built-in Python scripting is perfect for this sort of thing.

"""

def asteroid():
    bpy.ops.mesh.primitive_ico_sphere_add()
    bpy.ops.object.mode_set(mode='EDIT')
    bpy.ops.mesh.faces_shade_smooth()
    bpy.ops.mesh.select_mode(type='VERT')
    bpy.ops.mesh.select_random()
    bpy.ops.transform.resize(value=(random.uniform(1.1, 1.4), random.uniform(1.1, 1.4), random.uniform(1.1, 1.4)))
    bpy.ops.mesh.select_all(action='SELECT')
    bpy.ops.mesh.subdivide(smoothness=1)
    bpy.ops.mesh.select_random()
    bpy.ops.transform.resize(value=(random.uniform(1.05, 1.15), random.uniform(1.05, 1.15), random.uniform(1.05, 1.15)))
    bpy.ops.mesh.select_all(action='SELECT')
    bpy.ops.mesh.subdivide(smoothness=1)
    bpy.ops.mesh.select_random()
    bpy.ops.transform.resize(value=(random.uniform(0.92, 1.05), random.uniform(0.92, 1.05), random.uniform(0.92, 1.05)))
    bpy.ops.mesh.select_all(action='SELECT')
    bpy.ops.mesh.subdivide(smoothness=1)
    stretch = random.uniform(0.9,1.5)
    bpy.ops.transform.resize(value=(stretch,1,1))
    bpy.ops.transform.rotate(value=(random.uniform(-1.57, 1.57)), orient_axis=(random.uniform(-1.57, 1.57), random.uniform(-1.57, 1.57), random.uniform(-1.57, 1.57)))
    bpy.ops.object.mode_set(mode='OBJECT')

asteroid()
