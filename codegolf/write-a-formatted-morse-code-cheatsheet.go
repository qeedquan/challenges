/*

Challenge:
Write a program that produces the following output:

. E   .. I   ... S   .... H
                     ...- V
             ..- U   ..-. F
                     ..--
      .- A   .-. R   .-.. L
                     .-.-
             .-- W   .--. P
                     .--- J
- T   -. N   -.. D   -... B
                     -..- X
             -.- K   -.-. C
                     -.-- Y
      -- M   --. G   --.. Z
                     --.- Q
             --- O   ---.
                     ----
This is a formatted table of the Morse codes of the letters from A to Z. Each column is separated by three spaces.

There are four missing slots, which are used by international character sets. Your program must write a space there.

The output must consist of ASCII spaces, dots, dashes, uppercase letters and newlines (either LF or CRLF) only.

Your program accepts no input.

The following is a sample Python program that produces the desired output:

b = "."
out = []
last = 0
ch = "EISHVUF ARL WPJTNDBXKCYMGZQO  "
cx = 0
while b:
    if last >= len(b):
        print("   ".join(out))
        out = ["   ", "    ", "     ", "      "][0:len(b) - 1]
    out.append(b + " " + ch[cx])
    cx += 1
    last = len(b)
    if len(b) < 4:
        b += "."
    elif b[-1] == ".":
        b = b[0:-1] + "-"
    else:
        i = len(b) - 1
        while b[i] == "-":
            i -= 1
            if i < 0:
                break
        if i < 0:
            break
        b = b[0:i] + "-"
print("   ".join(out))
This is code-golf, so the shortest answer in bytes wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(CHEATSHEET)
}

const CHEATSHEET = `
. E   .. I   ... S   .... H
                     ...- V
             ..- U   ..-. F
                     ..--
      .- A   .-. R   .-.. L
                     .-.-
             .-- W   .--. P
                     .--- J
- T   -. N   -.. D   -... B
                     -..- X
             -.- K   -.-. C
                     -.-- Y
      -- M   --. G   --.. Z
                     --.- Q
             --- O   ---.
                     ----
`
