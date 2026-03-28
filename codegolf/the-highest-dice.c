/*

Challenge:
Here we have the first 100 items of a sequence:

6,5,4,3,2,1,66,65,64,63,62,61,56,55,54,53,52,51,46,45,44,43,42,41,36,35,34,33,32,31,26,25,24,23,22,21,16,15,14,13,12,11,666,665,664,663,662,661,656,655,654,653,652,651,646,645,644,643,642,641,636,635,634,633,632,631,626,625,624,623,622,621,616,615,614,613,612,611,566,565,564,563,562,561,556,555,554,553,552,551,546,545,544,543,542,541,536,535,534,533,...
How is this sequence formed? We first have the number in the range [6, 1] (all possible values of a single die from highest to lowest).
We then have the numbers [66..61, 56..51, 46..41, 36..31, 26..21, 16..11] (all possible concatted values of two dice from highest to lowest). Etc.
This is related to the OEIS sequence A057436: Contains digits 1 through 6 only, but with all the numbers with equal amount of digits sorted backwards in the sequence.

The challenge is to choose one of these three options for your function/program with the sequence above:

Take an input n and output the n'th value of this sequence, where it can be either 0-indexed or 1-indexed.
Take an input n and output the first n or n+1 values of this sequence.
Output the values from the sequence indefinitely.
Of course, any reasonable output format can be used. Could be as strings/integers/decimals/etc.; could be as an (infinite) list/array/stream/etc.; could be output with space/comma/newline/other delimiter to STDOUT; etc. etc. Please state what I/O and option you're using in your answer!

General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (i.e. TIO).
Also, adding an explanation for your answer is highly recommended.
Here some larger test cases if you choose option 1:

n         0-indexed output    1-indexed output

500       5624                5625
750       4526                4531
1000      3432                3433
9329      11111               11112
9330      666666              11111
9331      666665              666666
10000     663632              663633
100000    6131232             6131233

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

long
mod(long x, long m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

long
highdice(long n)
{
	if (n < 1)
		return 0;
	return (10 * highdice((n - 1) / 6)) + mod(-n, 6) + 1;
}

int
main(void)
{
	static const long tab[] = {
		6, 5, 4, 3, 2, 1, 66, 65, 64, 63, 62, 61, 56, 55, 54, 53, 52, 51, 46,
		45, 44, 43, 42, 41, 36, 35, 34, 33, 32, 31, 26, 25, 24, 23, 22, 21, 16,
		15, 14, 13, 12, 11, 666, 665, 664, 663, 662, 661, 656, 655, 654, 653,
		652, 651, 646, 645, 644, 643, 642, 641, 636, 635, 634, 633, 632, 631,
		626, 625, 624, 623, 622, 621, 616, 615, 614, 613, 612, 611, 566, 565,
		564, 563, 562, 561, 556, 555, 554, 553, 552, 551, 546, 545, 544, 543,
		542, 541, 536, 535, 534, 533
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(highdice(i + 1) == tab[i]);

	assert(highdice(500) == 5625);
	assert(highdice(750) == 4531);
	assert(highdice(1000) == 3433);
	assert(highdice(9329) == 11112);
	assert(highdice(9330) == 11111);
	assert(highdice(9331) == 666666);
	assert(highdice(10000) == 663633);
	assert(highdice(100000) == 6131233);

	return 0;
}
