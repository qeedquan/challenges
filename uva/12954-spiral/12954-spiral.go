package main

import "fmt"

func main() {
	fmt.Println(solve(8, 53))
	fmt.Println(solve(1073741824, 1152921504603393520))
}

func solve(N, B int64) (int64, int64) {
	if N%2 != 0 && B == N*N {
		return N/2 + 1, N/2 + 1
	}

	lo := int64(1)
	hi := N/2 + N%2
	for lo <= hi {
		mid := lo + (hi-lo)/2
		st := 4*N - 4
		ed := 4*(N-(mid-1)*2) - 4
		ss := (st + ed) * mid / 2
		if ss-ed+1 <= B && B <= ss {
			x := mid
			y := mid
			b := B - (ss - ed + 1)
			e := N - (mid-1)*2
			if b < e {
				return x, y + b
			}
			y += e - 1
			b -= e
			x += 1
			if b < e-1 {
				return x + b, y
			}
			x += e - 2
			b -= e - 1
			y -= 1
			if b < e-1 {
				return x, y - b
			}
			y -= e - 2
			b -= e - 1
			x -= 1
			return x - b, y
		}
		if ss < B {
			lo = mid + 1
		} else {
			hi = mid - 1
		}
	}
	return -1, -1
}
