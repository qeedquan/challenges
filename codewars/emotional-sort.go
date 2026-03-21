/*

Emotional Sort ( ︶︿︶)
You'll have a function called "sortEmotions" that will return an array of emotions sorted. It has two parameters, the first parameter called "arr" will expect an array of emotions where an emotion will be one of the following:

:D -> Super Happy
:) -> Happy
:| -> Normal
:( -> Sad
T_T -> Super Sad
Example of the array:[ 'T_T', ':D', ':|', ':)', ':(' ]

And the second parameter is called "order", if this parameter is true then the order of the emotions will be descending (from Super Happy to Super Sad) if it's false then it will be ascending (from Super Sad to Super Happy)

Example if order is true with the above array: [ ':D', ':)', ':|', ':(', 'T_T' ]

Super Happy -> Happy -> Normal -> Sad -> Super Sad
If order is false: [ 'T_T', ':(', ':|', ':)', ':D' ]

Super Sad -> Sad -> Normal -> Happy -> Super Happy
Example:

arr = [':D', ':|', ':)', ':(', ':D']
sortEmotions(arr, true) // [ ':D', ':D', ':)', ':|', ':(' ]
sortEmotions(arr, false) // [ ':(', ':|', ':)', ':D', ':D' ]
More in test cases!

Notes:

The array could be empty, in that case return the same empty array ¯\_( ツ )_/¯
All emotions will be valid

Enjoy! (づ｡◕‿‿◕｡)づ

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	array := []string{":D", ":|", ":)", ":(", ":D"}
	fmt.Println(emosort(array, true))
	fmt.Println(emosort(array, false))
}

func emosort(array []string, order bool) []string {
	lut := map[string]int{
		":D":  1,
		":)":  2,
		":|":  3,
		":(":  4,
		"T_T": 5,
	}

	var cmp func(i, j int) bool
	if order {
		cmp = func(i, j int) bool { return lut[array[i]] < lut[array[j]] }
	} else {
		cmp = func(i, j int) bool { return lut[array[i]] > lut[array[j]] }
	}
	sort.Slice(array, cmp)

	return array
}
