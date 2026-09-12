/*

Given an array arr of strings, complete the function by calculating the total perimeter of all the islands. Each piece of land will be marked with 'X' while the water fields are represented as 'O'. Consider each tile being a perfect 1 x 1 piece of land. Some examples for better visualization:

['XOOXO',
 'XOOXO',
 'OOOXO',
 'XXOXO',
 'OXOOO']

which represents:

https://i.snag.gy/ZOQYs2.jpg

should return: "Total land perimeter: 24".

Following input:

['XOOO',
 'XOXO',
 'XOXO',
 'OOXX',
 'OOOO']

which represents:

https://i.snag.gy/Kv9BEz.jpg

should return: "Total land perimeter: 18"

*/

package main

func main() {
	assert(perimeter([][]byte{
		[]byte("XOOXO"),
		[]byte("XOOXO"),
		[]byte("OOOXO"),
		[]byte("XXOXO"),
		[]byte("OXOOO"),
	}) == 24)

	assert(perimeter([][]byte{
		[]byte("XOOO"),
		[]byte("XOXO"),
		[]byte("XOXO"),
		[]byte("OOXX"),
		[]byte("OOOO"),
	}) == 18)

	assert(perimeter([][]byte{
		[]byte("OXOOOX"),
		[]byte("OXOXOO"),
		[]byte("XXOOOX"),
		[]byte("OXXXOO"),
		[]byte("OOXOOX"),
		[]byte("OXOOOO"),
		[]byte("OOXOOX"),
		[]byte("OOXOOO"),
		[]byte("OXOOOO"),
		[]byte("OXOOXX"),
	}) == 60)

	assert(perimeter([][]byte{
		[]byte("OXOOO"),
		[]byte("OOXXX"),
		[]byte("OXXOO"),
		[]byte("XOOOO"),
		[]byte("XOOOO"),
		[]byte("XXXOO"),
		[]byte("XOXOO"),
		[]byte("OOOXO"),
		[]byte("OXOOX"),
		[]byte("XOOOO"),
		[]byte("OOOXO"),
	}) == 52)

	assert(perimeter([][]byte{
		[]byte("XXXXXOOO"),
		[]byte("OOXOOOOO"),
		[]byte("OOOOOOXO"),
		[]byte("XXXOOOXO"),
		[]byte("OXOXXOOX"),
	}) == 40)

	assert(perimeter([][]byte{
		[]byte("XOOOXOO"),
		[]byte("OXOOOOO"),
		[]byte("XOXOXOO"),
		[]byte("OXOXXOO"),
		[]byte("OOOOOXX"),
		[]byte("OOOXOXX"),
		[]byte("XXXXOXO"),
	}) == 54)

	assert(perimeter([][]byte{
		[]byte("OOOOXO"),
		[]byte("XOXOOX"),
		[]byte("XXOXOX"),
		[]byte("XOXOOO"),
		[]byte("OOOOOO"),
		[]byte("OOOXOO"),
		[]byte("OOXXOO"),
	}) == 40)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func perimeter(land [][]byte) int {
	p := 0
	for y := range land {
		for x := range land[y] {
			if land[y][x] != 'X' {
				continue
			}

			p += 4
			p -= at(land, x, y-1)
			p -= at(land, x, y+1)
			p -= at(land, x-1, y)
			p -= at(land, x+1, y)
		}
	}
	return p
}

func at(land [][]byte, x, y int) int {
	if x < 0 || y < 0 || y >= len(land) || x >= len(land[y]) {
		return 0
	}
	if land[y][x] == 'X' {
		return 1
	}
	return 0
}
