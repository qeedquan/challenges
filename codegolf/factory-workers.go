/*

Challenge
Factory workers are usually very hard-working. However, their work is now being commonly replaced with machines.

You have to write a program that takes a number as input. It will print out a factory of 10 workers 10 times. Every time, each worker has a 1/input chance of being 'fired' and replaced by a machine.

Input
An integer, coming from STDIN or a function call.

Output
10 cases of the factory, each one with usually more workers fired.

Output format - how to print a factory
A factory looks like this:

|0000000000| or |0000011001|

A pipe represents the walls, a 0 represents a worker, and a 1 represents a machine, so the first print of the factory will always be |0000000000|.

Example
Input: 10
Output:
|0000000000| //always start off with this
|0000000010| //a 1/10 chance means that this worker lost his job
|0000010010|
|0010010010|
|1010010010|
|1010110010|
|1010110011|
|1010111011|
|1010111111|
|1110111111|

Input: 5
Output:
|0000000000| //always start here
|0000001001| //a 1/5 chance means that 2 workers got fired
|1000101001|
|1000101111|
|1101101111|
|1111111111| //after achieving all machinery, the machines continue to be printed
|1111111111|
|1111111111|
|1111111111|
|1111111111|

NOTE
The number of workers fired is RANDOM - in my examples for 1/5 chance there would always be 2 workers fired but your program has to do this randomly - sometimes 1 and sometimes 3 - they just have 1/5 chance of being fired.

*/

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	sim(10)
	sim(5)
}

func sim(n int) {
	fmt.Printf("n=%d\n", n)
	s := []byte("|0000000000|")
	for i := 0; i < 11; i++ {
		fmt.Printf("%s\n", s)
		for j := 1; j < 11; j++ {
			if rand.Intn(n) == 0 {
				s[j] = '1'
			}
		}
	}
	fmt.Println()
}
