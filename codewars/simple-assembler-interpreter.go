/*

Description:
This is the first part of this kata series. Second part is here.

We want to create a simple interpreter of assembler which will support the following instructions:

mov x y - copies y (either a constant value or the content of a register) into register x
inc x - increases the content of the register x by one
dec x - decreases the content of the register x by one
jnz x y - jumps to an instruction y steps away (positive means forward, negative means backward, y can be a register or a constant), but only if x (a constant or a register) is not zero
Register names are alphabetical (letters only). Constants are always integers (positive or negative).

Note: the jnz instruction moves relative to itself. For example, an offset of -1 would continue at the previous instruction, while an offset of 2 would skip over the next instruction.

The function will take an input list with the sequence of the program instructions and will execute them. The program ends when there are no more instructions to execute, then it returns a dictionary (a table in COBOL) with the contents of the registers.

Also, every inc/dec/jnz on a register will always be preceeded by a mov on the register first, so you don't need to worry about uninitialized registers.

Example
["mov a 5"; "inc a"; "dec a"; "dec a"; "jnz a -1"; "inc a"]

visualized:

mov a 5
inc a
dec a
dec a
jnz a -1
inc a
The above code will:

set register a to 5,
increase its value by 1,
decrease its value by 2,
then decrease its value until it is zero (jnz a -1 jumps to the previous instruction if a is not zero)
and then increase its value by 1, leaving register a at 1
So, the function should return:

{'a': 1}
This kata is based on the Advent of Code 2016 - day 12

*/

package main

import "fmt"

func main() {
	test([]string{"mov a 5", "inc a", "dec a", "dec a", "jnz a -1", "inc a"})
}

func test(lines []string) {
	mem, err := assemble(lines)
	if err != nil {
		panic(err)
	}
	regs := execute(mem)
	fmt.Println(regs)
}

const (
	MOV = 1 + iota
	INC
	DEC
	JNZ
)

func assemble(lines []string) ([]int, error) {
	optab := map[string]struct {
		enc  int
		args int
	}{
		"mov": {MOV, 2},
		"inc": {INC, 1},
		"dec": {DEC, 1},
		"jnz": {JNZ, 2},
	}

	var (
		op  string
		reg rune
		val int
		mem []int
	)
	for lineno, line := range lines {
		nargs, _ := fmt.Sscanf(line, "%s %c %d", &op, &reg, &val)
		if nargs != 3 {
			nargs, _ = fmt.Sscanf(line, "%s %c", &op, &reg)
			val = 0
		}

		asm, found := optab[op]
		if !found || nargs-1 != asm.args {
			return nil, fmt.Errorf("%d: invalid instruction: %q", lineno+1, line)
		}

		mem = append(mem, asm.enc)
		mem = append(mem, int(reg))
		mem = append(mem, val)
	}
	return mem, nil
}

func execute(mem []int) map[int]int {
	regs := make(map[int]int)
	pc := 0
	for {
		if pc+2 >= len(mem) {
			break
		}

		ra := mem[pc+1]
		imm := mem[pc+2]
		switch mem[pc] {
		case MOV:
			regs[ra] = imm
		case INC:
			regs[ra]++
		case DEC:
			regs[ra]--
		case JNZ:
			if regs[ra] != 0 {
				pc += 3 * imm
				continue
			}
		}
		pc += 3
	}
	return regs
}
