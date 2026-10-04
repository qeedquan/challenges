package main

import (
	"flag"
	"fmt"
	"image"
	"image/color"
	"image/png"
	"log"
	"os"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	data, err := os.ReadFile(flag.Arg(0))
	check(err)

	size := 3073
	for id := 0; len(data) > 0; id++ {
		img := getimage(data)
		name := fmt.Sprintf("%d_%d.png", data[0], id)
		err := writepng(name, img)
		if err != nil {
			fmt.Println(err)
		}
		data = data[size:]
	}
}

func getimage(data []byte) *image.RGBA {
	bound := image.Rect(0, 0, 32, 32)
	img := image.NewRGBA(bound)
	rgba := data[1:]
	for y := range 32 {
		for x := range 32 {
			i := y*32 + x
			r := rgba[i]
			g := rgba[i+1024]
			b := rgba[i+2048]
			img.Set(x, y, color.RGBA{r, g, b, 255})
		}
	}
	return img
}

func writepng(name string, img *image.RGBA) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}
	err = png.Encode(f, img)
	xerr := f.Close()
	if err == nil {
		err = xerr
	}
	return err
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] file.bin")
	flag.PrintDefaults()
	os.Exit(2)
}
