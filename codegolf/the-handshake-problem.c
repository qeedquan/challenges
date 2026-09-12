/*

The handshake problem is the classic problem that for n people in a room, if they all shake hands, what's the total number of handshakes that occur.

You code should take an input of any number and output the number of handshakes, both in base ten.

Also the code should not let non-integers through. You should output a falsey in this case. The only expected inputs are positive whole integers and positive real numbers - you don't need to worry about complex numbers or strings as inputs. This should mean that you should expect n >= 0

Test cases

(N:handshakes)
0:0
10:45
20:190
10.5:0
1337:893116
Normal golfing rules apply and shortest code wins. If your code isn't self explanatory, please explain.

Jelly and 05AB1E are the winners, both at 2 bytes

*/

#include <assert.h>

long
handshake(long n)
{
	if (n < 1)
		return 0;
	return (n - 1) * n / 2;
}

int
main()
{
	assert(handshake(0) == 0);
	assert(handshake(10) == 45);
	assert(handshake(20) == 190);
	assert(handshake(1337) == 893116);

	return 0;
}
