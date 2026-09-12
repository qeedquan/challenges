package main

import "fmt"

func main() {
	save([]string{
		"donate 1000",
		"report",
		"donate 500",
		"report",
	})
}

func save(s []string) int {
	var u, v int
	for i := range s {
		n, err := fmt.Sscanf(s[i], "donate %d", &u)
		if n == 1 && err == nil {
			v += u
			continue
		}

		_, err = fmt.Sscanf(s[i], "report")
		if err == nil {
			fmt.Println(v)
		}
	}
	return v
}
