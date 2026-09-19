/*

Your task is to solve N x N Systems of Linear Equations (e.g. Gauss Algorithm).
 
Here it's easy, you don't have to check errors or incorrect input values, every thing is ok and every given LS has exactly none or one solution (different from endless solutions for N x M Systems - see my harder kata). More about LS you can find here or perhaps is already known.
 
First of all two easy examples:

1*x1 + 2*x2 + 0*x3 = 7
0*x1 + 0*x2 + 3*x3 = 8
0*x1 + 5*x2 + 6*x3 = 9

SOLUTION=(9,8; -1,4; 2,66666666666667)
 
You can see exactly one solution which fulfills every equation (1*9,8 + 2*-1,4 + 0*2,66666666666667 =7 a.s.o.).
 
Second example:

1*x1 + 2*x2 + 0*x3 = 7
0*x1 + 0*x2 + 0*x3 = 8
0*x1 + 5*x2 + 6*x3 = 9

SOLUTION=NONE
 
There's no solution because the second equation isn't solvable.
 
So what info is missing?
 
You have to build a function "public string Solve (string input)" which takes the equations as an input string. "\r\n" (CRLF) separates the single equations, " " (SPACE) separates the numbers (like 3 or -1,5 only the coefficients not the xi's), each last number per line is the number behind the "=" (the equation result, see examples). The result of the function is the solution given as a string. All test examples will be syntactically correct, once again you don't need to take care of it.
 
So for the first example you have to call: Solve ("1 2 0 7\r\n0 0 3 8\r\n0 5 6 9"). The result of Solve is "SOLUTION=(9,8; -1,4; 2,66666666666667)", exactly in this form/syntax. Spaces in your result are allowed, but not necessary. Missing ";" or "(" throws an error. If there exists no solution you have to respond with "SOLUTION=NONE".
 
One last word to the tests:
The testfunction solves the given equations with your solution and accepts results which don't differ more than 1e-6 (precision) for each number - so no problem for you;-)!
 

Hope you have fun:-)!

*/

#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;
using namespace std;

int main()
{
	auto M1 = MatrixXf(3, 3);
	auto M2 = MatrixXf(3, 3);
	auto M3 = MatrixXf(2, 2);
	auto M4 = MatrixXf(4, 4);
	M1 << 1, 2, 0,
		0, 0, 3,
		0, 5, 6;
	M2 << 1, 2, 0,
		0, 0, 0,
		0, 5, 6;
	M3 << 1, 2,
		1, 2;
	M4 << 1, 2, 0, 4,
		0, 2, 0, 2,
		0, 0, -1, 4,
		1, 2, 3, 2;

	auto b1 = VectorXf(3);
	auto b2 = VectorXf(3);
	auto b3 = VectorXf(2);
	auto b4 = VectorXf(4);
	b1 << 7, 8, 9;
	b2 << 7, 9, 9;
	b3 << 1, 0;
	b4 << 7, 8, 6, 3;

	VectorXf x1 = M1.lu().solve(b1);
	VectorXf x2 = M2.lu().solve(b2);
	VectorXf x3 = M3.lu().solve(b3);
	VectorXf x4 = M4.lu().solve(b4);

	cout << x1 << endl
		 << endl;
	cout << x2 << endl
		 << endl;
	cout << x3 << endl
		 << endl;
	cout << x4 << endl
		 << endl;

	return 0;
}
