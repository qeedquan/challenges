/*

Given a positive integer n, output all integers b (such that 1<b<n−1) where n can be written as the sum of any number of consecutive powers of b.

Example:

Let's say n=39.

3^1 + 3^2 + 3^3 = 3 + 9 + 27 = 39

This does not work for any other b, so our output is [3].

Test cases up to n=50:

1: []
2: []
3: []
4: [2]
5: []
6: [2]
7: [2]
8: [2]
9: [3]
10: []
11: []
12: [2,3]
13: [3]
14: [2]
15: [2]
16: [2,4]
17: []
18: []
19: []
20: [4]
21: [4]
22: []
23: []
24: [2]
25: [5]
26: []
27: [3]
28: [2]
29: []
30: [2,5]
31: [2,5]
32: [2]
33: []
34: []
35: []
36: [3,6]
37: []
38: []
39: [3]
40: [3]
41: []
42: [6]
43: [6]
44: []
45: []
46: []
47: []
48: [2]
49: [7]
50: []

Clarifications:

You can use this Python script to generate your own test cases.
This is code-golf, so shortest answer wins!

*/

package main

import "fmt"

func main() {
	for i := 1; i <= 50; i++ {
		fmt.Println(i, f(i))
	}
}

/*

@Arnauld

Algorithm
Given the input n and for each b∈[2,n-2]:


1. we do n = n/b as long as n ≡ 0 (mod b)
2. we do n = (n-1)/b as long as (n-1) ≡ 0 (mod b)

If we end up with n=0, then b is a solution.

Explanation
If n is of the form b^p + b^(p+1) + ⋯ + b^(p+q), the first step will normalize it to:

b^0 + b^1 + ⋯ + b^q

and each iteration of the second step will remove the most significant term ...

b0 + b1 + ⋯ + b^(q-1)

... until it's eventually reduced to 0.

*/

func f(n int) []int {
	r := []int{}
	for b := 2; b <= n-2; b++ {
		x := n
		for x%b == 0 {
			x = x / b
		}
		for (x-1)%b == 0 {
			x = (x - 1) / b
		}
		if x == 0 {
			r = append(r, b)
		}
	}
	return r
}
