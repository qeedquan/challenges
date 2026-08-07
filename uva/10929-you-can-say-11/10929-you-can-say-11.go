package main

import "fmt"

func main() {
	assert(multiple11("112233") == true)
	assert(multiple11("30800") == true)
	assert(multiple11("2937") == true)
	assert(multiple11("323455693") == true)
	assert(multiple11("5038297") == true)
	assert(multiple11("112234") == false)

	for i := range 1000000 {
		s := fmt.Sprint(i)
		if i%11 == 0 {
			assert(multiple11(s) == true)
		} else {
			assert(multiple11(s) == false)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func multiple11(s string) bool {
	n := len(s)
	r := 0
	for i := n - 1; i >= 0; i -= 2 {
		r += int(s[i] - '0')
	}
	for i := n - 2; i >= 0; i -= 2 {
		r -= int(s[i] - '0')
	}
	return r%11 == 0
}
