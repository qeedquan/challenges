/*

Task
John is a programmer. He treasures his time very much. He lives on the n floor of a building. Every morning he will go downstairs as quickly as possible to begin his great work today.

There are two ways he goes downstairs: walking or taking the elevator.

When John uses the elevator, he will go through the following steps:

1. Waiting the elevator from m floor to n floor;
1a. Or take the stairs to m floor;
2. Waiting the elevator open the door and go in;
3. Waiting the elevator close the door;
4. Waiting the elevator down to 0 floor;
5. Waiting the elevator open the door and go out;
(the time of go in/go out the elevator will be ignored)

Given the following arguments:

n: An integer. The floor of John(0-based).
m: An integer. The floor of the elevator(0-based).
speeds: An array of integer. It contains four integer [a,b,c,d]
        a: The seconds required when the elevator rises or falls 1 floor
        b: The seconds required when the elevator open the door
        c: The seconds required when the elevator close the door
        d: The seconds required when John walks to n-1 or n+1 floor

Please help John to calculate the shortest time to go downstairs.

Example
For n = 4, m = 5 and speeds = [1,2,3,10], the output should be 12.

John go downstairs by using the elevator:

1 + 2 + 3 + 4 + 2 = 12

For n = 0, m = 5 and speeds = [1,2,3,10], the output should be 0.

John is already at 0 floor, so the output is 0.

For n = 4, m = 3 and speeds = [2,3,4,5], the output should be 20.

John go downstairs by walking:

5 x 4 = 20

For n = 7, m = 6 and speeds = [3,1,1,4], the output should be 25.

John walks down 1 floor and takes the elevator from there.

1×4 + 1 + 1 + 6×3 + 1 = 25

Pure walk would have taken 7×4 = 28; pure elevator would have taken 1×3 + 1 + 1 + 7×3 + 1 = 27.

Note
These are Dutch floors. They are numbered 0-based. (0 is usually called "begane grond".)

*/

#include <assert.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
shorterest(int n, int m, int s[4])
{
	int a, b, c, d;
	int t0, t1, t2;

	if (n < 1 || m < 0)
		return 0;

	a = s[0];
	b = s[1];
	c = s[2];
	d = s[3];

	t0 = n * d;
	t1 = abs(n - m) * a + b + c + (n * a) + b;
	t2 = abs(n - m) * d + b + c + (m * a) + b;
	return min(t0, min(t1, t2));
}

int
main()
{
	int s1[] = { 1, 2, 3, 10 };
	int s2[] = { 2, 3, 4, 10 };
	int s3[] = { 2, 3, 4, 5 };
	int s4[] = { 3, 1, 1, 4 };

	assert(shorterest(4, 5, s1) == 12);
	assert(shorterest(0, 5, s1) == 0);
	assert(shorterest(4, 4, s1) == 11);
	assert(shorterest(1, 1, s1) == 8);
	assert(shorterest(4, 3, s1) == 12);
	assert(shorterest(1, 1, s2) == 10);
	assert(shorterest(4, 3, s3) == 20);
	assert(shorterest(7, 6, s4) == 25);

	return 0;
}
