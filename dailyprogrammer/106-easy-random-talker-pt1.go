/*

Your protoken will be responsible for analyzing a small chunk of text, the text of this entire dailyprotokenmer description.
Your task is to output the distinct words in this description, from highest to lowest count with the number of occurrences for each.
Punctuation will be considered as separate words where they are not a part of the word.

The following will be considered their own words: " . , : ; ! ? ( ) [ ] { }

For anything else, consider it as part of a word.

Extra Credit:

Process the text of the ebook Metamorphosis, by Franz Kafka and determine the top 10 most frequently used words and their counts. (This will help for part 2)

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"os"
	"regexp"
	"sort"
	"strings"
)

type Token struct {
	text  string
	count int
}

var flags struct {
	file string
	ntop int
}

func main() {
	parseflags()
	err := analyze(flags.file, flags.ntop)
	if err != nil {
		log.Fatal(err)
	}
}

func parseflags() {
	flags.file = "pg5200.txt"
	flag.IntVar(&flags.ntop, "ntop", 10, "show n-tops")
	flag.Parse()
	if flag.NArg() >= 1 {
		flags.file = flag.Arg(0)
	}
}

func analyze(name string, ntop int) error {
	data, err := os.ReadFile(name)
	if err != nil {
		return err
	}

	regex := regexp.MustCompile(`\w+|[",;.:!?()[\]}{]`)
	dict := make(map[string]int)
	for _, match := range regex.FindAll(data, -1) {
		word := string(match)
		word = strings.ToLower(word)
		dict[word] += 1
	}

	var tokens []Token
	for key, value := range dict {
		tokens = append(tokens, Token{key, value})
	}

	sort.Slice(tokens, func(i, j int) bool {
		return tokens[i].count > tokens[j].count
	})

	if len(tokens) > ntop {
		tokens = tokens[:ntop]
	}

	for _, token := range tokens {
		fmt.Println(token.text, token.count)
	}

	return nil
}
