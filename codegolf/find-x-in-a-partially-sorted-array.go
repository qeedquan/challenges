/*

Your job is to find the location (read index) of a given element X in an array gone through the following transformation process:

Take a fully sorted integer array of size N (N is known implicitly)
Take any random number of mutually exclusive even index pairs (as in that no index appears in more than 1 pair) from the array and swap the elements on those indexes.
A sample array can be like

[5, 2, 3, 4, -1, 6, 90, 80, 70, 100]
formed by

// Take fully sorted integer array
[-1, 2, 3, 4, 5, 6, 70, 80, 90, 100]
// Take some even index pairs : (0, 4) and (6, 8)
// Swap the elements in these indexes. i.e., element at 4<sup>th</sup> index goes to 0<sup>th</sup> etc.
// Final array:
[5, 2, 3, 4, -1, 6, 90, 80, 70, 100]
and a sample X to find in this array can be

-1
You should output the index of the element X in the final array (4 in the above example) or -1 if the element is not found in the array.

Rules

In built searching functions are prohibited.
You must write a method/function/program which takes input from STDIN/Command line arguments/Function arguments.
Input must be in <Array> <X> format. Example: [5, 2, 3, 4, 1, 6, 9, 8, 7, 10] 1
The input array may also contain duplicate integers. In such case, any one index can be the output. UPDATE : You may assume that total number of duplicates << (far less than) size of array. For the benefit of the question in general, duplicates are now prohibited to avoid playing a role in time complexity of the searching algorithm.
Output should be the index of the element X in the array or -1 if not present.

Scoring

Being a code-golf and a code-challenge, your score is calculated by <byte count of your program>*<coeff. of complexity>
Coefficient of Complexity is decided based on the worst case time complexity of your code (Big-O) using the mappings given below.
If your code needs to know the length of the array, it can calculate length using inbuilt methods and that won't be added to the time complexity of the searching part of the code.
Time Complexity      Coefficient
--------------------------------
O(1)                 0.25
O(log(n))            0.5
O(n)                 5
O(n*log(n))          8.5
O(n^2)               10
O(greater than n^2)  20
Minimum score wins!

Bonus

Multiply your final score by 0.5 if you can handle a case where the array has gone through the step 2 in the transformation process I times (instead of just 1), where I is passed as the third parameter in input.
Note that while going through step 2, I times, pairs in each step are mutually exclusive, but pairs in different steps can have common indexes.

*/

package main

import (
	"slices"
)

func main() {
	assert(find([]int{5, 2, 3, 4, -1, 6, 90, 80, 70, 100}, -1) == 4)
	assert(find([]int{5, 2, 3, 4, -1, 6, 90, 80, 70, 100}, 32) == -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func find(a []int, v int) int {
	return slices.Index(a, v)
}
