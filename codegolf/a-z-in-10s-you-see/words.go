/*

As a follow up to my previous challenge Count to 20 with Words!, we will once again be using the word list from that challenge to perform another task. This time, you will be exclusively using:

https://github.com/Magic Octopus Urn/wordListsByLength/blob/master/10.txt

To choose 26 different words, each starting with a unique letter, and output them in ascending order from A to Z. Here's a valid example:

aardwolves
babbitting
caravaning
debilitate
evaporator
fantasized
geographer
hawfinches
imbecility
juvenility
kalanchoes
lamaseries
malodorous
nudibranch
oligophagy
pantywaist
quarreling
russetting
scantiness
teetotaler
undercount
voodooisms
wentletrap
xenophobic
yeomanries
zwitterion

This is an aardwolf, this is a hawfinch, this is a kalanchoe, this is a nudibranch and a wentletrap.

Rules
No reading directly from the repository, or any other loopholes.
You may select any 26 of the words provided in the link.
You choose words and these are the words your program should output every time.
One word beginning with each of the following letters must be selected:
[a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z]
This is code-golf, lowest byte-count wins.
Any other suggestions for spin-offs using the word lists?

Also, feel free to steal my word-lists and make challenges.

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"math/rand"
	"os"
	"unicode/utf8"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	db, err := build(flag.Arg(0))
	if err != nil {
		log.Fatal(err)
	}

	output(db)
}

func output(db map[rune][]string) {
	for letter := 'a'; letter <= 'z'; letter++ {
		words := db[letter]
		numwords := len(words)
		if numwords > 0 {
			fmt.Println(words[rand.Intn(numwords)])
		}
	}
}

func build(name string) (db map[rune][]string, err error) {
	fd, err := os.Open(name)
	if err != nil {
		return
	}
	defer fd.Close()

	db = make(map[rune][]string)

	scan := bufio.NewScanner(fd)
	for scan.Scan() {
		word := scan.Text()
		letter, _ := utf8.DecodeRuneInString(word)
		db[letter] = append(db[letter], word)
	}
	return
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: file")
	flag.PrintDefaults()
	os.Exit(2)
}
