/*

Four-digit number is given. Determine if there are two consecutive digits 3 and 7.

Input
One four-digit number.

Output
Print "YES" if the number contains digits 3 and 7 in a row. Print "NO" otherwise.

Examples

Input #1
1378

Answer #1
YES

Input #2
3478

Answer #2
NO

*/

#include <assert.h>
#include <string.h>

const char *
solve(int n)
{
	for (; n > 0; n /= 10) {
		if ((n % 100) == 37)
			return "YES";
	}
	return "NO";
}

int
main()
{
	assert(!strcmp(solve(1378), "YES"));
	assert(!strcmp(solve(3478), "NO"));

	return 0;
}
