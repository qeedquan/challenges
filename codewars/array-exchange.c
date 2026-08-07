/*

Array Exchange and Reversing

It's time for some array exchange! The objective is simple: exchange the elements of two arrays in-place in a way that their new content is also reversed.

// before
const myArray = ['a', 'b', 'c'];
const otherArray = [1, 2, 3];

exchangeWith(myArray, otherArray);

// after
myArray => [3, 2, 1]
otherArray => ['c', 'b', 'a']

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
swap(int *x, int *y)
{
	int t;

	t = *x;
	*x = *y;
	*y = t;
}

void
exchange(int *a, int *b, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		swap(&a[i], &b[n - i - 1]);
}

int
main()
{
	int a[] = {'a', 'b', 'c'};
	int b[] = {1, 2, 3};

	exchange(a, b, nelem(a));
	printf("%d %d %d\n", a[0], a[1], a[2]);
	printf("%c %c %c\n", b[0], b[1], b[2]);

	return 0;
}
