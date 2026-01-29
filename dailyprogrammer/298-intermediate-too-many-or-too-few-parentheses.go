/*

this challenge is about spotting where parentheses are unbalanced.

find the index in string where the first extra ) or ( parentheses is, or return the length of string if parentheses are balanced.

for flashiness, insert ** around any index that is found. (will bold in markdown)

inputs:

)(asdf)))
((((asdf)))
((((asdf))
(ab)((cd)(asdf)))
(ab)((cd)(asdf)())
(ab)(((cd)(asdf)
(ab)(((cd)(asdf
(ab)(((cd)(asdf)))))

outputs:

)(asdf)))
((((asdf)))
((((asdf))
(ab)((cd)(asdf)))
(ab)((cd)(asdf)())
(ab)(((cd)(asdf)
(ab)(((cd)(asdf NB. may argue it should be 1 left.
(ab)(((cd)(asdf)))))

*/

package main

import "fmt"

func main() {
	spot("")
	spot(")(asdf)))")
	spot("((((asdf)))")
	spot("((((asdf))")
	spot("(ab)((cd)(asdf)))")
	spot("(ab)((cd)(asdf)())")
	spot("(ab)(((cd)(asdf)")
	spot("(ab)(((cd)(asdf")
	spot("(ab)(((cd)(asdf)))))")
}

func spot(input string) {
	stack := make([]int, len(input)+1)
	depth := 0
	position := 0
	for index, symbol := range input {
		if symbol == '(' {
			depth += 1
			stack[depth] = index
		} else if symbol == ')' {
			if depth -= 1; depth < 0 {
				position = index
				break
			}
		}
	}

	switch {
	case depth == 0:
		fmt.Println(input)

	case depth < 0:
		fmt.Print(input[:position])
		fmt.Printf("\x1b[91m)\x1b[0m")
		fmt.Println(input[position+1:])

	default:
		index := stack[depth]
		fmt.Print(input[:index])
		fmt.Printf("\x1b[91m(\x1b[0m")
		fmt.Println(input[index+1:])
	}
}
