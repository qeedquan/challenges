/*

A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation:
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation:
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Example 3:

Input: s = "()()"
Output: ""
Explanation:
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".


Constraints:

1 <= s.length <= 10^5
s[i] is either '(' or ')'.
s is a valid parentheses string.

*/

package main

import "bytes"

func main() {
	assert(rmop("(()())(())") == "()()()")
	assert(rmop("(()())(())(()(()))") == "()()()()(())")
	assert(rmop("()()") == "")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rmop(s string) string {
	w := new(bytes.Buffer)
	p := []int{}
	for i, r := range s {
		switch r {
		case '(':
			p = append(p, i)
		case ')':
			n := len(p)
			if n == 0 {
				return s
			}

			j := p[n-1]
			p = p[:n-1]
			if n == 1 {
				w.WriteString(s[j+1 : i])
			}
		}
	}

	if len(p) > 0 {
		return s
	}

	return w.String()
}