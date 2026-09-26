/*

At a job interview, you are challenged to write an algorithm to check if a given string, s, can be formed from two
other strings, part1 and part2.

The restriction is that the characters in `part1` and `part2` should be in the same order as in s.

The interviewer gives you the following example and tells you to figure out the rest from the given test cases.

For example:

'codewars' is a merge from 'cdw' and 'oears':

    s:  c o d e w a r s   = codewars
part1:  c   d   w         = cdw
part2:    o   e   a r s   = oears

*/

#include <assert.h>

bool
ismerge(const char *s, const char *p1, const char *p2)
{
	bool r;

	if (!s[0])
		return !p1[0] && !p2[0];

	r = false;
	if (s[0] == p1[0])
		r = ismerge(s + 1, p1 + 1, p2);
	if (s[0] == p2[0])
		r = r || ismerge(s + 1, p1, p2 + 1);
	return r;
}

int
main()
{
	assert(ismerge("codewars", "cdw", "oears") == true);
	assert(ismerge("", "", "") == true);
	assert(ismerge("codewars", "code", "wars") == true);
	assert(ismerge("codewars", "cdwr", "oeas") == true);
	assert(ismerge("Bananas from Bahamas", "Bahas", "Bananas from am") == true);
	assert(ismerge("Can we merge it? Yes, we can!", "aw egets,we ca", "Cn emr i? Ye n!") == true);
	assert(ismerge("Can we merge it? Yes, we can!", "an  re Ye,we !", "Cwemeg it?s can") == true);

	assert(ismerge("", "code", "wars") == false);
	assert(ismerge("codewars", "cod", "wars") == false);
	assert(ismerge("\\*M[w6c8\\[5m>", ">*M[68m\\", "wc\\[5") == false);

	return 0;
}
