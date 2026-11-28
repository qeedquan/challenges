package main

import "fmt"

func main() {
	sim(7)
	sim(19)
	sim(10)
	sim(6)
	sim(0)
}

func sim(n int) {
	if n < 1 {
		return
	}

	q := []int{}
	for i := 1; i <= n; i++ {
		q = append(q, i)
	}

	fmt.Printf("Discarded cards:")
	for len(q) > 1 {
		fmt.Printf(" %d", q[0])
		q = q[1:]
		x := q[0]
		q = q[1:]
		if len(q) > 0 {
			fmt.Printf(",")
		}
		q = append(q, x)
	}
	fmt.Printf("\nRemaining cards: %d\n", q[0])
}
