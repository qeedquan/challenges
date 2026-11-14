/*

Semordnilaps (also known as heteropalindromes, semi-palindromes, half-palindromes, reversgrams, mynoretehs, reversible anagrams, word reversals, or anadromes) are words which are also words when spelled backwards. A few examples are:

Ward <=> Draw
Mined <=> Denim
Parts <=> Strap
Given a positive integer N (via function argument or STDIN), return / output a list of semordnilaps from this list of English words, that have exactly N letters. The list of words can be saved locally on your computer as a text file called: w.txt. You can also get the list from the url, but it will be included in the byte count.

Rules:

Palindromes are not semordnilaps! Therefore, the words "noon", "rotor" and "radar" should not be included in the list.
Only one of the words (in a semordnilap pair) should be included in the list. Therefore, if "dog" is in the list, "god" should not be (it doesn't matter which one is included.)
If there are no semordnilaps, the output should be an empty string, 0, FALSE or something else indicating that there were no results. The function must work even if there are no results.
This is code golf so the shortest code in bytes wins!

*/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"sort"
	"strings"
)

func main() {
	w, err := semordnilaps("corncob_lowercase.txt")
	if err != nil {
		log.Fatal(err)
	}
	for _, w := range w {
		fmt.Println(w)
	}
}

func semordnilaps(name string) ([]string, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	m := make(map[string]bool)
	s := bufio.NewScanner(f)
	for s.Scan() {
		w := s.Text()
		w = strings.TrimSpace(w)
		w = strings.ToLower(w)
		m[w] = true
	}

	r := []string{}
	for w := range m {
		if m[reverse(w)] {
			r = append(r, w)
		}
	}
	sort.Strings(r)
	return r, nil
}

func reverse(s string) string {
	p := []rune{}
	for _, r := range s {
		p = append(p, r)
	}

	n := len(p)
	for i := 0; i < n/2; i++ {
		p[i], p[n-i-1] = p[n-i-1], p[i]
	}
	return string(p)
}
