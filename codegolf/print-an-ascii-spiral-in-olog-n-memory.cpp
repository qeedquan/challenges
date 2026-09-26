/*

You may write a program or function that receives an odd, positive integer n, where n >= 3, as either a function argument, command line arguments, or on STDIN (or equivalent for your system), and prints to STDOUT (or system equivalent) an ASCII spiral that spins inward clockwise where the top edge is exactly n characters long. The first right edge should be n+1 characters long, obviously. For instance,

Input:
11

Output:
***********
          *
********* *
*       * *
* ***** * *
* *   * * *
* * * * * *
* * *** * *
* *     * *
* ******* *
*         *
***********
The catches:
Your program must use no more than O(log n) memory.
Your program may only print the characters * (ASCII 42), (ASCII 32), <CR> (ASCII 13) and <LF> (ASCII 10).
Your program must print the string, not return it from the function.
The Big-O restriction is only on memory, there are no restrictions on runtime.
A trailing newline is optional.
If your language does not support large integer types, you do not have to support higher than what it does support, but you may not use this as a trick to say "oh, well, I don't have to support above X so I can just make a huge array the maximum size every time"
Standard loopholes are banned, as usual.

*/

#include <cstdio>

/*

@Reto Koradi

The key observation is that the pattern is almost a series of concentric squares. With a couple of slight wrinkles:

The y-size is one larger than the x-size. This is corrected by subtracting 1 from y for the lower half, which essentially repeats the middle row.
To turn the rectangles into a spiral, the pixels along the y = x + 1 diagonal need to be inverted up to the middle of the shape.
For the rest, the code is simply looping over all positions, calculating the Chebyshev distance from the center for each position, and emitting one of the two characters depending on the distance being even or odd. And emitting a newline for the last position of each line.

Since there are only a few scalar variables, and characters are emitted one by one, memory usage is obviously constant.

*/

void spiral(int n)
{
	int m, p, x, y, d;

	printf("n=%d\n", n);
	if (!(n & 1))
		return;

	m = n / 2;
	n += 1;
	for (p = 0; p < n * n;)
	{
		x = (p % n) - m;
		y = (p / n) - m;
		d = 0;

		p += 1;
		if (y == x + 1 && x < 0)
			d = 1;
		if (y > 0)
			y -= 1;
		if (x * x > y * y)
			d += x;
		else
			d += y;

		if (x > m)
			putchar('\n');
		else if ((d + m) % 2)
			putchar(' ');
		else
			putchar('*');
	}
	putchar('\n');
}

int main()
{
	for (auto i = 0; i <= 11; i++)
		spiral(i);
	return 0;
}
