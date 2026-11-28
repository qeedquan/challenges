/*

Input
A dictionary with string keys and string values.

Output
The 'inversedict' of this dictionary.

How to make an inversedict
An inversedict is a dictionary with string keys and string array values. The keys are the values from the original dictionary, and the values are the keys from the original dictionary with that value from the original dictionary.

An example
Input
["Clyde": "blue", "Sarah": "blue", "Fred": "green"]
Output
["blue": ["Clyde", "Sarah"], "green": ["Fred"]]
This is code-golf, so shortest code in bytes wins!

*/

package main

import "fmt"

func main() {
	fmt.Println(inversedict(map[string]string{
		"Clyde": "blue",
		"Sarah": "blue",
		"Fred":  "green",
	}))
}

func inversedict(m map[string]string) map[string][]string {
	p := make(map[string][]string)
	for k, v := range m {
		p[v] = append(p[v], k)
	}
	return p
}
