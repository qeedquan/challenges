/*

The simplest speech detector calls a frame speech when it is loud. Words do not stay loud, though. The end of a word fades out and a short pause sits inside many words, so a plain threshold chops speech into pieces. Classic detectors such as ITU-T G.729 Annex B, a 1996 telephone speech standard, fix this with a hangover, which keeps the decision at speech for a few frames after the sound drops.

A frame t is loud when energy_db at t is strictly greater than threshold_db. The decision for frame t is True when frame t is loud or when one of the hangover frames just before it, frames t minus hangover to t minus 1, is loud.

d[t] = max[0<=j<=h, j<=t] e[t-j] > theta

Here e is energy_db, theta is threshold_db, h is hangover, and the brackets give True when the condition holds. The hangover only extends speech forward in time. It never switches speech on before the first loud frame.

Return a bool tensor with the same length as energy_db.

Examples
Input: energy_db = [-50.0, -30.0, -50.0, -50.0, -50.0, -30.0, -50.0], threshold_db = -40.0, hangover = 2

Output: [False, True, True, True, False, True, True]

Explanation: Frames 1 and 5 are loud. With a hangover of 2, frames 2 and 3 after frame 1 stay speech, frame 4 is 3 frames after the last loud frame and drops to False, and frame 6 follows frame 5.

Input: energy_db = [-50.0, -30.0, -50.0, -50.0, -50.0, -30.0, -50.0], threshold_db = -40.0, hangover = 0

Output: [False, True, False, False, False, True, False]

Input: energy_db = [-40.0, -39.9, -60.0, -40.0, -60.0], threshold_db = -40.0, hangover = 1

Output: [False, True, True, False, False]

Hint 1
Keep a counter of frames since the last loud frame and reset it to 0 on each loud frame.

Hint 2
A frame is speech when that counter is at most hangover.

Hint 3
Use a strict greater-than comparison with the threshold.

Requirements
Loud means strictly greater than threshold_db; a value equal to it is not loud.
After the last loud frame, the next hangover frames are also True.
A hangover of 0 gives the plain threshold.
Frames before the first loud frame stay False.
Return a torch.bool tensor of the same length.
Constraints
1 to 50 frames, energies between -100 and 0 dB.
hangover between 0 and 20.

*/

package main

import (
	"fmt"
)

func main() {
	fmt.Println(threshold_with_hangover(
		[]float64{-50.0, -30.0, -50.0, -50.0, -50.0, -30.0, -50.0},
		-40, 2,
	))

	fmt.Println(threshold_with_hangover(
		[]float64{-50.0, -30.0, -50.0, -50.0, -50.0, -30.0, -50.0},
		-40, 0,
	))

	fmt.Println(threshold_with_hangover(
		[]float64{-40.0, -39.9, -60.0, -40.0, -60.0},
		-40, 1,
	))
}

func threshold_with_hangover(energy_db []float64, threshold_db float64, hangover int) []bool {
	result := make([]bool, len(energy_db))
	for i := 0; i < len(energy_db); {
		if energy_db[i] > threshold_db {
			j := 0
			for ; j <= hangover && i+j < len(energy_db); j++ {
				result[i+j] = true
			}
			i += j
		} else {
			i += 1
		}
	}
	return result
}
