/*

Generate the contents of an SVG file containing 6 bingo cards. Winner is the one that uses the shortest code. A qualifying answer has an output that can be directly pasted in a blank to get the required image. Rules are as follows.

The generated SVG code should comply with SVG version 1.1 described here.
The size of the image should be equal to either Letter or A4 page sizes.
Cards should be arranged in 3 rows and 2 columns.
Each card should be 3 inches in width and height.
Each card should contain numbers 1 to 25 in random order, arranged in 5x5 squares. The numbers in all 6 cards should be generated independently.
Text size should be 20 points and text color should be black.
Text font should be Helvetica, Arial, Calibri or Open Sans. Text should be centered in each cell.
The line in the cards should have thickness either 0.5 or 1 points, and black color.
The cards should be arranged evenly around the image: The vertical distances between cards and the vertical distances between the cards and image boundaries should all be the same. Similar for horizontal distances.
There is a margin of 5% allowed in each dimension, but all cards should be strictly equal in size.
The following image shows the intended layout of the image, although sizes and spacing may not be accurate.

Can someone please close my older question and open up this one? This question is more realistic for because it doesn't need file-write operations or libraries. I could update the older question to remove the PDF requirement, but it was already getting allegations of a chameleon question so I didn't want to risk it. I can delete the older question if there is no other option but I would prefer to keep it (even if closed).

https://i.sstatic.net/rpPLw.png

from random import shuffle

def m(h,j,k,l):
    print('<line x1="'+str(h)+'pt" y1="'+str(j)+'pt" x2=\"'+str(k)+'pt" y2="'+str(l)+'pt" stroke="black" stroke-width="1pt" />')

print('<svg version="1.1" width="612pt" height="792pt" xmlns="http://www.w3.org/2000/svg">')
a=[i for i in range(1,26)]
for b in range(0,3):
    for c in range (0,2):
        shuffle(a)
        e=252*b
        d=276*c
        m(60+d,36+e,276+d,36+e)
        m(276+d,36+e,276+d,246+e)
        m(60+d,36+e,60+d,246+e)
        m(60+d,246+e,276+d,246+e)
        for g in range(0,5):
            f=g*43.2
            m(60+d,36+e+f,276+d,36+e+f)
            m(60+d+f,36+e,60+d+f,246+e)
            for i in range(0,5):
                print('<text x="'+str(81.6+d+f)+'pt" y="'+str(57.6+e+i*43.2)+'pt" dominant-baseline="middle" text-anchor="middle" font-size="20pt" font-family="Arial, Helvetica, sans-serif">'+str(a[i+5*g])+'</text>')
print("</svg>")

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	output()
}

func output() {
	fmt.Println(`<svg version="1.1" width="612pt" height="792pt" xmlns="http://www.w3.org/2000/svg">`)
	a := make([]int, 25)
	for i := range a {
		a[i] = i + 1
	}
	for b := 0.0; b < 3; b++ {
		rand.Shuffle(len(a), func(i, j int) {
			a[i], a[j] = a[j], a[i]
		})

		for c := 0.0; c < 2; c++ {
			e := 252 * b
			d := 276 * c
			m(60+d, 36+e, 276+d, 36+e)
			m(276+d, 36+e, 276+d, 246+e)
			m(60+d, 36+e, 60+d, 246+e)
			m(60+d, 246+e, 276+d, 246+e)
			for g := range 5 {
				f := float64(g) * 43.2
				m(60+d, 36+e+f, 276+d, 36+e+f)
				m(60+d+f, 36+e, 60+d+f, 246+e)
				for i := range 5 {
					fmt.Printf(
						`<text x="%.1fpt" y="%.1fpt" dominant-baseline="middle" text-anchor="middle" font-size="20pt" font-family="Arial, Helvetica, sans-serif">%d</text>`,
						81.6+d+f, 57.6+e+float64(i)*43.2, a[i+5*g],
					)
					fmt.Println()
				}
			}
		}
	}
	fmt.Println(`</svg>`)
}

func m(h, j, k, l float64) {
	fmt.Printf(`<line x1="%.1fpt" y1="%.1fpt" x2="%.1fpt" y2="%.1fpt" stroke="black" stroke-width="1pt" />`, h, j, k, l)
}
