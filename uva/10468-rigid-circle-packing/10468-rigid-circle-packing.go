package main

import "fmt"

func main() {
	fmt.Println(solve(0.00001))
	fmt.Println(solve(0.00002))
	fmt.Println(solve(0.00003))
}

func solve(r float64) (float64, float64) {
	const (
		NINE = 7.022509503430381
		TEN  = 7.519130890631598
	)
	return NINE * r, TEN * r
}
