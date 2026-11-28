/*

You work in the best consumer electronics corporation, and your boss wants to find out which three products generate the most revenue. Given 3 lists of the same length like these:

products: ["Computer", "Cell Phones", "Vacuum Cleaner"]
amounts: [3, 24, 8]
prices: [199, 299, 399]
return the three product names with the highest revenue (amount * price).

Note: if multiple products have the same revenue, order them according to their original positions in the input list.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(
		[]string{"Computer", "Cell Phones", "Vacuum Cleaner"},
		[]int{3, 24, 8},
		[]int{199, 299, 399},
		[]string{"Cell Phones", "Vacuum Cleaner", "Computer"},
	)

	test(
		[]string{"Cell Phones", "Vacuum Cleaner", "Computer", "Autos", "Gold", "Fishing Rods", "Lego", " Speakers"},
		[]int{5, 25, 2, 7, 10, 3, 2, 24},
		[]int{51, 225, 22, 47, 510, 83, 82, 124},
		[]string{"Vacuum Cleaner", "Gold", " Speakers"},
	)

	test(
		[]string{"Cell Phones", "Vacuum Cleaner", "Computer", "Autos", "Gold", "Fishing Rods", "Lego", " Speakers"},
		[]int{0, 12, 24, 17, 19, 23, 120, 8},
		[]int{9, 24, 29, 31, 51, 8, 120, 14},
		[]string{"Lego", "Gold", "Computer"},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(products []string, amounts, prices []int, expected []string) {
	result := top3(products, amounts, prices)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func top3(products []string, amounts, prices []int) []string {
	revenue := make([][2]int, len(amounts))
	for i := range revenue {
		revenue[i][0] = i
		revenue[i][1] = amounts[i] * prices[i]
	}
	sort.SliceStable(revenue, func(i, j int) bool {
		return revenue[i][1] > revenue[j][1]
	})

	if len(revenue) >= 3 {
		revenue = revenue[:3]
	}

	result := []string{}
	for i := range revenue {
		result = append(result, products[revenue[i][0]])
	}
	return result
}
