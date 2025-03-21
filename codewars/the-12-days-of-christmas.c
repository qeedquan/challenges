/*

Oh No!

The song sheets have been dropped in the snow and the lines of each verse have become all jumbled up.

Task
You have to write a comparator function which can sort the lines back into their correct order, otherwise Christmas will be cancelled!

Reminder: Below is what the final verse should look like

On the 12th day of Christmas my true love gave to me
12 drummers drumming,
11 pipers piping,
10 lords a leaping,
9 ladies dancing,
8 maids a milking,
7 swans a swimming,
6 geese a laying,
5 golden rings,
4 calling birds,
3 French hens,
2 turtle doves and
a partridge in a pear tree.

Background
A Java comparator function ( https://docs.oracle.com/javase/8/docs/api/java/util/Comparator.html ) is described as below. Other languages are similar:

int compare(T o1, T o2) Compares its two arguments for order. Returns a negative integer, zero, or a positive integer as the first argument is less than, equal to, or greater than the second.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
find(const char *s)
{
	static const char *verse[] = {
		"On the 12th day of Christmas my true love gave to me",
		"12 drummers drumming,",
		"11 pipers piping,",
		"10 lords a leaping,",
		"9 ladies dancing,",
		"8 maids a milking,",
		"7 swans a swimming,",
		"6 geese a laying,",
		"5 golden rings,",
		"4 calling birds,",
		"3 French hens,",
		"2 turtle doves and",
		"a partridge in a pear tree.",
	};

	size_t i;

	for (i = 0; i < nelem(verse); i++) {
		if (!strcmp(s, verse[i]))
			return i;
	}
	return -1;
}

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = find(a);
	y = find(b);
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
main()
{
	return 0;
}
