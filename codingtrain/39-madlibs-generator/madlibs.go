/*

https://en.wikipedia.org/wiki/Mad_Libs

*/

package main

import (
	"encoding/csv"
	"flag"
	"fmt"
	"log"
	"math/rand"
	"os"
)

func main() {
	parseflags()

	table, err := load(flag.Arg(0))
	check(err)

	fmt.Println(generate(table))
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func parseflags() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] madlib.csv")
	flag.PrintDefaults()
	os.Exit(2)
}

func load(name string) (table map[string][]string, err error) {
	table = make(map[string][]string)

	file, err := os.Open(flag.Arg(0))
	if err != nil {
		return
	}
	defer file.Close()

	reader := csv.NewReader(file)
	records, err := reader.ReadAll()
	if err != nil {
		return
	}

	if len(records) < 2 {
		return
	}

	index := make(map[string]int, len(records[0]))
	for position, key := range records[0] {
		index[key] = position
	}

	for _, record := range records[1:] {
		for key := range index {
			position := index[key]
			table[key] = append(table[key], record[position])
		}
	}

	return table, nil
}

func generate(table map[string][]string) string {
	exclamation := pick(table, "Exclamation")
	adverb := pick(table, "Adverb")
	noun := pick(table, "Noun")
	adjective := pick(table, "Adjective")
	pluralnoun := pick(table, "PluralNoun")
	return fmt.Sprintf("%s! they said %s as they jumped into their %s and flew off with their %s %s.",
		exclamation, adverb, noun, adjective, pluralnoun)
}

func pick(table map[string][]string, key string) string {
	values := table[key]
	if len(values) == 0 {
		return "[PLACEHOLDER]"
	}
	index := rand.Intn(len(values))
	return values[index]
}
