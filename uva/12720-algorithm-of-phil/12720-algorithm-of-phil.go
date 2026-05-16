package main

func main() {
	assert(solve("00000") == 0)
	assert(solve("0101101") == 106)
	assert(solve("100") == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) int {
	const mod = 1000000007

	v := 0
	n := len(s)
	q := n / 2
	p := q - 1
	r := 0
	for i, j := 0, n&1; i < n; i, j = i+1, j^1 {
		if j != 0 {
			if n-q > p {
				r = int(s[q] - '0')
				q += 1
			} else {
				r = int(s[p] - '0')
				p -= 1
			}
		} else {
			if s[p] > s[q] {
				r = int(s[p] - '0')
				p -= 1
			} else {
				r = int(s[q] - '0')
				q += 1
			}
		}
		v = ((v << 1) + r) % mod
	}
	return v
}
