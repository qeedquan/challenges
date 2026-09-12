/*

Simulate the CSS directives font-weight: bolder; and font-weight: lighter; for a given inherited font weight.

Input
An integer 1 ≤ w ≤ 999, and a string s, either bolder or lighter.

Output
A new integer, as according to this table:

Inherited value
w	Output
if s = bolder	Output
if s = lighter
w < 100	400	w
100 ≤ w < 350	400	100
350 ≤ w < 550	700	100
550 ≤ w < 750	900	400
750 ≤ w < 900	900	700
900 ≤ w	w	700
In other words:

if s is bolder, your program produces w<350 ? 400 : w<550 ? 700 : w<900 ? 900 : w.
if s is lighter, your program produces w<100 ? w : w<550 ? 100 : w<750 ? 400 : 700.
This is code-golf: write the shortest program, scored in bytes.

Test cases
256 bolder -> 400
902 bolder -> 902
902 lighter -> 700
44 lighter -> 44
200 lighter -> 100
349 bolder -> 400
350 bolder -> 700
700 bolder -> 900
700 lighter -> 400
1 lighter -> 1
1 bolder -> 400
999 bolder -> 999
999 lighter -> 700

*/

package main

func main() {
	assert(enhance(256, "bolder") == 400)
	assert(enhance(902, "bolder") == 902)
	assert(enhance(902, "lighter") == 700)
	assert(enhance(44, "lighter") == 44)
	assert(enhance(200, "lighter") == 100)
	assert(enhance(349, "bolder") == 400)
	assert(enhance(350, "bolder") == 700)
	assert(enhance(700, "bolder") == 900)
	assert(enhance(700, "lighter") == 400)
	assert(enhance(1, "lighter") == 1)
	assert(enhance(1, "bolder") == 400)
	assert(enhance(999, "bolder") == 999)
	assert(enhance(999, "lighter") == 700)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func enhance(value int, operation string) int {
	bolder := []int{400, 400, 700, 900, 900, value}
	lighter := []int{value, 100, 100, 400, 700, 700}

	var table []int
	switch operation {
	case "bolder":
		table = bolder
	case "lighter":
		table = lighter
	default:
		return value
	}

	switch {
	case value < 100:
		return table[0]
	case value < 350:
		return table[1]
	case value < 550:
		return table[2]
	case value < 750:
		return table[3]
	case value < 900:
		return table[4]
	}
	return table[5]
}
