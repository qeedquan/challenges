/*

You have just boarded a train when your friend texts you to ask how long it will take your train to reach the stop where they're waiting for you.

Assuming that you know the distance in km and the train's average speed in km/h, let your friend know how long it will take the train to reach their stop, rounding the time to the nearest half hour.

As you are sending your reply via text, you should specify the time using numbers rather than words.

For example, given a distance of 80 km and an average speed of 20 km/h:

reachDestination(80, 20);

Your function should return:

'The train will be there in 4 hours.'

Hint: Keep in mind that the returned sentence needs to follow basic grammatical rules.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	assert(reach(5, 10) == "The train will be there in 0.5 hours.")
	assert(reach(80, 20) == "The train will be there in 4 hours.")
	assert(reach(80, 80) == "The train will be there in 1 hour.")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func reach(distance, speed int) string {
	time := float64(distance) / float64(speed)
	integral, fractional := math.Modf(time)

	var string0, string1, string2 string
	switch {
	case fractional < 0.25:
	case fractional < 0.75:
		string1 = ".5"
	default:
		integral += 1
	}
	string0 = fmt.Sprintf("%.0f", integral)
	if distance != speed {
		string2 = "s"
	}
	return fmt.Sprintf("The train will be there in %s%s hour%s.", string0, string1, string2)
}
