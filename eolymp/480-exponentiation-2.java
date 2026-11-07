/*

Given A, B, and M, compute A^B mod M.

Input
A single line contains three natural numbers A, B, and M (1≤A,B≤10^18, 2≤M≤2×10^9) separated by spaces.

Output
Output the value of A^B mod M.

Examples

Input #1
2 100000000 1000

Answer #1
376

*/

import java.math.BigInteger;

class MODEXP {
	public static void main(String[] args) {
		System.out.println(solve("2", "100000000", "1000"));
	}

	public static BigInteger solve(String base, String exponent, String modulus) {
		var A = new BigInteger(base);
		var B = new BigInteger(exponent);
		var M = new BigInteger(modulus);
		return A.modPow(B, M);
	}
}
