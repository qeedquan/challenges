/*

You're involved in the creation of a game.
In this game, a certain function is to be used to generate colors dynamically, such that, say, different temperatures will produce different colors.
This function can be replaced during the gameplay, or even chosen by the player.
The exact choices aren't finalized, but you know that a simple linear gradient will be used.

Your task is to implement a higher-order function that takes two colors in RGB format,
and returns another function representing a linear gradient which interpolates between
them using an integer (lying in range [0; 100]) provided as an input and returns this interpolated color.
The resulting RGB components must be rounded down.

*/

package main

import "fmt"

type interpfn func(int) [3]int

func main() {
	interpolate := gradient([3]int{100, 100, 100}, [3]int{210, 230, 200})
	for p := range 101 {
		fmt.Println(interpolate(p))
	}
}

func gradient(A, B [3]int) interpfn {
	return func(p int) [3]int {
		return [3]int{
			(A[0]*(100-p) + B[0]*p) / 100,
			(A[1]*(100-p) + B[1]*p) / 100,
			(A[2]*(100-p) + B[2]*p) / 100,
		}
	}
}
