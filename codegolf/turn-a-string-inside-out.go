/*

A balanced string is a string of parentheses () so that every parenthesis is can be matched with another one. More rigorously they are the strings spanned by this grammar:

S → (S)S | ε
We can turn a string "inside out" by:

Switching all occurrences of ( and ) with each other

Moving characters from the front of the string to the back until the string is balanced again.

Lets do an example.

We start with the balanced string:

(()(())())
We then switch the parens to make

))())(()((
Then move characters from the front of the string to the back of the string until the string is balanced.

))())(()((
)())(()(()
())(()(())
))(()(())(
)(()(())()
(()(())())
Thats our result!

Note that some strings can be turned inside out in multiple ways, for example the string

(()())
When turned inside out can be either:

()(())
or

(())()
However every string has at least one solution.

Task
Write a program to take a balanced string as input and output that string turned inside out. In cases where there may be multiple valid outputs you need only output one of them. You may use a different brace type (<>,[] or {}) if you so wish.

This is a code-golf competition so you should aim to minimize your size of your source code, as measured by bytes.

Test Cases
(()())     -> ()(()), (())()
(()(())()) -> (()(())())
((())())() -> (()(()()))

*/

package main

import (
	"bytes"
)

func main() {
	assert(evert("(()())") == "()(())")
	assert(evert("(()(())())") == "(()(())())")
	assert(evert("((())())()") == "(()(()()))")
	assert(evert("(()(())())") == "(()(())())")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@EinkornEnchanter

There is always a solution for any string that was initially balanced.
Let us begin by saying that balanced subsections can be moved to the end without harm, that is if our string is xy we can make it into yx.
This means that when rebalancing a string we can ignore subsections that are already balanced.
Thus any string is equivalent to a string matched by )*(*, however since our initial string was balanced we know the number of open and close parens is the same.
Thus we can just move all the close parens to the end of the string matching everything off.

*/

func evert(s string) string {
	p := complement(s)
	for i := 0; i < len(p); i++ {
		if balanced(p) {
			break
		}
		p = p[1:] + string(p[0])
	}
	return p
}

func complement(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		switch r {
		case '(':
			r = ')'
		case ')':
			r = '('
		}
		w.WriteRune(r)
	}
	return w.String()
}

func balanced(s string) bool {
	p := 0
	for _, r := range s {
		switch r {
		case '(':
			p++
		case ')':
			if p--; p < 0 {
				return false
			}
		}
	}
	return p == 0
}
