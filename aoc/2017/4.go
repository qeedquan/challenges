/*

--- Day 4: High-Entropy Passphrases ---
A new system policy has been put in place that requires all accounts to use a passphrase instead of simply a password. A passphrase consists of a series of words (lowercase letters) separated by spaces.

To ensure security, a valid passphrase must contain no duplicate words.

For example:

aa bb cc dd ee is valid.
aa bb cc dd aa is not valid - the word aa appears more than once.
aa bb cc dd aaa is valid - aa and aaa count as different words.
The system's full passphrase list is available as your puzzle input. How many passphrases are valid?

--- Part Two ---
For added security, yet another system policy has been put in place. Now, a valid passphrase must contain no two words that are anagrams of each other - that is, a passphrase is invalid if any word's letters can be rearranged to form any other word in the passphrase.

For example:

abcde fghij is a valid passphrase.
abcde xyz ecdab is not valid - the letters from the third word can be rearranged to form the first word.
a ab abc abd abf abj is a valid passphrase, because all letters need to be used when forming another word.
iiii oiii ooii oooi oooo is valid.
oiii ioii iioi iiio is not valid - any of these words can be rearranged to form any other word.
Under this new system policy, how many passphrases are valid?

*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	fmt.Println(phrases("4.txt", valid1))
	fmt.Println(phrases("4.txt", valid2))
}

func phrases(name string, valid func([]string) bool) (int, error) {
	f, err := os.Open(name)
	if err != nil {
		return 0, err
	}
	defer f.Close()

	r := 0
	b := bufio.NewScanner(f)
	for b.Scan() {
		t := strings.Split(b.Text(), " ")
		if valid(t) {
			r++
		}
	}
	return r, nil
}

func valid1(t []string) bool {
	m := make(map[string]int)
	for _, v := range t {
		if m[v]++; m[v] > 1 {
			return false
		}
	}
	return true
}

func valid2(t []string) bool {
	m := make(map[string]int)
	for _, v := range t {
		v = lexisort(v)
		if m[v]++; m[v] > 1 {
			return false
		}
	}
	return true
}

func lexisort(s string) string {
	b := []byte(s)
	sort.Slice(b, func(i, j int) bool {
		return b[i] < b[j]
	})
	return string(b)
}
