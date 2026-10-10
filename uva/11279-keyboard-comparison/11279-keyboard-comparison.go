package main

import (
	"fmt"
	"unicode"
)

func main() {
	fmt.Println(distance("CCPC"))
	fmt.Println(distance("Which keyboard is better?"))
	fmt.Println(distance("Numbers! 1234567890"))
}

func distance(line string) [3]float64 {
	var score [3]float64
	for _, letter := range line {
		letter = unicode.ToLower(letter)
		score[0] += qwerty2[letter]
		score[1] += qwerty1[letter]
		score[2] += dvorak[letter]
	}
	return score
}

var (
	qwerty2 = make(map[rune]float64)
	qwerty1 = make(map[rune]float64)
	dvorak  = make(map[rune]float64)
)

func init() {
	qwerty2['`'] = 4.472135955
	qwerty2['1'] = 4
	qwerty2['2'] = 4
	qwerty2['3'] = 4
	qwerty2['4'] = 4
	qwerty2['5'] = 4.472135955
	qwerty2['6'] = 4.472135955
	qwerty2['7'] = 4
	qwerty2['8'] = 4
	qwerty2['9'] = 4
	qwerty2['0'] = 4
	qwerty2['-'] = 4.472135955
	qwerty2['='] = 5.656854249

	qwerty2['~'] = 4.472135955
	qwerty2['!'] = 4
	qwerty2['@'] = 4
	qwerty2['#'] = 4
	qwerty2['$'] = 4
	qwerty2['%'] = 4.472135955
	qwerty2['^'] = 4.472135955
	qwerty2['&'] = 4
	qwerty2['*'] = 4
	qwerty2['('] = 4
	qwerty2[')'] = 4
	qwerty2['_'] = 4.472135955
	qwerty2['+'] = 5.656854249

	qwerty2['q'] = 2
	qwerty2['w'] = 2
	qwerty2['e'] = 2
	qwerty2['r'] = 2
	qwerty2['t'] = 2.828427125
	qwerty2['y'] = 2.828427125
	qwerty2['u'] = 2
	qwerty2['i'] = 2
	qwerty2['o'] = 2
	qwerty2['p'] = 2
	qwerty2['['] = 2.828427125
	qwerty2[']'] = 4.472135955
	qwerty2['\\'] = 6.32455532

	qwerty2['{'] = 2.828427125
	qwerty2['}'] = 4.472135955
	qwerty2['|'] = 6.32455532

	qwerty2['a'] = 0
	qwerty2['s'] = 0
	qwerty2['d'] = 0
	qwerty2['f'] = 0
	qwerty2['g'] = 2
	qwerty2['h'] = 2
	qwerty2['j'] = 0
	qwerty2['k'] = 0
	qwerty2['l'] = 0
	qwerty2[';'] = 0
	qwerty2['\''] = 2

	qwerty2[':'] = 0
	qwerty2['"'] = 2

	qwerty2['z'] = 2
	qwerty2['x'] = 2
	qwerty2['c'] = 2
	qwerty2['v'] = 2
	qwerty2['b'] = 2.828427125
	qwerty2['n'] = 2.828427125
	qwerty2['m'] = 2
	qwerty2[','] = 2
	qwerty2['.'] = 2
	qwerty2['/'] = 2

	qwerty2['<'] = 2
	qwerty2['>'] = 2
	qwerty2['?'] = 2

	qwerty1['`'] = 8.94427191
	qwerty1['1'] = 7.211102551
	qwerty1['2'] = 5.656854249
	qwerty1['3'] = 4.472135955
	qwerty1['4'] = 4
	qwerty1['5'] = 4
	qwerty1['6'] = 4
	qwerty1['7'] = 4
	qwerty1['8'] = 4.472135955
	qwerty1['9'] = 5.656854249
	qwerty1['0'] = 7.211102551
	qwerty1['-'] = 8.94427191
	qwerty1['='] = 10.77032961

	qwerty1['~'] = 8.94427191
	qwerty1['!'] = 7.211102551
	qwerty1['@'] = 5.656854249
	qwerty1['#'] = 4.472135955
	qwerty1['$'] = 4
	qwerty1['%'] = 4
	qwerty1['^'] = 4
	qwerty1['&'] = 4
	qwerty1['*'] = 4.472135955
	qwerty1['('] = 5.656854249
	qwerty1[')'] = 7.211102551
	qwerty1['_'] = 8.94427191
	qwerty1['+'] = 10.77032961

	qwerty1['q'] = 6.32455532
	qwerty1['w'] = 4.472135955
	qwerty1['e'] = 2.828427125
	qwerty1['r'] = 2
	qwerty1['t'] = 2
	qwerty1['y'] = 2
	qwerty1['u'] = 2
	qwerty1['i'] = 2.828427125
	qwerty1['o'] = 4.472135955
	qwerty1['p'] = 6.32455532
	qwerty1['['] = 8.246211251
	qwerty1[']'] = 10.19803903
	qwerty1['\\'] = 12.16552506

	qwerty1['{'] = 8.246211251
	qwerty1['}'] = 10.19803903
	qwerty1['|'] = 12.16552506

	qwerty1['a'] = 6
	qwerty1['s'] = 4
	qwerty1['d'] = 2
	qwerty1['f'] = 0
	qwerty1['g'] = 0
	qwerty1['h'] = 0
	qwerty1['j'] = 0
	qwerty1['k'] = 2
	qwerty1['l'] = 4
	qwerty1[';'] = 6
	qwerty1['\''] = 8

	qwerty1[':'] = 6
	qwerty1['"'] = 8

	qwerty1['z'] = 6.32455532
	qwerty1['x'] = 4.472135955
	qwerty1['c'] = 2.828427125
	qwerty1['v'] = 2
	qwerty1['b'] = 2
	qwerty1['n'] = 2
	qwerty1['m'] = 2
	qwerty1[','] = 2.828427125
	qwerty1['.'] = 4.472135955
	qwerty1['/'] = 6.32455532

	qwerty1['<'] = 2.828427125
	qwerty1['>'] = 4.472135955
	qwerty1['?'] = 6.32455532

	dvorak['`'] = 10.77032961
	dvorak['1'] = 8.94427191
	dvorak['2'] = 7.211102551
	dvorak['3'] = 5.656854249
	dvorak['q'] = 4.472135955
	dvorak['j'] = 4
	dvorak['l'] = 4
	dvorak['m'] = 4
	dvorak['f'] = 4
	dvorak['p'] = 4.472135955
	dvorak['/'] = 5.656854249
	dvorak['['] = 7.211102551
	dvorak[']'] = 8.94427191

	dvorak['~'] = 10.77032961
	dvorak['!'] = 8.94427191
	dvorak['@'] = 7.211102551
	dvorak['#'] = 5.656854249
	dvorak['?'] = 5.656854249
	dvorak['{'] = 7.211102551
	dvorak['}'] = 8.94427191

	dvorak['4'] = 8.246211251
	dvorak['5'] = 6.32455532
	dvorak['6'] = 4.472135955
	dvorak['.'] = 2.828427125
	dvorak['o'] = 2
	dvorak['r'] = 2
	dvorak['s'] = 2
	dvorak['u'] = 2
	dvorak['y'] = 2.828427125
	dvorak['b'] = 4.472135955
	dvorak[';'] = 6.32455532
	dvorak['='] = 8.246211251
	dvorak['\\'] = 10.19803903

	dvorak['$'] = 8.246211251
	dvorak['%'] = 6.32455532
	dvorak['^'] = 4.472135955
	dvorak['>'] = 2.828427125
	dvorak[':'] = 6.32455532
	dvorak['+'] = 8.246211251
	dvorak['|'] = 10.19803903

	dvorak['7'] = 8
	dvorak['8'] = 6
	dvorak['9'] = 4
	dvorak['a'] = 2
	dvorak['e'] = 0
	dvorak['h'] = 0
	dvorak['t'] = 0
	dvorak['d'] = 0
	dvorak['c'] = 2
	dvorak['k'] = 4
	dvorak['-'] = 6

	dvorak['&'] = 8
	dvorak['*'] = 6
	dvorak['('] = 4
	dvorak['_'] = 6

	dvorak['0'] = 8.246211251
	dvorak['z'] = 6.32455532
	dvorak['x'] = 4.472135955
	dvorak[','] = 2.828427125
	dvorak['i'] = 2
	dvorak['n'] = 2
	dvorak['w'] = 2
	dvorak['v'] = 2
	dvorak['g'] = 2.828427125
	dvorak['\''] = 4.472135955

	dvorak[')'] = 8.246211251
	dvorak['<'] = 2.828427125
	dvorak['"'] = 4.472135955
}
