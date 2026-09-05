/*

You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo"
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are:
"D" -> "B" -> "C" -> "A".
"B" -> "C" -> "A".
"C" -> "A".
"A".
Clearly the destination city is "A".
Example 3:

Input: paths = [["A","Z"]]
Output: "Z"


Constraints:

1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
All strings consist of lowercase and uppercase English letters and the space character.

*/

package main

func main() {
	assert(destination([][2]string{{"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}}) == "Sao Paulo")
	assert(destination([][2]string{{"B", "C"}, {"D", "B"}, {"C", "A"}}) == "A")
	assert(destination([][2]string{{"A", "Z"}}) == "Z")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func destination(paths [][2]string) string {
	cities := make(map[string][]string)
	for _, path := range paths {
		from, to := path[0], path[1]
		cities[from] = append(cities[from], to)
	}

	for _, path := range paths {
		to := path[1]
		if len(cities[to]) == 0 {
			return to
		}
	}
	return ""
}
