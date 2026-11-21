%{

Normalize one 3D vector or every row in a batch to unit length:

v_normalized = v/norm(v)

Here norm(v) is the Euclidean norm.
A zero vector has no direction, so return a zero row for it.
Preserve the input shape and return a floating-point NumPy array.

Examples
Input: v = [3, 4, 0]

Output: [0.6, 0.8, 0]

Explanation: The vector norm is 5, so dividing each coordinate by 5 produces a unit vector.

Input: v = [[0, 0, 0], [1, 2, 2]]

Output: [[0, 0, 0], [0.333333, 0.666667, 0.666667]]

Hint 1
Compute norms with keepdims=True so they broadcast over coordinates.

Hint 2
Use np.divide(values, norms, out=np.zeros_like(values), where=norms != 0).

Requirements
Compute one norm per vector along the final axis
Divide nonzero vectors by their norms
Keep zero vectors equal to zero
Return a floating-point NumPy array with the input shape
Constraints
Input shape is (3,) or (N, 3)
Use NumPy only

%}

function normalize(v)
	v / norm(v)
end

normalize([3 4 0])
normalize([0 0 0; 1 2 2])
