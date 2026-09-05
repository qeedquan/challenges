/*

Description
Let's try something different this week. Our output is going to be sound instead of text/graphics

Formal Inputs & Outputs
No real input for this challenge. But this is research/getting familiar with the sound framework of your language, for the next 2 challenges.

You create an applition that produces Do–Re–Mi–Fa–Sol–La–Si of the Solfège.

Notes/Hints
Here you find some more info about music notes, especialy the part about frequencies.

Bonus
Be able to output [Chords](https://en.wikipedia.org/wiki/Chord_(music)

Bonus 2 by u/dgendreau
Look up the file format spec for WAVE files. Do the same assignment by writing a wave file. Use a lookup table to make saw square or triangle waves.

Finally
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

*/

package main

import (
	"bufio"
	"encoding/binary"
	"flag"
	"fmt"
	"math"
	"os"
)

// ported from @skeeto solution

const (
	C = 261.63
	D = 293.66
	E = 329.63
	F = 349.23
	G = 392.00
	A = 440.00
	B = 493.88
)

type voicefn func(float64) float64

var flags struct {
	samplerate int
	stretch    float64
}

func main() {
	parseflags()
	song := [][]float64{
		{
			C * 2, D * 2, E * 2, F * 2, G * 2, A * 2, B * 2,
		},
		{
			C * 1, D * 1, E * 1, F * 1, G * 1, A * 1, B * 1,
		},
	}
	play(flags.samplerate, flags.stretch, song, []voicefn{square, sawtooth})
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options]")
	flag.PrintDefaults()
	os.Exit(2)
}

func parseflags() {
	flag.Usage = usage
	flag.IntVar(&flags.samplerate, "samplerate", 44100, "specify sample rate")
	flag.Float64Var(&flags.stretch, "stretch", 1, "specify stretch factor")
	flag.Parse()
}

func play(samplerate int, stretch float64, notes [][]float64, voices []voicefn) {
	stream := bufio.NewWriter(os.Stdout)
	defer stream.Flush()

	binary.Write(stream, binary.BigEndian, []uint32{
		0x2e736e64,         // magic number
		24,                 // header size
		0xffffffff,         // unspecified duration
		3,                  // 16-bit linear PCM
		uint32(samplerate), // sample rate
		1,                  // channels
	})

	scale := 2 * math.Pi / float64(samplerate)
	for n := range notes[0] {
		for t := range int(float64(samplerate) * stretch) {
			sample := 0.0
			for v := range voices {
				if notes[v][n] != 0 {
					sample += voices[v](notes[v][n]*float64(t)*scale) / float64(len(voices))
				}
			}
			binary.Write(stream, binary.BigEndian, uint16(sample*0x7fff))
		}
	}
}

func sawtooth(t float64) float64 {
	x := t / (2 * math.Pi)
	return x - math.Floor(x)
}

func square(t float64) float64 {
	x := math.Mod(t, 2*math.Pi)
	if x <= math.Pi {
		return 1
	}
	return 0
}
