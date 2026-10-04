/*

Input:
A list of integers

Output:
Put each digit (and the minus sign) in its own lane, in the order -0123456789, ignoring any duplicated digits.

Example:
Input: [1,729,4728510,-3832,748129321,89842,-938744,0,11111]

Output:

-0123456789  <- Added as clarification only, it's not part of the output

  1
   2    7 9
 012 45 78
-  23    8
  1234  789
   2 4   89
-   34  789
 0
  1

Challenge rules:
Any duplicated digits in the number are ignored.
I/O can be in any reasonable format. Input can be as a list/array of strings or character-array. Output can be as a list of strings, characters, character-matrix, etc.
Trailing spaces are optional.
Any amount of leading or trailing new-lines are optional (but not in between lines).
Input will always contain at least one integer
You'll have to support an integer range of at least -2,147,483,648 though 2,147,483,647 (32-bit).
The input-list will never contain -0, 00 (or more than two zeroes), or integers with leading zeroes (i.e. 012).
If you language uses a different symbol for negative numbers (like an upper ¯), you are also allowed to use that instead, as long as it's consistent.
You are allowed to have a space delimiter between digits (so a line without 5 or 8 can be - 0 1 2 3 4   6 7   9 instead of -01234 67 9), as long as it's consistent (and therefore there should also be a space between - and 0).

General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.

Test cases:
Input: [1,729,4728510,-3832,748129321,89842,-938744,0,11111]
Output:
  1
   2    7 9
 012 45 78
-  23    8
  1234  789
   2 4   89
-   34  789
 0
  1

Input: [4,534,4,4,53,26,71,835044,-3559534,-1027849356,-9,-99,-3459,-3459,-94593,-10234567859]
Output:
      4
     345
      4
      4
     3 5
    2   6
   1     7
  0  345  8
 -   345   9
 -0123456789
 -         9
 -         9
 -   345   9
 -   345   9
 -   345   9
 -0123456789

Input: [112,379,-3,409817,239087123,-96,0,895127308,-97140,923,-748]
Output:
  12
   3    7 9
-  3
 01 4   789
 0123   789
-      6  9
 0
  123 5 789
-01  4  7 9
   23     9
-    4  78

Input: [-15,-14,-13,-12,-11,10,-9,-8,-7,-5,-4,-3,-1,0,9,100,101,102,1103,104,105,106,116,-12345690]
Output:
- 1   5
- 1  4
- 1 3
- 12
- 1
-01
-         9
-        8
-       7
-     5
-    4
-   3
- 1
 0
          9
 01
 01
 012
 01 3
 01  4
 01   5
 01    6
  1    6
-0123456  9

Input: [99,88,77,66,55,44,33,22,11,10,0,0,0,-941]
Output:
          9
         8
        7
       6
      5
     4
    3
   2
  1
 01
 0
 0
 0
- 1  4    9

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
mark(bool h[16], long x)
{
	memset(h, 0, sizeof(*h) * 16);

	if (x < 0) {
		x = -x;
		h[10] = true;
	}

	do {
		h[x % 10] = true;
		x /= 10;
	} while (x);
}

void
output(bool h[16])
{
	size_t i;

	if (h[10])
		printf("-");
	else
		printf(" ");

	for (i = 0; i <= 9; i++) {
		if (h[i])
			printf("%zu", i);
		else
			printf(" ");
	}
	printf("\n");
}

void
digitlane(long *a, size_t n)
{
	bool h[16];
	size_t i;

	for (i = 0; i < n; i++) {
		mark(h, a[i]);
		output(h);
	}
	printf("\n");
}

int
main()
{
	long a1[] = {1, 729, 4728510, -3832, 748129321, 89842, -938744, 0, 11111};
	long a2[] = {4, 534, 4, 4, 53, 26, 71, 835044, -3559534, -1027849356, -9, -99, -3459, -3459, -94593, -10234567859};
	long a3[] = {112, 379, -3, 409817, 239087123, -96, 0, 895127308, -97140, 923, -748};
	long a4[] = {-15, -14, -13, -12, -11, 10, -9, -8, -7, -5, -4, -3, -1, 0, 9, 100, 101, 102, 1103, 104, 105, 106, 116, -12345690};
	long a5[] = {99, 88, 77, 66, 55, 44, 33, 22, 11, 10, 0, 0, 0, -941};

	digitlane(a1, nelem(a1));
	digitlane(a2, nelem(a2));
	digitlane(a3, nelem(a3));
	digitlane(a4, nelem(a4));
	digitlane(a5, nelem(a5));

	return 0;
}
