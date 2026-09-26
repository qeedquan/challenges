/*

Not to be confused with Least Common Multiple.

Given a list of positive integers with more than one element, return the most common product of two elements in the array.

For example, the MCM of the list [2,3,4,5,6] is 12, as a table of products is:

    2  3  4  5  6
  ---------------
2 | #  6  8  10 12
3 | #  #  12 15 18
4 | #  #  #  20 24
5 | #  #  #  #  30
6 | #  #  #  #  #
Thanks DJMcMayhem for the table

As 12 appears the most times (two times as 2*6 and 3*4). Note that we aren't including the product of an element and itself, so 2*2 or 4*4 do not not appear in this list. However, identical elements will still be multiplied, so the table for [2,3,3] looks like:

    2  3  3
  ----------
2 | #  6  6
3 | #  #  9
3 | #  #  #
With the MCM being 6.

In the event of a tie, you may return any of the tied elements, or a list of all of them.

This is code-golf, so the shortest byte count for each language wins!

Test-cases:
[2,3,4,5,6] -> 12
[7,2] -> 14
[2,3,3] -> 6
[3,3,3] -> 9
[1,1,1,1,2,2] -> 2
[6,200,10,120] -> 1200
[2,3,4,5,6,7,8,8] -> 24
[5,2,9,10,3,4,4,4,7] -> 20
[9,7,10,9,7,8,5,10,1] -> 63, 70, 90 or [63,70,90]

*/

package main

func main() {
	assert(mcm([]int{2, 3, 4, 5, 6}) == 12)
	assert(mcm([]int{7, 2}) == 14)
	assert(mcm([]int{2, 3, 3}) == 6)
	assert(mcm([]int{3, 3, 3}) == 9)
	assert(mcm([]int{1, 1, 1, 1, 2, 2}) == 2)
	assert(mcm([]int{6, 200, 10, 120}) == 1200)
	assert(mcm([]int{2, 3, 4, 5, 6, 7, 8, 8}) == 24)
	assert(mcm([]int{5, 2, 9, 10, 3, 4, 4, 4, 7}) == 20)
	v := mcm([]int{9, 7, 10, 9, 7, 8, 5, 10, 1})
	assert(v == 63 || v == 70 || v == 90)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mcm(a []int) int {
	m := make(map[int]int)
	for i, u := range a {
		for _, v := range a[i+1:] {
			m[u*v]++
		}
	}

	r, c := 0, 0
	for k, v := range m {
		if v > c {
			r, c = k, v
		}
	}
	return r
}
