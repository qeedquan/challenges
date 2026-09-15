package main

import (
	"flag"
	"fmt"
	"math/rand/v2"
	"time"
)

var flags struct {
	width  int
	length int
	prob   float64
}

func main() {
	parseflags()
	render(flags.width, flags.length, flags.prob)
}

func parseflags() {
	flag.IntVar(&flags.width, "width", 80, "specify window width")
	flag.IntVar(&flags.length, "length", 4, "specify balloon length")
	flag.Float64Var(&flags.prob, "prob", 0.05, "specify balloon probability")
	flag.Parse()
}

func render(width, length int, prob float64) {
	skyr := 60
	skyg := 160
	skyb := 255
	balloons := make([]int, width)
	for {
		fmt.Printf("\033[48;2;%d;%d;%dm", skyr, skyg, skyb)
		for i := range balloons {
			if balloons[i] != 0 {
				if balloons[i] == length {
					balloons[i] = 0
					fmt.Printf(" ")
				} else {
					if balloons[i]%2 == 0 {
						fmt.Printf("\\")
					} else {
						fmt.Printf("/")
					}
					balloons[i] += 1
				}
			} else {
				if rand.Float64()*10 <= prob {
					r := rand.N(256)
					g := rand.N(256)
					b := rand.N(256)
					fmt.Printf("\033[38;2;%d;%d;%dm0\033[39m", r, g, b)
					balloons[i] = 1
				} else {
					fmt.Printf(" ")
				}
			}
		}
		fmt.Println("\033[49m")
		time.Sleep(150 * time.Millisecond)
	}
}
