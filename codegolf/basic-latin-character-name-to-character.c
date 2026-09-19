/*

Let's get back to basics!

Your code, a complete program or function, must convert the official Unicode name of a printable Basic Latin character into the corresponding character. For example, for the input LOW LINE your code must output _.
You only need to take a single character name as input.
You cannot use any preexisting function or library, built-in or otherwise, which offers any logic relating specifically to Unicode character names (e.g. Python's unicodedata, Java's Character.getName, and so on.)
For input other than one of these names, any behavior is acceptable.
This is code golf: shortest code in bytes wins.

To avoid any ambiguity, this is the full set of official character names we'll be using (borrowed from this question):

     SPACE
!    EXCLAMATION MARK
"    QUOTATION MARK
#    NUMBER SIGN
$    DOLLAR SIGN
%    PERCENT SIGN
&    AMPERSAND
'    APOSTROPHE
(    LEFT PARENTHESIS
)    RIGHT PARENTHESIS
*    ASTERISK
+    PLUS SIGN
,    COMMA
-    HYPHEN-MINUS
.    FULL STOP
/    SOLIDUS
0    DIGIT ZERO
1    DIGIT ONE
2    DIGIT TWO
3    DIGIT THREE
4    DIGIT FOUR
5    DIGIT FIVE
6    DIGIT SIX
7    DIGIT SEVEN
8    DIGIT EIGHT
9    DIGIT NINE
:    COLON
;    SEMICOLON
<    LESS-THAN SIGN
=    EQUALS SIGN
>    GREATER-THAN SIGN
?    QUESTION MARK
@    COMMERCIAL AT
A    LATIN CAPITAL LETTER A
B    LATIN CAPITAL LETTER B
C    LATIN CAPITAL LETTER C
D    LATIN CAPITAL LETTER D
E    LATIN CAPITAL LETTER E
F    LATIN CAPITAL LETTER F
G    LATIN CAPITAL LETTER G
H    LATIN CAPITAL LETTER H
I    LATIN CAPITAL LETTER I
J    LATIN CAPITAL LETTER J
K    LATIN CAPITAL LETTER K
L    LATIN CAPITAL LETTER L
M    LATIN CAPITAL LETTER M
N    LATIN CAPITAL LETTER N
O    LATIN CAPITAL LETTER O
P    LATIN CAPITAL LETTER P
Q    LATIN CAPITAL LETTER Q
R    LATIN CAPITAL LETTER R
S    LATIN CAPITAL LETTER S
T    LATIN CAPITAL LETTER T
U    LATIN CAPITAL LETTER U
V    LATIN CAPITAL LETTER V
W    LATIN CAPITAL LETTER W
X    LATIN CAPITAL LETTER X
Y    LATIN CAPITAL LETTER Y
Z    LATIN CAPITAL LETTER Z
[    LEFT SQUARE BRACKET
\    REVERSE SOLIDUS
]    RIGHT SQUARE BRACKET
^    CIRCUMFLEX ACCENT
_    LOW LINE
`    GRAVE ACCENT
a    LATIN SMALL LETTER A
b    LATIN SMALL LETTER B
c    LATIN SMALL LETTER C
d    LATIN SMALL LETTER D
e    LATIN SMALL LETTER E
f    LATIN SMALL LETTER F
g    LATIN SMALL LETTER G
h    LATIN SMALL LETTER H
i    LATIN SMALL LETTER I
j    LATIN SMALL LETTER J
k    LATIN SMALL LETTER K
l    LATIN SMALL LETTER L
m    LATIN SMALL LETTER M
n    LATIN SMALL LETTER N
o    LATIN SMALL LETTER O
p    LATIN SMALL LETTER P
q    LATIN SMALL LETTER Q
r    LATIN SMALL LETTER R
s    LATIN SMALL LETTER S
t    LATIN SMALL LETTER T
u    LATIN SMALL LETTER U
v    LATIN SMALL LETTER V
w    LATIN SMALL LETTER W
x    LATIN SMALL LETTER X
y    LATIN SMALL LETTER Y
z    LATIN SMALL LETTER Z
{    LEFT CURLY BRACKET
|    VERTICAL LINE
}    RIGHT CURLY BRACKET
~    TILDE

*/

#include <stdio.h>

