/*

Once upon a time, there lived a mad programmer. He loved to solve creative problems other than anything. His wife loved him quite a lot but disliked his curiosity for the problems. One day he came from office, his wife gave him a glass of cold lime juice. She was in a romantic mood and waiting for some romantic stuff. But the programmer asked her curiously, "If I give u radius of the top and bottom part of the glass and the height, can you come up with the volume of the glass?" His wife became a bit disappointed but as she is smart she replied with a smile, "You already have drunk some juice, and the glass is not full. If I give you the height of the juice, can you find the volume of the remaining juice in the glass?" Then the programmer kissed his wife and said, "You are the best problem setter in the world!"

Now he set the same problem for you. The radius of the upper part r1 and lower part r2 is given. If height of the glass is h and height of the juice is p what is the volume of the juice in the glass?

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case starts with a line containing four integers r1 r2 h p (1 ≤ r2 < r1 ≤ 100, 1 ≤ p ≤ h ≤ 100).

Output
For each case, print the case number and the volume of the juice in the glass. Errors less than 10^-6 will be ignored.

Sample
Input	Output
2
5 2 3 2
5 2 3 3

Case 1: 58.643062867
Case 2: 122.52211349

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(5, 2, 3, 2))
	fmt.Println(solve(5, 2, 3, 3))
}

func solve(r1, r2, h, p float64) float64 {
	r3 := p/h*(r1-r2) + r2
	return (math.Pi / 3) * p * (r3*r3 + r2*r2 + r3*r2)
}
