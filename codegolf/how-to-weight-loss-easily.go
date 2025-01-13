/*

In this question, we will only focus on losing weight by doing exercise, although there are still many ways to lose weight.

Different sports burn different amount of calories.

For example, playing billiards for an hour can burn 102 calories[1], while playing basketball for 15 minutes can already burn 119 calories [1], which make weight loss by playing basketball easier, at least from some perspectives.

The exact way to weigh the easiness is by dividing the amount of calories burnt by the time needed, which gives us the easiness index (EI).

For example, fencing for 15 minutes can burn 85 calories, which gets an EI of 85/15.

You will be given a list in this format:

[["fencing",15,85],["billiards",60,102],["basketball",15,119]]
or other format that you want.

Then, you will output the sports which have the highest EI.

TL;DR
Given a list of tuples [name,value1,value2] output the name where value2/value1 is the highest.

Constraints
You may not produce any real number that is not integer in the process.
You may not use any fraction built-in.
Specifications (Specs)
If there is more than one name that satisfy the result, you may output any non-empty subset of them or any element of them.
The name will match the regex /^[a-z]+$/, meaning that it will only consist of lowercase Latin standard alphabet.
The list will not be empty.

Testcase

Input:

[["fencing",15,85],["billiards",60,102],["basketball",15,119]]

Output:

basketball
References
http://calorielab.com/burned/

*/

package main

import (
	"math"
	"math/big"
)

func main() {
	assert(rank([]Activity{
		{"fencing", 15, 85},
		{"billiards", 60, 102},
		{"basketball", 15, 119},
	}) == "basketball")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func rank(a []Activity) string {
	s := ""
	r := big.NewRat(math.MinInt64, 1)
	for _, v := range a {
		t := big.NewRat(v.calories, v.time)
		if r.Cmp(t) < 0 {
			s = v.name
			r = t
		}
	}
	return s
}

type Activity struct {
	name     string
	time     int64
	calories int64
}
