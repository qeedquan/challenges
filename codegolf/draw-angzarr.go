/*

Angzarr, ⍼, or RIGHT ANGLE WITH DOWNWARDS ZIGZAG ARROW, or "Azimut, Richtungswinkel", is an obscure Unicode character whose meaning has not been fully established. Somebody found that it may mean "azimuth", but no published usage (or explanation of why it became part of Unicode) is known.

Your task is to draw this interesting symbol.

Rules:

Your program must produce a recognizable representation of the symbol shown below.
You must not output the Unicode character itself. For example, solutions such as print('⍼'), &angzarr; or \rangledownzigzagarrow are not allowed.
The symbol may be displayed on the screen or written to a file.
Both raster and vector output are allowed.
ASCII art is allowed.
the exact style does not matter, as long as the resulting shape is clearly recognizable as the Angzarr (see examples below)
Standard code-golf rules apply: the score is the number of bytes in the submitted program, unless otherwise specified by the language.
Glyphs from GNU Unifont, STIX Two, Julia Mono, and Noto Sans Math/Symbols

https://i.sstatic.net/2B25Z4M6.png

(Glyphs from GNU Unifont, STIX Two, Julia Mono, and Noto Sans Math/Symbols, from ionathan.ch blog)

*/

package main

import "fmt"

func main() {
	fmt.Println(ART)
}

const ART = `
    #   #
    #  #
    # #
    ##
    #
   ##
  # #
 #  #
#   #
 #  #
  # #
   ##
    #
    ##
    # #
    #  #
    #   #
    #  #
    # #
    ##
    ####################
#  #
# #
##
####
`
