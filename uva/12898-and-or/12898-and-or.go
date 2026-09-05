package main

import "fmt"

func main() {
	fmt.Println(solve(1, 1))
	fmt.Println(solve(1, 2))

	N := int64(2000)
	for a := int64(1); a <= N; a++ {
		for b := a; b <= N; b++ {
			or1, and1 := solve(a, b)
			or2, and2 := solvebf(a, b)
			assert(or1 == or2 && and1 == and2)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(a, b int64) (or, and int64) {
	for i := range int64(63) {
		sb := f(b, i)
		sa := f(a-1, i)
		if sb-sa > 0 {
			or |= bit(i)
		}
		if sb-sa == b-a+1 {
			and |= bit(i)
		}
	}
	return
}

func solvebf(a, b int64) (or, and int64) {
	or, and = a, a
	for i := a; i <= b; i++ {
		or |= i
		and &= i
	}
	return
}

func f(u, i int64) int64 {
	l := (u >> (i + 1)) << i
	r := (u & ((1 << i) - 1))
	if (u>>i)&1 != 0 {
		return l + r + 1
	}
	return l
}

func bit(i int64) int64 {
	return 1 << i
}
