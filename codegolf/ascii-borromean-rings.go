/*

The Borromean rings are a curious set of three circles, linked such that the removal of any one of them will unlink the other two:

https://upload.wikimedia.org/wikipedia/commons/5/5a/Borromean_Rings_Illusion.png

You can make a set for yourself with a couple rubber bands and a binder ring. With more rubber bands, it's easy to make any Brunnian link.

Write a program or function that outputs (prints or returns) this ascii-art representation of Borromean rings:

    +-----+
    |     |
+-----+   |
|   | |   |
| +-|---+ |
| | | | | |
| | +-|---+
| |   | |
+-|---+ |
  |     |
  +-----+
The lines may have trailing spaces and there may be a trailing newline.

The shortest code in bytes wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(BORROMEAN)
}

const BORROMEAN = `
    +-----+
    |     |
+-----+   |
|   | |   |
| +-|---+ |
| | | | | |
| | +-|---+
| |   | |
+-|---+ |
  |     |
  +-----+
`
