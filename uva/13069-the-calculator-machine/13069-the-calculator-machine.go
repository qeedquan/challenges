package main

func main() {
	assert(solve(0, 1024) == 11)
	assert(solve(5000, 0) == 1)
	assert(solve(9999, 6666) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x0, x1 int) int {
	q := []int{x0}
	u := map[int]int{x0: 1}
	for len(q) > 0 {
		v := q[0]
		q = q[1:]

		if u[x1] != 0 {
			break
		}

		x := (v + 1) % 10000
		if u[x] == 0 {
			u[x] = u[v] + 1
			q = append(q, x)
		}
		x = (v*2 + 10000) % 10000
		if u[x] == 0 {
			u[x] = u[v] + 1
			q = append(q, x)
		}
		x = (v / 3)
		if u[x] == 0 {
			u[x] = u[v] + 1
			q = append(q, x)
		}
	}
	return u[x1] - 1
}
