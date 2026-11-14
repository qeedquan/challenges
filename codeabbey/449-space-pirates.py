#!/usr/bin/env python3

"""

A space pirate ship is cruising slowly above the surface of an outlying planet, hiding from the galactic police. The pirates are currently unaware of the fact that there is a galactic police ship moving slowly on the other side of the planet, waiting for their next assignment. Neither ship is aware of the presence of the other. Otherwise the police ship would aim to capture the pirate ship and its crew; and the pirate ship would try hard to escape.

In a coordinate system which has the centre of the planet at its origin, both ships are moving with constant but different velocities. The sensors on both ships will simultaneously detect the presence of the other ship when the straight line between the two ships no longer passes through any part of the planet. You will be given the velocities of the two ships and their positions at time t = 0. You are to find the time (in seconds), rounded to the nearest second, when the ships first become aware of each other. It is guaranteed that the exact answer will be not more than 0.3 seconds from the nearest whole second.

All distances are in metres and velocities are in metres per second. The planet can be assumed to be a perfectly smooth sphere with radius R. The two ships will be designated P (pirate ship) and Q (police ship). The x, y and z coordinates are px, py and pz for the pirate ship, and qx, qy and qz for the police ship. The velocity components are vpx, vpy and vpz for the pirate ship, and vqx, vqy and vqz for the police ship. The velocity component vpx is just the distance travelled each second in the x direction by the pirate ship.

In order to keep this problem fairly simple, we have the two ships moving in straight lines within a fixed coordinate system, having the planet at its centre. In practice the paths travelled by each of the ships would be influenced by the motion of the planet as well as by its rotation and gravitational field. Incorporating all of this would make the problem significantly more complicated.

Input and Answer:
The first line of the problem will be a single integer T denoting the number of test cases.
Each test case has a single line of data containing 13 integers.
These are, in order, R, px, py, pz, vpx, vpy, vpz, qx, qy, qz, vqx, vqy, vqz.
For each test case give the time (in seconds) when the ships first become aware of each other; rounded to the nearest whole second. Combine all answers into a single string, separated by single spaces.

Example:

input:
2
5740542 -3170168 3774765 5814956 335 688 -2 -154959 1579076 -6298799 125 17 -2
10620322 -2959351 6815947 11383407 -671 -984 -43 4916081 1295871 -11055629 -704 -386 14

answer:
12960 15108

"""

import numpy as np
from scipy.optimize import fsolve

def solve(R, px, py, pz, vpx, vpy, vpz, qx, qy, qz, vqx, vqy, vqz):
    P0 = np.array([px, py, pz], dtype=float)
    Vp = np.array([vpx, vpy, vpz], dtype=float)
    Q0 = np.array([qx, qy, qz], dtype=float)
    Vq = np.array([vqx, vqy, vqz], dtype=float)

    # Objective function: find when closest distance squared to origin equals R^2
    def target_func(t):
        Pt = P0 + Vp * t
        Qt = Q0 + Vq * t
        Dt = Qt - Pt
        len_D2 = np.sum(Dt**2)

        if len_D2 == 0:
            return np.sum(Pt**2) - R**2

        # Projection factor s along the line segment
        s = -np.dot(Pt, Dt) / len_D2
        closest_point = Pt + s * Dt

        # Distance squared minus R squared
        return np.sum(closest_point**2) - R**2

    # Find the root starting a scan from t = 0 upwards to locate the sign change
    t_match = 0.0
    for t_guess in range(0, 100000, 10):
        if target_func(t_guess) > 0 and target_func(t_guess + 10) < 0:
            # Crossed into visibility zone
            t_match = fsolve(target_func, t_guess)[0]
            break
        elif target_func(t_guess) < 0 and target_func(t_guess + 10) > 0:
            t_match = fsolve(target_func, t_guess)[0]
            break
    return round(t_match)

def main():
    assert(solve(5740542, -3170168, 3774765, 5814956, 335, 688, -2, -154959, 1579076, -6298799, 125, 17, -2) == 12960)
    assert(solve(10620322, -2959351, 6815947, 11383407, -671, -984, -43, 4916081, 1295871, -11055629, -704, -386, 14) == 15108)

main()
