/*


A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.

*/

package main

func main() {
	assert(strobogrammatic("69") == true)
	assert(strobogrammatic("88") == true)
	assert(strobogrammatic("818") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A000787
func strobogrammatic(s string) bool {
	m := map[byte]byte{
		'0': '0',
		'1': '1',
		'8': '8',
		'6': '9',
		'9': '6',
	}

	for i, j := 0, len(s)-1; i <= j; i, j = i+1, j-1 {
		a, b := s[i], s[j]
		if !(m[a] != 0 && m[b] != 0 && m[a] == b) {
			return false
		}
	}
	return true
}
