/*

Round any given number to the closest 0.5 step

I.E.

solution(4.2) = 4
solution(4.3) = 4.5
solution(4.6) = 4.5
solution(4.8) = 5
Round up if number is as close to previous and next 0.5 steps.

solution(4.75) == 5

*/

#include <assert.h>
#include <math.h>

double
solve(double n)
{
	return round(n * 2) / 2;
}

int
main()
{
	assert(solve(4.2) == 4);
	assert(solve(4.3) == 4.5);
	assert(solve(4.6) == 4.5);
	assert(solve(4.8) == 5);
	assert(solve(4.75) == 5);
	return 0;
}
