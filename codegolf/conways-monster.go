/*

This challenge is in honor of mathematician John Conway who passed away April 11, 2020 due to COVID-19. He was famous for coming up with the Game of Life cellular automaton and many other mathematical contributions such as the surreal numbers and the monster group.

The advanced math of those topics is out scope for this programming challenge, though I strongly recommend people watch the various Numberphile videos about Conway. In one of those videos Conway says that he'd like to know why the monster group exists before he dies. It's unfortunately too late for that now but we can honor his memory in a very small way by exploring in code the strange number associated with the group.

Challenge
The monster group is the largest sporadic simple group in the branch of group theory in mathematics. But the only thing to know for this challenge is that its order, or number of elements it contains is:

808017424794512875886459904961710757005754368000000000
Your task is to write a program that outputs this number. However, to keep this from being trivial, your program may not contain any digits, 0 through 9. That is, your program may not contain any of the ten characters 0123456789.

Your output must be the precise digits of the number:

808017424794512875886459904961710757005754368000000000
or the digits with appropriate commas:

808,017,424,794,512,875,886,459,904,961,710,757,005,754,368,000,000,000
(Commas , are allowed in your code.)

Any usual output method is valid. No input should be required. The shortest program in bytes wins.

If it helps anyone the factorization of the number is:

2^46 * 3^20 * 5^9 * 7^6 * 11^2 * 13^3 * 17 * 19 * 23 * 29 * 31 * 41 * 47 * 59 * 71
(Factorization is not valid output.)

*/

package main

import (
	"math/big"
)

func main() {
	assert(monster().String() == "808017424794512875886459904961710757005754368000000000")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// ported from @dingledooper solution
func monster() *big.Int {
	const enc = "?G^dddrstuuuvwxxy{|~~~~"
	r := big.NewInt(1)
	for i := range enc {
		x := int64(enc[i])
		r.Mul(r, big.NewInt(x+x))
	}
	return r
}
