/*

As a programmer, you've probably heard of forward slashes and backward slashes. But have you heard of downslashes? That's when you take a bunch of slashes, connect their ends and draw them going down.

For today's challenge, you must write a program or function that takes a string consisting purely of slashes, and outputs all of those slashes drawn downwards in a line connecting them.
This will be a lot more clear if you see an example. Given the string \\\//\/\\, you should output:

\
 \
  \
  /
 /
 \
 /
 \
  \
Here are some clarifications:

There must be one slash per line.

The first line will have 0 leading spaces.

For each pair of slashes:

If they are different from each other, they will be drawn in the same column. For example, \/ will give:

\
/
If they are the same character, the lower one is in the direction pointed to, that is moving to the right for a backslash, and moving to the left for a forward slash. So \\// will give

\
 \
 /
/
Each line may have extra trailing whitespace as long as this doesn't change the visual appearance of the output. Up to one trailing and leading newline is also acceptable. Extra leading spaces are not permitted!

In order to keep this simpler, you can assume that the string will never contain too many forward slashes.
In other words, no prefix of the input will contain more forward slashes than backslashes, so an input like \\//// or // will never be given.
This also means that every input will start with a backslash.

If your input is taken as a string literal, you may escape the backslashes if this is necessary. You will also never need to handle an input that is empty, or contains characters other than a slash.

You may output by any reasonable format.

As usual, this is a code-golf challenge, so try to make the shortest solution possible, even if you pick a language where this is rather difficult. Bonus points for explaining any interesting techniques you used to take bytes off!

Examples
#Input
\\\\\\\\\\\

#Output
\
 \
  \
   \
    \
     \
      \
       \
        \
         \
          \

#Input
\\\//\\/\//\\///

#Output
\
 \
  \
  /
 /
 \
  \
  /
  \
  /
 /
 \
  \
  /
 /
/


#Input
\/\/\/

#Output
\
/
\
/
\
/

*/

#include <stdio.h>

void
downslash(const char *s)
{
	const char *p;
	size_t i, n;

	n = 0;
	for (p = s; *p; p++) {
		if (*p == '/' && n > 0)
			n--;

		for (i = 0; i < n; i++)
			printf(" ");
		printf("%c\n", *p);

		if (*p == '\\')
			n++;
	}
	printf("\n");
}

int
main(void)
{
	downslash("\\\\\\\\\\\\\\\\\\\\\\");
	downslash("\\\\\\//\\\\/\\//\\\\///");
	downslash("\\/\\/\\/");

	return 0;
}
