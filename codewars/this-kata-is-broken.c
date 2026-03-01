/*

(Imagine the following spoken in the voice of GlaDOS from Portal...)

We regret to inform you that this next kata is impossible. Make no attempt to solve it.

Do not be fooled by anyone who tells you to "think outside the box" or "know when to break the rules." They obviously just want to encourage you to try so they can watch you fail.

Again, we apologize for this clearly broken kata.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
solution()
{
	static const int table[] = { 71, 108, 97, 68, 79, 83 };
	static thread_local size_t index = 0;

	int result;

	result = table[index];
	index = (index + 1) % nelem(table);
	return result;
}

int
main()
{
	assert(solution() == 71);
	assert(solution() == 108);
	assert(solution() == 97);
	assert(solution() == 68);
	assert(solution() == 79);
	assert(solution() == 83);

	return 0;
}
