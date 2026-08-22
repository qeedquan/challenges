/*

Write a program to do the following:

input: a base ten (non-fractional) number at the command line

output: the binary representation of that number.

*/

#include <iostream>
#include <format>

using namespace std;

string dec2bin(int value)
{
	return format("{:b}", value);
}

int main()
{
	for (auto i = 0; i <= 32; i++)
		cout << i << ": " << dec2bin(i) << endl;

	return 0;
}
