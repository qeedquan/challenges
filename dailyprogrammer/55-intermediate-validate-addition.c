/*

Write a program that will allow the user to enter two characters. The program will validate the characters to make sure they are in the range '0' to '9'. The program will display their sum. The output should look like this.

INPUT .... OUTPUT

3 6 ........ 3 + 6 = 9
4 9 ........ 4 + 9 = 13
0 9 ........ 0 + 9 = 9
g 6 ........ Invalid
7 h ........ Invalid

thanks to frenulem for the challenge at r/dailyprogrammer_ideas .. please ignore the dots :D .. it was messing with the formatting actually

*/

#include <assert.h>
#include <ctype.h>

int
add(int a, int b)
{
	if (!isdigit(a) || !isdigit(b))
		return -1;
	return (a - '0') + (b - '0');
}

int
main()
{
	assert(add('3', '6') == 9);
	assert(add('4', '9') == 13);
	assert(add('0', '9') == 9);
	assert(add('g', '6') == -1);
	assert(add('7', 'h') == -1);

	return 0;
}
