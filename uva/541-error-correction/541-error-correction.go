package main

import "fmt"

func main() {
	fmt.Println(solve([][]int{
		{1, 0, 1, 0},
		{0, 0, 0, 0},
		{1, 1, 1, 1},
		{0, 1, 0, 1},
	}))

	fmt.Println(solve([][]int{
		{1, 0, 1, 0},
		{0, 0, 1, 0},
		{1, 1, 1, 1},
		{0, 1, 0, 1},
	}))

	fmt.Println(solve([][]int{
		{1, 0, 1, 0},
		{0, 1, 1, 0},
		{1, 1, 1, 1},
		{0, 1, 0, 1},
	}))
}

func solve(A [][]int) string {
	n := len(A)
	C := make([]int, n)
	R := make([]int, n)
	for i := range n {
		for j := range n {
			C[i] += A[i][j]
			R[i] += A[j][i]
		}
	}

	ER := 0
	EC := 0
	IR := 0
	IC := 0
	for i := range n {
		if R[i]&1 != 0 {
			ER += 1
			IR = i
		}
		if C[i]&1 != 0 {
			EC += 1
			IC = i
		}
	}

	if ER == 0 && EC == 0 {
		return "OK"
	}
	if ER == 1 && EC == 1 {
		return fmt.Sprintf("Change bit (%d,%d)", IC+1, IR+1)
	}
	return "Corrupt"
}
