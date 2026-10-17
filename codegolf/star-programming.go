/*

The challenge
Write a program or function that prints stars! The program will receive two parameters by standar input: Size of the star and number of points of the star. A star can be any size between 0 and 10 and have 3, 4 or 5 points. The input parameters are separated by a comma, for example: 5,3 means a size 5 star with 3 points. The stars are composed by asterisks *

Consider the program will only receive valid inputs.

The prints must be correctly spaced so we can see pretty stars in the output!

Parameters explanations
Points
Is the number of arms counting from the central asterisk.

3 points stars:

       *
       *
       *
     *   *
    *     *
They are composed by a vertical arms and two diagonal arms. The separation between diagonal arms is 2*size-1

4 points stars

   *     *
    *   *
      *
    *   *
   *     *
They have the form of a X and composed by two diagonal lines. The separation between lines is 2*(size-1)+1

5 points stars

     *
     *
 * * * * *
    * *
   *   *
They are composed by a vertical line and a horizontal line. Each asterisk in the horizontal line is separated by one space. Also they have two diagonal lines, with a separation between themselves of 2*(size-2)+1

Size
Size is the number of asterisks that has each arm of the star counting from the central asterisk (inclusive).

Size 1 stars are composed by a single asterisk

*
Size 2 stars examples

3 points

       *
       *
     *   *
4 points stars

    *   *
      *
    *   *
5 points stars

     *
   * * *
    * *
You have examples of the size 3 stars in the Points parameter explanation.

Winning criteria
Shortest code wins. Code have to be checked with the following input parameters: 3,2 3,3 4,2 4,3 5,2 5,3

Bonus
-25% characters count for creating a size 6 pointed with the criteria explained before (6 arms and the size is the number of asterisks counting from the central asterisk). It can be any form you want while it respect the specifications. A example of a size 6 star with size 3:

      *
      *
  * * * * *
    * * *
   *  *  *
6 points stars must be checked with the following inputs 6,2 6,3.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	star(3, 2)
	star(3, 3)
	star(4, 2)
	star(4, 3)
	star(5, 2)
	star(5, 3)
	star(6, 3)
	star(6, 2)
	star(6, 4)
}

// Ported from @art solution
func star(size, points int) {
	fmt.Printf("n=%d p=%d\n", size, points)
	if size < 1 || points < 1 {
		return
	}

	area := points * 6
	center := area / 2

	grid := make([][]byte, area+1)
	for i := range grid {
		grid[i] = make([]byte, area+1)
		for j := range grid[i] {
			grid[i][j] = ' '
		}
	}

	grid[center][center] = '*'
	for step := range size {
		for distance := range points {
			x, y := polar(2*math.Pi*float64(step)/float64(size), float64(points*distance))
			x = math.Round(x)
			y = math.Round(y)
			grid[center+int(x)][center+int(y)] = '*'
		}
	}

	for i := range grid {
		fmt.Printf("%s\n", grid[i])
	}
	fmt.Println()
}

func polar(angle, radius float64) (float64, float64) {
	x := radius * math.Sin(angle)
	y := radius * math.Cos(angle)
	return x, y
}
