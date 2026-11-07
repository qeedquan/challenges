/*

You are provided with two numbers.

Your task is to calculate and output their product.

Input
The input consists of two lines, each containing one integer. The length of each integer does not exceed 250,000 characters.

Output
Print the product of the two given numbers.

Examples
Input #1
2
2

Answer #1
4

*/

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

cpp_int solve(cpp_int a, cpp_int b)
{
	return a * b;
}

int main()
{
	cout << solve(2, 2) << endl;
	cout << solve(2493058398649769467, 240854387569376763) << endl;

	return 0;
}
