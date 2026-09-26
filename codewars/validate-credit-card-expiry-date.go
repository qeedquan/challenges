/*

It is a simple, real world task. You will receive a single string as input. It will have the month (2 digits) and year(2 or 4 digits). These are separated by one character ("-" or "/", maybe some spaces too). For example:

02/21
02 / 21
02 / 2021
02-2021

Assume that all dates are in the XXI century.

Your task is to write a function that returns true or false if the expiry date is not in the past. Note, current month should still return true.

Good luck.

*/

package main

import (
	"fmt"
	"strings"
	"time"
)

func main() {
	fmt.Println(validate("02/21"))
	fmt.Println(validate("02 / 21"))
	fmt.Println(validate("02 / 2021"))
	fmt.Println(validate("02-2021"))
}

func validate(s string) bool {
	r := strings.NewReplacer(" ", "", "-", "/")
	s = r.Replace(s)

	t, err := time.Parse("01/06", s)
	if err != nil {
		t, err = time.Parse("01/2006", s)
	}
	if err != nil {
		return false
	}

	return t.Before(time.Now())
}
