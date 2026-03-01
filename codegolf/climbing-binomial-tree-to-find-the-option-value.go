/*

Background:
In finance, the binomial options pricing model (BOPM) is the simplest technique used for option pricing. The mathematics behind the model is relatively easy to understand and (at least in their basic form) it is not difficult to implement. This model was first proposed by Cox, Ross, and Rubinstein in 1979. Quoting Wikipedia:

The binomial pricing model traces the evolution of the option's key underlying variables in discrete-time. This is done by means of a binomial lattice (tree), for a number of time steps between the valuation and expiration dates. Each node in the lattice represents a possible price of the underlying at a given point in time.

Valuation is performed iteratively, starting at each of the final nodes (those that may be reached at the time of expiration), and then working backwards through the tree towards the first node (valuation date). The value computed at each stage is the value of the option at that point in time.

For this challenge's sake, we will create a simple model to predict potential future prices of the option(s) by creating a lattice or a tree as shown below (a picture is worth a thousand words):

https://i.sstatic.net/YdCGY.jpg

where S is the option price today, p is the probability of a price rise, and t is the period of time or number of steps.

Challenge:
The challenge is to write either a program or a function which take S, p (in percent), and t as the inputs and give the binomial tree as the output. The output of the program or the function must follow the format above, but the boxes and the arrow lines are optional. For example, if the program take inputs S = 100, p = 10%, and t = 3, then its output may be in the following simple form:

                        133.1
                121
        110             108.9
100              99
         90              89.1
                 81
                         72.9
General rules:
This is code-golf, so the shortest answer in bytes wins the challenge.
Don't let esolangs discourage you from posting an answer with regular languages. Enjoy this challenge by providing an answer as short as possible with your programming language. If you post a clever answer and a clear explanation, your answer will be appreciated (hence the upvotes) regardless of the programming language you use.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/ method with the proper parameters, full programs, etc. The choice is yours.
Using a binomial tree built-in is forbidden.
If possible, your program can properly handle a large number of steps. If not, that will just be fine.

References:
Binomial options pricing model
Binomial tree option calculator

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	tree(100, 0.1, 3)
	tree(10, 0.20, 3)
	tree(100, 0.01, 7)
}

// ported from @Jonathan Allan solution
func tree(s, p float64, t int) {
	fmt.Printf("S=%.2f p=%.2f t=%d\n", s, p, t)
	for r := range 2*t + 1 {
		for c := range t + 1 {
			b := " "
			if (t-c <= r && r <= t+c) && ((r%2)^(c+^t%2)%2) != 0 {
				s0 := math.Pow(1+p, float64(c-(r+c-t)/2))
				s1 := math.Pow(1-p, float64((r+c-t)/2))
				b = fmt.Sprintf("%.2f", s*s0*s1)
			}
			fmt.Printf("%-12s", b)
		}
		fmt.Println()
	}
	fmt.Println()
}
