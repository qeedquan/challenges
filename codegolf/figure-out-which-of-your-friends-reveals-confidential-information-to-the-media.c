/*

Exposition
You send secret information to 100 of your friends, and the next day you discover that the information has been published! Who could have revealed it?

To determine that, you number your friends 0...99 and encode the number in the message by altering spaces in it. You can replace each space " " by one or two spaces " " or "  ". Your unscrupulous friend will forward the message exactly as it is to the public media, and you will determine who it is by analyzing the spaces.

(I heard that something like this happened in real life, but couldn't find the details; is it an urban legend?)

Input
Your code must receive a text message (you can assume it's ASCII) and a number in the range 0...99. The message will not contain two adjacent spaces; it will not have space as a first or last character. It will contain at least 7 spaces.

The most obvious algorithm is to use a binary encoding of the input number. However, if you want to use another algorithm (e.g. unary), you can require the input message to contain any minimal number of spaces, up to 101.

Output
The output must be the same as input, with some spaces replaced by double spaces. The output must be different for different input numbers - it should be possible to discover the input number from the output message.

Twist
Your code should be a valid input to itself! That is, it can't contain two spaces one after another, and it should be able to output at least 100 different versions of itself when given to itself as input. And any output version of the code (with some of the spaces doubled) should do exactly the same as the original version.

Examples
Input: message = "Here is one example with 7 spaces. Seven!", number = 22
Possible output: "Here  is one  example  with 7 spaces. Seven!"

Input: message = "a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a", number = 33
Possible output: "a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a  a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a"

Input: "1 2 3 4 5 6 7"
Output: Undefined behavior - the input is invalid, contains too few spaces

Code: lambda s, x: ''.join(map(lambda a: a[0]+a[1],zip(s.split(),map(lambda n: (n+1)*' ',chain(map(int,list(bin(x)[2:])),repeat(0))))))[:-1]
Input: message = code, number = 42
Possible output: lambda  s, x:  ''.join(map(lambda a:  a[0]+a[1],zip(s.split(),map(lambda n: (n+1)*' ',chain(map(int,list(bin(x)[2:])),repeat(0))))))[:-1]
In the last example, I feed the code to itself. I had to add extra spaces to the code so it would satisfy the twist condition. Note: the last space in the code is essential to its correct execution - it should never be doubled! I had to make sure the code contains 7 spaces before it to ensure it wouldn't happen.

I wonder if it's possible to solve this challenge using the whitespace language. Are there any other languages for which it's hard but possible?

*/

#include <stdio.h>

char *
plant(const char *src, int num, char *dst)
{
	char *buf;

	for (buf = dst; *src; src++) {
		*buf++ = *src;
		if (*src == ' ') {
			if (num & 1)
				*buf++ = ' ';
			num >>= 1;
		}
	}
	*buf = '\0';

	return dst;
}

void
test(const char *src, int num)
{
	char dst[256];

	printf("'%s'\n", plant(src, num, dst));
}

int
main()
{
	test("Here is one example with 7 bits. Seven!", 22);
	test("a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a a", 33);
	test("1 2 3 4 5 6 7", 63);
	test("lambda s, x: ''.join(map(lambda a: a[0]+a[1],zip(s.split(),map(lambda n: (n+1)*' ',chain(map(int,list(bin(x)[2:])),repeat(0))))))[:-1] ", 42);

	return 0;
}
