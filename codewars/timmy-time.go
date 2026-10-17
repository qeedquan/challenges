/*

Write a function changeTime which increases or decreases given time. Input param is string in HH:MM format and delta is integer value -1 or 1 in minutes. Let see some examples:

changeTime('10:00', 1) //return '10:01'
changeTime('10:00', -1) //return '09:59'
changeTime('23:59', 1) //return '00:00'
changeTime('00:00', -1) //return '23:59'

*/

package main

import "fmt"

func main() {
	assert(changetime("10:00", 1) == "10:01")
	assert(changetime("10:00", -1) == "09:59")
	assert(changetime("23:59", 1) == "00:00")
	assert(changetime("00:00", -1) == "23:59")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func changetime(s string, d int) string {
	var h, m int
	n, _ := fmt.Sscanf(s, "%d:%d", &h, &m)
	if n != 2 {
		return ""
	}

	v := mod(h*60+m+d, 1440)
	return fmt.Sprintf("%02d:%02d", v/60, v%60)
}

func mod(x, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}
