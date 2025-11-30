/*

We call a parens group the open paren (, its matching close paren ) and everything inside them.

A parens group or string is called parenthesly balanced if it contains either nothing or only 2 parenthesly balanced parens groups.

For example:

The string   "(()())()"      is parenthesly balanced
              (    )()       Because it contains exactly 2 parenthesly balanced parens groups
               ()()          The left one is parenthesly balanced because it contains 2 parenthesly balanced parens groups (balanced because they are empty). The right one is parenthesly balanced because it contains nothing.
Likewise:

The string   "(()(()))()"    is not parenthesly balanced
              (      )()     Because it contains a parens group that is not parenthesly balanced: the left one
               ()(  )        The left one is not balanced because it contains a parens group that is not balanced: the right one
                  ()         The right one is not balanced because it only contains one balanced group.
So, a parenthesly balanced string or parens group should either:

Contain nothing at all.
Or contain only and exactly 2 parenthesly balanced parens groups. It should contain nothing else.
Task:
Your task is to write a function or program that checks if a given string is a parenthesly balanced one or not.

Input:
Input will be a string or list of characters or something similar. You can assume that the string will only consist of the characters '(' and ')'. You can also assume that each open paren ( will have its matching close paren ), so don't worry about strings like "(((" or ")(" or "(())("...

Note: As mentioned by @DigitalTrauma in his comment bellow, it's ok to subtitute the () combo by other characters (such as <>, [], ...), if it's causing additional work like escaping in some languages

Output:
Anything to signal whether the string is parenthesly balanced or not (true or false, 1 or 0, ...). Please include in your answer what your function/program is expected to yield.

Examples:
""                                        => True
"()()"                                    => True
"()(()())"                                => True
"(()(()(()())))(()())"                    => True
"(((((((()())())())())())())())()"        => True
"()"                                      => False
"()()()"                                  => False
"(())()"                                  => False
"()(()(())())"                            => False
"(()())(((((()())()))())())"              => False
"()(()()()())"                            => False
"()(()(()())()())"                        => False
The last two examples really made a difference!

Best of luck!

*/

package main

import "strings"

func main() {
	assert(balanced("(()())()") == true)
	assert(balanced("(()(()))()") == false)
	assert(balanced("") == true)
	assert(balanced("()()") == true)
	assert(balanced("()(()())") == true)
	assert(balanced("(()(()(()())))(()())") == true)
	assert(balanced("(((((((()())())())())())())())()") == true)
	assert(balanced("()") == false)
	assert(balanced("()()()") == false)
	assert(balanced("(())()") == false)
	assert(balanced("()(()(())())") == false)
	assert(balanced("(()())(((((()())()))())())") == false)
	assert(balanced("()(()()()())") == false)
	assert(balanced("()(()(()())()())") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func balanced(s string) bool {
	for {
		t := strings.Replace(s, "(()())", "()", -1)
		if s == t {
			break
		}
		s = t
	}
	return s == "" || s == "()()"
}
