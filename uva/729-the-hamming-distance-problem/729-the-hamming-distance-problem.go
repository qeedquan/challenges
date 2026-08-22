package main

import "fmt"

func main() {
	solve(4, 2)
	solve(0, 0)
	solve(10, 1)
}

func solve(n, m int) {
	dfs(make([]byte, n), n, n, m)
	fmt.Println()
}

func dfs(s []byte, i, n, m int) {
	if m > i || m < 0 {
		return
	}
	if i == 0 {
		fmt.Printf("%s\n", s)
		return
	}

	s[n-i] = '0'
	dfs(s, i-1, n, m)

	s[n-i] = '1'
	dfs(s, i-1, n, m-1)
}
