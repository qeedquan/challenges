/*

We've had challenges for SIGSEGV and SIGILL so why not...

Write the shortest code that results in a Bus Error (SIGBUS) in any programming language.

Your program can't call raise() or kill(getpid(),sig) or pthread_kill(pthread_self(),sig), or any other equivalent.

*/

#include <assert.h>
#include <stdlib.h>

#if defined(__GNUC__)
#define alignment alignment_gcc
#else
#define alignment alignment_none
#endif

// https://en.wikipedia.org/wiki/Bus_error
void
alignment_gcc(void)
{
#if defined(__i386)
	__asm__("pushf\norl $0x40000,(%esp)\npopf");
#elif defined(__x86_64__)
	__asm__("pushf\norl $0x40000,(%rsp)\npopf");
#endif
}

void
alignment_none()
{
}

int
main(void)
{
	int *i;
	char *p;

	alignment();

	p = malloc(sizeof(int) + 1);
	assert(p);

	i = (int *)(p + 1);
	*i = 42;

	return 0;
}
