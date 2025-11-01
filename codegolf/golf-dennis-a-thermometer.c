/*

Dennis puts in a huge amount of effort for this community, including as moderator, language designer, and provider of TIO.

Unfortunately, his four-year-old daughter has caught a cold, so let us all help him keep track of her recovery (may it be speedy) by providing him with a thermometer:

.-----------.
|           |
|           |
'-.       .-'
.-'   -   '-.
|107.6- 42.0|
|106.7- 41.5|
|105.8- 41.0|
|104.9- 40.5|
|104.0- 40.0|
|103.1- 39.5|
|102.2- 39.0|
|101.3- 38.5|
|100.4- 38.0|
| 99.5- 37.5|
| 98.6- 37.0|
| 97.7- 36.5|
| 96.8- 36.0|
| 95.9- 35.5|
| 95.0- 35.0|
'---. - .---'
    | - |
    |---|
    |   |
    '---'
Since Dennis does not have much time to read code, you must keep yours as short as possible.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
thermometer(void)
{
	static const double values[][2] = {
	    {107.6, 42.},
	    {106.7, 41.5},
	    {105.8, 41.0},
	    {104.9, 40.5},
	    {104.0, 40.0},
	    {103.1, 39.5},
	    {102.2, 39.0},
	    {101.3, 38.5},
	    {100.4, 38.0},
	    {99.5, 37.5},
	    {98.6, 37.0},
	    {97.7, 36.5},
	    {96.8, 36.0},
	    {95.9, 35.5},
	    {95.0, 35.0},
	};

	size_t i;

	puts(".-----------.");
	puts("|           |");
	puts("|           |");
	puts("'-.       .-'");
	puts(".-'   -   '-.");

	for (i = 0; i < nelem(values); i++)
		printf("|%5.1f-%5.1f|\n", values[i][0], values[i][1]);

	puts("'---. - .---'");
	puts("    | - |");
	puts("    |---|");
	puts("    |   |");
	puts("    '---'");
}

int
main(void)
{
	thermometer();
	return 0;
}
