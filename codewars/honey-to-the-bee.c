/*

Find out why the amount of honey in the hive is not increasing.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int pollen;
} Hive;

typedef struct {
	int capacity;
	Hive *hive;
} Bee;

void
inithive(Hive *hive)
{
	hive->pollen = 100;
}

void
addpollen(Hive *hive, int pollen)
{
	hive->pollen += pollen;
}

int
getpollen(Hive *hive)
{
	return hive->pollen;
}

void
initbee(Bee *bee, int capacity, Hive *hive)
{
	bee->capacity = capacity;
	bee->hive = hive;
}

void
unloadpollen(Bee *bee)
{
	addpollen(bee->hive, bee->capacity);
}

int
main()
{
	Hive hive;
	Bee bees[10];
	size_t i;

	inithive(&hive);
	for (i = 0; i < nelem(bees); i++)
		initbee(&bees[i], 100, &hive);
	for (i = 0; i < nelem(bees); i++)
		unloadpollen(&bees[i]);
	printf("%d\n", getpollen(&hive));
	return 0;
}
