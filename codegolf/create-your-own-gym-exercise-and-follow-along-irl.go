/*

Let's do an exercise together, shall we? Simply follow the movements of the stickman. What stickman you ask? The one we are about to create!

Make a program that allows for a string-input only containing integers, and outputs the following nine stick-figures with an interval in between:

 @  \@/ |@_ _@| @/   \@ |@| \@\ /@/
/|\  |   |   |   |   |   |   |   |
/ \ / \ / \ / \ /|\ /|\ / \ / \ / \
 1   2   3   4   5   6   7   8   9
This will result in an animation, which we can then follow along irl.

Here is an example of the output created when the input is "123245762":

https://i.sstatic.net/7p9UX.gif

Some rules:

This is tagged code-golf, so shortest code in bytes wins
The input is a string only containing [1-9] with a length potentially varying from 2 to 100 characters **
The animation must be an endless loop
The interval time must be 750 ms
No duplicated adjacent integers are allowed in the input - this also includes the first and last integers of the input (see the seventh and eight test cases) **
** How it fails in case of invalid input is completely up to you, but it should be clear that it fails. It could throw an exception; simply return at the start; reboot your PC; delete it's own source-/compile-code; hack into the military and shoots a rocket to the compiling GPS-location. Your call. EDIT: It's not allowed to simply display a (correct / half) animation as failing input. It must be clear that something is wrong with the input for the failing testcases below. Thanks to @user81655 for bringing this to my attention, hence the edit.

Subrules:

Please post the gif for one of the (non-failing) test cases below in your answer, which you can make very easy with the following program: screentogif.codeplex.com (Any other gif-creating program is also allowed of course.)
Bonus points if you actually do the exercise alongside the animation irl when it's finished. ;)
Correct testcases:

123245762
65
121234346565879879132418791576
Failing testcases:

2 // Too few characters
7282918274959292747383785189478174826894958127476192947512897571298593912374857471978269591928974518735891891723878 // Too much characters
1232405762 // Containing invalid input (the 0)
112212 // Fails because of the 11 and 22 present
1232457621 // Fails because of the starting and leading 1

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	animate("123245762")
}

func animate(routine string) {
	for {
		step(routine)
	}
}

func step(routine string) {
	for _, code := range routine {
		if !('1' <= code && code <= '9') {
			continue
		}

		clear()
		j := (code - '1') * 4
		for i := range STICKS {
			fmt.Println(STICKS[i][j : j+4])
		}
		time.Sleep(750 * time.Millisecond)
	}
}

func clear() {
	fmt.Printf("\033c")
}

var STICKS = []string{
	` @  \@/ |@_ _@| @/   \@ |@| \@\ /@/ `,
	`/|\  |   |   |   |   |   |   |   |  `,
	`/ \ / \ / \ / \ /|\ /|\ / \ / \ / \ `,
}
