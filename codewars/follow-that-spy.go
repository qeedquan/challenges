/*

We are diligently pursuing our elusive operative, Matthew Knight, who also goes by the alias Roy Miller.
He employs a nomadic lifestyle to evade detection, constantly moving from one location to another, with each of his journeys following a perplexing and non-standard sequence of itineraries.
Our mission is to decipher the routes he will undertake during each of his voyages.

Task
You've been provided with an array of itinerary routes, decipher the precise destinations he will visit in the correct sequence according to his meticulously planned itineraries.

Example
Based on the provided routes:

[ [USA, BRA], [JPN, PHL], [BRA, UAE], [UAE, JPN] ]
The correct sequence of destinations is:

"USA, BRA, UAE, JPN, PHL"
Note:

You can safely assume that there will be no duplicate locations with distinct routes.
All routes provided will have non-empty itineraries.
There will always be at least one (1) route connecting one waypoint to another.

*/

package main

import (
	"fmt"
	"reflect"
)

type Node struct {
	name       string
	prev, next *Node
}

func main() {
	test([][2]string{
		{"USA", "BRA"},
		{"JPN", "PHL"},
		{"BRA", "UAE"},
		{"UAE", "JPN"},
	}, []string{"USA", "BRA", "UAE", "JPN", "PHL"})

	test([][2]string{
		{"MNL", "TAG"},
		{"CEB", "TAC"},
		{"TAG", "CEB"},
		{"TAC", "BOR"},
	}, []string{"MNL", "TAG", "CEB", "TAC", "BOR"})

	test([][2]string{
		{"Chicago", "Winnipeg"},
		{"Halifax", "Montreal"},
		{"Montreal", "Toronto"},
		{"Toronto", "Chicago"},
		{"Winnipeg", "Seattle"},
	}, []string{"Halifax", "Montreal", "Toronto", "Chicago", "Winnipeg", "Seattle"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(routes [][2]string, expected []string) {
	result := findroutes(routes)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func findroutes(routes [][2]string) []string {
	paths := []string{}
	links := make(map[string]*Node)
	for _, route := range routes {
		node0 := links[route[0]]
		node1 := links[route[1]]

		if node0 == nil {
			node0 = &Node{name: route[0]}
		}
		if node1 == nil {
			node1 = &Node{name: route[1]}
		}

		node0.next = node1
		node1.prev = node0

		links[route[0]] = node0
		links[route[1]] = node1
	}

	var root *Node
	for _, node := range links {
		if node.prev == nil {
			root = node
			break
		}
	}

	for node := root; node != nil; node = node.next {
		paths = append(paths, node.name)
	}
	return paths
}
