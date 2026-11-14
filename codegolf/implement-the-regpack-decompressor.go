/*

The JavaScript compressor RegPack uses a very simple string compression algorithm. Given a piece of code, it will make a list of characters that aren't used in that code and use them to delimit repeated strings that are inserted back into the string.

To show how strings are compressed, it's necessary to show how the decompressor works. If you give RegPack the tongue-twister How much wood would a woodchuck chuck if a woodchuck could chuck wood?, it will spit out How much } w|a }~~if a }~c|~}?~chuck }wood|ould  along with the list of characters |}~.

The decompressor starts by splitting this string on the first character in the char list, |, resulting in ["How much } w", "a }~~if a }~c", "~}?~chuck }wood", "ould "]. It then pops the last item, "ould ", and joins what remains by this, resulting in "How much } would a }~~if a }~could ~}?~chuck }wood".

It then does the same thing for }, replacing } with wood to result in "How much wood would a wood~~if a wood~could ~wood?~chuck ", and finally replaces ~ with "chuck " to result in the whole thing, How much wood would a woodchuck chuck if a woodchuck could chuck wood?.

The advantage of this algorithm is that it's very simple and short to implement. RegPack itself implements it in 39 bytes of JavaScript: for(i of<chars>)with(_.split(i))_=join(pop()) (where <chars> is a hardcoded char list), which basically performs the steps described above.

Your challenge is to, given a compressed string and a list of characters, decompress it using the above algorithm.

Testcases
'a|b|c|hello', '|' => ahellobhelloc
'He||o, wor|d!|l', '|' => Hello, world!
'| | & &&|house|green', '|&' => green green greenhouse greenhouse
'N~give}up,n~let}down~ever gonna } you ', '}~' => Never gonna give you up,never gonna let you down
'How much } w|a }~~if a }~c|~}?~chuck }wood|ould ', '|}~' => How much wood would a woodchuck chuck if a woodchuck could chuck wood?
'She sells~ells by the~ore~ sea sh', '~' => She sells sea shells by the sea shore

*/

package main

import (
	"strings"
)

func main() {
	assert(decompress("a|b|c|hello", "|") == "ahellobhelloc")
	assert(decompress("He||o, wor|d!|l", "|") == "Hello, world!")
	assert(decompress("| | & &&|house|green", "|&") == "green green greenhouse greenhouse")
	assert(decompress("N~give}up,n~let}down~ever gonna } you ", "}~") == "Never gonna give you up,never gonna let you down")
	assert(decompress("How much } w|a }~~if a }~c|~}?~chuck }wood|ould ", "|}~") == "How much wood would a woodchuck chuck if a woodchuck could chuck wood?")
	assert(decompress("She sells~ells by the~ore~ sea sh", "~") == "She sells sea shells by the sea shore")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func decompress(s, d string) string {
	r := s
	for _, d := range d {
		t := strings.Split(r, string(d))
		n := len(t)
		r = strings.Join(t[:n-1], t[n-1])
	}
	return r
}
