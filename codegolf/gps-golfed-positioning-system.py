#!/usr/bin/env python3

"""

Your mission, should you choose to accept it, is to write code for a GPS receiver.

Input
The current time, as nanoseconds from the Unix epoch. [EDIT: This is optional, please state whether you require it]
Four satellite signals, in the following format:
The time the signal was sent, as nanoseconds from the Unix epoch. You must be able to handle dates up to and including 2020.
The location of the satellite, as Cartesian coordinates, in metres. You must be able to handle values that fit into a signed 32-bit integer (-2,147,483,648 to 2,147,483,647). Only integer coordinates will be given. You may assume valid input (i.e. your position can be calculated)
Input can be provided from command-line arguments, standard input or equivalent, but not from a variable. The input can have any separator characters in it; please specify what your input format is.

Output
The coordinates of your receiver, to the nearest 1000 metres, using 299,792,458 m/s as the speed of light. Again, I will be lenient with the output format: any separators are acceptable.

Example
Input

1412349052664203400
[1412349052692915310,2267943, 13318342, 0]
[1412349052698278110,-3757960, 3500627, 0]
[1412349052691548521,4425976, -1533193, 3469445]
[1412349052687888295,10622179, 11246951, 84184]

Output

(6223615, 5673496, 0)
I have made a GeoGebra notebook for this example. Please excuse my extremely sloppy GeoGebra skills.

How GPS Works
Because the speed of light is finite, there will be a difference between your current time and the time the satellite sent the signal.

Use the difference to calculate the distance to the satellite, d.
You are clearly located somewhere on the surface of a sphere, centered on the satellite, with radius d.
Once you have two satellites and two spheres, you have to be located somewhere on the intersection of the two sphere surfaces, which is a circle.
Adding another satellite reduces the possible positions to just two points, where all three sphere surfaces intersect.
The fourth satellite allows you to decide on a specific one of these points. Your task is to calculate the location of this point, where all four spheres intersect. Since you assume valid input, such a point does exist.

Rules
Standard loopholes are banned.

"""

import numpy as np
import sys

"""

@flawr

As I said the posed problem seems to result in something about 200 to 300m off in the z coordinate compared to the given solution so this entry does not work within the 100m precision assuming the given test case is correct.

You can interpret your position as the intersectionpoint of four spheres, since you can calculate the distance to each sattelite by the runtime.
The points [x,y,z] on a sphere with center [x,y,z] and radius r can be written as an equation (so 4 satellites = 4 equations):

(x-x0)^2 + (y-y0)^2 + (z-z0)^2 = r^2
Or when expanded / transformed:

-2*x0*x -2*y0*y -2*z0*z = r^2 - x0^2 - y0^2 - z0^2 - x^2 - y^2 - z^2
As you have 4 equations that look like that you can substract one from the other three, which eliminates the x^2+y^2+z^2 and get a system of 3 linear equations that can easily be solved for x,y,z.

But 3 intersecting spheres would result in two possible points, so a fourth is only needed for choosing the right one of those two points.
But if the intersection point of the first three is not exactly on the fourth sphere you cannot get an accurate answer.

Normally for gps you have the earth as fourth sphere, so three satelites could give you a line on which your current position must be (when the current exact time is unknown).
The line intersected with the earth surface results in only two possible points. So by comparing the different timestamps you could estimate on which side of the earth you are.

"""

def solve(epoch, receivers):
    lightspeed = 299792458

    # Extract the positions and timestamps into row matrices
    # P = [[x1 y1 z1] [x2 y2 z2] ...]
    # T = [[t0] [t1] [t2] ...] 
    positions = receivers[0:4:, 1:4:]
    timestamps = receivers[0:4:, 0:1:]
    
    # Center the timestamps relative to the epoch time and convert it into seconds, then scale it by the speed of light
    timestamps = (timestamps - epoch)/1e9 * lightspeed
    
    # Since we have redundant information with 4 positions, subtract the last position from the first 3 positions and get the following:
    # Q = 3x3 position matrix (full_position_matrix - last_position)
    # B = 3x3 position matrix squared (full_position_matrix^2 - last_position^2) 
    # S = 3x1 timestamp matrix (full_timestamp_matrix^2 - last_timestamp^2)
    ones = np.ones((3, 1))
    Q = positions[0:3:, 0:3:] - np.outer(ones, receivers[3][1:4])
    B = positions[0:3:, 0:3:]**2 - np.outer(ones, receivers[3][1:4])**2
    S = timestamps[0:3, 0:1:]**2 - np.outer(ones, timestamps[3])**2

    # We want to solve Ax = b where
    # A = -2*Q
    # b = tr(tr(S) - sum(B, 2))
    A = -2 * Q
    b = np.transpose(np.transpose(S) - np.sum(B, axis=1))
    return np.dot(np.linalg.inv(A), b)

def main():
    np.set_printoptions(suppress=True)
    print(solve(1412349052664203400, np.array([[1412349052692915310, 2267943, 13318342, 0], [1412349052698278110, -3757960, 3500627, 0], [1412349052691548521, 4425976, -1533193, 3469445], [1412349052687888295, 10622179, 11246951, 84184]])))

main()
