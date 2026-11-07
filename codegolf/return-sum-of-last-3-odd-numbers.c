/*

Introduction
In my CS4 class I worked with another student to golf this lab as much as possible. I learned a lot about Ruby with it, and I am curious what optimizations could be done. :D

Challenge
The 3rd grade students in Mrs. Johnson’s class are learning about odd and even numbers. To reinforce the concept, Mrs. Johnson had the students write the odd numbers an odd number of times per line like so:

1
3 5 7
9 11 13 15 17
19 21 23 25 27 29 31
Notice the first line has 1 number, the next line 3, the next 5, and so forth containing all odd numbers in sequential order.

Given the number of odd numbers in a line, you are expected to write a program that will give the sum of the last 3 numbers of that line.

Input
The input is a sequence of lines, each having a single odd number N, where (1 < N < 100). N denotes the number of odd numbers in that particular line.

Output
For each value of N, you will print the sum of the last 3 odd numbers in that line.

Example Input
3
5
7
Example Output
15
45
87
My best attempt is 26 characters, and this took a lot of little optimizations.

I recommend working on this yourself, but here's our solution:

$<.map{p~_1.to_i**2*3/2-9}

*/

#include <assert.h>
#include <math.h>

int
f(int n)
{
	if (n < 1)
		return 0;

	n += 1;
	return floor((n * n * 1.5) - 9);
}

int
main()
{
	assert(f(3) == 15);
	assert(f(5) == 45);
	assert(f(7) == 87);

	return 0;
}
