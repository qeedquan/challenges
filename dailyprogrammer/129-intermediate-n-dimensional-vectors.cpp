/*

N-Dimensional vectors are vectors with n-components; it can be interpreted as a point in n-dimensional space. 2-dimensional (2D) vectors can be seen as a line on paper. 3D vectors can be seen as a line (direction with length) in regular space. You can represent higher n-dimensions in many different ways, but what we're interested in is the three common vector operations: length, normilization, and dot-product.

You are to implement code that first accepts a few vectors, the operations you want to perform on them, and their results.

Note: this Friday's upcoming [Hard] challenge will be to implement the cross-product computation (for only 3-dimensions). You are encouraged to bring the code you write for this solution as a starting point for the associated [Hard]-level challenge!

Original author: u/nint22

Formal Inputs & Outputs
Input Description
You will be given an integer N on standard input, which represents the N-following number of lines of text. The start of each line will be a positive non-zero integer A, where A is the following number of space-delimited Real number (floating-point in many languages). These numbers representing a vector of A-dimensions (or an A-component vector). After these N-lines of text, expect a single line with an integer M, which represents the M-following number of lines of text. Each line will start with the characters 'l', 'n', or 'd', representing the function you are to compute. After that, you can expect one or two space-delimited integers. These integers represent the index of the above-defined vectors; the indexing scheme starts at zero (0). An 'l' and 'n' line will be given a single integer, while a 'd' will be given two space-delimited integers.

Output Description
For each line that defines the function ('l' for length, 'n' for normalize, and 'd' for dot-product) and operands (the vector values based on the given indices), you are to print the result of the appropriate computation on standard console output. The length-function must compute the given vector's Euclidean space length. The normalize-function must compute the given vector's Unit vector. Finally, the Dot-product function must compute the two given vector's, well... Dot Product! When printing your result, you may choose however you print the result (regular float, or scientific notation), but you must be accurate with 5 decimals.

Sample Inputs & Outputs
Sample Input
5
2 1 1
2 1.2 3.4
3 6.78269 6.72 6.76312
4 0 1 0 1
7 84.82 121.00 467.05 142.14 592.55 971.79 795.33
7
l 0
l 3
l 4
n 1
n 2
n 3
d 0 1
Sample Output
1.4142
1.4142
1479.26
0.33282 0.94299
0.579689 0.574332 0.578017
0 0.707107 0 0.707107
4.6

*/

#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

typedef vector<double> Vector;

double length(const Vector &vector)
{
	double value = 0;
	for (auto element : vector)
		value += element * element;
	return sqrt(value);
}

double dot(const Vector &vector0, const Vector &vector1)
{
	double value = 0;
	for (size_t i = 0; i < vector0.size(); i++)
		value += vector0[i] * vector1[i];
	return value;
}

Vector normalize(const Vector &vector)
{
	auto modulus = length(vector);
	auto xvector = vector;
	if (modulus == 0)
		return xvector;
	for (size_t i = 0; i < xvector.size(); i++)
		xvector[i] /= modulus;
	return xvector;
}

ostream &operator<<(std::ostream &stream, const Vector &vector)
{
	for (auto value : vector)
		stream << value << " ";
	return stream;
}

int main()
{
	Vector v0 = { 1, 1 };
	Vector v1 = { 1.2, 3.4 };
	Vector v2 = { 6.78269, 6.72, 6.76312 };
	Vector v3 = { 0, 1, 0, 1 };
	Vector v4 = { 84.82, 121.00, 467.05, 142.14, 592.55, 971.79, 795.33 };

	cout << length(v0) << endl;
	cout << length(v3) << endl;
	cout << length(v4) << endl;
	cout << normalize(v1) << endl;
	cout << normalize(v2) << endl;
	cout << normalize(v3) << endl;
	cout << dot(v0, v1) << endl;

	return 0;
}
