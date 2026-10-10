/*

The task
Given the set S=[1,2,3,4,5,6,7,8] and an integer 0≤N<2^|S|
Find the Nth subset.

Input/Output
N is given as an unsigned integer on stdin.
You must print the Nth subset in a format suitable for your language (this may include [1,2,3],{1,2,3},[1, 2, 3],1 2 3,1,2,3 etc.
for as long as it is a human readable text format).

A little bit about subsets
There is a relationship between subsets and numbers in base two. Each digit di specifies whether the ith element of the set is within
the subset. For example 00000000 would be the empty set and 10000001 is the subset containing [1,8] (the last and first element).
You get the Nth subset by converting the number into base 2 and then the subset includes all elements where
di>0.
The 3rd subset (3 = 00000011) thus contains [1,2].
The rightmost digit is digit #0. It's ok to print [2,1].
The set does not have to be sorted.

Addendums:

Yes, the set is fixed to 1..8. The set is not part of the input. Input is just N.

Yes, you may use alternate input forms.

All expected outputs for all N: https://tio.run/##SyotykktLixN/f/fyNS02qIoP8soJd1CwSAg2kY32LPWPaoqs7jg/38A

*/

package main

import "fmt"

func main() {
	for i := range 256 {
		fmt.Println(i, subset(i))
	}
}

func subset(n int) []int {
	r := []int{}
	for i := range 8 {
		if (n>>i)&1 != 0 {
			r = append(r, i+1)
		}
	}
	return r
}
