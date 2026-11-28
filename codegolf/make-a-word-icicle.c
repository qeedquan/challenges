/*

Due to technical limitations of Stack Exchange, the title is rendered incorrectly. The correct title for this challenge is

Make a

Word Icicle!
Word Icicle
Word  cicle
 ord  cicle
 ord   icle
 ord   i le
 or    i le
 or    i l
 or      l
 or
  r
Today's challenge is to make icicles out of the input word. Given a string of entirely printable ASCII, and at least 2 non-space characters, perform the following steps:

Print the current state of the string.

Replace the lexically smallest character (other than spaces) with a space. If there is a tie, replace the leftmost character.

Repeat on consecutive lines until the string contains only 1 non-space character.

This creates the effect that the input string looks like it's melting...

I'm Melting!!!
I'm Melting !!
I'm Melting  !
I'm Melting
I m Melting
  m Melting
  m  elting
  m   lting
  m   ltin
  m   lt n
  m    t n
       t n
       t
Rules
After a couple iterations, your output will almost surely have trailing spaces on each line. If you choose to truncate these, that is allowed.

You may have one trailing empty line, but not more.

Remember that the input may contain several spaces, but these are all effectively skipped. For example, the input a     a should give

a      a
       a
You may take input as a list of strings if you want. For output, you may return or print a list of strings, a single string with newlines, or char matrix/2D array. Generally, I prefer permissive IO formats, so other formats are most likely allowed as long as they are consistent and clearly correspond to the right output. If in doubt, feel free to ask. As usual, full programs or functions are allowed.

Remember, this is a contest to make the shortest answer in any language! If you choose to answer in Java, try to make the shortest Java answer (in bytes) that you can.

Test cases
Hello World! -->

Hello World!
Hello World
 ello World
 ello  orld
 ello  orl
  llo  orl
   lo  orl
    o  orl
    o  or
       or
        r


AbCdEfGhIjKlMnOpQrStUvWxYz -->

AbCdEfGhIjKlMnOpQrStUvWxYz
 bCdEfGhIjKlMnOpQrStUvWxYz
 b dEfGhIjKlMnOpQrStUvWxYz
 b d fGhIjKlMnOpQrStUvWxYz
 b d f hIjKlMnOpQrStUvWxYz
 b d f h jKlMnOpQrStUvWxYz
 b d f h j lMnOpQrStUvWxYz
 b d f h j l nOpQrStUvWxYz
 b d f h j l n pQrStUvWxYz
 b d f h j l n p rStUvWxYz
 b d f h j l n p r tUvWxYz
 b d f h j l n p r t vWxYz
 b d f h j l n p r t v xYz
 b d f h j l n p r t v x z
   d f h j l n p r t v x z
     f h j l n p r t v x z
       h j l n p r t v x z
         j l n p r t v x z
           l n p r t v x z
             n p r t v x z
               p r t v x z
                 r t v x z
                   t v x z
                     v x z
                       x z
                         z


PPCG is da BEST -->

PPCG is da BEST
PPCG is da  EST
PP G is da  EST
PP G is da   ST
PP   is da   ST
 P   is da   ST
     is da   ST
     is da    T
     is da
     is d
     is
      s


({({})({}[()])}{}) -->

({({})({}[()])}{})
 {({})({}[()])}{})
 { {})({}[()])}{})
 { {}) {}[()])}{})
 { {}) {}[ )])}{})
 { {}  {}[ )])}{})
 { {}  {}[  ])}{})
 { {}  {}[  ] }{})
 { {}  {}[  ] }{}
 { {}  {}   ] }{}
 { {}  {}     }{}
   {}  {}     }{}
    }  {}     }{}
    }   }     }{}
    }   }     } }
        }     } }
              } }
                }

*/

#include <stdio.h>
#include <ctype.h>

void
icicle(char *s)
{
	size_t i, j;
	int c;

	for (;;) {
		c = 0;
		for (i = j = 0; s[i]; i++) {
			putchar(s[i]);
			if (!isspace(s[i])) {
				if (c == 0 || c > s[i]) {
					c = s[i];
					j = i;
				}
			}
		}
		putchar('\n');

		if (c == 0)
			break;
		s[j] = ' ';
	}
}

int
main()
{
	char s1[] = "Word Icicle!";
	char s2[] = "I'm Melting!!!";
	char s3[] = "Hello World!";
	char s4[] = "AbCdEfGhIjKlMnOpQrStUvWxYz";
	char s5[] = "PPCG is da BEST";
	char s6[] = "({({})({}[()])}{})";

	icicle(s1);
	icicle(s2);
	icicle(s3);
	icicle(s4);
	icicle(s5);
	icicle(s6);

	return 0;
}
