/*

Your job is to figure out the index of which vowel is missing from a given string:

A has an index of 0,
E has an index of 1,
I has an index of 2,
O has an index of 3,
U has an index of 4.

Notes: There is no need for string validation and every sentence given will contain all vowels but one. Also, you won't need to worry about capitals.

Examples
"John Doe hs seven red pples under his bsket"          =>  0  ; missing: "a"
"Bb Smith sent us six neatly arranged range bicycles"  =>  3  ; missing: "o"

*/

#include <assert.h>
#include <string.h>
#include <ctype.h>

int
absent(const char *s)
{
	int f, i;

	for (f = 0x1f; *s; s++) {
		switch (tolower(*s)) {
		case 'a':
			f &= ~0x1;
			break;
		case 'e':
			f &= ~0x2;
			break;
		case 'i':
			f &= ~0x4;
			break;
		case 'o':
			f &= ~0x8;
			break;
		case 'u':
			f &= ~0x10;
			break;
		}
	}
	for (i = 0; i < 5; i++) {
		if (f & (1 << i))
			return i;
	}
	return -1;
}

int
main()
{
	assert(absent("John Doe hs seven red pples under his bsket") == 0);
	assert(absent("Bb Smith sent us six neatly arranged range bicycles") == 3);

	return 0;
}
