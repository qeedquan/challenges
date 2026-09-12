/*

This challenge is in honor of the tacky Christmas lights at my in laws' house.

The challenge is to create a graphical output showing the decoration in "real time".

The video (gif or other format) will have n-by-m vertical and horizontal "lights". 5 <= m,n <= 40. The frame size and resolution may vary dependent on n and m, but must be at least 50x50 pixels for n,m=5 (vector graphics is OK). A picture with n=6 and m=5 will look something like this:

https://i.sstatic.net/IJkq0.png

The decoration:
Colors:

All lights will have one of the following 6 RGB-colors {255,0,0}, {0,255,0}, {0,0,255}, {255,255,0}, {0,255,255} and {255,0,255}.

Animation:

n and m will be taken as input on any reasonable format and in the order you like
The image will change every dt = 25 ms. Deviations are OK if it's due to "outside factors" such as limitation in the interpreter, slow computer etc.
If it's impossible to set the time step manually, then the default time step is accepted.
All lights will be red ({255,0,0}) at t=0.
There's always a 5% chance that the first light (top-left) will change color. All colors (except the color it currently has) should be equally likely.
Each light (except the first) will get the color of the light to its left. If the light is at the far left then it will get the color of the light on the far right on the row above. The lights are numbered as shown below. Light number k will get the color of the light number k-1.

 1  2  3  4  5  6
 7  8  9 10 11 12
13 14 15 16 17 18
The output should in theory run for ever (unless your language / interpreter has some limitation that prevents this).

Please provide a sample of at least 5 seconds, preferably more in the answer (this is an encouragement, not a requirement). (A link to TIO or similar is of course OK too :D )
Frames, axes, grid lines etc are accepted.

https://i.sstatic.net/0kc10.gif

15-by-30

https://i.sstatic.net/5UYW8.gif

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"time"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	w, _ := strconv.Atoi(flag.Arg(0))
	h, _ := strconv.Atoi(flag.Arg(1))
	animate(w, h)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: w h")
	flag.PrintDefaults()
	os.Exit(2)
}

func animate(w, h int) {
	p := []string{"\x1b[1;41m ", "\x1b[1;42m ", "\x1b[1;43m ", "\x1b[1;44m ", "\x1b[1;45m ", "\x1b[1;46m "}

	m := make([]string, w*h)
	for i := range m {
		m[i] = p[0]
	}

	b := bufio.NewWriter(os.Stdout)
	for {
		fmt.Fprintf(b, "\x1b[0m\x1b[2J\x1b[f\n")

		c := m[0]
		if rand.Float64() <= 0.05 {
			for {
				i := rand.Intn(len(p))
				if c != p[i] {
					c = p[i]
					break
				}
			}
		}
		m = append([]string{c}, m[:len(m)-1]...)

		for x := 0; x < w*h; x += w {
			for i := range w {
				fmt.Fprintf(b, m[x+i])
			}
			fmt.Fprintln(b)
		}
		b.Flush()

		time.Sleep(15 * time.Millisecond)
	}
}
