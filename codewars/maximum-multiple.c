/*

Task
Given a Divisor and a Bound , Find the largest integer N , Such That ,

Conditions :
N is divisible by divisor

N is less than or equal to bound

N is greater than 0.

Notes
The parameters (divisor, bound) passed to the function are only positive values .
It's guaranteed that a divisor is Found .
Input >> Output Examples
maxMultiple (2,7) ==> return (6)
Explanation:
(6) is divisible by (2) , (6) is less than or equal to bound (7) , and (6) is > 0 .

maxMultiple (10,50)  ==> return (50)
Explanation:
(50) is divisible by (10) , (50) is less than or equal to bound (50) , and (50) is > 0 .*

maxMultiple (37,200) ==> return (185)
Explanation:
(185) is divisible by (37) , (185) is less than or equal to bound (200) , and (185) is > 0 .

*/

#include <assert.h>

int
max_multiple(int divisor, int bound)
{
	return bound - (bound % divisor);
}

int
main()
{
	assert(max_multiple(2, 7) == 6);
	assert(max_multiple(3, 10) == 9);
	assert(max_multiple(7, 17) == 14);
	assert(max_multiple(10, 50) == 50);
	assert(max_multiple(37, 200) == 185);
	assert(max_multiple(7, 100) == 98);

	return 0;
}
