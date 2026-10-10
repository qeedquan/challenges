/*

New Posts and New Sandbox Posts are chatbots that occupy CGSE's main chatroom, The Nineteenth Byte. They've been doing their jobs for almost one full year now, so I thought I'd make a challenge to honor their contributions!

The challenge is simple: Draw the profile picture of either New Posts (NP) or New Sandbox Posts (NSP). Your program must take as input a boolean value, and draw NP's profile picture if true and NSP's profile picture if false. (They're identical except for the color difference.)

Here are the images you need to output:

https://i.stack.imgur.com/impOl.png
https://i.stack.imgur.com/XfkDe.png?s=48&g=1

The colors of each image should be #0093E8 (NP) and #000000 (NSP). If your language is unable to output that exact shade of blue you may use the closest equivalent. The background may be white or transparent.

The image can be saved to a file or piped raw to STDOUT in any common image file format, or it can be displayed in a window.

*/

package main

import (
	"bytes"
	"encoding/base64"
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
	"strconv"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	typ, _ := strconv.ParseBool(flag.Arg(0))
	bg := BLUE
	if !typ {
		bg = BLACK
	}

	png.Encode(os.Stdout, logo(bg))
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <bool>")
	flag.PrintDefaults()
	os.Exit(2)
}

func check(err error) {
	if err != nil {
		panic(err)
	}
}

func logo(bg color.RGBA) *image.RGBA {
	data, err := base64.StdEncoding.DecodeString(LOGO)
	check(err)

	pic, err := loadimage(data)
	check(err)

	r := pic.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			if pic.RGBAAt(x, y) == BLACK {
				pic.SetRGBA(x, y, bg)
			}
		}
	}
	return pic
}

func loadimage(data []byte) (*image.RGBA, error) {
	m, _, err := image.Decode(bytes.NewBuffer(data))
	if err != nil {
		return nil, err
	}

	r := m.Bounds()
	p := image.NewRGBA(r)
	draw.Draw(p, r, m, image.ZP, draw.Src)
	return p, nil
}

const LOGO = `iVBORw0KGgoAAAANSUhEUgAAADAAAAAwCAYAAABXAvmHAAAABGdBTUEAALGPC/xhBQAAAAZiS0dE
AP8A/wD/oL2nkwAAAAlwSFlzAAAOwQAADsEBuJFr7QAAAMlJREFUaN7tmUsOwCAIRGvi/a9Mdw0L
iT/UoQ7LLpApz8GELCLyBI78BA8KKEVKyT2nRTo7EEKAJxItplc6T3/TOYgQrIAaNjUUWrDzQJMI
QQkYbakHChaStdxE6GoBo9iwAy1/csWLFKIDHsJ0jnsR2oVIVQBKIZwDETzfRcCqQohQtFnwCdBI
9CZGcDAiNOtI211oVSGj5xKh0xc+oxTSMixDuFDvwuhfd2DmnXNq1UYXghWAjA0RghVgYYO8zCdC
IQYZO0ABdrypO0DVHLd22QAAABh0RVh0U29mdHdhcmUAcGFpbnQubmV0IDQuMS42/U4J6AAAAABJ
RU5ErkJggg==`

var (
	BLACK = color.RGBA{0, 0, 0, 255}
	BLUE  = color.RGBA{0, 127, 200, 255}
)
