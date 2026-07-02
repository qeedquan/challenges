/*

Jack is a little businessman. He found out a way to earn money by buying electricity on days when it's cheap and selling it when it's much more expensive. He stores the electricity in a battery he made by himself.

Challenge
You are given N (if required), the number of days Jack knows the cost of electricity for, and X, the amount of money Jack has available to invest in electricity, and the value(buy/sell value) of the electricity for N days. Your job is to determine when Jack should buy and when he should sell electricity in order to earn as much money as possible and simply print the largest possible sum of money he could have afterwards.

The value of the electricity is always a positive integer but depending on the amount of money Jack has, the amount of electricity and money he has may be floating point numbers.

Examples
(I/O need not be exactly as shown):

1.

4 10
4 10 5 20
Output: 100
- because he buys electricity on the 1st day and the sells it on the 2nd and buys it on the 3rd and sells it on the 4th day.

2.

3 21
10 8 3
Output: 21
- because it's better if he doesn't buy/sell any electricity.

3.

3 10
8 10 14
Output: 17.5
- because he buys electricity on the 1st day, but he sells it on the 3rd day.

4.

5 10
4 2 10 5 20
Output: 200
- much like example 1, but this time Jack waits for the price to drop to 2 before making a purchase.

The program with the shortest amount of code wins! This is a code golf problem. Note:You can shorten the input, as long as it still makes sense.

*/

package main

func main() {
	assert(transactions(10, []float64{4, 10, 5, 20}) == 100)
	assert(transactions(21, []float64{10, 8, 3}) == 21)
	assert(transactions(10, []float64{8, 10, 14}) == 17.5)
	assert(transactions(10, []float64{4, 2, 10, 5, 20}) == 200)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func transactions(capital float64, prices []float64) float64 {
	total := 1.0
	for i := range len(prices) - 1 {
		total *= max(prices[i+1], prices[i]) / prices[i]
	}
	return capital * total
}
