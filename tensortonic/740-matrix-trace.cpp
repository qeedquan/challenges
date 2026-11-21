/*

Compute the trace of a square matrix, which is the sum of its main-diagonal entries:

tr(A) = Sum[i=1, N] A[i][i]

Here, A is a NxN matrix and A[i][i] is its entry in row i and column i.
Compute the sum directly from indexed elements and return it as a Python float.

Examples
Input: A = [[1, 2], [3, 4]]

Output: 5

Explanation: The main diagonal contains 1 and 4.

Input: A = [[2, -1, 0], [3, 5, 1], [0, 2, -2]]

Output: 5

Input: A = [[42]]

Output: 42

Hint 1
Accumulate A[i, i] for i from zero through A.shape[0] - 1.

Hint 2
Convert the final NumPy scalar with float(total).

Requirements
Sum the entries whose row and column indices are equal
Do not use np.trace or np.diagonal
Return a Python float
Constraints
A is a nonempty square numeric matrix
Matrix entries may be integers or floating-point values
Use NumPy only

*/

#include <cassert>
#include <Eigen/Dense>

int main()
{
	Eigen::MatrixXd M1(2, 2);
	Eigen::MatrixXd M2(3, 3);
	Eigen::MatrixXd M3(1, 1);

	M1 << 1, 2,
		3, 4;

	M2 << 2, -1, 0,
		3, 5, 1,
		0, 2, -2;

	M3 << 42;

	assert(M1.trace() == 5);
	assert(M2.trace() == 5);
	assert(M3.trace() == 42);

	return 0;
}
