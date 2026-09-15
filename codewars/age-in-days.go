/*

Did you ever want to know how many days old are you? Complete the function which returns your age in days. The birthday is given in the following order: year, month, day.

For example if today is 30 November 2015 then

ageInDays(2015, 11, 1) returns "You are 29 days old"

The birthday is expected to be in the past.

Suggestions on how to improve the kata are welcome!

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println(ageindays(2015, 11, 1))
}

func ageindays(year, month, day int) int {
	time1 := time.Now()
	time0 := time.Date(year, time.Month(month), day, 0, 0, 0, 0, time.UTC)
	delta := time1.Sub(time0)
	return int(delta.Hours() / 24)
}
