package main

import "fmt"

func main() {
	solve([]string{
		`"I like to solve"`,
		`I do not like to code`,
	})

	solve([]string{
		`yeah accepted`,
	})
}

func solve(lines []string) {
	fmt.Println("#include <string.h>")
	fmt.Println("#include <stdio.h>")
	fmt.Println("int main()")
	fmt.Println("{")
	for _, line := range lines {
		fmt.Printf("printf(\"")
		for _, ch := range line {
			if ch == '"' || ch == '\\' {
				fmt.Printf("\\")
			}
			fmt.Printf("%c", ch)
		}
		fmt.Println("\\n\");")
	}
	fmt.Println("printf(\"\\n\");")
	fmt.Println("return 0;")
	fmt.Println("}")
	fmt.Println()
}
