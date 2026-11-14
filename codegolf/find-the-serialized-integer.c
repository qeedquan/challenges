/*

Task
Write a program that will take (as input) a positive integer. It will then count up from 0, appending each integer to a String, only continuing if the length of the String is less than the value of the input.

A serialized integer is defined as the fully-formed integer with the maximum value belonging to the String. By "fully-formed", the integer should have no missing digits (which would occur if the length constraint of the String is met).

The output of the program should be the serialized integer for its respective, positive input.

Rules
It's code golf, so the shortest answer (in bytes) wins!
Input will always be positive.
The output must be an integer in base-10 (decimal).
The program must be 0-indexed.
Example Input | Output
   5 | 4   (0 1 2 3 4              - Length of 5)
  11 | 9   (0 1 2 3 4 5 6 7 8 9 1  - Length of 11)
  12 | 10  (0 1 2 3 4 5 6 7 8 9 10 - Length of 12)
1024 | 377 (0 1 2 3 4 5 6 7 8 ...  - Length of 1024)

Note(s)
If you have any questions (or would like me to provide more examples), please comment!
Inspiration: https://stackoverflow.com/questions/45034478/how-do-i-calculate-the-maximum-serialized-integers-in-1024-length-limit

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

int
serialize(int n)
{
	char b[sizeof(n) * CHAR_BIT];
	int i, l;

	i = 0;
	l = snprintf(b, sizeof(b), "%d", i);
	for (;;) {
		l += snprintf(b, sizeof(b), "%d", i + 1);
		if (l > n)
			break;

		i += 1;
	}
	return i;
}

int
main(void)
{
	assert(serialize(5) == 4);
	assert(serialize(11) == 9);
	assert(serialize(12) == 10);
	assert(serialize(1024) == 377);

	return 0;
}
