/*

Given an array of strings of the same letter type. Return a new array, which will differ in that the length of each element is equal to the average length of the elements of the previous array.

A few examples:

['u', 'y'] =>  ['u', 'y'] // average length is 1
['aa', 'bbb', 'cccc'] => ['aaa', 'bbb', 'ccc'] // average length is 3
['aa', 'bb', 'ddd', 'eee'] => ['aaa', 'bbb', 'ddd', 'eee'] // average length is 2.5 round up to 3

If the average length is not an integer, use Math.round().

The input array's length > 1

*/

package main

import (
	"fmt"
	"math"
	"reflect"
	"strings"
)

func main() {
	test([]string{"u", "y"}, []string{"u", "y"})
	test([]string{"aa", "bbb", "cccc"}, []string{"aaa", "bbb", "ccc"})
	test([]string{"aa", "bb", "ddd", "eee"}, []string{"aaa", "bbb", "ddd", "eee"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(array, expected []string) {
	result := averagelength(array)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func averagelength(array []string) []string {
	if len(array) == 0 {
		return []string{}
	}

	sum := 0
	for i := range array {
		sum += len(array[i])
	}
	length := int(math.Round(float64(sum) / float64(len(array))))

	result := []string{}
	for i := range array {
		char := ""
		if len(array[i]) > 0 {
			char = string(array[i][0])
		}
		result = append(result, strings.Repeat(char, length))
	}
	return result
}
