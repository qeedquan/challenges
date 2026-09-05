/*

A Geiger counter is a device that is used to detect radiation.

We will be making a Geiger counter program.

As we all know, when radiation hits a computer program it removes exactly 1 byte at random. So a Geiger counter program is a program that itself does nothing, but when any byte is removed the modified program prints beep, to indicate the presence of radiation.

Answers will be scored in bytes with fewer bytes being better. Answers must be at least 1 byte.

Your program may print beep with trailing a newline or print a single newline for empty output, so long as it does so consistently. Your program may also use a different case for beep such as BEEP, bEEP, or Beep so long as it does so consistently.

*/

package main

import (
	"crypto/sha512"
	"fmt"
	"math/rand"
	"time"
)

func main() {
	d := newdecay(4096, 1e-6)
	monitor(d)
}

func monitor(m Mach) {
	sig := sha512.Sum512(m.Memory())
	for {
		m.Update()
		newsig := sha512.Sum512(m.Memory())
		if sig != newsig {
			fmt.Println("Beep:", time.Now())
			sig = newsig
		}
	}
}

type Mach interface {
	Memory() []byte
	Update()
}

type Decay struct {
	mem  []byte
	prob float64
}

func newdecay(size int, prob float64) *Decay {
	return &Decay{
		mem:  make([]byte, size),
		prob: prob,
	}
}

func (d *Decay) Memory() []byte {
	return d.mem
}

func (d *Decay) Update() {
	if d.prob < rand.Float64() {
		return
	}
	for i := range d.mem {
		d.mem[i] ^= uint8(rand.Intn(255))
	}
}
