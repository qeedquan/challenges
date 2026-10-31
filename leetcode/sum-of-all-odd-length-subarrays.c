/*

Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.

A subarray is a contiguous subsequence of the array.

Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
Example 2:

Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
Example 3:

Input: arr = [10,11,12]
Output: 66


Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 1000


Follow up:

Could you solve this problem in O(n) time complexity?

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

/*

https://www.geeksforgeeks.org/sum-of-all-odd-length-subarrays/

For any element at index idx there are (idx + 1) choices on the left side of it and (N – idx) choices on the right side of it.
Therefore, for any element arr[i], the count of arr[i] is (i + 1) * (N – i) in all the subarrays.
So, for an element arr[i], there are ((i + 1) * (N – i) + 1) / 2 sub-arrays with odd length.
Finally, arr[i] will have a total of ((i + 1) * (n – i) + 1) / 2 frequency in the sum.
Therefore, to find the sum of all elements of all the subarrays of odd length, the idea is to iterate over the array and for every ith array element, add [((i + 1) * (n – i) + 1) / 2]*arr[i] to the sum.

*/

int
sols(int *a, size_t n)
{
	size_t i;
	int s;

	s = 0;
	for (i = 0; i < n; i++)
		s += (((i + 1) * (n - i) + 1) / 2) * a[i];
	return s;
}

int
main(void)
{
	int a1[] = {1, 4, 2, 5, 3};
	int a2[] = {1, 2};
	int a3[] = {10, 11, 12};

	assert(sols(a1, nelem(a1)) == 58);
	assert(sols(a2, nelem(a2)) == 3);
	assert(sols(a3, nelem(a3)) == 66);

	return 0;
}
