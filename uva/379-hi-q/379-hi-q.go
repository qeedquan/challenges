package main

func main() {
	assert(solve([]int{10, 12, 17, 19, 25}) == 51)
	assert(solve([]int{}) == 0)
	assert(solve([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33}) == 561)
	assert(solve([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33}) == 98)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(use []int) int {
	pegs := make([]int, 34)
	for _, i := range use {
		pegs[i] = 1
	}

	for try(pegs) {
	}

	tot := 0
	for i := 1; i <= 33; i++ {
		if pegs[i] != 0 {
			tot += i
		}
	}
	return tot
}

func try(pegs []int) bool {
	for i := 33; i >= 1; i-- {
		if pegs[i] != 0 {
			continue
		}

		d0, d1 := down(i), down(down(i))
		r0, r1 := right(i), right(right(i))
		l0, l1 := left(i), left(left(i))
		u0, u1 := up(i), up(up(i))

		if pegs[d0] != 0 && pegs[d1] != 0 {
			pegs[d0], pegs[d1], pegs[i] = 0, 0, 1
			return true
		}

		if pegs[r0] != 0 && pegs[r1] != 0 {
			pegs[r0], pegs[r1], pegs[i] = 0, 0, 1
			return true
		}

		if pegs[l0] != 0 && pegs[l1] != 0 {
			pegs[l0], pegs[l1], pegs[i] = 0, 0, 1
			return true
		}

		if pegs[u0] != 0 && pegs[u1] != 0 {
			pegs[u0], pegs[u1], pegs[i] = 0, 0, 1
			return true
		}
	}
	return false
}

func up(a int) int {
	switch {
	case a <= 3 || a == 7 || a == 8 || a == 12 || a == 13:
		return 0
	case a <= 6:
		return a - 3
	case a <= 11:
		return a - 5
	case a <= 27:
		return a - 7
	case a <= 30:
		return a - 5
	}
	return a - 3
}

func down(a int) int {
	switch {
	case a == 0 || a >= 31 || a == 21 || a == 22 || a == 26 || a == 27:
		return 0
	case a >= 28:
		return a + 3
	case a >= 23:
		return a + 5
	case a >= 7:
		return a + 7
	case a >= 4:
		return a + 5
	}
	return a + 3
}

func left(a int) int {
	switch {
	case a <= 1 || a == 4 || a == 7 || a == 14 || a == 21 || a == 28 || a == 31:
		return 0
	}
	return a - 1
}

func right(a int) int {
	switch {
	case a == 0 || a == 3 || a == 6 || a == 13 || a == 20 || a == 27 || a == 30 || a == 33:
		return 0
	}
	return a + 1
}
