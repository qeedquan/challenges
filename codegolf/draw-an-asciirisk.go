/*

There are an abundance of questions involving drawing shapes using asterisks - so I thought, with so many asterisks out there, we should draw one, using the ASCII table.

Challenge

Your task is to write a program or function which takes no input, and outputs this exact text:

          !
         "#
         $%
         &'
         ()
         *+
         ,-
         ./
         01
23456789:;<=>?@ABCDEF
GHIJKLMNOPQRSTUVWXYZ[
        \]^_
       `a  bc
      de    fg
     hi      jk
    lm        no
   pq          rs
  tu            vw
 xy              z{
|}                ~

For reference, this site lists the complete ASCII table.
Rules

    The output should be the exact text, as shown above. Leading/trailing whitespace is allowed.
    Standard golfing loopholes apply - no reading this ASCIIrisk from the internet, etc.
    This is code-golf, so the shortest solution (in bytes) wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(ART)
}

const ART = `
          !
         "#
         $%
         &'
         ()
         *+
         ,-
         ./
         01
23456789:;<=>?@ABCDEF
GHIJKLMNOPQRSTUVWXYZ[
        \]^_
       ` + "`" + `a  bc
      de    fg
     hi      jk
    lm        no
   pq          rs
  tu            vw
 xy              z{
|}                ~
`
