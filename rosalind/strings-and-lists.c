/*

Strings and lists

We've already seen numbers and strings, but Python also has variable types that can hold more than one piece of data at a time. The simplest such variable is a list.

You can assign data to a list in the following way: list_name = [item_1, item_2, ..., item_n]. The items of the list can be of any other type: integer, float, string. You even explore your inner Zen and make lists of lists!

Any item in a list can be accessed by its index, or the number that indicates its place in the list. For example, try running the following code:

tea_party = ['March Hare', 'Hatter', 'Dormouse', 'Alice']
print tea_party[2]
Your output should be:

Dormouse
Note that the output was not Hatter, as you might have guessed. This is because in Python, indexing begins with 0, not 1. This property is called 0-based numbering, and it's shared by many programming languages.

You can easily change existing list items by reassigning them. Try running the following:

tea_party[1] = 'Cheshire Cat'
print tea_party
This code should output the list with "Hatter" replaced by "Cheshire Cat":

March Hare, Cheshire Cat, Dormouse, Alice
You can also add items to the end of an existing list by using the function append():

tea_party.append('Jabberwocky')
print tea_party
This code outputs the following:

March Hare, Cheshire Cat, Dormouse, Alice, Jabberwocky
If you need to obtain only some of a list, you can use the notation list_name[a:b] to get only those from index a up to but not including index b. For example, tea_party[1:3] returns Cheshire Cat, Dormouse, not Cheshire Cat, Dormouse, Alice. This process is called "list slicing".

If the first index of the slice is unspecified, then Python assumes that the slice begins with the beginning of the list (i.e., index 0); if the second index of the slice is unspecified, then you will obtain the items at the end of the list. For example, tea_party[:2] returns March Hare, Cheshire Cat and tea_party[3:] returns Alice, Jabberwocky.

You can also use negative indices to count items backtracking from the end of the list. So tea_party[-2:] returns the same output as tea_party[3:]: Alice, Jabberwocky.

Finally, Python equips you with the magic ability to slice strings the same way that you slice lists. A string can be considered as a list of characters, each of which having its own index starting from 0. For example, try running the following code:

a = 'flimsy'
b = 'miserable'
c = b[0:1] + a[2:]
print c
This code will output the string formed by the first character of miserable and the last four characters of flimsy:

mimsy
Problem
Given: A string s of length at most 200 letters and four integers a, b, c and d.

Return: The slice of this string from indices a through b and c through d (with space in between), inclusively. In other words, we should include elements s[b] and s[d] in our slice.

Sample Dataset
HumptyDumptysatonawallHumptyDumptyhadagreatfallAlltheKingshorsesandalltheKingsmenCouldntputHumptyDumptyinhisplaceagain.
22 27 97 102
Sample Output
Humpty Dumpty

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
strslice(const char *s, size_t a, size_t b, size_t c, size_t d, char *s1, char *s2)
{
	size_t n, m;

	if (b < a || d < c)
		return -1;

	n = b + 1 - a;
	m = d + 1 - c;
	memcpy(s1, s + a, n);
	memcpy(s2, s + c, m);
	s1[n] = '\0';
	s2[m] = '\0';
	return 0;
}

void
test(const char *s, size_t a, size_t b, size_t c, size_t d, char *r1, char *r2)
{
	char s1[32], s2[32];

	strslice(s, a, b, c, d, s1, s2);
	printf("%s %s\n", s1, s2);
	assert(!strcmp(s1, r1));
	assert(!strcmp(s2, r2));
}

int
main()
{
	test("HumptyDumptysatonawallHumptyDumptyhadagreatfallAlltheKingshorsesandalltheKingsmenCouldntputHumptyDumptyinhisplaceagain", 22, 27, 97, 102, "Humpty", "Dumpty");
	test("Bej1fCandoiajfOh0mXkzMw4nYe2KypwmEcVgTasxZwzKGKp2U8SZU9f0OmtnndpR0UAAVhrMjApnpHJIKfpsFRImlU2E0fNMVddwSBulkJF2e3VpNx8jnOHjyvwvAFgZZm0jslwoacerasPH83aA0VpR3dVDbfk3BjcrAoXbNobmcRYGjUWDjA3U6lbTWgHd42A.", 5, 11, 137, 142, "Candoia", "aceras");

	return 0;
}
