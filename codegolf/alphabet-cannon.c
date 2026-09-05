/*

A cannonball is fired so that in the first eyeblink of its flight it ascends by N treetops, during the second eyeblink by N-1 treetops, etc until it reaches the highest point of its trajectory. Then it starts falling by 1, 2, etc treetops per eyeblink until it hits the ground. At the same time the cannonball is moving horizontally with a constant velocity of 1 treetop/eyeblink.

Your task is to draw the trajectory with consecutive letters from the English alphabet. If you run out of letters, start again from 'A'. Write a function or a program. The input is an integer N (1≤N≤15). The output can be a character matrix in any reasonable form, for instance a newline-separated string or a list of strings. Letters can be all lowercase or all uppercase. Extra leading and trailing spaces are allowed. Standard loopholes are forbidden. Shorter code is better.

in:
5
out:
    OP
   N  Q
   M  R
  L    S
  K    T
  J    U
 I      V
 H      W
 G      X
 F      Y
E        Z
D        A
C        B
B        C
A        D

in:
1
out:
AB

*/

#include <stdio.h>

void
repeat(int c, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%c", c);
}

void
cannon(int n)
{
	int i, j, l, r;

	printf("n=%d\n", n);
	if (n < 1)
		return;

	l = n * (n + 1) / 2;
	r = l;
	i = 1;
	j = 0;
	n += 1;
	while (l > 0) {
		repeat(' ', n - i - 1);
		printf("%c", 'A' + ((l - 1) % 26));
		repeat(' ', (2 * i) - 2);
		printf("%c", 'A' + (r % 26));
		printf("\n");

		l -= 1;
		r += 1;
		j -= 1;
		if (j <= 0) {
			i += 1;
			j = i;
		}
	}
	printf("\n");
}

int
main()
{
	cannon(5);
	cannon(1);
	return 0;
}
