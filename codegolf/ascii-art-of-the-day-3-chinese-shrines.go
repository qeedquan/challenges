/*

In today's episode of AAOD, we are going to construct a Chinese Shrine of varying heights.

Consider the following examples for height (N) 1 to 6

N = 1:

       .
       |
  .   ]#[   .
   \_______/
.    ]###[    .
 \__]#.-.#[__/
  |___| |___|
  |___|_|___|
  ####/_\####
     |___|
    /_____\
N = 2:

         .
         |
    .   ]#[   .
     \_______/
  .    ]###[    .
   \___________/
.     ]#####[     .
 \___]#.---.#[___/
  |__|_|   |_|__|
  |__|_|___|_|__|
  #####/___\#####
      |_____|
     /_______\
N = 3:

           .
           |
      .   ]#[   .
       \_______/
    .    ]###[    .
     \___________/
  .     ]#####[     .
   \_______________/
.      ]#######[      .
 \____]#.-----.#[____/
  |__|__|     |__|__|
  |__|__|_____|__|__|
  ######/_____\######
       |_______|
      /_________\
N = 4:

             .
             |
        .   ]#[   .
         \_______/
      .    ]###[    .
       \___________/
    .     ]#####[     .
     \_______________/
  .      ]#######[      .
   \___________________/
.       ]#########[       .
 \_____]##.-----.##[_____/
  |__|__|_|     |_|__|__|
  |__|__|_|_____|_|__|__|
  ########/_____\########
         |_______|
        /_________\
N = 5:

               .
               |
          .   ]#[   .
           \_______/
        .    ]###[    .
         \___________/
      .     ]#####[     .
       \_______________/
    .      ]#######[      .
     \___________________/
  .       ]#########[       .
   \_______________________/
.        ]###########[        .
 \______]###.-----.###[______/
  |__|__|___|     |___|__|__|
  |__|__|___|_____|___|__|__|
  ##########/_____\##########
           |_______|
          /_________\
N = 6:

                 .
                 |
            .   ]#[   .
             \_______/
          .    ]###[    .
           \___________/
        .     ]#####[     .
         \_______________/
      .      ]#######[      .
       \___________________/
    .       ]#########[       .
     \_______________________/
  .        ]###########[        .
   \___________________________/
.         ]#############[         .
 \_______]####.-----.####[_______/
  |__|__|__|__|     |__|__|__|__|
  |__|__|__|__|_____|__|__|__|__|
  ############/_____\############
             |_______|
            /_________\
and so on.

Construction Details
I am sure most of the details about the pattern are clear. Here are some finer details:

The door at the bottom of the shrine can at minimum be of 1 _ width and at maximum be of 5 _ width.
There will always be two . directly above the pillars around the door (two vertical |).
The stairs start with the same width as the door and increase like show in the pattern
The ]##..##[ blocks above each roof level increase in size of 2 from top to bottom.
The \__...__/ roofs levels increase in size of 4 from top to bottom.
The walls blocks around the door should at minimum contain 1 _ and at maximum, 3 _ between the two |. Priority goes to the outer wall blocks so that the one closest to the door gets a varying size for each level.
The space between the . and the ] (or [) is filled by # in the roof just above the doors.

Challenge Details
Write a function or full program that reads a positive integer greater than 0 via STDIN/ARGV/function argument or closest equivalent and outputs (to STDOUT or closest equivalent) the Nth Chinese Shrine
Trailing newline is optional.
There should either be no trailing spaces or enough trailing spaces to pad the output in the minimum bounding rectangle.
There should not be any leading spaces that are not part of the pattern.

*/

package main

import "fmt"

func main() {
	for i := 1; i <= 6; i++ {
		shrine(i)
	}
}

// ported from @Reto Koradi solution
func shrine(n int) {
	fmt.Printf("n=%d\n", n)
	if n < 1 {
		return
	}

	m := n * 2
	d := 5
	if n < 3 {
		d = m - 1
	}
	w := m - d/2 + 2

	repeat(m+5, " ")
	fmt.Println(".")

	repeat(m+5, " ")
	fmt.Println("|")

	for i := 0; ; i++ {
		repeat(m-i*2, " ")
		fmt.Print(".")
		repeat(i+3, " ")
		fmt.Print("]")
		repeat(i*2+1, "#")
		fmt.Print("[")
		repeat(i+3, " ")
		fmt.Println(".")

		if i == n {
			break
		}

		repeat(m-i*2+1, " ")
		fmt.Print(`\`)
		repeat(i*4+7, "_")
		fmt.Println("/")
	}

	fmt.Print(` \`)
	repeat(n+1, "_")
	fmt.Print("]")
	repeat(n-d/2, "#")
	fmt.Print(".")
	repeat(d, "-")
	fmt.Print(".")
	repeat(n-d/2, "#")
	fmt.Print("[")
	repeat(n+1, "_")
	fmt.Println("/")

	for i := range 2 {
		sym0 := []string{"|", "_|", "|_|"}
		sym1 := []string{" ", "_"}
		sym2 := []string{"|", "|_", "|_|"}

		fmt.Print("  ")
		repeat(w/3, "|__")
		fmt.Print(sym0[w%3])

		repeat(d, sym1[i])

		fmt.Print(sym2[w%3])
		repeat(w/3, "__|")
		fmt.Println()
	}

	fmt.Print("  ")
	repeat(w, "#")
	fmt.Print("/")
	repeat(d, "_")
	fmt.Print(`\`)
	repeat(w, "#")
	fmt.Println()

	repeat(w+1, " ")
	fmt.Print("|")
	repeat(d+2, "_")
	fmt.Println("|")

	repeat(w, " ")
	fmt.Print("/")
	repeat(d+4, "_")
	fmt.Println(`\`)
	fmt.Println()
}

func repeat(n int, s string) {
	for range n {
		fmt.Print(s)
	}
}
