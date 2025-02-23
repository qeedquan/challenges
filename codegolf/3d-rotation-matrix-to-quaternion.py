#!/usr/bin/env python3

"""

There are multiple ways to represent a 3D rotation. The most intuitive way is the rotation matrix -

     A11 A12 A13
A =  A21 A22 A23
     A31 A32 A33

rotates a point p = (x,y,z)^T by left-multiplication: p'=Ap.
This is however inefficient since a 3D rotation has only three degrees of freedom, so I personally prefer the quaternion representation where p is interpreted as the quaternion 0+xi+yj+zk and then conjugated by the rotating unit quaternion q to get p'=qpq*.
Dropping the scalar (first) part leaves the rotated 3D point.

A can be converted to a quaternion q=s+ai+bj+ck with the same effect as follows:

s = sqrt(1 + A11 + A22 + A33) / 2
a = (A32 - A23) / (4s)
b = (A13 - A31) / (4s)
c = (A21 - A12) / (4s)

Note that -q has the same effect as q by distribution of scalars in qpq∗, so the quaternion representation is not unique.

Task
Given a 3D rotation matrix – an orthogonal (to floating-point error) 3×3 real matrix with determinant 1 - output a quaternion with the same effect as that matrix to within 10^-6 entrywise relative error.

You may use any reasonable and consistent formats for input and output, and any correct formula for the calculation (including the one in the previous section).
In particular the code has to handle s=0 cases, for which alternate formulas are available from this paper:

ta = sqrt(1 + A11 - A22 - A33) / 2
tb = sqrt(1 - A11 + A22 - A33) / 2
tc = sqrt(1 - A11 - A22 + A33) / 2

b = (A32 + A23) / (4*tc)
c = (A13 + A31) / (4*ta)
a = (A21 + A12) / (4*tb)

This is code-golf; fewest bytes wins.

Test cases
These are in the format A -> q. The random cases were generated through this program - you can make your own cases there too!

[[1, 0, 0], [0, 1, 0], [0, 0, 1]] -> [1.0, 0.0, 0.0, 0.0]
[[0, 0, 1], [1, 0, 0], [0, 1, 0]] -> [0.5, 0.5, 0.5, 0.5]
[[0, -1, 0], [1, 0, 0], [0, 0, 1]] -> [0.7071067811865476, 0.0, 0.0, 0.7071067811865476]
[[-1, 0, 0], [0, -1, 0], [0, 0, 1]] -> [0.0, 0.0, 0.0, 1.0]
[[0, 1, 0], [1, 0, 0], [0, 0, -1]] -> [0.0, 0.7071067811865476, 0.7071067811865476, 0.0]
[[0.1508272311227814, -0.2824279103927633, -0.9473571775117411], [-0.7156381696218376, -0.692324273056756, 0.09246140338941596], [-0.6819920501971715, 0.6640192590336603, -0.3065375459878405]] -> [0.19491370659742277, 0.7330908965072773, -0.3403623223156108, -0.5556436573799196]
[[0.13019043201085, -0.4676759473774085, -0.874259492174647], [0.4976035235357375, 0.7934932016832866, -0.35037019314894013], [0.8575786755614011, -0.3894197569808834, 0.33602242201273236]] -> [0.7516159351202696, -0.01298853643440075, -0.5760382686201726, 0.32106805677246825]


"""

import numpy as np

"""

https://en.wikipedia.org/wiki/Rotation_matrix#Quaternion

This method will work for the case s=0 in the above equations and also matrices that have drifted due to numerical errors.
Construct a 4x4 symmetric matrix out of the 3x3 rotation matrix and find the eigenvalues/eigenvectors for it.
The largest eigenvalue of the 4x4 matrix will correspond to the eigenvector that represents the closest quaternion fit.

"""

def rotm2quat(R):
    xx, xy, xz = R[0][0], R[0][1], R[0][2]
    yx, yy, yz = R[1][0], R[1][1], R[1][2]
    zx, zy, zz = R[2][0], R[2][1], R[2][2]
    
    K = 1/3 * np.array([
        [xx - yy - zz, yx + xy,      zx + xz,      zy - yz],
        [yx + xy,      yy - xx - zz, zy + yz,      xz - zx],
        [zx + xz,      zy + yz,      zz - xx - yy, yx - xy],
        [zy - yz,      xz - zx,      yx - xy,      xx + yy + zz]
    ])
    
    w, v = np.linalg.eig(K)
    e = v[:,np.argmax(w)]
    q = [e[3], e[0], e[1], e[2]]
    return np.array(q)

def test(R, q):
    p = rotm2quat(R)
    print(p)
    assert(np.allclose(p, q) or np.allclose(p*-1, q))

def main():
    test([[1, 0, 0], [0, 1, 0], [0, 0, 1]], [1.0, 0.0, 0.0, 0.0])
    test([[0, 0, 1], [1, 0, 0], [0, 1, 0]], [0.5, 0.5, 0.5, 0.5])
    test([[0, -1, 0], [1, 0, 0], [0, 0, 1]], [0.7071067811865476, 0.0, 0.0, 0.7071067811865476])
    test([[-1, 0, 0], [0, -1, 0], [0, 0, 1]], [0.0, 0.0, 0.0, 1.0])
    test([[0, 1, 0], [1, 0, 0], [0, 0, -1]], [0.0, 0.7071067811865476, 0.7071067811865476, 0.0])
    test([[0.1508272311227814, -0.2824279103927633, -0.9473571775117411], [-0.7156381696218376, -0.692324273056756, 0.09246140338941596], [-0.6819920501971715, 0.6640192590336603, -0.3065375459878405]], [0.19491370659742277, 0.7330908965072773, -0.3403623223156108, -0.5556436573799196])
    test([[0.13019043201085, -0.4676759473774085, -0.874259492174647], [0.4976035235357375, 0.7934932016832866, -0.35037019314894013], [0.8575786755614011, -0.3894197569808834, 0.33602242201273236]], [0.7516159351202696, -0.01298853643440075, -0.5760382686201726, 0.32106805677246825])

main()
