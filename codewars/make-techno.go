/*

German music producer Herbert Von Klunkerkunt has been using the same formula to make industrial techno for over twenty years. Producing at 120 beats per minute, each 4-beat bar contains:

4 kick drum hits
8 hihat hits
2 clap hits

Write a programme that takes the number of minutes and returns the number of "kicks", "hihats" and "claps" Klunkerkunt will need to fill each bar of his new track with percussion in an array. The total number of kicks, hihats and claps should be rounded to the nearest integer.

function perc (3) {}
// should return ["360 kicks", "720 hihats", "180 claps"]

The function should return "invalid track time" if the number of minutes is:

less than 1
more than 100
not a number

function perc (0.22) {}
// should return "invalid track time"

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(perc(3))
	fmt.Println(perc(0.22))
}

func perc(mins float64) any {
	if mins < 1 || mins > 100 {
		return "invalid track time"
	}

	beats := (mins * 120) / 4
	return [3]string{
		fmt.Sprintf("%.0f kicks", math.Round(beats*4)),
		fmt.Sprintf("%.0f hihats", math.Round(beats*8)),
		fmt.Sprintf("%.0f claps", math.Round(beats*2)),
	}
}
