/*

Introduction and credit
Assume you're a bartender. You have many happy people in your bar at most times, but many only ever drink the very same drink and too few for your taste and you want to change that. So you introduce a system where the price of a drink is variable, depending on how many have already been sold, but never more or less expensive than certain thresholds. For some odd reason you always forget to keep proper track of all sold drinks and prices and thus you need to think of a short (= memorable!) piece of code that does the math for you given the amount of drinks consumed.

This challenge has already appeared in the mid-term exam in 2012 at the functional programming course at my uni and I've got my professor's ok to post it here. We have been provided an example solution in the exam's language.

Input
Your input will be a list of strings which don't contain spaces - these are the names of the drinks sold. Take the input using your preferred, generally accepted input method.

Output
Your output will be a single number - this is the income you have generated this evening. Give the output using your preferred, generally accepted output method.

What to do?
This applies for each drink individually:

The starting price is 10.
Each time the drink is bought, it's price is bumped up by 1 for the next buyer.
The maximal price is 50. If the drink has been bought for 50 the new price will be 10 again.
Your task is to find the overall income, generated by the input list of drinks given the above rules.

In case you're wondering: "50 bucks is really damn expensive for a drink!", this is 50-deci Bucks, so 50 * 0.1 * Unit, but I've opted to go for 10-50 to not exclude languages without floating point arithmetic.

Who wins?
This is code-golf, so the shortest code in bytes wins! Standard rules apply.

Potential Corner Cases
If the input list is empty, the output shall be 0.
The input list icannot be assumed to be sorted by drink.

Examples
[] -> 0
["A"] -> 10
["A","B"] -> 20
["A","A","B"] -> 31
["A","B","A"] -> 31
["A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A"] -> 1240
["A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","B","B","B","C","C","D"] -> 1304
["D","A","A","C","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","B","B","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","B","C"] -> 1304
["A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","B","B","B","C","C","D","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A","A"] -> 1304

*/

package main

func main() {
	assert(price([]string{}) == 0)
	assert(price([]string{"A"}) == 10)
	assert(price([]string{"A", "B"}) == 20)
	assert(price([]string{"A", "A", "B"}) == 31)
	assert(price([]string{"A", "B", "A"}) == 31)
	assert(price([]string{
		"A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",
		"A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",
		"A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",
	}) == 1240)
	assert(price([]string{
		"A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",
		"A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",
		"A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",
		"B", "B", "B", "C", "C", "D",
	}) == 1304)
	assert(price([]string{
		"D", "A", "A", "C", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",
		"A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "B", "B", "A", "A",
		"A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",
		"A", "A", "A", "A", "B", "C",
	}) == 1304)
	assert(price([]string{
		"A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",
		"A", "A", "A", "A", "A", "A", "A", "A", "A", "B", "B", "B", "C", "C",
		"D", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A", "A",
		"A", "A", "A", "A", "A", "A",
	}) == 1304)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func price(s []string) int {
	r := 0
	p := make(map[string]int)
	for _, i := range s {
		if p[i] == 0 {
			p[i] = 10
		} else if p[i]++; p[i] > 50 {
			p[i] = 10
		}
		r += p[i]
	}
	return r
}
