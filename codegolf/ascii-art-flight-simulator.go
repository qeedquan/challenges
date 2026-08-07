/*

It appears that there has been some confusion following my typo in the original post which used a lowercase o to define the plane and then an uppercase later. Unfortunately this bug did not get picked up in the Sandbox. Since many members have written answers with both and since the typo was my fault I will allow either uppercase or lowercase o in the definition of the plane. I have added a new rule for this.

Background

I like ascii art animations as I tend to call them so here is another one. I don't think this is too difficult to implement so will hopefully get some short and interesting answers.

To all fellow community members

If you improve on your answer please modify your byte count as

old byte count new byte count

so we can see your progress. Thanks!

Challenge

Here is an ascii plane

--O--

Here is an ascii runway

____|     |____

The plane starts at 5 newlines above the runway. To prevent any clashes between metric and imperial systems and make this a truly international challenge I won't mention meters or feet. Example:

        --O--




____|     |____

The Plane must land exactly in the middle of the runway as shown below:

____|--O--|____

Input

The initial horizontal position of the plane is defined by an integer input which is used to reference the tip of the left wing i.e. it is between 0 and 10 inclusive.

Output

Each stage of the planes flight must be shown. Example below (input=10):

          --O--




____|     |____

         --O--



____|     |____

        --O--


____|     |____

       --O--

____|     |____

      --O--
____|     |____

____|--O--|____

To keep things simple, we are ignoring the laws of perspective. The runway stays the same size as you get closer.

Rules

    Update The middle of the plane can be either an uppercase or lowercase o but whichever is chosen must be consistent throughout the code. If your language does not support the characters above feel free to use alternative ascii only characters.
    The plane descends 1 line per frame.
    The plane can only move 1 space to the left or right each time it descends one line. It does not have to move on each line of descent. As long as it finishes on the runway it is up to you when it moves right or left. You're the pilot!
    No error handling required. You may assume that the input will always be a valid integer from 0-10 inclusive.
    Output must consist of only the characters shown above (if your language does not support them the see edited first rule) and must be the same size i.e. must start 6 lines high by 15 characters wide. The height can decrease as it progresses as in the example above.
    Program or function is fine but must produce an output as shown above.
    Leading/trailing spaces/newlines are fine by me.
    Please feel free to clear the screen between output frames if you wish. This is not a requirement.
    Standard loopholes prohibited as usual (although I don't think there are many that would help with this kind of challenge).
    This is code golf so shortest answer is obviously the winner and will probably get most votes but may not necessarily be accepted as the best answer if some really interesting solution comes along in some unexpected language, even if it is longer. Feel free to post anything that meets the rules as long as it works.

Ungolfed reference implementation in Python 2 available at Try it online! so you can see how it looks for different input values.


*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	flight(10)
}

func flight(n int) {
	for h := 5; h > 0; h-- {
		fmt.Print(strings.Repeat(" ", n))
		fmt.Print("--O--")
		fmt.Print(strings.Repeat("\n", h))
		fmt.Println("____|     |____\n")
		n -= cmp(n, 5)
	}
	fmt.Println("____|--O--|____")
}

func cmp(a, b int) int {
	if a < b {
		return -1
	}
	if a > b {
		return 1
	}
	return 0
}
