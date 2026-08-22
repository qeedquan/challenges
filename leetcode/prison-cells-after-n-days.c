/*

There are 8 prison cells in a row and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.

You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.

Return the state of the prison after n days (i.e., n such changes described above).

Example 1:

Input: cells = [0,1,0,1,1,0,0,1], n = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]
Example 2:

Input: cells = [1,0,0,1,0,0,1,0], n = 1000000000
Output: [0,0,1,1,1,1,1,0]

Constraints:

cells.length == 8
cells[i] is either 0 or 1.
1 <= n <= 10^9

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
ndays(int c[8], int n)
{
	int c2[8];
	int i;

	memset(c2, 0, sizeof(c2));
	n = ((n - 1) % 14) + 1;
	for (; n > 0; n--) {
		for (i = 1; i < 7; i++)
			c2[i] = (c[i - 1] == c[i + 1]);
		memcpy(c, c2, sizeof(c2));
	}
}

void
test(int c[8], int n, int r[8])
{
	ndays(c, n);
	assert(!memcmp(c, r, sizeof(*r) * 8));
}

int
main()
{
	int c1[] = { 0, 1, 0, 1, 1, 0, 0, 1 };
	int c2[] = { 1, 0, 0, 1, 0, 0, 1, 0 };

	int r1[] = { 0, 0, 1, 1, 0, 0, 0, 0 };
	int r2[] = { 0, 0, 1, 1, 1, 1, 1, 0 };

	test(c1, 7, r1);
	test(c2, 1000000000, r2);

	return 0;
}
