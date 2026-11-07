/*

Update the solution method to round the argument value to the closest precision of two. The argument will always be a float.

23.23456 --> 23.23
1.546    --> 1.55

*/

#include <assert.h>
#include <stdio.h>

float
solution(float n)
{
	int r;

	r = (n * 100) + 0.5;
	return r / 100.0;
}

int
main()
{
	printf("%f\n", solution(23.23456));
	printf("%f\n", solution(1.546));
	return 0;
}
