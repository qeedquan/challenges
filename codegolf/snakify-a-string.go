/*

A snakified string looks like this:

T AnE eOf ifi ing
h s x l A k e r
isI amp Sna dSt
Your Task
Take a string s and a size n, then output the snakified string. The inputs ThisIsAnExampleOfaSnakifiedString and 3 would produce the example above.

Specifications
s will only contain ASCII characters between code points 33 and 126 inclusive (no spaces or newlines).
s will be between 1 and 100 characters long.
n is an integer representing the size of each output string segment. Each line of characters (up/down or left/right) that make up the curves in the "snake" is n characters long. See the test cases for examples.
n will be between 3 and 10 inclusive.
The output string always starts pointing downwards.
Trailing spaces on each line are allowed.
Trailing newlines at the end of the output are also allowed.
Leading spaces are not allowed.
code-golf means shortest code in bytes wins.
Test Cases
a 3

a

----------

Hello,World! 3

H Wor
e , l
llo d!

----------

ProgrammingPuzzlesAndCodeGolf 4

P  ngPu  Code
r  i  z  d  G
o  m  z  n  o
gram  lesA  lf

----------

IHopeYourProgramWorksForInputStringsWhichAre100CharactersLongBecauseThisTestCaseWillFailIfItDoesNot. 5

I   gramW   tStri   100Ch   gBeca   CaseW   DoesN
H   o   o   u   n   e   a   n   u   t   i   t   o
o   r   r   p   g   r   r   o   s   s   l   I   t
p   P   k   n   s   A   a   L   e   e   l   f   .
eYour   sForI   Which   cters   ThisT   FailI

----------

!"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~ 10

!        <=>?@ABCDE        `abcdefghi
"        ;        F        _        j
#        :        G        ^        k
$        9        H        ]        l
%        8        I        \        m
&        7        J        [        n
'        6        K        Z        o        ~
(        5        L        Y        p        }
)        4        M        X        q        |
*+,-./0123        NOPQRSTUVW        rstuvwxyz{

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(snakify("a", 3))
	fmt.Println(snakify("Hello,World!", 3))
	fmt.Println(snakify("ProgrammingPuzzlesAndCodeGolf", 4))
	fmt.Println(snakify("IHopeYourProgramWorksForInputStringsWhichAre100CharactersLongBecauseThisTestCaseWillFailIfItDoesNot.", 5))
	fmt.Println(snakify("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~", 10))
}

// ported from @Neil solution
func snakify(s string, w int) string {
	r := make([][]byte, w)
	for i := range r {
		r[i] = make([]byte, len(s))
	}

	x, y := 0, 0
	for i := 0; i < len(s); i++ {
		r[x][y] = s[i]
		switch i / (w - 1) & 3 {
		case 0:
			x++
		case 1:
			y++
		case 2:
			x--
		case 3:
			y++
		}
	}

	t := []string{}
	for i := range r {
		for j := range r[i] {
			if r[i][j] == 0 {
				r[i][j] = ' '
			}
		}
		t = append(t, string(r[i]))
	}
	return strings.Join(t, "\n") + "\n"
}
