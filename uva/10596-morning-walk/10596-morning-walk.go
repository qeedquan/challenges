package main

func main() {
	assert(solve(2, [][2]int{{0, 1}, {1, 0}}) == true)
	assert(solve(2, [][2]int{{0, 1}}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(intersections int, edges [][2]int) bool {
	degree := map[int]int{}
	for _, edge := range edges {
		degree[edge[0]] += 1
		degree[edge[1]] += 1
	}

	for i := range intersections {
		if degree[i]%2 != 0 || degree[i] == 0 {
			return false
		}
	}
	return true
}
