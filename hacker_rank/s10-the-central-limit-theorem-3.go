/*

Task
You have a sample of 100 values from a population with mean mu=500 and with standard deviation sd=80.
Compute the interval that covers the middle 95% of the distribution of the sample mean; in other words, compute A and B such that P(A < x < B) = 0.95.
Use the value of z=1.96. Note that z is the z-score.

Input Format

There are five lines of input (shown below):

100
500
80
.95
1.96
The first line contains the sample size. The second and third lines contain the respective mean (mu) and standard deviation (sd).
The fourth line contains the distribution percentage we want to cover (as a decimal), and the fifth line contains the value of z.

If you do not wish to read this information from stdin, you can hard-code it into your program.

Output Format

Print the following two lines of output, rounded to a scale of 2 decimal places (i.e., 1.23 format):

On the first line, print the value of A.
On the second line, print the value of B.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(solve(100, 500, 80, 1.96))
}

func solve(sample, mu, sd, zscore float64) (p0, p1 float64) {
	sq := math.Sqrt(sample)
	p0 = -zscore*(sd/sq) + mu
	p1 = zscore*(sd/sq) + mu
	return
}
