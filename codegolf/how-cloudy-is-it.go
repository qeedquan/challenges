/*

Challenge
Given an image of the sky, you must output the cloud cover in oktas. The image supplied will be an image file (the type is up to you) and the output should be to STDOUT.

Oktas
In meteorology, an okta is a unit of measurement used to describe the amount of cloud cover at any given location such as a weather station. Sky conditions are estimated in terms of how many eighths of the sky are covered in cloud, ranging from 0 oktas (completely clear sky) through to 8 oktas (completely overcast).

The sky will always be a picture from around midday (so, blue sky, not red/night sky).

The colour of a cloud will always be a colour which follows the following pattern:

#ABCDEF
Where AB >= C0, CD >= C0 and EF >= C0.

Or, in RGB:

(A, B, C)
Where A >= 192, B >= 192 and C >= 192.

Here are the percentage coverages related to the oktas:

0%    - 0 oktas
12.5% - 1 okta
25%   - 2 oktas
37.5% - 3 oktas
50%   - 4 oktas
62.5% - 5 oktas
75%   - 6 oktas
87.5% - 7 oktas
100%  - 8 oktas
The percentages are the percentage of the image which is cloud.

If you the percentage cloud of your image is not a multiple of 12.5, you should round to the nearest.

Output
The output should just be the okta number (you don't have to say the unit).

Examples
1 okta (18.030743615677714% cloud)
https://upload.wikimedia.org/wikipedia/commons/1/16/Appearance_of_sky_for_weather_forecast,_Dhaka,_Bangladesh.JPG

0 oktas (0.0% cloud)
https://1.bp.blogspot.com/-lstV3uZJbPM/UHhLG5_vqAI/AAAAAAAAHGw/Hr9GN52jasM/s1600/spanish-sky.jpeg

3 oktas (42.66319444444445% cloud)
https://i.stack.imgur.com/qmRjN.jpg

1 okta (12.000401814778645% cloud)
https://i.stack.imgur.com/KTBF5.jpg

Python code used to calculate numbers

from PIL import Image

fname = input()

image = Image.open(fname)
pix = image.load()

npixels = image.size[0]*image.size[1]
ncloud = 0

for x in range(image.size[0]):
    for y in range(image.size[1]):
        col = pix[x,y]
        if col[0] >= 192 and col[1] >= 192 and col[2] >= 192:
            ncloud += 1

print(ncloud/npixels*100)

Winning
Shortest code in bytes wins.

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"image"
	"image/draw"
	_ "image/gif"
	_ "image/jpeg"
	_ "image/png"
	"log"
	"math"
	"os"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("cloudiness: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	m, err := loadimage(flag.Arg(0))
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println(cloudiness(m))
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] <image>")
	flag.PrintDefaults()
	os.Exit(2)
}

func loadimage(name string) (*image.RGBA, error) {
	f, err := os.Open(name)
	if err != nil {
		return nil, err
	}
	defer f.Close()

	r := bufio.NewReader(f)
	m, _, err := image.Decode(r)
	if err != nil {
		return nil, err
	}

	b := m.Bounds()
	p := image.NewRGBA(b)
	draw.Draw(p, b, m, image.ZP, draw.Src)
	return p, nil
}

func cloudiness(m *image.RGBA) int {
	t := 0.0
	r := m.Bounds()
	w := r.Dx()
	h := r.Dy()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			c := m.RGBAAt(x, y)
			if c.R >= 192 && c.G >= 192 && c.B >= 192 {
				t++
			}
		}
	}
	return oktas(t / float64(w*h))
}

func oktas(p float64) int {
	const level = 0.125
	k := p / level
	k0 := math.Floor(k)
	k1 := math.Ceil(k)
	d0 := math.Abs(p - k0*level)
	d1 := math.Abs(p - k1*level)
	if d0 < d1 {
		return int(k0)
	}
	return int(k1)
}
