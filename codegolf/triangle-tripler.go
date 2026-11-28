/*

Task
You must create a program that outputs a triangle of a given size N.

A triangle is made of 3 identical triangles
A triangle of size N should be made of N lines
A triangle's line starts from 1 star, and increases by 2 stars each line

Test Cases:
1 ->

 *
* *

3 ->

     *
    ***
   *****
  *     *
 ***   ***
***** *****

5 ->

         *
        ***
       *****
      *******
     *********
    *         *
   ***       ***
  *****     *****
 *******   *******
********* *********

10 ->


                   *
                  ***
                 *****
                *******
               *********
              ***********
             *************
            ***************
           *****************
          *******************
         *                   *
        ***                 ***
       *****               *****
      *******             *******
     *********           *********
    ***********         ***********
   *************       *************
  ***************     ***************
 *****************   *****************
******************* *******************
Scoring:
This is code-golf so shortest code size wins!

Trailing whitespace is allowed

Credits to Ninsuo for the puzzle

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	tritrip(1)
	tritrip(3)
	tritrip(5)
	tritrip(10)
}

/*

@Lynn

lambda n:[print(i//n*f"{i%n*'**'+'*':^{8*n>>i//n}}")for i in range(n,3*n)]

Explanation
For each i in range(n,3*n), we center i%n*2+1 asterisks in 8*n>>i//n spaces and repeat this string i//n times.

i	i%n	i%n*'**'+'*'	8*n>>i//n	i//n
n	0	*	4n	1
n+1	1	***	4n	1
n+2	2	*****	4n	1
…	…	…	…	…
2n	0	*	2n	2
2n+1	1	***	2n	2
2n+2	2	*****	2n	2
…	…	…	…	…

i%n*'**'+'*' is a byte shorter than (i%n*2+1)*'*'.
f"{s:^{n}}" is an icky but short way to write (s).center(n).

*/

func tritrip(n int) {
	fmt.Printf("n=%v\n", n)
	for i := n; i < 3*n; i++ {
		stars := 2*(i%n) + 1
		spaces := (8 * n) >> (i / n)
		text := center(strings.Repeat("*", stars), spaces)
		for j := 0; j < i/n; j++ {
			fmt.Print(text)
		}
		fmt.Println()
	}
	fmt.Println()
}

func center(str string, width int) string {
	spaces := (width - len(str)) / 2
	return strings.Repeat(" ", spaces) + str + strings.Repeat(" ", width-(spaces+len(str)))
}
