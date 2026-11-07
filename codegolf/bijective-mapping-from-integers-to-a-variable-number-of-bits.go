/*

A variable number of bits is an array of 0 or more bits. So [0, 1] is a variable number of bits, but so is [].

Write a function or program that, given an nonnegative integer returns a variable number of bits such that every integer has a one-to-one (bijective) mapping with an array.

There are an infinite amount of such mappings, you are free to construct one as you please, but it must be one-to-one. Your mapping must conceptually be one-to-one for an arbitrarily sized integer, but it's OK if your implementation fails for large integers due to numerical limits of types in your preferred language (e.g. C's int).

As an example of what is not a one-to-one mapping, is simply listing the binary digits of the integer. In such a system 5 becomes [1, 0, 1] (or 0b101), but it's not one-to-one, because 0b0101 or [0, 1, 0, 1] also means 5.

It should be fairly obvious that a mapping is not one-to-one if it skips an integer (e.g. it doesn't work for 5), but I'd like to make it clear that skipping a variable bit array is also not one-to-one. You must map to every possible variable bit array, including [].

Shortest code in bytes wins.

*/

package main

import "fmt"

func main() {
	for i := 0; i < 16; i++ {
		fmt.Printf("%v: %q\n", i, i2b(i))
	}
}

/*

@xnor

Since any positive number starts with 1 in binary, this uniquely gives a binary representation.

*/

func i2b(n int) string {
	s := fmt.Sprintf("%b", -n-1)
	return s[2:]
}
