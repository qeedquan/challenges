/*

A k-hyperperfect number is a natural number n≥1 such that

n=1+k(σ(n)−n−1)

where σ(n) is the sum of the divisors of n. Note that σ(n)−n is the proper divisor sum of n. The sequence of k-hyperperfect numbers begins

6,21,28,301,325,496,697,…

This is A034897 on the OEIS.

For example:

σ(21)21 = 1+3+7+21 = 32 = 1+2(32−21−1) = 1+2×10 = 21

Therefore, 21 is a 2-hyperperfect number.

You are to take a k-hyperperfect number n as input and output the value of k. You can assume you will never have to handle numbers greater than your language's limit at any point (i.e. kσ(n) will always be within the bounds of your language), and you may input and output in any convenient format.

The input is guaranteed to be a k-hyperperfect number, you don't have to handle inputs such as 2,87,104 etc. that aren't k-hyperperfect.

This is code-golf, so the shortest code in bytes wins.

Test cases
These are the outputs for all the listed values in the OEIS for this sequence, and are the exhaustive list of inputs for n<1055834

      n       k
      6       1
     21       2
     28       1
    301       6
    325       3
    496       1
    697      12
   1333      18
   1909      18
   2041      12
   2133       2
   3901      30
   8128       1
  10693      11
  16513       6
  19521       2
  24601      60
  26977      48
  51301      19
  96361     132
 130153     132
 159841      10
 163201     192
 176661       2
 214273      31
 250321     168
 275833     108
 296341      66
 306181      35
 389593     252
 486877      78
 495529     132
 542413     342
 808861     366
1005421     390
1005649     168
1055833     348

*/

#include <assert.h>

long
hyperk(long n)
{
	long d, m;

	m = 1;
	for (d = 2; d < n; d++) {
		if (!(n % d))
			m -= d;
	}
	return n / -m;
}

int
main(void)
{
	assert(hyperk(6) == 1);
	assert(hyperk(21) == 2);
	assert(hyperk(28) == 1);
	assert(hyperk(301) == 6);
	assert(hyperk(325) == 3);
	assert(hyperk(496) == 1);
	assert(hyperk(697) == 12);
	assert(hyperk(1333) == 18);
	assert(hyperk(1909) == 18);
	assert(hyperk(2041) == 12);
	assert(hyperk(2133) == 2);
	assert(hyperk(3901) == 30);
	assert(hyperk(8128) == 1);
	assert(hyperk(10693) == 11);
	assert(hyperk(16513) == 6);
	assert(hyperk(19521L) == 2);
	assert(hyperk(24601L) == 60);
	assert(hyperk(26977L) == 48);
	assert(hyperk(51301L) == 19);
	assert(hyperk(96361L) == 132);
	assert(hyperk(130153L) == 132);
	assert(hyperk(159841L) == 10);
	assert(hyperk(163201L) == 192);
	assert(hyperk(176661L) == 2);
	assert(hyperk(214273L) == 31);
	assert(hyperk(250321L) == 168);
	assert(hyperk(275833L) == 108);
	assert(hyperk(296341L) == 66);
	assert(hyperk(306181L) == 35);
	assert(hyperk(389593L) == 252);
	assert(hyperk(486877L) == 78);
	assert(hyperk(495529L) == 132);
	assert(hyperk(542413L) == 342);
	assert(hyperk(808861L) == 366);
	assert(hyperk(1005421L) == 390);
	assert(hyperk(1005649L) == 168);
	assert(hyperk(1055833L) == 348);

	return 0;
}
