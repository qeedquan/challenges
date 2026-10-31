/*

Challenge
For any two non-empty strings A and B, we define the following sequence :

F(0) = A
F(1) = B
F(n) = F(n-1) + F(n-2)
Where + denotates the standard string concatenation.

The sequence for strings "A" and "B" starts with the following terms: A, B, BA, BAB, BABBA, ...

Create a function or program that, when given two strings A and B, and a positive integer I returns the I-th character of F(∞).

You may choose to use 0-indexing or 1-indexing for I, just specify it in your answer.

You may assume the strings contain only uppercase (or lowercase) letters.

This is a variation of Project Euler's Problem 230, where the two strings were strings of digits of equal length, which trivialize the problem.

Input/Output
You may choose any format for the input. The output should only contain the desired character, with trailing spaces/newlines allowed.

Test Cases
ABC, DEF, 1234567890 → A
ACBB, DEFGH, 45865 → B
A, B, 3 → B
ABC, DEF, 10 → E

This is code-golf, so the lowest byte count for each language wins!

*/

package main

func main() {
	assert(vlfw("ABC", "DEF", 1234567890) == 'A')
	assert(vlfw("ACBB", "DEFGH", 45865) == 'B')
	assert(vlfw("A", "B", 3) == 'B')
	assert(vlfw("ABC", "DEF", 10) == 'E')
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Delfad0r

F(a, b) = b + F(b, a + b)

*/

func vlfw(a, b string, n int) byte {
	if n < len(b) {
		return b[n]
	}
	return vlfw(b, b+a, n)
}
