/*

There are five workers : James,John,Robert,Michael and William.They work one by one and on weekends they rest. Order is same as in the description(James works on mondays,John works on tuesdays and so on).You have to create a function 'task' that will take 3 arguments(w, n, c):

Weekday

Number of trees that must be sprayed on that day

Cost of 1 litre liquid that is needed to spray tree,let's say one tree needs 1 litre liquid.

Let cost of all liquid be x

Your function should return string like this : 'It is (weekday) today, (name), you have to work, you must spray (number) trees and you need (x) dollars to buy liquid'

For example:

task('Monday', 15, 2) -> 'It is Monday today, James, you have to work, you must spray 15 trees and you need 30 dollars to buy liquid'

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
task(const char *weekday, int trees, int cost, char *output)
{
	static const struct assignment {
		char weekday[16];
		char name[16];
	} assignments[] = {
		{ "Monday", "James" },
		{ "Tuesday", "John" },
		{ "Wednesday", "Robert" },
		{ "Thursday", "Michael" },
		{ "Friday", "William" },
	};

	const struct assignment *assignment;
	size_t index;

	for (index = 0; index < nelem(assignments); index++) {
		assignment = assignments + index;
		if (!strcmp(weekday, assignment->weekday)) {
			sprintf(output, "It is %s today, %s, you have to work, you must spray %d trees and you need %d dollars to buy liquid",
			    weekday, assignment->name, trees, trees * cost);
			return output;
		}
	}
	return NULL;
}

void
test(const char *weekday, int trees, int cost, const char *expected)
{
	char output[128];

	assert(task(weekday, trees, cost, output));
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("Monday", 15, 2, "It is Monday today, James, you have to work, you must spray 15 trees and you need 30 dollars to buy liquid");
	return 0;
}
