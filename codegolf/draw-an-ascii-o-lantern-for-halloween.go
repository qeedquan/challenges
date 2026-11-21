/*

Halloween is almost here, the holiday after which most people need to wean themselves off a hollow diet of sugar.

Write a program that takes in a positive integer. If the integer is less than 31 (1 through 30), output this ASCII-art jack-o'-lantern, looking to the right as if looking forward to Halloween:

 _____I_____
| | | | | | |
| | |^| |^| |
| | | |^| | |
| | |VvVvV| |
|_|_|_|_|_|_|
If the input is 31 (the October date Halloween is on), output the same ASCII-o'-lantern, but looking left:

 _____I_____
| | | | | | |
| |^| |^| | |
| | |^| | | |
| |VvVvV| | |
|_|_|_|_|_|_|
If the input is greater than 31, output a bloated-looking ASCII-o'-lantern who probably ate too much candy. He can face either left or right since queasyness can be disorientating. So output:

 _____I_____
| | | | | | |
| |o| |o| | |
| | |^| | | |
| |XXXXX| | |
|_|_|_|_|_|_|
or

 _____I_____
| | | | | | |
| | |o| |o| |
| | | |^| | |
| | |XXXXX| |
|_|_|_|_|_|_|
Whichever you prefer. It may even be different for different numbers above 31.

The shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	lantern(3)
	lantern(31)
	lantern(300)
	lantern(400)
}

func lantern(n int) {
	switch {
	case n < 31:
		fmt.Println(LANTERN0)
	case n == 31:
		fmt.Println(LANTERN1)
	case rand.Intn(2) == 0:
		fmt.Println(LANTERN2)
	default:
		fmt.Println(LANTERN3)
	}
}

const LANTERN0 = `
 _____I_____
| | | | | | |
| | |^| |^| |
| | | |^| | |
| | |VvVvV| |
|_|_|_|_|_|_|
`

const LANTERN1 = `
 _____I_____
| | | | | | |
| |^| |^| | |
| | |^| | | |
| |VvVvV| | |
|_|_|_|_|_|_|
`

const LANTERN2 = `
 _____I_____
| | | | | | |
| |o| |o| | |
| | |^| | | |
| |XXXXX| | |
|_|_|_|_|_|_|
`

const LANTERN3 = `
 _____I_____
| | | | | | |
| | |o| |o| |
| | | |^| | |
| | |XXXXX| |
|_|_|_|_|_|_|
`
