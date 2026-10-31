/*

https://upload.wikimedia.org/wikipedia/en/b/b7/Missingno.png

I think is about time to do another Pokemon challenge! Even if Pokémon Go is not as mainstream as it used to be...

The task.
Just draw a MISSINGNO. MISSINGNO is an unofficial Pokémon species found in the video games Pokémon Red and Blue. IGN has noted MISSINGNO appearance in Pokémon Red and Blue as one of the most famous video game glitches.

How MISSINGNO looks like?
This Pokémon is a 3 tiles wide 7 tiles high image of random pixels. Each tile is 8x8 pixels. Considering x as horizontal coordinate which increases from left to right, y as vertical coordinate which increases from top to bottom and [x, y] as coordinate system, the tiles [0, 0], [0, 1] and [0, 2] are blank. The original MISSINGNO appears in Game Boy color roughly as the screenshot below:

https://i.sstatic.net/OLhN8.png

(source: nocookie.net)

Your MISSINGNO.
Your MISSINGNO shoudn't be exactly as the one in the screenshots above, but it should follow this pattern:

Should be formed of 21 tiles, 3 tiles wide 7 tiles high.
Every tile should have at least 9 colors, more than 9 colors is alowed, less is forbidden.
Every tile should have the same pixels in width and in heigth: this is, every tile should be a square.
Every tile should be of the same size, but they can be of any arbitrary size as long as they can show at least 9 colors (a MISSINGNO of 21 tiles of 3x3 pixels is as valid as one with 21 1000x1000 pixels tiles).
Tiles [0, 0], [0, 1] and [0, 2] should be transparent (alpha 0), look at How MISSINGNO looks like? to know the coordinates system.
Transparent means transparent. So any color is acceptable as long as it is completely transparent (alpha 0).
The opaque tiles shall be completely opaques, no transparent or semi-transparent pixels allowed.
Repeated opaque tiles are forbidden.
As long as the tiles follows the rules above, they can be anything: either procedural random pixels tiles or (as an example) pictures from google image search are alowed.
Your output.
Your output should be a image in any format your language supports.

The size of the image should be 3 * tile width wide and 7 * tile height high with no additional pixels alowed. So if you're using 3x3 tiles the image size should be: 9 pixels width and 21 pixels high, with 42x42 tiles the image size should be: 126 pixels width and 294 pixels high.
The ouptut image should be different every program call. Look at Your MISSINGNO to know about the size of the tiles.
The task is to generate the MISSINGNO image, not to show it. So as long as the image is generated the program is valid (but please, upload your results! all of us want to enjoy them!).
Your program.
It can accept a single integer value, this value will be the size of the MISSINGNO tiles.

You can assume that the input will be always possitive and equal to or greater than 3. Look at Your MISSINGNO to know about the size of the tiles.
If no input is provided, the default value is 8.
This is code golf, so the shortest code in bytes win!

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/png"
	"log"
	"math/rand"
	"os"
)

var flags struct {
	tilewidth  int
	tileheight int
	tilesize   int
}

var palette = []color.RGBA{
	{255, 240, 255, 255},
	{184, 144, 168, 255},
	{214, 173, 181, 255},
	{123, 123, 148, 255},
	{25, 16, 16, 255},
}

func main() {
	parseflags()
	picture := generate(flags.tilewidth, flags.tileheight, flags.tilesize)

	file, err := os.Create(flag.Arg(0))
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	err = png.Encode(file, picture)
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] output.png")
	flag.PrintDefaults()
	os.Exit(2)
}

func parseflags() {
	flag.Usage = usage
	flag.IntVar(&flags.tilewidth, "tilewidth", 3*5, "tile width")
	flag.IntVar(&flags.tileheight, "tileheight", 7*5, "tile height")
	flag.IntVar(&flags.tilesize, "tilesize", 16, "tile size")
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}
}

func generate(tilewidth, tileheight, tilesize int) *image.RGBA {
	bounds := image.Rect(0, 0, tilewidth*tilesize, tileheight*tilesize)
	picture := image.NewRGBA(bounds)
	for tiley := range tileheight {
		for tilex := range tilewidth {
			if tilex == 0 && tiley < 2 {
				continue
			}
			fill(picture, tilex*tilesize, tiley*tilesize, tilesize)
		}
	}
	return picture
}

func fill(picture *image.RGBA, x, y, size int) {
	index := rand.Intn(len(palette))
	base := palette[index]
	for dy := range size {
		for dx := range size {
			dr := rand.Intn(10)
			dg := rand.Intn(10)
			db := rand.Intn(10)
			rgba := color.RGBA{
				saturate8(int(base.R) + dr),
				saturate8(int(base.G) + dg),
				saturate8(int(base.B) + db),
				255,
			}
			picture.SetRGBA(x+dx, y+dy, rgba)
		}
	}
}

func saturate8(x int) uint8 {
	if x < 0 {
		x = 0
	} else if x > 255 {
		x = 255
	}
	return uint8(x)
}
