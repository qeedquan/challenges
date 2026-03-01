/*

A category page displays a set number of products per page, with pagination at the bottom allowing the user to move from page to page.

Given that you know the page you are on, how many products are in the category in total, and how many products are on any given page, how would you output a simple string showing which products you are viewing..

Examples
In a category of 30 products with 10 products per page, on page 1 you would see

'Showing 1 to 10 of 30 Products.'

In a category of 26 products with 10 products per page, on page 3 you would see

'Showing 21 to 26 of 26 Products.'

In a category of 8 products with 10 products per page, on page 1 you would see

'Showing 1 to 8 of 8 Products.'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

char *
pagination(int pagenumber, int pagesize, int totalproducts, char *output)
{
	int value0;
	int value1;

	value0 = (pagesize * pagenumber) - pagesize + 1;
	value1 = min(pagesize * pagenumber, totalproducts);
	sprintf(output, "Showing %d to %d of %d Products.", value0, value1, totalproducts);
	return output;
}

void
test(int pagenumber, int pagesize, int totalproducts, const char *expected)
{
	char output[128];

	pagination(pagenumber, pagesize, totalproducts, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test(1, 10, 30, "Showing 1 to 10 of 30 Products.");
	test(3, 10, 26, "Showing 21 to 26 of 26 Products.");
	test(1, 10, 8, "Showing 1 to 8 of 8 Products.");
	test(2, 30, 350, "Showing 31 to 60 of 350 Products.");
	test(1, 23, 30, "Showing 1 to 23 of 30 Products.");
	test(2, 23, 30, "Showing 24 to 30 of 30 Products.");
	test(43, 15, 3456, "Showing 631 to 645 of 3456 Products.");

	return 0;
}
