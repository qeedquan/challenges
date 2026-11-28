%{

Given a vector v in Rn, construct a NxN matrix whose main diagonal contains v
and whose remaining entries are zero:

D[i, j] = v[i]   if i = j
          0      if i != j


Here, i and j are row and column indices.
Construct the matrix without np.diag and return it as a NumPy array.

Examples
Input: v = [3, 5]

Output: [[3, 0], [0, 5]]

Explanation: The two vector values occupy positions (0, 0) and (1, 1).

Input: v = [1.5]

Output: [[1.5]]

Input: v = [0, 0, 2]

Output: [[0, 0, 0], [0, 0, 0], [0, 0, 2]]

Hint 1
Initialize the output with np.zeros((values.size, values.size), dtype=values.dtype).

Hint 2
Assign with matrix[np.arange(values.size), np.arange(values.size)] = values.

Requirements
Create a square zero matrix with the same dtype as the input vector
Place each vector element at the matching row and column index
Do not use np.diag
Return a NumPy array of shape (N, N)
Constraints
v is a nonempty one-dimensional numeric list
Use NumPy only

%}

diag([3 5])
diag([1.5])
diag([0, 0, 2])
