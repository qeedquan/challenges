/*

a XAND b
a AND b, but not at the same time.

I've always found the idea of an XAND gate amusing.

Many would claim such a gate can not exist, but I suspect they're just not trying hard enough.

Popularity Contest
You simply need to demonstrate an XAND gate.

The rules are simple:

Create two identifiers a and b
They do not have to be primitives but can be anything [eg variables, functions, macros, constants, types, etc].
They must both be truthy by themselves [eg if (a)]
They must fail to be truthy together [eg if (a && b)]
Once rules 3 & 4 are achieved, they must continue to hold true throughout the duration of your program. [Explained in detail at the end].
The most straight-forward way to demonstrate this would be to simply use three conditionals:

if (a) {
   print("a");
}

if (b) {
   print("b");
}

if (!(a&&b)) {
   print("but not at the same time");
}
However, this is a popularity contest, so it's actually up to you how you wish to demonstrate it, and up to voters to determine how valid your XAND is.

I use && in the code above, but you are allowed to get creative in demonstrating the "but not at the same time" nature of your gate; so, you are not limited to using a strict a&&b conditional, per se (voters will determine validity).

Rule 5 Explained:

It must remain true in your code that:
• a is truthy
• b is truthy
• a AND b is not truthy

These conditions must remain true no matter how many times you'd demonstrate these conditions or what order you'd demonstrate them in.

So you can not just have a value that simply changes after it's read the first time so that the second time you make the comparison it is no longer truthy.

Perhaps this is more easily explained with pseudocode:

while (1)
    i = random%3;
    switch(i):
        case 0:
            if (a) //This must always be true
        case 1:
            if (b) //This must always be true
        case 2:
            if (a AND b) //This must always be false
And again, this is a popularity contest, so you do not have to strictly demonstrate this in any particular way...

You just need to demonstrate to your audience the XAND nature of your gate. You are not necessarily forced to explicitly use && for example.

You just need to demonstrate in a clear way "a AND b, but not at the same time"

...so get creative XAND have fun!

*/

#include <iostream>

using namespace std;

struct Bool
{
	operator bool() const
	{
		return true;
	}

	bool operator &&(const Bool)
	{
		return false;
	}
};

int main()
{
	Bool a, b;

	if (a)
		cout << "a" << endl;

	if (b)
		cout << "b" << endl;
	
	if (a && b)
		cout << "but not at the same time" << endl;

	return 0;
}
