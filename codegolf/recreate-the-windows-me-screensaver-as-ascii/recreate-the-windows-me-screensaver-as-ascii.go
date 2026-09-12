/*

This challenge is inspired from this answer at the Ask Ubuntu Stack Exchange.
https://askubuntu.com/questions/699579/ascii-screensaver-for-the-command-line-or-a-tui/699587#699587

Intro
Remember the Windows ME screensaver with the pipes? Time to bring the nostalgia back!

https://i.sstatic.net/U5PrJ.gif

Challenge
You should write a program or function which will output an ASCII representation of the screensaver. In the screensaver there should be a single pipe which will grow in semi-random directions.
The start of the pipe will be randomly placed at any of the borders of the screen and the pipe piece should be perpendicular to the border (corner first-pipes can either be horizontal or vertical). Each tick the pipe will grow in the direction it is facing (horizontal/vertical) at an 80% chance or take a corner at a 20% chance.

Pipe representation
To create the pipe, 6 unicode characters will be used

─    \u2500    horizontal pipe
│    \u2502    vertical pipe
┌    \u250C    upper left corner pipe
┐    \u2510    upper right corner pipe
└    \u2514    lower left corner pipe
┘    \u2518    lower right corner pipe
Input
The program / function will take 3 values of input, which can be gathered through function parameters or prompted to the user.

Amount of ticks
Screen width
Screen height
Amount of ticks
For every tick, a piece of pipe will be added to the screen. Pipes will overwrite old pipe pieces if they spawn at the same position.

For example, take a screen of size 3x3

ticks == 3
─┐
 ┘


ticks == 4
─┐
└┘


ticks == 5
│┐
└┘
Whenever a pipe exits the screen, as in the last example at 5 ticks, then a new pipe will spawn at a random border. For example:

ticks == 6
│┐
└┘
  ─
The new pipe should have a 50% chance of being horizontal or vertical.

Screen width/height
The screen width and height can be combined into a single value if that's preferrable in your language of choice. The screen width and height will always have a minimum value of 1 and a maximum value of 255. If your language of choice supports a console or output screen which is smaller than a 255x255 grid of characters then you may assume that the width and height will never exceed the boundaries of your console. (Example: Windows 80x25 cmd window)

Output
The output of your program/function should be printed to the screen, or returned from a function. For every run of your program, a different set of pipes should be generated.

Test cases
The following test cases are all random examples of valid outputs

f(4, 3, 3)
 │
─┘
  │

f(5, 3, 3)
 │
─┘┌
  │

f(6, 3, 3)
─│
─┘┌
  │

f(7, 3, 3)
──
─┘┌
  │
Obviously, the more ticks that have occured, the harder it becomes to prove the validity of your program. Hence, posting a gif of your output running will be preferred. If this is not possible, please post a version of your code which includes printing the output. Obviously, this will not count towards your score.

Rules
This is code-golf, shortest amount of bytes wins
Standard loopholes apply
If you use the unicode pipe characters in your source code, you may count them as a single byte
This is quite a hard challenge that can possibly be solved in many creative ways, you are encouraged to write an answer in a more verbose language even though there are already answers in short esolangs. This will create a catalog of shortest answers per language. Bonus upvotes for fancy coloured gifs ;)

Happy golfing!

Disclaimer: I am aware that Unicode characters aren't ASCII, but in lack of a better name I just call it ASCII art. Suggestions are welcome :)

*/

package main

import (
	"flag"
	"fmt"
	"math/rand"
	"time"
)

var (
	delay  = flag.Duration("delay", 1*time.Millisecond, "specify delay")
	width  = flag.Int("width", 80, "specify width")
	height = flag.Int("height", 25, "specify height")
)

func main() {
	flag.Parse()
	screensaver(*delay, *width, *height)
}

/*

ported from @DLosc solution

How?
TL;DR: A lot of math.

The current row and column are r and c; the current direction is d and the previous direction is b. Direction values 0-3 are down, right, up, left. Arithmetic translates those into the correct step values for r and c, as well as the correct edge coordinates to start on.

The box drawing characters │┐└─┘┌ are code points 179, 191, 192, 196, 217, and 218 in QBasic. Those appear pretty random, but it still used fewer characters to generate the numbers with some (pretty convoluted, I'm-not-sure-even-I-understand-it) math than to do a bunch of conditional statements.

The code for changing direction generates a random number between -0.125 and 1.125 and takes its floor. This gives -1 10% of the time, 0 80% of the time, and 1 10% of the time. We then add this to the current value of d, mod 4. Adding 0 keeps the current direction; adding +/-1 makes a turn.

As for control flow, the WHILE t ... WEND is the main loop; the section before it, starting with line number 1 (1b=INT(RND*4)), restarts the pipe at a random edge. Whenever r and c are outside the window, we GOTO 1.

INPUT t, w, h
RANDOMIZE TIMER
CLS

restart:
' Calculate an edge to start from

b = INT(RND * 4)
'0: top edge (moving down)
'1: left edge (moving right)
'2: bottom edge (moving up)
'3: right edge (moving left)
d = b

' Calculate column and row for a random point on that edge
IF b MOD 2 THEN
    c = (b - 1) / 2 * (w - 1) + 1
    r = 1 + INT(RND * h)
ELSE
    c = 1 + INT(RND * w)
    r = b / 2 * (h - 1) + 1
END IF
COLOR INT(RND * 15) + 1

WHILE t
    ' Mathemagic to generate the correct box-drawing character
    m = (b + d) MOD 4
    IF b = d THEN
        x = 17 * m / 2
    ELSE
        x = 13 * m + (1 < ((b MOD m * 3) + m) MOD 5)
    END IF
    LOCATE r, c
    PRINT CHR$(179 + x);

    ' Update row and column
    r = r - (d - 1) MOD 2
    c = c - (d - 2) MOD 2
    ' Generate new direction (10% turn one way, 10% turn the other way,
    ' 80% go straight)
    b = d
    d = (4 + d + INT(RND * 1.25 - .125)) MOD 4

    ' Pause
    z = TIMER
    WHILE TIMER < z + 0.01
        IF z > TIMER THEN z = z - 86400
    WEND

    t = t - 1
    IF r > h OR c > w OR r = 0 OR c = 0 THEN GOTO restart
WEND

*/

func screensaver(t time.Duration, w, h int) {
	fmt.Printf("\033[2J")

restart:
	c := 0
	r := 0
	b := rand.Intn(4)
	d := b
	if b%2 != 0 {
		c = (b-1)/2*(w-1) + 1
		r = 1 + rand.Intn(h)
	} else {
		c = 1 + rand.Intn(w)
		r = b/2*(h-1) + 1
	}
	p := 31 + rand.Intn(8)

	for {
		var z rune
		switch {
		case (b == 0 && d == 0) || (b == 2 && d == 2):
			z = '│'
		case (b == 1 && d == 1) || (b == 3 && d == 3):
			z = '─'
		case b == 0 && d == 1:
			z = '└'
		case b == 1 && d == 2:
			z = '┘'
		case b == 2 && d == 3:
			z = '┐'
		case b == 3 && d == 0:
			z = '┌'
		default:
			panic(fmt.Sprintf("unhandled case: (%d, %d)", b, d))
		}

		fmt.Printf("\033[%dm\033[%d;%dH%c\033[H\n", p, r, c, z)

		r = r - (d-1)%2
		c = c - (d-2)%2
		b = d
		d = (4 + d + int(rand.Float64()*1.25-.125)) % 4

		if r > h || c > w || r == 0 || c == 0 {
			goto restart
		}
		time.Sleep(t)
	}
}
