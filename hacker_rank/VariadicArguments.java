/*

You are given a class Solution and its main method in the editor.
Your task is to create the class Add and the required methods so that the code prints the sum of the numbers passed to the function add.

Note: Your add method in the Add class must print the sum as given in the Sample Output

Input Format

There are six lines of input, each containing an integer.

Output Format

There will be only four lines of output. Each line contains the sum of the integers passed as the parameters to add in the main method.

Sample Input

1
2
3
4
5
6

Sample Output

1+2=3
1+2+3=6
1+2+3+4+5=15
1+2+3+4+5+6=21

*/

public class VariadicArguments {
	public static void main(String[] args) {
		sum(1, 2, 3, 4, 5, 6);
	}

	public static void sum(int... values) {
		for (var value : values) {
			if (value < 2)
				continue;
			for (var number = 1; number <= value; number++) {
				System.out.print(number);
				if (number < value) {
					System.out.print("+");
				}
			}
			System.out.println("=" + triangular(value));
		}
	}

	public static int triangular(int value) {
		return value*(value+1)/2;
	}
}