const char *
lookup(int c)
{
	static const char *lut[256] = {
	    ['&'] = "AMPERSAND",
	    ['\''] = "APOSTROPHE",
	    ['*'] = "ASTERISK",
	    ['^'] = "CIRCUMFLEX ACCENT",
	    [':'] = "COLON",
	    [','] = "COMMA",
	    ['@'] = "COMMERCIAL AT",
	    ['8'] = "DIGIT EIGHT",
	    ['5'] = "DIGIT FIVE",
	    ['4'] = "DIGIT FOUR",
	    ['9'] = "DIGIT NINE",
	    ['1'] = "DIGIT ONE",
	    ['7'] = "DIGIT SEVEN",
	    ['6'] = "DIGIT SIX",
	    ['3'] = "DIGIT THREE",
	    ['2'] = "DIGIT TWO",
	    ['0'] = "DIGIT ZERO",
	    ['$'] = "DOLLAR SIGN",
	    ['='] = "EQUALS SIGN",
	    ['!'] = "EXCLAMATION MARK",
	    ['.'] = "FULL STOP",
	    ['`'] = "GRAVE ACCENT",
	    ['>'] = "GREATER-THAN SIGN",
	    ['-'] = "HYPHEN-MINUS",
	    ['A'] = "LATIN CAPITAL LETTER A",
	    ['B'] = "LATIN CAPITAL LETTER B",
	    ['C'] = "LATIN CAPITAL LETTER C",
	    ['D'] = "LATIN CAPITAL LETTER D",
	    ['E'] = "LATIN CAPITAL LETTER E",
	    ['F'] = "LATIN CAPITAL LETTER F",
	    ['G'] = "LATIN CAPITAL LETTER G",
	    ['H'] = "LATIN CAPITAL LETTER H",
	    ['I'] = "LATIN CAPITAL LETTER I",
	    ['J'] = "LATIN CAPITAL LETTER J",
	    ['K'] = "LATIN CAPITAL LETTER K",
	    ['L'] = "LATIN CAPITAL LETTER L",
	    ['M'] = "LATIN CAPITAL LETTER M",
	    ['N'] = "LATIN CAPITAL LETTER N",
	    ['O'] = "LATIN CAPITAL LETTER O",
	    ['P'] = "LATIN CAPITAL LETTER P",
	    ['Q'] = "LATIN CAPITAL LETTER Q",
	    ['R'] = "LATIN CAPITAL LETTER R",
	    ['S'] = "LATIN CAPITAL LETTER S",
	    ['T'] = "LATIN CAPITAL LETTER T",
	    ['U'] = "LATIN CAPITAL LETTER U",
	    ['V'] = "LATIN CAPITAL LETTER V",
	    ['W'] = "LATIN CAPITAL LETTER W",
	    ['X'] = "LATIN CAPITAL LETTER X",
	    ['Y'] = "LATIN CAPITAL LETTER Y",
	    ['Z'] = "LATIN CAPITAL LETTER Z",
	    ['a'] = "LATIN SMALL LETTER A",
	    ['b'] = "LATIN SMALL LETTER B",
	    ['c'] = "LATIN SMALL LETTER C",
	    ['d'] = "LATIN SMALL LETTER D",
	    ['e'] = "LATIN SMALL LETTER E",
	    ['f'] = "LATIN SMALL LETTER F",
	    ['g'] = "LATIN SMALL LETTER G",
	    ['h'] = "LATIN SMALL LETTER H",
	    ['i'] = "LATIN SMALL LETTER I",
	    ['j'] = "LATIN SMALL LETTER J",
	    ['k'] = "LATIN SMALL LETTER K",
	    ['l'] = "LATIN SMALL LETTER L",
	    ['m'] = "LATIN SMALL LETTER M",
	    ['n'] = "LATIN SMALL LETTER N",
	    ['o'] = "LATIN SMALL LETTER O",
	    ['p'] = "LATIN SMALL LETTER P",
	    ['q'] = "LATIN SMALL LETTER Q",
	    ['r'] = "LATIN SMALL LETTER R",
	    ['s'] = "LATIN SMALL LETTER S",
	    ['t'] = "LATIN SMALL LETTER T",
	    ['u'] = "LATIN SMALL LETTER U",
	    ['v'] = "LATIN SMALL LETTER V",
	    ['w'] = "LATIN SMALL LETTER W",
	    ['x'] = "LATIN SMALL LETTER X",
	    ['y'] = "LATIN SMALL LETTER Y",
	    ['z'] = "LATIN SMALL LETTER Z",
	    ['{'] = "LEFT CURLY BRACKET",
	    ['('] = "LEFT PARENTHESIS",
	    ['['] = "LEFT SQUARE BRACKET",
	    ['<'] = "LESS-THAN SIGN",
	    ['_'] = "LOW LINE",
	    ['#'] = "NUMBER SIGN",
	    ['%'] = "PERCENT SIGN",
	    ['+'] = "PLUS SIGN",
	    ['?'] = "QUESTION MARK",
	    ['\"'] = "QUOTATION MARK",
	    ['\\'] = "REVERSE SOLIDUS",
	    ['}'] = "RIGHT CURLY BRACKET",
	    [')'] = "RIGHT PARENTHESIS",
	    [']'] = "RIGHT SQUARE BRACKET",
	    [';'] = "SEMICOLON",
	    ['/'] = "SOLIDUS",
	    [' '] = "SPACE",
	    ['~'] = "TILDE",
	    ['|'] = "VERTICAL LINE",
	};

	return lut[c & 0xff];
}

int
main()
{
	int i;

	for (i = 32; i < 127; i++)
		printf("%c: %s\n", i, lookup(i));

	return 0;
}
