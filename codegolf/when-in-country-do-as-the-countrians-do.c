/*

When in Rome, do as the Romans do. This is a well-known English phrase meaning that it’s best to follow what others are doing around you — to go with the flow. Today, you're going to rewrite the phrase to fit most (Western) place names.

To get the name of a group that lives within a region, there are a couple of cases:

If the name ends with an ‘i’, ‘o’, or ‘u’, append ‘ans’. If the name ends with an ‘e’ or ’a’, drop it and append ’ans’.
If the name ends with a ‘y’, replace it with an ’i’ if the preceding character is a consonant, and finally append ‘ans‘.
If the name ends in a consonant (excluding ‘y’), append ‘ians’.
Some examples:

“Italy” ends with a consonant followed by a ‘y’, so we replace the ‘y’ with an ‘i’ and append ‘ans’ to get “Italians”.
“Rome” ends with an ‘e’, so we drop it and append ‘ans’ to get “Romans”.
“Hungary” → “Hungarians”
”Paraguay” → “Paraguayans”.
So, your task is: Given a name starting with an uppercase letter and ending with a lowercase letter, output the name of that group of people.

This is code-golf, so the shortest code per language wins! Defaults for code-golf apply.

Test cases:
When in Rome, do as the Romans do.

When in Transylvania, do as the Transylvanians do.

When in Code Golf, do as the Code Golfians do.

When in Hawaii, do as the Hawaiians do.

When in Sparta, do as the Spartans do.

When in America, do as the Americans do.

When in South Dakota, do as the South Dakotans do.

When in Korea, do as the Koreans do.

When in India, do as the Indians do.

(And yes, I know there are plenty of outliers, e.g. group names ending in ‘stani’, ‘ese’, ‘er’, etc. However, this formula seems to work for most English place names.)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
countrians(const char *s, char *b)
{
	size_t n;

	n = sprintf(b, "%s", s);
	if (n == 0)
		return b;

	if (strchr("iou", b[n - 1]))
		sprintf(b + n, "ans");
	else if (strchr("ea", b[n - 1]))
		sprintf(b + n - 1, "ans");
	else if (b[n - 1] == 'y') {
		if (n >= 2 && !strchr("aeiou", b[n - 2]))
			b[n - 1] = 'i';
		sprintf(b + n, "ans");
	} else
		sprintf(b + n, "ians");

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	countrians(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Rome", "Romans");
	test("Transylvania", "Transylvanians");
	test("Code Golf", "Code Golfians");
	test("Hawaii", "Hawaiians");
	test("Sparta", "Spartans");
	test("America", "Americans");
	test("South Dakota", "South Dakotans");
	test("Korea", "Koreans");
	test("India", "Indians");

	return 0;
}
