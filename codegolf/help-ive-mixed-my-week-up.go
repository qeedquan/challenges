/*

My dog ate my calendar, and now my days are all mixed up. I tried putting it back together, but I keep mixing up the days of the week! I need some help putting my calendar back together, with the days in the correct order.

And since I need my calendar put together as fast as possible, don't waste my time by sending me superfluous bytes. The fewer bytes I have to read, the better!

Input
The days of the week, in any order. Input can be taken as a list of strings, or a space separated string, or any reasonable way of representing 7 strings (one for each day of the week).

The strings themselves are all capitalized, as weekdays should be, so the exact strings are:

Monday
Tuesday
Wednesday
Thursday
Friday
Saturday
Sunday
Output
The days of the week, in sorted order (Monday - Sunday, because of course we adhere to ISO 8601). Output can be as a list of strings, or printed with some delimiter.

Disclaimer
Note that this is a kolmogorov-complexity challenge, with the added benefit of being able to use the input to shorten your code. You are not required to use the input if you don't want to. You are also free to use any approach, from a builtin datetime library to hard-coding the output.

Examples
To see example input and output, you can consult this python script.

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(daysort([]string{"Sunday", "Saturday", "Wednesday", "Friday", "Thursday", "Tuesday", "Monday"}))
}

func daysort(s []string) []string {
	tab := map[string]int{
		"Monday":    0,
		"Tuesday":   1,
		"Wednesday": 2,
		"Thursday":  3,
		"Friday":    4,
		"Saturday":  5,
		"Sunday":    6,
	}

	sort.Slice(s, func(i, j int) bool {
		return tab[s[i]] < tab[s[j]]
	})

	return s
}
