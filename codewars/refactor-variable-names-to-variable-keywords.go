/*

Information
Define the following 13 variables:
bool, char, sbyte, byte, short, ushort, int, uint, long, ulong, float, double, decimal

The type of each variable must be the same as the name.
The values don't matter.

Examples:
bool bool = false;
char char = '\0';
sbyte sbyte = 0;
...

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(refactor("bool x = false;"))
	fmt.Println(refactor(`char c = '\0';`))
	fmt.Println(refactor("sbyte y = 0;"))
}

func refactor(line string) string {
	tokens := strings.Split(line, " ")
	if len(tokens) >= 2 {
		tokens[1] = tokens[0]
	}
	return strings.Join(tokens, " ")
}
