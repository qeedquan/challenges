/*

Description
Mark saw someone doing experiments with blinking LEDs (imagine something like this ) and became fascinated by it. He wants to know more about it. He knows you are good with computers, so he comes to you asking if you can teach him how it works. You agree, but as you don't have any LEDs with you at the moment, you suggest: "Let's build an emulator with which we can see what's happening inside". And that's today's challenge.

1st Part

The 1st part should be easy, even though the description is rather verbose. If you want more challenge try the 2nd part afterwards.

Our system has 8 LEDs, we represent their state with a text output. When all LEDs are off, it is printed as string of eight dots "........". When a led is on, it is printed as "*". LED-0 is on the right side (least significant bit), LED-7 is on the left side. Having LEDs 0 and 1 on and all others off is written as "......**"

On input you get a sequence of lines forming a program. Read all lines of the input (detect EOF, or make the first line contain number of lines that follow, whichever is more convenient for you). Afterwards, print LED states as they are whenever the program performs an out instruction.

Each line is in the following format:

<line>: <whitespace> <instruction> |
        <empty>

<instruction> : ld a,<num> |
                out (0),a
<whitespace> is one or more of characters " " or "\t". <num> is a number between 0 and 255.

Instruction ld a,<num> sets internal 8-bit register A to the given number. Instruction out (0),a updates the LEDs according to the current number in A. The LED-0's state corresponds to bit 0 of number in A, when that number is represented in binary. For example, when A = 5, the LED state after out instruction is ".....*.*".

You should output the LED states after each out instruction.

Challenge input 1:

  ld a,14
  out (0),a
  ld a,12
  out (0),a
  ld a,8
  out (0),a

  out (0),a
  ld a,12
  out (0),a
  ld a,14
  out (0),a
Expected output:

....***.
....**..
....*...
....*...
....**..
....***.
2nd Part

We will extend our programming language, so that we can do more updates without writing out instruction for each of them. We will have loops.

Each line has the following format:

<line>: <whitespace> <instruction> |
        <label>                    |
        <empty>

<instruction> : ld a,<num> |
                ld b,<num> |
                out (0),a  |
                rlca       |
                rrca       |
                djnz <labelref>
<label> is a sequence of characters a-z A-Z _ terminated with one character ":". <labelref> is a sequence of characters a-z A-Z _ (it corresponds to some label minus the trailing ":").

Instruction ld b,<num> sets a number to register B. Instruction rlca rotates bits in register A one position to the left, in circle (i.e. bit 0 goes to bit 1, bit 1 to bit 2, and bit 7 to bit 0). Instruction rrca rotates bits in register A one position to the right, in circle. Instruction djnz <labelref> (decrement and jump if not zero) subtracts one from the value of register B and if the new value of register B is not zero then the processing of instructions continues at the line containg label corresponding to the <labelref>. You can assume that in the input text <label> is always given before the corresponding <labelref> (i.e. jumps go backwards).

You should output the LED states after each out instruction.

Challenge Input 2:

  ld b,3

triple:
  ld a,126
  out (0),a
  ld a,60
  out (0),a
  ld a,24
  out (0),a
  djnz triple
Challenge Output 2:

.******.
..****..
...**...
.******.
..****..
...**...
.******.
..****..
...**...
Challenge Input 3:

  ld a,1
  ld b,9

loop:
  out (0),a
  rlca
  djnz loop
Challenge Output 3:

.......*
......*.
.....*..
....*...
...*....
..*.....
.*......
*.......
.......*
Challenge Input 4:

  ld a,2
  ld b,9

loop:
  out (0),a
  rrca
  djnz loop
Challenge Output 4:

......*.
.......*
*.......
.*......
..*.....
...*....
....*...
.....*..
......*.
Credit
This challenge was suggested by u/lukz in r/dailyprogrammer_ideas, many thanks! If you have a challenge idea please share it and there's a good chance we'll use it.

*/

package main

import (
	"fmt"
	"strconv"
	"strings"
)

type Inst struct {
	op    int
	nargs int
	reg   int
	val   int
	label string
}

type Mach struct {
	inst []Inst
	reg  [2]int
	pc   int
}

const (
	A = iota
	B
)

