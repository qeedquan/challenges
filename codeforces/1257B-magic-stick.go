/*

Recently Petya walked in the forest and found a magic stick.

Since Petya really likes numbers, the first thing he learned was spells for changing numbers. So far, he knows only two spells that can be applied to a positive integer:

If the chosen number a is even, then the spell will turn it into (3*a)/2;
If the chosen number a is greater than one, then the spell will turn it into a-1.
Note that if the number is even and greater than one, then Petya can choose which spell to apply.

Petya now has only one number x. He wants to know if his favorite number y can be obtained from x using the spells he knows. The spells can be used any number of times in any order. It is not required to use spells, Petya can leave x as it is.

Input
The first line contains single integer T (1≤T≤10^4) - the number of test cases. Each test case consists of two lines.

The first line of each test case contains two integers x and y (1≤x,y≤10^9) - the current number and the number that Petya wants to get.

Output
For the i-th test case print the answer on it — YES if Petya can get the number y from the number x using known spells, and NO otherwise.

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES will all be recognized as positive answer).

Example

input
7
2 3
1 1
3 6
6 8
1 2
4 1
31235 6578234

output
YES
YES
NO
YES
NO
YES
YES

*/

package main

func main() {
	assert(mutable(2, 3) == "YES")
	assert(mutable(1, 1) == "YES")
	assert(mutable(3, 6) == "NO")
	assert(mutable(6, 8) == "YES")
	assert(mutable(1, 2) == "NO")
	assert(mutable(4, 1) == "YES")
	assert(mutable(31235, 6578234) == "YES")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mutable(x, y int) string {
	switch {
	case x == 1 && y > x:
		fallthrough
	case x == 3 && y > x:
		fallthrough
	case x == 2 && y > 3:
		return "NO"
	}
	return "YES"
}
