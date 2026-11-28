/*

We already now how to strip a string from its spaces.

However, as proper gentlemen/ladies, we should rather undress it.

Undressing a string is the same as stripping it, only more delicate. Instead of removing all leading and trailing spaces at once, we remove them one by one. We also alternate between leading and trailing, so as not to burn steps.

Example, starting with "     codegolf     " (five leading and trailing spaces):

     codegolf
    codegolf
    codegolf
   codegolf
   codegolf
  codegolf
  codegolf
 codegolf
 codegolf
codegolf
codegolf
First output the string unchanged. Then, output every step. Begin by removing a leading space (if applicable - see rule #2).

The input may have a different number of leading and trailing spaces. If you run out of spaces on one side, keep undressing the other until the string is bare.

The input may have no leading nor trailing spaces. If that's the case, output it as-is.

Use PPCG's default I/O methods. PPCG Default loopholes are forbidden.

Undefined behaviour on empty input, or input that only contains spaces, is OK.

You can assume that the string will only contain characters from the ASCII printable space (0x20 to 0x7E).

Examples - spaces are replaced by dots . for better readability:

4 leading spaces, 5 trailing: "....Yes, Sir!....."
....Yes, Sir!.....
...Yes, Sir!.....
...Yes, Sir!....
..Yes, Sir!....
..Yes, Sir!...
.Yes, Sir!...
.Yes, Sir!..
Yes, Sir!..
Yes, Sir!.
Yes, Sir!

6 leading, 3 trailing: "......Let's go golfing..."
......Let's go golfing...
.....Let's go golfing...
.....Let's go golfing..
....Let's go golfing..
....Let's go golfing.
...Let's go golfing.
...Let's go golfing
..Let's go golfing
.Let's go golfing
Let's go golfing

0 leading, 2 trailing: "Hello.."
Hello..
Hello.
Hello

0 leading, 0 trailing: "World"
World

21 leading, 5 trailing: ".....................a....."
.....................a.....
....................a.....
....................a....
...................a....
...................a...
..................a...
..................a..
.................a..
.................a.
................a.
................a
...............a
..............a
.............a
............a
...........a
..........a
.........a
........a
.......a
......a
.....a
....a
...a
..a
.a
a
A gentleman/lady is concise, so the shortest answer in bytes wins.

*/

package main

import "fmt"

func main() {
	undress("     codegolf     ")
	undress("    Yes, Sir!     ")
	undress("      Let's go golfing   ")
	undress("Hello  ")
	undress("World")
	undress("                     a     ")
}

func undress(s string) string {
	fmt.Println(s)
	for {
		f := true
		n := len(s)
		if n > 0 && s[0] == ' ' {
			s, n, f = s[1:], n-1, false
			fmt.Println(s)
		}

		if n > 0 && s[n-1] == ' ' {
			s, n, f = s[:n-1], n-1, false
			fmt.Println(s)
		}

		if f {
			break
		}
	}
	return s
}
