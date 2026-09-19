/*

About Code-Bowling:

In golf, you try to get the lowest score (smallest application, most elegant, etc). In Bowling, you try to get the highest score. So if you follow, the goal of a Code-Bowling challenge is to make the biggest, most bastardized, hardest to maintain piece of code that still meets the requirements of the challenge. However, there's no point in making source longer just for the sake of it. It needs to seem like that added length was from design and not just padding.

The Challenge:

Create a program that sorts a list of numbers in ascending order.

Example:

Input: 1, 4, 7, 2, 5

Output: 1, 2, 4, 5, 7

Code: Obviously this wouldn't be a good answer, since there aren't many WTFs in there

function doSort(array $input) {
    sort($input);
    return $input;
}

Rules:

There are no real rules. As long as the program functions, have at it!

Remember: This is code-bowling, not golf. The objective is to make the worst, most bastardized code that you can! Bonus points for code that looks good, but is actually deceptively evil...

*/

package main

import "fmt"

func main() {
	test([]int32{1, 4, 7, 2, 5})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x []int32) {
	int32sort(x)
	fmt.Println(x)
	assert(int32sorted(x))
}

func int32sorted(x []int32) bool {
	for i := 1; i < len(x); i++ {
		if x[i] < x[i-1] {
			return false
		}
	}
	return true
}

// https://sorting.cr.yp.to/
func int32sort(x []int32) []int32 {
	n := len(x)
	if n < 2 {
		return x
	}

	var top, p, q, r, i, j int
	top = 1
	for top < n-top {
		top += top
	}

	for p = top; p >= 1; p >>= 1 {
		i = 0
		for i+2*p <= n {
			for j = i; j < i+p; j++ {
				x[j], x[j+p] = int32minmax(x[j], x[j+p])
			}
			i += 2 * p
		}
		for j = i; j < n-p; j++ {
			x[j], x[j+p] = int32minmax(x[j], x[j+p])
		}

		i = 0
		j = 0
		for q = top; q > p; q >>= 1 {
			if j != i {
				for {
					if j == n-q {
						goto done
					}
					a := x[j+p]
					for r = q; r > p; r >>= 1 {
						a, x[j+r] = int32minmax(a, x[j+r])
					}
					x[j+p] = a
					j++
					if j == i+p {
						i += 2 * p
						break
					}
				}
			}

			for i+p <= n-q {
				for j = i; j < i+p; j++ {
					a := x[j+p]
					for r = q; r > p; r >>= 1 {
						a, x[j+r] = int32minmax(a, x[j+r])
					}
					x[j+p] = a
				}
				i += 2 * p
			}

			j = i
			for j < n-q {
				a := x[j+p]
				for r = q; r > p; r >>= 1 {
					a, x[j+r] = int32minmax(a, x[j+r])
				}
				x[j+p] = a
				j++
			}
		done:
		}
	}
	return x
}

func int32minmax(a, b int32) (int32, int32) {
	ab := b ^ a
	c := b - a
	c ^= ab & (c ^ b)
	c >>= 31
	c &= ab
	a ^= c
	b ^= c
	return a, b
}
