package main

func main() {
	assert(maxcost(
		[]int{2, 5, 3, 11, 1},
		[]string{"legal", "illegal", "legal", "illegal", "legal"},
		2,
	) == 10)

	assert(maxcost(
		[]int{1},
		[]string{"illegal"},
		1,
	) == 0)

	assert(maxcost(
		[]int{0, 3, 2, 3, 4},
		[]string{"legal", "legal", "illegal", "legal", "legal"},
		1,
	) == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func maxcost(cost []int, labels []string, dailycount int) int {
	var result, count, sum int
	for i := range cost {
		if labels[i] == "legal" {
			count++
		}

		sum += cost[i]
		if count == dailycount {
			result = max(result, sum)
			sum = 0
			count = 0
		}
	}
	return result
}
