/*

Holy simplicity!Jan Hus

Two positive integers a and b are given. Apply the bitwise exclusive or operation to them.

Input
Two positive integers a and b (a,b≤10^9).

Output
Print the result of applying xor operation over the given numbers.

Examples

Input #1
3 7

Answer #1
4

Input #2
12 11

Answer #2
7

*/

class XOR {
	public static void main(String[] args) {
		System.out.println(solve(3, 7));
		System.out.println(solve(12, 11));
	}

	static int solve(int a, int b) {
		return a ^ b;
	}
}
