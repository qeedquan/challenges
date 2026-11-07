/*

Task
In this kata you will be given a list consisting of unique elements except for one thing that appears twice.

Your task is to output a list of everything inbetween both occurrences of this element in the list.

Examples:
[0, 1, 2, 3, 4, 5, 6, 1, 7, 8] => [2, 3, 4, 5, 6]
["None", "Hello", "Example", "hello", "None", "Extra"] => ["Hello", "Example", "hello"]
[0, 0] => []
[true, false, true] => [false]
"example" => "xampl"

Notes
All elements will be the same datatype.
All used elements will be primitive.

*/

package main

import "fmt"

type Value interface {
	~int | ~string | ~bool | ~rune
}

func main() {
	fmt.Println(sandwich([]int{0, 1, 2, 3, 4, 5, 6, 1, 7, 8}))
	fmt.Println(sandwich([]string{"None", "Hello", "Example", "hello", "None", "Extra"}))
	fmt.Println(sandwich([]int{0, 0}))
	fmt.Println(sandwich([]bool{true, false, true}))
	fmt.Println(sandwich([]rune{'e', 'x', 'a', 'm', 'p', 'l', 'e'}))
}

func sandwich[T Value](a []T) []T {
	m := make(map[T]int)
	for i, v := range a {
		j, f := m[v]
		if f {
			return a[j+1 : i]
		}
		m[v] = i
	}
	return []T{}
}
