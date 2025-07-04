/*

Description
Every December my friends do a "Secret Santa" - the traditional gift exchange where everybody is randomly assigned to give a gift to a friend. To make things exciting, the matching is all random (you cannot pick your gift recipient) and nobody knows who got assigned to who until the day when the gifts are exchanged - hence, the "secret" in the name.

Since we're a big group with many couples and families, often a husband gets his wife as secret santa (or vice-versa), or a father is assigned to one of his children. This creates a series of issues:

If you have a younger kid and he/she is assigned to you, you might end up paying for your own gift and ruining the surprise.

When your significant other asks "who did you get for Secret Santa", you have to lie, hide gifts, etc.

The inevitable "this game is rigged!" commentary on the day of revelation.

To fix this, you must design a program that randomly assigns the Secret Santa gift exchange, but prevents people from the same family to be assigned to each other.

Input
A list of all Secret Santa participants. People who belong to the same family are listed in the same line separated by spaces. Thus, "Jeff Jerry" represents two people, Jeff and Jerry, who are family and should not be assigned to eachother.

Joe
Jeff Jerry
Johnson
Output
The list of Secret Santa assignments. As Secret Santa is a random assignment, output may vary.

Joe -> Jeff
Johnson -> Jerry
Jerry -> Joe
Jeff -> Johnson
But not Jeff -> Jerry or Jerry -> Jeff!

Challenge Input
Sean
Winnie
Brian Amy
Samir
Joe Bethany
Bruno Anna Matthew Lucas
Gabriel Martha Philip
Andre
Danielle
Leo Cinthia
Paula
Mary Jane
Anderson
Priscilla
Regis Julianna Arthur
Mark Marina
Alex Andrea

Bonus
The assignment list must avoid "closed loops" where smaller subgroups get assigned to each other, breaking the overall loop.

Joe -> Jeff
Jeff -> Joe # Closed loop of 2
Jerry -> Johnson
Johnson -> Jerry # Closed loop of 2

*/

package main

import (
	"fmt"
	"math/rand"
)

type Person struct {
	name   string
	family int
}

func main() {
	solve([]Person{
		{"Joe", 0},
		{"Jeff", 1},
		{"Jerry", 1},
		{"Johnson", 2},
	})

	solve([]Person{
		{"Sean", 0},
		{"Winnie", 1},
		{"Brian", 2},
		{"Amy", 2},
		{"Samir", 3},
		{"Joe", 4},
		{"Bethany", 4},
		{"Bruno", 5},
		{"Anna", 5},
		{"Matthew", 5},
		{"Lucas", 5},
		{"Gabriel", 6},
		{"Martha", 6},
		{"Philip", 6},
		{"Andre", 7},
		{"Danielle", 8},
		{"Leo", 9},
		{"Cinthia", 9},
		{"Paula", 10},
		{"Mary", 11},
		{"Jane", 11},
		{"Anderson", 12},
		{"Priscilla", 13},
		{"Regis", 14},
		{"Julianna", 14},
		{"Arthur", 14},
		{"Mark", 15},
		{"Marina", 15},
		{"Alex", 16},
		{"Andrea", 16},
	})
}

func solve(p []Person) {
	for {
		rand.Shuffle(len(p), func(i, j int) {
			p[i], p[j] = p[j], p[i]
		})
		if valid(p) {
			break
		}
	}
	show(p)
}

func valid(p []Person) bool {
	for i := range p {
		j := (i + 1) % len(p)
		if p[i].family == p[j].family {
			return false
		}
	}
	return true
}

// circo -Tpng file.dot > pic.png
func show(p []Person) {
	fmt.Printf("digraph {\n")
	for i := range p {
		j := (i + 1) % len(p)
		fmt.Printf("    %s_%d -> %s_%d\n", p[i].name, p[i].family, p[j].name, p[j].family)
	}
	fmt.Printf("}\n\n")
}
