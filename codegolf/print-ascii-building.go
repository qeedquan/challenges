/*

Challenge

Display to the screen or write to stdout this exactly:

    **
    **
   ****
   ****
   ****
   ****
   ****
   ****
   ****
**********
**********
**********

Winning

This is code-golf, so the shortest submission (in bytes) wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(BUILDING)
}

const BUILDING = `
    **
    **
   ****
   ****
   ****
   ****
   ****
   ****
   ****
**********
**********
**********
`
