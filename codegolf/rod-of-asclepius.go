/*

With this challenge we pay homage to everyone around the whole world fighting against the coronavirus crisis; particularly represented are the people tied to medicine, as the Rod of Asclepius is a symbol associated with medicine and health care.

For that matter, we resort to some ASCII art found at asciiart.eu (wrongfully) listed under the ASCII art associated with the Rod of Caduceus.

Task
Your task is to print or return the following modified art of an original by Juergen Jakubowski:

                          LLLLLLLLLLLLLLLLLLL
                          LLLLLLLLLLLLLLLLLLL
                          LLLLLLLLLLLLLLLLLLL
                          LLLLLLLLLLLLLLLLLLL
                          LLLLLLLLLLLLLLLLLLL
          LLL             LLLLLLLLLLLLLLLLLLL             LLL
         LLLLLLL          LLLLLLLLLLLLLLLLLLL          LLLLLLL
         LLLLLLLLLL       LLLLLLLLL  LLLLLLLL       LLLLLLLLLL
        LLLLLLLLLLLLL     LLLLLLLLL      LLLL     LLLLLLLLLLLLL
       LLLLLLLLLLLLLLLLL  LLLLL L  LL    LLLL  LLLLLLLLLLLLLLLLL
      LLLLLLLLLLLLLLLLLLLLLLL   LLL  LL    LLLLLLLLLLLLLLLLLLLLLL
     LLLLLLLLLLLLLLLLLLLLLLL      LLLLLL  LLLLLLLLLLLLLLLLLLLLLLLL
    LLLLLLLLLLLLLLLLLLLLLLL    LLLLLLLLL  LLLLLLLLLLLLLLLLLLLLLLLLL
   LLLLLLLLLLLLLLLLLLLLLLLL     LLLL     LLLLLLLLLLLLLLLLLLLLLLLLLLL
 LLLLLLLLLLLLLLLLLLLLLLLLLLL        LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
 LLLLLLLLLLLLLLLLLLLLLLLLLLLLL          LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
    LLLLLLLLLLLLLLLLLLLLLLLLLLLLL         LLLLLLLLLLLLLLLLLLLLLLLLL
       LLLLLLLLLLLLLLLLLLLLLLLLLLLLL       LLLLLLLLLLLLLLLLLLLLL
          LLLLLLLLLLLLLLLLLLLLLLLLLLLLL      LLLLLLLLLLLLLLLL
             LLLLLLLLLLLLLLLLLLLLLL  LLL     LLLLLLLLLLLLL
              LLLLLLLLLLLLLLLLLLLL    L     LLLLLLLLLLLLL
                LLLLLLLLLLLLLLLL  LL   L   LLLLLLLLLLLL
            LLLLLLLLLLLLLLLLLLL   LL  L LLLLLLLLLLLLLLLLLLL
          LLLLLLLLLLLLLLLLLLLLL      LLLLLLLLLLLLLLLLLLLLLLLL
       LLLLLLLLLLLLLLLLLLLLLLLLL       LLLLLLLLLLLLLLLLLLLLLLLLL
    LLLLLLLLLLLLLLLLLLLLLLLLLLLLL        LLLLLLLLLLLLLLLLLLLLLLLLLL
 LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL       LLLLLLLLLLLLLLLLLLLLLLLLLLLL
  LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL    LLLLLLLLLLLLLLLLLLLLLLLLLLL
   LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL LLL   LLLLLLLLLLLLLLLLLLLLLLLLLL
    LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL   L  LLLLLLLLLLLLLLLLLLLLLLLLLL
     LLLLLLLLLLLLLLLLLLLLLLLLLLL      LLLLLLLLLLLLLLLLLLLLLLLLLLLL
       LLLLLLLLLLLLLLLLLL LLLLLL   L  LLLLLLL LLLLLLLLLLLLLLLLLL
       LLLLLLLLLLLLLLL    LLLLLL    LLLLLLLLL    LLLLLLLLLLLLLLL
        LLLLLLLLLLLL      LLLLLLL     LLLLLLL      LLLLLLLLLLLL
         LLLLLLLL         LLLLLLLLL     LLLLL         LLLLLLLL
         LLLLL            LLLLLLLLLLL  LLLLLL            LLLLL
          LL              LLLLLLLLLLLLLLLLLLL              LL
                          LLLLLLLLLL LLLLLLLL
                          LLLLLLLLLL LLLLLLLL
                          LLLLLLLLLLLLLLLLLLL
                          LLLLLLLLLLLLLLLLLLL
                          LLLLLLLLLLLLLLLLLLL

This art has been made more symmetrical, non-L characters have been replaced by Ls and the author name and e-mail have been removed from the art.

You may add/remove leading/trailing whitespace as long as the layout of the Ls and the whitespace within them doesn't change.

This is code-golf so shortest submission in bytes, wins! If you liked this challenge, consider upvoting it! If you dislike this challenge, please give me your feedback. Happy golfing!

*/

