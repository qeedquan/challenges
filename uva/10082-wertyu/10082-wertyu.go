package main

import "bytes"

func main() {
	assert(solve(`O S, GOMR YPFSU/`) == `I AM FINE TODAY.`)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(line string) string {
	output := new(bytes.Buffer)
	for _, letter := range line {
		if mapping, found := wertyu[letter]; found {
			letter = mapping
		}
		output.WriteRune(letter)
	}
	return output.String()
}

var wertyu = make(map[rune]rune)

func init() {
	wertyu['1'] = '`'
	wertyu['2'] = '1'
	wertyu['3'] = '2'
	wertyu['4'] = '3'
	wertyu['5'] = '4'
	wertyu['6'] = '5'
	wertyu['7'] = '6'
	wertyu['8'] = '7'
	wertyu['9'] = '8'
	wertyu['0'] = '9'
	wertyu['-'] = '0'
	wertyu['='] = '-'
	wertyu['W'] = 'Q'
	wertyu['E'] = 'W'
	wertyu['R'] = 'E'
	wertyu['T'] = 'R'
	wertyu['Y'] = 'T'
	wertyu['U'] = 'Y'
	wertyu['I'] = 'U'
	wertyu['O'] = 'I'
	wertyu['P'] = 'O'
	wertyu['['] = 'P'
	wertyu[']'] = '['
	wertyu['\\'] = ']'
	wertyu['S'] = 'A'
	wertyu['D'] = 'S'
	wertyu['F'] = 'D'
	wertyu['G'] = 'F'
	wertyu['H'] = 'G'
	wertyu['J'] = 'H'
	wertyu['K'] = 'J'
	wertyu['L'] = 'K'
	wertyu[';'] = 'L'
	wertyu['\''] = ';'
	wertyu['X'] = 'Z'
	wertyu['C'] = 'X'
	wertyu['V'] = 'C'
	wertyu['B'] = 'V'
	wertyu['N'] = 'B'
	wertyu['M'] = 'N'
	wertyu[','] = 'M'
	wertyu['.'] = ','
	wertyu['/'] = '.'
	wertyu[' '] = ' '
}
