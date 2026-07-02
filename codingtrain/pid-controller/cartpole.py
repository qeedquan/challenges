#!/usr/bin/env python3

"""

https://www.youtube.com/watch?v=fWQWX9-8_sA

Use a PID controller to balance a pole on a cart (a standard control theory problem)

"""

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FFMpegWriter
from matplotlib.patches import Rectangle

# Pendulum parameters
# Gravity (m/s)
g = 9.8
# Length (m)
L = 1
# Cart mass (kg)
m1 = 2
# Pendulum mass (kg)
m2 = 1
# Viscous friction coefficient
b = 0.0

# Time Vector for simulation
# Time Step
dt = 0.001
# Length of simulation
sim_time = 10
t_vec = np.arange(0, sim_time, dt)

# State Vectors
vec_size = len(t_vec)
x_vec = np.zeros(vec_size)
dx_vec = np.zeros(vec_size)
theta_vec = np.zeros(vec_size)
dtheta_vec = np.zeros(vec_size)

# Pole End Effector location for Animation
x_pole = np.zeros(vec_size)
y_pole = np.zeros(vec_size)

# Set initial conditions
# Cart Position
x_vec[0] = 0
# Cart Velocity
dx_vec[0] = 0
# Pole Angle
theta_vec[0] = 9*np.pi/10
# Pole Angular Velocity
dtheta_vec[0] = 0

# Initial Pole End Effector Location
y_offset = 0
x_pole[0] = x_vec[0] + L*np.sin(theta_vec[0])
y_pole[0] = y_offset - L*np.cos(theta_vec[0])

# Euler Simulation using State Space Form
A = np.array([[m1 + m2, 0], [0, 1/3*m2*L**2]])
B = np.array([0, 0])

error_int = 0
for i in range(1, vec_size):
    # Control Input
    thetades = np.pi
    Kp = 50
    Ki = 1
    Kd = 10
    e = thetades - theta_vec[i-1]
    de_dt = -dtheta_vec[i-1]
    error_int = error_int + e*dt
    u = Kp*e + Kd*de_dt + Ki*error_int
    
    # Only the off diagonal needs to be updated
    A[0, 1] = 0.5 * m2 * L * np.cos(theta_vec[i-1])
    A[1, 0] = A[0, 1]
    # B is updated every iteration
    B[0] = -0.5 * m2 * L * dtheta_vec[i-1]**2 * np.sin(theta_vec[i-1]) - b + u
    B[1] = -0.5 * m2 * L * g * np.sin(theta_vec[i-1])
    [ddx, ddtheta] = np.linalg.solve(A, B)
    
    # Apply control for acceleration of theta
    # If no control, set u=0
    ddtheta += u

    # use ddx and ddtheta to solve
    x_vec[i] = x_vec[i-1] + dx_vec[i-1]*dt
    theta_vec[i] = theta_vec[i-1] + dtheta_vec[i-1]*dt
    dx_vec[i] = dx_vec[i-1] + ddx*dt
    dtheta_vec[i] = dtheta_vec[i-1] + ddtheta*dt
    # Extra states for animation
    x_pole[i] = x_vec[i] + L*np.sin(theta_vec[i])
    y_pole[i] = y_offset - L*np.cos(theta_vec[i])

# Create animation
fig, ax = plt.subplots()
p, = ax.plot([], [], color='royalblue')
min_lim = -5
max_lim = 5
ax.axis('equal')
ax.set_xlim([min_lim, max_lim])
ax.set_ylim([min_lim, max_lim])
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_title('Cartpole Simulation')
title = 'cartpole'

FPS = 20
sample_rate = int(1 / (dt * FPS))
dpi = 300
writer = FFMpegWriter(fps=FPS)

# Cart
width = 1
height = width / 2
xy_cart = (x_vec[0] - width/2, y_offset - height/2)
r = Rectangle(xy_cart, width, height, color='cornflowerblue')
ax.add_patch(r)

# Ground
ground = ax.hlines(-height/2, min_lim, max_lim, colors='black')
height_hatch = 0.25
width_hatch = max_lim - min_lim
xy_hatch = (min_lim, y_offset - height/2 - height_hatch)
ground_hatch = Rectangle(xy_hatch, width_hatch, height_hatch, facecolor='None')
ax.add_patch(ground_hatch)

with writer.saving(fig, title + ".mp4", dpi):
    for i in range(0, vec_size, sample_rate):
        x_pole_arm = [x_vec[i], x_pole[i]]
        y_pole_arm = [y_offset, y_pole[i]]
        p.set_data(x_pole_arm, y_pole_arm)
        r.set(xy=(x_vec[i] - width/2, y_offset - height/2))
        fig.canvas.draw()
        writer.grab_frame()
