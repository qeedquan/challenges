/*

Inspired by this question, your goal today is to encode an URL in brainfuck.

My browser has been hacked! The location bar has been turned into a brainfuck interpreter. I need a program that turns an URL into a brainfuck program. My computer is also very slow, so if the brainfuck program is small it's better.

Oh and I only have one working tab left open, my twitter. So you can only send me the program in a tweet.

Write a program that fits in a tweet (140 characters) in any language that takes a string as input and outputs a brainfuck program.

This brainfuck program will be run without input and will generate an output.

This output will be inserted into the location bar of Google Chrome, and executed.

If the behaviour of Google Chrome is identical to the behaviour you would get by entering the input string from #1, then the solution is valid. Redirection by URL shorteners is considered different behaviour - stay at least on the same domain.

You may assume the brainfuck interpreter has infinite precision signed integers in each cell and an unlimited amount of cells.

Your score is determined by the sum of the lengths of the brainfuck programs generated to encode the following set of URLs:

https://www.google.com/
https://codegolf.stackexchange.com/questions/47895/
http://www.golfscript.com/golfscript/examples.html
http://en.wikipedia.org/wiki/Percent-encoding
ftp://ftp.freebsd.org/pub/FreeBSD/
https://github.com/isaacg1/pyth/blob/master/doc.txt#L92
http://ftp.gnu.org/non-gnu/nethack/nethack-3.4.0.tar.gz.back-RSN.README

Smallest score wins.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	urls := []string{
		"https://www.google.com/",
		"https://codegolf.stackexchange.com/questions/47895/",
		"http://www.golfscript.com/golfscript/examples.html",
		"http://en.wikipedia.org/wiki/Percent-encoding",
		"ftp://ftp.freebsd.org/pub/FreeBSD/",
		"https://github.com/isaacg1/pyth/blob/master/doc.txt#L92",
		"http://ftp.gnu.org/non-gnu/nethack/nethack-3.4.0.tar.gz.back-RSN.README",
	}

	for _, url := range urls {
		fmt.Printf("%q: %q\n\n", url, encode(url))
	}
}

func encode(url string) string {
	w := new(bytes.Buffer)
	for _, r := range url {
		for range r {
			w.WriteByte('+')
		}
		w.WriteString(".>")
	}
	return w.String()
}
