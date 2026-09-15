/*

Whilst trying (and failing) have persuade my infant son to eat his dinner, I tried singing to him. Mid way through this song I realised the formulaic structure might lend itself well to code golfing!

The task is to write a program or function which accepts no input and produces the following text:

There's a hole in the bottom of the sea
There's a hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a log in the hole in the bottom of the sea
There's a log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a bump on the log in the hole in the bottom of the sea
There's a bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a frog on the bump on the log in the hole in the bottom of the sea
There's a frog on the bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a fly on the hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a fly on the hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a flea on the fly on the hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a flea on the fly on the hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a smile on the flea on the fly on the hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a smile on the flea on the fly on the hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea
Challenge rules:

The text may be printed or returned as function output
Each verse is separated by a single empty line
Trailing whitespace is OK as long as it does not change the layout (so no leading whitespace or extra spaces between words)
Trailing newlines are OK too.
No leading newlines.
All languages welcomed, and this is code-golf, so the shortest answer in bytes for each language wins!

*/

package main

import "fmt"

func main() {
	fmt.Println(POEM)
}

const POEM = `
There's a hole in the bottom of the sea
There's a hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a log in the hole in the bottom of the sea
There's a log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a bump on the log in the hole in the bottom of the sea
There's a bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a frog on the bump on the log in the hole in the bottom of the sea
There's a frog on the bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a fly on the hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a fly on the hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a flea on the fly on the hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a flea on the fly on the hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea

There's a smile on the flea on the fly on the hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a smile on the flea on the fly on the hair on the wart on the frog on the bump on the log in the hole in the bottom of the sea
There's a hole, there's a hole
There's a hole in the bottom of the sea
`
