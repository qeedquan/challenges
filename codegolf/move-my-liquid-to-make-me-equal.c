/*

You are given 4 positive integers: volume of the first container (v1), volume of the second container (v2), volume of the liquid in the first container (l1), and volume of the liquid in the second container (l2). Your task is to move some of the liquid from container 1 to container 2, making the amount of empty space in the containers equal to each other, outputting how much liquid should be moved.

An example
Here is an example of some possible input (formatted for the ease of test cases. The input isn't formatted.):

8 11
6  5
Here, you need to make sure that the differences between the volumes and the containers are equal. Currently the difference is not equal:

  8 11
- 6  5
======
   6 2
So we need to try to make them equal, by taking some of the values in one container to another container:

  8 11
- 4  7
======
  4  4
After you have succeeded, output how much liquid you need to take from container 1 to container 2. Therefore the above example should output 2.

Test cases
15 16
 9  2
We move into this state:

 15 16
- 5  6
======
 10 10
Therefore 4 is the expected result.

Test case #2
16 12
13  1
We move into this state:

 16 12
- 9  5
======
  7  7
Therefore 4 is the expected output.

Test case #3
20 12
10 2
Moved:

 20 12
-10 2
======
 10 10
Therefore 0 is the expected output.

More test cases
(They don't have explanations as this should be quite clear)

12 5
9  0 -> 1

9 11
7  3 -> 3

Rules
The test cases will be made so that the result is always possible as a positive integer. The result will never be a decimal.
Input can be taken in any convenient and reasonable format.
Output can be given in any convenient and reasonable format.
The input string will be made so that a moving is always possible without involving decimals or negative numbers. Also there will not be more liquid than how much a container can hold.
Of course, this is code-golf, so the answer in each language consisting of the fewest number of bytes wins. Happy golfing!
An extra restriction for the test cases: you can assume that there is always going to be space available in the second container. So a test case like this:
10 2
 2 2
is not going to be a valid testcase.

*/

#include <assert.h>

int
liquid(int v1, int v2, int l1, int l2)
{
	return (v2 - l2 - v1 + l1) / 2;
}

int
main(void)
{
	assert(liquid(8, 11, 6, 5) == 2);
	assert(liquid(15, 16, 9, 2) == 4);
	assert(liquid(16, 12, 13, 1) == 4);
	assert(liquid(20, 12, 10, 2) == 0);
	assert(liquid(12, 5, 9, 0) == 1);
	assert(liquid(9, 11, 7, 3) == 3);

	return 0;
}
