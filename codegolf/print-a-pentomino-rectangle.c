/*

Write a program or function that takes no input but prints or returns a constant textual depiction of a rectangle made of the 12 distinct pentominoes:

https://i.sstatic.net/BRVgy.png

The rectangle may have any dimensions and be in any orientation, but all 12 pentominoes must be used exactly once, so it will have area 60.
Each different pentomino must be composed of a different printable ASCII character (you don't need to use the letters from above).

For example, if you chose to output this 20×3 pentomino rectangle solution:

https://i.sstatic.net/Ga6tF.png

Your program's output might look something like this:

00.@@@ccccF111//=---
0...@@c))FFF1//8===-
00.ttttt)))F1/8888=-
Alternatively, you might find it easier to golf this 6×10 solution:

000111
203331
203431
22 444
2   46
57 666
57769!
58779!
58899!
5889!!
Any rectangle solution will do, your program only needs to print one. (A trailing newline in the output is fine.)

This great website has loads of solutions for various rectangle dimensions and it's probably worth browsing them to make sure your solution is as short as possible. This is code-golf, the shortest answer in bytes wins.
https://puzzler.sourceforge.net/docs/pentominoes.html

*/

#include <stdio.h>

void
output()
{
	puts("00.@@@ccccF111//=---");
	puts("0...@@c))FFF1//8===-");
	puts("00.ttttt)))F1/8888=-");
}

int
main()
{
	output();
	return 0;
}
