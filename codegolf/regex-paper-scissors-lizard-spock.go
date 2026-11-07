/*

Warm up: Regex, Paper, Scissors
This is the challenge I originally wanted to post, before realising that some very short solution exist. Nevertheless, it can be an interesting problem to think about in preparation for the actual challenge below.

Write three regexes R, P and S such that they match each other in a cyclic Rock, Paper, Scissors fashion. In particular, R matches S, S matches P and P matches R, but R doesn't match P, S doesn't match R and P doesn't match S. Here's a handy table:

Regex   Matches   Doesn't match
R       S         P
P       R         S
S       P         R
It doesn't matter what R, P and S do on any other inputs, including themselves.

Here, match just means that some (possibly empty) substring of the input is matched. The match does not need to cover the entire input.

The challenge: Regex, Paper, Scissors, Lizard, Spock
For this challenge, you'll solve a tougher version of the above problem, based on the RPS variant Rock, Paper, Scissors, Lizard, Spock (as popularised by The Big Bang Theory). In RPSLV, there are five different symbols, that beat each other in two cycles:

Rock → Scissors → Lizard → Paper → Spock → Rock
Rock → Lizard → Spock → Scissors → Paper → Rock
You should write five regexes R, P, S, L and V which mimic this structure when given to each other as input. Here is the corresponding table:

Regex   Matches   Doesn't match
R       L, S      V, P
L       V, P      S, R
V       S, R      P, L
S       P, L      R, V
P       R, V      L, S
Just to be clear, you should not match the string R, P, etc, but the other regexes. E.g. if your regex R is ^\w$ for example, then P and V have to match the string ^\w$, whereas S and L shouldn't.

Again, match just means that at least one (possibly empty) substring of the input is matched. The match does not need to cover the entire input. For example \b (word boundary) matches hello (at the beginning and at the end), but it doesn't match (^,^).

You may use any regex flavour, but please state the choice in your answer and, if possible, provide a link to an online tester for the chosen flavour. You may not use any regex features that let you invoke code in the flavour's host language (like the Perl flavour's e modifier).

Delimiters (like /regex/) are not included in the regex when given as input to another, and you cannot use modifiers that are outside of the regex. Some flavours still let you use modifiers with inline syntax like (?s).

Your score is the sum of the lengths of the five regexes in bytes. Lower is better.

It turns out to be a lot simpler to find a working solution to this problem than it may seem at first, but I hope that finding an optimal solution is quite tricky.

*/

package main

import (
	"regexp"
)

func main() {
	test(R, []string{L, S}, []string{V, P})
	test(L, []string{V, P}, []string{S, R})
	test(V, []string{S, R}, []string{P, L})
	test(S, []string{P, L}, []string{R, V})
	test(P, []string{R, V}, []string{L, S})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(p string, a, b []string) {
	re := regexp.MustCompile(p)
	for _, s := range a {
		assert(re.MatchString(s) == true)
	}
	for _, s := range b {
		assert(re.MatchString(s) == false)
	}
}

/*

@Business Cat

The idea here is to match characters at the end of other regexes which are reserved regex characters,
but stop being treated as such when inside a character class.

*/

const (
	R = `([*?]$)`
	P = `[)$]$+`
	S = `[+?]$.*`
	L = `[+$]$.?`
	V = `[*)]$`
)
