/*

Evaluate the given string with the given conditons.

The conditions will be passed in an array and will be formatted like this:

{symbol or digit}{comparison operator}{symbol or digit}
Return the results in an array.

The characters in the conditions will always be in the string. Characters in the string are chosen from ascii letters + @#$%^&*()_{}[]

Example
input string: "aab#HcCcc##l#"
conditions: ["a<b", "#==4", "c>=C", "H!=a"]
The conditions in this example array can be interpreted as:

"a<b": The number of times "a" occurs in the string should be less than the number of times "b" occurs in the string
"#==4": "#" should occur exactly 4 times in the string
"c>=C": "c" should occur greater than or equal to the number of times "C" occurs
"H!=a": The number of times "H" occurs should not equal the number of times "a" occurs
In this example condition 1 is false and 2, 3, 4 are true. So the return value will be an array as such:

[False, True, True, True]

*/

package main

import (
	"fmt"
	"reflect"
	"strconv"
)

func main() {
	test("aab#HcCcc##l#", []string{"a<b", "#==4", "c>=C", "H!=a"}, []bool{false, true, true, true})
	test("abc#$%KDAyyaa@@@", []string{"#>@", "A==2", "a>A", "$!=2"}, []bool{false, false, true, true})
	test("abb", []string{"a>b", "b==a", "b<=a", "b>a", "b!=b", "a==1", "b==1"}, []bool{false, false, false, true, false, true, false})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(input string, conditions []string, expected []bool) {
	result := evaluation(input, conditions)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func evaluation(input string, conditions []string) []bool {
	count := make(map[rune]int)
	for _, symbol := range input {
		count[symbol] += 1
	}

	result := []bool{}
	for _, condition := range conditions {
		var lhs, op, rhs string
		lhs, condition = next(condition)
		op, condition = next(condition)
		rhs, condition = next(condition)
		result = append(result, logop(lhs, op, rhs, count))
	}
	return result
}

func next(input string) (string, string) {
	if len(input) == 0 {
		return "", ""
	}

	logicals := []string{"<=", "<", ">=", ">", "==", "!="}
	for _, logical := range logicals {
		if len(input) > len(logical) && input[:len(logical)] == logical {
			return logical, input[len(logical):]
		}
	}
	return input[:1], input[1:]
}

func logop(lhs, op, rhs string, count map[rune]int) bool {
	if len(lhs) == 0 || len(op) == 0 || len(rhs) == 0 {
		return false
	}

	rune0 := rune(lhs[0])
	rune1 := rune(rhs[0])
	value, err := strconv.Atoi(rhs)
	table := map[string][2]bool{
		"<=": [2]bool{count[rune0] <= value, count[rune0] <= count[rune1]},
		"<":  [2]bool{count[rune0] < value, count[rune0] < count[rune1]},
		">=": [2]bool{count[rune0] >= value, count[rune0] >= count[rune1]},
		">":  [2]bool{count[rune0] > value, count[rune0] > count[rune1]},
		"==": [2]bool{count[rune0] == value, count[rune0] == count[rune1]},
		"!=": [2]bool{count[rune0] != value, count[rune0] != count[rune1]},
	}
	if err == nil {
		return table[op][0]
	}
	return table[op][1]
}
