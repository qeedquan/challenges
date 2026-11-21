/*

https://en.wikipedia.org/wiki/Acrostic

*/

package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"log"
	"math/rand/v2"
	"net/http"
	"os"
	"strings"
)

type Figment struct {
	Word  string
	Score int
}

func main() {
	log.SetFlags(0)
	log.SetPrefix("acrostic: ")
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	err := acrostic(flag.Arg(0))
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <word>")
	flag.PrintDefaults()
	os.Exit(2)
}

func acrostic(word string) error {
	word = strings.ToUpper(word)
	for _, letter := range word {
		err := pickword(letter, word)
		if err != nil {
			return err
		}
	}

	return nil
}

func pickword(letter rune, word string) error {
	url := fmt.Sprintf("https://api.datamuse.com/words?sp=%c*&ml=%s&max=5", letter, word)
	resp, err := http.Get(url)
	if err != nil {
		return err
	}

	data, err := io.ReadAll(resp.Body)
	if err != nil {
		return err
	}

	var result []*Figment
	err = json.Unmarshal(data, &result)
	if err != nil {
		return err
	}

	if len(result) == 0 {
		fmt.Printf("%c\n", letter)
	} else {
		index := rand.N(len(result))
		fmt.Println(result[index].Word)
	}

	return nil
}
