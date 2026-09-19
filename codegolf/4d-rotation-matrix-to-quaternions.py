#!/usr/bin/env python3

"""

It is well-known that a 3D rotation can always be represented by a quaternion.
It is less well-known that a 4D rotation can always be represented by two quaternions, sending a point p=(a,b,c,d)T represented as the quaternion a+bi+cj+dk to the point p′=xpy for an appropriate choice of unit quaternions x,y.

Let R be a 4D rotation matrix. Then the corresponding x,y can be obtained through a direct algorithm of Perez-Gracia and Thomas:

Compute S:
S = 1/4 * (R - A1*R*A1 - A2*R*A2 - A3*R*A3) where
A1 = [[0 0 0 -1] [0 0 -1 0] [0 1 0 0] [1 0 0 0]]
A2 = [[0 0 1 0] [0 0 0 -1] [-1 0 0 0] [0 1 0 0]]
A3 = [[0 -1 0 0] [1 0 0 0] [0 0 0 -1] [0 0 1 0]]

Set Y = S/(det(S)^1/4) and X=R*Y^T. We have R=XY where X and Y are the matrices of left- and right-isoclinic rotations respectively - very special matrices with at most four distinct magnitudes among their entries.
Finally x and y are the left-most columns of X and Y. The pair (-x,-y) also corresponds to R, analogous to the 3D case.

S above may have zero determinant, in which case one of the following alternative expressions should be used. These of course give different S matrices, but the steps afterwards are unchanged:
S = (-1/4) * (R*A1 + A1*R + A3*R*A2 - A2*R*A3)
S = (-1/4) * (R*A2 + A2*R + A1*R*A3 - A3*R*A1)
S = (-1/4) * (R*A3 + A3*R + A2*R*A1 - A1*R*A2)

Task
Given R - an orthogonal (to floating-point error) 4×4 real matrix with determinant 1 - output a corresponding (x,y) pair to within 10^-6 entrywise relative error.
You may use any reasonable and consistent formats for input and output, and any correct formula for the calculation (including the one in the previous section).

This is code-golf; fewest bytes wins.

Test cases
These are in the format R -> x y. The random cases were generated (and you can generate your own random cases) with this program.

import numpy as np
rng = np.random.default_rng()

def random_rotation(n=4):
 A = rng.normal(size=(n,n))
 Q, R = np.linalg.qr(A)
 B = Q @ np.diag(np.sign(np.diagonal(R)))
 if np.linalg.det(B) < 0:
  B[0] *= -1
 return B


[[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]] -> [1.0, 0.0, 0.0, 0.0] [1.0, 0.0, 0.0, 0.0]
[[-1, 0, 0, 0], [0, -1, 0, 0], [0, 0, -1, 0], [0, 0, 0, -1]] -> [1.0, 0.0, 0.0, 0.0] [-1.0, 0.0, 0.0, 0.0]
[[0, 0, 1, 0], [0, 0, 0, 1], [0, 1, 0, 0], [1, 0, 0, 0]] -> [1.0, 0.0, 0.0, 0.0] [0.0, 0.0, -1.0, 0.0]
[[0, 0, 1, 0], [-1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 0, -1]] -> [0.5, 0.5, 0.5, -0.5] [-0.5, -0.5, -0.5, -0.5]
[[0, 0, 0, -1], [1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0]] -> [0, -0.7071067811865476, 0, -0.7071067811865476] [-0.7071067811865476, 0, 0.7071067811865476, 0]
[[-0.6609058926555349, -0.30938449301078536, -0.6536493902436745, -0.2005669742797215], [-0.19737145221236216, 0.6931746532606626, 0.08266116424964398, -0.6882735952028355], [0.13703192282789176, -0.6502921800262064, 0.3686714537074865, -0.6499412988447983], [0.7109642487712476, 0.030169788832262925, -0.6557369638659809, -0.25224721015459695]] -> [0.560009784749661, 0.400037446835586, 0.272063553490942, 0.6725626401873549] [0.06637964559158858, 0.052592253308694104, 0.6737046111530368, 0.7341320688092741]
[[0.6544007065477859, -0.5813716570041381, -0.411235410397809, -0.2542678684713569], [0.6193101080207767, 0.7694074810291105, -0.005562224168405557, -0.1563207596643309], [0.38183012824424395, -0.12606111825246455, 0.23940297340390976, 0.8837423628837136], [-0.2059622745505508, 0.23265364607854452, -0.8795116345009956, 0.36043183434001774]] -> [0.9455738853169363, -0.26286929698266226, 0.18881691258838904, -0.033733271870118764] [0.5350303732855687, 0.7836340999984829, 0.31251919145079116, 0.044630168680125246]
This question and its 3D version were inspired by my answer to a MathsSE question. I needed to wrestle with 4D rotations when rendering images like these for this other MathsSE question which I have asked, and for which I have no answers:

"""

