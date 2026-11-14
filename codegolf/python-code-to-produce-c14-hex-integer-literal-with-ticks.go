/*

tl;dr? See bottom for The Competition

Integer literals
While programming, the 64-bit hexadecimal literal 0x123456789abcdefL is difficult to gauge the size of. I find myself mentally grouping digits from the right by fours to see that it's 15 digits' worth.

Python PEP 515 allows you to express the above literal, inside code, as 0x123_4567_89ab_cdefL. If you prefer binary, then it's even more invaluable: 0b1_0010_0011_0100_0101_0110_0111_1000_1001_1010_1011_1100_1101_1110_1111L

String representations
Python can also convert an integer into strings with spacing characters, as follows:

'{:#_b}'.format(81985529216486895L)
'{:#_x}'.format(81985529216486895L)
'{:,}'.format(81985529216486895L)
The first two produce what's shown above (although without the L suffix), while the last will produce

"81,985,529,216,486,895"
Although with PEP 515, they would be better expressed as:

'{:#_b}'.format(81_985_529_216_486_895L)
'{:#_x}'.format(81_985_529_216_486_895L)
'{:,}'.format(81_985_529_216_486_895L)
Note, though, the following:

'_' is only legal for binary and hexadecimal strings - and Python will insert them every four characters (from the right);
',' is only legal for decimal strings - and Python will insert them every three characters (from the right);
No other separator characters are allowed.
Enough with the Python syntax lesson; on to C++!
C++14 also allows separators inside an integer literal to allow grouping, much like the above. Only (of course) it's a different character: the tick (single quote '). So the above literals would be:

0b1'0010'0011'0100'0101'0110'0111'1000'1001'1010'1011'1100'1101'1110'1111uL
0x123'4567'89ab'cdefuL
81'985'529'216'486'895uL
Python is often used to machine-generate C/C++ code, because it's so easy to do! But there's no native Python way to generate these new 'tick'-based identifiers - .format() can only use _. So, here's some code that I wrote to do it:

# Hex function with tick marks
def HexTicks(num) :
  # Convert to hex (without leading 0x - yet)
  s = '{:x}'.format(num)
  # Insert tick marks
  for i in range(len(s)-4, 0, -4) :
    s = s[:i] + "'" + s[i:]
  # Return the result
  return "0x" + s + "uLL"
The Competition
Sorry @ASCII-only !

Write a Python 2.7.3 expression or lambda, smaller than the above function (not including whitespace or comments), that:

Takes any non-negative integer;
Produces the correct hexadecimal string for that integer;
With a leading 0x and trailing uLL;
No leading zeroes as part of the hex number;
With tick marks (') every four digits, counting backwards from the right;
No tick mark straight after the 0x.
ILLEGAL
0x0uLL       # If integer was anything other than zero (2.)
12'3456      # No 0x or uLL (3.)
0x0'1234uLL  # Leading zero (4.)
0x12'345uLL  # Not grouped by four (5.)
0x'1234uLL   # Tick mark before hex number (6.)
Bonuses
A. Can be easily modified to produce capital hex letters - but not the 0x or uLL parts;

Note that .format() allows '{:_X}' to capitalise the hex characters - but '{:#_X}' will capitalise the 0X too

B. An extra digits parameter that will add leading zeros to that number of digits (not resultant characters; just hex digits) - unless it's already got that many.

For example: HexTick(0x1234,6) would produce "0x00'1234uLL"

*/

package main

import "fmt"

func main() {
	fmt.Println(hexticks(0))
	fmt.Println(hexticks(123456))
	fmt.Println(hexticks(0x12345))
	fmt.Println(hexticks(0xffba))
}

func hexticks(n uint64) string {
	s := fmt.Sprintf("%x", n)
	for i := len(s) - 4; i > 0; i -= 4 {
		s = s[:i] + "'" + s[i:]
	}
	return "0x" + s + "ULL"
}
