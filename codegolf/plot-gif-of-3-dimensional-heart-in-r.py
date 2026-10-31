#!/usr/bin/env python3

"""

inspired by this blog: http://alstatr.blogspot.co.uk/2014/02/r-animating-2d-and-3d-plots.html I made a 2D gif of a heart with:

library(animation)
saveGIF({
for(i in 1:150){
dat<- data.frame(t=seq(0, 2*pi, by=0.1) )
xhrt <- function(t) 16*sin(t)^3
 yhrt <- function(t) 13*cos(t)-5*cos(2*t)-2*cos(3*t)-cos(4*t)
dat$y=yhrt(dat$t)
dat$x=xhrt(dat$t)
with(plot(x,y, type="l", xlim = c(-100  , i ^ 2 / 10 )) )
}
}, interval = 0.1, ani.width = 550, ani.height = 550)
I wonder if anyone out there could show me how to do this in 3D!

"""

import matplotlib.pyplot as plt
import numpy as np

# https://stackoverflow.com/questions/4680525/plotting-implicit-equations-in-3d
def plot_implicit(fn, bbox=(-2.5, 2.5)):
    xmin, xmax, ymin, ymax, zmin, zmax = bbox*3
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    A = np.linspace(xmin, xmax, 100) # resolution of the contour
    B = np.linspace(xmin, xmax, 15) # number of slices
    A1,A2 = np.meshgrid(A,A) # grid on which the contour is plotted

    for z in B: # plot contours in the XY plane
        X,Y = A1,A2
        Z = fn(X,Y,z)
        cset = ax.contour(X, Y, Z+z, [z], zdir='z')
        # [z] defines the only level to plot for this contour for this value of z

    for y in B: # plot contours in the XZ plane
        X,Z = A1,A2
        Y = fn(X,y,Z)
        cset = ax.contour(X, Y+y, Z, [y], zdir='y')

    for x in B: # plot contours in the YZ plane
        Y,Z = A1,A2
        X = fn(x,Y,Z)
        cset = ax.contour(X+x, Y, Z, [x], zdir='x')

    # must set plot limits because the contour will likely extend
    # way beyond the displayed level.  Otherwise matplotlib extends the plot limits
    # to encompass all values in the contour.
    ax.set_zlim3d(zmin,zmax)
    ax.set_xlim3d(xmin,xmax)
    ax.set_ylim3d(ymin,ymax)

    plt.show()

def hyp_part1(x, y, z):
    return -(x**2) - (y**2) + (z**2) - 1

# https://mathworld.wolfram.com/GoursatsSurface.html
def goursat_tangle(x, y, z):
    a, b, c = 0.0, -5.0, 11.8
    return x**4 + y**4 + z**4 + a*(x**2 + y**2 + z**2)**2 + b*(x**2 +y**2 + z**2) + c

# https://mathworld.wolfram.com/HeartSurface.html
def heart3d(x, y, z):
    return (x**2 + 9/4*y**2 + z**2 - 1)**3 - x**2*z**3 - 9/80*y**2*z**3

def main():
    plot_implicit(heart3d, bbox=(-1.5, 1.5))

main()
