package main

func main() {
	assert(solve(7, []int{200000, 500000}) == 100000)
	assert(solve(6, []int{120, 2680, 3400, 200}) == 1700)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(m int, a []int) int {
	lo := 1
	hi := 0
	for _, val := range a {
		hi = max(hi, val)
	}

	ret := hi
	for lo <= hi {
		mid := lo + (hi-lo)/2
		box := 0
		for _, val := range a {
			box += val/mid + bool2(val%mid != 0)
		}
		if box <= m {
			hi = mid - 1
			ret = mid
		} else {
			lo = mid + 1
		}
	}
	return ret
}

func bool2(x bool) int {
	if x {
		return 1
	}
	return 0
}
