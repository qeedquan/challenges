/*

Context
Consider the following sequence of integers:

2,10,12,16,17,18,19,...

Can you guess the next term? Well, it is 200. What about the next? It is 201... In case it hasn't become obvious to you, this is the sequence of positive integers whose name starts with a letter D in Portuguese.

Task
Given a positive integer n, decide if it belongs in the sequence or not. An algorithm to do so is given next to the Output section.

Input
A positive integer n, no greater than 999999999.

Output
A truthy/falsey value, representing whether or not the input belongs in the sequence. Truthy if it does, falsey if it doesn't. Truthy/falsey can't be switched for this challenge.

For 0<n<10^9, here's how to determine if n is part of the sequence. If 9<n, say ab are its two leading digits, so that if n=583, a=5 and b=8.
If n<10 then a=n. Let k be the number of digits of n, so that if n=583, k=3. n is in the sequence if any of these hold:

a=2 and k=1,3,4,6,7,9;
ab=10,12,16,17,18,19 and k=2,5,8
Please notice that standard loopholes are forbidden by default, in particular trivialising the challenge by using a language with a trivial numeric type.

(The rules above generalise trivially for n arbitrarily big but I capped the input for simplicity)

Test cases
Truthy
2
10
12
16
17
18
19
200
201
223
256
10000
10100
10456
10999
12000
12180
12220
16550
17990
18760
19000
200000
212231
256909
299999
10000000
10999999
12000000
12999999
16000000
16562345
16999999
17000000
17999999
18000000
18999999
19000000
19999999
200000000
200145235
200999999
201000000
245345153
299999999

Falsy
1
3
4
5
6
7
8
9
11
13
14
15
20
100
1000
1200
1600
1738
1854
1953
20000
21352
120000
160000
170000
180000
190000
20000000
100000000
120000000
160000000
170000000
180000000
190000000
999999999

This is code-golf so shortest submission in bytes, wins! If you liked this challenge, consider upvoting it! If you dislike this challenge, please give me your feedback. Happy golfing!

*/

package main

func main() {
	truthy := []uint{
		2, 10, 12, 16, 17, 18, 19, 200, 201, 223, 256, 10000, 10100,
		10456, 10999, 12000, 12180, 12220, 16550, 17990, 18760, 19000, 200000, 212231,
		256909, 299999, 10000000, 10999999, 12000000, 12999999, 16000000, 16562345, 16999999,
		17000000, 17999999, 18000000, 18999999, 19000000, 19999999, 200000000, 200145235, 200999999,
		201000000, 245345153, 299999999,
	}
	falsey := []uint{
		1, 3, 4, 5, 6, 7, 8, 9, 11, 13, 14, 15, 20, 100, 1000, 1200,
		1600, 1738, 1854, 1953, 20000, 21352, 120000, 160000, 170000,
		180000, 190000, 20000000, 100000000, 120000000, 160000000,
		170000000, 180000000, 190000000, 999999999,
	}

	for _, x := range truthy {
		assert(portuguese(x) == true)
	}

	for _, x := range falsey {
		assert(portuguese(x) == false)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

@xnor

f=lambda n:f(n/1000)if n>299else 988164>>n&1|n/200

An arithmetic solution. Chomps down n to a three-digit number by repeatedly removing the last 3 digits. Then, checks that the remaining three-digit number is one of [2,10,12,16,17,18,19], or is between 200 and 299.

The [2,10,12,16,17,18,19] is checked against the set bits of a binary number, 988164.

The 200≤n<300 check is simplified by making the ≥300 case never happen. We keep chomping groups of 3 digits if the number is at least 300 (rather than at least 1000), making the 300-999 case go to 0. This leaves us with a 200≤n check that we do simply as n/200.

You might wonder why the if/else isn't shortened to and/or as usual, but the output potentially being truthy or falsey doesn't play nicely here.

*/

func portuguese(n uint) bool {
	if n > 299 {
		return portuguese(n / 1000)
	}
	return ((988164>>n)&1)|(n/200) != 0
}
