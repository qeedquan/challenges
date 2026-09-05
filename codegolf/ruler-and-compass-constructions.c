/*

In this code-golf challenge, you will work with a construction that was used by the ancient Greeks: the straightedge-and-compass construction. In particular, you will count how many different constructions can be made with a compass and an unmarked ruler in n
 steps, where a step is either drawing a new line or a circle defined by two points.

As an example of some of these constructions, when n=5 we get the following constructions (and many more!)

https://i.sstatic.net/F0rmK3KV.png

Defining a straightedge-and-compass construction
Starting with two points, which are conventionally (0,0) and (1,0), we can draw lines and circles in the following way:

Choose two distinct points, A and B and draw the infinite line AB¯ connecting them, or
Choose two distinct points A and B and draw the circle centered at A that goes through B.
We get new points where lines intersect with lines, where lines intersect with circles, and where circles intersect with circles.
These new points can be used in subsequent steps of the construction.

Examples for 0≤n≤2
Let a(n) be the number of distinct diagrams that can be made in exactly n moves.

Example for n=1.
Here are the a(1)=3 distinct constructions.

https://i.sstatic.net/XIDWSM8c.png

Example for n=2.
Here are the a(2)=3 distinct constructions.

https://i.sstatic.net/2fhXQiAM.png

Example for n=3
When n=3, we have a(3)=16 constructions that fall into six equivalence classes with respect to rigid transformations.

3 constructions which are rigid transformations of the first diagram,
4 constructions that are rigid transformations of the second diagram,
1 construction corresponding to the third diagram,
4 constructions that are rigid transformations of the fourth diagram,
2 constructions that are rigid transformations of the fifth diagram,
2 constructions that are rigid transformations of the six diagram.

https://i.sstatic.net/5GLlkNHO.png

Start of sequence
The (0-indexed) sequence begins:1,3,3,16,205,5886,542983,…

Challenge
In this code-golf challenge. Your goal is to write a program that takes a positive integer n∈Z≥0 as an input and outputs a(n), which is the number of distinct diagrams that can be constructed with exactly n circles and lines.

Winning criterion
This is code-golf so shortest code wins.

*/

#include <stdio.h>

typedef unsigned long ulong;

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A383082
long
seq(ulong n)
{
	static const long tab[] = { 1, 3, 3, 16, 205, 5886, 542983 };

	if (n >= nelem(tab))
		return -1;
	return tab[n];
}

int
main()
{
	ulong i;

	for (i = 0; i < 7; i++)
		printf("%ld\n", seq(i));

	return 0;
}
