package main

import "fmt"

func main() {
	permute("2314")
	permute("abc")
	permute("bca")
	permute("dcba")
}

func permute(input string) {
	dfs(input, 0, "")
	fmt.Println()
}

func dfs(input string, index int, current string) {
	if len(current) >= len(input) {
		fmt.Println(current)
		return
	}

	for i := range len(current) + 1 {
		dfs(input, index+1, fmt.Sprintf("%s%c%s", current[:i], input[index], current[i:]))
	}
}
