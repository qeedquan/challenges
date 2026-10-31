/*

This is the inverse of "Encode the date in Christmas Eve format."

Write a program that takes as input the string Christmas, possibly followed by  Eve between 1 and 365 times, and outputs the date encoded in YYYY-MM-DD format, or any format from which the year, month, and date can be easily obtained. Assume that the "Christmas" being referred to is the next Christmas, or today, if today is Christmas. Christmas is December 25.

Your program may also take the current date as input in the same format used for input, if there is no way to get it in the language you use.

Remember to take leap years into account.

Examples if run before on or Christmas 2023:
Input 	Output
Christmas 	2023-12-25
Christmas Eve 	2023-12-24
Christmas Eve Eve 	2023-12-23
Christmas Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve 	2023-11-15
"Christmas" + " Eve"*364

*/

package main

import (
	"fmt"
	"strings"
	"time"
)

func main() {
	fmt.Println(cefdec("Christmas"))
	fmt.Println(cefdec("Christmas Eve"))
	fmt.Println(cefdec("Christmas Eve Eve"))
	fmt.Println(cefdec("Christmas Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve Eve"))

	s := fmt.Sprintf("Christmas %v", strings.Repeat("Eve ", 364))
	s = s[:len(s)-1]
	fmt.Println(cefdec(s))
}

func cefdec(s string) string {
	const invalid = "invalid format"
	n := time.Now()
	t := time.Date(n.Year(), time.December, 25, 0, 0, 0, 0, time.UTC)
	for i, s := range strings.Split(s, " ") {
		switch {
		case i == 0:
			if s != "Christmas" {
				return invalid
			}
		default:
			if s != "Eve" {
				return invalid
			}
			t = t.AddDate(0, 0, -1)
		}
	}
	return t.Format("2006-01-02")
}
