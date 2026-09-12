package main

import (
	"encoding/json"
	"flag"
	"fmt"
	"log"
	"os"
	"strings"
)

type Sprite struct {
	Word        string
	Countrycode string
	Timestamp   string
	Recognized  bool
	Key_id      string
	Drawing     [][2][]int
}

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	name := flag.Arg(0)
	sprite, err := decode(name)
	check(err)

	dump(sprite)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: sprite.json")
	flag.PrintDefaults()
	os.Exit(2)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func decode(name string) (*Sprite, error) {
	data, err := os.ReadFile(name)
	if err != nil {
		return nil, err
	}

	var sprite Sprite
	err = json.Unmarshal(data, &sprite)
	if err != nil {
		return nil, err
	}
	return &sprite, nil
}

func dump(sprite *Sprite) {
	name := strings.ToUpper(sprite.Word)
	maxlength := 0
	for _, strokes := range sprite.Drawing {
		maxlength = max(maxlength, min(len(strokes[0]), len(strokes[1])))
	}
	maxlength += 1

	fmt.Printf("const Vector2 %s[%v][%v] = {\n", name, len(sprite.Drawing), maxlength)
	for _, strokes := range sprite.Drawing {
		length := min(len(strokes[0]), len(strokes[1]))
		fmt.Printf("\t{\n")
		for i := range length {
			fmt.Printf("\t\t{%d, %d},\n", strokes[0][i], strokes[1][i])
		}
		fmt.Printf("\t\t{-1, -1},\n")
		fmt.Println("\t},")
	}
	fmt.Println("};")
}
