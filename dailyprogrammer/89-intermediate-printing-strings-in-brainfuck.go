/*

A while ago we had some fun with the very peculiar Brainfuck programming language, which (despite its limited set of commands and character set) is actually Turing complete, meaning that any computation you can do in any other programming language, you can do in Brainfuck.

That doesn't make it easy to use, though. Even as simple a task as printing out a string requires quite lengthy code. Today, we will simplify that task quite a bit!

Your task today is to write a program that takes a string as input and outputs Brainfuck code that, when run, will print out that string. That is, given "Hello World!", it will print out something that looks like Wikipedia's example Hello World program (though not necessarily exactly, of course).

Use your program to create a Brainfuck program that prints out The Raven, by Edgar Allen Poe.

Bonus: Try to optimize your program in such a way as to make the brainfuck code as short as possible. Here, for instance, is a 34500 character long Brainfuck program that I made which prints out "The Raven". Can you beat me and write a program that generates shorter Brainfuck code?

Remember, this bonus is optional, even if your generated program is very big, you are still free to submit code.

*/

package main

import "fmt"

func main() {
	bfc := newbfc(1024)
	bfc.Compile("Hello, World!")
}

type BFC struct {
	mem []uint8
}

func newbfc(n int) *BFC {
	return &BFC{
		mem: make([]uint8, n),
	}
}

// ported from @skeeto solution
func (b *BFC) Compile(s string) {
	b.preamble()

	p := 0
	for _, c := range s {
		best := 256
		bestp := p
		for i := range b.mem {
			count := abs(p-i) + abs(int(c)-int(b.mem[i]))
			if count < best {
				best = count
				bestp = i
			}
		}
		b.move(bestp - p)
		p = bestp
		b.inc(int(c) - int(b.mem[p]))
		b.mem[p] = uint8(c)
		fmt.Printf(".")
	}
}

func (b *BFC) preamble() {
	for i := 1; i < len(b.mem); i++ {
		b.mem[i] = 89
	}
	fmt.Printf("+++++++++[")
	for i := 1; i < len(b.mem); i++ {
		fmt.Printf(">++++++++++")
	}
	b.move(-len(b.mem) + 1)
	fmt.Printf("-]")
	fmt.Printf("+[")
	for i := 1; i < len(b.mem); i++ {
		fmt.Printf(">-")
	}
	b.move(-len(b.mem) + 1)
	fmt.Printf("-]")
}

func (b *BFC) move(d int) {
	b.emit2(d, "<", ">")
}

func (b *BFC) inc(d int) {
	b.emit2(d, "-", "+")
}

func (b *BFC) emit2(d int, s0, s1 string) {
	n := abs(d)
	for range n {
		if d < 0 {
			fmt.Printf(s0)
		} else {
			fmt.Printf(s1)
		}
	}
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
