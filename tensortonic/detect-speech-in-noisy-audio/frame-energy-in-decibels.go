/*

A recording is a long list of numbers called samples. Each sample is the position of the microphone at one instant, between -1 and 1, and a sample rate of 8000 means 8000 samples per second. To decide where someone is speaking, a detector first cuts the recording into short overlapping pieces called frames and measures how loud each frame is.

Frame i holds the frame_length samples that start at sample i times hop_length. Keep only frames that fit completely inside the waveform and drop the leftover samples at the end. The energy of a frame is the mean of its squared samples, and you report it in decibels (dB), a log scale where every factor of 10 in energy adds 10 dB.

E[i] = 10*log10(1/L * Sum[n=0, L-1] x[i*H + n]^2 + 10^-10)

Here x is the waveform, L is frame_length, H is hop_length, and the small constant 10 to the power -10 keeps a silent frame at -100 dB instead of minus infinity.

Return a float32 tensor of shape (num_frames,) holding one energy in dB per full frame, or an empty tensor of shape (0,) when the waveform is shorter than one frame.

Examples
Input: waveform = [0.0, 0.1, 0.1, 0.0, 0.5, 0.5, 0.5, 0.5], frame_length = 4, hop_length = 2

Output: [-23.0103, -8.9449, -6.0206]

Explanation: Frame 0 is [0.0, 0.1, 0.1, 0.0], whose squares average 0.005, which is 10 times log10 of 0.005, about -23.0103 dB. Frame 1 starts 2 samples later at [0.1, 0.0, 0.5, 0.5] and frame 2 is [0.5, 0.5, 0.5, 0.5], whose mean square 0.25 is -6.0206 dB.

Input: waveform = [0.0, 0.0, 0.0, 0.0, 0.0, 1.0], frame_length = 3, hop_length = 3

Output: [-100.0, -4.7712]

Input: waveform = [0.2, -0.2, 0.2, -0.2, 0.1, -0.1, 0.4], frame_length = 2, hop_length = 2

Output: [-13.9794, -13.9794, -20.0]

Hint 1
The number of full frames is 1 plus (number of samples minus frame_length) divided by hop_length, rounded down.

Hint 2
waveform.unfold(0, frame_length, hop_length) gives a (num_frames, frame_length) tensor.

Hint 3
Decibels of a power p are 10 times log10 of p.

Requirements
Frame i starts at sample i times hop_length and holds exactly frame_length samples.
Keep only full frames; drop leftover samples at the end.
Use the mean of the squared samples, not the sum.
Add 1e-10 before taking log10.
Return an empty tensor of shape (0,) when no full frame fits.
Constraints
1 to 1,000 samples, each between -1 and 1.
frame_length and hop_length between 1 and 400.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(frame_energy_db(
		[]float64{0.0, 0.1, 0.1, 0.0, 0.5, 0.5, 0.5, 0.5},
		4, 2,
	))

	fmt.Println(frame_energy_db(
		[]float64{0.0, 0.0, 0.0, 0.0, 0.0, 1.0},
		3, 3,
	))

	fmt.Println(frame_energy_db(
		[]float64{0.2, -0.2, 0.2, -0.2, 0.1, -0.1, 0.4},
		2, 2,
	))
}

func frame_energy_db(waveform []float64, frame_length, hop_length int) []float64 {
	full_frames := 1 + (len(waveform)-frame_length)/hop_length
	energies := make([]float64, full_frames)
	frame_offset := 0
	for i := range energies {
		energy := 0.0
		for L := range frame_length {
			energy += sqr(waveform[frame_offset+L])
		}
		energy /= float64(frame_length)
		energy += 1e-10
		energy = 10 * math.Log10(energy)
		energies[i] = energy
		frame_offset += hop_length
	}
	return energies
}

func sqr(x float64) float64 {
	return x * x
}
