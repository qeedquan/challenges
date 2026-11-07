/*

Task description:

Write a program as short as possible to draw a radial gradient in ASCII art. The size of the output grid is predefined. The center point and the characters to be used for the gradient are provided as input to the program.

The gradient will be 70×25 character cells in size with the following specifications

The upper-left corner of the grid has the coordinates (0, 0).
The gradient, consisting of the characters provided, is mapped into 35 length units. A length unit is one character tall and two characters wide (since monospaced fonts usually have characters twice as high as they are wide).
Within those 35 LU the current distance from the center point is multiplied by number of gradient characters/35 to get the index of the character to draw at that point. Fractional numbers for the index are rounded towards zero here. The length units are to be left as a real number. (Of course, if the results are the same, the implementation doesn't matter.)
Beyond those 35 LU only the last gradient character appears. However, since the last gradient »band« already starts within the 35 LU, the last character starts appearing short of 35 LU already.
Input:

The input is given on standard input and consists of three lines, each terminated by a line break:

The x coordinate of the gradient center point
The y coordinate of the gradient center point
The characters to use for drawing the gradient. Those may include spaces.
Output:

Output is the gradient as defined by the rules above on standard output. The standard error stream is ignored. Each line of the gradient is terminated by a line break. No other characters except those defined by the input may occur.

Sample input 1:

58
14
 .:;+=xX$&
Sample output 1:

&&$$$$$$$$XXXXXXXXxxxxxxxxx===========++++++++++++++++++++++++++++++++
&$$$$$$$$XXXXXXXXxxxxxxxxx=========+++++++++++++;;;;;;;;;;;;;;;;;;;;;+
$$$$$$$$XXXXXXXXxxxxxxxx=========+++++++++++;;;;;;;;;;;;;;;;;;;;;;;;;;
$$$$$$$XXXXXXXXxxxxxxxx========++++++++++;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
$$$$$$XXXXXXXXxxxxxxxx========+++++++++;;;;;;;;;;;;;:::::::::::::;;;;;
$$$$$XXXXXXXXxxxxxxxx=======+++++++++;;;;;;;;;;;:::::::::::::::::::::;
$$$$$XXXXXXXxxxxxxxx=======+++++++++;;;;;;;;;:::::::::::::::::::::::::
$$$$XXXXXXXXxxxxxxx=======++++++++;;;;;;;;;:::::::::::::::::::::::::::
$$$$XXXXXXXxxxxxxx========+++++++;;;;;;;;::::::::::...............::::
$$$XXXXXXXXxxxxxxx=======+++++++;;;;;;;;:::::::::...................::
$$$XXXXXXXxxxxxxx=======++++++++;;;;;;;::::::::.......................
$$$XXXXXXXxxxxxxx=======+++++++;;;;;;;::::::::.........       ........
$$$XXXXXXXxxxxxxx=======+++++++;;;;;;;:::::::........           ......
$$$XXXXXXXxxxxxxx=======+++++++;;;;;;;:::::::.......             .....
$$$XXXXXXXxxxxxxx=======+++++++;;;;;;;:::::::.......             .....
$$$XXXXXXXxxxxxxx=======+++++++;;;;;;;:::::::.......             .....
$$$XXXXXXXxxxxxxx=======+++++++;;;;;;;:::::::........           ......
$$$XXXXXXXxxxxxxx=======+++++++;;;;;;;::::::::.........       ........
$$$XXXXXXXxxxxxxx=======++++++++;;;;;;;::::::::.......................
$$$XXXXXXXXxxxxxxx=======+++++++;;;;;;;;:::::::::...................::
$$$$XXXXXXXxxxxxxx========+++++++;;;;;;;;::::::::::...............::::
$$$$XXXXXXXXxxxxxxx=======++++++++;;;;;;;;;:::::::::::::::::::::::::::
$$$$$XXXXXXXxxxxxxxx=======+++++++++;;;;;;;;;:::::::::::::::::::::::::
$$$$$XXXXXXXXxxxxxxxx=======+++++++++;;;;;;;;;;;:::::::::::::::::::::;
$$$$$$XXXXXXXXxxxxxxxx========+++++++++;;;;;;;;;;;;;:::::::::::::;;;;;
Sample input 2:

0
0
X.X.X.X
Sample output 2:

XXXXXXXXXX..........XXXXXXXXXX..........XXXXXXXXXX..........XXXXXXXXXX
XXXXXXXXXX..........XXXXXXXXXX..........XXXXXXXXXX..........XXXXXXXXXX
XXXXXXXXXX..........XXXXXXXXXX..........XXXXXXXXXX..........XXXXXXXXXX
XXXXXXXX............XXXXXXXXXX..........XXXXXXXXXX..........XXXXXXXXXX
XXXXXX.............XXXXXXXXXX...........XXXXXXXXXX..........XXXXXXXXXX
..................XXXXXXXXXXX..........XXXXXXXXXX...........XXXXXXXXXX
................XXXXXXXXXXXX...........XXXXXXXXXX..........XXXXXXXXXXX
...............XXXXXXXXXXXX...........XXXXXXXXXX...........XXXXXXXXXXX
............XXXXXXXXXXXXXX...........XXXXXXXXXXX..........XXXXXXXXXXXX
.........XXXXXXXXXXXXXXX............XXXXXXXXXXX...........XXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXX............XXXXXXXXXXX...........XXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXX.............XXXXXXXXXXX...........XXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXX..............XXXXXXXXXXXX...........XXXXXXXXXXXXXXX
XXXXXXXXXXXXXXX................XXXXXXXXXXXX............XXXXXXXXXXXXXXX
XXXXXXXXXXX..................XXXXXXXXXXXXX............XXXXXXXXXXXXXXXX
...........................XXXXXXXXXXXXX............XXXXXXXXXXXXXXXXXX
........................XXXXXXXXXXXXXXX............XXXXXXXXXXXXXXXXXXX
......................XXXXXXXXXXXXXXX.............XXXXXXXXXXXXXXXXXXXX
..................XXXXXXXXXXXXXXXXX.............XXXXXXXXXXXXXXXXXXXXXX
.............XXXXXXXXXXXXXXXXXXXX..............XXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX...............XXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXXXXXX...............XXXXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXX.................XXXXXXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXX...................XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXX......................XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
Sample input 3:

70
25
.:+#
Sample output 3:

######################################################++++++++++++++++
#################################################+++++++++++++++++++++
#############################################+++++++++++++++++++++++++
##########################################++++++++++++++++++++++++++++
#######################################+++++++++++++++++++++++++++++++
####################################++++++++++++++++++++++++++++++++++
##################################++++++++++++++++++++++++++++++++++++
################################++++++++++++++++++++++++++++++++++++++
##############################++++++++++++++++++++++++++++++++::::::::
#############################+++++++++++++++++++++++++++::::::::::::::
###########################+++++++++++++++++++++++++::::::::::::::::::
##########################++++++++++++++++++++++++::::::::::::::::::::
#########################++++++++++++++++++++++:::::::::::::::::::::::
########################+++++++++++++++++++++:::::::::::::::::::::::::
#######################++++++++++++++++++++:::::::::::::::::::::::::::
######################++++++++++++++++++++::::::::::::::::::::::::::::
#####################+++++++++++++++++++::::::::::::::::::::::::::::::
####################+++++++++++++++++++::::::::::::::::::::::::.......
####################++++++++++++++++++::::::::::::::::::::::..........
###################+++++++++++++++++++::::::::::::::::::::............
###################++++++++++++++++++:::::::::::::::::::..............
###################+++++++++++++++++:::::::::::::::::::...............
##################++++++++++++++++++::::::::::::::::::................
##################++++++++++++++++++:::::::::::::::::.................
##################++++++++++++++++++:::::::::::::::::.................
Sample input 4

59
1
 abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789<>|,.-#+!$%&/()=?*'_:;
Sample output 4

!+#-,|><87654210ZYWVUTRQPONLKJIHFEDCBzyxwutsrqonmlkjhgfedcbbbcdefghjkl
!+#-,|><87654210ZYWVUTRQPONLKJIHFEDCAzyxwutsrqonmljihgfdcba abcdfghijl
!+#-,|><87654210ZYWVUTRQPONLKJIHFEDCBzyxwutsrqonmlkjhgfedcbbbcdefghjkl
!+#-,|><97654310ZYXVUTSQPONMKJIHGEDCBAyxwvutrqponmkjihgffeedeeffghijkm
$+#-.|><98654320ZYXWUTSRQONMLKIHGFEDBAzyxwutsrqponmlkjihhggggghhijklmn
$!#-.,|<987643210YXWVUSRQPONLKJIHGEDCBAzywvutsrqponmllkjjjiiijjjkllmno
$!+#.,|><87654210ZYXVUTSRQONMLKJHGFEDCBAzywvutsrrqponnmmlllllllmmnnopq
%!+#-.|><987543210YXWVUTRQPONMLJIHGFEDCBAzyxwvutsrrqppooonnnnnoooppqrr
%$!+-.,|><87654310ZYXWVTSRQPONMLJIHGFEDCBAzyxxwvuttssrrqqqqqqqqqrrsstt
&%!+#-.,><987643210ZYXVUTSRQPONMLKJIHGFEDCBAzyyxwvvuutttssssssstttuuvv
&%$!+#.,|><986543210ZYWVUTSRQPONMLKJIHGFEDDCBAzzyyxwwwvvvuuuuuvvvwwwxy
/&%$!#-.,|><976543210ZYXVUTSRQPONMLKKJIHGFEEDCBBAAzzyyyxxxxxxxxxyyyzzA
(/&%!+#-.,|><876543210ZYXWVUTSRQPONMLKJJIHGGFEEDCCBBBAAAzzzzzzzAAABBBC
)(/%$!+#-.,|><876543210ZYXWVUTSRQPPONMLKKJIIHGGFFEEDDDCCCCCCCCCCCDDDEE
=)(&%$!+#-.,|><986543210ZYYXWVUTSRQPPONMMLKKJIIHHGGGFFFEEEEEEEEEFFFGGG
?=)(&%$!+#-.,|><9876543210ZYXWVVUTSRRQPOONMMLLKJJJIIIHHHHHHHHHHHHHIIIJ
*?=)(/%$!+#-.,|><98765432210ZYXWWVUTSSRQQPOONNMMLLLKKKJJJJJJJJJJJKKKLL
'*?=)(/&%$!+#-.,|><98765432110ZYXXWVUUTSSRRQPPOOONNNMMMMMLLLLLMMMMMNNN
_'*?=)(/&%$!+#-.,|><988765432210ZYYXWWVUUTTSSRRQQQPPPOOOOOOOOOOOOOPPPQ
:_'*?=)(/&%$!+##-.,|><9877654332100ZYYXXWVVUUTTTSSSRRRRQQQQQQQQQRRRRSS
;;:_'*?=)(/&%$!+#-.,,|><98876554322100ZZYYXXWWVVVUUUTTTTTTTTTTTTTTTUUU
;;;:_'*?=)(/&&%$!+#-.,,|><9987665443321100ZZYYYXXXWWWWVVVVVVVVVVVWWWWX
;;;;;:_'*?=)(/&%$$!+#-..,|>><9887665544322211000ZZZYYYYYYYYYYYYYYYYYZZ
;;;;;;:_'*??=)(/&%%$!+##-.,,|><<99877665544333222111100000000000001111
;;;;;;;;:_'*?==)(/&&%$!++#--.,,|>><<9887766655544433333322222223333334

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void
gradients(int xc, int yc, const char *s)
{
	int x, y, w, h;
	int l, b, i;
	double dx, dy;

	printf("(%d, %d): \"%s\"\n", xc, yc, s);
	w = 70;
	h = 25;
	b = 35;
	l = strlen(s);
	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++) {
			dx = abs(xc - x) / 2.0;
			dy = abs(yc - y);
			i = fmin(l * hypot(dx, dy) / b, l - 1);
			putchar(s[i]);
		}
		putchar('\n');
	}
	putchar('\n');
}

int
main()
{
	gradients(58, 14, " .:;+=xX$&");
	gradients(0, 0, "X.X.X.X");
	gradients(70, 25, ".:+#");
	gradients(59, 1, " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789<>|,.-#+!$%&/()=?*'_:;");

	return 0;
}
