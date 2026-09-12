/*

The Great Pyramid of Giza, the largest pyramid in Egypt, is not only the oldest of the Seven Wonders of the Ancient World, but it is also the only one to remain largely intact. The Egyptian Pyramids can take up to 20 years to build and are so big that Al-Aziz Uthman, son of the great Saladin who crushed the Crusaders, had to give up demolishing the Great pyramids of Giza because it was deemed too great a task. The Egyptian pyramids were mostly built as tombs for the country's Pharaohs and their consorts during the Old and Middle Kingdom periods (c. 2686–1690 BCE), and as of 2008, 138 Egyptian pyramids have been discovered.

The task is to create a program which inputs a sequence of distances separated by a space, and produces 10×10 text pyramids separated by those distances. A distance of 1 is equal to two characters.

A text pyramid will look like this:

         /\
        /--\
       /----\
      /------\
     /--------\
    /----------\
   /------------\
  /--------------\
 /----------------\
/------------------\
If the input consists of only a line break, then one pyramid will be produced, as above. For each pyramid, pyramids to the left are displayed as if they were in front.

Example I
Input:

4 3 1
Output:

         /\      /\    /\/\
        /--\    /--\  /--\-\
       /----\  /----\/----\-\
      /------\/------\-----\-\
     /--------\-------\-----\-\
    /----------\-------\-----\-\
   /------------\-------\-----\-\
  /--------------\-------\-----\-\
 /----------------\-------\-----\-\
/------------------\-------\-----\-\
Example II
Input:

0 9
Output:

         /\                /\
        /--\              /--\
       /----\            /----\
      /------\          /------\
     /--------\        /--------\
    /----------\      /----------\
   /------------\    /------------\
  /--------------\  /--------------\
 /----------------\/----------------\
/------------------\-----------------\
Example III
Input:

11
Output:

         /\                    /\
        /--\                  /--\
       /----\                /----\
      /------\              /------\
     /--------\            /--------\
    /----------\          /----------\
   /------------\        /------------\
  /--------------\      /--------------\
 /----------------\    /----------------\
/------------------\  /------------------\
The application to fulfill these requirements in the fewest amount of characters is the winner.

Reference: Wikipedia.org

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	pyramid([]int{4, 3, 1})
	pyramid([]int{0, 9})
	pyramid([]int{11})
}

func pyramid(d []int) {
	fmt.Println(d)
	d = append([]int{10}, d...)
	for y := range 10 {
		s := ""
		for _, n := range d {
			t := strings.Repeat(" ", 2*n) + "/" + strings.Repeat("-", 2*y) + `\ `
			s += t[len(t)-2*n-1 : len(t)-1]
		}
		fmt.Println(s[9-y:])
	}
	fmt.Println()
}
