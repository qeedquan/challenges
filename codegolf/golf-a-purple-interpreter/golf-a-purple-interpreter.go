/*

Golf a Purple Interpreter
Purple is an esolang which is designed with two main purposes:

To be a minimization of Aubergine, since there just aren't enough self-modifying one-instruction languages around.
To admit the possibility of terrifyingly small golfed interpreters. My first pass at a reasonably full-featured Python 2 interpreter is only 702 bytes, and I'm sure a more experienced golfer could shave quite a bit from that.
Your goal is to write an interpreter for this language.

Information on Purple:
A Purple program is a sequence of characters placed into an infinite, addressable memory array such that the first character of the program is placed at address zero. The rest of the array (both before and after where the Purple program is stored) is initialized to zero.

There are three registers in Purple, called a and b and i, each of which can hold a signed integer and is initialized to zero. i is also the instruction pointer, and always points to the currently executing Purple instruction.

Each cycle, the interpreter will read a sequence of three contiguous characters beginning from the memory location indicated by the instruction pointer and attempt to execute this sequence as the Purple instruction. Afterwards, the instruction pointer is always incremented by 3.

Syntactically, the Purple instruction consists of three characters (or encodings thereof) in a row, like "xyz".

The first character x can be any of the following:

abABio
These symbols have the following meaning:

a - Place the result in register a.
b - Place the result in register b.
A - Place the result in the location in memory referred to by register a.
B - Place the result in the location in memory referred to by register b.
i - Set the instruction pointer to the result.
o - Output the result to stdout.
The other two bytes y and z can be any of the following:

abABio1
Each of these symbols has the following meaning:

a - Return the contents of register a.
b - Return the contents of register b.
A - Return the contents of the memory array at the address stored in register a.
B - Return the contents of the memory array at the address stored in register b.
i - Return the contents of register i (the instruction pointer).
o - Return the value of a single character read from stdin.
1 - Return the literal numeric value 1.
After fetching the instruction, the Purple interpreter will evaluate y and then z, subtract the result of z from the result of y, and then perform the action indicated by x on the difference.

If the sequence of three characters (or encodings thereof) is not a valid Purple instruction, the interpreter halts immediately without giving any errors.

Your interpreter must:
Be a complete program, not a function.
Never output to stderr, unless EOF is read.
Behave identically to the reference implementation on all well-formed inputs that do not involve very large numbers, including the test programs given below. (Well, identically up to timing--it can run slower, but not by too much!)
You may provide the program to the interpreter in any form you wish: read it from a file, embed it in the program as a string, or read it from stdin.

Test cases:
The program

ooo
when run with input

z!
should yield

Y
The program

bbboobiii
when run with input

It's a cat program.
(or any other input) should yield

It's a cat program.
(or whatever input it received) and then start over and do the same thing again.

The program

Aoab11bi1bABoAaiba
when run with input

0
should yield

0
and then halt, but when run with input

1
should continue outputting

1
forever.

The program

b1bbb1oAbabaa1ab1Ab1Bi1b
should yield

b1bbb1oAbabaa1ab1Ab1Bi1b
The program

aA1aa1bb1oAbbi1bb1bbAb1Bi1b Purple is the awesomest! Why haven't you tried it yet?
!dlroW ,olleG
should yield

Hello, World!
Scoring:
This is code-golf, so shortest source in bytes, as potentially modified by the following bonus, wins.

Bonus:
-10% if your interpreter reads a filename from either stdin or from a command line argument and loads the program from the file.

*/

package main

import (
	"flag"
	"fmt"
	"log"
	"os"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}

	var purple Purple
	err := purple.Load(flag.Arg(0))
	if err != nil {
		log.Fatal(err)
	}
	purple.Reset()
	purple.Run()
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: <file>")
	flag.PrintDefaults()
	os.Exit(2)
}

type Purple struct {
	a, b int
	i    int
	mem  map[int]int
	hlt  bool
}

func (p *Purple) Load(name string) error {
	buf, err := os.ReadFile(name)
	if err != nil {
		return err
	}

	p.mem = make(map[int]int)
	for i := range buf {
		p.mem[i] = int(buf[i])
	}

	return nil
}

func (p *Purple) Reset() {
	p.a, p.b, p.i, p.hlt = 0, 0, 0, false
}

func (p *Purple) Run() {
	for !p.hlt {
		p.Step()
	}
	fmt.Println()
}

func (p *Purple) Step() {
	defer func() {
		if err := recover(); err != nil {
			p.hlt = true
		}
	}()

	op := p.mem[p.i]
	y := p.arg(p.i + 1)
	z := p.arg(p.i + 2)
	r := y - z
	switch op {
	case 'a':
		p.a = r
	case 'b':
		p.b = r
	case 'A':
		p.mem[p.a] = r
	case 'B':
		p.mem[p.b] = r
	case 'i':
		p.i = r
	case 'o':
		fmt.Printf("%c", r)
	default:
		panic("unknown instruction")
	}
	p.i += 3
}

func (p *Purple) arg(i int) int {
	switch p.mem[i] {
	case 'a':
		return p.a
	case 'b':
		return p.b
	case 'A':
		return p.mem[p.a]
	case 'B':
		return p.mem[p.b]
	case 'i':
		return p.i
	case 'o':
		var c byte
		fmt.Scanf("%c", &c)
		return int(c)
	case '1':
		return 1
	default:
		panic("unknown argument")
	}
}
