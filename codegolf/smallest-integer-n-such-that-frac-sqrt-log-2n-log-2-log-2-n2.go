/*

Write code that outputs the smallest integer n>5 such that sqrt(log2(n)) / sqrt(log2(log2(n))^2) > 1

Your code may have at most one digit in its source code. You can use your chosen digit more than once however.

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	fmt.Println(solve())
}

/*

@ovs

According to WolframAlpha, the equation sqrt(log2(x)) = log2(log2(x))^2 has three solutions.
Two real numbers around 1 and 5 and a very large integer solution. So what is that large integer solution?

simple transformations on both sides yield

log2(x)^(1/4) = log2(log2(x))
2^(2^(log2(x)^(1/4))) = x

Now, lets substitute y=log2(x)^(1/4).
Note that y has to be an integer as well. This yields two equations:

2^(2^y) = x, y = log2(x)^(1/4)
2^(2^y) = x, y^4 = log2(x)
2^(2^y) = x, 2^(y^4) = x
2^(2^y) = 2^(y^4)
2^y = y^4

The only integer solution to this is y=16, leaving us with x=2^(16^4) = 2^(2^(2^(2^2))).
The first integer that satisfies the inequality is x + 1.

*/

func solve() *big.Int {
	x := big.NewInt(1)
	x.Lsh(x, 65536)
	x.Add(x, big.NewInt(1))
	return x
}
