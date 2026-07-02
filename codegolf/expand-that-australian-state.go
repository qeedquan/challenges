/*

There are 8 Australian states and territories, each with a 2 or 3 letter abbreviation:

ACT: Australian Capital Territory
NSW: New South Wales
NT: Northern Territory
QLD: Queensland
SA: South Australia
TAS: Tasmania
VIC: Victoria
WA: Western Australia
Your task is to write a function/program which takes a valid Australian state abbreviation in upper case, and returns the correct full name (case-sensitive as above).

No extra whitespace permitted, other than a single trailing newline where this is an unavoidable side-effect of every program in that language.

For example:

f("TAS") => "Tasmania"

Standard code-golf rules (shortest code in bytes wins!) and loopholes apply.

*/

package main

func main() {
	assert(expand("TAS") == "Tasmania")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func expand(code string) string {
	table := map[string]string{
		"ACT": "Australian Capital Territory",
		"NSW": "New South Wales",
		"QLD": "Queensland",
		"TAS": "Tasmania",
		"VIC": "Victoria",
		"NT":  "Northern Territory",
		"SA":  "South Australia",
		"WA":  "Western Australia",
	}
	return table[code]
}
