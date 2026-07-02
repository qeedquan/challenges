/*

All Aboard the ASCII Train!
    o O O   ___     ___     ___     ___     ___     ___     ___     ___     ___
   o       | C |   | O |   | D |   | E |   |   |   | G |   | O |   | L |   | F |
  TS__[O]  |___|   |___|   |___|   |___|   |___|   |___|   |___|   |___|   |___|
 {======|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|
./o--000'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'
You best be prepared to ride the train, because you're about to build the train you'll be riding on. Given a string s, output a fully formed train as depicted above. The first thing output is always the engine that'll be tugging your string along, as depicted alone below:

    o O O
   o
  TS__[O]
 {======|
./o--000'
Following the locomotive are rail-cars containing each character of your precious cargo. To save confusion when unloading, your company has tasked you with labeling the outside of these cars. The cars in question will always look like this:

   ___
  | # |
  |___|
_|"""""|
"`-0-0-'
Where the # is representative of the character that is inside the "cargo" hold. Chaining the engine to each car is also part of your job, as you've been tasked with overseeing the fluidity and success of this entire shipment. So, once you've labeled all the cars and got the engine on the tracks, you must ensure that the train is assembled and ready to roll.

Rules
The only input your program should take is a single string.
The engine must always be output, even if your shipment is empty.
Each car can only hold one character, don't push your luck you may damage the goods.
You need only support the following printable ASCII characters: _-0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
If you end up doing more, that's fine too, but this is the bare minimum.
1-2 trailing spaces are acceptable, as is a single trailing newline.
This is code-golfascii-art, shortest byte-count wins.

*/

package main

import "fmt"

func main() {
	train("CODE GOLF")
}

func train(s string) {
	H := []string{
		"    o O O ",
		"   o      ",
		"  TS__[O] ",
		" {======| ",
		"./o--000' ",
	}
	P := []string{
		"   ___  ",
		"  | # | ",
		"  |___| ",
		`_|"""""|`,
		"\"`-0-0-'",
	}

	for y := range 5 {
		fmt.Print(H[y])
		for i := range len(s) {
			for _, c := range P[y] {
				if c == '#' {
					c = rune(s[i])
				}
				fmt.Printf("%c", c)
			}
		}
		fmt.Println()
	}
	fmt.Println()
}
