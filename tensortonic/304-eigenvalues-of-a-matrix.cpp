/*

Calculate the eigenvalues of a square matrix whose eigenvalues are guaranteed to be real.

Av = λv

Here, A is the input matrix, v is a nonzero eigenvector, and λ is its eigenvalue.
Return all eigenvalues in ascending order as a NumPy array of floats.

Examples
Input: matrix = [[4, 1], [2, 3]]

Output: [2.0, 5.0]

Explanation: Both values satisfy the characteristic equation of the matrix.

Input: matrix = [[5]]

Output: [5.0]

Hint 1
Use np.linalg.eigvals(matrix) to compute the eigenvalues.

Hint 2
Use .real followed by np.sort() for the guaranteed-real output.

Requirements
Compute the eigenvalues with NumPy
Sort them in ascending order
Return a NumPy array of floating-point values
Constraints
matrix is a nonempty square numeric list
Every eigenvalue is real
Matrix dimensions are at most 100x100
Use NumPy only

*/

#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

using namespace std;

bool solve(Eigen::MatrixXd &A)
{
	Eigen::EigenSolver<Eigen::MatrixXd> solver(A);

	if (solver.info() != Eigen::Success)
	{
		cerr << "Decomposition failed!" << endl;
		return false;
	}

	cout << "Real parts:\n"
		 << solver.eigenvalues().real() << "\n\n";

	return true;
}

int main()
{
	Eigen::MatrixXd A1(2, 2);
	Eigen::MatrixXd A2(1, 1);

	A1 << 4, 1,
		2, 3;

	A2 << 5;

	solve(A1);
	solve(A2);

	return 0;
}
