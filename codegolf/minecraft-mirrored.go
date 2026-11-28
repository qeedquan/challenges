/*

Write a program or function that takes in a positive integer.

If the integer is even (2, 4, 6, ...), print or return this exact ASCII art string:

                       __    __   __             __  ___
  /\  /\    |  |\  |  |     /    |  |     /\    |     |
 /  \/  \   |  | \ |  |--  |     |--\    /__\   |--   |
/        \  |  |  \|  |__   \__  |   \  /    \  |     |
If the integer is odd (1, 3, 5, ...), print or return this exact ASCII art string:

                       __    __
\        /  |  |  /|  |     /    |   /  \ __ /  |     |
 \  /\  /   |  | / |  |--  |     |--/    \  /   |--   |
  \/  \/    |  |/  |  |__   \__  |__|     \/    |__  _|_

You may assume the input is always a positive integer.

In both output cases there may optionally be any number of trailing spaces up to the right edge of the "T" on each line, and/or a single trailing newline. Note how there are two columns of spaces between each letter.

The shortest code in bytes wins.

*/

package main

import "fmt"

func main() {
	output(0)
	output(1)
}

func output(n int) {
	switch n & 1 {
	case 0:
		fmt.Println(ART1)
	default:
		fmt.Println(ART2)
	}
}

const ART1 = `
                       __    __   __             __  ___
  /\  /\    |  |\  |  |     /    |  |     /\    |     |
 /  \/  \   |  | \ |  |--  |     |--\    /__\   |--   |
/        \  |  |  \|  |__   \__  |   \  /    \  |     |
`

const ART2 = `
                       __    __
\        /  |  |  /|  |     /    |   /  \ __ /  |     |
 \  /\  /   |  | / |  |--  |     |--/    \  /   |--   |
  \/  \/    |  |/  |  |__   \__  |__|     \/    |__  _|_
`
