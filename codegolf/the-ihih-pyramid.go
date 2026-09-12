/*

I find it fascinating how the letters "H" and "I" are very similar. "H" is a horizontal stroke surrounded by two vertical strokes; "I" is a vertical stroke surrounded by two horizontal strokes (depending on your font). I bet this could be nested... You know what that reminds me of? Fractals!!!

Let's define the "IHIH" pyramid as follows: The first iteration is this ASCII representation of the letter "I":

---
 |
---
The next iteration has a vertical stroke on either side.

|   |
|---|
| | |
|---|
|   |
If you view the "I" in the middle as a single horizontal stroke, then this second iteration is basically an "H". The third iteration adds a horizontal stroke on the top and bottom

-------
 |   |
 |---|
 | | |
 |---|
 |   |
-------
Again, if you view the "H" in the middle as a single vertical stroke, then this iteration is basically an "I". This pattern continues, alternating between "H"s and "I"s on every iteration. For reference, here are the first 6 iterations:

1:
---
 |
---

2:
|   |
|---|
| | |
|---|
|   |

3:
-------
 |   |
 |---|
 | | |
 |---|
 |   |
-------

4:
|       |
|-------|
| |   | |
| |---| |
| | | | |
| |---| |
| |   | |
|-------|
|       |

5:
-----------
 |       |
 |-------|
 | |   | |
 | |---| |
 | | | | |
 | |---| |
 | |   | |
 |-------|
 |       |
-----------

6:
|           |
|-----------|
| |       | |
| |-------| |
| | |   | | |
| | |---| | |
| | | | | | |
| | |---| | |
| | |   | | |
| |-------| |
| |       | |
|-----------|
|           |

The Challenge:
Write a program or function that outputs the N'th iteration of the IHIH pyramid, and an optional trailing newline. Your input will be a single positive integer in whatever reasonable format you want. You do not have to handle invalid inputs, e.g. non-integers, numbers smaller than 1, etc. Your program must at the very least produce the right output for inputs up to 20. Since this is code-golf, standard loopholes are not allowed and the shortest answer in bytes wins!

*/

package main

import "fmt"

func main() {
	for i := range 10 {
		pyramid(i)
	}
}

func pyramid(n int) {
	const (
		c0 = " -"
		c1 = "| "
	)

	fmt.Printf("n=%d\n", n)
	for y := -n; y <= n; y++ {
		j := abs(y)
		for x := -n; x <= n; x++ {
			i := abs(x)
			if i&^1 < j {
				fmt.Printf("%c", c0[j&1])
			} else {
				fmt.Printf("%c", c1[i&1])
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
