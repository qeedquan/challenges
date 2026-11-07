/*

Find text pattern in a website

*/

package main

import (
	"flag"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"
	"regexp"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	err := find(flag.Arg(0), flag.Arg(1))
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: url pattern")
	flag.PrintDefaults()
	os.Exit(2)
}

func find(url, pattern string) error {
	resp, err := http.Get(url)
	if err != nil {
		return err
	}

	data, err := io.ReadAll(resp.Body)
	if err != nil {
		return err
	}

	re := regexp.MustCompile(pattern)
	for _, match := range re.FindAll(data, -1) {
		fmt.Printf("%q\n", match)
	}
	return nil
}
