/*

Description

As we known, data stored in the computers is in binary form. The problem we discuss now is about the positive integers and its binary form.

Given a positive integer I, you task is to find out an integer J, which is the minimum integer greater than I, and the number of '1's in whose binary form is the same as that in the binary form of I.

For example, if "78" is given, we can write out its binary form, "1001110". This binary form has 4 '1's. The minimum integer, which is greater than "1001110" and also contains 4 '1's, is "1010011", i.e. "83", so you should output "83".

Input

One integer per line, which is I (1 <= I <= 1000000).

A line containing a number "0" terminates input, and this line need not be processed.

Output

One integer per line, which is J.

Sample Input

1
2
3
4
78
0

Sample Output

2
4
5
8
83

Source

POJ Monthly,zby03

*/

#include <cassert>
#include <algorithm>
#include <string>

using namespace std;

unsigned shift(string str)
{
	next_permutation(str.begin(), str.end());
	auto val = 0u;
	auto len = str.size();
	for (size_t i = 0; i < len; i++)
	{
		if (str[i] == '1')
			val = val + (1 << (len - i - 1));
	}
	return val;
}

string strbin(unsigned n)
{
	string str = "";
	for (; n; n >>= 1)
	{
		if (n & 1)
			str = "1" + str;
		else
			str = "0" + str;
	}
	str = "0" + str;
	return str;
}

unsigned binform(unsigned n)
{
	return shift(strbin(n));
}

int main()
{
	assert(binform(1) == 2);
	assert(binform(2) == 4);
	assert(binform(3) == 5);
	assert(binform(4) == 8);
	assert(binform(78) == 83);

	return 0;
}
