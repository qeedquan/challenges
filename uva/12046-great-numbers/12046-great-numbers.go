package main

func main() {
	assert(solve(1) == 6)
	assert(solve(2) == 10)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(n int) int {
	return dfs(n, 0, 0, 0, 0, 0, 0, make(map[[7]int]int))
}

func dfs(n, m2, m3, m4, m5, m6, mark int, memo map[[7]int]int) int {
	if n < 0 {
		return 0
	}

	if n == 0 {
		f := 1
		if mark&2 != 0 {
			f &= bool2(m2 == 0)
		}
		if mark&4 != 0 {
			f &= bool2(m3 == 0)
		}
		if mark&8 != 0 {
			f &= bool2(m4 == 0)
		}
		if mark&16 != 0 {
			f &= bool2(m5 == 0)
		}
		if mark&32 != 0 {
			f &= bool2(m6 == 0)
		}
		return f
	}

	key := [7]int{n, m2, m3, m4, m5, m6, mark}
	if ret, found := memo[key]; found {
		return ret
	}

	ret := 0
	for i := 1; i <= 6; i++ {
		t2 := (m2*10 + i) % 2
		t3 := (m3*10 + i) % 3
		t4 := (m4*10 + i) % 4
		t5 := (m5*10 + i) % 5
		t6 := (m6*10 + i) % 6
		ret += dfs(n-1, t2, t3, t4, t5, t6, mark|(1<<(i-1)), memo)
		ret %= 1000007
	}

	memo[key] = ret
	return ret
}

func bool2(x bool) int {
	if x {
		return 1
	}
	return 0
}
