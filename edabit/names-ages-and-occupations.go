/*

Write a function that maps a string into an array of name, string, and occupation pairs.

Examples
organize("John Mayer, 41, Singer, Emily Blunt, 36, Actor") ➞ [
  {:name=>"John Mayer", :age=>"41", :occupation=>"Singer"},
  {:name=>"Emily Blunt", :age=>"36", :occupation=>"Actor"}
]

organize("Conan O'Brien, 56, Talk Show Host, Anna Wintour, 69, Editor") ➞ [
  {:name=>"Conan O'Brien", :age=>"56", :occupation=>"Talk Show Host"},
  {:name=>"Anna Wintour", :age=>"69", :occupation=>"Editor"}
]

organize("") ➞ []
Notes
Return an empty array if given an empty string.

*/

package main

import (
	"fmt"
	"strconv"
	"strings"
)

type Person struct {
	name       string
	age        int
	occupation string
}

func main() {
	fmt.Println(organize("John Mayer, 41, Singer, Emily Blunt, 36, Actor"))
	fmt.Println(organize("Conan O'Brien, 56, Talk Show Host, Anna Wintour, 69, Editor"))
	fmt.Println(organize(""))
}

func organize(info string) []Person {
	var result []Person
	toks := strings.Split(info, ",")
	for i := 0; i+2 < len(toks); i += 3 {
		age, _ := strconv.Atoi(strings.TrimSpace(toks[i+1]))
		result = append(result, Person{
			name:       strings.TrimSpace(toks[i]),
			age:        age,
			occupation: strings.TrimSpace(toks[i+2]),
		})
	}
	return result
}
