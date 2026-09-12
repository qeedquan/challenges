/*

Petya, a young boy with a passion for programming in Pascal, has realized that he often uses too many variables in his programs.
This has made it difficult for him to keep track of the number of variables he uses in each program.

To help Petya with this task, you need to write a program that counts the variables for him.

Since Petya is still learning Pascal, he only uses four basic types: boolean, char, double, and integer.

Input
The input consists of several lines, each containing variable declarations.
Each line declares variables of a single type.
All declarations are syntactically correct according to Pascal rules, with unique variable names, and only the standard types are used: boolean, char, double, integer.

Formally, each declaration follows this format:

⟨ identifier ⟩ {',' ⟨ identifier ⟩} ':' ⟨ type ⟩ ';'

Here, ⟨ type ⟩ is one of the strings boolean, char, double, integer; ⟨ identifier ⟩ is a string made up of letters, digits, or the character '_', and it starts with a letter or the character '_'.

The strings ⟨ type ⟩ and ⟨ identifier ⟩, as well as the characters ':', ';' and ',' are indivisible elements.
There may be any number of spaces between these elements, as well as before and after them.

It is guaranteed that the input contains no more than 100 lines, each with no more than 20 variables, and each variable name is no longer than 1000 characters.

Output
The output should consist of four lines in the following format:

boolean: <number of declared boolean variables>

char: <number of declared char variables>

double: <number of declared double variables>

integer: <number of declared integer variables>

Ensure there is one space between the colon and the number of variables.

Examples
Input #1
i,  j, k : integer ;
flag: boolean;
length: integer;
  c1, c2: char;
  c3:     char;

Answer #1
boolean: 1
char: 3
double: 0
integer: 4

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	solve([]string{
		"i,  j, k : integer ;",
		"flag: boolean;",
		"length: integer;",
		"c1, c2: char;",
		"c3:     char;",
	})
}

func solve(declarations []string) {
	types := make(map[string]int)
	for _, declaration := range declarations {
		i := strings.IndexRune(declaration, ':')
		j := strings.IndexRune(declaration, ';')
		if i < 0 || j < 0 || i >= j {
			continue
		}
		vars := declaration[:i]
		kind := strings.TrimSpace(declaration[i+1 : j])
		types[kind] += len(strings.Split(vars, ","))
	}
	fmt.Println("boolean:", types["boolean"])
	fmt.Println("char:", types["char"])
	fmt.Println("double:", types["double"])
	fmt.Println("integer:", types["integer"])
}
