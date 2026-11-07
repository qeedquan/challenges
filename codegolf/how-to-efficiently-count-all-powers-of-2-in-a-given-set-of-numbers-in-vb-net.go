/*

Every integer can be expressed in powers of 2. You know this as the binary system

Assume you are given a set of k numbers (0 < k < 2^n). You want to decide for this set whether every integer power of 2 up to 2^(n-1) occurs at least m times

One example:

n = 7 (2^n = 128, )
k = 5
set =
{100,
91,
88,
63,
44}
m = 3

Solution:
Consider the binary representation of the set for up to n(=7) digits:
set = {
1100100
1011011
1011000
0111111
0101100
}
sum up the columns
{3,3,3,4,3,2,2} -> result the set failed, because 2 < m
This is so far my best(fastest) algorithm(, written for vb.net):

Private Function Check(arr As Integer(), n As Integer, m as Integer) As Boolean
    For i = n - 1 To 0 Step -1
        Dim columnCheck = 0
        For j = 0 To arr.Length - 1
            If (arr(j) And (1 << i)) <> 0 Then columnCheck += 1
        Next
        If columnCheck < m Then Return False
    Next
    Return True
End Function
maximum size of the elements of arr need to checked before entering.

Do you have better ideas?

*/

package main

func main() {
	assert(check([]int{100, 91, 88, 63, 44}, 7, 3) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func check(a []int, n, m int) bool {
	for i := n - 1; i >= 0; i-- {
		c := 0
		for j := range a {
			if a[j]&(1<<i) != 0 {
				c += 1
			}
		}
		if c < m {
			return false
		}
	}
	return true
}
