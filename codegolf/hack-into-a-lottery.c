/*

You've recently made an account on a dodgy gambling site, where for a fee of 25 dollars, they will pay you back a random amount between 0 and 50 dollars.
After getting around 5 dollars twice, you decide to prove the site is a scam. After accessing their external firewall with the default password, you find your way onto their database server, and find where the values for the minimum and maximum amounts are held.
You decide to plug 25 '9's in as the maximum value, but get an error message saying the maximum value must be of type 'uint64'.
However it is now that you notice some number keys don't seem to type into the remote console correctly. The challenge appears before you almost as if typed up on a Q+A site.

using only the conveniently installed programs for testing and executing your particular language, output the maximum size of an unsigned 64-bit integer value,
however almost everything except the programming tools are broken on this machine, leaving you without the use of the numbers 1,2,4,6,8 - in either source code or literals,
you also notice that it seems to take an exponentially longer amount of time to execute the program for each additional piece of code, so you'd better keep it short if you want to get rich before the drawing!

The Challenge
Write a program which outputs 18446744073709551615, the maximum value of an unsigned 64-bit integer, as either a number, or a single string.

Your source code cannot contain any of the characters '1','2','4','6' or '8'

if your language does not have an unsigned 64-bit integer or equivalent, the output can be in string format or otherwise, but must be the above number.

this is code-golf so shortest code in each language wins!

*/

#include <stdio.h>
#include <inttypes.h>
#include <limits.h>

int
main(void)
{
	printf("%" PRIu64 "\n", UINT64_MAX);
	return 0;
}
