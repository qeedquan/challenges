/*

Draw a program or function that will write to STDOUT n times (each for one step) a string that contains a dot . at the location of the walker. The program also needs to write a line every s seconds (or wait s seconds after each line).

A random walk is a mathematical formalization of a path that consists of a succession of random steps (wiki), such that every new step will be the last step plus a new value, so any tstep value is just the sum of all the random values before ir plus the initial value.

The program should take 2 inputs and will use only spaces " " and dots "." on the output. The start value of the walker will be 20 such that the output should be a dot after 19 spaces.

                  . #19 spaces then a dot
Every new step the value will be the last value of the walker plus one of these[-2-1,0,1,2](20% chance each). After the new position is printed the program should wait s seconds and the go to the next step. If the step takes the walker outsite the range 1 to 40 it should be just ignored and the walker position stays the same. The number of spaces will always be a number from 0 to 39.

Example
#input
Mywalk(s = 0.1, n = 30)

#output
                     .
                    .
                      .
                        .
                          .
                           .
                            .
                          .
                         .
                          .
                           .
                            .
                           .
                          .
                           .
                           .
                         .
                         .
                          .
                            .
                           .
                          .
                           .
                           .
                           .
                         .
                          .
                         .
                          .
                          .
Considerations
You may take the input as any reasonable format

The shortest code wins

It's okay if your program only accept the seconds as integers

*/

package main

import (
	"fmt"
	"math/rand"
	"strings"
	"time"
)

func main() {
	walker(100*time.Millisecond, 30)
}

func walker(s time.Duration, n int) {
	d := []int{-2 - 1, 0, 1, 2}
	p := 20
	for i := 0; i < n; i++ {
		fmt.Printf("%s.\n", strings.Repeat(" ", p-1))
		time.Sleep(s)
		p = clamp(p+d[rand.Intn(len(d))], 1, 40)
	}
}

func clamp(x, a, b int) int {
	if x < a {
		x = a
	} else if x > b {
		x = b
	}
	return x
}
