/*

You are given two positive integers x and y.

In one operation, you can do one of the four following operations:

Divide x by 11 if x is a multiple of 11.
Divide x by 5 if x is a multiple of 5.
Decrement x by 1.
Increment x by 1.
Return the minimum number of operations required to make x and y equal.

Example 1:

Input: x = 26, y = 1
Output: 3
Explanation: We can make 26 equal to 1 by applying the following operations:
1. Decrement x by 1
2. Divide x by 5
3. Divide x by 5
It can be shown that 3 is the minimum number of operations required to make 26 equal to 1.

Example 2:

Input: x = 54, y = 2
Output: 4
Explanation: We can make 54 equal to 2 by applying the following operations:
1. Increment x by 1
2. Divide x by 11
3. Divide x by 5
4. Increment x by 1
It can be shown that 4 is the minimum number of operations required to make 54 equal to 2.

Example 3:

Input: x = 25, y = 30
Output: 5
Explanation: We can make 25 equal to 30 by applying the following operations:
1. Increment x by 1
2. Increment x by 1
3. Increment x by 1
4. Increment x by 1
5. Increment x by 1
It can be shown that 5 is the minimum number of operations required to make 25 equal to 30.

Constraints:

1 <= x, y <= 10^4


Hint 1
The only way to make x larger is to increase it by 1 so if y >= x the answer is y - x.

Hint 2
For y < x, x - y is always a candidate answer since we can repeatedly decrease x by one to reach y.

Hint 3
We can also increase x and then use the division operations. For example, if x = 10 and y = 1, we can increment x by 1 then divide it by 11.

Hint 4
Find an upper bound U on the maximum value of x we will reach an optimal solution. Since all values of x will be in the range [1, U], we can use BFS to find the answer.

Hint 5
One possible upper bound on x is U = x + (x - y) . To reach any number strictly greater than U from x, we will need more than x - y operations which is not optimal since we can always reach y in x - y operations.

*/

package main

func main() {
	s := NewSolver()
	assert(s.Minimize(26, 1) == 3)
	assert(s.Minimize(54, 2) == 4)
	assert(s.Minimize(25, 30) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type Solver struct {
	cache map[[2]int]int
}

func NewSolver() *Solver {
	return &Solver{
		cache: make(map[[2]int]int),
	}
}

func (s *Solver) Minimize(x, y int) int {
	if y >= x {
		return y - x
	}

	k := [2]int{x, y}
	r, f := s.cache[k]
	if f {
		return r
	}

	r0 := x%5 + 1 + s.Minimize(x/5, y)
	r1 := 5 - x%5 + 1 + s.Minimize((x/5)+1, y)
	r2 := x%11 + 1 + s.Minimize(x/11, y)
	r3 := 11 - x%11 + 1 + s.Minimize((x/11)+1, y)
	r4 := x - y
	s.cache[k] = min(r0, r1, r2, r3, r4)

	return s.cache[k]
}
