/*

Here are the first 100 numbers of a sequence:

1,2,33,4,55,66,777,8,99,11,111,12,133,141,1515,1,11,18,191,22,222,222,2232,24,252,266,2772,282,2922,3030,31313,3,33,33,335,36,377,383,3939,44,441,444,4443,444,4455,4464,44747,48,499,505,5151,522,5333,5445,55555,565,5757,5855,59559,6060,61611,62626,636363,6,66,66,676,66,666,770,7717,72,737,744,7557,767,7777,7878,79797,88,888,882,8838,888,8888,8886,88878,888,8898,9900,99119,9929,99399,99494,995959,96,979,988,9999,100
How does this sequence work?

n:            1 2  3  4   5   6   7   8    9    10   11   12   13   14   15   16    17
binary:       1 10 11 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111 10000 10001
n extended:   1 22 33 444 555 666 777 8888 9999 1010 1111 1212 1313 1414 1515 16161 17171
1-bit digits: 1 2  33 4   5 5 66  777 8    9  9 1 1  1 11 12   13 3 141  1515 1     1   1
result:       1 2  33 4   55  66  777 8    99   11   111  12   133  141  1515 1     11
As you can see, the steps to get the output are as follows:

Convert integer n to a binary-string.
Extend integer n to the same length as this binary-string. (I.e. n=17 is 10001 in binary, which has a length of 5. So we extend the 17 to this same length of 5 by cycling it: 17171.)
Only keep the digits in the extended integer n at the positions of the 1s in the binary-string.
Join them together to form an integer†.

Challenge:
One of these options:

Given an integer n, output the nth number in the sequence.
Given an integer n, output the first n numbers of this sequence.
Output the sequence indefinitely without taking an input (or by taking an empty unused input).
Challenge rules:
†Step 4 isn't mandatory to some extent. You're also allowed to output a list of digits, but you aren't allowed to keep the falsey-delimiter. I.e. n=13 resulting in [1,3,3] or "1,3,3" instead of 133 is fine, but "13 3", [1,3,false,3], [1,3,-1,3], etc. is not allowed.
Although I don't think it makes much sense, with option 1 you are allowed to take a 0-based index m as input and output the (m+1)th value.
If you output (a part of) the sequence (options 2 or 3), you can use a list/array/stream; print to STDOUT with any non-digit delimiter (space, comma, newline, etc.); etc. Your call. If you're unsure about a certain output-format, feel free to ask in the comments.
Please state which of the three options you've used in your answer.
The input (with options 1 and 2) is guaranteed to be positive.
You'll have to support at least the first [1,10000] numbers. n=...,9998,9999,10000] result in ...,9899989,99999999,10010] (the largest output in terms of length within this range is n=8191→8191819181918).

General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (i.e. TIO).
Also, adding an explanation for your answer is highly recommended.
PS: For the 05AB1E code-golfers among us, 4 bytes is possible.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
digitalxor(unsigned n)
{
	unsigned b, i, l, r;
	char s[128];

	b = 1;
	while (n / b)
		b *= 2;

	r = 0;
	for (i = 0; b /= 2; i++) {
		if (b & n) {
			l = snprintf(s, sizeof(s), "%u", n);
			r = (r * 10) + (s[i % l] - '0');
		}
	}
	return r;
}

int
main(void)
{
	static const unsigned tab[] = {1, 2, 33, 4, 55, 66, 777, 8, 99, 11, 111, 12, 133, 141, 1515, 1, 11, 18, 191, 22, 222, 222, 2232, 24, 252, 266, 2772, 282, 2922, 3030, 31313, 3, 33, 33, 335, 36, 377, 383, 3939, 44, 441, 444, 4443, 444, 4455, 4464, 44747, 48, 499, 505, 5151, 522, 5333, 5445, 55555, 565, 5757, 5855, 59559, 6060, 61611, 62626, 636363, 6, 66, 66, 676, 66, 666, 770, 7717, 72, 737, 744, 7557, 767, 7777, 7878, 79797, 88, 888, 882, 8838, 888, 8888, 8886, 88878, 888, 8898, 9900, 99119, 9929, 99399, 99494, 995959, 96, 979, 988, 9999, 100};

	unsigned i;

	for (i = 0; i < nelem(tab); i++)
		assert(digitalxor(i + 1) == tab[i]);

	return 0;
}
