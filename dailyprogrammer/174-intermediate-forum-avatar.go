/*

Description
You run a popular programming forum, Programming Daily, where programming challenges are posted and users are free to show off their solutions.
Three of your most prolific users happen to have very similar handles: Sarlik, Sarlek, and Sarlak.
Following a discussion between these three users can be incredibly confusing and everyone mixes them up.

The community decides that the best solution is to allow users to provide square avatars to identify themselves.
Plus the folks over at the competing r/dailyprogrammer forum don't have this feature, so perhaps you can use this to woo over some of their userbase.
However, Sarlik, Sarlek, and Sarlak are totally old school.
They each browse the forum through an old text-only terminal with a terminal browser (lynx, links).
They don't care about avatars, so they never upload any.

After sleeping on the problem you get a bright idea: you'll write a little program to procedurally generate an avatar for them, and any other stubborn users.
To keep the database as simple as possible, you decide to generate these on the fly.
That is, given a particular username, you should always generate the same avatar image.

Formal Input Description
Your forum's usernames follow the same rules as reddit's usernames (e.g. no spaces, etc.). Your program will receive a single reddit-style username as input.

Formal Output Description
Your program outputs an avatar, preferably in color, with a unique pattern for that username. The output must always be the same for that username. You could just generate a totally random block of data, but you should try to make it interesting while still being reasonably unique.

Sample Inputs
Sarlik Sarlek Sarlak

Sample Outputs
http://i.imgur.com/9KpGEwO.png
http://i.imgur.com/IR8zxaI.png
http://i.imgur.com/xf6h0Br.png
Challenge Input
Show us the avatar for your own reddit username.

Note
Thanks to u/skeeto for submitting the idea, which was conceived from here: https://github.com/download13/blockies

Remember to submit your own challenges over at r/dailyprogrammer_ideas

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

func main() {
	var (
		seed  = uint32(0xdeadbeef)
		size  = 20
		scale = 15
	)
	flag.IntVar(&size, "size", size, "specify size")
	flag.IntVar(&scale, "scale", scale, "specify scale")
	flag.Parse()
	if flag.NArg() >= 1 {
		seed = hash([]byte(flag.Arg(0)))
	}
	paint(bufio.NewWriter(os.Stdout), size, scale, seed)
}

/*

@skeeto

It uses the nearly same algorithm as the Blockies project that inspired this challenge.
It randomly picks a color, but from RGB rather than HSL because the conversion is more complicated than generating the avatar itself.
Then it fills the left-hand side randomly and mirrors it to the right-hand side, so it's symmetrical like a face. Output is Netpbm.

The most fascinating part for me was actually the PRNG (rng()).
It's a floating point PRNG that uses the least significant bits of sin().
The state is just incremented by one between outputs, which means it's seekable.
The output of this PRNG is surprisingly good, too.

*/

func paint(stream *bufio.Writer, size, scale int, seed uint32) {
	r := rng(&seed) * 256
	g := rng(&seed) * 256
	b := rng(&seed) * 256
	row := make([]byte, size)

	fmt.Fprintf(stream, "P6\n%d %d\n%d\n", size*scale, size*scale, 255)
	for range size {
		for x := range (size-1)/2 + 1 {
			row[x], row[size-x-1] = 0, 0
			if rng(&seed) > 0.5 {
				row[x], row[size-x-1] = 1, 1
			}
		}
		for range scale {
			for x := range size * scale {
				pixel := row[x/scale]
				if pixel != 0 {
					stream.Write([]byte{byte(r), byte(g), byte(b)})
				} else {
					stream.Write([]byte{0, 0, 0})
				}
			}
		}
	}
	stream.Flush()
}

func hash(data []byte) uint32 {
	seed := uint32(0)
	for i := 0; i+1 < len(data); i += 2 {
		seed ^= uint32(binary.BigEndian.Uint16(data[i:]))
	}
	return seed
}

func rng(state *uint32) float64 {
	value := (math.Sin(float64(*state)) + 1.0) * 10000
	*state += 1
	return value - math.Floor(value)
}
