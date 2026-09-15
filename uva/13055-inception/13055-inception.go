package main

import (
	"fmt"
	"strings"
)

func main() {
	solve([]string{
		"Sleep Dom",
		"Sleep Sakin",
		"Test",
		"Sleep Asif",
		"Sleep Mushfiq",
		"Test",
		"Kick",
		"Test",
		"Sleep Shafi",
		"Test",
		"Kick",
		"Test",
		"Kick",
		"Test",
		"Kick",
		"Test",
		"Kick",
		"Test",
		"Kick",
		"Test",
	})
}

func solve(commands []string) {
	path := []string{}
	for _, command := range commands {
		fields := strings.Split(command, " ")
		if len(fields) == 0 {
			continue
		}

		switch fields[0] {
		case "Sleep":
			if len(fields) >= 1 {
				path = append(path, fields[1])
			}

		case "Kick":
			if len(path) > 0 {
				path = path[:len(path)-1]
			}

		case "Test":
			if len(path) == 0 {
				fmt.Println("Not in a dream")
			} else {
				fmt.Println(path[len(path)-1])
			}
		}
	}
}
