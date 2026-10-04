/*

Remember those brute-force programs to crack password that show every combination they are trying? More precisely, at one point, the n first characters are fixed (they have been guessed successfully), and every possible character for the remaining ones is being tested. You've probably seen some in movies, or in some software written by people that like fancy interfaces.
Sorry to disappoint, but we won't write a program to crack password, only one to reproduce the nice output.

Challenge
Given a string containing printable ascii characters but no newlines (ascii code 32 to 126 or matching the regex ^[ -~]{2,}$), print an output following this rules:

At time t=n seconds, the n first characters printed are the n first characters of the input string.
After the n fixed characters, you should append a string formed random character (chosen uniformly pseudo-randomly from the unicode range   to ~ (code 32 to 126)) to form a string of the length of the initial one.
You should output at least (more on that later) 20 lines every second: every one of them will have the same n first characters, but a different random end.
It's probably not very clear yet what you are supposed to do, so lets go through an example:

Example
I'll print only 5 different lines for every seconds instead of the 20 minimum just to make it more readable.

Consider the input abcde.
During the first second, a valid output can be something like (completely random):

dGuT4
S!jkN
"gQ>[
TU3!
*fAjV
Then, t=1, the first character of every following string will be a (the first character of the input):

a);jD
aHv^p
aqw5*
a|.?:
a{gbK
Now, t=2, the first two characters will be ab:

abTJ"
ab\ e
ab3T#
abYWS
ab"#<
Now, t=3, the first three characters will be abc :

abcvW
abc3G
abc(g
abc{@
abc@4
Now, t=4, the first four characters will be abcd :

abcdD
abcdv
abcdj
abcd$
abcd6
Finally, t=5, we print the input (only once):

abcde
A few precisions
You shouldn't bother too much with your language precision toward the seconds (ie. If your algorithm is correct but your system/language lacks precision then it's fine).
The first second can be shorter than one second (That is, if you launch you program during a second, the first second can be just the remaining time until the end of the current second). Or put differently, you don't have to wait for the start of a new second to start printing the outputs.
At least 20 lines per second: The more natural way would be an infinite loop with a special behaviour one every second (or a timeout, or whatever), so that will result in probably a few thousand lines per second (and that's perfectly fine!). But if you have another idea, feel free to use it as long as you print at least 20 lines per second.
The input will always be more than 2 characters long.
You can consider that the input won't be more that 30 characters long if it helps. (But if it works for longer ones, it's for the best)
The input format should be the most natural representation of a string in your language.
You are allowed to print a trailing newline.
Code example
If you still don't understand exactly what you have to do, you can run the following code in a linux terminal to see:

perl -F -aplE 'map{$t=time;print$s,map{chr 32+rand 94}@F until$t-time;$s.=shift@F}@F' <<< "Cracking in progress\!"
Winning criterion
This is code-golf, so shortest code in byte wins!

Thanks to Laikoni and Flp.Tkc for their suggestions and improvement in the sandbox.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	crack("abcde")
}

func crack(s string) {
	t := time.Now()
	n := len(s)
	for i := 0; i < n; {
		fmt.Print(s[:i])
		for j := i; j < n; {
			c := 32 + rand.Intn(95)
			if byte(c) != s[j] {
				fmt.Printf("%c", c)
				j += 1
			}
		}
		fmt.Println()

		if time.Since(t) >= time.Second {
			t = time.Now()
			i += 1
		}
	}
	fmt.Println(s)
}
