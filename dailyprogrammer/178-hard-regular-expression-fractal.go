/*

Description:
For today's challenge you will be generating fractal images from regular expressions. This album describes visually how it works:

[https://imgur.com/a/QWMGi]

For the challenge you don't need to worry about color, just inclusion in the set selected by the regular expression. Also, don't implicitly wrap the regexp in ^...$. This removes the need to use .* all the time.

Input:
On standard input you will receive two lines. The first line is an integer n that defines the size of the output image (nxn). This number will be a power of 2 (8, 16, 32, 64, 128, etc.). The second line will be a regular expression with literals limited to the digits 1-4. That means you don't need to worry about whitespace.

Output:
Output a binary image of the regexp fractal according to the specification. You could print this out in the terminal with characters or you could produce an image file. Be creative! Feel free to share your outputs along with your submission.

Example Input & Output:
Input Example 1:
 256
 [13][24][^1][^2][^3][^4]
Output Example 1:
[http://i.imgur.com/zhSr365.png]

Input Example 2 (Bracktracing) :
 256
 (.)\1..\1
Output Example 2:
[http://i.imgur.com/iLu7Pq4.png]

Extra Challenge:
Add color based on the length of each capture group.

Challenge Credit:
Huge thanks to u/skeeto for [his idea posted on our idea subreddit] (http://www.reddit.com/r/dailyprogrammer_ideas/comments/24ykjs/intermediatehard_regexp_fractals/)

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/png"
	"log"
	"math"
	"os"
	"regexp"
	"strconv"
)

func main() {
	log.SetPrefix("regex-fractal: ")
	log.SetFlags(0)

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	n, err := strconv.Atoi(flag.Arg(0))
	check(err)

	re, err := regexp.Compile(flag.Arg(1))
	check(err)

	m := gen(ilog2(n), re)
	png.Encode(os.Stdout, m)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] size pattern")
	flag.PrintDefaults()
	os.Exit(2)
}

func gen(n int, re *regexp.Regexp) *image.RGBA {
	const sym = "3241"

	s := 1 << n
	r := image.Rect(0, 0, s, s)
	m := image.NewRGBA(r)
	id := make([]byte, n)
	for y := range s {
		for x := range s {
			for i := range n {
				ix := (x / (1 << i)) & 1
				iy := (y / (1 << i)) & 1
				id[n-i-1] = sym[(ix<<1)+iy]
			}

			if re.Match(id) {
				m.Set(x, y, image.White)
			} else {
				m.Set(x, y, image.Black)
			}
		}
	}
	return m
}

func ilog2(x int) int {
	return int(math.Log2(float64(x)))
}
