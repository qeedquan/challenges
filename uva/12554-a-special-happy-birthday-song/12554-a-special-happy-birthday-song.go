package main

import "fmt"

func main() {
	sing([]string{"Mom", "Dad", "Girlfriend"})
}

func sing(names []string) {
	if len(names) == 0 {
		return
	}

	n := 0
	for range len(names)/16 + 1 {
		for i := range 4 {
			fmt.Printf("%s: Happy\n", names[n])
			n = (n + 1) % len(names)
			fmt.Printf("%s: birthday\n", names[n])
			n = (n + 1) % len(names)
			fmt.Printf("%s: to\n", names[n])
			n = (n + 1) % len(names)
			if i == 2 {
				fmt.Printf("%s: Rujia\n", names[n])
			} else {
				fmt.Printf("%s: you\n", names[n])
			}
			n = (n + 1) % len(names)
		}
	}
}
