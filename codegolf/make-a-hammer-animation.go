/*

The goal is to make a two frame animation with ASCII art of a hammer smacking a table.

Trailing white-space is allowed and the frames need to repeat continuously. The program should iterate over both frames with a time of 0.5 seconds between frames.

Lowest byte count wins for each language!

Sample:

Animation Frames:

Frame 1:
 -------------------
|                   |
|                   |
|                   |
 -------------------
         /  /
        /  /
       /  /
      /  /
     /  /
    /  /
   /  /
  /  /
 /  /
 \ /


                        ---------------------------
                       |                           |


Frame 2:

                                        ----------
                                       |          |
                                       |          |
                                       |          |
 --------------------------------------|          |
|                                      |          |
 --------------------------------------|          |
                                       |          |
                                       |          |
                                       |          |
                                        ----------
                                  -------------------------------
                                |                                |

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	art := []string{HAMMER1, HAMMER2}
	for i := 0; ; i ^= 1 {
		time.Sleep(500 * time.Millisecond)
		fmt.Printf("\033[H\033[2J")
		fmt.Println(art[i])
	}
}

const HAMMER1 = `
 -------------------
|                   |
|                   |
|                   |
 -------------------
         /  /
        /  /
       /  /
      /  /
     /  /
    /  /
   /  /
  /  /
 /  /
 \ /


                        ---------------------------
                       |                           |
`

const HAMMER2 = `
                                        ----------
                                       |          |
                                       |          |
                                       |          |
 --------------------------------------|          |
|                                      |          |
 --------------------------------------|          |
                                       |          |
                                       |          |
                                       |          |
                                        ----------
                                  -------------------------------
                                |                                |
`