import numpy as np

def rotm4d2quat(R):
    A1 = np.array([[0, 0, 0, -1], [0, 0, -1, 0], [0, 1, 0, 0], [1, 0, 0, 0]])
    A2 = np.array([[0, 0, 1, 0], [0, 0, 0, -1], [-1, 0, 0, 0], [0, 1, 0, 0]])
    A3 = np.array([[0, -1, 0, 0], [1, 0, 0, 0], [0, 0, 0, -1], [0, 0, 1, 0]])
    
    S0 =  1/4 * (R - np.dot(np.dot(A1, R), A1) - np.dot(np.dot(A2, R), A2) - np.dot(np.dot(A3, R), A3))
    S1 = -1/4 * (np.dot(R, A1) + np.dot(A1, R) + np.dot(np.dot(A3, R), A2) - np.dot(np.dot(A2, R), A3))
    S2 = -1/4 * (np.dot(R, A2) + np.dot(A2, R) + np.dot(np.dot(A1, R), A3) - np.dot(np.dot(A3, R), A1))
    S3 = -1/4 * (np.dot(R, A3) + np.dot(A3, R) + np.dot(np.dot(A2, R), A1) - np.dot(np.dot(A1, R), A2))
    
    S = S0
    d = 0
    for M in [S0, S1, S2, S3]:
        S = M
        d = np.linalg.det(M)
        if d != 0:
            break

    Y = S / (d**0.25)
    X = np.dot(R, np.transpose(Y))
    return (X[:,0], Y[:,0])

def test(R, QX, QY):
    (X, Y) = rotm4d2quat(R)
    print(X, Y)
    print(QX, QY)
    print()
    assert((np.allclose(X, QX) and np.allclose(Y, QY)) or (np.allclose(X*-1, QY) or np.allclose(Y*-1, QY)))

def main():
    test([[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]], [1.0, 0.0, 0.0, 0.0], [1.0, 0.0, 0.0, 0.0])
    test([[-1, 0, 0, 0], [0, -1, 0, 0], [0, 0, -1, 0], [0, 0, 0, -1]], [1.0, 0.0, 0.0, 0.0], [-1.0, 0.0, 0.0, 0.0])
    test([[0, 0, 1, 0], [0, 0, 0, 1], [0, 1, 0, 0], [1, 0, 0, 0]], [1.0, 0.0, 0.0, 0.0], [0.0, 0.0, -1.0, 0.0])
    test([[0, 0, 1, 0], [-1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 0, -1]], [0.5, 0.5, 0.5, -0.5], [-0.5, -0.5, -0.5, -0.5])
    test([[0, 0, 0, -1], [1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0]], [0, -0.7071067811865476, 0, -0.7071067811865476], [-0.7071067811865476, 0, 0.7071067811865476, 0])
    test([[-0.6609058926555349, -0.30938449301078536, -0.6536493902436745, -0.2005669742797215], [-0.19737145221236216, 0.6931746532606626, 0.08266116424964398, -0.6882735952028355], [0.13703192282789176, -0.6502921800262064, 0.3686714537074865, -0.6499412988447983], [0.7109642487712476, 0.030169788832262925, -0.6557369638659809, -0.25224721015459695]], [0.560009784749661, 0.400037446835586, 0.272063553490942, 0.6725626401873549], [0.06637964559158858, 0.052592253308694104, 0.6737046111530368, 0.7341320688092741])
    test([[0.6544007065477859, -0.5813716570041381, -0.411235410397809, -0.2542678684713569], [0.6193101080207767, 0.7694074810291105, -0.005562224168405557, -0.1563207596643309], [0.38183012824424395, -0.12606111825246455, 0.23940297340390976, 0.8837423628837136], [-0.2059622745505508, 0.23265364607854452, -0.8795116345009956, 0.36043183434001774]], [0.9455738853169363, -0.26286929698266226, 0.18881691258838904, -0.033733271870118764], [0.5350303732855687, 0.7836340999984829, 0.31251919145079116, 0.044630168680125246])

main()
