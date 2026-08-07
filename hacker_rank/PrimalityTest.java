/*

A prime number is a natural number greater than  whose only positive divisors are  and itself. For example, the first six prime numbers are 2, 3, 5, 7, 11, and 13.

Given a large integer, n, use the Java BigInteger class' isProbablePrime method to determine and print whether it's prime or not prime.

Input Format

A single line containing an integer, n (the number to be checked).

Constraints

n contains at most 100 digits.
Output Format

If n is a prime number, print prime; otherwise, print not prime.

Sample Input
13
Sample Output
prime

Explanation

The only positive divisors of 13 are 1 and 13, so we print prime.

*/

import java.math.BigInteger;

public class PrimalityTest {
	public static void main(String[] args) {
		System.out.println(isPrime("13"));
		System.out.println(isPrime("57"));
		System.out.println(isPrime("2147483647"));
		System.out.println(isPrime("4294967295"));
	}

	public static String isPrime(String string) {
		var number = new BigInteger(string);
		if (number.isProbablePrime(10)) {
			return "prime";
		}
		return "not prime";
	}
}
