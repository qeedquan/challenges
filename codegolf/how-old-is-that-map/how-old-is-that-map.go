/*

Referencing xkcd 1688:
https://xkcd.com/1688/

Your task is to deduce the age of a map by asking the user questions. These question must be exactly the same as in the xkcd guide, except from the capitalisation and additional newline(s). Additionally, you should give the user some options to choose from, which don't have to be in the order as in the xkcd image. If the input doesn't match any of the expected answers, your program/function may behave in any undefined way. At the end, you should output the year/timespan the map was created.

Examples (> denotes input, but you may choose something else):
Example 1:
ISTANBUL OR CONSTANTINOPLE?
(CONSTANTINOPLE, NEITHER, ISTANBUL)

>ISTANBUL

DOES THE SOVIET UNION EXISTS?
(YES, NO)

>NO

ZAIRE?
OR: 'HONG KONG (UK)'
(YES, NO)

>NO

SERBIA / MONTENEGRO ARE?
(ONE COUNTRY, TWO COUNTRIES)

>TWO COUNTRIES

HOW MANY SUDANS ARE THERE?
(ONE, TWO)

>ONE

2007-11
Example 2:
ISTANBUL OR CONSTANTINOPLE?
(CONSTANTINOPLE, NEITHER, ISTANBUL)

>how are you

error

*/

package main

import (
	"bufio"
	"encoding/xml"
	"flag"
	"fmt"
	"log"
	"os"
	"strings"
)

type Doc struct {
	XMLName xml.Name `xml:xkcd1688"`
	Nodes   []*Node  `xml:"node"`
	Leafs   []*Leaf  `xml:"leaf"`
}

type Node struct {
	XMLName     xml.Name  `xml:"node"`
	ID          string    `xml:"id,attr"`
	Question    string    `xml:"question"`
	Options     []*Option `xml:"option"`
	Transitions map[string]any
}

type Option struct {
	XMLName xml.Name `xml:"option"`
	Target  string   `xml:"target,attr"`
	Choice  string   `xml:",chardata"`
}

type Leaf struct {
	XMLName xml.Name `xml:"leaf"`
	ID      string   `xml:"id,attr"`
	Text    string   `xml:",chardata"`
	Range   *Range   `xml:"range"`
}

type Range struct {
	XMLName xml.Name `xml:"range"`
	Begin   struct {
		XMLName xml.Name `xml:"begin"`
		Year    string   `xml:"year,attr"`
	}
	End struct {
		XMLName xml.Name `xml:"end"`
		Year    string   `xml:"year,attr"`
	}
}

var flags struct {
	mapfile string
}

func main() {
	log.SetFlags(0)
	log.SetPrefix("xkcd-map: ")

	flag.StringVar(&flags.mapfile, "mapfile", "xkcd1688.xml", "specify map file")
	flag.Parse()

	start, states, err := readmap(flags.mapfile)
	check(err)

	play(start, states)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func readmap(name string) (start string, states map[string]any, err error) {
	data, err := os.ReadFile(name)
	if err != nil {
		return
	}

	doc := &Doc{}
	err = xml.Unmarshal(data, &doc)
	if err != nil {
		return
	}

	for _, leafs := range doc.Leafs {
		leafs.Text = tidy(leafs.Text)
	}

	states = make(map[string]any)
	for _, node := range doc.Nodes {
		node.Question = tidy(node.Question)
		node.Transitions = make(map[string]any)
		for _, option := range node.Options {
			option.Choice = tidy(option.Choice)

			var next any
			for _, target := range doc.Nodes {
				if node != target && target.ID == option.Target {
					next = target
					goto next
				}
			}
			for _, target := range doc.Leafs {
				if target.ID == option.Target {
					next = target
					goto next
				}
			}

		next:
			node.Transitions[option.Choice] = next
		}

		states[node.ID] = node
	}

	root, ok := states["root"].(*Node)
	if root == nil || !ok {
		err = fmt.Errorf("map missing root node")
		return
	}
	if len(root.Options) < 1 {
		err = fmt.Errorf("map root node has no options")
		return
	}

	start = root.Options[0].Target
	if states[start] == nil {
		err = fmt.Errorf("map missing start state")
		return
	}

	return
}

func play(start string, states map[string]any) {
	scanner := bufio.NewScanner(os.Stdin)
	state := states[start]
loop:
	for {
		switch cur := state.(type) {
		case *Node:
			fmt.Printf("\n%s\n", cur.Question)
			fmt.Printf("(")
			for index, option := range cur.Options {
				fmt.Printf("%s", option.Choice)
				if index+1 < len(cur.Options) {
					fmt.Printf(", ")
				}
			}
			fmt.Printf(")\n\n")

			fmt.Printf("> ")
			if !scanner.Scan() {
				break loop
			}

			line := tidy(scanner.Text())
			next := cur.Transitions[line]
			if next == nil {
				fmt.Printf("\nERROR\n")
				continue
			}
			state = next

		case *Leaf:
			fmt.Println()
			if cur.Text != "" {
				fmt.Print(cur.Text)
			} else if cur.Range != nil {
				fmt.Printf("%s-%s", cur.Range.Begin.Year, cur.Range.End.Year)
			}
			fmt.Println()

			break loop

		default:
			panic("unreachable")
		}
	}
	fmt.Println()
}

func tidy(str string) string {
	str = strings.TrimSpace(str)
	str = strings.ToUpper(str)
	return str
}
