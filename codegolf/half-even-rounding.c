/*

The round function in Python 3 will round values of the form k+1/2 (with k being an integer) to the nearest even integer, which is apparently better than the usual rounding method

Your task is to recreate this functionality: write a program of function that given a (real) number as input, outputs that number rounded to the nearest number, using the same tie-breaking rule as Python's round function

Examples/Test-cases
-3.0   ->    -3
-2.7   ->    -3
-2.5   ->    -2
-2.2   ->    -2
-1.7   ->    -2
-1.5   ->    -2
-0.7   ->    -1
-0.5   ->    0
0.0    ->    0
0.4    ->    0
0.5    ->    0
0.51   ->    1
1.0    ->    1
1.2    ->    1
1.4999 ->    1
1.5    ->    2
1.7    ->    2
2.0    ->    2
2.3    ->    2
2.5    ->    2
2.6    ->    3

Rules
Please add built-in solutions to the community wiki
This is code-golf the shortest solution wins

*/

#include <assert.h>
#include <math.h>

int
main(void)
{
	assert(lrint(-3.0) == -3);
	assert(lrint(-2.7) == -3);
	assert(lrint(-2.5) == -2);
	assert(lrint(-2.2) == -2);
	assert(lrint(-1.7) == -2);
	assert(lrint(-1.5) == -2);
	assert(lrint(-0.7) == -1);
	assert(lrint(-0.5) == 0);
	assert(lrint(0.0) == 0);
	assert(lrint(0.4) == 0);
	assert(lrint(0.5) == 0);
	assert(lrint(0.51) == 1);
	assert(lrint(1.0) == 1);
	assert(lrint(1.2) == 1);
	assert(lrint(1.4999) == 1);
	assert(lrint(1.5) == 2);
	assert(lrint(1.7) == 2);
	assert(lrint(2.0) == 2);
	assert(lrint(2.3) == 2);
	assert(lrint(2.5) == 2);
	assert(lrint(2.6) == 3);

	return 0;
}
