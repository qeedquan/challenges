/*

Inspired by this and the following chat:

https://i.stack.imgur.com/STXcP.jpg

Your task is to output the following:

   _ _ _
  /_/_/_/\
 /_/_/_/\/\
/_/_/_/\/\/\
\_\_\_\/\/\/
 \_\_\_\/\/
  \_\_\_\/

Extra leading or trailing whitespace is allowed, as long as it does not change the appearance of the cube. As usual, returning the above or a list of strings from a function is allowed.

This is code-golf, so shortest answer in bytes wins!

*/

package main

import "fmt"

func main() {
	fmt.Println(CUBE)
}

const CUBE = `
   _ _ _
  /_/_/_/\
 /_/_/_/\/\
/_/_/_/\/\/\
\_\_\_\/\/\/
 \_\_\_\/\/
  \_\_\_\/
`
