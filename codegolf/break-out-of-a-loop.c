/*

Now that we have over a hundred ways to get stuck in a loop, the next challenge is to get out.

Specifically, write a piece of code with a (seemingly) infinite loop, but somehow manage to break out.

The "infinite loop" can be a statement like while true, for (;1>0;) or anything else which obviously lasts forever. Recursion does not count (since stack overflows will quickly occur).

To break out, you need to execute an instruction written just after the loop. You can not just exit the program or leave the method.

Valid answer (if only it somehow exited the loop):

while (true)
    print("I'm stuck!")

print("I escaped!")
Invalid answer:

define loop() {
    while (true)
        print("I'm stuck!")
}

loop()
print("I escaped!")

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <setjmp.h>

jmp_buf env;

int
number()
{
	int n;

	n = rand();
	if (n > 0 && !(n % 0xdead))
		longjmp(env, n);
	return n;
}

int
main()
{
	srand(time(NULL));

	if (setjmp(env))
		return 0;

	for (;;)
		printf("%d\n", number());

	return 0;
}
