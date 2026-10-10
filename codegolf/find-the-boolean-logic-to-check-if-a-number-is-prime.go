/*

Your task is to find a boolean expression that uses AND (∧), OR (∨), XOR (⊕), and NOT (¬)
operators and binary digit positions (d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,⋯) such that it
successfully checks if any number is prime or not.
From now on, you can use definitions (xn:=S or a fn b:=S or fn(a0,a1,⋯)=S, where S may contain
digit variables and variables previously defined and operators that can be builtin or defined). Here are some clarifications:


0 and 1 aren't primes, thus it should be returned false.

every binary position d1,d2,d3,d4,⋯ can be either TRUE or FALSE, and the position 1 is the last digit, the position 2 is the second to last digit, and so on.

You can use any format to represent the boolean expressions, as long as you know the order to evaluate,
it is unambiguous (numbers must be separated, to avoid confusion for 2-digit numbers, 3-digit, and so on!),
and something like a & b & c is valid, however, a % b | c isn't as it is ambiguous.
You may NOT make the assumption that ¬a has the higher priority, like ¬(a & b) & b is ambiguous.

(3 & (¬2) & 1) | ((¬3) & 2) | (3 & 2 & 1)

You must find a boolean expression with the number of digits depending on the input,
for example, if the input was 4, then it would output the expression with digits d1,d2,d3,d4, because the input is 4.
There may be leading zeros like if the input is 4, then d4=0,d3=1,d2=0,d1=1 is allowed, and that means that the binary number is 0101 or 101 (in decimal, 5).

Also, you must use input (digits to calculate the boolean expression). Outputting to STDOUT or to text file is fine. Using brute force is fine, however, it's really slow, and there's no size limit to the expressions generated as long as it isn't unreasonably too big, like who would expect a 100 TB generated expression with just 5 digits to check?

This is fastest-code, so the code that generates the boolean logic with most bits that can check if a number is prime in less than 1 minute will win, in case of a tie, the fastest to return the most bits will win. The scores will be (re)calculated in my Linux computer.

Example of valid boolean logic that checks if a 3-binary-digit number is prime:

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	for i := 1; i <= 23; i++ {
		fmt.Println(solve(i))
		fmt.Println()
	}
}

/*

@DesmosEnthusiast

The code works by filtering out the primes in the range [0,2^numBits], using the Sieve of Eratosthenes. It converts these primes to binary, and makes a sort of truth table, matching prime binary numbers to 1, and everything else to 0. I then used SOP to fit a boolean expression to this truth table. Here is an example of SOP on a 3-digit prime number table.

Number | Is prime?
==================
000    |0
001    |0
010    |1
011    |1
100    |0
101    |1
110    |0
111    |1
Prime when number = 010 | 011 | 101 | 111

Checking if the number is just one of these cases, 010 for example, can be expanded to (digit 1 = 0) & (digit 2 = 1) & (digit 3 = 0). This can be written more concisely as ((¬d1) & d2 & (¬d3)). Doing this for each case, we get ((¬d1) & d2 & (¬d3)) | ((¬d1) & d2 & d3) | (d1 & (¬d2) & d3) | (d1 & d2 & d3).

Edit February 23rd: Used this article to massively improve the time complexity of the algorithm.
https://cp-algorithms.com/algebra/prime-sieve-linear.html

*/

func solve(numbits int) string {
	size := 1 << numbits
	factor := make([]int, size+1)
	primes := []int{}
	buffer := new(bytes.Buffer)
	for i := 2; i <= size; i++ {
		if factor[i] == 0 {
			factor[i] = i
			primes = append(primes, i)
			fmt.Fprintf(buffer, "(")
			for j := 0; j < numbits; j++ {
				if i&(1<<j) != 0 {
					fmt.Fprintf(buffer, "(¬%d", numbits-j)
					if j != numbits-1 {
						fmt.Fprintf(buffer, ")&")
					} else {
						fmt.Fprintf(buffer, "))|")
					}
				} else {
					fmt.Fprintf(buffer, "%d", numbits-j)
					if j != numbits-1 {
						fmt.Fprintf(buffer, "&")
					} else {
						fmt.Fprintf(buffer, ")|")
					}
				}
			}
		}

		for j := 0; j < len(primes) && i*primes[j] <= size; j++ {
			factor[i*primes[j]] = primes[j]
		}
	}

	result := buffer.String()
	if len(result) > 0 {
		result = result[:len(result)-1]
	}
	return result
}
