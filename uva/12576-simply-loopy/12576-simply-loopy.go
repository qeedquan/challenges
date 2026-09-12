package main

func main() {
	assert(lol(5) == 5)
	assert(lol(6) == 40)
	assert(lol(7) == 175)
	for i := range int64(50) {
		assert(lol(i) == lolbf(i))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A040977 (related)
// f(x) = lol(x) / 5
func lol(n int64) int64 {
	M := int64(7477777)
	r := int64(0)
	for i := int64(1); i <= n-4; i++ {
		r = (sqr(i)*tetra(n-i-1) + r) % M
	}
	return (r * 5) % M
}

func lolbf(n int64) int64 {
	M := int64(7477777)
	r := int64(0)
	for i := int64(1); i <= n; i++ {
		for j := int64(1); j <= n; j++ {
			for k := int64(1); k <= n; k++ {
				for l := int64(1); l <= n; l++ {
					for m := int64(1); m <= n; m++ {
						if i+j+k+l+m == n {
							r = (r + i*i + j*j + k*k + l*l + m*m) % M
						}
					}
				}
			}
		}
	}
	return r
}

// https://oeis.org/A000290
func sqr(n int64) int64 {
	return n * n
}

// https://oeis.org/A000292
func tetra(n int64) int64 {
	return n * (n - 1) * (n - 2) / 6
}