const (
	LABEL = iota
	LD
	OUT
	RLCA
	RRCA
	DJNZ
)

func main() {
	test([]string{
		"ld a,14",
		"out (0),a",
		"ld a,12",
		"out (0),a",
		"ld a,8",
		"out (0),a",
		"out (0),a",
		"ld a,12",
		"out (0),a",
		"ld a,14",
		"out (0),a",
	})

	test([]string{
		"ld b,3",
		"triple:",
		"ld a,126",
		"out (0),a",
		"ld a,60",
		"out (0),a",
		"ld a,24",
		"out (0),a",
		"djnz triple",
	})

	test([]string{
		"ld a,1",
		"ld b,9",
		"loop:",
		"out (0),a",
		"rlca",
		"djnz loop",
	})

	test([]string{
		"ld a,2",
		"ld b,9",
		"loop:",
		"out (0),a",
		"rrca",
		"djnz loop",
	})
}

func test(code []string) {
	var mach Mach

	err := mach.Assemble(code)
	if err != nil {
		panic(err)
	}

	mach.Reset()
	mach.Run()
}

func (m *Mach) Assemble(code []string) error {
	itab := map[string]Inst{
		"ld":   {op: LD, nargs: 2},
		"out":  {op: OUT, nargs: 2},
		"rlca": {op: RLCA, nargs: 0},
		"rrca": {op: RRCA, nargs: 0},
		"djnz": {op: DJNZ, nargs: 1},
	}

	for lineno, line := range code {
		line = strings.Replace(line, ",", " ", -1)
		line = strings.Replace(line, "\t", " ", -1)
		line = strings.ToLower(line)
		if line == "" {
			continue
		}

		args := strings.Split(line, " ")
		for i := range args {
			args[i] = strings.TrimSpace(args[i])
		}

		if strings.HasSuffix(args[0], ":") {
			label := strings.TrimSuffix(args[0], ":")
			m.inst = append(m.inst, Inst{op: LABEL, label: label})
			continue
		}

		inst, ok := itab[args[0]]
		if !ok {
			return fmt.Errorf("%d: unknown instruction: %q", lineno+1, args[0])
		}

		if inst.nargs != len(args)-1 {
			return fmt.Errorf("%d: invalid number of arguments", lineno+1)
		}

		switch inst.op {
		case LD:
			switch args[1] {
			case "a":
				inst.reg = A
			case "b":
				inst.reg = B
			default:
				return fmt.Errorf("%d: invalid register: %q", lineno+1, args[1])
			}

			val, err := strconv.ParseInt(args[2], 0, 64)
			if err != nil {
				return fmt.Errorf("%d: invalid value: %q", lineno+1, args[2])
			}
			inst.val = int(val)

		case OUT:
			if args[1] != "(0)" || args[2] != "a" {
				return fmt.Errorf("%d: invalid operand", lineno+1)
			}

		case DJNZ:
			inst.label = args[1]
		}

		m.inst = append(m.inst, inst)
	}

	for i := range m.inst {
		if m.inst[i].op != DJNZ {
			continue
		}
		for j := range m.inst {
			if m.inst[j].op == LABEL && m.inst[i].label == m.inst[j].label {
				m.inst[i].val = j - i
				break
			}
		}
	}

	return nil
}

func (m *Mach) Reset() {
	m.reg = [2]int{}
	m.pc = 0
}

func (m *Mach) Run() {
	for m.pc < len(m.inst) {
		inst := &m.inst[m.pc]
		switch inst.op {
		case LD:
			m.reg[inst.reg] = inst.val

		case OUT:
			for i := 7; i >= 0; i-- {
				if (m.reg[A]>>i)&1 != 0 {
					fmt.Printf("*")
				} else {
					fmt.Printf(".")
				}
			}
			fmt.Println()

		case RLCA:
			m.reg[A] = m.reg[A]<<1 | m.reg[A]>>7

		case RRCA:
			m.reg[A] = m.reg[A]>>1 | m.reg[A]<<7

		case DJNZ:
			if m.reg[B]--; m.reg[B] != 0 {
				m.pc += inst.val - 1
			}
		}
		m.pc++
	}
	fmt.Println()
}
