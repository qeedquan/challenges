/*

Take a non-empty matrix / numeric array containing positive integers as input. Return, in this order, the sums of the first row and column, then the second row and column and continue until there aren't any more rows or columns.

Suppose the input is:

2   10   10    2    4
9    7    7    2    9
1    7    6    2    4
7    1    4    8    9
Then the output should be:

45, 33, 16, 17
Because: 2+9+1+7+10+10+2+4=45, 7+7+1+7+2+9=33, 6+4+2+4=16, 8+9=17.

Test cases:
Test cases are on the following format:

Input
---
Output
5
---
5
..........

1  4
----
5
..........

7
2
---
9
..........

 8    3    7   10    3    7   10    1
10    7    5    8    4    3    3    1
 1    6    4    1    3    6   10    1
 2    3    8    2    8    3    4    1
---
62   40   33   18
..........

30    39    48     1    10    19    28
38    47     7     9    18    27    29
46     6     8    17    26    35    37
 5    14    16    25    34    36    45
13    15    24    33    42    44     4
21    23    32    41    43     3    12
22    31    40    49     2    11    20
---
320  226   235   263   135    26    20
..........

7   10    1
4    4    2
6    3    4
1    4   10
5    7    6
---
34   20   20

As arrays:

[[5]]
[[1,4]]
[[7],[2]]
[[8,3,7,10,3,7,10,1],[10,7,5,8,4,3,3,1],[1,6,4,1,3,6,10,1],[2,3,8,2,8,3,4,1]]
[[30,39,48,1,10,19,28],[38,47,7,9,18,27,29],[46,6,8,17,26,35,37],[5,14,16,25,34,36,45],[13,15,24,33,42,44,4],[21,23,32,41,43,3,12],[22,31,40,49,2,11,20]]
[[7,10,1],[4,4,2],[6,3,4],[1,4,10],[5,7,6]]
This is code-golf so the shortest solution in each language wins.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]int{
		{2, 10, 10, 2, 4},
		{9, 7, 7, 2, 9},
		{1, 7, 6, 2, 4},
		{7, 1, 4, 8, 9},
	}, []int{45, 33, 16, 17})

	test([][]int{
		{5},
	}, []int{5})

	test([][]int{
		{1, 4},
	}, []int{5})

	test([][]int{
		{7},
		{2},
	}, []int{9})

	test([][]int{
		{8, 3, 7, 10, 3, 7, 10, 1},
		{10, 7, 5, 8, 4, 3, 3, 1},
		{1, 6, 4, 1, 3, 6, 10, 1},
		{2, 3, 8, 2, 8, 3, 4, 1},
	}, []int{62, 40, 33, 18})

	test([][]int{
		{30, 39, 48, 1, 10, 19, 28},
		{38, 47, 7, 9, 18, 27, 29},
		{46, 6, 8, 17, 26, 35, 37},
		{5, 14, 16, 25, 34, 36, 45},
		{13, 15, 24, 33, 42, 44, 4},
		{21, 23, 32, 41, 43, 3, 12},
		{22, 31, 40, 49, 2, 11, 20},
	}, []int{320, 226, 235, 263, 135, 26, 20})

	test([][]int{
		{7, 10, 1},
		{4, 4, 2},
		{6, 3, 4},
		{1, 4, 10},
		{5, 7, 6},
	}, []int{34, 20, 20})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m [][]int, r []int) {
	p := sum(m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func sum(m [][]int) []int {
	p := []int{}
	if len(m) == 0 || len(m[0]) == 0 {
		return p
	}

	r, c := len(m), len(m[0])
	n := min(r, c)
	for i := 0; i < n; i++ {
		v := 0
		for j := i; j < r; j++ {
			v += m[j][i]
		}
		for j := i + 1; j < c; j++ {
			v += m[i][j]
		}
		p = append(p, v)
	}
	return p
}
