/*

The Stern-Brocot sequence is much like the Fibonacci sequence and has some cool implications. Let's learn about it:

It starts with [1, 1] and adds two new terms every iteration: nextTerm which is the sum of a previous pair; and termAfterThat which is the second term of this previous pair. Here is how to find those terms:

[1, 1] + [nextTerm: 1 + 1 = 2; termAfterThat: 1] ==> [1, 1, 2, 1]
 ^  ^
Then you shift the pairs with one index in the sequence:

[1, 1, 2, 1] + [1 + 2, 2] ==> [1, 1, 2, 1, 3, 2]
    ^  ^
And so on... doing this for 2 more iterations will yield:

[1, 1, 2, 1, 3, 2, 3, 1, 4, 3]

Complete the code that takes a positive integer n, and returns the index of the first occurrence of n in the sequence. Note: indexing start at zero.

Examples
[1, 1, 2, 1, 3, 2, 3, 1, 4, 3, ...]
       ^     ^           ^
n = 2 ==> 2
n = 3 ==> 4
n = 4 ==> 8

*/

package main

func main() {
	tab := []int{
		0, 2, 4, 8, 10, 32, 18, 20, 34, 38, 36, 44, 42, 68, 72,
		92, 76, 74, 82, 188, 84, 140, 138, 152, 150, 146, 154,
		266, 148, 164, 172, 278, 274, 170, 282, 314, 276, 536,
		324, 296, 292, 578, 300, 308, 364, 332, 298, 566, 330,
		338, 552, 548, 562, 1274, 340, 584, 564, 614, 628,
	}

	for i := range tab {
		assert(sternbrocot(i+1) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A020950
func sternbrocot(n int) int {
	if n < 1 {
		return 0
	}

	s := []int{1, 1}
	i := 0
	for {
		if s[i] == n {
			return i
		}

		a := s[i] + s[i+1]
		b := s[i+1]
		i += 1
		s = append(s, a, b)
	}
}
