/*

To rotate string by K characters means to cut these characters from the beginning and transfer them to the end. If K is negative, characters, on contrary should be transferred from the end to the beginning.

Input data will contain the number of test-cases in the first line.
Following lines will contain number K and some string S separated by space - one pair in each line.
String S will contain only lowercase latin letters. K will not exceed half the length of S by absolute value.
Answer should contain strings rotated in accordance with the rule above, separated by spaces. For example:

input data:
2
3 forwhomthebelltolls
-6 verycomplexnumber

answer:
whomthebelltollsfor numberverycomplex
The task could be easily solved by creating new instance of string concatenating two substrings. However, if you want more serious challenge, you are encouraged to perform rotation "in-place", moving bytes of original string (i.e. without allocating memory for new instance). This could be done with the help of a loop and only one temporary variable.

*/

#include <cassert>
#include <string>

using namespace std;

template <typename T>
T mod(T x, T m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

string rotate_left(string input, ssize_t amount)
{
	ssize_t length = input.size();
	if (length == 0)
		return input;
	amount = mod(amount, length);
	return input.substr(amount) + input.substr(0, amount);
}

int main()
{
	assert(rotate_left("forwhomthebelltolls", 3) == "whomthebelltollsfor");
	assert(rotate_left("verycomplexnumber", -6) == "numberverycomplex");

	return 0;
}
