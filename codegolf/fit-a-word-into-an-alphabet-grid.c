/*

Inspired by a meme I saw earlier today.

Challenge description
Consider an infinite alphabet grid:

ABCDEFGHIJKLMNOPQRSTUVWXYZ
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ABCDEFGHIJKLMNOPQRSTUVWXYZ
...
Take a word (CODEGOLF in this example) and make it a subsequence of the grid, replacing unused letters by a space and removing letters at the end of the infinite grid altogether:

  C           O
   DE G       O
           L
     F
Examples
STACKEXCHANGE

                  ST
A C       K
    E                  X
  C    H
A            N
      G
    E
ZYXWVUTSRQPONMLKJIHGFEDCBA

                         Z
                        Y
                       X
                      W
                     V
                    U
                   T
                  S
                 R
                Q
               P
              O
             N
            M
           L
          K
         J
        I
       H
      G
     F
    E
   D
  C
 B
A
F

     F
ANTIDISESTABLISHMENTARIANISM

A            N     T
        I
   D    I         S
    E             ST
AB         L
        I         S
       H    M
    E        N     T
A                R
        I
A            N
        I         S
            M
Notes
Trailing whitespaces are allowed.
You don't need to pad the last any line with spaces. For example, if the input is ABC, you may output just ABC without 23 trailing spaces.
You may assume input will match [A-Z]+ regex.
Alternatively, you may use lower-case alphabet, in which case output will match [a-z]+.
You must use a newline (\n, \r\n or equivalent) to separate lines, that is a list of strings is not a proper output format.
This is a code-golf challenge, so make your code as short as possible!

*/

#include <stdio.h>
#include <ctype.h>

void
fitword(const char *s)
{
	int c, c1;
	size_t i;

	c = 'A';
	for (i = 0; s[i];) {
		c1 = toupper(s[i]);
		if (!('A' <= c1 && c1 <= 'Z')) {
			i++;
			continue;
		}

		if (c == c1)
			printf("%c", s[i++]);
		else
			printf(" ");

		if (c++ == 'Z') {
			c = 'A';
			printf("\n");
		}
	}

	printf("\n");
}

int
main(void)
{
	fitword("CODEGOLF");
	fitword("STACKEXCHANGE");
	fitword("ZYXWVUTSRQPONMLKJIHGFEDCBA");
	fitword("F");
	fitword("ANTIDISESTABLISHMENTARIANISM");
	fitword("SUPERCALIFRAGILISTICEXPIALIDOCIOUS");

	return 0;
}
