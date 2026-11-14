/*

https://en.wikipedia.org/wiki/Jackson_Mac_Low

The Diastic technique is a methodology and algorithm for generating found poetry from a source text.
It was developed and used by poet / artist Jackson Mac

*/

package main

import (
	"bytes"
	"flag"
	"fmt"
	"log"
	"os"
	"strings"
)

var flags struct {
	source string
	seed   string
}

func main() {
	parseflags()
	tokens, err := load(flags.source)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(diastic(flags.seed, tokens))
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <seed>")
	flag.PrintDefaults()
	os.Exit(2)
}

func parseflags() {
	flag.StringVar(&flags.source, "source", "rainbow.txt", "specify source text")
	flag.Usage = usage
	flag.Parse()

	flags.seed = "rainbow"
	if flag.NArg() >= 1 {
		flags.seed = flag.Arg(0)
	}
}

func load(name string) ([]string, error) {
	data, err := os.ReadFile(name)
	if err != nil {
		return nil, err
	}

	output := new(bytes.Buffer)
	for _, symbol := range data {
		if strings.IndexByte(",!.?", symbol) >= 0 {
			symbol = ' '
		}
		output.WriteByte(symbol)
	}

	tokens := strings.Split(output.String(), " ")
	length := 0
	for _, token := range tokens {
		token = strings.TrimSpace(token)
		if token == "" {
			continue
		}
		tokens[length], length = token, length+1
	}
	return tokens[:length], nil
}

func diastic(seed string, tokens []string) string {
	var (
		phrase  string
		current int
	)
	for i := 0; i < len(seed); i++ {
		for j := current; j < len(tokens); j++ {
			if i < len(tokens[j]) && tokens[j][i] == seed[i] {
				phrase += fmt.Sprintf("%s ", tokens[j])
				current = j + 1
				break
			}
		}
	}
	return phrase
}
