/*

Intro
In most fonts all of the uppercase alphabet characters besides BDO have single lines approximately touching some of the four corners of the character's bounding rectangle: ACEFGHIJKLMNPQRSTUVWXYZ.

For example, the two legs of an A "touch" the bottom left and bottom right corners of the character. Likewise, C touches its top and bottom right corners (it is a bit curved but it's close enough). L only touches it's top left and bottom right corners with single lines. The bottom left corner of L is a vertex, not the end of a single line.

Here is a table of what characters touch which corners according to the Stack Exchange font I (and hopefully you) see. 1 is for upper left, 2 is for upper right, 3 lower left, 4 lower right.

A: 3 4
C: 2 4
E: 2 4
F: 2 3
G: 2
H: 1 2 3 4
I: 1 2 3 4
J: 1 3
K: 1 2 3 4
L: 1 4
M: 3 4
N: 2 3
P: 3
Q: 4
R: 3 4
S: 2 3
T: 1 2
U: 1 2
V: 1 2
W: 1 2
X: 1 2 3 4
Y: 1 2
Z: 1 4
Setup
Pretend like these corner touching lines extend in the direction of the corner that they touch so that arrangements of these characters on a grid can be "connected".

For example, all the characters in

 A
C X
are connected because the bottom left of A and top right of C connect, and the bottom right of A and top left of X connect.

However,

CAX
has no connections because connections only occur diagonally from one character to the next.

Challenge
Write the shortest program possible (in bytes) that outputs all of the characters in ACEFGHIJKLMNPQRSTUVWXYZ in one big fully connected tree, according to the rules above. Each character must appear exactly once. Use spaces for empty space.

Example
Everything in this 23-letter tree can be reached from anything else via the diagonal connections defined above:

  Q
 A J   R
C U   S Y
 I M N
E H X
 F L T
G   Z K P
     V W
Notes
You may hardcode your solution.
Your output should only contain ACEFGHIJKLMNPQRSTUVWXYZ, spaces, and newlines. BDO will not be used.
Leading/trailing spaces are fine as long as all the connections are properly positioned.
The output grid should not be larger than 30 by 30 characters (including newlines and spaces).
Only corner connections are considered. The bottom of Y does not connect to anything. You must use the corner connections from the table above.
Not all connectable corners need to connect to something. Connectable and non-connectable corners may border each other.
Output to stdout. There is no input.
Including a connectivity graph made with slashes as Peter Taylor has done is a helpful touch but not required.

Update:
githubhagocyte has made an alphabet tree validity checker over on Github.
https://github.com/trichoplax/Alphabet-tree-checker/blob/master/alphabet-tree-checker.py

*/

#include <stdio.h>

// ported from @grc solution
void
tree()
{
	static const char sym[] = "  MQRCNAF\n XZHLKSIP\nGJWVUYET";
	size_t i;

	for (i = 0; sym[i]; i++) {
		printf("%c", sym[i]);
		if (sym[i + 1])
			printf(" ");
	}
	printf("\n");
}

int
main()
{
	tree();
	return 0;
}
