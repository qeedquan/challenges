/*

Simulator for a subset of quantum logic gates

In a classical computer, each wire represents a bit (0 or 1).
In a quantum computer, each wire can be in superposition with each other.
With N wires holding a qubit in each wire, we need 2^N states of complex numbers (amplitudes) to represent the state of the system.

Example:
3 bit quantum computer will need 2^3 = 8 complex number for the state

Unlike a classical computer where the gates apply to 1 or 2 wire (bits) at a time without touching any other wire (bits),
Quantum gates apply to all wires at the same time.

The simulation algorithm:
for all wires {
	for all gates {
		apply gate to wire
	}
}

Each gate will look at the binary representation of the wire and work on the bits represented by that wire

https://en.wikipedia.org/wiki/Quantum_logic_gate
The following gates are commonly used in practice:
Pauli (XYZ)
Hadamard (H)
Phase (S, P)
PI/8 (T)
Controlled NOT/CNOT/CX
Controlled Z
SWAP
Fredkin (CSWAP)
Toffoli (CCNOT/CCX/TOFF)

Some of the gates are universal so we can use them to implement other gates (like using NAND to implement AND/OR/etc)

At the end of the simulation, the system will contain 2^N output states for N wires, a MEASURE operator will collapse it and pick one at random.
The probability of a state being picked is the absolute value of the square of the wire.
The sum of all absolute square values of the amplitude should equal 1 (satisfying probability rules).
Simulators don't have to obey the proability sum restriction though, to make it easier to test stuff, so we could initialize it with any complex value.

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"math/cmplx"
	"os"
	"sort"
	"strings"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	sim := &Sim{}
	err := sim.LoadCircuit(flag.Arg(0))
	check(err)

	fmt.Println(sim.Wires)
	sim.Step()
	fmt.Println(sim.Wires)
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] file.circuit")
	flag.PrintDefaults()
	os.Exit(2)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
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
		c.Wires = c.merge(newwires)
	}
}

func (c *Sim) merge(wires []Wire) []Wire {
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

func (c *Sim) LoadCircuit(name string) error {
	fd, err := os.Open(name)
	if err != nil {
		return err
	}
	defer fd.Close()

	var (
		size  int
		gates []Gate
		sval  string
		ival  [2]int
		fval  [1]float64
	)

	scan := bufio.NewScanner(fd)
	scan.Scan()
	fmt.Sscanf(scan.Text(), "%d", &size)
	for scan.Scan() {
		line := scan.Text()
		line = strings.TrimSpace(line)
		switch {
		case strings.HasPrefix(line, "#"):
			continue
		case strings.HasPrefix(line, "INITSTATE"):
			fields := strings.Split(line, " ")
			if len(fields) != 3 {
				continue
			}
			if fields[1] == "FILE" {
				c.LoadState(fields[2])
			}
		case strings.HasPrefix(line, "CNOT"):
			fmt.Sscanf(line, "%s %d %d", &sval, &ival[0], &ival[1])
			gates = append(gates, &CNOT{ival[0], ival[1]})
		case strings.HasPrefix(line, "H"):
			fmt.Sscanf(line, "%s %d", &sval, &ival[0])
			gates = append(gates, &Hadamard{ival[0]})
		case strings.HasPrefix(line, "P"):
			fmt.Sscanf(line, "%s %d %f", &sval, &ival[0], &fval[0])
			gates = append(gates, &Phase{ival[0], complex(fval[0], 0)})
		}
	}

	c.Size = size
	c.Gates = gates
	return nil
}

func (c *Sim) LoadState(name string) error {
	fd, err := os.Open(name)
	if err != nil {
		return err
	}
	defer fd.Close()

	wires := []Wire{}
	scan := bufio.NewScanner(fd)
	bits := 0
	for scan.Scan() {
		line := scan.Text()
		line = strings.TrimSpace(line)
		if strings.HasPrefix(line, "#") {
			continue
		}

		var real, imag float64
		fmt.Sscanf(line, "%f %f", &real, &imag)
		wires = append(wires, Wire{
			Amplitude: complex(real, imag),
			Bits:      bits,
		})
		bits++
	}

	c.Wires = wires
	return nil
}
