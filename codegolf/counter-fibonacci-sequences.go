/*

Given three numbers m,n and p, your task is to print a list/array of length p starting with m and n and each element after p represents the difference of the 2 numbers before it, m-n (Counter-Fibonacci Sequence)

For this challenge you can either use a function to return or print the result or a full program.

Input
Three integers, m,n and p, separated by newlines/spaces/commas, whatever your language supports, but you should specify your input format. Code insertion is disallowed.

Output
The numbers contained by the Counter-Fibonacci Sequence, in any of the following formats (this example: m = 50, n = 40, p = 6):

50,40,10,30,-20,50 (or with spacing after commas)
[50,40,10,30,-20,50] (or with spacing after commas)
50 40 10 30 -20 50 (or with \n(newlines) instead of spaces)
{50,40,10,30,-20,50} (or with spaces instead of commas)

Examples
Input => Output

50,40,10 => 50,40,10,30,-20,50,-70,120,-190,310
-100,-90,7 => -100,-90,-10,-80,70,-150,220
250,10,8 => 250,10,240,-230,470,-700,1170,-1870

Rules
You are guaranteed that p is higher than 1
You should provide a way to test your program, if possible
Take note that this loopholes are forbidden and code insertion is disallowed, as mentioned above

Scoring & Leaderboard
Your code must be as short as possible, since this is code-golf. No answer will be accepted, because this challenge is meant to find the shortest answer by language, avoiding an unfair advantage to golfing languages.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(50, 40, 10, []int{50, 40, 10, 30, -20, 50, -70, 120, -190, 310})
	test(-100, -90, 7, []int{-100, -90, -10, -80, 70, -150, 220})
	test(250, 10, 8, []int{250, 10, 240, -230, 470, -700, 1170, -1870})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m, n, p int, r []int) {
	x := cfs(m, n, p)
	fmt.Println(x)
	assert(reflect.DeepEqual(x, r))
}

func cfs(m, n, p int) []int {
	if p < 1 {
		return []int{}
	}
	return append([]int{m}, cfs(n, m-n, p-1)...)
}
