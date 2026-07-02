/*

The Zachtronics game TIS-100 contains a graphics display called the visualization module.
I could try and explain the specs of this module, but the game's manual will do a better job:

https://i.sstatic.net/R18L6.png

(As you may have guessed, the motivation of this problem is to create a code golf challenge in which TIS-100 is the optimal language.)

Your job is to, in as few characters as possible, implement a program which will output the correct image for any valid input sequence. There are no requirements on what happens for an invalid input sequence. This can be a graphical window or console output. This includes strings of more than 1 command! If it has multiple -1s, multiple lines should be drawn.

Test Cases:
Input:

    3, 4, 4, 3, 2, 1, 0, 1, 2, 3, 4, -1

Output:
https://i.sstatic.net/d4pyl.jpg

Input:

    1, 1, 4, 4, -1, 8, 8, 4, 4, -1

Output:
https://i.sstatic.net/fzCNH.jpg

Input:

    5, 5, 4, -1, 5, 5, 0, -1

Output:
https://i.sstatic.net/04vvO.jpg

The simple TIS implementation is:

TIS-100, 64 55 Bytes
-9 thanks to feersum

@1
MOV UP ANY
@5
MOV UP ANY
@9
MOV UP ANY
@10
MOV ANY ANY
An additional byte is added as a single character in the filename is relevant.

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"log"
	"os"
	"strconv"
	"strings"
)

var flags struct {
	width  int
	height int
	size   int
}

func main() {
	log.SetFlags(0)
	log.SetPrefix("tis100-vis: ")
	parseflags()

	values, err := getints(flag.Arg(0))
	check(err)

	picture := visualize(flags.width, flags.height, flags.size, values)
	check(png.Encode(os.Stdout, picture))
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] [commands]")
	flag.PrintDefaults()
	os.Exit(2)
}

func parseflags() {
	flag.IntVar(&flags.width, "width", 30, "specify width")
	flag.IntVar(&flags.height, "height", 18, "specify height")
	flag.IntVar(&flags.size, "size", 20, "specify size")
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}
}

func getints(input string) ([]int, error) {
	values := []int{}
	input = strings.Replace(input, ",", " ", -1)
	for _, token := range strings.Split(input, " ") {
		token = strings.TrimSpace(token)
		if token == "" {
			continue
		}

		value, err := strconv.Atoi(token)
		if err != nil {
			return nil, err
		}
		values = append(values, value)
	}
	return values, nil
}

func visualize(width, height, size int, values []int) *image.RGBA {
	palette := []*image.Uniform{
		image.NewUniform(color.RGBA{0x00, 0x00, 0x00, 0xff}),
		image.NewUniform(color.RGBA{0x42, 0x42, 0x42, 0xff}),
		image.NewUniform(color.RGBA{0x87, 0x87, 0x87, 0xff}),
		image.NewUniform(color.RGBA{0xce, 0xcc, 0xcd, 0xff}),
		image.NewUniform(color.RGBA{0xa0, 0x0a, 0x0c, 0xff}),
	}

	var (
		x, y  int
		state int
	)

	picture := image.NewRGBA(image.Rect(0, 0, width*size, height*size))
	draw.Draw(picture, picture.Bounds(), palette[0], image.ZP, draw.Src)
	for _, value := range values {
		switch {
		case value < 0:
			state = 0
			continue
		case state == 0:
			x = value
		case state == 1:
			y = value
		case value < len(palette):
			bounds := image.Rect(x*size, y*size, (x+1)*size, (y+1)*size)
			draw.Draw(picture, bounds, palette[value], image.ZP, draw.Src)
			x += 1
		}
		state += 1
	}
	return picture
}
