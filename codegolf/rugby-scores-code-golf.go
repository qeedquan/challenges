/*

The Rugby World Cup starts in a few hours!

Write a program or function which, given a rugby team score as input, outputs all possible ways the score could have been attained in a Rugby game.

Ways to score in Rugby
Penalty kick/Drop kick: Both penalty kicks and a drop kicks are worth 3 points (We regroup them in this challenge to reduce the number of possibilities).
Try: A try is worth 5 points.
Conversion: A conversion is worth 2 points. It can only occur if a try occurs too (i.e. there can never be more conversions than trys in a game).
Input
Input is a positive integer, which corresponds to the total score of one team at the end of the game. You may assume that the score is valid, i.e. it can be attained using at least one combination of ways to score described above.

Ouput
The output for one possible way of attaining the score must look like this:

2K,1T,1C
(the numbers can obviously change). the number before K is the number of penalty kicks and/or drop kicks, the number before T is the number of Trys, and the number before C is the number of conversions.

Since you have to output all possible ways the score could have been attained, you may output them either inside a list, or separate them with line breaks (which is what I'll use in the examples below).

Test cases
Input: 9
Output:

3K,0T,0C
There are no other possibilites (For example, 0K,1T,2C would give 9 points but a conversion cannot happen without a corresponding try).

Input: 12
Output:

4K,0T,0C
0K,2T,1C
Input: 19
Output:

0K,3T,2C
4K,1T,1C
3K,2T,0C
Input: 42
Output:

14K,0T,0C
10K,2T,1C
9K,3T,0C
7K,3T,3C
6K,4T,2C
5K,5T,1C
4K,6T,0C
3K,5T,4C
2K,6T,3C
1K,7T,2C
0K,8T,1C
0K,6T,6C

Scoring
This is code-golf, so the shortest code in bytes wins.

*/

package main

import (
	"fmt"
)

func main() {
	test(9)
	test(12)
	test(19)
	test(42)
}

func test(n int) {
	fmt.Printf("n=%d\n", n)
	for _, s := range solve(n) {
		fmt.Println(s)
	}
	fmt.Println()
}

/*

@xnor

Generates all possible triples of values by converting a value k from 0 to n^3-1 to base n.
Filters for those with the right sum.
Try+conversion is considered a separate 7-point play, and the number of tries includes those too.

*/

func solve(n int) []string {
	r := []string{}
	for k := range n * n * n {
		if (k%n*7)+(k/n%n*5)+(k/n/n*3) == n {
			r = append(r, fmt.Sprintf("%dK,%dT,%dC", k/n/n, (k%n)+(k/n%n), k%n))
		}
	}
	return r
}
