/*

Find the eigenvalues for the following matrix:

A = 1 -3 3
    3 -5 3
    6 -6 4

Then print the smallest eigenvalue on the first line and the largest eigenvalue on the second line. For example:

5
6
Note: You must print exactly two distinct values.

*/

#include <iostream>
#include <Eigen/Eigenvalues>

using namespace std;
using namespace Eigen;

int main()
{
	Matrix3d M;
	M << 1, -3, 3,
	    3, -5, 3,
	    6, -6, 4;
	
	cout << M.eigenvalues() << endl;

	return 0;
}
