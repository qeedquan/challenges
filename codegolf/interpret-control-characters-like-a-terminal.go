/*

Given a ASCII string containing control characters, compute what it should look like when printed to a terminal. Imagining the behaviour of a cursor, this is how to treat each character in the input:

0x08 backspace (\b): go left one (if already at the start of a line, do not go up)
0x09 horizontal tab (\t): go right one, and then right until the column number (0-indexed) is a multiple of 8
0x0A line feed (\n): go down one line and back to the start of the line
0x0B vertical tab (\v): go down one line without changing horizontal position
0x0D carriage return (\r): go back to the start of the line
0x20 space ( ): overwrite the previous character with a space, and go right one (This is the same behaviour as a normal character but it's here just for clarity)
Any other printable ASCII character should be appended literally
Any characters that aren't listed above (other control characters, NULL bytes, Unicode, etc.) will not be given in the input, so you don't have to handle them
Note: The behaviours above are those of modern terminal emulators; in the olden days, on a printer or teletype, \n would have done what \v does here, and \v would have moved the print head down so that the line number was a multiple of 8 (or however else the tab stops were configured). More information

Since this is like a terminal or printer, you can assume the output will never be longer than 80 columns.

Gaps that were never printed on (because the cursor moved over it) should be filled in with spaces, but gaps that are further to the right than the cursor ever went should be stripped off.

If you try these in a shell (particularly those with \b and \r), the shell prompt may overwrite some of the text - try printing a newline afterwards or add a ; sleep 1 to see the effect properly.

Here is a reference implementation: Try it online!

Test cases
Input and output are given in C-style escaped string syntax. To clarify, your program does not need to interpret backslash escape sequences - the input will contain the literal control codes themselves.

Input           Output
-----------------------------------
""              ""
"A"             "A"
" "             " "
"\n"            "\n"
"A\nB\nC"       "A\nB\nC"
"\t"            "        "
"A\t"           "A       "
"A\t\t"         "A               "
"\tA"           "        A"
"A\tB\tC"       "A       B       C"
"ABCDEF\t"      "ABCDEF  "
"ABCDEFG\t"     "ABCDEFG "
"ABCDEFGH\t"    "ABCDEFGH        "
"ABCDEFGHI\t"   "ABCDEFGHI       "
"\b"            ""
"A\b"           "A"
"A\bB"          "B"
"A\n\bB"        "A\nB"
"AB\b\bC"       "CB"
"A\b "          " "
"\r"            ""
"A\r"           "A"
"A\rB"          "B"
"A\rB\rC"       "C"
"ABC\rD"        "DBC"
"A\rB\nC"       "B\nC"
"A\n\rB"        "A\nB"
"A \r"          "A "
"A\t\r"         "A       "
"AB\vC\rD"      "AB\nD C"
"\v"            "\n"
"A\v"           "A\n "
"A\vB"          "A\n B"
"AB\vCD"        "AB\n  CD"
"AB\v\bCD"      "AB\n CD"
"AB\v\rCD"      "AB\nCD"
"AB\tC\rD"      "DB      C"
"AB\t\bC"       "AB     C"
"AB\b\t"        "AB      "
"ABCDEF\b\t"    "ABCDEF  "
"ABCDEFG\b\t"   "ABCDEFG "
"ABCDEFGH\b\t"  "ABCDEFGH"
"ABCDEFGHI\b\t" "ABCDEFGHI       "
"a very long string that is approaching the 80-column limit\t!\n" "a very long string that is approaching the 80-column limit      !\n"

Rules
You may input and output a list of ASCII integer code-points instead of a string
You may use any sensible I/O format
Standard loopholes are forbidden
This is code-golf, so the shortest code in bytes wins

*/

package main

func main() {
	assert(compute("") == "")
	assert(compute("A") == "A")
	assert(compute(" ") == " ")
	assert(compute("\n") == "\n")
	assert(compute("A\nB\nC") == "A\nB\nC")
	assert(compute("\t") == "        ")
	assert(compute("A\t") == "A       ")
	assert(compute("A\t\t") == "A               ")
	assert(compute("\tA") == "        A")
	assert(compute("A\tB\tC") == "A       B       C")
	assert(compute("ABCDEF\t") == "ABCDEF  ")
	assert(compute("ABCDEFG\t") == "ABCDEFG ")
	assert(compute("ABCDEFGH\t") == "ABCDEFGH        ")
	assert(compute("ABCDEFGHI\t") == "ABCDEFGHI       ")
	assert(compute("\b") == "")
	assert(compute("A\b") == "A")
	assert(compute("A\bB") == "B")
	assert(compute("A\n\bB") == "A\nB")
	assert(compute("AB\b\bC") == "CB")
	assert(compute("A\b ") == " ")
	assert(compute("\r") == "")
	assert(compute("A\r") == "A")
	assert(compute("A\rB") == "B")
	assert(compute("A\rB\rC") == "C")
	assert(compute("ABC\rD") == "DBC")
	assert(compute("A\rB\nC") == "B\nC")
	assert(compute("A\n\rB") == "A\nB")
	assert(compute("A \r") == "A ")
	assert(compute("A\t\r") == "A       ")
	assert(compute("AB\vC\rD") == "AB\nD C")
	assert(compute("\v") == "\n")
	assert(compute("A\v") == "A\n ")
	assert(compute("A\vB") == "A\n B")
	assert(compute("AB\vCD") == "AB\n  CD")
	assert(compute("AB\v\bCD") == "AB\n CD")
	assert(compute("AB\v\rCD") == "AB\nCD")
	assert(compute("AB\tC\rD") == "DB      C")
	assert(compute("AB\t\bC") == "AB     C")
	assert(compute("AB\b\t") == "AB      ")
	assert(compute("ABCDEF\b\t") == "ABCDEF  ")
	assert(compute("ABCDEFG\b\t") == "ABCDEFG ")
	assert(compute("ABCDEFGH\b\t") == "ABCDEFGH")
	assert(compute("ABCDEFGHI\b\t") == "ABCDEFGHI       ")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func compute(text string) string {
	line := make([]rune, 128)
	for i := range line {
		line[i] = ' '
	}

	output := ""
	index := 0
	width := 0
	for _, char := range text {
		switch char {
		case '\b':
			index = max(index-1, 0)
		case '\n':
			output = flush(output, line, width)
			index = 0
			width = 0
		case '\v':
			output = flush(output, line, width)
			width = index
		case '\r':
			index = 0
		case '\t':
			index += 8 - index%8
			width = max(width, index)
		default:
			line = addchar(line, index, char)
			index += 1
			width = max(width, index)
		}
	}
	output += string(line[:width])
	return output
}

func addchar(line []rune, index int, char rune) []rune {
	if len(line) < index {
		newline := make([]rune, index+128)
		copy(newline, line)
		line = newline
	}
	line[index] = char
	return line
}

func flush(output string, line []rune, width int) string {
	output += string(line[:width]) + "\n"
	for i := range line {
		line[i] = ' '
	}
	return output
}
