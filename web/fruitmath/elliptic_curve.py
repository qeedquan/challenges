#!/usr/bin/env python3

"""

https://www.youtube.com/watch?v=tXTV86cZZ6s
https://publikacio.uni-eszterhazy.hu/2858/1/AMI_43_from29to41.pdf

x/(y + z) + y/(x + z) + z/(x + y) = 4

(x^3 + x^2 y + x^2 z + x y^2 + 3 x y z + x z^2 + y^3 + y^2 z + y z^2 + z^3) = 4(x + y)(x + z)(y + z)

"""

import math

"""

Defines a point on the elliptic curve.
To satisfy the constraint of point being on the curve, use the following equation:

u = x + y
v = x + z
w = x + y

2x = -u + v + w
2y = u - v + w
2z = u + v - w

vw(v + w) + uw(u + w) + uv(u + v) = 11uvw

"""

class Point(tuple):
    def __new__(cls, *u):
        # The point we are passed is (u, v, w), check if it satisfies the equation above
        r = 0
        for i, j in [(0, 1), (0, 2), (1, 0), (1, 2), (2, 0), (2, 1)]:
            r += u[i] * u[j] * u[j]
        r -= 11*u[0]*u[1]*u[2]

        assert r == 0, "{} not on the curve!".format(u)
        if u[0] < 0 or (u[0] == 0 and u[0] > u[1]) or (u[0] == 0 and u[0] == u[1] and u[1] > u[2]):
            return tuple.__new__(cls, tuple(-_ for _ in u))
        return tuple.__new__(cls, u)

    # Converts the (u, v, w) point to (x, y, z)
    def xyz(self):
        x = tuple(sum(self) - 2*u for u in self)
        return x if any(_%2 for _ in x) else tuple(_//2 for _ in x)

    # Chord construction
    # Returns w = su + tv
    def __mul__(self, v):
        u = self
        if u[0]*v[1] == u[1]*v[0] and u[0]*v[2] == v[2]*u[0] and u[1]*v[2] == u[2]*v[1]:
            # if x, y are proportional, use tangent instead
            w = u.tangent()
        else:
            p = q = 0
            for i, j in [(0, 1), (0, 2), (1, 0), (1, 2), (2, 0), (2, 1)]:
                p += u[i]*u[i]*v[j] + 2 * u[i]*v[i]*u[j]
                q += v[i]*v[i]*u[j] + 2 * v[i]*u[i]*v[j]
            p -= 11 * (u[0]*u[1]*v[2] + u[0]*v[1]*u[2] + v[0]*u[1]*u[2])
            q -= 11 * (v[0]*v[1]*u[2] + v[0]*u[1]*v[2] + u[0]*v[1]*v[2])
            w = u[0]*q - v[0]*p, u[1]*q - v[1]*p, u[2]*q - v[2]*p
        g = math.gcd(*w)
        w = Point(*(_//g for _ in w))
        return w

    def tangent(self):
        u = self
        # gradient of the cubic
        g = (2 * u[0] * (u[1]+u[2]) + u[1]*u[1] + u[2]*u[2] - 11*u[1]*u[2],
             2 * u[1] * (u[0]+u[2]) + u[0]*u[0] + u[2]*u[2] - 11*u[0]*u[2],
             2 * u[2] * (u[0]+u[1]) + u[0]*u[0] + u[1]*u[1] - 11*u[0]*u[1])
        # orthogonal direction to the curve (cross product of g and u)
        v = (g[1]*u[2] - g[2]*u[1], g[2]*u[0] - g[0]*u[2], g[0]*u[1] - g[1]*u[0])
        
        p = q = 0
        for i, j in [(0, 1), (0, 2), (1, 2), (1, 0), (2, 0), (2, 1)]:
            p += v[i]*v[i]*u[j] + 2*v[i]*u[i]*v[j]
            q += v[i]*v[i]*v[j]
        p -= 11*(v[0]*v[1]*u[2] + v[0]*u[1]*v[2] + u[0]*v[1]*v[2])
        q -= 11*(v[0]*v[1]*v[2])

        return Point(u[0]*q - v[0]*p, u[1]*q - v[1]*p, u[2]*q - v[2]*p)

    def __neg__(self):
        z = self
        return Point(z[0], z[2], z[1])

# The idea is to use the "multiplication" operator defined as a generator
# Keep generating new points on the curve until we find all positive coefficients that satisfies the (x, y, z) equation
def find_positive_solution(*point, n=10):
    pts = list(point)
    count = len(pts)
    for step in range(n):
        for i in range(len(pts)):
            for j in range(i + 1):
                z = pts[i] * pts[j]
                if z not in pts:
                    pts.append(z)
                    count += 1
                    u = z.xyz()
                    if all(_ > 0 for _ in u):
                        return u
    return None

P1 = Point(1, 0, 0)

# Q is a point on the elliptic curve that was found using brute force that satisfies the (u, v, w) construction
# One of the (x, y, z) terms has a negative coefficient though, so the point can't be a solution
# The point can serve as one of the set of points to find the solution
Q = Point(10, 3, 2)

print(find_positive_solution(P1, Q))

