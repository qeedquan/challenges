package main

import (
	"flag"
	"fmt"
	"log"
	"math/rand/v2"
	"os"
	"path/filepath"
)

func main() {
	var (
		width   = 64
		height  = 64
		frames  = 100
		dataset = "dataset"
	)

	flag.IntVar(&width, "width", width, "specify width")
	flag.IntVar(&height, "height", height, "specify height")
	flag.IntVar(&frames, "frames", frames, "specify number of frames")
	flag.StringVar(&dataset, "dataset", dataset, "specify dataset")
	flag.Parse()

	os.MkdirAll(dataset, 0755)

	for frame := range frames {
		var (
			r = randn(8, 24)
			x = randn(r, width-r)
			y = randn(r, height-r)
			s = randstroke()
			t = randn(0, 180)
		)
		for shape := range 3 {
			file := open(dataset, frame, shape)
			fmt.Fprintf(file, `<svg width="%d" height="%d">`, width, height)
			fmt.Fprintf(file, "\n")
			fmt.Fprintln(file, `<rect width="100%" height="100%" fill="#ffffff"/>`)
			switch shape {
			case 0:
				fmt.Fprintf(file,
					`<circle cx="%d" cy="%d" r="%d" stroke="%s" stroke-width="4" fill="none" />`,
					x, y, r, s)

			case 1:
				fmt.Fprintf(file,
					`<rect x="%d" y="%d" width="%d" height="%d" stroke="%s" stroke-width="4" fill="none" transform="rotate(%d, %d, %d)" />`,
					x, y, r, r, s, t, x, y)

			case 2:
				fmt.Fprintf(file,
					`<polygon points="%d,%d,%d,%d,%d,%d" stroke="%s" stroke-width="4" fill="none" transform="rotate(%d, %d, %d)" />`,
					x, y-r, x+r, y+r, x-r, y+r, s, t, x, y)
			}
			fmt.Fprintf(file, "\n")
			fmt.Fprintf(file, `</svg>`)
			fmt.Fprintf(file, "\n")
			file.Close()
		}
	}
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func open(directory string, frame, shape int) *os.File {
	var name string
	switch shape {
	case 0:
		name = fmt.Sprintf("circle-%04d.svg", frame)
	case 1:
		name = fmt.Sprintf("square-%04d.svg", frame)
	case 2:
		name = fmt.Sprintf("triangle-%04d.svg", frame)
	}
	name = filepath.Join(directory, name)
	file, err := os.Create(name)
	check(err)
	return file
}

func randn(min, max int) int {
	return rand.IntN(max-min) + min
}

func randstroke() string {
	r := rand.IntN(100)
	g := rand.IntN(100)
	b := rand.IntN(100)
	return fmt.Sprintf("#%02X%02X%02X", r, g, b)
}
