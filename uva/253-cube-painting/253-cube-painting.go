package main

type Dice [6]byte

func main() {
	assert(solve("rbgggrrggbgr") == true)
	assert(solve("rrrbbbrrbbbr") == false)
	assert(solve("rbgrbgrrrrrg") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(s string) bool {
	if len(s) != 12 {
		return false
	}

	var a, b Dice
	copy(a[:], s[:6])
	copy(b[:], s[6:])

	return minexp(a) == minexp(b)
}

func minexp(x Dice) Dice {
	y := x
	for range 4 {
		for range 4 {
			x = shift(x, 2, 0, 3, 5)
			if cmp(y, x) > 0 {
				y = x
			}
		}

		for range 4 {
			x = shift(x, 0, 1, 5, 4)
			if cmp(y, x) > 0 {
				y = x
			}
		}

		x = shift(x, 1, 3, 4, 2)
		if cmp(y, x) > 0 {
			y = x
		}
	}
	return y
}

func shift(x Dice, i, j, k, l int) Dice {
	t := x[i]
	x[i] = x[j]
	x[j] = x[k]
	x[k] = x[l]
	x[l] = t
	return x
}

func cmp(x, y Dice) int {
	for i := range x {
		if x[i] != y[i] {
			return int(x[i]) - int(y[i])
		}
	}
	return 0
}
