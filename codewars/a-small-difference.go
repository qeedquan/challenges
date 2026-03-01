/*

Write a function that given two strings determines if they differ by exactly one character.

The difference may consist of one charater being added, removed or replaced, in which case the function must return true. In all other cases it must return false.

Examples:

tower / towe -> true
tower / towner -> true
tower / bower -> true
tower / token -> false
tower / tower -> false

*/

package main

func main() {
	assert(ocd("tower", "towe") == true)
	assert(ocd("tower", "towner") == true)
	assert(ocd("tower", "bower") == true)
	assert(ocd("tower", "token") == false)
	assert(ocd("tower", "tower") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ocd(s1, s2 string) bool {
	n1, n2 := len(s1), len(s2)
	if n1 < n2 {
		s1, s2 = s2, s1
		n1, n2 = n2, n1
	}

	switch {
	case n1-n2 > 1:
		return false
	case n1 == n2:
		return cmp1(s1, s2)
	}
	return cmp2(s1, s2, n1, n2)
}

func cmp1(s1, s2 string) bool {
	d := 0
	for i := 0; i < len(s1) && d < 2; i++ {
		if s1[i] != s2[i] {
			d++
		}
	}
	return d == 1
}

func cmp2(s1, s2 string, n1, n2 int) bool {
	for i, j, d := 0, 0, 0; i < n1 && j < n2; {
		if s1[i] != s2[j] {
			d, i = d+1, i+1
		} else {
			i, j = i+1, j+1
		}
		if d > 1 {
			return false
		}
	}
	return true
}
