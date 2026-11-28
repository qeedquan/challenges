/*

This was originally a question from interviewstreet.com over a decade ago

You are given an array (or whatever - your choice of input) of positive integers  y1,…,yn
that represents n line segments, where segment i has endpoints (i,0) and (i,yi).
Imagine that from the top of each segment a horizontal ray is shot to the left,
and this ray stops when it touches another segment or it hits the  y-axis.
 Construct an array of n integers,  v1,…,vn, where  vi is equal to the length of ray shot from the top of segment i.
 Define V(y1,…,yn)=v1+⋯+vn.

For example starting with 3,2,5,3,3,4,1,2, then  v1,…,v8=1,1,3,1,1,3,1,2 as shown in this picture,
and so V(3,2,5,3,3,4,1,2)=1+1+3+1+1+3+1+2=13 here.

https://i.sstatic.net/bZ04e.png

For each permutation p of  1,…,n, you can calculate  V(yp1,…,ypn).
You can then take the average across all possible permutations.

Write a program or function that gives the expected value of V(yp1,…,ypn) for a uniformly random permutation p of 1,…,n.
Include a complexity measure for your approach, such as O(n) or O(n!) and explain why.

This is code-golf, so the shortest answer in bytes wins. Standard rules apply and default loopholes are forbidden.

Test examples include

Input y             Output E[V]
3,2,5,3,3,4,1,2     15.25
1,2,3               4.333333
3,3,3               3
2,2,3               4
10,2,4,4            6
10,10,10,5,10       5.8
1,2,3,4,5,6         11.15

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
E(int *y, size_t n)
{
	double h, p;
	size_t i, j;

	p = 0;
	for (i = 0; i < n; i++) {
		h = 0;
		for (j = 0; j < n; j++) {
			if (y[i] <= y[j])
				h += 1;
		}
		p += (n + 1) / (h + 1);
	}
	return p;
}

int
main()
{
	int y1[] = { 3, 2, 5, 3, 3, 4, 1, 2 };
	int y2[] = { 1, 2, 3 };
	int y3[] = { 3, 3, 3 };
	int y4[] = { 2, 2, 3 };
	int y5[] = { 10, 2, 4, 4 };
	int y6[] = { 10, 10, 10, 5, 10 };
	int y7[] = { 1, 2, 3, 4, 5, 6 };

	printf("%f\n", E(y1, nelem(y1)));
	printf("%f\n", E(y2, nelem(y2)));
	printf("%f\n", E(y3, nelem(y3)));
	printf("%f\n", E(y4, nelem(y4)));
	printf("%f\n", E(y5, nelem(y5)));
	printf("%f\n", E(y6, nelem(y6)));
	printf("%f\n", E(y7, nelem(y7)));

	return 0;
}
