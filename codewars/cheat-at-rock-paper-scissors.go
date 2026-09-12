/*

You seem to have the worst luck at rock, paper, scissors! Everyday you play against your friends, but never win. You want a taste of victory!

In this kata you need to define r_p_s_cheat() that takes an argument, either 'rock', 'paper', or 'scissors' and returns your counter to win!

But there's a catch! Your friends know how terrible you are at rock, paper, scissors, and if you win all of the time, then they'll see through your deception!

You need r_p_s_cheat to win 88-92% of the time and lose 8-12% of the time! In other words, you should never tie!

Note: The testing will check to see that this condition is fulfilled!

If you believe your solution will work, but doesn't on the first try, submit again!

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	for range 20 {
		fmt.Println(sim(1e6))
	}
}

func sim(n int) float64 {
	m := [3]string{"rock", "paper", "scissor"}
	c := 0
	for range n {
		i := rand.Intn(len(m))
		if winner(rpscheat(m[i]), m[i]) == 1 {
			c += 1
		}
	}
	return float64(c) / float64(n)
}

func rpscheat(s string) string {
	m := map[string][2]string{
		"rock":    [2]string{"paper", "scissor"},
		"paper":   [2]string{"scissor", "rock"},
		"scissor": [2]string{"rock", "paper"},
	}

	p := 0.88 + rand.Float64()*0.04
	i := 1
	if rand.Float64() <= p {
		i = 0
	}
	return m[s][i]
}

func winner(s, t string) int {
	switch s {
	case "rock":
		switch t {
		case "scissor":
			return 1
		case "paper":
			return 2
		}
	case "paper":
		switch t {
		case "rock":
			return 1
		case "scissor":
			return 2
		}
	case "scissor":
		switch t {
		case "paper":
			return 1
		case "rock":
			return 2
		}
	}
	return 0
}
