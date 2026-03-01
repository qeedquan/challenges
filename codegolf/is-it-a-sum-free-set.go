/*

A set is sum-free if no two (not necessarily distinct) elements when added together are part of the set itself.

For example, {1, 5, 7} is sum-free, because all members are odd, and two odd numbers when added together are always even. On the other hand, {2, 4, 9, 13} is not sum-free, as either 2 + 2 = 4 or 4 + 9 = 13 add together to a member of the set.

Write a program or function that takes a set as input, and outputs a Truthy value if the set is sum-free, and Falsy otherwise.

Examples:

Sum-free:
{}
{4}
{1, 5, 7}
{16, 1, 4, 9}

Not sum-free:
{0}
{1, 4, 5, 7}
{3, 0}
{16, 1, 4, 8}

*/

package main

func main() {
	assert(sumfree(map[int]bool{}) == true)
	assert(sumfree(map[int]bool{4: true}) == true)
	assert(sumfree(map[int]bool{1: true, 5: true, 7: true}) == true)
	assert(sumfree(map[int]bool{16: true, 1: true, 4: true, 9: true}) == true)

	assert(sumfree(map[int]bool{0: true}) == false)
	assert(sumfree(map[int]bool{1: true, 4: true, 5: true, 7: true}) == false)
	assert(sumfree(map[int]bool{3: true, 0: true}) == false)
	assert(sumfree(map[int]bool{16: true, 1: true, 4: true, 8: true}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sumfree(m map[int]bool) bool {
	for a := range m {
		for b := range m {
			if m[a+b] {
				return false
			}
		}
	}
	return true
}
