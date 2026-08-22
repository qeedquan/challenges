/*

You might know Alan Walker from his ever popular song Faded. Now his "followers" are called Walkers and they have a logo, here is a simplified version:

\\
 \\              //\\
  \\            //  \\            //
   \\          //    \\          //
    \\        //      \\        //
     \\      //        \\      //
      \\    //          \\    //
       \\  //    //\\    \\  //
        \\//    //  \\    \\//
         //    //    \\    \\
        //\\  //      \\  //\\
           \\//        \\//  \\
                              \\
The goal of this challenge is to print this logo.

RULES:

If you return a list of strings from a function as per meta standards, please provide a footer that prints it to the screen.
All characters of the above logo have to be there. No shortcuts!
Shortest number of bytes wins!

*/

package main

import "fmt"

func main() {
	fmt.Println(LOGO)
}

const LOGO = `

\\
 \\              //\\
  \\            //  \\            //
   \\          //    \\          //
    \\        //      \\        //
     \\      //        \\      //
      \\    //          \\    //
       \\  //    //\\    \\  //
        \\//    //  \\    \\//
         //    //    \\    \\
        //\\  //      \\  //\\
           \\//        \\//  \\
                              \\
`
