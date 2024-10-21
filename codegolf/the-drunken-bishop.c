/*

In public-key cryptography, a public key fingerprint is a short sequence of bytes used to identify a longer public key.

In SSH in particular they can be used to verify that a server is in fact the server I'm expecting to communicate with and I'm not targeted by a man-in-the-middle attack.

They are usually represented as a string of hexadecimal digits, so it can be rather boring and tedious to compare it with the fingerprint I would expect:

37:e4:6a:2d:48:38:1a:0a:f3:72:6d:d9:17:6b:bd:5e
To make it a little easier, OpenSSH has introduced a method to visualize fingerprints as ASCII art, that would look like the following:

+-----------------+
|                 |
|                 |
|          .      |
|     .   o       |
|o . o . S +      |
|.+ + = . B .     |
|o + + o B o E    |
| o .   + . o     |
|         .o      |
+-----------------+
With this, I could try to remember the rough shape of the ASCII art and would then (theoretically) recognize it when the fingerprint of the server changed and the image looks different.

How it works
Taken from Dirk Loss, Tobias Limmer, Alexander von Gernler. 2009. The drunken bishop: An analysis of the OpenSSH fingerprint visualization algorithm.

The grid has a width of 17 characters and a height of 9 characters. The "bishop" starts at row 4/column 8 (the center). Each position can be denoted as [x,y], i.e. [8,4] for the starting position of the bishop.

            1111111
  01234567890123456
 +-----------------+
0|                 |
1|                 |
2|                 |
3|                 |
4|        S        |
5|                 |
6|                 |
7|                 |
8|                 |
 +-----------------+
The bishop uses the fingerprint to move around. It reads it byte-wise from left to right and from the least significant bit to the most significant bit:

Fingerprint      37      :       e4      :       6a      :  ...  :       5e
Bits        00 11 01 11  :  11 10 01 00  :  01 10 10 10  :  ...  :  01 01 11 10
             |  |  |  |      |  |  |  |      |  |  |  |              |  |  |  |
Step         4  3  2  1      8  7  6  5     12 11 10  9             64 63 62 61
The bishop will move by the following plan:

Bits   Direction
-----------------
00     Up/Left
01     Up/Right
10     Down/Left
11     Down/Right
Special cases:

If the bishop is in a corner and would move into the corner again, he doesn't move at all. i.e: The bishop is at [0,0] and his next step would be 00. He remains at [0,0]
If the bishop is in a corner or at a wall and would move into one of the walls, he moves horizontally or vertically only. i.e: The bishop is at [0,5] and his next step would be 01. He cannot go left, so he just moves up, to [0,4].
Each position holds a value of how often the bishop has visited this field:

Value      | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15| 16|
Character  |   | . | o | + | = | * | B | O | X | @ | % | & | # | / | ^ | S | E |
The values 15 (S) and 16 (E) are special in that they mark the start and end position of the bishop respectively and overwrite the real value of the respecting position.

Goal
Create a program, that takes an alphanumeric fingerprint as input and produces its ASCII art representation as shown in the examples.

Examples
Input:
16:27:ac:a5:76:28:2d:36:63:1b:56:4d:eb:df:a6:48

Output:
+-----------------+
|        .        |
|       + .       |
|      . B .      |
|     o * +       |
|    X * S        |
|   + O o . .     |
|    .   E . o    |
|       . . o     |
|        . .      |
+-----------------+

Input:
b6:dd:b7:1f:bc:25:31:d3:12:f4:92:1c:0b:93:5f:4b

Output:
+-----------------+
|            o.o  |
|            .= E.|
|             .B.o|
|              .= |
|        S     = .|
|       . o .  .= |
|        . . . oo.|
|             . o+|
|              .o.|
+-----------------+

Input:
05:1e:1e:c1:ac:b9:d1:1c:6a:60:ce:0f:77:6c:78:47

Output:
+-----------------+
|       o=.       |
|    o  o++E      |
|   + . Ooo.      |
|    + O B..      |
|     = *S.       |
|      o          |
|                 |
|                 |
|                 |
+-----------------+

Rules
This is code-golf. The code in the fewest bytes wins.
You can not use an existing library that produces the image.
Use whichever language you prefer!
Your submission has to be a complete program

*/

#include <stdio.h>
#include <string.h>

typedef char Grid[9][17];

int
clamp(int x, int a, int b)
{
	if (x < a)
		x = a;
	else if (x > b)
		x = b;
	return x;
}

void
reset(Grid g)
{
	memset(g, 0, 9 * 17);
	g[4][8] = 15;
}

void
show(Grid g)
{
	static const char sym[] = " .o+=*BOX@%&#/^SE";
	int c, x, y;

	printf("+-----------------+\n");
	for (y = 0; y < 9; y++) {
		printf("|");
		for (x = 0; x < 17; x++) {
			c = g[y][x];
			printf("%c", sym[c]);
		}
		printf("|\n");
	}
	printf("+-----------------+\n\n");
}

void
move(const char *s, Grid g)
{
	int x, y, dx, dy;
	unsigned b;
	size_t i, j;

	x = 8;
	y = 4;
	for (i = 0; s[i] && s[i + 1]; i += 3) {
		if (sscanf(s + i, "%02x", &b) != 1)
			break;

		for (j = 0; j < 4; j++) {
			dx = (b & 1) ? 1 : -1;
			dy = (b & 2) ? 1 : -1;
			b >>= 2;

			x = clamp(x + dx, 0, 16);
			y = clamp(y + dy, 0, 8);
			if (g[y][x] < 14)
				g[y][x]++;
		}

		if (s[i + 2] != ':')
			break;
	}
	g[y][x] = 16;
}

void
fingerprint(const char *s)
{
	Grid g;

	printf("%s\n", s);
	reset(g);
	move(s, g);
	show(g);
}

int
main(void)
{
	fingerprint("37:e4:6a:2d:48:38:1a:0a:f3:72:6d:d9:17:6b:bd:5e");
	fingerprint("16:27:ac:a5:76:28:2d:36:63:1b:56:4d:eb:df:a6:48");
	fingerprint("b6:dd:b7:1f:bc:25:31:d3:12:f4:92:1c:0b:93:5f:4b");
	fingerprint("05:1e:1e:c1:ac:b9:d1:1c:6a:60:ce:0f:77:6c:78:47");

	return 0;
}
