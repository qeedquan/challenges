/*

Recently, I created a binary word search that got me working with grids. It was fun, so I wanted to create some more similar content. Meet Pythagoras' Golfing grid:

d e f
g T h
i j k

Each of d, e, f, g, h, i, j, k and T represent a numeric value.

Now consider an orthogonal triangle along the lower diagonal of this grid (so the vertical side is d, g, i; the horizontal base is i, j, k and; the hypotenuse is d, T, k).

We'll then assign some value constraints to various different cells/sums of cells, in a manner similar to Pythagoras' theorem:

Let a=d+g+i
Let b=i+j+k
Let c=f=dk
Let T=f-eh
You'll be given the value of T. You should then output the values of d,e,f,g,h,i,j,k, in that order, such that a^2+b^2=c^2 (equivalently, such that (d+g+i)^2 + (i+j+k)^2 = f^2 = (dk)^2) and such that T = f-eh

For example, given a value T=55, the output should be:

as T=f-eh=80-5*5 and

(4 + 22 + 22)^2 + (22 + 22 + 20)^2 = 48^2 + 64^2 = 2304 + 4096 = 6400 = 802 = (4*20)^2

The resulting grid would look like this:
4 5 80
22 55 5
22 22 20

Input
For clarity, your input will be a numeric value T:

55

Output
For clarity, your output will be a comma delimited list of the values d,e,f,g,h,i,j,k:

4,5,80,22,5,22,22,20

Completion of Processing
There can be more than one answer for a given T, and as such, processing should complete upon discovery of the first valid set of values.

Loophole Prevention
Loopholes should not be utilized to achieve an answer. For example, returning hard coded values is prohibited.

Final Notes
While their is no official time limit, you can feel free to or not to add a variable cutoff time to your solution and return an answer of u (representing unsolvable) for the sake of brevity when reviewing answers.
So long as this portion of your solution is clearly explained, it can be excluded from your size calculation.

If you choose to add a cutoff time, please make it an additional variable for input named c.

Scoring
This is code-golf so the shortest code in bytes wins.

*/

#include <assert.h>

bool
check(long T, long d, long e, long f, long g, long h, long i, long j, long k)
{
	long a, b, c;

	a = d + g + i;
	b = i + j + k;
	c = f;
	return (a * a + b * b == c * c) && (T == f - e * h) && (f == d * k);
}

// @Arnauld - some parameters can just be hardcoded to be constants
void
solve(long T, long *d, long *e, long *f, long *g, long *h, long *i, long *j, long *k)
{
	*d = 1;
	*e = 1;
	*f = 5;
	*g = 0;
	*h = 5 - T;
	*i = 2;
	*j = -3;
	*k = 5;
}

int
main()
{
	long d, e, f, g, h, i, j, k;
	long N, T;

	N = 100000000;
	for (T = -N; T <= N; T++) {
		solve(T, &d, &e, &f, &g, &h, &i, &j, &k);
		assert(check(T, d, e, f, g, h, i, j, k));
	}

	return 0;
}
