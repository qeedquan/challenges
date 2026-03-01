/*

This is a cigarette.

   _
  //
 //
//
°
This is two (2) cigarettes.

   __
  ///
 ///
///
°°
This is three (3) cigarettes. The third is stacked upon the other two.

    _
   //
  ///
 ///
/°/
°°
Write a function to print 500 cigarettes, stacked according to the following rules:

There must be a single pile of cigarettes. (You're not allowed to print 500 individual cigarettes in a line, or 250 pairs of cigarettes, etc. etc.: you must stack them in accordance with the above diagrams.)
The pile need not come to a point (the highest layer (apex) may contain more than 1 cigarette).
All layers (excluding the apex and base) must be as wide as possible; if the base of your pile is a layer of 20 cigarettes, the next layer must be 19 cigarettes long, unless it is the apex.
The apex must be aligned to the left of the pile.
The pile must be as tall as possible.
Shortest program wins. Good luck!

EDIT: For reference for other players, this is the target output.

                           ________
                          /////////
                         //////////
                        ///////////
                       /°°°°°°°°///
                      /°°°°°°°°°///
                     /°°°°°°°°°°///
                    /°°°°°°°°°°°///
                   /°°°°°°°°°°°°///
                  /°°°°°°°°°°°°°///
                 /°°°°°°°°°°°°°°///
                /°°°°°°°°°°°°°°°///
               /°°°°°°°°°°°°°°°°///
              /°°°°°°°°°°°°°°°°°///
             /°°°°°°°°°°°°°°°°°°///
            /°°°°°°°°°°°°°°°°°°°///
           /°°°°°°°°°°°°°°°°°°°°///
          /°°°°°°°°°°°°°°°°°°°°°///
         /°°°°°°°°°°°°°°°°°°°°°°///
        /°°°°°°°°°°°°°°°°°°°°°°°///
       /°°°°°°°°°°°°°°°°°°°°°°°°///
      /°°°°°°°°°°°°°°°°°°°°°°°°°///
     /°°°°°°°°°°°°°°°°°°°°°°°°°°///
    /°°°°°°°°°°°°°°°°°°°°°°°°°°°///
   /°°°°°°°°°°°°°°°°°°°°°°°°°°°°///
  /°°°°°°°°°°°°°°°°°°°°°°°°°°°°°///
 /°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°//
/°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°/
°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
Many thanks to Themoonisacheese for her contribution here!

*/

package main

import "fmt"

func main() {
	fmt.Println(CIGS)
}

const CIGS = `
                           ________
                          /////////
                         //////////
                        ///////////
                       /°°°°°°°°///
                      /°°°°°°°°°///
                     /°°°°°°°°°°///
                    /°°°°°°°°°°°///
                   /°°°°°°°°°°°°///
                  /°°°°°°°°°°°°°///
                 /°°°°°°°°°°°°°°///
                /°°°°°°°°°°°°°°°///
               /°°°°°°°°°°°°°°°°///
              /°°°°°°°°°°°°°°°°°///
             /°°°°°°°°°°°°°°°°°°///
            /°°°°°°°°°°°°°°°°°°°///
           /°°°°°°°°°°°°°°°°°°°°///
          /°°°°°°°°°°°°°°°°°°°°°///
         /°°°°°°°°°°°°°°°°°°°°°°///
        /°°°°°°°°°°°°°°°°°°°°°°°///
       /°°°°°°°°°°°°°°°°°°°°°°°°///
      /°°°°°°°°°°°°°°°°°°°°°°°°°///
     /°°°°°°°°°°°°°°°°°°°°°°°°°°///
    /°°°°°°°°°°°°°°°°°°°°°°°°°°°///
   /°°°°°°°°°°°°°°°°°°°°°°°°°°°°///
  /°°°°°°°°°°°°°°°°°°°°°°°°°°°°°///
 /°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°//
/°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°/
°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
`
