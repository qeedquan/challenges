/*

Output the following text exactly.

You may have additional trailing whitespace on eac line, and trailing newlines as well.
Shortest code, in bytes, wins.

                                              !"!
                                             "#$#"
                                            #$%&%$#
                                           $%&'('&%$
                                          %&'()*)('&%
                                         &'()*+,+*)('&
                                        '()*+,-.-,+*)('
                                       ()*+,-./0/.-,+*)(
                                      )*+,-./01210/.-,+*)
                                     *+,-./012343210/.-,+*
                                    +,-./0123456543210/.-,+
                                   ,-./01234567876543210/.-,
                                  -./0123456789:9876543210/.-
                                 ./0123456789:;<;:9876543210/.
                                /0123456789:;<=>=<;:9876543210/
                               0123456789:;<=>?@?>=<;:9876543210
                              123456789:;<=>?@ABA@?>=<;:987654321
                             23456789:;<=>?@ABCDCBA@?>=<;:98765432
                            3456789:;<=>?@ABCDEFEDCBA@?>=<;:9876543
                           456789:;<=>?@ABCDEFGHGFEDCBA@?>=<;:987654
                          56789:;<=>?@ABCDEFGHIJIHGFEDCBA@?>=<;:98765
                         6789:;<=>?@ABCDEFGHIJKLKJIHGFEDCBA@?>=<;:9876
                        789:;<=>?@ABCDEFGHIJKLMNMLKJIHGFEDCBA@?>=<;:987
                       89:;<=>?@ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA@?>=<;:98
                      9:;<=>?@ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA@?>=<;:9
                     :;<=>?@ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA@?>=<;:
                    ;<=>?@ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA@?>=<;
                   <=>?@ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA@?>=<
                  =>?@ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA@?>=
                 >?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\[ZYXWVUTSRQPONMLKJIHGFEDCBA@?>
                ?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^]\[ZYXWVUTSRQPONMLKJIHGFEDCBA@?
               @ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`_^]\[ZYXWVUTSRQPONMLKJIHGFEDCBA@
              ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`aba`_^]\[ZYXWVUTSRQPONMLKJIHGFEDCBA
             BCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdcba`_^]\[ZYXWVUTSRQPONMLKJIHGFEDCB
            CDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefedcba`_^]\[ZYXWVUTSRQPONMLKJIHGFEDC
           DEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghgfedcba`_^]\[ZYXWVUTSRQPONMLKJIHGFED
          EFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijihgfedcba`_^]\[ZYXWVUTSRQPONMLKJIHGFE
         FGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklkjihgfedcba`_^]\[ZYXWVUTSRQPONMLKJIHGF
        GHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnmlkjihgfedcba`_^]\[ZYXWVUTSRQPONMLKJIHG
       HIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnoponmlkjihgfedcba`_^]\[ZYXWVUTSRQPONMLKJIH
      IJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrqponmlkjihgfedcba`_^]\[ZYXWVUTSRQPONMLKJI
     JKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstsrqponmlkjihgfedcba`_^]\[ZYXWVUTSRQPONMLKJ
    KLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvutsrqponmlkjihgfedcba`_^]\[ZYXWVUTSRQPONMLK
   LMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxwvutsrqponmlkjihgfedcba`_^]\[ZYXWVUTSRQPONML
  MNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba`_^]\[ZYXWVUTSRQPONM
 NOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|{zyxwvutsrqponmlkjihgfedcba`_^]\[ZYXWVUTSRQPON
OPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~}|{zyxwvutsrqponmlkjihgfedcba`_^]\[ZYXWVUTSRQPO

*/

#include <stdio.h>

void
pylons()
{
	int c, y;

	for (y = 0; y < 48; y++) {
		for (c = (2 * y) - 15; c < 32 + (2 * y); c++) {
			if (c > 31 + y)
				putchar(c);
			else
				putchar(' ');
		}
		for (; c > 31 + y; c--)
			putchar(c);
		putchar('\n');
	}
}

int
main()
{
	pylons();
	return 0;
}
