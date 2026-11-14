/*

"A picture is worth a thousand words"—so the old saying goes. The average word is about four characters long, so a picture conveys 4kB of information.
But how much entropy, rather than information, can a picture convey?

Your task is to generate an image, exactly 4,000 bytes in size, with the highest entropy possible.
You may use any language, libraries, or image format you choose, and you may output to the console or to a file so long as you upload your image here.

Scoring
Your score is the compression ratio (4000 ÷ compressed size) when your image is compressed with GNU tar version 1.28 and gzip version 1.6,
using the DEFLATE algorithm and default settings — specifically, the command tar -czvf out.tar.gz image. The smallest compression ratio wins.

*/

package main

import (
	crand "crypto/rand"
	"flag"
	"fmt"
	"image"
	"image/png"
	"log"
	"os"
)

func main() {
	width := flag.Int("width", 512, "image width")
	height := flag.Int("height", 512, "image height")
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	img := gen(*width, *height)
	f, err := os.Create(flag.Arg(0))
	check(err)
	check(png.Encode(f, img))
	check(f.Close())
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] output.png")
	flag.PrintDefaults()
	os.Exit(2)
}

func gen(width, height int) *image.RGBA {
	img := image.NewRGBA(image.Rect(0, 0, width, height))
	crand.Read(img.Pix)
	return img
}
