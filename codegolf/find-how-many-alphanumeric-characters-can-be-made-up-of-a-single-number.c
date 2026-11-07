/*

The alphanumeric characters have ASCII-values:

0-9  ->  48-57
A-Z  ->  65-90
a-z  ->  97-122
Your challenge is to take an integer as input, and output how many characters can be made using consecutive digits of that number. The character codes may be overlapping. 666 should result in 2, since you have 66 twice.

Test cases:

Input: 5698
Possible characters: '8' (56), 'E' (69), 'b' (98)
Output: 3

Input: 564693
Possible characters: '8' (56), 'E' (69)
Output: 2

Input: 530923864209124521
Possible characters: '5' (53), 'V' (86), '4' (52)
Output: 3

Input: 1111111
Possible characters: 'ooooo' (5*111)
Output: 5

Input: 5115643141276343
Possible characters: '3' (51), '8' (56), 'L' (76), 's' (115)
Output: 4

Input: 56789
Possible characters: '8' (56), 'C' (67), 'N' (78), 'Y' (89)
Output: 4

Input: 94
Possible characters: ''
Output: 0

Input: 1
Output: 0
Input and output formats are optional (yes, you may take the integer as a string).

*/

#include <assert.h>
#include <ctype.h>

typedef unsigned long long uvlong;

// Ported from @Dennis solution
uvlong
count(uvlong n)
{
	uvlong m, r;

	if (n == 0)
		return 0;

	m = 1000;
	if ((n % 1000) > 122)
		m = 100;

	r = 0;
	if (isalnum(n % m))
		r += 1;
	return r + count(n / 10);
}

int
main()
{
	assert(count(5698) == 3);
	assert(count(564693) == 2);
	assert(count(530923864209124521) == 3);
	assert(count(1111111) == 5);
	assert(count(5115643141276343) == 4);
	assert(count(56789) == 4);
	assert(count(94) == 0);
	assert(count(1) == 0);

	return 0;
}
