/*

Write a program or function that accepts an integer in the range 1..3999 as input and returns the number of line segments required to express that integer in standard Roman numerals (so you would use XL but not VM). Examples:

   1 -> 1
   4 -> 3
   5 -> 2
   9 -> 3
  10 -> 2
  40 -> 4
  50 -> 2
  90 -> 3
 100 -> 1
 400 -> 3
 500 -> 2
 900 -> 5
1000 -> 4
Roman number conversion builtins are permitted, but you can solve the problem without them by repeatedly subtracting the largest remaining number from the above list. Example: 1234 = 4 + 1 + 1 + 2 + 2 + 2 + 3 = 15.

This is code-golf, so the shortest program wins.

*/

#include <assert.h>

// https://oeis.org/A002963 (Related, but not the same sequence)
int
strokes(int n)
{
	static const int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1, 4, 5, 2, 3, 1, 3, 2, 4, 2, 3, 2, 3, 1};

	int r, i;

	if (n < 1 || n > 3999)
		return 0;

	r = i = 0;
	do {
		r += (n / num[i]) * num[i + 13];
		n %= num[i++];
	} while (n);

	return r;
}

int
main()
{
	assert(strokes(1) == 1);
	assert(strokes(4) == 3);
	assert(strokes(5) == 2);
	assert(strokes(9) == 3);
	assert(strokes(10) == 2);
	assert(strokes(40) == 4);
	assert(strokes(50) == 2);
	assert(strokes(90) == 3);
	assert(strokes(100) == 1);
	assert(strokes(400) == 3);
	assert(strokes(500) == 2);
	assert(strokes(900) == 5);
	assert(strokes(1000) == 4);
	assert(strokes(1234) == 15);

	return 0;
}
