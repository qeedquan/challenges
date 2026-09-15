/*

You live in a communal house. Each night, one room's residents are required to clean the dayroom. Your task is to make a random rota for the entire week.

Write a function that takes a list/array of the current occupied rooms in the house, and returns a list of 7 random rooms. If the number of occupied rooms is equal to or bigger than 7, duplicates are not allowed. If the number is less than 7, duplicates are allowed.

Examples:

rota(["One", "Two", "Three", "Four", "Five", "Six", "Seven"])

Would output

[ 'Three', 'Six', 'Four', 'Five', 'Two', 'One', 'Seven' ]

And rota(["One", "Two", "Three"]) would output

[ 'One', 'Three', 'Two', 'One', 'Two', 'Three', 'One' ]

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println(rota([]string{"One", "Two", "Three", "Four", "Five", "Six", "Seven"}))
	fmt.Println(rota([]string{"One", "Two", "Three"}))
}

func rota(rooms []string) []string {
	if len(rooms) == 0 {
		return []string{}
	}

	result := make([]string, 7)
	switch {
	case len(rooms) >= 7:
		copy(result, rooms[:7])
		rand.Shuffle(len(result), func(i, j int) {
			result[i], result[j] = result[j], result[i]
		})
	default:
		for i := range result {
			j := rand.Intn(len(rooms))
			result[i] = rooms[j]
		}
	}
	return result
}
