/*

Oh no!
The new zookeeper has lost track of how many animals are in the zoo because the last person to do the count thought it would be funny to do it in binary.

Write a function that can help the zookeper convert the binary count.
Input will be an object where key:value-pairs will represent an animal and a binary number.
Output should be an integer that equals the sum of all the animals in the zoo.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char name[32];
	char binary[32];
} Animal;

long
count(Animal *animals, size_t size)
{
	size_t index;
	long total;

	total = 0;
	for (index = 0; index < size; index++)
		total += strtol(animals[index].binary, NULL, 2);
	return total;
}

int
main()
{
	Animal animals[] = {
		{ "aardvark", "1101" },
		{ "tiger",    "1100" },
		{ "donkey",   "1100" },
		{ "emu",      "1010" },
	};

	assert(count(animals, nelem(animals)) == 47);
	return 0;
}
