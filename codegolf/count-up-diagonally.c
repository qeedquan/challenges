/*

We have lots of horizontal axis for numbers, but I honestly think they're kind of boring. Your task today is to build me a portion of a diagonal axis between two distinct non-negative integers given as input.

How to build a diagonal axis?
Let's take an example, with the input 0, 5. Our axis should look like this:

0
 1
  2
   3
    4
     5
However, our axis should look nice for numbers that have more digits too! If the input is, for instance 0, 14, the new axis should be:

0
 1
  2
   3
    4
     5
      6
       7
        8
         9
          10
            11
              12
                13
                  14
The idea is that the first digit of next number on the axis must always be placed exactly after the last digit of the previous number. To understand the idea even better, here is another example with 997, 1004:

997
   998
      999
         1000
             1001
                 1002
                     1003
                         1004
Rules
You may assume that input is in ascending or descending order (you may choose between 5,3 and 3,5).

You may also assume that the difference between the two integers is lower than 100.

You may have a leading newline or a consistent leading space (on each line). Trailing spaces / newlines are fine as well.

Default Loopholes are forbidden.

You can take input and provide output by any standard mean.

This is code-golf, so the shortest code in bytes in every language wins!

Other Test Cases
1, 10:

1
 2
  3
   4
    5
     6
      7
       8
        9
         10
95, 103:

95
  96
    97
      98
        99
          100
             101
                102
                   103
999999, 1000009:

999999
      1000000
             1000001
                    1000002
                           1000003
                                  1000004
                                         1000005
                                                1000006
                                                       1000007
                                                              1000008
                                                                     1000009

*/

#include <stdio.h>

typedef unsigned long long uvlong;

void
diagonal(uvlong a, uvlong b)
{
	uvlong i, j, n, s;

	s = 0;
	for (i = a; i <= b; i++) {
		for (j = 0; j < s; j++)
			printf(" ");
		n = printf("%llu\n", i);
		s += n - 1;
	}
}

int
main(void)
{
	diagonal(1, 10);
	diagonal(95, 103);
	diagonal(997, 1004);
	diagonal(999999ULL, 1000009ULL);

	return 0;
}
