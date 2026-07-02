/*

Make me slow! Calling makeMeSlow() should take at least 7 seconds.

*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <threads.h>

int
print(void *ud)
{
	puts(ud);
	return 0;
}

int
slow(int (*f)(void *), void *ud)
{
	struct timespec tp;
	int r;

	memset(&tp, 0, sizeof(tp));
	tp.tv_sec = 3;
	thrd_sleep(&tp, NULL);

	r = f(ud);

	tp.tv_sec = 4;
	thrd_sleep(&tp, NULL);
	return r;
}

int
main()
{
	slow(print, "hello");
	return 0;
}
