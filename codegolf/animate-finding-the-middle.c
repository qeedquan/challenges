/*

Given a non-empty string, keep removing the first and last characters until you get to one or two characters.

For example, if the string was abcde, your program should print:

abcde
 bcd
  c
However, if it was abcdef, it should stop at two characters:

abcdef
 bcde
  cd
Trailing newlines and trailing spaces at the end of each line are optional. You can have as many as you want or none.

Test cases
ABCDEFGHIJKLMNOPQRSTUVWXYZ -> ABCDEFGHIJKLMNOPQRSTUVWXYZ
                               BCDEFGHIJKLMNOPQRSTUVWXY
                                CDEFGHIJKLMNOPQRSTUVWX
                                 DEFGHIJKLMNOPQRSTUVW
                                  EFGHIJKLMNOPQRSTUV
                                   FGHIJKLMNOPQRSTU
                                    GHIJKLMNOPQRST
                                     HIJKLMNOPQRS
                                      IJKLMNOPQR
                                       JKLMNOPQ
                                        KLMNOP
                                         LMNO
                                          MN

ABCDEFGHIJKLMNOPQRSTUVWXYZ! -> ABCDEFGHIJKLMNOPQRSTUVWXYZ!
                                BCDEFGHIJKLMNOPQRSTUVWXYZ
                                 CDEFGHIJKLMNOPQRSTUVWXY
                                  DEFGHIJKLMNOPQRSTUVWX
                                   EFGHIJKLMNOPQRSTUVW
                                    FGHIJKLMNOPQRSTUV
                                     GHIJKLMNOPQRSTU
                                      HIJKLMNOPQRST
                                       IJKLMNOPQRS
                                        JKLMNOPQR
                                         KLMNOPQ
                                          LMNOP
                                           MNO
                                            N

A -> A

AB -> AB

Remember this is code-golf, so the code with the smallest number of bytes wins.

*/

#include <stdio.h>
#include <string.h>

void
animate(const char *s)
{
	size_t i, j, n;

	n = strlen(s);
	for (i = 0; i < n; i++, n--) {
		for (j = 0; j < i; j++)
			printf(" ");
		for (j = i; j < n; j++)
			printf("%c", s[j]);
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	animate("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	animate("ABCDEFGHIJKLMNOPQRSTUVWXYZ!");
	animate("A");
	animate("AB");
	animate("abcde");
	animate("abcdef");

	return 0;
}
