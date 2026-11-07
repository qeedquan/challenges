/*

Output this binary sequence of length 1160:

-++-+--++-++-+--+--++-+--+--++-+--++-++-+-++--++-+---+-++-+--+--++++--+--++-+--++-++----++-++-+-++--++-+-+---++-+--++-++-+--++-+--+---+-++-+--++-++-+--+--++-++-+--++-+--+++-+-+----+++-+--+--+++---++-++-+--+--+++--+-+-+--+-+++-++-+--+--++-+--++-++-+--+--++--+++---+++-+---++-+--++--+-+--+-+++-+--++-++-+--++-+--+--++-+--++--+-++-+-+--+-+-++-+--++-+--+--++-+-+-++-+-+-++---+-+--++++--+---++-+-++-+--++-+--+--++-+--++++--+---+-++++--+--++-++-+--++-+--+--++-+--++-++-+--++-+--+--++-++-+----+++-+--++--+++---+-++-+--+-++---+-++-++-+--+--++--++++-+--+--+--++++--+--+++---++-++-+--++--+-+--+--++-++-+--+--+-+++-++-+--+--++--+-++-++-+--+--+--++-++-+--+++---++-+--++-++---+++---++-++----+++--+-++-+--+--++-+--++-++-+-++--++--++----+++-++--++----++-+++--++---+++----+-+-++-++-++-+-+----+++--++-+--++-++-+--+--+--++-+--++-++-+--++--+-+--+-+-+-++++---+-+-++--+--+-+-+-++-+-+++--+-+--+--+-+++--+-+++---++-+--+--++-++--++---++-+-++--++-+---+-++-+--+-++--++-+--++-+--+-+++-+--++--+-+-+++--+-+--++-++-+--+--+-++---+-++-+-++--++-+--+++-+----++--+-++-+-++--++-+--++-+-++--++-+---+-++-+--+++----+-+-++--++-+--++-++-++-+--+--+--++++---++---+-+-++-+-+++--+-++--+-+--+-+-++---+++-++
The sequence

This finite sequence is tightly structured in a way that I hope lends to unique methods for compression. It arises from the Erdős discrepancy problem, which was featured in a previous challenge.

Treating the terms as +1 and -1, this is a maximal-length sequence of discrepancy 2, which means that:

For every positive step size d, if you take every d'th term (starting with the dth term), the running sum of the resulting sequence remains between -2 and 2 inclusive.

If you think of each + to mean a step right and - to mean a step left, this means that the walk of every dth instruction never travels more than 2 steps away from the start position.

For example, for d=3, taking every 3rd term gives the sequence +-++--+--+-..., whose running sums are [1,0,1,2,1,0,1,0,-1,0,1,...], which never hit -3 or 3.

-++-+--++-++-+--+--++-+--+--++-+--+...
  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^  ^
  +  -  +  +  -  -  +  -  -  +  -
   1  0  1  2  1  0  1  0 -1  0  -1  ...
This sequence was found in 2014 via a computer search. See this paper, where the sequence is reproduced in Appendix B. The search proves that 1160 is the maximum length of a discrepancy-2 sequence, though there is more than one sequence of that length. The Erdős discrepancy problem, proven in 2015, says that any such sequence must have finite length for any maximum discrepancy c in place of 2.

Time requirement

Your code should finish within 5 seconds. This is to limit brute-forcing.

Output format

You can use any two fixed distinct characters or values for + and - in any list-like or string-like format. The format should be one where the 1160 bit-values can be directly read off, not for example encoded as a number via its binary representation or a string via character values. For string output, a trailing newline is allowed.

*/

package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	assert(uncompress() == "-++-+--++-++-+--+--++-+--+--++-+--++-++-+-++--++-+---+-++-+--+--++++--+--++-+--++-++----++-++-+-++--++-+-+---++-+--++-++-+--++-+--+---+-++-+--++-++-+--+--++-++-+--++-+--+++-+-+----+++-+--+--+++---++-++-+--+--+++--+-+-+--+-+++-++-+--+--++-+--++-++-+--+--++--+++---+++-+---++-+--++--+-+--+-+++-+--++-++-+--++-+--+--++-+--++--+-++-+-+--+-+-++-+--++-+--+--++-+-+-++-+-+-++---+-+--++++--+---++-+-++-+--++-+--+--++-+--++++--+---+-++++--+--++-++-+--++-+--+--++-+--++-++-+--++-+--+--++-++-+----+++-+--++--+++---+-++-+--+-++---+-++-++-+--+--++--++++-+--+--+--++++--+--+++---++-++-+--++--+-+--+--++-++-+--+--+-+++-++-+--+--++--+-++-++-+--+--+--++-++-+--+++---++-+--++-++---+++---++-++----+++--+-++-+--+--++-+--++-++-+-++--++--++----+++-++--++----++-+++--++---+++----+-+-++-++-++-+-+----+++--++-+--++-++-+--+--+--++-+--++-++-+--++--+-+--+-+-+-++++---+-+-++--+--+-+-+-++-+-+++--+-+--+--+-+++--+-+++---++-+--+--++-++--++---++-+-++--++-+---+-++-+--+-++--++-+--++-+--+-+++-+--++--+-+-+++--+-+--++-++-+--+--+-++---+-++-+-++--++-+--+++-+----++--+-++-+-++--++-+--++-+-++--++-+---+-++-+--+++----+-+-++--++-+--++-++-++-+--+--+--++++---++---+-+-++-+-+++--+-++--+-+--+-+-++---+++-++")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func uncompress() string {
	const enc = "28x0lphxjx8ze4uuhtdzo0oebr25amtmuxm62cbit0ibdwjm2sf50clh2ejq0a73ndseo5tove8uqca6nf66bo4abbkg867woh2b435at0o3pddvqmsqp29b6as5bd4eo28xgwkkj607gp66icba1q4n9fc13dltp45j340mpzbc56wsrbb3oejnczsbzfgh82xdi8aku8m4wlmwuxkgy4yaew7pu4p1g"

	x := new(big.Int)
	x.SetString(enc, 36)

	s := fmt.Sprintf("%b", x)
	s = strings.Replace(s, "1", "-", -1)
	s = strings.Replace(s, "0", "+", -1)
	return s
}
