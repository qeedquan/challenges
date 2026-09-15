package main

import (
	"fmt"
	"time"
)

func main() {
	solve()
}

func solve() {
	date := time.Now()
	output := date.Format("January 02, 2006 Monday")
	fmt.Println(output)
}
