/*

Background
A ray of light is fired from the top left vertex of an MxN Chamber, where M a denotes the width and N denotes the height of the chamber. The ray of light advances one grid space per second. Given that T is the number of seconds to be simulated, calculate the number of reflections in this time frame.

For example, given 5 4 11 (ie. M = 5, N = 4, T = 11):

\/\  [
/\ \ [
\ \ \[
   \/[
-----
There would be 4 reflections, so the output should be 4.
Note that a reflection only counts if the ray of light has already bounced off it, so for example, given 5 4 10:

\/\  [
/\ \ [
  \ \[
   \/[
-----
There would only be 3 reflections, so the output should be 3.
Your Task
Sample Input: M, the width of the chamber, N, the height of the chamber, and T, the time frame. These are all numbers.

Output: Return the number of reflections.

Explained Examples

Input => Output
1 1 10 => 9

Chamber:
\[
-

The ray will be reflected back and forth a total of 9 times.
Input => Output
5 1 10 => 9

Chamber:
\/\/\[
-----

The ray will be reflected back and forth a total of 9 times. It will first go left to right, then go backwards right to left.
Input => Output
4 5 16 => 6

Chamber:
\/\ [
/\ \[
\ \/[
 \/\[
\/\/[
----

The ray will be reflected back and forth a total of 6 times.
Input => Output
100 100 1 => 0

Chamber:
\ ... [
...    x100
-x100


The ray never touches a wall, and is never reflected, so output 0.

Test Cases

Input => Output
5 4 11 => 4
5 4 10 => 3
1 1 10 => 9
5 1 10 => 9
4 5 16 => 6
100 100 1 => 0

3 2 9 => 5
3 2 10 => 6
6 3 18 => 5
5 3 16 => 7
1 1 100 => 99
4 4 100 => 24
2398 2308 4 => 0
10000 500 501 => 1
500 10000 502 => 1
Bonus points (not really): Listen to DeMarco's song Chamber of Reflection while solving this.

This is code-golf, so shortest answer wins.

*/

package main

func main() {
	assert(reflections(5, 4, 11) == 4)
	assert(reflections(5, 4, 10) == 3)
	assert(reflections(1, 1, 10) == 9)
	assert(reflections(5, 1, 10) == 9)
	assert(reflections(4, 5, 16) == 6)
	assert(reflections(100, 100, 1) == 0)
	assert(reflections(3, 2, 9) == 5)
	assert(reflections(3, 2, 10) == 6)
	assert(reflections(6, 3, 18) == 5)
	assert(reflections(5, 3, 16) == 7)
	assert(reflections(1, 1, 100) == 99)
	assert(reflections(4, 4, 100) == 24)
	assert(reflections(2398, 2308, 4) == 0)
	assert(reflections(10000, 500, 501) == 1)
	assert(reflections(500, 10000, 502) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func reflections(m, n, t int) int {
	c := 0
	p := make(map[[2]int]bool)
	for i := 0; i < t; i++ {
		k := [2]int{i / m, i / n}
		if !p[k] {
			p[k], c = true, c+1
		}
	}
	return max(c-1, 0)
}
