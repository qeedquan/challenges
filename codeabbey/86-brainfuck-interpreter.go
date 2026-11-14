/*

We are going to make extension for our site - to add problems which should be solved in Brainfuck programming language.

But of course we need an executing system (interpreter) for this funny esoteric language.

In this problem you should create such interpreter. Do not be afraid - it is easier to write Brainfuck interpreter itself than to write Brainfuck problems for such interpreter.

We ask you to implement slightly altered version of the language - Brainfuck++ which includes two additional commands ; and :.

Please, refer to the wiki article by the link above to read specification of the language.

Input data will contain two lines.
The first input line contains Brainfuck program without any spare characters.
The second line contains a sequence of numbers which would be consumed as input.
Answer should contain output of the program.

Example:

input data:
;>;<[->+<]:>:
3 5

answer:
0 8

*/

package main

import (
	"fmt"
	"io"
	"log"
	"os"
	"strings"
)

func main() {
	test([]byte(";>;<[->+<]:>:"), "3 5")
}

func test(code []byte, input string) {
	bf := NewBF(30000, strings.NewReader(input), os.Stdout)
	bf.Load(code)
	err := bf.Run()
	if err != nil {
		log.Fatal(err)
	}
}

type BF struct {
	ip   int
	mem  []byte
	code []byte
	in   io.Reader
	out  io.Writer
}

func NewBF(size int, in io.Reader, out io.Writer) *BF {
	return &BF{
		mem: make([]byte, size),
		in:  in,
		out: out,
	}
}

func (c *BF) Reset() {
	c.ip = 0
	clear(c.mem)
}

func (c *BF) Load(code []byte) {
	c.code = code
}

func (c *BF) Run() error {
	for i := 0; i < len(c.code); i++ {
		switch c.code[i] {
		case '>':
			c.ip = (c.ip + 1) % len(c.mem)

		case '<':
			if c.ip--; c.ip < 0 {
				c.ip = len(c.mem) - 1
			}

		case '.':
			fmt.Fprintf(c.out, "%c", c.mem[c.ip])

		case '+':
			c.mem[c.ip]++

		case '-':
			c.mem[c.ip]--

		case ',':
			var r rune
			fmt.Fscanf(c.in, "%c", &r)
			c.mem[c.ip] = byte(r)

		case '[':
			if c.mem[c.ip] == 0 {
				for p := 1; p > 0; {
					if i++; i >= len(c.code) {
						return fmt.Errorf("unmatched ]")
					}

					if c.code[i] == '[' {
						p++
					} else if c.code[i] == ']' {
						p--
					}
				}
			}

		case ']':
			if c.mem[c.ip] != 0 {
				for p := 1; p > 0; {
					if i--; i < 0 {
						return fmt.Errorf("unmatched [")
					}

					if c.code[i] == ']' {
						p++
					} else if c.code[i] == '[' {
						p--
					}
				}
			}

		case ':':
			fmt.Fprintf(c.out, "%d ", c.mem[c.ip])

		case ';':
			var val int
			fmt.Fscanf(c.in, "%d", &val)
			c.mem[c.ip] = byte(val)
		}
	}

	fmt.Fprintln(c.out)
	return nil
}
