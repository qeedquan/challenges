/*

In the language Nim, the rules for differentiating identifiers are slightly more relaxed than most other languages. Two identifiers are equivalent or address the same variable if they follow these rules:

the first character of both are the same (case sensitive)
both strings are the same (case insensitive) after removing all instances of the characters - and _
Challenge
Write a program/function that takes two strings that represent Nim identifiers and output a truthy or falsey value based on whether or not they are equivalent by the rules above.

Specifications
Standard I/O rules apply.
Standard loopholes are forbidden.
The strings will only contain ASCII printables. You do not need to check if it's a valid identifier.
The strings may be taken as two separate inputs, list of strings, etc. (you know the drill)
Empty strings need not be handled.
The output must be consistent for both truthy and falsey values.
This challenge is not about finding the shortest approach in all languages, rather, it is about finding the shortest approach in each language.
Your code will be scored in bytes, usually in the encoding UTF-8, unless specified otherwise.
Built-in functions that perform this task are allowed but including a solution that doesn't rely on a built-in is encouraged.
Explanations, even for "practical" languages, are encouraged.
Test cases
Input                                    Output

count, Count                             falsey
lookMaNoSeparator, answer                falsey
_test, test                              falsey
test, tset                               falsey
aVariableName, a_variable_name           truthy
numbers_are_cool123, numbersAreCool123   truthy
symbolsAre_too>_>, symbols_areTOO>>      truthy
Ungolfed reference implementation
This is written in Nim, itself.

import strutils, re

proc sameIdentifier(a, b: string): bool =
  a[0] == b[0] and
    a.replace(re"_|–", "").toLower == b.replace(re"_|–", "").toLower

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

bool
equal(const char *s, const char *t)
{
	size_t i, j;

	if (s[0] != t[0])
		return false;

	for (i = j = 0; s[i] || t[j];) {
		if (s[i] == '-' || s[i] == '_')
			i++;
		else if (t[j] == '-' || t[j] == '_')
			j++;
		else if (tolower(s[i++]) != tolower(t[j++]))
			return false;
	}
	return true;
}

int
main(void)
{
	assert(equal("count", "Count") == false);
	assert(equal("lookMaNoSeparator", "answer") == false);
	assert(equal("_test", "test") == false);
	assert(equal("test", "tset") == false);

	assert(equal("aVariableName", "a_variable_name") == true);
	assert(equal("numbers_are_cool123", "numbersAreCool123") == true);
	assert(equal("symbolsAre_too>_>", "symbols_areTOO>>") == true);

	return 0;
}
