package main

import "strconv"

func main() {
	assert(solve([]string{
		"10",
		"too high",
		"3",
		"too low",
		"4",
		"too high",
		"2",
		"right on",
	}) == "Stan is dishonest")

	assert(solve([]string{
		"5",
		"too low",
		"7",
		"too high",
		"6",
		"right on",
	}) == "Stan may be honest")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(responses []string) string {
	low, high, guess := 1, 10, 0
loop:
	for _, response := range responses {
		switch response {
		case "too high":
			high = min(high, guess-1)
		case "too low":
			low = max(low, guess+1)
		case "right on":
			break loop
		default:
			guess, _ = strconv.Atoi(response)
		}
	}
	if low <= guess && guess <= high {
		return "Stan may be honest"
	}
	return "Stan is dishonest"
}
