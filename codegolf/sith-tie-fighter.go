/*

Today is May 5th which means it's Star-Wars Day episode II: Revenge of the 5th.

For this task, you will output the following image of a Sith TIE-fighter:

 ____         ____
/\  /\ ___   /\  /\
| \/  /   \  | \/ |
|--[=| (+) [=|-[]-|
| /\  \___/  | /\ |
\/__\/       \/__\/
Your output may have any extra whitespace that doesn't affect the representation of the image. You may output a list of lines instead of a string with newlines.

This is code-golf, so shortest answer wins.

(If it's May 4th in your time zone, try X-Wing Starfighter)

*/

package main

import "fmt"

func main() {
	fmt.Println(SHIP)
}

const SHIP = `
 ____         ____
/\  /\ ___   /\  /\
| \/  /   \  | \/ |
|--[=| (+) [=|-[]-|
| /\  \___/  | /\ |
\/__\/       \/__\/
`
