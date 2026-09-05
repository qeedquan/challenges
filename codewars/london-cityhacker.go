/*

You are given a sequence of a journey in London, UK. The sequence will contain bus numbers and TFL tube names as strings e.g.

['Northern', 'Central', 243, 1, 'Victoria']
Journeys will always only contain a combination of tube names and bus numbers. Each tube journey costs £2.40 and each bus journey costs £1.50. If there are 2 or more adjacent bus journeys, the bus fare is capped for sets of two adjacent buses and calculated as one bus fare for each set.

For example: 'Piccadilly', 56, 93, 243, 20, 14 -> "£6.90"

Your task is to calculate the total cost of the journey and return the cost rounded to 2 decimal places in the format (where x is a number): £x.xx

*/

package main

import "fmt"

func main() {
	assert(lch([]any{12, "Central", "Circle", 21}) == "£7.80")
	assert(lch([]any{"Piccadilly", 56}) == "£3.90")
	assert(lch([]any{"Northern", "Central", "Circle"}) == "£7.20")
	assert(lch([]any{"Piccadilly", 56, 93, 243}) == "£5.40")
	assert(lch([]any{386, 56, 1, 876}) == "£3.00")
	assert(lch([]any{}) == "£0.00")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func lch(a []any) string {
	r := 0.0
	for i := 0; i < len(a); i++ {
		switch a[i].(type) {
		case string:
			r += 2.4
		default:
			r += 1.5
			if i+1 < len(a) && isnumber(a[i+1]) {
				i++
			}
		}
	}
	return fmt.Sprintf("£%.2f", r)
}

func isnumber(x any) bool {
	switch x.(type) {
	case uint8, uint16, uint32, uint64,
		int8, int16, int32, int64,
		int, uint, uintptr, float32, float64:
		return true
	}
	return false
}
