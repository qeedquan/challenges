/*

Your task is to determine how many files of the copy queue you will be able to save into your Hard Disk Drive. The files must be saved in the order they appear in the queue.

Input:

Array of file sizes (0 <= s <= 100)
Capacity of the HD (0 <= c <= 500)

Output:

Number of files that can be fully saved in the HD.

Examples:

save([4,4,4,3,3], 12) -> 3
# 4+4+4 <= 12, but 4+4+4+3 > 12

save([4,4,4,3,3], 11) -> 2
# 4+4 <= 11, but 4+4+4 > 11

Do not expect any negative or invalid inputs.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
save(int *s, size_t n, int c)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n && c > 0; i++) {
		if (s[i] > c)
			break;

		c -= s[i];
		r += 1;
	}
	return r;
}

int
main()
{
	int s1[] = {4, 4, 4, 3, 3};
	int s2[] = {4, 4, 4, 3, 3};

	assert(save(s1, nelem(s1), 12) == 3);
	assert(save(s2, nelem(s2), 11) == 2);

	return 0;
}
