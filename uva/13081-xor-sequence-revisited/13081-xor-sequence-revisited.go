package main

func main() {
	assert(solve(2, 4) == 0)
	assert(solve(2, 2) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(L, R uint64) uint64 {
	if R-L >= 2 {
		return 0
	}
	if L != R {
		return bool2(R%4 == 0)
	}

	ret := uint64(0)
	for i := uint64(1); i < 63; i++ {
		v := bit(i + 1)
		a := L/v*v + bit(i)
		odd := bool2(a <= L && L < a+bit(i) && (L-a)%2 == 0)
		if i == 0 {
			odd++
		}
		if odd%2 != 0 {
			ret |= bit(i)
		}
	}
	if (L+1)/2%2 == 0 {
		ret |= 1
	}
	return ret
}

func bit(x uint64) uint64 {
	return 1 << x
}

func bool2(x bool) uint64 {
	if x {
		return 1
	}
	return 0
}
