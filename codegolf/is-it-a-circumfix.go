/*

Introduction
We all know prefixes and suffixes. But there are other types of affixes that exist too. Such as circumfixes, a type of affix that has two parts, one of which is a prefix and another of which is a suffix. Figuring out whether some string is a prefix or a suffix of some other string is easy, but what about figuring out whether it might be a circumfix?

That is today's challenge - create a program or function which takes two strings as input, and determine whether the first is a circumfix of the second.

For the purposes of this challenge a string i1 is a circumfix of another string i2 if and only if there exists some non-empty string j which is a contiguous substring of i2 such that removing j from i2 results in i1, and j is neither a prefix nor a suffix of i2 (if it is, you don't have a circumfix, you just have a suffix or a prefix respectively).

For example, "fog" is a circumfix of "frog", because removing "r" from "frog" produces "fog".

When given valid input, your program either needs to output a single consistent value of your choice if the first input string is a circumfix of the second, and any other value if it is not, or vice versa. For example, you may decide have your program output 6 when the first string is a circumfix of the second, in which case any output except 6 is acceptable when it is not.

This is code-golf, so do make sure to golf your code.

Test cases
Format:
"String 1", "String 2" -> output
    comments about the test case - in all these test cases, the output will be true if string 1 is a circumfix or string 2 and false otherwise
"apply", "appreciably" -> true
    "app]reciab[ly"
"rake", "racket by the lake" -> true
    multiple options - "r]acket by the l[ake" and "ra]cket by the la[ke"
"trout", "trumpet" -> false
    Doesn't work at all
"bring", "brought him a gong" -> false
    You only get to remove one substring - "br]ought h[i]m a go[ng" is not allowed
"falcon", "false conundrum" -> false
    You can't have extra stuff at the start or end either - "fal]se [con(undrum)" is not allowed
"goose", "goosebumps" -> false
    "goose]bumps[" is just a prefix
"lame", "blame" -> false
    And "]b[lame" is just a suffix
"pale", "pale ale" -> true
    "pale] ale[" is just a prefix, but "pal]e al[e" is a circumfix, so this is allowed
"b", "barb" -> false
    This could be a prefix ("b]arb[") or a suffix ("]bar[b"), but not a circumfix - "b]ar[b" is not allowed
"abba", "aba" -> false
    "abba" can be split into a prefix of "aba" ("ab") and a suffix of "aba" ("ba"), but "abba" is still not a circumfix of "aba"
"friend", "friend" -> false
    It's only a proper circumfix if you actually remove something - "fri][end" doesn't make the cut
"float", "on" -> false
    You may not assume the first input will be shorter than the second one
"", "" -> false
    One or both input strings may be empty
"Twin Sister", "Twister" -> false
    Inputs are ordered - you may reverse the order, but there must be a consistent ordering
"case", "Castle" -> false
    Inputs are case sensitive
"<<@ 23|>", "<<@23??|> 23|>" -> true
    "<<@]23??|>[ 23|>", not all characters will be letters)

*/

package main

func main() {
	assert(circumfix("fog", "frog") == true)
	assert(circumfix("apply", "appreciably") == true)
	assert(circumfix("rake", "racket by the lake") == true)
	assert(circumfix("trout", "trumpet") == false)
	assert(circumfix("bring", "brought him a gong") == false)
	assert(circumfix("falcon", "false conundrum") == false)
	assert(circumfix("goose", "goosebumps") == false)
	assert(circumfix("lame", "blame") == false)
	assert(circumfix("pale", "pale ale") == true)
	assert(circumfix("b", "barb") == false)
	assert(circumfix("abba", "aba") == false)
	assert(circumfix("friend", "friend") == false)
	assert(circumfix("float", "on") == false)
	assert(circumfix("", "") == false)
	assert(circumfix("Twin Sister", "Twister") == false)
	assert(circumfix("case", "Castle") == false)
	assert(circumfix("<<@ 23|>", "<<@23??|> 23|>") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func circumfix(a, b string) bool {
	n, m := len(a), len(b)
	for i := 1; i < n; i++ {
		x := min(i, m)
		y := max(m-n+i, 0)
		if a == b[:x]+b[y:] {
			return n < m
		}
	}
	return false
}
