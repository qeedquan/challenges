/*

Back before I learned to code I played a lot of Fifa. One of the many things I've wasted a good portion of life on! Still, I just saw a TV advert announcing the release of the new version, so thought it deserved a kata in memory of the many happy hours.

You have placed bets on a series of football matches. Your ticket is represented by (ticket) and will look something like this:

Home:£74
Away:£36
Draw:£5

Each line is a seperate bet and will be a key:value pair within the ticket object. In each case you will always place a bet for a home win, an away win and a draw. You're weird like that. Each bet is for a different game.

Your will also be given an array of (results). Like this:

[3-0, 1-1, 0-2] <-- strings in array

There will always be the same number of result as there are bets on the ticket (3). In the results array, a higher number on the left side of the pair = Home win, higher on the right = Away win, equal = Draw. Like this:

3-0 = Home win
0-3 = Away win
3-3 = Draw

For each line on your ticket, check whether or not the result matches. If it does, you win the amount specified on the ticket for that match. Like this:

Away:£20
Home:£10
Draw:£5
[1-0, 2-1, 0-1]
Results in Winnings = £10 (first bet lost, second bet won, third bet lost);

Return your total winning as a string with the £ sign like this: '£100'

Good luck!

*/

package main

import "fmt"

type Ticket struct {
	bet    string
	amount int
}

func main() {
	assert(fifa([]Ticket{
		{"Home", 75},
		{"Away", 5000},
		{"Draw", 1324},
	}, []string{
		"1-0",
		"2-3",
		"0-1",
	}) == "£5075")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func fifa(tickets []Ticket, results []string) string {
	total := 0
	for index, result := range results {
		var score1, score2 int
		scanned, err := fmt.Sscanf(result, "%d-%d", &score1, &score2)
		if scanned != 2 || err != nil {
			continue
		}

		switch ticket := tickets[index]; {
		case score1 > score2 && ticket.bet == "Home":
			total += ticket.amount
		case score1 < score2 && ticket.bet == "Away":
			total += ticket.amount
		case score1 == score2 && ticket.bet == "Draw":
			total += ticket.amount
		}
	}
	return fmt.Sprintf("£%v", total)
}
