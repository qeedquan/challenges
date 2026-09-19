/*

We define the following terms:

Lexicographical Order, also known as alphabetic or dictionary order, orders characters as follows:
A < B < ... Y < Z < a < b < ... < y < z

For example, ball < cat, dog < dorm, Happy < happy, Zoo < ball.

A substring of a string is a contiguous block of characters in the string. For example, the substrings of abc are a, b, c, ab, bc, and abc.

Given a string, s, and an integer, k, complete the function so that it finds the lexicographically smallest and largest substrings of length k.

Function Description

Complete the getSmallestAndLargest function in the editor below.

getSmallestAndLargest has the following parameters:

string s: a string
int k: the length of the substrings to find

Returns

string: the string ' + "\n" + ' where and are the two substrings

Input Format

The first line contains a string denoting s.
The second line contains an integer denoting k.

Constraints
1 <= |s| <= 1000
s consists of English alphabetic letters only (i.e., [a-zA-Z]).

Sample Input 0
welcometojava
3

Sample Output 0
ava
wel

*/

public class StringCompare {
	public static void main(String[] args) {
		System.out.println(getSmallestAndLargest("welcometojava", 3));
	}

	public static String getSmallestAndLargest(String string, int length) {
		var smallest = "";
		var largest = "";
		for (var index = 0; index+length-1 < string.length(); index++) {
			var substring = string.substring(index, index+length);

			if (smallest.equals(""))
				smallest = substring;
			if (largest.equals(""))
				largest = substring;

			if (smallest.compareTo(substring) > 0)
				smallest = substring;
			if (largest.compareTo(substring) < 0)
				largest = substring;
		}
		return String.format("%s %s", smallest, largest);
	}
}
