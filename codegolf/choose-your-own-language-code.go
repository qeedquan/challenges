/*

Let's take a grid of 16x16 printable ASCII characters (code points 0x20 to 0x7E). There are 30-choose-15 paths from the top left to the bottom right corner, making only orthogonal moves, like the following example:

##..............
.#..............
.######.........
......##........
.......##.......
........#.......
........#.......
........#.......
........###.....
..........###...
............#...
............####
...............#
...............#
...............#
Each such path consists of exactly 31 characters. Note that each of those characters is on a different of the 31 anti-diagonals:

0123456789ABCDEF
123456789ABCDEFG
23456789ABCDEFGH
3456789ABCDEFGHI
456789ABCDEFGHIJ
56789ABCDEFGHIJK
6789ABCDEFGHIJKL
789ABCDEFGHIJKLM
89ABCDEFGHIJKLMN
9ABCDEFGHIJKLMNO
ABCDEFGHIJKLMNOP
BCDEFGHIJKLMNOPQ
CDEFGHIJKLMNOPQR
DEFGHIJKLMNOPQRS
EFGHIJKLMNOPQRST
FGHIJKLMNOPQRSTU
This is not an example grid. This is a visualisation of the 31 anti-diagonals.

We'll call a grid diagonally unique if no anti-diagonal contains the same character twice. If the grid has this property, no two paths will contain the same string. (Just to clarify, the visualisation itself is basically the opposite of diagonally unique.)

The Challenge
Design a diagonally unique 16x16 grid, such that as many paths as possible are valid code which prints Jabberwocky to STDOUT (with optional trailing line break) in as many languages as possible. Each code may either be a full program, or the body of a parameterless function without return statement (this is in order not to discourage languages that need to have their code in some boilerplate function/class/namespace).

Note: For simplicity you can use some reserved character for unused cells like Ypnypn did.

For each valid path, please clearly state one programming language it is valid in.

The winner is the submission with the largest number of languages covered by the above list. (Alternatively, for each language you want to count, show one path which is valid in that language, but make sure not to count any path for two languages.)

In the event of a tie, count the grid cells which are not covered by any valid path. Fewer unused cells win. If there is still a tie, I'll accept the answer with the most (net) votes.

Validation Script
I just quickly put together a little CJam snippet you can use to validate that a grid is diagonally unique.

Go to the online CJam interpreter.
Paste the following code

l:A;
qN/W%A16**33/z{A-__|=}%:*"D""Not d"?"iagonally unique"
In the input field, put you reserved character on the first line (use an unused character if you don't make sue of a reserved character), and then your grid in line 2 to 17. E.g., for Ypnypn's answer:

~
 pr~~~~~~~~~~~~~
 tin~~~~~~~~~~~~
~ypt(~~~~~~~~~~~
~~ef(~~~~~~~~~~~
~~  "J~~~~~~~~~~
~~~~~ab~~~~~~~~~
~~~~~~be~~~~~~~~
~~~~~~~rwo~~~~~~
~~~~~~~~~ck~~~~~
~~~~~~~~~~y~~~~~
~~~~~~~~~~\n~~~~
~~~~~~~~~~~")) ~
~~~~~~~~~~~  ;
~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~
Run.

Let me know if you think it has a bug.

*/

package main

import "fmt"

func main() {
	fmt.Println(GRID)
}

/*

@grc

And here are the languages and their paths (ignore the vertical bars):

01. Rust        | println!(   "Jabberwocky" ) ; |
02. Swift       | println (   "Jabberwocky" ) ; |
03. Scala       | println (   "Jabberwocky" )   |
04. Falcon      | printl  (   "Jabberwocky" )   |
05. Vala        | print   (   "Jabberwocky" ) ; |
06. Lua         | print   (   'Jabberwocky' ) ; |
07. ALGOL 68    | print   (   "Jabberwocky" )   |
08. Dart        | print   (   'Jabberwocky' )   |
09. Rebol       | print       "Jabberwocky"   ; |
10. Perl        | print       'Jabberwocky'   ; |
11. AWK         | print       "Jabberwocky"     |
12. Euphoria    | puts    (1, "Jabberwocky" )   |
13. C           | puts    (   "Jabberwocky" ) ; |
14. Tcl         | puts        "Jabberwocky"     |
15. Ruby        | puts        'Jabberwocky'     |
16. Bash        |     echo    "Jabberwocky"     |
17. PHP         |     echo    "Jabberwocky"   ; |

*/

const GRID = `
 prin...........
 utstln!........
       (1,......
<?echo    ".....
.........'Jab...
............b...
............e...
............r...
............w...
............o...
............c...
............k...
............y"..
............' ).
.............  ;
..............
`
