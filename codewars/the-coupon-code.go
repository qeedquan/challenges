/*

Story
Your online store likes to give out coupons for special occasions. Some customers try to cheat the system by entering invalid codes or using expired coupons.

Task
Your mission:
Write a function called checkCoupon which verifies that a coupon code is valid and not expired.

A coupon is no more valid on the day AFTER the expiration date. All dates will be passed as strings in this format: "MONTH DATE, YEAR".

Examples:
checkCoupon("123", "123", "July 9, 2015", "July 9, 2015")  ===  true
checkCoupon("123", "123", "July 9, 2015", "July 2, 2015")  ===  false

*/

package main

import (
	"time"
)

func main() {
	assert(checkCoupon("123", "123", "July 9, 2015", "July 9, 2015") == true)
	assert(checkCoupon("123", "123", "July 9, 2015", "July 2, 2015") == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func checkCoupon(enteredCode, correctCode, currentDate, expirationDate string) bool {
	time0, err0 := time.Parse("January 2, 2006", currentDate)
	time1, err1 := time.Parse("January 2, 2006", expirationDate)
	if err0 != nil || err1 != nil {
		return false
	}
	return enteredCode == correctCode && (time0.Before(time1) || time0.Equal(time1))
}
