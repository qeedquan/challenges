/*

Your task is to print this exact text:

az                                               za
abyz                                           zyba
abcxyz                                       zyxcba
abcdwxyz                                   zyxwdcba
abcdevwxyz                               zyxwvedcba
abcdefuvwxyz                           zyxwvufedcba
abcdefgtuvwxyz                       zyxwvutgfedcba
abcdefghstuvwxyz                   zyxwvutshgfedcba
abcdefghirstuvwxyz               zyxwvutsrihgfedcba
abcdefghijqrstuvwxyz           zyxwvutsrqjihgfedcba
abcdefghijkpqrstuvwxyz       zyxwvutsrqpkjihgfedcba
abcdefghijklopqrstuvwxyz   zyxwvutsrqpolkjihgfedcba
abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba
  abcdefghijklopqrstuvwxyzyxwvutsrqpolkjihgfedcba
    abcdefghijkpqrstuvwxyzyxwvutsrqpkjihgfedcba
      abcdefghijqrstuvwxyzyxwvutsrqjihgfedcba
        abcdefghirstuvwxyzyxwvutsrihgfedcba
          abcdefghstuvwxyzyxwvutshgfedcba
            abcdefgtuvwxyzyxwvutgfedcba
              abcdefuvwxyzyxwvufedcba
                abcdevwxyzyxwvedcba
                  abcdwxyzyxwdcba
                    abcxyzyxcba
                      abyzyba
                        aza

The following are allowed:

Leaving out trailing spaces at the end of lines
Doing everything in uppercase instead of lowercase
Trailing newlines
Remember, this is code-golf, so the code with the smallest number of bytes wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(WING)
}

const WING = `
az                                               za
abyz                                           zyba
abcxyz                                       zyxcba
abcdwxyz                                   zyxwdcba
abcdevwxyz                               zyxwvedcba
abcdefuvwxyz                           zyxwvufedcba
abcdefgtuvwxyz                       zyxwvutgfedcba
abcdefghstuvwxyz                   zyxwvutshgfedcba
abcdefghirstuvwxyz               zyxwvutsrihgfedcba
abcdefghijqrstuvwxyz           zyxwvutsrqjihgfedcba
abcdefghijkpqrstuvwxyz       zyxwvutsrqpkjihgfedcba
abcdefghijklopqrstuvwxyz   zyxwvutsrqpolkjihgfedcba
abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba
  abcdefghijklopqrstuvwxyzyxwvutsrqpolkjihgfedcba
    abcdefghijkpqrstuvwxyzyxwvutsrqpkjihgfedcba
      abcdefghijqrstuvwxyzyxwvutsrqjihgfedcba
        abcdefghirstuvwxyzyxwvutsrihgfedcba
          abcdefghstuvwxyzyxwvutshgfedcba
            abcdefgtuvwxyzyxwvutgfedcba
              abcdefuvwxyzyxwvufedcba
                abcdevwxyzyxwvedcba
                  abcdwxyzyxwdcba
                    abcxyzyxcba
                      abyzyba
                        aza
`
