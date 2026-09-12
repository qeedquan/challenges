/*

Given any of the following characters (or a newline):

`1234567890-=~!@#$%^&*()_+qwertyuiop[]\QWERTYUIOP{}|asdfghjkl;'ASDFGHJKL:"zxcvbnm,./ZXCVBNM<>?
Your program must output the row that it is on the keyboard

Because my keyboard is (almost) out of battery, your code must be as short as possible

The keyboard your program should use (for the row lookup), should look like:


Row 1:~` !1@2 #3$4 %5^6 &7*8 (9)0 _-+=
Row 2:                         Q W E R T Y U I O P {[ }]    |\
Row 3:                              A S D F G H J K L :; "' ↵ return
Row 4:                                 Z X C V B N M <, >. ?/
Row 5:                                                    space


Where ↵  return is a newline. Empty keys don't mean anything.

Examples
"$"
1

"R"
2

"a"
3

"?"
4

"\n"
3

" "
5
where \n is a newline character.

Specifications
Your program should be case insensitive
Your program only needs to handle the characters on the keyboard shown

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
keyrow(int key)
{
	static const char *rows[] = {
	    "`1234567890-=~!@#$%^&*()_+",
	    "QWERTYUIOP{}|[]\\",
	    "ASDFGHJKL:\";'\n",
	    "ZXCVBNM<>?,./",
	    " ",
	};

	size_t i;

	for (i = 0; i < nelem(rows); i++) {
		if (strchr(rows[i], toupper(key)))
			return i + 1;
	}
	return -1;
}

int
main()
{
	assert(keyrow('$') == 1);
	assert(keyrow('R') == 2);
	assert(keyrow('a') == 3);
	assert(keyrow('?') == 4);
	assert(keyrow('\n') == 3);
	assert(keyrow(' ') == 5);

	return 0;
}
