/*

What is your favourite day of the week? Check if it's the most frequent day of the week in the year.

You are given a year as integer (e. g. 2001). You should return the most frequent day(s) of the week in that year. The result has to be a list of days sorted by the order of days in week (e. g. ['Monday', 'Tuesday'], ['Saturday', 'Sunday'], ['Monday', 'Sunday']). Week starts with Monday.

Input: Year as an int.

Output: The list of most frequent days sorted by the order of days in week (from Monday to Sunday).

Preconditions:

Week starts on Monday.
Year is between 1583 and 4000.
Calendar is Gregorian.
Examples (input -> output):
* 2427 -> ['Friday']
* 2185 -> ['Saturday']
* 2860 -> ['Thursday', 'Friday']

*/

package main

import (
	"fmt"
	"reflect"
	"time"
)

func main() {
	test(2427, []string{"Friday"})
	test(2185, []string{"Saturday"})
	test(2860, []string{"Thursday", "Friday"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(year int, expected []string) {
	days := frequent(year)
	fmt.Println(days)
	assert(reflect.DeepEqual(days, expected))
}

func frequent(year int) []string {
	count := [7]int{}
	date := time.Date(year, time.January, 1, 0, 0, 0, 0, time.UTC)
	maximum := 0
	for year == date.Year() {
		day := date.Weekday()
		count[day]++
		maximum = max(maximum, count[day])
		date = date.AddDate(0, 0, 1)
	}

	result := []string{}
	for day, value := range count {
		if value == maximum {
			result = append(result, time.Weekday(day).String())
		}
	}
	return result
}
