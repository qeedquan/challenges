/*

On wikipedia, you can find this lovely blank map of the United States. What makes it so lovely? Well, first off all, it's in the SVG format, which means that you can download it and edit it quite easily, even with a computer program you write yourself (SVG is nothing but XML, after all).

Second, the kind mapmaker has gone to the extra trouble of labelling all the states in the code with their proper abbreviation (so "AR" for "Arkansas" and "MT" for "Montana"). For instance, look at the source file for that image, and you'll see that the first path that is defined has the id "HI", so we know it represents Hawaii.

By parsing that file, noting the "id" attributes of the various "path" tags, you can then change the color of a specific state by changing the "style" attribute. For instance, if we change Hawaii's style attribute from

fill:#d3d3d3;stroke:#ffffff;stroke-opacity:1;stroke-width:0.75;stroke-miterlimit:4;stroke-dasharray:none
to

fill:#ff0000;stroke:#ffffff;stroke-opacity:1;stroke-width:0.75;stroke-miterlimit:4;stroke-dasharray:none
then Hawaii will stand out as bright red.

Your task today is to write a program that will read in that SVG file, then assign colors to all the different US states, such that no states that share a border has the same color. Here is an example. You don't have to figure out what states border which other states from the SVG file, you can just put that as a table in your code, or use any other solution you can come up with.

If you finish, please upload your image, or a PNG of your image, to imgur, so the rest of us can see what it looks like!

Bonus: By the 4-color theorem all maps like this can be colored using at most 4 colors, so that no two regions that share a border have the same color. Color the map using only four different colors.

NOTE: Look out for Michigan! Michigan is tricky.

Edit: to make it easier for everyone, here's a list of what states borders other states. I compiled it myself, so I can't guarantee accuracy (though I'm fairly sure it's accurate, and it works fine in my program). To be clear, a line like

ND <- MN, SD, MT
Means that North Dakota borders Minnesota, South Dakota and Montana.

*/

package main

import (
	"bufio"
	"bytes"
	"flag"
	"fmt"
	"image/color"
	"log"
	"math/rand"
	"os"
	"strings"
)

type State struct {
	Name      string
	Color     color.RGBA
	Neighbors []*State
}

var flags struct {
	svgfile    string
	statesfile string
	outfile    string
}

func main() {
	log.SetFlags(0)
	log.SetPrefix("colorize: ")

	parseflags()

	svg, err := os.ReadFile(flags.svgfile)
	check(err)

	states, err := readstates(flags.statesfile)
	check(err)

	colorize(states)

	err = render(states, svg, flags.outfile)
	check(err)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func parseflags() {
	flag.StringVar(&flags.statesfile, "states", "states.txt", "specify states file")
	flag.StringVar(&flags.svgfile, "map", "map.svg", "specify map file")
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}
	flags.outfile = flag.Arg(0)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] output.svg")
	flag.PrintDefaults()
	os.Exit(2)
}

func render(states map[string]*State, svg []byte, outfile string) error {
	buf := new(bytes.Buffer)
	for _, state := range states {
		fmt.Fprintf(buf, ".%s {fill:%s} ", state.Name, hexcolor(state.Color))
		fmt.Fprintf(buf, "/* ")
		for _, neighbor := range state.Neighbors {
			fmt.Fprintf(buf, "%s ", neighbor.Name)
		}
		fmt.Fprintf(buf, "*/\n")
	}

	i := bytes.Index(svg, []byte("</style>"))
	if i > 0 {
		svg = append(svg[:i], append(buf.Bytes(), svg[i:]...)...)
	}
	return os.WriteFile(outfile, svg, 0644)
}

func colorize(states map[string]*State) {
loop:
	for {
		for _, state := range states {
			state.Color = randrgb()
		}
		for _, state := range states {
			for _, neighbor := range state.Neighbors {
				if state.Color == neighbor.Color {
					continue loop
				}
			}
			return
		}
	}
}

func readstates(name string) (map[string]*State, error) {
	file, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer file.Close()

	states := make(map[string]*State)
	scan := bufio.NewScanner(file)
	for scan.Scan() {
		line := strings.TrimSpace(scan.Text())
		if line == "" {
			continue
		}

		fields := strings.Split(line, "<-")
		state := makestate(states, fields[0])
		if len(fields) > 1 {
			neighbors := strings.Split(fields[1], ",")
			for _, neighbor := range neighbors {
				state.Neighbors = append(state.Neighbors, makestate(states, neighbor))
			}
		}
	}
	return states, nil
}

func makestate(states map[string]*State, name string) *State {
	name = strings.TrimSpace(name)
	name = strings.ToLower(name)
	if states[name] == nil {
		states[name] = &State{Name: name}
	}
	return states[name]
}

func randrgb() color.RGBA {
	return color.RGBA{
		uint8(rand.Intn(256)),
		uint8(rand.Intn(256)),
		uint8(rand.Intn(256)),
		255,
	}
}

func hexcolor(c color.RGBA) string {
	return fmt.Sprintf("#%02x%02x%02x", c.R, c.G, c.B)
}
