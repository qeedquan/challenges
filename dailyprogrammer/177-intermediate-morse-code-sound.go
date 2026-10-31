/*

Description
Morse code is an aural method of transmitting text through the use of silence and tones.

Todays challenge will involve translating your standard english text into morse code, and from there, into an audio file.

Example
Step 1: "I like cats" - The phrase entered by you for translating

Step 2: .. / .-.. .. -.- . / -.-. .- - ... - The output of the phrase in step 1

Step 3: cats.wav - An audio file containing each dot(.) and dash(-) as an audible tone

Formal Inputs & Outputs
Input description
On standard console input, you should enter a phrase of your choosing. This will then be parsed into morse code and finally outputted as stated in the output description.

Output description
The program should output a valid audio file (WAV, MP3, OGG, as long as it can play it's fine). In that audio should be an audio translation of your input.

Finally
Thanks to u/13467 for this submission

We're always on the IRC channel on Freenode . Our channel is #reddit-dailyprogrammer

There's usually ~20 or so people on at any given moment, stop by!

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
	"strings"
	"unicode"
)

func main() {
	var (
		frequency float64
		gain      float64
	)

	flag.Float64Var(&frequency, "frequency", 1000, "specify frequency")
	flag.Float64Var(&gain, "gain", 0.6, "specify gain")
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	au := &au{
		output:      bufio.NewWriter(os.Stdout),
		sample_rate: 8000,
		gain:        gain,
		frequency:   frequency,
	}
	defer au.output.Flush()

	message := strings.Join(flag.Args(), " ")
	au.header()
	morse_string(au, message)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: message")
	flag.PrintDefaults()
	os.Exit(2)
}

// ported from @skeeto solution
type au struct {
	output      *bufio.Writer
	sample_rate float64
	gain        float64
	frequency   float64
}

func (au *au) header() {
	header := struct {
		magic    [4]byte
		offset   uint32
		size     uint32
		format   uint32
		rate     uint32
		channels uint32
	}{
		[4]byte{'.', 's', 'n', 'd'},
		24,
		0xffffffff,
		2,
		uint32(au.sample_rate),
		1,
	}

	binary.Write(au.output, binary.BigEndian, &header)
}

func (au *au) beep(seconds, frequency float64) {
	samples := au.sample_rate * seconds
	for i := range uint64(samples) {
		t := float64(i) / au.sample_rate
		value := math.Sin(t * 2 * math.Pi * frequency)
		value *= 128 * au.gain
		au.output.WriteByte(byte(value))
	}
}

func (au *au) silence(seconds float64) {
	samples := au.sample_rate * seconds
	for range uint64(samples) {
		au.output.WriteByte(0)
	}
}

const LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

var CODES = []string{
	".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
	"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
	"..-", "...-", ".--", "-..-", "-.--", "--.", "-----", ".----", "..---",
	"...--", "....-", ".....", "-....", "--...", "---..", "----.",
}

func morse_code(c rune) string {
	i := strings.IndexRune(LETTERS, unicode.ToUpper(c))
	if i < 0 {
		return ""
	}
	return CODES[i]
}

func morse_char(au *au, c rune) {
	code := morse_code(c)
	if code == "" {
		au.silence(0.7)
		return
	}

	for _, c := range code {
		seconds := 0.6
		if c == '.' {
			seconds = 0.2
		}
		au.beep(seconds, au.frequency)
		au.silence(0.2)
	}
}

func morse_string(au *au, message string) {
	for _, c := range message {
		morse_char(au, c)
		au.silence(0.6)
	}
}
