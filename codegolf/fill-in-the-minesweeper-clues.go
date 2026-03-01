/*

Minesweeper is a popular puzzle game where you must discover which tiles are "mines" without clicking on those tiles. Each tile is either a mine (represented by *) or a clue, i.e. a number from 0 to 8 representing how many of the 8 neighboring tiles are mines. Your task today is to take a board containing the mines and fill in all of the clues. For example, look at the following 5x4 board, with 5 mines:

 *
*  *
  *
    *
After filling in the clues, the board will look like this:

2*211
*33*1
12*32
0112*
Details
You must write either a full-program or a function that takes in a grid of characters containing only spaces and asterisks and outputs another grid where each space is replaced with the number of adjacent mines (asterisks). Any of these are acceptable formats for your grids:

A string with newlines in it

A 2D list of characters/single character strings

A list of strings

You can assume the grid will be at least 1x1, although it is possible for it to be all mines or all spaces.

The input grid will always be padded with the appropriate number of spaces. As usual, this is code-golf, so standard loopholes apply and the shortest answer in bytes wins!

Sample IO
So that you can see the whitespace, I will show all sample IO with brackets around it.

Input:
[    * ]
[*     ]
[      ]
[      ]
[  **  ]
[ *  * ]

Output:
[1101*1]
[*10111]
[110000]
[012210]
[12**21]
[1*33*1]

Input:
[****]
[****]

Output:
[****]
[****]

Input:
[   ]
[   ]
[   ]
[   ]

Output:
[000]
[000]
[000]
[000]

Input:
[*   ]
[**  ]
[    ]
[   *]

Ouput:
[*310]
[**10]
[2221]
[001*]

Input:
[**    ]
[*    *]
[  *   ]
[      ]
[*     ]
[****  ]

Output:
[**1011]
[*4211*]
[12*111]
[121100]
[*43210]
[****10]

Input:
[     *    ]
[        * ]
[     *    ]
[**   ***  ]
[      *** ]
[          ]
[       ** ]
[  * *     ]
[*      ** ]
[       ** ]

Output:
[00001*1111]
[00002221*1]
[22102*4321]
[**102***31]
[221013***1]
[0000013542]
[0112111**1]
[12*2*12442]
[*212112**2]
[1100002**2]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]byte{
		[]byte("    * "),
		[]byte("*     "),
		[]byte("      "),
		[]byte("      "),
		[]byte("  **  "),
		[]byte(" *  * "),
	}, [][]byte{
		[]byte("1101*1"),
		[]byte("*10111"),
		[]byte("110000"),
		[]byte("012210"),
		[]byte("12**21"),
		[]byte("1*33*1"),
	})

	test([][]byte{
		[]byte("****"),
		[]byte("****"),
	}, [][]byte{
		[]byte("****"),
		[]byte("****"),
	})

	test([][]byte{
		[]byte("   "),
		[]byte("   "),
		[]byte("   "),
		[]byte("   "),
	}, [][]byte{
		[]byte("000"),
		[]byte("000"),
		[]byte("000"),
		[]byte("000"),
	})

	test([][]byte{
		[]byte("*   "),
		[]byte("**  "),
		[]byte("    "),
		[]byte("   *"),
	}, [][]byte{
		[]byte("*310"),
		[]byte("**10"),
		[]byte("2221"),
		[]byte("001*"),
	})

	test([][]byte{
		[]byte("**    "),
		[]byte("*    *"),
		[]byte("  *   "),
		[]byte("      "),
		[]byte("*     "),
		[]byte("****  "),
	}, [][]byte{
		[]byte("**1011"),
		[]byte("*4211*"),
		[]byte("12*111"),
		[]byte("121100"),
		[]byte("*43210"),
		[]byte("****10"),
	})

	test([][]byte{
		[]byte("     *    "),
		[]byte("        * "),
		[]byte("     *    "),
		[]byte("**   ***  "),
		[]byte("      *** "),
		[]byte("          "),
		[]byte("       ** "),
		[]byte("  * *     "),
		[]byte("*      ** "),
		[]byte("       ** "),
	}, [][]byte{
		[]byte("00001*1111"),
		[]byte("00002221*1"),
		[]byte("22102*4321"),
		[]byte("**102***31"),
		[]byte("221013***1"),
		[]byte("0000013542"),
		[]byte("0112111**1"),
		[]byte("12*2*12442"),
		[]byte("*212112**2"),
		[]byte("1100002**2"),
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m, r [][]byte) {
	clueit(m)
	dump(m)
	assert(reflect.DeepEqual(m, r))
}

func dump(m [][]byte) {
	for i := range m {
		fmt.Printf("%s\n", m[i])
	}
	fmt.Println()
}

func clueit(m [][]byte) {
	for i := range m {
		for j := range m[i] {
			if m[i][j] != '*' {
				m[i][j] = stars(m, i, j)
			}
		}
	}
}

func stars(m [][]byte, i, j int) byte {
	c := byte('0')
	for dy := -1; dy <= 1; dy++ {
		for dx := -1; dx <= 1; dx++ {
			if dx == 0 && dy == 0 {
				continue
			}

			y := i + dy
			x := j + dx
			if !(x < 0 || y < 0 || y >= len(m) || x >= len(m[y]) || m[y][x] != '*') {
				c++
			}
		}
	}
	return c
}
