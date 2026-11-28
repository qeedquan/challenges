/*

Print a continuous sinusoidal wave scrolling vertically on a terminal. The program should not terminate and should continuously scroll down the wave (except until it is somehow interrupted). You may assume overflow is not a problem (i.e. you may use infinite loops with incrementing counters, or infinite recursion).

The wave should satisfy the following properties:

Amplitude = 20 chars (peak amplitude)
Period = 60 to 65 lines (inclusive)
The output should only consist of spaces, newline and |
After each line of output, pause for 50ms
Sample output:

                    |
                      |
                        |
                          |
                            |
                              |
                                |
                                 |
                                   |
                                    |
                                     |
                                      |
                                       |
                                        |
                                        |
                                        |
                                        |
                                        |
                                        |
                                       |
                                       |
                                      |
                                     |
                                   |
                                  |
                                |
                               |
                             |
                           |
                         |
                       |
                     |
                   |
                 |
               |
             |
            |
          |
        |
       |
     |
    |
   |
  |
 |
 |
 |
 |
 |
 |
 |
  |
   |
    |
     |
      |
        |
         |
           |
             |
               |
                 |
                   |
                     |
                       |
                         |
                           |
                             |
                              |
                                |
                                  |
                                   |
                                    |
                                      |
                                      |
                                       |
                                        |
                                        |
                                        |
                                        |
                                        |
                                        |
                                       |
                                       |
                                      |
                                    |
                                   |
                                  |
                                |
                               |
                             |
                           |
                         |
                       |
                     |
                   |
                 |
               |
             |
           |
          |
        |
       |
     |
    |
   |
  |
 |
 |
 |
 |
 |
 |
 |
  |
   |
    |
     |
       |
        |
          |
            |
             |
               |
                 |
                   |
The above output should go on forever unless otherwise interrupted, e.g. SIGINT or SIGKILL, or closing terminal window, or you power off your machine, or the Sun swallows the Earth, etc.

Shortest code wins.

Note. I am aware of a similar problem on Display Scrolling Waves but this isn't exactly the same. In my problem, the wave is not to be scrolled "in place" - just output it on a terminal. Also, this is an ascii-art problem, so don't use Mathematica to plot it.

*/

package main

import (
	"fmt"
	"math"
	"time"
)

func main() {
	sinewave()
}

func sinewave() {
	t := 0.0
	for {
		x := 20*math.Sin(0.1*t) + 21
		fmt.Printf("%*c\n", int(x), '|')
		t = math.Mod(t+1, 2*math.Pi/0.1)
		time.Sleep(50 * time.Millisecond)
	}
}
