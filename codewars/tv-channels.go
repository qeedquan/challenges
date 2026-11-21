/*

Program channels into your TV's memory. An array with channels (strings) will be passed as an argument to the function redarr(). Sort the channels in an alphabetical order, remove duplicates and, finally, return an object where each channel (object's value) is assigned to a whole number (objects's key), starting with 0.

Examples:

var arr = ["BBC1", "BBC2", "MTV"];

redarr(arr) // returns {"0":"BBC1", "1":"BBC2", "2":"MTV"}

var arr = ["BBC1", "BBC1", "BBC2", "MTV"];

redarr(arr) // returns {"0":"BBC1", "1":"BBC2", "2":"MTV"}

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(redarr([]string{"BBC1", "BBC2", "MTV"}))
	fmt.Println(redarr([]string{"BBC1", "BBC1", "BBC2", "MTV"}))
}

func redarr(s []string) map[string]string {
	sort.Strings(s)

	m := make(map[string]string)
	for i, j, k := 0, 0, 0; i < len(s); i = j {
		j = i + 1
		for j < len(s) && s[i] == s[j] {
			j++
		}

		l := fmt.Sprint(k)
		k += 1
		m[l] = s[i]
	}
	return m
}
