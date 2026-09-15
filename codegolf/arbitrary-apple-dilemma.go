/*

I have encountered this type of puzzle, that usually involves apples, several times. It goes as follows:

    There is a certain number of apples in a basket. Ava takes a third of the apples. Bob takes a quarter of the apples that are left. Finally, Dennis takes one-sixth of the apples left. In the end, there are 10 leftover apples. How many apples were in the basket?

The answer to the above task is 24.

Task

Given a list of positive integers and an integer representing the apples left in the end, return the number of apples originally in the basket.

Specs

    The nth element of the list represents the 1k share of apples the nth person took in the apples left over.
    There will always exist one integer solution, but the step calculations might result in rational numbers
    This is code-golf, so the shortest answer wins.

Test cases

[3, 4, 6], 10    -> 24
[2], 14          -> 28
[6], 30          -> 36
[4, 3], 20       -> 40
[5, 8, 7], 9     -> 15
[2, 9, 4, 8], 7  -> 24

*/

package main

func main() {
	assert(apples([]int{3, 4, 6}, 10) == 24)
	assert(apples([]int{2}, 14) == 28)
	assert(apples([]int{6}, 30) == 36)
	assert(apples([]int{4, 3}, 20) == 40)
	assert(apples([]int{5, 8, 7}, 9) == 15)
	assert(apples([]int{2, 9, 4, 8}, 7) == 24)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func apples(a []int, n int) int {
	x, y := 1, 1
	for _, v := range a {
		x *= v
		y *= v - 1
	}
	return (n * x) / y
}
