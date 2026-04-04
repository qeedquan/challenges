/*

You are given three integers x, y, and z.

You have x strings equal to "AA", y strings equal to "BB", and z strings equal to "AB". You want to choose some (possibly all or none) of these strings and concatenate them in some order to form a new string. This new string must not contain "AAA" or "BBB" as a substring.

Return the maximum possible length of the new string.

A substring is a contiguous non-empty sequence of characters within a string.



Example 1:

Input: x = 2, y = 5, z = 1
Output: 12
Explanation: We can concatenate the strings "BB", "AA", "BB", "AA", "BB", and "AB" in that order. Then, our new string is "BBAABBAABBAB".
That string has length 12, and we can show that it is impossible to construct a string of longer length.

Example 2:

Input: x = 3, y = 2, z = 2
Output: 14
Explanation: We can concatenate the strings "AB", "AB", "AA", "BB", "AA", "BB", and "AA" in that order. Then, our new string is "ABABAABBAABBAA".
That string has length 14, and we can show that it is impossible to construct a string of longer length.

Constraints:

    1 <= x, y, z <= 50

Hint 1
It can be proved that ALL “AB”s can be used in the optimal solution. (1) If the final string starts with 'A', we can put all unused “AB”s at the very beginning. (2) If the final string starts with 'B' (meaning) it starts with “BB”, we can put all unused “AB”s after the 2nd 'B'.

Hint 2
Using “AB” doesn’t increase the number of “AA”s or “BB”s we can use. If we put an “AB” after “BB”, then we still need to append “AA” as before, so it doesn’t change the state.

Hint 3
We only need to consider strings “AA” and “BB”; we can either use the pattern “AABBAABB…” or the pattern “BBAABBAA…”, depending on which one of x and y is larger.

*/

#include <assert.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
longest(int x, int y, int z)
{
	int r;

	r = z + (min(x, y) * 2);
	if (x != y)
		r += 1;
	return r * 2;
}

int
main()
{
	assert(longest(2, 5, 1) == 12);
	assert(longest(3, 2, 2) == 14);

	return 0;
}
