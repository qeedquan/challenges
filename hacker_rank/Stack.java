/*

In computer science, a stack or LIFO (last in, first out) is an abstract data type that serves as a collection of elements, with two principal operations: push, which adds an element to the collection, and pop, which removes the last element that was added.(Wikipedia)
A string containing only parentheses is balanced if the following is true: 1. if it is an empty string 2. if A and B are correct, AB is correct, 3. if A is correct, (A) and {A} and [A] are also correct.

Examples of some correctly balanced strings are: "{}()", "[{()}]", "({()})"

Examples of some unbalanced strings are: "{}(", "({)}", "[[", "}{" etc.

Given a string, determine if it is balanced or not.

Input Format

There will be multiple lines in the input file, each having a single non-empty string. You should read input till end-of-file.

The part of the code that handles input operation is already provided in the editor.

Output Format

For each case, print 'true' if the string is balanced, 'false' otherwise.

Sample Input
{}()
({()})
{}(
[]

Sample Output
true
true
false
true

*/

public class Stack {
	public static void main(String[] args) {
		assert(balanced("{}()") == true);
		assert(balanced("({()})") == true);
		assert(balanced("{}(") == false);
		assert(balanced("[]") == true);
		assert(balanced("[}") == false);
		assert(balanced("((()))[[[]]]") == true);
	}

	public static boolean balanced(String string) {
		final var opening = "{[(";
		final var closing = "}])";

		var length = string.length();
		var stack = new int[length + 1];
		var sp = 0;
		for (var i = 0; i < length; i++) {
			var ch = string.charAt(i);
			var i0 = opening.indexOf(ch);
			var i1 = closing.indexOf(ch);

			if (i0 >= 0) {
				stack[sp++] = ch;
			} else if (i1 >= 0) {
				if (sp <= 0)
					return false;
				if (stack[--sp] != opening.charAt(i1))
					return false;
			}
		}
		return sp == 0;
	}
}

