/*

Print all the numbers from 0-100 in the right order using the Danish way of counting

How they count
Like English, they have dedicated words for 0-20, 30, 40 and 100
Instead of saying twenty-one and twenty-two, they say one and twenty and two and twenty
Starting with fifty they say multiples of 10 as n*20

50 = half third times twenty = half way to the 3rd multiple of 20
60 = three times twenty
70 = half fourth times twenty
80 = four times twenty
90 = half fifth times twenty
So for instance, 55 would be five and half third times twenty.

Expected output
zero
one
two
three
four
five
six
seven
eight
nine
ten
eleven
twelve
thirteen
fourteen
fifteen
sixteen
seventeen
eighteen
nineteen
twenty
one and twenty
two and twenty
three and twenty
four and twenty
five and twenty
six and twenty
seven and twenty
eight and twenty
nine and twenty
thirty
one and thirty
two and thirty
three and thirty
four and thirty
five and thirty
six and thirty
seven and thirty
eight and thirty
nine and thirty
forty
one and forty
two and forty
three and forty
four and forty
five and forty
six and forty
seven and forty
eight and forty
nine and forty
half third times twenty
one and half third times twenty
two and half third times twenty
three and half third times twenty
four and half third times twenty
five and half third times twenty
six and half third times twenty
seven and half third times twenty
eight and half third times twenty
nine and half third times twenty
three times twenty
one and three times twenty
two and three times twenty
three and three times twenty
four and three times twenty
five and three times twenty
six and three times twenty
seven and three times twenty
eight and three times twenty
nine and three times twenty
half fourth times twenty
one and half fourth times twenty
two and half fourth times twenty
three and half fourth times twenty
four and half fourth times twenty
five and half fourth times twenty
six and half fourth times twenty
seven and half fourth times twenty
eight and half fourth times twenty
nine and half fourth times twenty
four times twenty
one and four times twenty
two and four times twenty
three and four times twenty
four and four times twenty
five and four times twenty
six and four times twenty
seven and four times twenty
eight and four times twenty
nine and four times twenty
half fifth times twenty
one and half fifth times twenty
two and half fifth times twenty
three and half fifth times twenty
four and half fifth times twenty
five and half fifth times twenty
six and half fifth times twenty
seven and half fifth times twenty
eight and half fifth times twenty
nine and half fifth times twenty
one hundred

Rules
You may use any separator to separate the numbers
Due to a typo in the original specification, you may use forth instead of fourth.
You may write a function or write to std-out
Standard loopholes apply
This is codegolf; shortest code in bytes win!

*/

package main

import "fmt"

func main() {
	for i := range 101 {
		fmt.Println(danish(i))
	}
}

func danish(n int) string {
	tab := []string{
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
		"ten",
		"eleven",
		"twelve",
		"thirteen",
		"fourteen",
		"fifteen",
		"sixteen",
		"seventeen",
		"eighteen",
		"nineteen",
		"twenty",
		"one and twenty",
		"two and twenty",
		"three and twenty",
		"four and twenty",
		"five and twenty",
		"six and twenty",
		"seven and twenty",
		"eight and twenty",
		"nine and twenty",
		"thirty",
		"one and thirty",
		"two and thirty",
		"three and thirty",
		"four and thirty",
		"five and thirty",
		"six and thirty",
		"seven and thirty",
		"eight and thirty",
		"nine and thirty",
		"forty",
		"one and forty",
		"two and forty",
		"three and forty",
		"four and forty",
		"five and forty",
		"six and forty",
		"seven and forty",
		"eight and forty",
		"nine and forty",
		"half third times twenty",
		"one and half third times twenty",
		"two and half third times twenty",
		"three and half third times twenty",
		"four and half third times twenty",
		"five and half third times twenty",
		"six and half third times twenty",
		"seven and half third times twenty",
		"eight and half third times twenty",
		"nine and half third times twenty",
		"three times twenty",
		"one and three times twenty",
		"two and three times twenty",
		"three and three times twenty",
		"four and three times twenty",
		"five and three times twenty",
		"six and three times twenty",
		"seven and three times twenty",
		"eight and three times twenty",
		"nine and three times twenty",
		"half fourth times twenty",
		"one and half fourth times twenty",
		"two and half fourth times twenty",
		"three and half fourth times twenty",
		"four and half fourth times twenty",
		"five and half fourth times twenty",
		"six and half fourth times twenty",
		"seven and half fourth times twenty",
		"eight and half fourth times twenty",
		"nine and half fourth times twenty",
		"four times twenty",
		"one and four times twenty",
		"two and four times twenty",
		"three and four times twenty",
		"four and four times twenty",
		"five and four times twenty",
		"six and four times twenty",
		"seven and four times twenty",
		"eight and four times twenty",
		"nine and four times twenty",
		"half fifth times twenty",
		"one and half fifth times twenty",
		"two and half fifth times twenty",
		"three and half fifth times twenty",
		"four and half fifth times twenty",
		"five and half fifth times twenty",
		"six and half fifth times twenty",
		"seven and half fifth times twenty",
		"eight and half fifth times twenty",
		"nine and half fifth times twenty",
		"one hundred",
	}

	if n < 0 || n >= len(tab) {
		return "unknown"
	}
	return tab[n]
}
