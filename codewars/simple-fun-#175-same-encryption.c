/*

Task
John loves encryption. He can encrypt any string by the following algorithm:

take the first and the last letters of the word;
replace the letters between them with their number;
replace this number with the sum of it digits
          until a single digit is obtained.
Given two strings(s1 and s2), return true if their encryption is the same, or false otherwise.

Example
For s1 = "EbnhGfjklmjhgz" and s2 = "Eabcz", the result should be true.

"EbnhGfjklmjhgz" --> "E12z" --> "E3z"
"Eabcz" --> "E3z"
Their encryption is the same.
Input/Output
[input] string s1
The first string to be encrypted.

s1.length >= 3

[input] string s2
The second string to be encrypted.

s2.length >= 3

[output] a boolean value
true if encryption is the same, false otherwise.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
digsum(size_t n)
{
	size_t r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return r;
}

bool
sameencryption(const char *s1, const char *s2)
{
	size_t n, m;

	n = strlen(s1);
	m = strlen(s2);
	if (n < 2 || m < 2)
		return false;
	if (s1[0] != s2[0] || s1[n - 1] != s2[m - 1])
		return false;
	return digsum(n - 2) == digsum(m - 2);
}

int
main()
{
	assert(sameencryption("EbnhGfjklmjhgz", "Eabcz") == true);
	assert(sameencryption("abc", "abc") == true);
	assert(sameencryption("abc", "abd") == false);
	assert(sameencryption("fKhjuytrdfcdc", "flJc") == true);
	assert(sameencryption("OKhjuytrdfcdc", "OijK") == false);

	return 0;
}
