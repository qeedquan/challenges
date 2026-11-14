/*

Draw the parabolic trajectory of a thrown ball.

The input is the ball's initial upward velocity, a positive integer v. Every second, the ball moves 1 space right and v spaces vertically, and then v decreases by 1 to due to gravity. So, the upward velocity eventually steps down from v to 0 and down to -v, finally falling back down to its initial height.

The ball's positions trace a parabola. At horizontal position x, its height is y=x*(2*v+1-x)/2, with (0,0) the ball's initial position at the bottom left.

Output ASCII art of the ball's trajectory with O's on the coordinates it ever occupies. The output should be a single multi-line piece of text, not an animation of the path over time.

The output should have no leading newlines and at most one trailing newline. The bottom line should be flush with the left edge of the screen, i.e. have no extra leading spaces. Trailing spaces are OK. You may assume the output line width fits in the output terminal.

v=1

 OO
O  O
v=2

  OO
 O  O

O    O
v=3

   OO
  O  O

 O    O


O      O
v=4

    OO
   O  O

  O    O


 O      O



O        O
v=10

          OO
         O  O

        O    O


       O      O



      O        O




     O          O





    O            O






   O              O







  O                O








 O                  O









O                    O

Related: Bouncing ball simulation

*/

#include <stdio.h>

void
arc(int v)
{
	int y, n;

	printf("V=%d\n", v);
	for (y = 0; y <= v;) {
		printf("%*c%*c", v - y + 1, 'o', (y * 2) + 1, 'o');
		y++;
		for (n = y; v + 1 - n > 0 && n > 0; n--)
			printf("\n");
	}
	printf("\n\n");
}

int
main(void)
{
	arc(1);
	arc(2);
	arc(3);
	arc(4);
	arc(10);

	return 0;
}
