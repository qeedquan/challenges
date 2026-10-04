/*

Introduction
"Yarr!! We had a laddie who called himself a "programmer" make a map t' our hidden treasure! But 'tis written wit' weird numbers 'n letters! "E5, N2, E3"... what does it even mean? Madness! Can't even scribe a proper treasure map, t' useless cretin. Fix it fer us! We'll gift ye a share o' t' treasure!"

Challenge Description
A group of pirates are having trouble reading a treasure map. Can you write a program to convert it into a more... piratey form?

As input, you'll receive the original treasure map. It's a list of comma separated strings, each string which consists of a letter portion (which tells the pirates which direction they need to walk in), and a number portion (which tells the pirates how many steps to take in that direction). For instance, the following treasure map:

E2,N4,E5,S2,W1,S3
would mean, "walk two steps to the east, walk four steps to the north, walk five steps to the east, walk two steps to the south, walk one step to the west, then walk three steps to the south."

As output, you'll output the map in a graphical form, using the characters >, ^, v, and < as pointers. Here's the output for the above input:

  >>>>>v
  ^    v
  ^   v<
  ^   v
>>^   X
Notice that we've replaced the last step to the south with an X instead. This is because the last step is where the treasure is, and as we all know, pirates must have an X on their treasure maps, otherwise they won't know how to read it.

By the way, the map won't ever cross itself, so you don't need to worry about dealing with overlaps. Also, you are allowed to have a trailing new line at the end of the output.

Sample Inputs and Outputs
S5,W2
 v
 v
 v
 v
 v
X<

N1,E1,S1,E1,N1,E1,S2
>v>v
^>^X

N1
X

N6,E6,S6,W5,N5,E4,S4,W3,N3,E2,S2,W1,N2
>>>>>>v
^>>>>vv
^^>>vvv
^^^Xvvv
^^^^<vv
^^^<<<v
^^<<<<<

E21,S2
>>>>>>>>>>>>>>>>>>>>>v
                     X

N12,E11,S12,W2,N4
>>>>>>>>>>>v
^          v
^          v
^          v
^          v
^          v
^          v
^          v
^          v
^        X v
^        ^ v
^        ^ v
^        ^<<


*/

package main

import (
	"fmt"
	"image"
	"image/color"
	"strings"
)

func main() {
	test("S5,W2")
	test("N1,E1,S1,E1,N1,E1,S2")
	test("N1")
	test("N6,E6,S6,W5,N5,E4,S4,W3,N3,E2,S2,W1,N2")
	test("E21,S2")
	test("N12,E11,S12,W2,N4")
}

func test(s string) {
	g := inst2map(s)
	drawmap(g)
}

func inst2map(s string) *image.Gray {
	r := bounds(s)
	g := image.NewGray(r)
	return exec(g, s)
}

func refit(r image.Rectangle, p image.Point) image.Rectangle {
	r.Min.X = min(r.Min.X, p.X)
	r.Min.Y = min(r.Min.Y, p.Y)
	r.Max.X = max(r.Max.X, p.X)
	r.Max.Y = max(r.Max.Y, p.Y)
	return r
}

func getdir(t string) (l int, d image.Point, c color.Gray, ok bool) {
	var op byte
	n, _ := fmt.Sscanf(t, "%c%d", &op, &l)
	if n != 2 {
		return
	}

	switch op {
	case 'N':
		c.Y, d.Y = '^', -1
	case 'S':
		c.Y, d.Y = 'v', 1
	case 'E':
		c.Y, d.X = '>', 1
	case 'W':
		c.Y, d.X = '<', -1
	default:
		return
	}

	ok = true
	return
}

func bounds(s string) image.Rectangle {
	r := image.ZR
	if s == "" {
		return r
	}

	p := image.ZP
	for _, t := range strings.Split(s, ",") {
		l, d, _, ok := getdir(t)
		if !ok {
			continue
		}

		q := image.Pt(p.X+d.X*(l-1), p.Y+d.Y*(l-1))
		p = image.Pt(p.X+d.X*l, p.Y+d.Y*l)
		r = refit(r, q)
	}

	r.Max.X++
	r.Max.Y++
	return r
}

func exec(g *image.Gray, s string) *image.Gray {
	p, q := image.ZP, image.ZP
	for _, t := range strings.Split(s, ",") {
		l, d, c, ok := getdir(t)
		if !ok {
			continue
		}

		for i := 0; i < l; i++ {
			g.Set(p.X, p.Y, c)
			p, q = p.Add(d), p
		}
	}
	g.Set(q.X, q.Y, color.Gray{'X'})
	return g
}

func drawmap(g *image.Gray) {
	r := g.Bounds()
	for y := r.Min.Y; y < r.Max.Y; y++ {
		for x := r.Min.X; x < r.Max.X; x++ {
			c := g.GrayAt(x, y)
			if c.Y == 0 {
				c.Y = '.'
			}
			fmt.Printf("%c", c.Y)
		}
		fmt.Println()
	}
	fmt.Println()
}
