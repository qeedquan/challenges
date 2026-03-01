/*

Very few, if any, programs or applications have utilised the proposed spec for WOM which was initially thought up in the early 1970s as a polar opposite to ROM,
so your task is to take a dataset of n Integers and simulate storing it to a WOM schema as a proof of concept.

Your array must contain 1 or more integers. Smallest solution wins.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/param.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
handler(int)
{
	const char message[] = "FORBIDDEN\n";

	write(1, message, sizeof(message) - 1);
	_exit(0);
}

// https://en.m.wikipedia.org/wiki/Write-only_memory_(engineering)
int *
wom(int *array, size_t elements)
{
	int *memory;
	size_t size;

	size = roundup(elements, getpagesize());
	memory = mmap(NULL, size, PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (memory == MAP_FAILED)
		goto error;

	memcpy(memory, array, sizeof(*array) * elements);
	if (mprotect(memory, size, PROT_NONE) < 0)
		goto error;

	if (0) {
	error:
		if (memory != MAP_FAILED)
			munmap(memory, size);
		return MAP_FAILED;
	}

	return memory;
}

int
main()
{
	int array[] = {1, 2, 3, 4, 5, 6};
	int *memory;

	signal(SIGSEGV, handler);
	memory = wom(array, nelem(array));
	assert(memory != MAP_FAILED);
	printf("%d\n", memory[0]);

	return 0;
}
