/*

Create a function that returns a villain name based on the user's birthday. The birthday will be passed to the function as a valid Date object, so for simplicity, there's no need to worry about converting strings to dates.

The first name will come from the month, and the last name will come from the last digit of the date:

Month -> first name

January -> "The Evil"
February -> "The Vile"
March -> "The Cruel"
April -> "The Trashy"
May -> "The Despicable"
June -> "The Embarrassing"
July -> "The Disreputable"
August -> "The Atrocious"
September -> "The Twirling"
October -> "The Orange"
November -> "The Terrifying"
December -> "The Awkward"

Last digit of date -> last name

0 -> "Mustache"
1 -> "Pickle"
2 -> "Hood Ornament"
3 -> "Raisin"
4 -> "Recycling Bin"
5 -> "Potato"
6 -> "Tomato"
7 -> "House Cat"
8 -> "Teaspoon"
9 -> "Laundry Basket"

The returned value should be a string in the form of "First Name Last Name".

For example, a birthday of November 18 would return "The Terrifying Teaspoon"

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	assert(villain(date(time.November, 18)) == "The Terrifying Teaspoon")
	assert(villain(date(time.January, 1)) == "The Evil Pickle")
	assert(villain(date(time.February, 2)) == "The Vile Hood Ornament")
	assert(villain(date(time.December, 2)) == "The Awkward Hood Ornament")
	assert(villain(date(time.May, 3)) == "The Despicable Raisin")
	assert(villain(date(time.April, 21)) == "The Trashy Pickle")
	assert(villain(date(time.December, 17)) == "The Awkward House Cat")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func date(month time.Month, day int) time.Time {
	return time.Date(2000, month, day, 0, 0, 0, 0, time.UTC)
}

func villain(birthdate time.Time) string {
	first := []string{
		"Evil",
		"Vile",
		"Cruel",
		"Trashy",
		"Despicable",
		"Embarrassing",
		"Disreputable",
		"Atrocious",
		"Twirling",
		"Orange",
		"Terrifying",
		"Awkward",
	}
	second := []string{
		"Mustache",
		"Pickle",
		"Hood Ornament",
		"Raisin",
		"Recycling Bin",
		"Potato",
		"Tomato",
		"House Cat",
		"Teaspoon",
		"Laundry Basket",
	}
	month := birthdate.Month()
	day := birthdate.Day()
	return fmt.Sprintf("The %s %s", first[month-1], second[day%10])
}
