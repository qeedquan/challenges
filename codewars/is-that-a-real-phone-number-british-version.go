/*

Congratulations! That Special Someone has given you their phone number.

But WAIT, is it a valid number?

Your task is to write a function that verifies whether a given string contains a valid British mobile (cell) phone number or not.

If valid, return 'In with a chance'.

If invalid, or if you're given an empty string, return 'Plenty more fish in the sea'.

A number can be valid in the following ways:

Here in the UK mobile numbers begin with '07' followed by 9 other digits, e.g. '07454876120'.

Sometimes the number is preceded by the country code, the prefix '+44', which replaces the '0' in ‘07’, e.g. '+447454876120'.

And sometimes you will find numbers with dashes in-between digits or on either side, e.g. '+44--745---487-6120' or '-074-54-87-61-20-'. As you can see, dashes may be consecutive.

Good Luck Romeo/Juliette!

*/

package main

import (
	"regexp"
	"strings"
)

func main() {
	assert(validate("07454876120") == "In with a chance")
	assert(validate("0745-487-61-20") == "In with a chance")
	assert(validate("+447535514555") == "In with a chance")
	assert(validate("+447454876120") == "In with a chance")
	assert(validate("+44--745---487-6120") == "In with a chance")
	assert(validate("-074-54-87-61-20-") == "In with a chance")

	assert(validate("0754876120") == "Plenty more fish in the sea")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func validate(s string) string {
	re := regexp.MustCompile(`^(0|\+44)7\d{9}$`)
	s = strings.Replace(s, "-", "", -1)
	if re.MatchString(s) {
		return "In with a chance"
	}
	return "Plenty more fish in the sea"
}
