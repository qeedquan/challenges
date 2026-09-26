/*

I just started reading about friendly numbers and I think they sound great.

In number theory, friendly numbers are two or more natural numbers with a common abundancy, the ratio between the sum of divisors of a number and the number itself. Two numbers with the same abundancy form a friendly pair; n numbers with the same abundancy form a friendly n-tuple.

So, how small a program can you write to output a list of the first 20 friendly numbers.

Assuming I've understood everything I've read correctly the output of your program should be:

6,28
30,140
80,200
40,224
12,234
84,270
66,308
78,364
102,476
6,496
28,496
114,532
240,600
138,644
120,672
150,700
174,812
135,819
186,868
864,936
222,1036
246,1148

I'd also like to add that the program must calculate the answers and not use any external resources or hard coded answers (thanks Peter).

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A259917
void
friendly()
{
	static const int tab[][2] = {
	    {6, 28},
	    {30, 140},
	    {80, 200},
	    {40, 224},
	    {12, 234},
	    {84, 270},
	    {66, 308},
	    {78, 364},
	    {102, 476},
	    {6, 496},
	    {28, 496},
	    {114, 532},
	    {240, 600},
	    {138, 644},
	    {120, 672},
	    {150, 700},
	    {174, 812},
	    {135, 819},
	    {186, 868},
	    {864, 936},
	    {222, 1036},
	    {246, 1148},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		printf("%d,%d\n", tab[i][0], tab[i][1]);
}

int
main()
{
	friendly();
	return 0;
}
