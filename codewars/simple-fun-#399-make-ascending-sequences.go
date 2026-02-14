/*

Task
You are given a positive integer n. We intend to make some ascending sequences according to the following rules:

Make a sequence of length 1: [ n ]

Or, insert a number to the left side of the sequence. But this number can not exceed half of the first number of the sequence.

Follow rule 2, continue insert number to the left side of the sequence.

Your task is to count the number of all possible sequences, and return it.

If you do not understand the task, please read the rewritten version below:

You are given a positive integer n. Your task is to count the number of such sequences:

It should be an ascending sequence;

It should end with number n.

Each number in the sequence should smaller or equals to the half of its right, except for the last number n.

We define that a sequence containing only a number n is a valid ascending sequence.

Examples
For n = 6, the output should be 6.

All sequences we made are:

[6]

insert a number to the left:

[1,6]
[2,6]
[3,6]

continue insert number:

[1,2,6]
[1,3,6]

There are 6 sequences in total.

For n = 10, the output should be 14.

All sequences we made are:

[10]

insert a number to the left:

[1,10]
[2,10]
[3,10]
[4,10]
[5,10]

continue insert number:

[1,2,10]
[1,3,10]
[1,4,10]
[2,4,10]
[1,5,10]
[2,5,10]

continue insert number:

[1,2,4,10]
[1,2,5,10]

There are 14 sequences in total.

Note
1 <= n <= 1000

3 fixed testcases

100 random testcases, testing for correctness of solution

All inputs are valid.

*/

package main

func main() {
	tab := []int{
		1, 1, 2, 2, 4, 4, 6, 6, 10, 10, 14, 14, 20, 20, 26, 26, 36, 36, 46, 46,
		60, 60, 74, 74, 94, 94, 114, 114, 140, 140, 166, 166, 202, 202, 238,
		238, 284, 284, 330, 330, 390, 390, 450, 450, 524, 524, 598, 598, 692,
		692, 786, 786, 900, 900, 1014, 1014, 1154, 1154, 1294, 1294,
	}

	for i := range tab {
		assert(seq(i) == tab[i])
	}

	assert(seq(6) == 6)
	assert(seq(10) == 14)
	assert(seq(1000) == 1981471878)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A018819
func seq(n int) int {
	if n < 0 {
		return 0
	}
	if n == 0 {
		return 1
	}
	r := []int{1}
	for i := range n {
		if (i+1)%2 != 0 {
			r = append(r, r[i])
		} else {
			r = append(r, r[(i+1)/2]+r[i])
		}
	}
	return r[len(r)-1]
}
