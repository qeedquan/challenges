/*

Playing the game of memory against a machine is highly unfair, because they play almost as good as small children. So let's make the machine play alone, but in a fair way:

Input: 1...26 pairs of lowercase letters in random order like zz or gttg or abcdefghiabcdefghi. You can trust each letter appears exactly twice and no other characters show up.
Lowercase letters represent unknown cards, uppercase letters are cards we already saw. Being a fair program, your code will not make knowledge of hidden cards.
With each turn, you are allowed to uncover a pair of cards (making them uppercase). Start to uncover cards at the left side and continue to the right. If the first card was seen before, pick the match. If not, continue with the next unknown card. If you uncover a pair, remove it.
Play the best you can: If you know an uppercase pair, uncover it. Otherwise never uncover a card you already know!
Output: The number of turns you needed to remove all cards. With the given strategy, this is fixed for a given input. Output as binary, ASCII number or length of output string, whatever you like best.
Goal: The shortest code wins, whatelse!

Let's illustrate this:

afzaxxzf | This is our input
AFzaxxzf | 1st turn, too bad: no pair
AFZAxxzf | 2nd turn was ZA, again no pair, but ...
 FZ xxzf | 3rd turn used to remove the AA pair
 FZ   zf | 4th turn uncovered XX, which can be immediately removed
 F     f | 5th turn started with z, so as second card we can pick the Z we already know
         | With the 6th turn we solved it, so output will be 6
Some more test data:

aa          --> 1
aabb        --> 2
abba        --> 3
ggijkikj    --> 6
qqwweerrtt  --> 5
cbxcxvbaav  --> 8
zyxzwyvxvw  --> 9
tbiaktyvnxcurczlgwmhjluoqpqkgspwsfidfedrzmhyeanxvboj --> 43
Hint:

You don't have to actually play memory, you don't need to actually turn anything uppercase! All that counts is the correct output with the lowest number of code bytes. Feel free to discover a hidden algorithm (but it's not as simple as it could appear on the first sight).

*/

package main

func main() {
	assert(turns("aa") == 1)
	assert(turns("aabb") == 2)
	assert(turns("abba") == 3)
	assert(turns("ggijkikj") == 6)
	assert(turns("qqwweerrtt") == 5)
	assert(turns("cbxcxvbaav") == 8)
	assert(turns("zyxzwyvxvw") == 9)
	assert(turns("tbiaktyvnxcurczlgwmhjluoqpqkgspwsfidfedrzmhyeanxvboj") == 43)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func turns(s string) int {
	m := make(map[byte]bool)
	n := len(s)
	r := 0
	for i := 0; i < n; r++ {
		var k0, k1 byte

		k0, i = s[i], i+1
		if m[k0] || i >= n {
			continue
		}

		k1 = s[i]
		if m[k1] {
			r++
		}
		m[k0], m[k1], i = true, true, i+1
	}
	return r
}
