package main

import (
	"fmt"
	"math/bits"
	"strconv"
)

func main() {
	fmt.Println(solve(265))
	fmt.Println(solve(111))
	fmt.Println(solve(1234))
}

func solve(n uint64) (int, int) {
	n2, _ := strconv.ParseUint(fmt.Sprint(n), 16, 64)
	return bits.OnesCount64(n), bits.OnesCount64(n2)
}
