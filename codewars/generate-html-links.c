/*

Generate HTML links
We need a HTML menu.... but writing HTML over and-over-again is boooring... Let's just generate it instead!

Task:
Write a function generateMenu() with the following inputs/output:

Inputs:
menuItems: An array of objects (with url and text properties), which represents our menu items

Output:
A string of HTML containing an anchor tag ( https://developer.mozilla.org/en/docs/Web/HTML/Element/a ) for each element of menuItems (with the appropriate href attribute and text content)

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	const char *url;
	const char *text;
} Link;

void
menu(Link *links, size_t nlinks)
{
	size_t i;

	for (i = 0; i < nlinks; i++) {
		printf("<a href=\"%s\">%s</a>\n", links[i].url, links[i].text);
	}
}

int
main()
{
	Link links[] = {
	    {"http://www.google.com", "Google"},
	    {"http://www.youtube.com", "Youtube"},
	};

	menu(links, nelem(links));
	return 0;
}
