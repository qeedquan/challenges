/*

A connected graph is a graph that contains a path between any two vertices.

Challenge
Build a [2-input NAND-gate] circuit that determines whether a 4-vertex graph is connected.
(A gate's 2 inputs can be the same input bit or other gate.)
Output True if the graph is connected, and False otherwise.

Input
The six possible edges of a simple graph with 4 vertices:

[ 0e1 , 0e2 , 1e2 , 0e3 , 1e3 , 2e3 ​]

where aeb represents whether there is an edge between vertices a and b

Connectedness is equivalent to the following conditions:

If less than 3 inputs are True then output False.

If more than 3 inputs are True then output True.

If exactly 3 inputs are True and they form a triangle then output False.

Otherwise, output True.

The answer that uses the fewest gates wins. ​ Ties will be broken by
the lowest circuit depth (length of longest path(s) from input to output).

*/

package main

import "fmt"

func main() {
	for i := 0; i < 64; i++ {
		a := i % 2
		b := i / 2 % 2
		c := i / 4 % 2
		d := i / 8 % 2
		e := i / 16 % 2
		f := i / 32 % 2
		fmt.Printf("%d, %d\n", i, connected(a, b, c, d, e, f))
		fmt.Printf(WEB, d, e, f, a, c, b)
		fmt.Printf("----------\n\n")
	}
}

/*

@Level River St

30 NAND
Instead of asking when do we get a 1, I asked the question when do we get a 0. It's better to ask it this way round because there are less 0's than 1's.

Here's the distribution according to number of edges (6th row of pascal's triangle)

Edges     0  1  2  3  4  5  6
Frequency 1  6 15 20 15  6  1 (total 64)
Output    0  0  0  *  1  1  1
* = 0 if triangle (4 possibilities) 1 if claw (4 possibilities)
1 if two opposite edges and one other (12 possibilities)
Asking the question this way round, we get the following diagram and expression

 ___D___
|\     /|
| E   F |
|  \ /  |
A   X   C
|  / \  |
| /   \ |
|/__B__\|

(A|C|D|B)&(A|D|E)&(D|B|E|F)&(C|B|E)&(A|C|E|F)&(D|F|C)&(A|F|B)
We assume the output will default to 1, but will change to 0 under any of the following conditions

1.A 0 for three adjacent edges (test 3 inputs)

2.A 0 for two opposing pairs of edges (test 4 inputs)

The terms above are already ordered in the manner that will enable them to be grouped as below. (Incidentally, this version of the expression is rotationally symmetrical abouth the AFB vertex.)

((A|D)|((C|B)&E))&((B|E)|((D|F)&C))&((C|F)|((A|E)&D))&(A|F|B)    =6 inverters
   1      1  1       1      1  1       1      1  1      1        =10 (7 OR with both inputs inverted, 3 NAND)
      2                 2                 2               2      =8  (4 OR with one input inverted)
                 2                 2                 2           =6  (3 AND)
                                                        Total    =30
The score for each & or | is placed below the symbol and justified as follows:

Level 0: We invest in an inverter for each input: 6 NANDS

Level 1: We can build an OR from a NAND gate by putting an inverter at the input (total 3 NANDS) but as we already invested in 6 NANDS in the previous step we can make 7 OR gates from 7 NAND gates. We also need 3 AND gates. For these, we will just use NANDs and leave the output inverted. 10 NANDS

Level 2: Again we build 4 OR gates from NAND gates. In each case we have 1 input from an OR gate, so we have to invert that. But the other input is already inverted (coming from one of the NANDs in the previous step that corresponds to a & symbol in three cases, and from an inverter in the last one) so we only need 2 gates for each OR functionality. 4 * 2 =8

Level 3: We now need to AND the four outputs together. This requires 3 AND gates, each built from 2 NANDs, 3 * 2 = 6

That's a total of 30 NAND gates, with a max depth of 2+2+4=8 NANDs for branches with an | at level 1 or 3+1+4=8 NANDs for branches with an & at level 1.

The following Ruby script confirms visually that the above expression is valid.

64.times{|i|
  a=i%2
  b=i/2%2
  c=i/4%2
  d=i/8%2
  e=i/16%2
  f=i/32%2

puts i, ((a|d)|((c|b)&e))&((b|e)|((d|f)&c))&((c|f)|((a|e)&d))&(a|f|b)

puts " ___#{d}___
|\\     /|
| #{e}   #{f} |
|  \\ /  |
#{a}   X   #{c}
|  / \\  |
| /   \\ |
|/__#{b}__\\|


"
}

*/

func connected(a, b, c, d, e, f int) int {
	return ((a | d) | ((c | b) & e)) &
		((b | e) | ((d | f) & c)) &
		((c | f) | ((a | e) & d)) &
		(a | f | b)
}

const WEB = `
 ___%d___
|\     /|
| %d   %d |
|  \ /  |
%d   X   %d
|  / \  |
| /   \ |
|/__%d__\|
`
