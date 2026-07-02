/*

I have an ASCII-art box and I need a program to open it.

Examples
Input:

-------
|     |
|_____|

Output:

      /
     /
    /
   /
  /
 /
/
|     |
|_____|

Specification
The first line will only consist of -, at least 3 of them
The middle rows will start with | have spaces, and end with |
All the middle rows will be the same
The last row will start with | have _ and end with a |
All rows will be the same length
Opening the box:

Each - should be replaced by a / in ascending lines and position.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
openbox(const char **s, size_t n)
{
	size_t i, j, w;

	if (n == 0)
		return;

	w = strlen(s[0]);
	for (i = w; i > 0; i--) {
		for (j = 1; j <= w; j++) {
			if (j == i)
				printf("/");
			else
				printf(" ");
		}
		printf("\n");
	}

	for (i = 1; i < n; i++)
		puts(s[i]);
}

int
main()
{
	const char *s1[] = {
		"-------",
		"|     |",
		"|_____|",
	};

	openbox(s1, nelem(s1));

	return 0;
}
