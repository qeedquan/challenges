/*

The input:

As an example, take a list containing a number of bits (in this case, 32):

11000010000100111011000011001011
We can calculate a simple checksum of this data by dividing it into evenly sized blocks, and taking the XOR of each of them. For example, with eight bit blocks:

11000010
00010011
10110000
11001011

10101010
We then append this to the end, making it 40 bits:

1100001000010011101100001100101110101010
This will be the form your input is given in.

To validate a checksum in this form, you just take the XOR of each block, including the checksum. If it's valid, it will result in a string of zeroes.

The challenge:

I've got a bunch of data with checksums. The problem is, I don't remember what the block size was! Your task is to write a program or function which takes input of any length, and returns all of the block sizes where the checksum is valid.

Blocks with sizes that do not fit evenly into the input should be ignored (so 7 would not be allowed in the output given 00000000). In the example above, the valid block sizes would be [1, 2, 4, 8], and the invalid ones would be [5, 10, 20].

Note that block sizes of one are possible (valid if the XOR of every bit in the string results in 0). A block the size of the entire string is not valid (so 8 would not be allowed in the output given 00000000), and blocks with sizes less than two do not need to be handled.

You can produce output and take input in any reasonable manner, such as lists of bits, strings of 0s and 1s, integers representing the binary values, etc.

This is code-golf, so shortest answer in bytes per language wins!

Test cases:

1100100001000000  ->  [1, 2, 4]
010010100100      ->  [1, 2, 3]
0000000000        ->  [1, 2, 5]
101101000         ->  [1, 3]
10010110          ->  [1, 2]
10000000          ->  []
0101010           ->  []
11                ->  [1]
1                 ->  (does not need to be handled)
                  ->  (does not need to be handled)

*/

package main

import (
	"bytes"
	"fmt"
	"slices"
)

func main() {
	test("1100100001000000", []int{1, 2, 4})
	test("010010100100", []int{1, 2, 3})
	test("0000000000", []int{1, 2, 5})
	test("101101000", []int{1, 3})
	test("10010110", []int{1, 2})
	test("10000000", []int{})
	test("0101010", []int{})
	test("11", []int{1})
	test("1", []int{})
	test("", []int{})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r []int) {
	b := blocksizes(s)
	fmt.Println(b)
	assert(slices.Equal(b, r))
}

func blocksizes(s string) []int {
	r := []int{}
	for i := 1; i < len(s); i++ {
		if check(s, i) {
			r = append(r, i)
		}
	}
	return r
}

func check(s string, b int) bool {
	n := len(s)
	if n%b != 0 {
		return false
	}

	x := s[:b]
	for i := 1; i < n/b; i++ {
		x = xor(x, s[i*b:(i+1)*b])
	}
	return allzeros(x)
}

func xor(s, t string) string {
	w := new(bytes.Buffer)
	n := min(len(s), len(t))
	for i := range n {
		if s[i] != t[i] {
			w.WriteByte('1')
		} else {
			w.WriteByte('0')
		}
	}
	return w.String()
}

func allzeros(s string) bool {
	for i := range s {
		if s[i] != '0' {
			return false
		}
	}
	return true
}
