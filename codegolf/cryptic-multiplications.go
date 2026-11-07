/*

Given two non-negative integers e.g. 27, 96 their multiplication expression would be 27 x 96 = 2592.
If now each digits is replaced with a symbol, such that

two digits are replaced with the same symbol if and only if they are equal
we could get something like AB x CD = AECA or 0Q x 17 = 0Z10 or !> x @^ = !x@!.
(following this rule we can also get the original expression itself but we'd lose the meaning of the digits being numbers since they will become just placeholders).
We call such an expression a cryptic multiplication of {27, 96}.

Is clear that some information is lost and the process is not always reversible, indeed an AB x CD = AECA cryptic multiplication can be obtained from each of the following pairs

{27, 96} 27 x 96 = 2592
{28, 74} 28 x 74 = 2072
{68, 97} 68 x 97 = 6596
There is no other pair of numbers that yields AB x CD = AECA.
Hence 3 is the cryptic multiplication ambiguity of {27, 96}

Write a function or a program that given two non-negative integers prints their cryptic multiplication ambiguity.

Test cases
{0, 0} -> 2
{5, 1} -> 17
{11, 11} -> 1
{54, 17} -> 18
{10, 49} -> 56
{7, 173} -> 1
{245, 15} -> 27
{216, 999} -> 48
{1173, 72} -> 3

Mathematica reference program
https://tio.run/##fY/LasNADEX3/ooBgUmK0sm4i1DyQBATCBRaSneDA0MqP8CZBEcGg/G3uxPidRdC4iLOkS5OSr44qc5uHG9OhBuvturQ@rNUV2877PTrT9mw@7VgFjtIYgv47XzB9MG@kJIgy2JKuWbhtL3VgSR8p0P9gHnqsnWUB@L@2nqxk0HTPiz5UPazDYE9euGCm7QqKrlr6sEgJAjmBZIhRoBgoNnTSsfcwmZrsF/i@4C9WZ5msDBzDEPoQxZrmnDPAx84GOYZqsn@ry08s46inKhfJaiMWb0NSmv11VRexvEP
pattern = Function[x,x/.Thread[#1->#2&[#,Range@Length@#]]&@DeleteDuplicates@Flatten@x];
f = Count[pattern/@Catenate[Outer[IntegerDigits/@{#1,#2,#1*#2}&,##]&@@(Range@@If[#<=1,{0,9},{10^(#-1),10^#-1}]&/@IntegerLength/@{##})], pattern[IntegerDigits/@{#1,#2,#1*#2}]]&;

f@@{72, 1173} // Print

*/

package main

import (
	"fmt"
	"slices"
	"strings"
)

func main() {
	assert(cryptmul(0, 0) == 2)
	assert(cryptmul(5, 1) == 17)
	assert(cryptmul(0, 1) == 17)
	assert(cryptmul(11, 11) == 1)
	assert(cryptmul(54, 17) == 18)
	assert(cryptmul(10, 49) == 56)
	assert(cryptmul(7, 173) == 1)
	assert(cryptmul(245, 15) == 27)
	assert(cryptmul(216, 999) == 48)
	assert(cryptmul(1173, 72) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cryptmul(x, y int) int {
	r := 0
	t := location(x, y)
	for a := range (1 + x) << 4 {
		for b := range (1 + y) << 4 {
			if slices.Equal(location(a, b), t) {
				r += 1
			}
		}
	}
	return r
}

func location(x, y int) []int {
	r := []int{}
	s := fmt.Sprintf("%d,%d,%d", x, y, x*y)
	for _, c := range s {
		r = append(r, strings.IndexRune(s, c))
	}
	return r
}
