package main

import (
	"fmt"
	"math/cmplx"
	"sort"
)

func main() {
	sim := &Sim{
		Size: 3,
		Wires: []Wire{
			{1, 0},
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
	fmt.Println(sim.Wires)
	sim.Step()
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
	Apply(Wire) []Wire
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

func (c *Hadamard) Apply(wire Wire) []Wire {
	wire0, wire1 := wire, wire
	wire0.Amplitude *= 1 / cmplx.Sqrt(2)
	if wire.Bits&(1<<c.Wire) == 0 {
		wire1.Amplitude *= 1 / cmplx.Sqrt(2)
	} else {
		wire1.Amplitude *= -1 / cmplx.Sqrt(2)
	}
	wire0.Bits &^= (1 << c.Wire)
	wire1.Bits |= (1 << c.Wire)
	return []Wire{wire0, wire1}
}

func (c *Phase) Apply(wire Wire) []Wire {
	if wire.Bits&(1<<c.Wire) != 0 {
		wire.Amplitude *= cmplx.Exp(1i * c.Theta)
	}
	return []Wire{wire}
}

func (c *CNOT) Apply(wire Wire) []Wire {
	if wire.Bits&(1<<c.Control) != 0 {
		wire.Bits ^= (1 << c.Not)
	}
	return []Wire{wire}
}

func (c *Sim) Step() {
	for _, gate := range c.Gates {
		newwires := []Wire{}
		for _, wire := range c.Wires {
			newwires = append(newwires, gate.Apply(wire)...)
		}
		c.Wires = merge(newwires)
	}
}

func merge(wires []Wire) []Wire {
	sort.Slice(wires, func(i, j int) bool {
		return wires[i].Bits < wires[j].Bits
	})

	newwires := []Wire{}
	for i, j := 0, 0; i < len(wires); i = j {
		amplitude := 0i
		j = i
		for j < len(wires) && wires[i].Bits == wires[j].Bits {
			amplitude += wires[j].Amplitude
			j++
		}

		newwires = append(newwires, Wire{amplitude, wires[i].Bits})
	}
	return newwires
}
