/*

You should write a program or function which receives the volume of a bowl and the volume of the water in it as input and outputs or returns an ASCII representation of a bowl with water in it with the desired volumes.

A bowl has the following structure:

 \     /
  \___/
The bowl has at least one _ character. The count of \'s and /'s are also positive and they are equal due to symmetry.

The volume of the bowl is the total number of _ and space characters between the \'s and /'s plus one for every pair of \ and /. This means the above bowl has the volume of 10:

 \     /  =>  xxxxx x (the last one is for the \/ pair)
  \___/        xxx x (the last one is for the \/ pair)
Note that two different bowl could have the same volume. E.g. both the following bowls have a volume of 18:

\       /
 \     /      \         /
  \___/        \_______/
We can pour some water into the bowl. The water is represented as a row of ~ characters instead of spaces inside the bowl. The bottom row has no spaces so it can not contain the ~'s. This means our example can be filled with water in only one way:

 \~~~~~/
  \___/
Other bowls could be filled in multiple ways:

 \~~~~~/   \     /
  \   /     \~~~/
   \_/       \_/
The volume of the water in a bowl is the volume of the bowl rows below the ~ characters. The above examples have water volumes of 4, 6 and 2 respectively.

Input
Two positive integers, the volume of the bowl and the volume of the water.
You can choose the order of the two numbers.
The two integer can be inputted in any common list format (list, tuple, array, etc.) or as two separate integers.
At least one valid bowl-water configuration is guaranteed for the input values.

Output
The ASCII representation of a bowl with water where the bowl and water volumes match the input.
If you choose to return the result instead of printing, it should be returned as single string (or your language's closest alternative).
Any trailing whitespace is allowed.
No unnecessary leading whitespace is allowed.
If there are multiple correct configurations you are free to choose which one you output but you can only output one of them.

Examples
Each input integer pair is followed by its one or more possible outputs.

6 2
\~~~/
 \_/

10 4
\~~~~~/
 \___/

24 8
\        /
 \~~~~~~/
  \    /
   \__/

42 12 //either of the two output is correct
\           /
 \         /
  \~~~~~~~/
   \     /
    \   /
     \_/

\               /
 \~~~~~~~~~~~~~/
  \___________/

90 68
\~~~~~~~~~~~~~~~~~~~~~/
 \                   /
  \                 /
   \               /
    \_____________/

102 42
\                     /
 \                   /
  \~~~~~~~~~~~~~~~~~/
   \               /
    \             /
     \___________/

This is code golf so the shortest entry wins.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	paint(6, 2)
	paint(10, 4)
	paint(24, 8)
	paint(42, 12)
	paint(90, 68)
	paint(102, 42)
}

// ported from @Cole Cameron solution
func paint(vb, vw int) {
	fmt.Println(vb, vw)
	bowl(enclose(vb, vw))
	fmt.Println()
}

func bowl(w, hb, hw int) {
	for i := 1; hb > 0; i++ {
		hb--
		fmt.Printf("%*s", i, `\`)
		for j := 0; j < w-1+2*hb; j++ {
			switch {
			case hb == 0:
				fmt.Printf("_")
			case hb == hw:
				fmt.Printf("~")
			default:
				fmt.Printf(" ")
			}
		}
		fmt.Println("/")
	}
}

func enclose(vb, vw int) (w, hb, hw int) {
	for hb = 1; hb < math.MaxInt; hb++ {
		for hw = 1; hw < hb; hw++ {
			w = 1
			for dim(w, hw) < vw {
				w++
			}

			if dim(w, hb) == vb {
				return
			}
		}
	}

	return 0, 0, 0
}

func dim(w, h int) int {
	return h*h + w*h - h
}
