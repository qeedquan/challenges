/*

Jaimito just graduated high school and wants to use his newfound freedom to travel the world before attending college, assuming debt, and being coerced to work for The Man. Having grown up in the same city his entire life, he wants to go as far away as possible, while remaining in budget. Help Jaimito plan his trip by providing him with the information he needs.

You will be given an array of objects. Each object will contain a destination, the distance to that destination, and the price of a ticket to that destination. Your job will be to return an array of destinations sorted by distance (in descending order) first and price (in ascending order) second.

Example:

Given the following array of objects:

[ {'dest': 'ATL', 'dist': 1300, 'price': 200} ,
{'dest': 'PEK', 'dist': 7000, 'price': 700} ,
{'dest': 'DXB', 'dist': 9000, 'price': 900} ,
{'dest': 'LAX', 'dist': 1300, 'price': 150} ]

You should return ['DXB', 'PEK', 'LAX', 'ATL']

Note:

'dist' and 'price' will always be integers, and 'dest' will always be a three-lettered string.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	char dest[4];
	int dist;
	int price;
} Trip;

int
cmp(const void *a, const void *b)
{
	const Trip *x, *y;

	x = a;
	y = b;
	if (x->dist > y->dist)
		return -1;
	if (x->dist < y->dist)
		return 1;
	if (x->price < y->price)
		return -1;
	if (x->price > y->price)
		return 1;
	return 0;
}

int
main()
{
	Trip trips[] = {
		{ "ATL", 1300, 200 },
		{ "PEK", 7000, 700 },
		{ "DXB", 9000, 900 },
		{ "LAX", 1300, 150 },
	};

	Trip *trip;
	size_t i;

	qsort(trips, nelem(trips), sizeof(*trips), cmp);
	for (i = 0; i < nelem(trips); i++) {
		trip = trips + i;
		printf("%s ", trip->dest);
	}
	printf("\n");

	return 0;
}
