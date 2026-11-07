/*

The challenge: Write a function, that delivers following output: "1 2 3 4 5 4 3 2 1".

Kids stuff? Of course. But here's the point:

You only can use: 1 for loop, 2 int variables.

You must not use: IF terms, another function, ...

Do not hardcode the output

There are also some more restrictions to make this harder:

No functions like abs or sth. else are allowed! (Yep, it's possible)
No static output like echo "1 2 3 4 5 4 3 2 1"
This is a popularity-contest, so the answer with the most votes wins!

*/

package main

import "fmt"

func main() {
	output()
}

// ported from @justhalf solution
func output() {
	for i := range 9 {
		fmt.Print(i + 1 - 2*(i/5)*(i-4))
	}
	fmt.Println()
}
