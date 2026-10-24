/*

A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward or forward.

Given a string A, print Yes if it is a palindrome, print No otherwise.

Constraints

A will consist at most 50 lower case english letters.

Sample Input
madam
Sample Output
Yes

*/

public class StringReverse {
	public static void main(String[] args) {
		System.out.println(isPalindrome("madam"));
		System.out.println(isPalindrome("ooze"));
	}

	public static String isPalindrome(String string) {
		var stringBuilder = new StringBuilder(string);
		var stringReverse = stringBuilder.reverse().toString();
		if (string.equals(stringReverse)) {
			return "Yes";
		}
		return "No";
	}
}
