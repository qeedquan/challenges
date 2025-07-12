/*

"The Nobel Prize in mathematics was awarded to a California professor who has discovered a new number! The number is bleen, which he claims belongs between 6 and 7." --George Carlin

In this challenge, you will print all Integers, inclusive, within the given input range. Print numbers ascending or descending according to their input order. That is, for input [n1, n2], print ascending if n1 < n2, descending if n1 > n2.

Since bleen is now an Integer number it may be used as input. It must also be included in the output, between 6 and 7 where applicable. Also note that -bleen exists between -7 and -6.

Input

Two Integers [n1, n2] in the range [-10, 10], inclusive, via your programming language's input of choice.

(Input may also contain bleen and -bleen!)

Output

Print all Integers starting at n1 and ending with n2, including the newly discovered bleen between 6 and 7. Output can be a range of character separated numbers in some form your language supports - that is, comma or space separated. One trailing space of output is okay.

Examples

Input:  1 10
Output: 1 2 3 4 5 6 bleen 7 8 9 10

Input:  -9 -4
Output: -9 -8 -7 -bleen -6 -5 -4

Input:  -8 bleen
Output: -8 -7 -bleen -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 6 bleen

Input:  9 1
Output: 9 8 7 bleen 6 5 4 3 2 1

Input:  2 -bleen
Output: 2 1 0 -1 -2 -3 -4 -5 -6 -bleen

Input:  -bleen 0
Output: -bleen -6 -5 -4 -3 -2 -1 0

Input:  bleen bleen
Output: bleen

Input:  2 2
Output: 2
Additional notes

You may write a program or function and use any standard method of receiving input and providing output.

You may use any programming language, but standard loopholes are not allowed.

This is code-golf, so the shortest valid answer – measured in bytes – wins.

*/

package main

import (
	"fmt"
	"slices"
	"strconv"
)

func main() {
	test("1", "10", []string{"1", "2", "3", "4", "5", "6", "bleen", "7", "8", "9", "10"})
	test("-9", "-4", []string{"-9", "-8", "-7", "-bleen", "-6", "-5", "-4"})
	test("-8", "bleen", []string{"-8", "-7", "-bleen", "-6", "-5", "-4", "-3", "-2", "-1", "0", "1", "2", "3", "4", "5", "6", "bleen"})
	test("9", "1", []string{"9", "8", "7", "bleen", "6", "5", "4", "3", "2", "1"})
	test("2", "-bleen", []string{"2", "1", "0", "-1", "-2", "-3", "-4", "-5", "-6", "-bleen"})
	test("-bleen", "0", []string{"-bleen", "-6", "-5", "-4", "-3", "-2", "-1", "0"})
	test("bleen", "bleen", []string{"bleen"})
	test("2", "2", []string{"2"})
	test("-bleen", "bleen", []string{"-bleen", "-6", "-5", "-4", "-3", "-2", "-1", "0", "1", "2", "3", "4", "5", "6", "bleen"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b string, r []string) {
	p := gen(a, b)
	fmt.Println(p)
	assert(slices.Equal(p, r))
}

func gen(a, b string) []string {
	r := []string{}
	x := conv(a)
	y := conv(b)
	y += truths(x < y)
	for ; x != y; x -= cmp(x, y) {
		switch {
		case x == -7:
			r = append(r, "-bleen")
		case x == 7:
			r = append(r, "bleen")
		default:
			z := x
			if x < -7 {
				z += 1
			} else if x >= 7 {
				z -= 1
			}
			r = append(r, fmt.Sprint(z))
		}
	}
	return r
}

func cmp(a, b int) int {
	if a < b {
		return -1
	}
	if a == b {
		return 0
	}
	return 1
}

func truths(x bool) int {
	if x {
		return 1
	}
	return -1
}

func conv(s string) int {
	switch s {
	case "bleen":
		return 7
	case "-bleen":
		return -7
	}

	x, _ := strconv.Atoi(s)
	switch {
	case x < -6:
		return x - 1
	case x > 6:
		return x + 1
	}
	return x
}
