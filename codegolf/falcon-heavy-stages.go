/*

Choose a set of four bytes without replacement (i.e. no byte repeated), and not necessarily in any particular order, from any one of the following four sets:

The characters of any one single-byte encoding
The Unicode characters in the range 00–FF
The signed decimal integers in the range −128–127
The unsigned decimal integers in the range 0–255
The four values you chose (please state which they are) will be the valid inputs. You must pair each value with one of the below ASCII artworks.

Given (by any means) one of your four valid inputs, respond (by any means, even list of strings) with the corresponding ASCII art. Extra white-space is allowed on all sides, as long as the image is in there in one contiguous 2D area.

First byte:

     /\
    /  \
   |    |
   |    |
   |    |
   |____|
    \__/
    |  |
    |  |
    |  |
    |  |
 /\ |  | /\
/  \|  |/  \
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
AAAAAAAAAAAA
Second byte:

  /\
 /  \
|    |
|    |
|    |
|____|
 \__/
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 AAAA
Third byte:

  /\
 /  \
|    |
|    |
|    |
|____|
 \__/
 |  |
 |  |
 |  |
 |__|
  /\
Fourth byte:

 db
_/\_
\__/
|  |
|  |
|  |
|__|
 /\
What's new about this ASCII art Kolmogorov complexity challenge?

The ability to select valid inputs presents a new aspect to the challenge. The inputs are clearly too limited to encode the entire result, but can carry enough information to merit attention.

The multiple possible outputs share a lot of structure, so reuse of code or sub-images is feasible both within each image and between images.

There is enough duplication that even languages which are not well-geared towards challenges like this have a fair chance of being able to use clever code rather than just hard-coding strings extensively.

*/

package main

import "fmt"

func main() {
	draw(0)
	draw(127)
	draw(-128)
	draw(255)
}

func draw(n int) {
	switch n {
	case 0:
		fmt.Println(FALCON1)
	case 127:
		fmt.Println(FALCON2)
	case -128:
		fmt.Println(FALCON3)
	case 255:
		fmt.Println(FALCON4)
	}
}

const FALCON1 = `
     /\
    /  \
   |    |
   |    |
   |    |
   |____|
    \__/
    |  |
    |  |
    |  |
    |  |
 /\ |  | /\
/  \|  |/  \
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
|  ||  ||  |
AAAAAAAAAAAA
`

const FALCON2 = `
  /\
 /  \
|    |
|    |
|    |
|____|
 \__/
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 |  |
 AAAA
`

const FALCON3 = `
  /\
 /  \
|    |
|    |
|    |
|____|
 \__/
 |  |
 |  |
 |  |
 |__|
  /\
`

const FALCON4 = `
 db
_/\_
\__/
|  |
|  |
|  |
|__|
 /\
`
