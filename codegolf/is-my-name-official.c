/*

Introduction
As ToonAlfrink says: "Me thinks there aren't enough easy questions on here that beginners can attempt!". So the task is very simple. Given a string, output a truthy or falsy value whether the name is official or not.

A name is "official" if it is a single title-case word, that is:

If the first letter is capitalized (not official: adnan)
If the other letters are not capitalized (not official: AdNaN)
If the name doesn't contain any non-alphabetic characters (not official: Adnan123, Adnan!)
If the name consists of just one word (not official: Adn an, Adn An)
If the name has more than one character (not official: A)

Rules
You may provide a function or a program
This is code-golf, so the submission with the least amount of bytes wins!
Note: To simplify things, names like Mary-Ann are in this challenge not official.
Assume that there are no leading whitespaces in the name.
Assume that only the printable ASCII characters (32-126) are used in the names

Test cases
Input: Adnan
Output: True

Input: adnan
Output: False

Input: AdnaN
Output: False

Input: Adnan123
Output: False

Input: Adnan Adnan
Output: False

Input: A
Output: False

Input: Mary-Ann
Output: False

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

bool
official(const char *s)
{
	size_t i;

	if (!isupper(s[0]))
		return false;

	for (i = 1; s[i]; i++) {
		if (!islower(s[i]))
			return false;
	}
	return i > 1;
}

int
main()
{
	assert(official("Adnan") == true);
	assert(official("adnan") == false);
	assert(official("AdnaN") == false);
	assert(official("Adnan123") == false);
	assert(official("Adnan Adnan") == false);
	assert(official("A") == false);
	assert(official("Mary-Ann") == false);

	return 0;
}
