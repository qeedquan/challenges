/*

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

*/

package main

import (
	"bytes"
	"fmt"
	"unicode"
)

func main() {
	fmt.Println(solve(5))
	fmt.Println(solve(1000))
}

func solve(n uint) int {
	r := 0
	for i := uint(1); i <= n; i++ {
		r += chars(numeng(i))
	}
	return r
}

func chars(s string) int {
	c := 0
	for _, r := range s {
		if unicode.IsSpace(r) || r == '-' {
			continue
		}
		c += 1
	}
	return c
}

func numeng(n uint) string {
	ones := []string{
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
	}
	tens := []string{
		"twenty",
		"thirty",
		"forty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety",
	}

	if n > 1000 {
		return "unsupported"
	}

	if n == 1000 {
		return "one thousand"
	}

	s := fmt.Sprint(n)
	m := len(s)
	i := 0
	o := false
	w := new(bytes.Buffer)
	for {
		t := 0
		r := m % 3
		switch r {
		case 0:
			t += int(s[i]-'0') * 100
			i += 1
			fallthrough
		case 2:
			t += int(s[i]-'0') * 10
			i += 1
			fallthrough
		case 1:
			t += int(s[i] - '0')
			i += 1
		}

		if t >= 100 {
			fmt.Fprintf(w, "%s hundred", ones[t/100])
			t %= 100
			if t != 0 {
				fmt.Fprintf(w, " and ")
			}
		}
		if t >= 20 {
			fmt.Fprintf(w, "%s", tens[t/10-2])
			if t%10 != 0 {
				fmt.Fprintf(w, " %s", ones[t%10])
			}
		} else if !(r == 0 && t == 0) || (!o && t != 0) {
			fmt.Fprintf(w, "%s", ones[t])
		}

		if r == 0 {
			m -= 3
		} else {
			m -= r
		}
		if m <= 0 {
			break
		}

		o = true
	}
	return w.String()
}
