/*

Can you calculate total amount of vodka that Vodka God have drank on his festival?Unfortunately Vodka God drank from various goblets with different capacities.

Task:
Write function which accepts an array of drank amounts from various cups and calculate total amount of vodka drunk by god.Result must be rounded to nearest one and can be return both in literes or mililitres.
Function input:
-There will be only 2 types of units litres and mililitres.
-Array will never be empty(hey its festival).
//capacity format:
//-number can be a float.
//-only small letters.
var shots = ["500ml","2l","1.4l"];

//output must be in same format.
vodkaConsumption(shots) //must return "3900ml" or "4l"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
vodka(const char **shots, size_t length, char *output)
{
	double value, total;
	char unit[4];
	size_t index;

	for (index = 0; index < length; index++) {
		if (sscanf(shots[index], "%lf%3s", &value, unit) != 2)
			continue;

		if (!strcmp(unit, "ml"))
			total += value;
		else if (!strcmp(unit, "l"))
			total += value * 1000;
	}
	sprintf(output, "%.0fml", total);
	return output;
}

void
test(const char **shots, size_t length)
{
	char output[128];

	vodka(shots, length, output);
	puts(output);
}

int
main()
{
	const char *shots[] = { "500ml", "2l", "1.4l" };

	test(shots, nelem(shots));

	return 0;
}
