%{

A homogeneous transformation combines a three-dimensional linear transformation and a translation in one 4x4 matrix:

T = [R t]
    [0 1]

Here, R is a 3x3 matrix and t is a three-dimensional translation vector.
For a point p = (x, y, z), form its homogeneous coordinate:

ph = [x y z 1]^T

Apply the transformation:

ph' = T*ph

Return the first three coordinates of every transformed point.
A single input point must produce an array of shape (3,),
while a batch must produce an array of shape (N, 3).

Examples
Input: T = [[1, 0, 0, 1], [0, 1, 0, 2], [0, 0, 1, 3], [0, 0, 0, 1]], points = [0, 0, 0]

Output: [1.0, 2.0, 3.0]

Explanation: Appending 1 allows the last column of T to translate the point by (1, 2, 3).

Input: T = [[0, -1, 0, 1], [1, 0, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]], points = [[1, 0, 0], [0, 1, 0]]

Output: [[1.0, 1.0, 0.0], [0.0, 0.0, 0.0]]

Hint 1
np.ones((points.shape[0], 1)) creates the homogeneous coordinate for a batch.

Hint 2
(T @ points_h.T).T applies one transform to every point at once.

Requirements
Accept T as a list representing a 4×4 homogeneous transformation
Accept either one three-dimensional point or a batch of points
Return a NumPy array with shape (3,) for one point or (N,3) for a batch
Process a batch without a Python loop over its points

Constraints
T has shape (4, 4)
Points has shape (3,) for one point or (N, 3) for a batch
Process a batch without a Python loop over its points

Constraints
T has shape (4, 4)
Points has shape (3,) or (N, 3)
1 <= N <= 100,000
Use NumPy only

%}

T1 = [[1 0 0 1]; [0 1 0 2]; [0 0 1 3]; [0 0 0 1]];
T2 = [[0 -1 0 1]; [1 0 0 0]; [0 0 1 0]; [0 0 0 1]];

p1 = [0 0 0 1];
p2 = [[1 0 0 1]; [0 1 0 1]];

(T1 * p1')
(T2 * p2')

