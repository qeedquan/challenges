/*

Background
Summer is well over in the Northern Hemisphere, and a lot of us miss the sun, the beaches, the waves of the ocean... This challenge aims at cheering them up by reminding them of the sea.

The challenge
Here is the sea :

             **              **              **              **              **
         ****            ****            ****            ****            ****
      *****           *****           *****           *****           *****
    **   **         **   **         **   **         **   **         **   **
  **      **      **      **      **      **      **      **      **      **
**          ******          ******          ******          ******          ****
The sea is made of 5 times this wave pattern :

            **
        ****
     *****
   **   **
 **      **
*          *****
Note that the pattern is 16 characters long, and the sea is 5 times this pattern = 80 characters long.

Which you can print into a terminal using this command-line :

perl -e 'print "            **  \n        ****    \n     *****      \n   **   **      \n **      **     \n*          *****\n"'
Or this one :

perl -e 'print " "x12, "*"x2, " "x2, "\n", " "x8, "*"x4, " "x4, "\n", " "x5, "*"x5, " "x6, "\n", " "x3, "*"x2, " "x3, "*"x2, " "x6, "\n", " "x1, "*"x2, " "x6, "*"x2, " "x5, "\n", "*"x1, " "x10, "*"x5, "\n"'
(The second one should make it easier for you to get the exact pattern)

Your task is to display the sea in a terminal, and make look like the waves are moving toward the right : it needs to shift to the right at a speed of 1 character each 100ms (= 10 times each seconds). No character should be printed after the 80th column, but as the rightmost wave disappears, a new one appears on the left.
Here is an example of output :

time = 0.0s

             **              **              **              **              **
         ****            ****            ****            ****            ****
      *****           *****           *****           *****           *****
    **   **         **   **         **   **         **   **         **   **
  **      **      **      **      **      **      **      **      **      **
**          ******          ******          ******          ******          ****
time = 0.1s

              **              **              **              **              **
          ****            ****            ****            ****            ****
       *****           *****           *****           *****           *****
     **   **         **   **         **   **         **   **         **   **
   **      **      **      **      **      **      **      **      **      **
***          ******          ******          ******          ******          ***
time = 0.2s

*              **              **              **              **              *
           ****            ****            ****            ****            ****
        *****           *****           *****           *****           *****
      **   **         **   **         **   **         **   **         **   **
    **      **      **      **      **      **      **      **      **      **
****          ******          ******          ******          ******          **
time = 0.3s

**              **              **              **              **
            ****            ****            ****            ****            ****
         *****           *****           *****           *****           *****
       **   **         **   **         **   **         **   **         **   **
     **      **      **      **      **      **      **      **      **      **
*****          ******          ******          ******          ******          *
time = 0.4s

 **              **              **              **              **
*            ****            ****            ****            ****            ***
          *****           *****           *****           *****           *****
        **   **         **   **         **   **         **   **         **   **
      **      **      **      **      **      **      **      **      **      **
******          ******          ******          ******          ******
Of course, each output should replace the previous one.

You can run this code into a unix terminal to see how it should look with the animation:

perl -M5.010 -MTime::HiRes=sleep -E '@arr=([($")x12,($n="*")x2,($")x3],[($")x8,($n)x4,($")x4],[($")x5,($n)x5,($")x6],[($")x3,($n)x2,($")x3,($n)x2,($")x6],[($")x1,($n)x2,($")x6,($n)x2,($")x5],[($n)x1,($")x10,($n)x5]);while(++$j){for$i(0..5){for$k(0..15) {$out[$i][16*$_+$k]=$arr[$i][($k-$j)%16]for 0..4}}say"\e[H",$/,join$/,map{join"",@$_}@out;sleep 0.1}'
(Note that this code isn't very well golfed: I just made it compact enough to be convenient to run in a terminal.)

Winning criterion
This is codegolf, so shortest code in byte wins.

*/

package main

import (
	"fmt"
	"strings"
	"time"
)

func main() {
	waves()
}

func clear() {
	fmt.Printf("\033c")
}

// Ported from @Pete Arden solution
func waves() {
	waves := []string{
		repeat("            **  "),
		repeat("        ****    "),
		repeat("     *****      "),
		repeat(" **      **     "),
		repeat("*          *****"),
	}

	offset := 0
	for {
		clear()
		for _, wave := range waves {
			fmt.Println(spread(wave, offset))
		}
		time.Sleep(100 * time.Millisecond)
		offset = (offset + 1) & 15
	}
}

func repeat(input string) string {
	return strings.Repeat(input, 5)
}

func spread(input string, offset int) string {
	result := input[16-offset:] + input
	return result[:80]
}
