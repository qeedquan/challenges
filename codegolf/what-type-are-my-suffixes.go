/*

Intro
So I've been wasting my time again researching suffix sorting algorithms, evaluating new ideas by hand and in code. But I always struggle to remember the type of my suffixes! Can you tell me which type my suffixes are?

Left-most what?
A lot of suffix sorting algorithms (SAIS, KA, my own daware) group suffixes into different types in order to sort them. There are two basic types: S-type and L-type suffixes. S-type suffixes are suffixes that are lexicographically less (Smaller) than the following suffix and L-type if it is lexicographically greater (Larger). A left-most S-type (LMS-type) is just that: A S-type suffix that is preceeded by a L-type suffix.

The special thing about these LMS-type suffixes is that once we sorted them we can sorted all the other suffixes in linear time ! Isn't that awesome?

The challenge
Given a string assume it is terminated by a special character that is less than any other character in that string (e.g. smaller than even the null byte). Output a type corrosponding char for each suffix.

You can freely choose which char to use for which type but I'd prefer L, S and * for L-, S- and LMS-type as long as they are all printable (0x20 - 0x7E).

Example
Given the string mmiissiissiippi output (when using L, S and *):

 LL*SLL*SLL*SLLL
For example the first L is due to the fact that mmiissiissiippi$ is lexicographically greater than miissiissiippi$ (the $ represents the added minimal character):

L - mmiissiissiippi$ > miissiissiippi$
L - miissiissiippi$  > iissiissiippi$
* - iissiissiippi$   < issiissiippi     and preceeded by L
S - issiissiippi$    < ssiissiippi$
L - ssiissiippi$     > siissiippi$
L - siissiippi$      > iissiippi$
* - iissiippi$       < issiippi$        and preceeded by L
S - issiippi$        < ssiippi$
L - ssiippi$         > siippi$
L - siippi$          > iippi$
* - iippi$           < ippi$            and preceeded by L
S - ippi$            < ppi$
L - ppi$             > pi$
L - pi$              > i$
L - i$               > $
Some more examples:

"hello world" -> "L*SSL*L*LLL"
"Hello World" -> "SSSSL*SSLLL"
"53Ab§%5qS"   -> "L*SSL*SLL"
Goal
I'm not here to annoy Peter Cordes (I'm so gonna do this on stackoverflow sometime); I'm just very lazy so this is of course code-golf ! The shortest answer in bytes wins.

Edit: The order of the chars is given by their byte value. That means compare should be like C's strcmp.

Edit2: Like stated in the comments output should be a single character for each input character. While I assumed that would be understood as "return a string" it seems at least 1 answer returns a list of single characters. In order to not invalidate the existing answers I will allow you to return a list of single characters (or integers which when printed result in only 1 char).

Tips for linear time:
It can be done in 2 parallel forward iterations or in a single backward iteration.
The state of each suffix depends only on the first 2 chars and the type of the second.
Scanning the input in reverse direction you can determine L or S like this: $t=$c<=>$d?:$t (PHP 7), where $c is the current char $d the previous and $t the previous type.
See my PHP answer. Tomorrow I will award the bounty.

*/

package main

import (
	"strings"
)

func main() {
	assert(lms("mmiissiissiippi") == "LL*SLL*SLL*SLLL")
	assert(lms("hello world") == "L*SSL*L*LLL")
	assert(lms("Hello World") == "SSSSL*SSLLL")
	assert(lms(`53Ab§%5qS`) == "L*SSL*SLL")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@Anders Kaseorg

This uses recursion, stripping off one character at a time from the beginning of the string. (The Haskell string type is a singly-linked list of characters, so each of these steps is constant-time.)

For a string abc where a and b are single characters and c is any (possibly empty) string,
f(abc) = SLe, if f(bc) = Le and a < b;
f(abc) = L*e, if f(bc) = Se and a > b;
f(abc) = LLe, if f(bc) = Le and a ≥ b;
f(abc) = SSe, if f(bc) = Se and a ≤ b.
For a single-character string a, f(a) = L.

*/

func lms(s string) string {
	return process([]rune(s))
}

func process(r []rune) string {
	switch len(r) {
	case 0:
		return ""
	case 1:
		return "L"
	}

	p := process(r[1:])
	switch {
	case strings.HasPrefix(p, "L"):
		if r[0] < r[1] {
			p = "S" + p
		} else {
			p = "L" + p
		}
	case strings.HasPrefix(p, "S"):
		if r[0] <= r[1] {
			p = "S" + p
		} else {
			p = "L*" + p[1:]
		}
	}
	return p
}
