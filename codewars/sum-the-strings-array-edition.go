/*

Create a function that takes 2 arrays of 5 string numbers each, and outputs the sum of the corresponding elements as strings as well.

  sumArr(['4','5','6','7','8'],['1','2','3','4','5']) // => ['5','7','9','11','13']
  sumArr(['34','5','200','17','6'],['27','24','14','90','16']) // => ['61','29','214','107','22']

If any input is an empty string, it should return the number that isn't just an empty string. If both corresponding elements are empty, output "0".

HINT: Remember Number()/parseInt() from https://www.codewars.com/kata/5966e33c4e686b508700002d

*/

package main

import (
	"fmt"
	"math/big"
	"reflect"
)

func main() {
	test(
		[]string{"4", "5", "6", "7", "8"}, []string{"1", "2", "3", "4", "5"},
		[]string{"5", "7", "9", "11", "13"},
	)

	test(
		[]string{"34", "5", "200", "17", "6"}, []string{"27", "24", "14", "90", "16"},
		[]string{"61", "29", "214", "107", "22"},
	)

	test(
		[]string{""}, []string{""},
		[]string{"0"},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, r []string) {
	c := sum(a, b)
	fmt.Println(c)
	assert(reflect.DeepEqual(c, r))
}

func sum(a, b []string) []string {
	n := max(len(a), len(b))
	m := min(len(a), len(b))
	x := new(big.Int)
	y := new(big.Int)
	r := make([]string, n)
	for i := range m {
		x.SetString(a[i], 10)
		y.SetString(b[i], 10)
		x.Add(x, y)
		r[i] = x.String()
	}
	return r
}
