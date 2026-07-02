/*

Given a strictly positive integer n (therefore 0 isn't a valid test case), produce an approximate triangle of height n.
A non-programmatic process of drawing the picture

Initially we start with the base of the triangle.

|

So, we want to draw a triangle of a height of 5. First we know that all the |'s align on a straight line, and there is a missing | on every even position.

|

|

|

Then, we insert the /'s onto these empty lines, where every / has 1 more preceding space than the next /. The lowest / starts at 1 space.

|
  /
|
 /
|

More reference outputs + Sample program

Here's what the program should output for inputs 1 to 9. A sample program is available if you still don't understand the specification.

For those that don't see that it's a triangle: Take a look at this. Scroll the picture really quickly. You will see the two sides of a triangle.

==== 1: ====
|
==== 2: ====
 /
|
==== 3: ====
|
 /
|
==== 4: ====
  /
|
 /
|
==== 5: ====
|
  /
|
 /
|
==== 6: ====
   /
|
  /
|
 /
|
==== 7: ====
|
   /
|
  /
|
 /
|
==== 8: ====
    /
|
   /
|
  /
|
 /
|
==== 9: ====
|
    /
|
   /
|
  /
|
 /
|

Specification

    Leading/Trailing whitespace is allowed.
    The string has to be joined with newlines, outputting a string list is not allowed.


def WrapTriangle(n):
	list = []
	for i in range(1,n+1):
		if i%2 == 1:
			list.append("|")
		else:
			list.append(" "*int(i/2)+"/")
	return '\n'.join(list[::-1])

for i in range(1,10):
	print("==== "+str(i)+": ====")
	print(WrapTriangle(i))

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
	"time"
)

func main() {
	sim(16, 100*time.Millisecond)
}

func sim(n int, d time.Duration) {
	i := 0
	for {
		clear()
		fmt.Println(alttri(i))
		time.Sleep(d)
		i = (i + 1) % n
	}
}

func clear() {
	fmt.Printf("\033c")
}

func alttri(n int) string {
	l := []string{}
	for i := 1; i <= n; i++ {
		if i&1 != 0 {
			l = append(l, "|")
		} else {
			l = append(l, strings.Repeat(" ", i/2)+"/")
		}
	}

	w := new(bytes.Buffer)
	for i := len(l) - 1; i >= 0; i-- {
		fmt.Fprintln(w, l[i])
	}
	return w.String()
}
