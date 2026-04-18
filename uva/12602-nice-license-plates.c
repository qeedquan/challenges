/*

Alberta licence plates currently have a format of
ABC-0123 (three letters followed by four digits).
We say that the licence plate is “nice” if the
absolute difference between the value of the first
part and the value of the second part is at most
100.
The value of the first part is calculated as
the value of base-26 number (where digits are in
[A..Z]). For instance, if the first part is “ABC”, its
value is 28 (0∗262+1∗261+2∗260
). So, the plate
“ABC-0123” is nice, because |28 − 123| ≤ 100.
Given the list of licence plate numbers, your
program should determine if the plate is nice or not.

Input
First line of the input contains an integer N (1 ≤ N ≤ 100), the number of licence plate numbers.
Then follow N lines, each containing a licence plate in the format ‘LLL-DDDD’.

Output
For each licence plate print on a line ‘nice’ or ‘not nice’ (without quotes) depending on the plate
number being nice as described in the probem statement.

Sample Input
2
ABC-0123
AAA-9999

Sample Output
nice
not nice

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
base26(const char *input)
{
	int result;

	result = (input[2] - 'A');
	result += 26 * (input[1] - 'A');
	result += 676 * (input[0] - 'A');
	return result;
}

bool
nice(const char *license)
{
	char left[4];
	int right;

	memset(left, 0, sizeof(left));
	if (sscanf(license, "%3s-%d", left, &right) != 2)
		return false;
	return abs(base26(left) - right) <= 100;
}

int
main()
{
	assert(nice("ABC-0123") == true);
	assert(nice("AAA-9999") == false);

	return 0;
}
