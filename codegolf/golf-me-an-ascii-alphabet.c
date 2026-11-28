/*

Don't you find that reading simple text isn't appealing enough? Try our

#####  ###   ###  ##### #####       ##### ##### #   # #####   #
#   # #     #   #   #     #           #   #      # #    #     #
#####  ###  #       #     #           #   ####    #     #     #
#   #     # #   #   #     #           #   #      # #    #
#   #  ###   ###  ##### #####         #   ##### #   #   #     #
Much more fancy isn't it? But it's pretty long to write by hand, it would be wonderful if someone did a program that do it for me !

Your task, if you volunteer to help me, will be to write a program or a function that takes a string containing [a-zA-Z\s\n] only, and output (or return) the ascii writing of it!

You must use the following alphabet to format your output:

##### ####   ###  ####  ##### #####  ###  #   # ##### ##### #   # #     #   #
#   # #   # #   # #   # #     #     #     #   #   #     #   #  #  #     ## ##
##### ####  #     #   # ####  ####  #  ## #####   #     #   ###   #     # # #
#   # #   # #   # #   # #     #     #   # #   #   #   # #   # #   #     #   #
#   # ####   ###  ####  ##### #      ###  #   # ##### ###   #  #  ##### #   #

#   #  ###  ####   ###  ####   ###  ##### #   # #   # #   # #   # #   # #####
##  # #   # #   # #   # #   # #       #   #   # #   # #   #  # #   # #     #
# # # #   # ####  #   # ####   ###    #   #   #  # #  # # #   #     #     #
#  ## #   # #     #  ## ##        #   #   #   #  # #  ## ##  # #    #    #
#   #  ###  #      #### # #    ###    #    ###    #   #   # #   #   #   #####
The space:

     |
     | it's a 5x5 square of spaces
     | but had to pad it with |s to make it appear in this post
     |
     |
As this is a fixed-width font, the space character is also surrounded by spaces, resulting in a 7-width space between the two letters.

a b
     1234567       -- these numbers are just for the example, you don't have to output them
#####       ####
#   #       #   #
#####       ####
#   #       #   #
#   #       ####

a  b
     1234567890123
#####             ####
#   #             #   #
#####             ####
#   #             #   #
#   #             ####
When you encounter a newline, as in the input

ascii
text
Just make sure to separate the two blocks of text by at least one empty line

#####  ###   ###  ##### #####
#   # #     #   #   #     #
#####  ###  #       #     #
#   #     # #   #   #     #
#   #  ###   ###  ##### #####

##### ##### #   # #####
  #   #      # #    #
  #   ####    #     #
  #   #      # #    #
  #   ##### #   #   #
Also, you are allowed to replace the #s with any other character as long as it is in the printable ASCII range, and is not spaces. You could for instance use As for the letter A, B for the letter B and so on.

As this is code-golf (and moreover kolmogorov-complexity) the winning submission will be the one that solve this challenge in the least byte possible, have fun!

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char art[10][84] = {
	"##### ####   ###  ####  ##### #####  ###  #   # ##### ##### #   # #     #   #      ",
	"#   # #   # #   # #   # #     #     #     #   #   #     #   #  #  #     ## ##      ",
	"##### ####  #     #   # ####  ####  #  ## #####   #     #   ###   #     # # #      ",
	"#   # #   # #   # #   # #     #     #   # #   #   #   # #   # #   #     #   #      ",
	"#   # ####   ###  ####  ##### #      ###  #   # ##### ###   #  #  ##### #   #      ",
	"#   #  ###  ####   ###  ####   ###  ##### #   # #   # #   # #   # #   # #####      ",
	"##  # #   # #   # #   # #   # #       #   #   # #   # #   #  # #   # #     #       ",
	"# # # #   # ####  #   # ####   ###    #   #   #  # #  # # #   #     #     #        ",
	"#  ## #   # #     #  ## ##        #   #   #   #  # #  ## ##  # #    #    #         ",
	"#   #  ###  #      #### # #    ###    #    ###    #   #   # #   #   #   #####      ",
};

void
text(const char **s, size_t n)
{
	size_t i, j;
	size_t x, y;
	size_t dx, dy;
	int c;

	for (i = 0; i < n; i++) {
		for (y = 0; y < 5; y++) {
			for (j = 0; s[i][j]; j++) {
				c = tolower(s[i][j]);
				dy = 0;
				if ('a' <= c && c <= 'm')
					dx = 6 * (c - 'a');
				else if ('n' <= c && c <= 'z') {
					dx = 6 * (c - 'n');
					dy = 5;
				} else
					dx = 78;

				for (x = 0; x < 6; x++)
					putchar(art[y + dy][x + dx]);
			}
			putchar('\n');
		}
		putchar('\n');
	}
}

int
main()
{
	const char *s1[] = {
		"ascii",
		"text",
	};
	const char *s2[] = {
		"hello world",
		"nop zzz",
	};
	const char *s3[] = {
		"abcdefghijklm",
		"nopqrstuvwxyz",
	};

	text(s1, nelem(s1));
	text(s2, nelem(s2));
	text(s3, nelem(s3));

	return 0;
}
