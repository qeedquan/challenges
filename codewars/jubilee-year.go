/*

A Jubilee Year is celebrated in Santiago de Compostela whenever July 25, the day of Santiago the Elder, falls on a Sunday.

For example, as of 2018 we know the last Jubilee year was 2010 and the next is going to be 2021.

Your task is to create the function isJubilee() that will tell us whether a given year was/is a Jubilee Year or not. For this kata, we're just interested in years from 1900 to 2099 (both included), so don't expect your function to receive any input out of that range.

Example:

  isJubilee(2020);  // <-- returns false  because 2020/07/25 is Saturday
  isJubilee(2021);  // <-- returns true   because 2021/07/25 is Sunday

*/

package main

import "time"

func main() {
	assert(isjubilee(2010) == true)
	assert(isjubilee(2012) == false)
	assert(isjubilee(2020) == false)
	assert(isjubilee(2021) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func isjubilee(year int) bool {
	date := time.Date(year, time.July, 25, 0, 0, 0, 0, time.UTC)
	return date.Weekday() == time.Sunday
}
