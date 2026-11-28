/*

Some new cashiers started to work at your restaurant.

They are good at taking orders, but they don't know how to capitalize words, or use a space bar!

All the orders they create look something like this:

"milkshakepizzachickenfriescokeburgerpizzasandwichmilkshakepizza"

The kitchen staff are threatening to quit, because of how difficult it is to read the orders.

Their preference is to get the orders as a nice clean string with spaces and capitals like so:

"Burger Fries Chicken Pizza Pizza Pizza Sandwich Milkshake Milkshake Coke"

The kitchen staff expect the items to be in the same order as they appear in the menu.

The menu items are fairly simple, there is no overlap in the names of the items:

1. Burger
2. Fries
3. Chicken
4. Pizza
5. Sandwich
6. Onionrings
7. Milkshake
8. Coke

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
getorder(const char *input, char *output)
{
	static const char *food[] = {"Burger", "Fries", "Chicken", "Pizza", "Sandwich", "Onionrings", "Milkshake", "Coke"};
	static const char pattern[] = "(burger|fries|chicken|pizza|sandwich|onionrings|milkshake|coke)";
	static const char code[] = "bfcpsomc";

	regex_t re;
	regmatch_t match[1];
	size_t foodcount[8];
	size_t count;
	size_t index;
	size_t length;
	int char0;
	int char1;

	if (regcomp(&re, pattern, REG_EXTENDED | REG_ICASE))
		return NULL;

	memset(foodcount, 0, sizeof(foodcount));
	while (!regexec(&re, input, nelem(match), match, 0)) {
		char0 = tolower(input[0]);
		char1 = tolower(input[1]);
		if (char0 == 'c' && char1 == 'o')
			index = nelem(code) - 2;
		else
			index = strchr(code, char0) - code;

		foodcount[index]++;
		input += match->rm_eo;
	}

	length = 0;
	for (index = 0; index < nelem(food); index++) {
		for (count = 0; count < foodcount[index]; count++)
			length += sprintf(output + length, "%s ", food[index]);
	}
	if (length)
		output[length - 1] = '\0';
	else
		output[0] = '\0';

	regfree(&re);
	return output;
}

void
test(const char *input, const char *expected)
{
	char output[128];

	getorder(input, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("milkshakepizzachickenfriescokeburgerpizzasandwichmilkshakepizza", "Burger Fries Chicken Pizza Pizza Pizza Sandwich Milkshake Milkshake Coke");
	test("pizzachickenfriesburgercokemilkshakefriessandwich", "Burger Fries Fries Chicken Pizza Sandwich Milkshake Coke");

	return 0;
}
