/*

Write a program fragment so that, when repeated N times it prints the Nth Fibonacci number. For example, if your program is print(x) then:

print(x) should print 1
print(x)print(x) should print 1
print(x)print(x)print(x) should print 2
print(x)print(x)print(x)print(x) should print 3
print(x)print(x)print(x)print(x)print(x) should print 5
etc.
First 2 items are 1 then each consecutive item in the sequence is the sum of the previous two.

You may include a non-repeated header and footer, but a smaller header and footer will always beat an answer with a larger sum of header+footer. For example, a 1000 byte answer with no header wins from a 20 byte answer with a 1 byte footer. However, a 0 byte header 20 byte body will win from both.

With header length being equal, smallest number of bytes, in each language, wins.

Tips
Output in unary
Use shell escape codes like \r to erase the previous print.
Use your languages implicit output feature

Example Submission
Python, 0 header/footer, 97 body
if"k"not in globals():k=["","x"];print("x",end="")
else:k.append(k[-1]+k[-2]);print(k[-3],end="")
Output in unary

Attempt This Online!

Comments are entirely valid, but solutions that don't use comments are extra impressive.

*/

#include <stdio.h>

#define print(x) nextfib();

void
nextfib(void)
{
	static int a = 1;
	static int b = 1;
	int c;

	printf("%d\n", a);
	c = a + b;
	a = b;
	b = c;
}

int
main(void)
{
	print(x) print(x) print(x) print(x) print(x) print(x) print(x) print(x) print(x) print(x);
	return 0;
}
