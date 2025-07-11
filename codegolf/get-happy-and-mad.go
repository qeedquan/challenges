/*

Requirements

You need to make a smiley face go from smiling to frowning and back. There needs to the below faces in the code: Smiling, no expression, frowning, no expression, and then back to smiling. The new face needs to replace the old face flipbook style so that there's only one face on the screen at a time. There is no input required it will just be a loop that displays one face, pauses for 200 milliseconds, and replaces the current face with the next and so on looping forever.

Faces to use:

                      __ooooooooo__
                 oOOOOOOOOOOOOOOOOOOOOOo
             oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
          oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
        oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
      oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
     oOOOOOOOOOOO*  *OOOOOOOOOOOOOO*  *OOOOOOOOOOOOo
    oOOOOOOOOOOO      OOOOOOOOOOOO      OOOOOOOOOOOOo
    oOOOOOOOOOOOOo  oOOOOOOOOOOOOOOo  oOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOO     OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     OOOOo
   oOOOOOO OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO OOOOOOo
    *OOOOO  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  OOOOO*
    *OOOOOO  *OOOOOOOOOOOOOOOOOOOOOOOOOOOOO*  OOOOOO*
     *OOOOOO  *OOOOOOOOOOOOOOOOOOOOOOOOOOO*  OOOOOO*
      *OOOOOOo  *OOOOOOOOOOOOOOOOOOOOOOO*  oOOOOOO*
        *OOOOOOOo  *OOOOOOOOOOOOOOOOO*  oOOOOOOO*
          *OOOOOOOOo  *OOOOOOOOOOO*  oOOOOOOOO*
             *OOOOOOOOo           oOOOOOOOO*
                 *OOOOOOOOOOOOOOOOOOOOO*
                      ""ooooooooo""

                      __ooooooooo__
                 oOOOOOOOOOOOOOOOOOOOOOo
             oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
          oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
        oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
      oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
     oOOOOOOOOOOO*  *OOOOOOOOOOOOOO*  *OOOOOOOOOOOOo
    oOOOOOOOOOOO      OOOOOOOOOOOO      OOOOOOOOOOOOo
    oOOOOOOOOOOOOo  oOOOOOOOOOOOOOOo  oOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
    *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
    *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
     *OOOOOOOOoOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOOOO*
      *OOOOOOo                             oOOOOOO*
        *OOOOOoOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOO*
          *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
             *OOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
                 *OOOOOOOOOOOOOOOOOOOOO*
                      ""ooooooooo""

                      __ooooooooo__
                 oOOOOOOOOOOOOOOOOOOOOOo
             oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
          oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
        oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
      oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
     oOOOOOOOOOOO*  *OOOOOOOOOOOOOO*  *OOOOOOOOOOOOo
    oOOOOOOOOOOO      OOOOOOOOOOOO      OOOOOOOOOOOOo
    oOOOOOOOOOOOOo  oOOOOOOOOOOOOOOo  oOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
    *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
    *OOOOOOOOOOOOOO                  OOOOOOOOOOOOOOO*
     *OOOOOOOOOOO                      OOOoOOOOOOOO*
      *OOOOOO       OOOOOOOOOOOOOOOO        OOOOOO*
        *OOOOO   OOOOOOOOOOOOOOOOOOOOOO   OOOOOO*
          *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
             *OOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
                 *OOOOOOOOOOOOOOOOOOOOO*
                      ""ooooooooo""

                      __ooooooooo__
                 oOOOOOOOOOOOOOOOOOOOOOo
             oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
          oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
        oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
      oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
     oOOOOOOOOOOO*  *OOOOOOOOOOOOOO*  *OOOOOOOOOOOOo
    oOOOOOOOOOOO      OOOOOOOOOOOO      OOOOOOOOOOOOo
    oOOOOOOOOOOOOo  oOOOOOOOOOOOOOOo  oOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
    *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
    *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
     *OOOOOOOOoOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOOOO*
      *OOOOOOo                             oOOOOOO*
        *OOOOOoOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOO*
          *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
             *OOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
                 *OOOOOOOOOOOOOOOOOOOOO*
                      ""ooooooooo""
Only one face shows up at a time and it should loop forever cycling between happy indifferent and sad.

Goal

Have the shortest code is always the goal but being able to tell that the output is actual a face is quite important.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	animate()
}

func animate() {
	faces := []string{FACE1, FACE2, FACE3, FACE4}
	frame := 0
	for {
		fmt.Printf("\x1bc")
		fmt.Println(faces[frame])
		time.Sleep(200 * time.Millisecond)
		frame = (frame + 1) % len(faces)
	}
}

const FACE1 = `
                      __ooooooooo__
                 oOOOOOOOOOOOOOOOOOOOOOo
             oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
          oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
        oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
      oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
     oOOOOOOOOOOO*  *OOOOOOOOOOOOOO*  *OOOOOOOOOOOOo
    oOOOOOOOOOOO      OOOOOOOOOOOO      OOOOOOOOOOOOo
    oOOOOOOOOOOOOo  oOOOOOOOOOOOOOOo  oOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOO     OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     OOOOo
   oOOOOOO OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO OOOOOOo
    *OOOOO  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  OOOOO*
    *OOOOOO  *OOOOOOOOOOOOOOOOOOOOOOOOOOOOO*  OOOOOO*
     *OOOOOO  *OOOOOOOOOOOOOOOOOOOOOOOOOOO*  OOOOOO*
      *OOOOOOo  *OOOOOOOOOOOOOOOOOOOOOOO*  oOOOOOO*
        *OOOOOOOo  *OOOOOOOOOOOOOOOOO*  oOOOOOOO*
          *OOOOOOOOo  *OOOOOOOOOOO*  oOOOOOOOO*
             *OOOOOOOOo           oOOOOOOOO*
                 *OOOOOOOOOOOOOOOOOOOOO*
                      ""ooooooooo""
`

const FACE2 = `
                      __ooooooooo__
                 oOOOOOOOOOOOOOOOOOOOOOo
             oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
          oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
        oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
      oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
     oOOOOOOOOOOO*  *OOOOOOOOOOOOOO*  *OOOOOOOOOOOOo
    oOOOOOOOOOOO      OOOOOOOOOOOO      OOOOOOOOOOOOo
    oOOOOOOOOOOOOo  oOOOOOOOOOOOOOOo  oOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
    *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
    *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
     *OOOOOOOOoOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOOOO*
      *OOOOOOo                             oOOOOOO*
        *OOOOOoOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOO*
          *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
             *OOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
                 *OOOOOOOOOOOOOOOOOOOOO*
                      ""ooooooooo""
`

const FACE3 = `
                      __ooooooooo__
                 oOOOOOOOOOOOOOOOOOOOOOo
             oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
          oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
        oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
      oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
     oOOOOOOOOOOO*  *OOOOOOOOOOOOOO*  *OOOOOOOOOOOOo
    oOOOOOOOOOOO      OOOOOOOOOOOO      OOOOOOOOOOOOo
    oOOOOOOOOOOOOo  oOOOOOOOOOOOOOOo  oOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
    *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
    *OOOOOOOOOOOOOO                  OOOOOOOOOOOOOOO*
     *OOOOOOOOOOO                      OOOoOOOOOOOO*
      *OOOOOO       OOOOOOOOOOOOOOOO        OOOOOO*
        *OOOOO   OOOOOOOOOOOOOOOOOOOOOO   OOOOOO*
          *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
             *OOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
                 *OOOOOOOOOOOOOOOOOOOOO*
                      ""ooooooooo""
`

const FACE4 = `
                      __ooooooooo__
                 oOOOOOOOOOOOOOOOOOOOOOo
             oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
          oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
        oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
      oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
     oOOOOOOOOOOO*  *OOOOOOOOOOOOOO*  *OOOOOOOOOOOOo
    oOOOOOOOOOOO      OOOOOOOOOOOO      OOOOOOOOOOOOo
    oOOOOOOOOOOOOo  oOOOOOOOOOOOOOOo  oOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
    *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
    *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
     *OOOOOOOOoOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOOOO*
      *OOOOOOo                             oOOOOOO*
        *OOOOOoOOOOOOOOOOOOOOOOOOOOOOOOOOOoOOOOOO*
          *OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
             *OOOOOOOOOOOOOOOOOOOOOOOOOOOOO*
                 *OOOOOOOOOOOOOOOOOOOOO*
                      ""ooooooooo""
`
