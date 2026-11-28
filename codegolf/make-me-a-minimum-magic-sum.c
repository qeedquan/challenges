/*

Keeping this challenge short.

You are given 4 numbers: p1, p2, p3 and p4.

The magic sum of the numbers are defined as follows:

magic_sum = |p1 - p2| + |p2 - p3| + |p3 - p4| + |p4 - p1|
You are only allowed to change one of the above integer values (p1, p2, p3 or p4). You need to change the value such that the magic sum of the values attains its minimum value.

For example:

p1, p2, p3, p4 = 17, -6, 15, 33. The value of the magic sum is 78 in this case.

You can change the -6 here to 16, and the value of the magic sum will become 36, which is the minimum attainable value.

Do keep in mind that numbers can be positive or negative integers.

This is code-golf, so least bytes in code wins. Brownie points for using a Practical Language over a Recreational language. May the 4th be with you.

To reiterate:

Sample 1
Input 1

17 -6 15 33
Output 1

36
Explanation 1

The -6 can be replaced with 16 and that gives us the minimum attainable magic sum possible.

Sample 2
Input 2

10 10 10 10
Output 2

0 or 2
either is acceptable

Explanation 2

The minimum attainable magic sum is 0 since the minimum sum of 4 positive integers is 0. If a number has to be changed, then one of the 10's can be changed to a 9 and thus yielding the output 2.

Sample 3
Input 3

1 2 3 4
Output 3

4
Explanation 3

The input by itself yields 6 as its magic sum. Changing the 4 to 1 and the minimum magic sum is attained, which is 4.

*/

#include <assert.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

void
cmpsw(int *a, int *b)
{
	int c;

	if (*a > *b) {
		c = *a;
		*a = *b;
		*b = c;
	}
}

/*

@xnor

Sorts the input as a,b,c,d, in ascending order, takes the smaller of c-a and d-b, and doubles it. Why does this work?

First, note that when we change an element to maximize to total cyclic sum of distances, it's optimal (or tied for optimal) to change it to equal a neighbor, such as 17, -6, 15, 33 -> 17, 17, 15, 33. That's because its new total distance to its left and right cyclic neighbors is at least the distance between those neighbors, so making these be equal is the best we can do.

Now, deleting one of two adjacent copies of a number gives the same cyclic sum of distances. In the example, this is 17, 15, 33, giving distances 2 + 18 + 16. So instead of replacing one of the four numbers, it's equivalent to just delete it leaving three numbers, and using the sum of their cyclic distances.

Notice that with 3 numbers, the largest distance is the sum of the two smaller ones. This is because if we sort the numbers to have a ≤ b ≤ c, then |a - c| = |a - b| + |b - c|. In other words, we travel between the largest and smallest number twice, using the medium number as a pit stop one of the times. So, the sum of the three distances is just twice the distance between the minimum and maximum, so (c-a)*2.

So, the question is which number we delete to get the smallest distance between the minimum and maximum of the three numbers that remains. Clearly we delete either the smallest or the largest of the numbers. Calling them a, b, c, d in sorted order, deleting a leaves d - b, and deleting d leaves c - a, and the final result is double whichever is smaller.

https://www2.cs.uregina.ca/~mouhoubm/=teaching/=c3620/sola4_02.html
Any comparison sort of 4 elements require 5 comparisons

*/

int
solve(int a, int b, int c, int d)
{
	cmpsw(&a, &b);
	cmpsw(&c, &d);
	cmpsw(&a, &c);
	cmpsw(&b, &d);
	cmpsw(&b, &c);
	return 2 * min(c - a, d - b);
}

int
main()
{
	assert(solve(17, -6, 15, 33) == 36);
	assert(solve(10, 10, 10, 10) == 0);
	assert(solve(1, 2, 3, 4) == 4);

	return 0;
}
