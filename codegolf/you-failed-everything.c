/*

Your goal is simple: to fail everything. More precisely, you should write the shortest code that triggers a compilation/interpretation error, or a runtime error.

What does not count
Failing with symbols that are not covered by the language syntax and are meant to appear only in string literals, comments and other ways to include non-executable data in the code, or are not meant to appear in the code at all
Warnings and notices that don't prevent successful compilation or execution
Overflow related errors: infinite loops, recursion limits reaching, stack overflows, out-of-memory errors and so on
This is code-golf, so the shortest code in bytes wins!

By the way, this is probably the only challenge where non-esoterical languages can beat esoterical ones ;-)

*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <time.h>

typedef void (*fn)(void);

int
main(void)
{
	fn f;

	srand48(time(NULL));
	f = (fn)lrand48();
	f();

	return 0;
}
