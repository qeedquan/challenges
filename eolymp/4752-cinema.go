/*

Once, the pupils of the B-th school of city G decided to go to the cinema. The cinema administration placed them in a hall of size n×m, which was specially chosen so that all the seats were occupied by pupils. Each cinema visitor was given a number.

The pupils took their seats as follows: they entered the hall in numerical order, completely filling the first row, then the second row, then the third, and so on.

https://static.e-olymp.com/content/62/62a57f79ba9955a6d5d44c8baadb4b13baadfde3.gif

However, the class teacher decided that such seating was bad for the pupils' behavior and rearranged them in another way: first, all the first seats in each row were occupied, then all the second seats in each row, and so on (see the picture).

https://static.e-olymp.com/content/d8/d86d0f4857aebf58e23e7f014d085c9599a17087.gif

The administration decided to find out how many pupils did not change their seat after the rearrangement.

Input
The first line contains the numbers n and m (1≤n,m≤1000).

Output
Print the number of pupils whose seat did not change after the rearrangement.

Examples

Input #1
3 3

Answer #1
3

Input #2
3 4

Answer #2
2

*/

package main

func main() {
	assert(solve(3, 3) == 3)
	assert(solve(3, 4) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n, m int) int {
	v1 := make([][]int, n)
	v2 := make([][]int, n)
	for i := range n {
		v1[i] = make([]int, m)
		v2[i] = make([]int, m)
	}

	for i := range n {
		for j := range m {
			v1[i][j] = m*i + j
		}
	}

	for j := range m {
		for i := range n {
			v2[i][j] = n*j + i
		}
	}

	r := 0
	for i := range n {
		for j := range m {
			if v1[i][j] == v2[i][j] {
				r++
			}
		}
	}
	return r
}
