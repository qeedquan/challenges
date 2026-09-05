/*

Write a program that checks if a given positive integer can be represented as sum of two or more consecutive positive integers.

Example:
43 can be represented as 21 + 22

10 = 1+2+3+4

but 4 cannot be represented in this way.

Input spec: positive integer (as argument or stdin)

Output spec: truthy or falsy

Sample i/o
43 -> true
4 -> false

Shortest code wins.

*/

package main

func main() {
	assert(solve(43) == true)
	assert(solve(4) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@mellamokb

1. All odd numbers greater than 1 can be trivially written as the sum of two consecutive numbers (ex 15 = 7+8, 23=11+12, etc.).

2. For even numbers having an odd factor where the odd factor is less than twice the even factor.
For example, 4*7, because 7 < (2*4 = 8). Simply add 7 numbers with 4 at the center, 1+2+3+4+5+6+7.

3. For even numbers having an odd factor where the odd factor is more than twice the even factor.
For example, 4*9, because 9 > (2 * 4 = 8). Double the even factor, and halve the odd factor to get 8*4.5.
You will add the 8 numbers centered at 4.5, i.e., 1+2+3+4+5+6+7+8.

4. The only numbers left are the even numbers having no odd factor, i.e., the powers of two.
The formula for the sum of a consecutive set of numbers is (avg * count).
Now if the count is odd, then avg is a whole number, and (avg * count) has an odd factor.
If count is even, then avg must be #.5, and thus avg * 2 is odd, and so avg * count has an odd factor.
Therefore, any sum using the formula (avg * count) must have an odd factor, which powers of two do not, and therefore have no solution.

*/

func solve(n int) bool {
	return !ispow2(n)
}

func ispow2(n int) bool {
	return n > 0 && n&(n-1) == 0
}
