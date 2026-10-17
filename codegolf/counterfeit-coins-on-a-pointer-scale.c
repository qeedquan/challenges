/*

You sell gold coins. Each gold coin you sell is supposed to be 1 ounce. However, you find out that one of your coin suppliers is cheating you. By alloying the gold material with something else, their coins weigh only 0.9 ounces. With a help of a pointer scale (one that shows the exact weight of a quantity of matter set on it), you want to determine which of your coin suppliers is selling you the counterfeit coins.

Apparently, you are not the only one to have this problem - lots of gold sellers buy coins from this supplier, and the supplier knows that it is being dodgy and is changing their branding accordingly. All of these sellers have the same problem - 1 ounce coins that end up being 0.9 ounces from this supplier - and need to solve it, fast! How can you determine, out of n suppliers, which one is the cheating supplier with the minimum number of weighings on the pointer scale?

Your task is to write a program function that can solve this problem automatically for n suppliers. It's input includes:

an integer number of suppliers, n,
an oracle function that represents weighing a set of coins on the balance scale
It must take this information, calling this function a minimum number of times and returning, as output, the index number of the cheating supplier.

The oracle function has the following specifications:

It takes as input an int->int mapping (as an array or dictionary, whichever your language prefers) mapping each supplier index (from 0 to n-1) to a number of gold coins that you want to try weighing on the scale.
The returned output is the total weight, in ounces, of the coins put on the scale.
The function is in whatever format your language prefers for passing procedures as data. For instance, functional languages will pass lambdas, C will take a function pointer, Java 7 and earlier will take a functional interface. Languages that support none of these, but do support string execution, will take these as strings.
In those cases when the oracle can be stringified or otherwise inspected as data, you may assume that it is sufficiently obfuscated such that you cannot tell which supplier is cheating without executing it.
This is also code-golf: among the solutions that call the function the minimum number of times, the smallest solution in bytes is the winner!

NOTE: If your language does not support functions at all, but does support string execution, write your program as a standalone program - assume that the number of suppliers, followed by the oracle, will be passed into standard input. If your language does not support string execution, assume that a file path to a binary oracle will be provided instead.

*/

#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int
triangular(int n)
{
	return n * (n - 1) / 2;
}

int
oracle(int n)
{
	return n;
}

/*

@Jonathan Allan

Places i coins from each of the suppliers i in [0,n-1] on the scale, subtracts the weighing from the total number of coins weighed and multiplies by 10.

*/

int
solve(int n, int (*f)(int))
{
	return max((triangular(n) - f(n)) * 10, 0);
}

int
main(void)
{
	int i;

	for (i = 0; i < 10; i++)
		printf("%d\n", solve(i, oracle));

	return 0;
}
