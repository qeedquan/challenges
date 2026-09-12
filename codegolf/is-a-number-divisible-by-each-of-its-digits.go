/*

My friend and I were working on a lab in our AP Computer Science class and decided to code golf one one the problems since we still had half the class free after we finished. Here is the question:

Given a number n, is n divisible by each of its digits?

For example, 128 will pass this test- it is divisible by 1,2, and 8. Any numbers with a zero automatically disqualify the number. While you may use other languages and post solutions with them if you like, we are most interested in seeing how compact people can make the program in Java, as that is the language we use in the class. So far, we both have 51. Here is my current code:

public boolean dividesSelf(int n){for(int p=n;n%10>0;)n/=p%(n%10)>0?.1:10;return n<1;}
// 51 characters

// Breakdown:
// for(int p=n;         Saves one semicolon to put declaration into for loop
// n%10>0;)             Basic check-for-zero
// n/=                  Pretty simple, discarding one number off of n at a time
// p%(n%10)>0?          If p (the given value) is not divisible by n%10 (the current digit)...
// .1:10;               Divide by .1 (multiply by 10) so it fails the check next iteration. If it is divisible, divide by 10 to truncate the last digit
// return n<1           If the number was fully divisible, every digit would be truncated, and n would be 0. Else, there would still be non-zero digits.
Requirements
The method signature can be whatever you want. Just count the function body. Make sure, though, that the method returns a boolean value and only passes in one numeric parameter (not a string).

The code must be able to pass all of these cases (in order to stay true to the directions of the original question, only boolean true and false values count if the language supports booleans. If and only if your language does not have boolean variables you may represent false with 0 and true with any nonzero integer (preferably 1 or -1):

128 -> true
 12 -> true
120 -> false
122 -> true
 13 -> false
 32 -> false
 22 -> true
 42 -> false
212 -> true
213 -> false
162 -> true
204 -> false
Also, we didn't count whitespace, so feel free to do the same, unless the whitespace is essential to the working of the program (so newlines in Java don't count, but a single space between int and x=1 does count.) Good luck!

*/

package main

func main() {
	assert(digdiv(128) == true)
	assert(digdiv(12) == true)
	assert(digdiv(120) == false)
	assert(digdiv(122) == true)
	assert(digdiv(13) == false)
	assert(digdiv(32) == false)
	assert(digdiv(22) == true)
	assert(digdiv(42) == false)
	assert(digdiv(212) == true)
	assert(digdiv(213) == false)
	assert(digdiv(162) == true)
	assert(digdiv(204) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func digdiv(n int) bool {
	if n < 1 {
		return false
	}

	for m := n; m > 0; m /= 10 {
		if d := m % 10; d == 0 || n%d != 0 {
			return false
		}
	}
	return true
}
