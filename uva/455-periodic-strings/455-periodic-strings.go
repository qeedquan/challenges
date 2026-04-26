package main

func main() {
	assert(solve("abcabcabcabc") == 3)
	assert(solve("HoHoHo") == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) int {
	l := len(s)
	t := kmp(s)
	m := l - t - 1
	if m != 0 && l%m != 0 {
		return l
	}
	return m
}

func kmp(s string) int {
	n := len(s)
	p := make([]int, n)
	p[0] = -1
	j := -1
	for i := 1; i < n; i++ {
		for j >= 0 && j+1 < n && s[j+1] != s[i] {
			j = p[j]
		}
		if j+1 < n && s[j+1] == s[i] {
			j += 1
		}
		p[i] = j
	}
	return j
}
