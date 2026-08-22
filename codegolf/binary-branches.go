/*

Given a binary number, your task is to create a 'branch' of that number, with a depth of 2.

For example, given 0 as input, you should output exactly this:

     /000
  /00
 /   \001
0
 \   /010
  \01
     \011
This should be fairly self explanatory of how the branches should be created. Depth 2 means we calculate branches for numbers of up to 2 numbers longer. We also calculate the branches in order, with zeroes at the top and ones at the bottom.

More test cases:

0

     /000
  /00
 /   \001
0
 \   /010
  \01
     \011

1

     /100
  /10
 /   \101
1
 \   /110
  \11
     \111

00

       /0000
   /000
  /    \0001
00
  \    /0010
   \001
       \0011

01

       /0100
   /010
  /    \0101
01
  \    /0110
   \011
       \0111

10

       /1000
   /100
  /    \1001
10
  \    /1010
   \101
       \1011

11

       /1100
   /110
  /    \1101
11
  \    /1110
   \111
       \1111
Rules
You will never receive characters in the input other than 1 and 0.
0 < length of input < 11.
Trailing whitespace allowed at the end of lines.

*/

package main

import "fmt"

func main() {
	binarybranch("0")
	binarybranch("1")
	binarybranch("00")
	binarybranch("01")
	binarybranch("10")
	binarybranch("11")
	binarybranch("11111111111")
}

func binarybranch(s string) {
	n := len(s)
	fmt.Println(s)
	fmt.Printf(TREEFMT,
		n-1, " ", s,
		s,
		n-1, " ", s,
		s,
		n-1, " ", s,
		s,
		n-1, " ", s)
}

const TREEFMT = `
     %*.s/%s00
  /%s0
 /   %*.s\%s01
%s
 \   %*.s/%s10
  \%s1
     %*.s\%s11

`
