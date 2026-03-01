/*

Introduction:
I think everyone knows what a Lava Lamp is, but in case they do not:

https://i.sstatic.net/dILgU.gif

They're basically glass tubes that contain wax in a translucent liquid. The bottom part is heated when the lamp is turned on, causing a change in density and thus the wax floats to the top. When it cools down, it falls down again, causing the effect we see above.

It usually takes about 45-60 minutes for the base of the lamp to rise in temperature high enough to change the solid wax to liquid wax (if the lamp is located in an area at room temperature).

More information on Wikipedia, which is also used as source for some of the text above.

Challenge:
Given a positive integer n indicating the amount of minutes that have passed since we've turned the Lava Lamp on, output a random state of the Lava Lamp based on integers on five levels.

For this challenge we'll say the Lava Lamp contains 1000 units of wax in total, and we have five levels where the wax can be at.

1) If n is below 45, the Lava Lamp is still heating up, so the output will be four empty lines with 1000 at the bottom:





1000
2) If n is in the range [45, 60) the Lava Lamp has increased in temperature enough for wax to move around, but no very high yet. The wax can reach up to and including the third level.
3) If n is 60 or higher, the wax can be at any of the five levels.

So given the positive integer n as input, we'll output a random state with the three rules above in mind.

Here are some example outputs:

Possible outputs for any n that is >= 45:



523
106
371


913

87
Possible outputs for any n that is >= 60:

73
113
312
5
497
284
55
637

24
Constant output for n that is <= 44 (and possible output for any n):





1000
Challenge rules:
There can be empty lines, even though the level above it is not empty.
Just 0 isn't allowed on any line. Should be empty instead.
Output is somewhat flexible. You are allowed to output a list/array of strings/objects instead of a new-line delimited result as above. The reason I say strings/objects is due to the rule above. An empty line should be "", null, [], etc., but cannot be 0 or a negative integer (nor can it be false) (I.e. ["", "", 913, "", 87] for n >= 45). You are also allowed to reverse the output (I.e. 1000\n\n\n\n instead of \n\n\n\n1000 or [87, null, 913, null, null] instead of [null, null, 913, null, 87]).
The numbers should all be integers. The can be decimals with 0 as decimal value, but none of the numbers should have any decimal digits, and the integers should always sum to exactly 1000.
All possible random outputs based on n should have a non-zero chance of occurring.
A trailing new-line (so there are six lines of output) is allowed.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, adding an explanation for your answer is highly recommended.

*/

package main

import (
	"fmt"
	"math/rand"
	"sort"
)

func main() {
	lava(34)
	lava(46)
	lava(75)
}

func lava(n int) {
	r := gen(n)
	output(r)
}

func gen(n int) [5]int {
	var (
		r [5]int
		x []int
		l int
	)
	switch {
	case n < 45:
		x = rng(1, 1000)
	case n < 60:
		x, l = rng(rand.Intn(3)+1, 1000), 3
	default:
		x, l = rng(rand.Intn(5)+1, 1000), 5
	}

	copy(r[:], x)
	rand.Shuffle(l, func(i, j int) {
		r[i], r[j] = r[j], r[i]
	})
	return r
}

func output(r [5]int) {
	for i := len(r) - 1; i >= 0; i-- {
		if r[i] != 0 {
			fmt.Printf("% 4d", r[i])
		} else {
			fmt.Printf("% 4s", " ")
		}
		fmt.Println()
	}
	fmt.Println("------\n")
}

// https://stackoverflow.com/questions/8064629/random-numbers-that-add-to-100-matlab/8064754#8064754
func rng(n, m int) []int {
	if n == 0 {
		return []int{}
	}

	r := make([]int, n+1)
	r[0] = 0
	r[1] = m
	for i := 2; i < len(r); i++ {
		r[i] = rand.Intn(m) + 1
	}
	sort.Ints(r)

	p := 0
	for i := range r {
		r[i], p = r[i]-p, r[i]
	}
	return r[1:]
}