package main

import "fmt"

func main() {
	fmt.Println(ART)
}

const ART = `
                          LLLLLLLLLLLLLLLLLLL
                          LLLLLLLLLLLLLLLLLLL
                          LLLLLLLLLLLLLLLLLLL
                          LLLLLLLLLLLLLLLLLLL
                          LLLLLLLLLLLLLLLLLLL
          LLL             LLLLLLLLLLLLLLLLLLL             LLL
         LLLLLLL          LLLLLLLLLLLLLLLLLLL          LLLLLLL
         LLLLLLLLLL       LLLLLLLLL  LLLLLLLL       LLLLLLLLLL
        LLLLLLLLLLLLL     LLLLLLLLL      LLLL     LLLLLLLLLLLLL
       LLLLLLLLLLLLLLLLL  LLLLL L  LL    LLLL  LLLLLLLLLLLLLLLLL
      LLLLLLLLLLLLLLLLLLLLLLL   LLL  LL    LLLLLLLLLLLLLLLLLLLLLL
     LLLLLLLLLLLLLLLLLLLLLLL      LLLLLL  LLLLLLLLLLLLLLLLLLLLLLLL
    LLLLLLLLLLLLLLLLLLLLLLL    LLLLLLLLL  LLLLLLLLLLLLLLLLLLLLLLLLL
   LLLLLLLLLLLLLLLLLLLLLLLL     LLLL     LLLLLLLLLLLLLLLLLLLLLLLLLLL
 LLLLLLLLLLLLLLLLLLLLLLLLLLL        LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
 LLLLLLLLLLLLLLLLLLLLLLLLLLLLL          LLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
    LLLLLLLLLLLLLLLLLLLLLLLLLLLLL         LLLLLLLLLLLLLLLLLLLLLLLLL
       LLLLLLLLLLLLLLLLLLLLLLLLLLLLL       LLLLLLLLLLLLLLLLLLLLL
          LLLLLLLLLLLLLLLLLLLLLLLLLLLLL      LLLLLLLLLLLLLLLL
             LLLLLLLLLLLLLLLLLLLLLL  LLL     LLLLLLLLLLLLL
              LLLLLLLLLLLLLLLLLLLL    L     LLLLLLLLLLLLL
                LLLLLLLLLLLLLLLL  LL   L   LLLLLLLLLLLL
            LLLLLLLLLLLLLLLLLLL   LL  L LLLLLLLLLLLLLLLLLLL
          LLLLLLLLLLLLLLLLLLLLL      LLLLLLLLLLLLLLLLLLLLLLLL
       LLLLLLLLLLLLLLLLLLLLLLLLL       LLLLLLLLLLLLLLLLLLLLLLLLL
    LLLLLLLLLLLLLLLLLLLLLLLLLLLLL        LLLLLLLLLLLLLLLLLLLLLLLLLL
 LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL       LLLLLLLLLLLLLLLLLLLLLLLLLLLL
  LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL    LLLLLLLLLLLLLLLLLLLLLLLLLLL
   LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL LLL   LLLLLLLLLLLLLLLLLLLLLLLLLL
    LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL   L  LLLLLLLLLLLLLLLLLLLLLLLLLL
     LLLLLLLLLLLLLLLLLLLLLLLLLLL      LLLLLLLLLLLLLLLLLLLLLLLLLLLL
       LLLLLLLLLLLLLLLLLL LLLLLL   L  LLLLLLL LLLLLLLLLLLLLLLLLL
       LLLLLLLLLLLLLLL    LLLLLL    LLLLLLLLL    LLLLLLLLLLLLLLL
        LLLLLLLLLLLL      LLLLLLL     LLLLLLL      LLLLLLLLLLLL
         LLLLLLLL         LLLLLLLLL     LLLLL         LLLLLLLL
         LLLLL            LLLLLLLLLLL  LLLLLL            LLLLL
          LL              LLLLLLLLLLLLLLLLLLL              LL
                          LLLLLLLLLL LLLLLLLL
                          LLLLLLLLLL LLLLLLLL
                          LLLLLLLLLLLLLLLLLLL
                          LLLLLLLLLLLLLLLLLLL
                          LLLLLLLLLLLLLLLLLLL
`