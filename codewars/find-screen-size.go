/*

Cheesy Cheeseman just got a new monitor! He is happy with it, but he just discovered that his old desktop wallpaper no longer fits. He wants to find a new wallpaper, but does not know which size wallpaper he should be looking for, and alas, he just threw out the new monitor's box. Luckily he remembers the width and the aspect ratio of the monitor from when Bob Mortimer sold it to him. Can you help Cheesy out?

The Challenge
Given an integer width and a string ratio written as WIDTH:HEIGHT, output the screen dimensions as a string written as WIDTHxHEIGHT.

Note: The calculated height should be represented as an integer. If the height is fractional, truncate it.

*/

package main

import "fmt"

func main() {
	assert(findScreenHeight(1024, "4:3") == "1024x768")
	assert(findScreenHeight(1280, "16:9") == "1280x720")
	assert(findScreenHeight(3840, "32:9") == "3840x1080")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func findScreenHeight(width int, ratio string) string {
	var coeff [2]int
	scanned, err := fmt.Sscanf(ratio, "%v:%v", &coeff[0], &coeff[1])
	if scanned != 2 || err != nil {
		return "invalid"
	}
	return fmt.Sprintf("%vx%v", width, (width/coeff[0])*coeff[1])
}
