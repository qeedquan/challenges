/*

Write a program or a function that can print out arbitrarily sized smiley face in ascii art. The smiley face can be however you want, but the eyes can't be single points (that is, they have to be circles at large size). Your program should be able to take in an integer between 16 and 1000 that represents the dimensions to render the face.

Here is a sample output.
                  OOOOOOOOOOOOOO
               OOO              OOO
             OOO                  OOO
           OO                        OO
          OO                          OO
        OO                              OO
       OO                                OO
      OO                                  OO
     OO                                    OO
     O                                      O
    O                                        O
   OO      OOO                      OOO      OO
   O       O O                      O O       O
  O        OOO                      OOO        O
  O                                            O
 OO                                            OO
 O                                              O
 O                                              O
O                                                O
O                                                O
O                                                O
O                                                O
O                                                O
O                                                O
O                                                O
O                                                O
O                                                O
O                                                O
O                                                O
O                                                O
O                   OOOOOOOOOO                   O
O                 OOO        OOO                 O
 O              OOO            OOO              O
 O              O                O              O
 OO                                            OO
  O                                            O
  O                                            O
   O                                          O
   OO                                        OO
    O                                        O
     O                                      O
     OO                                    OO
      OO                                  OO
       OO                                OO
        OO                              OO
          OO                          OO
           OO                        OO
             OOO                  OOO
               OOO              OOO
                  OOOOOOOOOOOOOO

thanks to Steve132 for the challenge at r/dailyprogrammer_ideas ! .. if you have a challenge you could suggest it there :)

*/

package main

import (
	"flag"
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	n, _ := strconv.Atoi(flag.Arg(0))
	smiley(n)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <n>")
	flag.PrintDefaults()
	os.Exit(2)
}

// ported from @Cosmologicon solution
func smiley(n int) {
	n *= 2
	N := float64(n)
	S := math.Sin(0.5)
	C := math.Cos(0.5)
	for jy := range n / 2 {
		for jx := range n {
			X := float64(jx)
			Y := float64(jy)

			X = (X - N/2.0 + 0.5) * 200 / N
			Y = (-Y + N/4.0 - 0.5) * 400 / N

			x := C*X - S*Y
			y := S*X + C*Y

			r0 := math.Hypot(x, y)
			r1 := math.Sqrt(sqr(math.Abs(x)-30) + sqr(y/2-15))
			r2 := math.Sqrt(sqr(x/2) + sqr(y+30))
			switch {
			case 85 < r0 && r0 <= 100:
				fallthrough
			case r1 < 15:
				fallthrough
			case 20 < r2 && r2 < 35 && y < -30:
				fmt.Printf("#")
			default:
				fmt.Printf(" ")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

func sqr(x float64) float64 {
	return x * x
}
