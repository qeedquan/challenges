/*

The challenge is actually extremely simple. Pick 5 distinct letters (you can just pick the 5 that allow you the shortest code if you like) and output them to the console. However, the twist is that they must be from the following list:

 AAA      BBBB       CCCC     DDDD      EEEEE     FFFFF      GGG      H   H
A   A     B   B     C         D   D     E         F         G         H   H
AAAAA     BBBB      C         D   D     EEEE      FFFF      G  GG     HHHHH
A   A     B   B     C         D   D     E         F         G   G     H   H
A   A     BBBB       CCCC     DDDD      EEEEE     F          GGG      H   H


IIIII         J     K   K     L         M   M     N   N      OOO
  I           J     K  K      L         MM MM     NN  N     O   O
  I           J     KKK       L         M M M     N N N     O   O
  I       J   J     K  K      L         M   M     N  NN     O   O
IIIII      JJJ      K   K     LLLLL     M   M     N   N      OOO


PPPP       QQQ      RRRR       SSSS     TTTTT     U   U     V   V     W   W
P   P     Q   Q     R   R     S           T       U   U     V   V     W   W
PPPP      Q   Q     RRRR       SSS        T       U   U     V   V     W   W
P         Q  QQ     R  R          S       T       U   U      V V      W W W
P          QQQQ     R   R     SSSS        T        UUU        V        W W


X   X     Y   Y     ZZZZZ
 X X       Y Y         Z
  X         Y         Z
 X X        Y        Z
X   X       Y       ZZZZZ

Additional Rules:
5 of the same letter is not allowed, no repeat choices.
Each letter must use the capital of itself as the ascii-character to draw it.
Each letter output must be on the "same line" and have 5 spaces between each letter.
You may choose any 5 letters that you want, this will allow you to reuse some code and lower your byte count. Figuring out which letters will allow you to do this most efficiently is part of the challenge.
Trailing spaces are acceptable.
A single trailing newline is acceptable, no more than one trailing newline though.
This is code-golf, lowest byte-count wins.

Examples:
A B C D E

 AAA      BBBB       CCCC     DDDD      EEEEE
A   A     B   B     C         D   D     E
AAAAA     BBBB      C         D   D     EEEE
A   A     B   B     C         D   D     E
A   A     BBBB       CCCC     DDDD      EEEEE
E F L I P

EEEEE     FFFFF     L         IIIII     PPPP
E         F         L           I       P   P
EEEE      FFFF      L           I       PPPP
E         F         L           I       P
EEEEE     F         LLLLL     IIIII     P
C R A Z Y

 CCCC     RRRR       AAA      ZZZZZ     Y   Y
C         R   R     A   A        Z       Y Y
C         RRRR      AAAAA       Z         Y
C         R  R      A   A      Z          Y
 CCCC     R   R     A   A     ZZZZZ       Y

Don't be afraid to submit more than one answer with different letters or different strategies each time, this can be accomplished various different ways.

*/

package main

import (
	"fmt"
	"image"
	"math"
	"strings"
)

func main() {
	render("A B C D E")
	render("E F L I P")
	render("C R A Z Y")
	render("B E N T O")
	render("W A V E Y")
}

func render(s string) {
	fmt.Println(s)
	for y := range 5 {
		for _, c := range s {
			b, ok := LOCATIONS[c]
			for x := range 5 {
				r := byte(' ')
				X := b.Min.X + x
				Y := b.Min.Y + y
				if ok && Y < len(LETTERS) && X < len(LETTERS[Y]) {
					r = LETTERS[Y][X]
				}
				fmt.Printf("%c", r)
			}
		}
		fmt.Println()
	}
	fmt.Println()
}

func bounds(s []string, c rune) image.Rectangle {
	x0, y0 := math.MaxInt, math.MaxInt
	x1, y1 := math.MinInt, math.MinInt
	for y := range s {
		for x, nc := range s[y] {
			if c == nc {
				x0 = min(x0, x)
				y0 = min(y0, y)
				x1 = max(x1, x+1)
				y1 = max(y1, y+1)
			}
		}
	}
	return image.Rect(x0, y0, x1, y1)
}

func init() {
	LETTERS = strings.Split(ALPHABET, "\n")
	for c := 'A'; c <= 'Z'; c++ {
		LOCATIONS[c] = bounds(LETTERS, c)
	}
}

var (
	LOCATIONS = make(map[rune]image.Rectangle)
	LETTERS   []string
)

const ALPHABET = `
 AAA      BBBB       CCCC     DDDD      EEEEE     FFFFF      GGG      H   H
A   A     B   B     C         D   D     E         F         G         H   H
AAAAA     BBBB      C         D   D     EEEE      FFFF      G  GG     HHHHH
A   A     B   B     C         D   D     E         F         G   G     H   H
A   A     BBBB       CCCC     DDDD      EEEEE     F          GGG      H   H


IIIII         J     K   K     L         M   M     N   N      OOO
  I           J     K  K      L         MM MM     NN  N     O   O
  I           J     KKK       L         M M M     N N N     O   O
  I       J   J     K  K      L         M   M     N  NN     O   O
IIIII      JJJ      K   K     LLLLL     M   M     N   N      OOO


PPPP       QQQ      RRRR       SSSS     TTTTT     U   U     V   V     W   W
P   P     Q   Q     R   R     S           T       U   U     V   V     W   W
PPPP      Q   Q     RRRR       SSS        T       U   U     V   V     W   W
P         Q  QQ     R  R          S       T       U   U      V V      W W W
P          QQQQ     R   R     SSSS        T        UUU        V        W W


X   X     Y   Y     ZZZZZ
 X X       Y Y         Z
  X         Y         Z
 X X        Y        Z
X   X       Y       ZZZZZ
`
