/*

"Introduce a little anarchy. Upset the established order and everything becomes chaos…" – Joker

"The city needs you, Batman! The Kings and Queens are being held for ransom and our only lead is a package we just received from the Joker: half a pack of cards, a jumble of numbers and letters, and a smile emoji. We have an hour... can you find him?" – Gotham City PD

Task
Help Gotham City PD decode the puzzle below. If all the letters of the Joker's name are encoded in the string of cards, return true. If not, return false. Note the input is a string of shuffled cards i.e. "6s5s4cAs4s2c7s..." and the name can be found in any order.

Card-letter correspondance
 Card | Letter
------+--------
  Jc  |   J
  7s  |   O
  5s  |   K
  As  |   E
  9c  |   R

Examples
"10s8s9c2s5s7c2c9s7sJc5cAs"  =>  true
"9s4s8c6s4c10c8sJs3s"        =>  false

*/

#include <assert.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
joker(const char *s)
{
	static const char *kw[] = {
	    "Jc",
	    "7s",
	    "5s",
	    "As",
	    "9c",
	};

	size_t i, j;
	int f;

	f = 0;
	for (i = 0; s[i]; i++) {
		for (j = 0; j < nelem(kw); j++) {
			if (!strncmp(s + i, kw[j], 2)) {
				f |= (1 << j);
				break;
			}
		}
	}
	return f == 0x1f;
}

int
main()
{
	assert(joker("10s8s9c2s5s7c2c9s7sJc5cAs") == true);
	assert(joker("9s4s8c6s4c10c8sJs3s") == false);
	return 0;
}
