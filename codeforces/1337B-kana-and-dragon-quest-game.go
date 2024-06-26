/*

Kana was just an ordinary high school girl before a talent scout discovered her. Then, she became an idol. But different from the stereotype, she is also a gameholic.

One day Kana gets interested in a new adventure game called Dragon Quest. In this game, her quest is to beat a dragon.

The dragon has a hit point of x initially. When its hit point goes to 0 or under 0, it will be defeated. In order to defeat the dragon, Kana can cast the two following types of spells.

Void Absorption
Assume that the dragon's current hit point is h, after casting this spell its hit point will become ⌊h2⌋+10. Here ⌊h2⌋ denotes h divided by two, rounded down.

Lightning Strike
This spell will decrease the dragon's hit point by 10. Assume that the dragon's current hit point is h, after casting this spell its hit point will be lowered to h-10.

Due to some reasons Kana can only cast no more than n Void Absorptions and m Lightning Strikes. She can cast the spells in any order and doesn't have to cast all the spells. Kana isn't good at math, so you are going to help her to find out whether it is possible to defeat the dragon.

Input
The first line contains a single integer t (1≤t≤1000)  - the number of test cases.

The next t lines describe test cases. For each test case the only line contains three integers x, n, m (1≤x≤105, 0≤n,m≤30)  - the dragon's intitial hit point, the maximum number of Void Absorptions and Lightning Strikes Kana can cast respectively.

Output
If it is possible to defeat the dragon, print "YES" (without quotes). Otherwise, print "NO" (without quotes).

You can print each letter in any case (upper or lower).

Example

input
7
100 3 4
189 3 4
64 2 3
63 2 3
30 27 7
10 9 1
69117 21 2

output
YES
NO
NO
YES
YES
YES
YES

Note
One possible casting sequence of the first test case is shown below:

Void Absorption ⌊1002⌋+10=60.
Lightning Strike 60-10=50.
Void Absorption ⌊502⌋+10=35.
Void Absorption ⌊352⌋+10=27.
Lightning Strike 27-10=17.
Lightning Strike 17-10=7.
Lightning Strike 7-10=-3.

*/

package main

func main() {
	assert(beatable(100, 3, 4) == true)
	assert(beatable(189, 3, 4) == false)
	assert(beatable(64, 2, 3) == false)
	assert(beatable(30, 27, 7) == true)
	assert(beatable(10, 9, 1) == true)
	assert(beatable(69117, 21, 2) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func beatable(h, n, m int) bool {
	for ; n > 0; n-- {
		if 10*m >= h {
			break
		}
		h = h/2 + 10
	}
	return 10*m >= h
}
