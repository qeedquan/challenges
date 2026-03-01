/*

The Background
So, we all know the classic proof that goes like this:

a = b
a² = ab
a² - b² = ab - b²
(a-b)(a+b) = b(a-b)
(a+b) = b
b+b = b
2b = b
2 = 1 (Ha ha!)
Of course, the mistake is that you can't divide by 0. Since a = b, a - b = 0, so there was a hidden division by 0.

The Challenge
You have to replicate this proof. First, declare two integers a and b (it doesn't matter what you call them) that equal. Then declare aMod and bMod to be modifiable versions of a and b and initially equal to a and b, respectively. You must multiply them both by a, then subtract b*b from both of them. You must then divide by a - b and then divide them by b (or a) to get. Then, print out aMod and bMod with an equal sign between them.

The Underhanded
Of course, since you declared a and b to equal, a - b = 0, and dividing by 0 causes an error. So you must creatively fake it. Also, because you are trying to replicate the proof, the result on all the operations on aMod and bMod must not equal when printed. They don't have to equal exactly 2 and 1, just two numbers that don't equal.

Here is an example:

#include <iostream>
#define subtract(a, b) a - b

using namespace std;
int main()
{
    int a = 4, b = 4;
    int a_2 = a, b_2 = b;

    a_2 *= a;
    b_2 *= b;

    a_2 -= b * b;
    b_2 -= b * b;

    a_2 = a_2 / subtract(a, b);
    b_2 = b_2 / subtract(-b, -a); // a - b == (-b) - (-a)

    a_2 /= a;
    b_2 /= a;

    cout << a_2 << " = " << b_2 << " because I did the same operations on both of them.";

    return 0;
}

Maybe not the best one, but it illustrates the point.

Bonus Underhanded
Instead of printing the equals sign, you can print out just the two variables (aMod and bMod), and then have code that appears to compare the two variables for equality but in actuality lies that they equal (and prints some form of true).

Remember, this is a popularity contest, so highest number of upvotes wins.
Also, a new version of mathematics called Mathematics 2.0 has made use of standard loopholes automatically invalidate a proof.

*/

#include <stdio.h>

#define subtract(a, b) a - b

int
main()
{
	int a_2, b_2;
	int a, b;

	a = 4;
	b = 4;
	a_2 = a;
	b_2 = b;

	a_2 *= a;
	b_2 *= b;

	a_2 -= b * b;
	b_2 -= b * b;

	a_2 = a_2 / subtract(a, b);
	b_2 = b_2 / subtract(-b, -a); // a - b == (-b) - (-a)

	a_2 /= a;
	b_2 /= a;

	printf("%d = %d because I did the same operations on both of them.\n", a_2, b_2);

	return 0;
}
