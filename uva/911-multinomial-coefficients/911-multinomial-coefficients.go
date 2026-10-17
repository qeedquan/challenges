package main

func main() {
	assert(multinomial(4, []int{1, 2, 1}) == 12)
	assert(multinomial(7, []int{2, 3, 0, 2}) == 210)
	assert(multinomial(3, []int{2, 0}) == 3)
	assert(multinomial(11, []int{1, 4, 4}) == 34650)
	assert(multinomial(4, []int{1, 2}) == 12)
	assert(multinomial(15, []int{5, 4, 3, 2}) == 37837800)
	assert(multinomial(15, []int{3, 3, 3, 3}) == 168168000)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func multinomial(n int, k []int) int {
	r := fact(n)
	for _, x := range k {
		r /= fact(x)
	}
	return r / fact(n-sum(k))
}

func fact(n int) int {
	if n < 0 {
		return 0
	}

	r := 1
	for i := 2; i <= n; i++ {
		r *= i
	}
	return r
}

func sum(a []int) int {
	r := 0
	for _, x := range a {
		r += x
	}
	return r
}
