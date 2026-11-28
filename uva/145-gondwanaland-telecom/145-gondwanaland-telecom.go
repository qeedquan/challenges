package main

import "fmt"

func main() {
	schedule('A', "183-5724", 17, 58, 18, 4)
}

func schedule(step rune, number string, beghour, begmin, endhour, endmin int) {
	array := map[rune][3]int{
		'A': {10, 6, 2},
		'B': {25, 15, 5},
		'C': {53, 33, 13},
		'D': {87, 47, 17},
		'E': {144, 80, 30},
	}

	begin := beghour*60 + begmin
	end := endhour*60 + endmin
	if end <= begin {
		end += 24 * 60
	}

	a, b, c := 0, 0, 0
	for i := range 48 * 60 {
		if begin <= i && i < end {
			if i%(24*60) < 8*60 {
				c++
			} else if i%(24*60) < 18*60 {
				a++
			} else if i%(24*60) < 22*60 {
				b++
			} else {
				c++
			}
		}
	}
	sum := a*array[step][0] + b*array[step][1] + c*array[step][2]
	fmt.Printf("%10s %5d %5d %5d  %c %4d.%02d\n", number, a, b, c, step, sum/100, sum%100)
}
