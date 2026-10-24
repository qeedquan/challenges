/*

- Kids drink toddy.
- Teens drink coke.
- Young adults drink beer.
- Adults drink whisky.

Make a function that receive age, and return what they drink.

**Rules:**

- Children under 14 old.
- Teens under 18 old.
- Young under 21 old.
- Adults have 21 or more.

**Examples: (Input --> Output)**

13 --> "drink toddy"
17 --> "drink coke"
18 --> "drink beer"
20 --> "drink beer"
30 --> "drink whisky"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
drink(int age, char *buf)
{
	if (age < 14)
		sprintf(buf, "drink toddy");
	else if (age < 18)
		sprintf(buf, "drink coke");
	else if (age < 21)
		sprintf(buf, "drink beer");
	else
		sprintf(buf, "drink whisky");
	return buf;
}

void
test(int age, const char *res)
{
	char buf[32];

	drink(age, buf);
	puts(buf);
	assert(!strcmp(buf, res));
}

int
main()
{
	test(13, "drink toddy");
	test(14, "drink coke");
	test(16, "drink coke");
	test(17, "drink coke");
	test(18, "drink beer");
	test(20, "drink beer");
	test(21, "drink whisky");
	test(30, "drink whisky");

	return 0;
}
