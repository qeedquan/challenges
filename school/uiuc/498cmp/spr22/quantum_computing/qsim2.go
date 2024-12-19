package main

import (
	"fmt"
	"math/cmplx"
)

func main() {
	sim := &Sim{
		Size: 3,
		Wires: []Wire{
			{0, 0},
			{0, 1},
			{0, 3},
		},
		Gates: []Gate{
			&Hadamard{1},
			&Hadamard{2},
			&Phase{2, 0.3},
			&CNOT{2, 1},
			&Hadamard{1},
			&Hadamard{2},
			&CNOT{2, 0},
		},
	}
	sim.Run()
	fmt.Println(sim.Wires)
}

type Sim struct {
	Size  int
	Wires []Wire
	Gates []Gate
}

type Wire struct {
	Amplitude complex128
	Bits      int
}

type Gate interface {
	Apply([]Wire) []Wire
}

type Hadamard struct {
	Wire int
}

type Phase struct {
	Wire  int
	Theta complex128
}

type CNOT struct {
	Control int
	Not     int
}

func (c *Hadamard) Apply(wires []Wire) []Wire {
	return wires
}

func (c *Phase) Apply(wires []Wire) []Wire {
	for i := range wires {
		wire := &wires[i]
		if wire.Bits&(1<<c.Wire) != 0 {
			wire.Amplitude *= cmplx.Exp(1i * c.Theta)
		}
	}
	return wires
}

func (c *CNOT) Apply(wires []Wire) []Wire {
	return wires
}

func (c *Sim) Run() {
	for _, gate := range c.Gates {
		c.Wires = gate.Apply(c.Wires)
		c.Wires = merge(c.Wires)
	}
}

func merge(wires []Wire) []Wire {
	xwires := []Wire{}
	seen := make(map[int]*Wire)
	for _, wire := range wires {
		if seen[wire.Bits] == nil {
			xwires = append(xwires, wire)
			seen[wire.Bits] = &xwires[len(xwires)-1]
		} else {
			seen[wire.Bits].Amplitude += wire.Amplitude
		}
	}
	return xwires
}
