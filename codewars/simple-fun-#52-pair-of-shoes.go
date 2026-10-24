/*

Task
Yesterday you found some shoes in your room. Each shoe is described by two values:

type indicates if it's a left or a right shoe;
size is the size of the shoe.
Your task is to check whether it is possible to pair the shoes you found in such a way that each pair consists of a right and a left shoe of an equal size.

Example

For:

shoes = [[0, 21],
         [1, 23],
         [1, 21],
         [0, 23]]
the output should be true;

For:

shoes = [[0, 21],
         [1, 23],
         [1, 21],
         [1, 23]]
the output should be false.

Input/Output

[input] 2D integer array shoes
Array of shoes. Each shoe is given in the format [type, size], where type is either 0 or 1 for left and right respectively, and size is a positive integer.

Constraints: 2 ≤ shoes.length ≤ 50, 1 ≤ shoes[i][1] ≤ 100.

[output] a boolean value

true if it is possible to pair the shoes, false otherwise.

*/

package main

func main() {
	assert(pairable([][2]int{{0, 21}, {1, 23}, {1, 21}, {0, 23}}) == true)
	assert(pairable([][2]int{{0, 21}, {1, 23}, {1, 21}, {1, 23}}) == false)
	assert(pairable([][2]int{{0, 23}, {1, 21}, {1, 23}, {0, 21}, {1, 22}, {0, 22}}) == true)
	assert(pairable([][2]int{{0, 23}, {1, 21}, {1, 23}, {0, 21}}) == true)
	assert(pairable([][2]int{{0, 23}, {1, 21}, {1, 22}, {0, 21}}) == false)
	assert(pairable([][2]int{{0, 23}}) == false)
	assert(pairable([][2]int{{0, 23}, {1, 23}}) == true)
	assert(pairable([][2]int{{0, 23}, {1, 23}, {1, 23}, {0, 23}}) == true)
	assert(pairable([][2]int{{0, 23}, {1, 22}}) == false)
	assert(pairable([][2]int{{0, 23}, {1, 23}, {1, 23}, {0, 23}, {0, 23}, {0, 23}}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func pairable(shoes [][2]int) bool {
	count := make(map[int][2]int)
	for _, shoe := range shoes {
		if shoe[0] != 0 && shoe[0] != 1 {
			return false
		}

		value := count[shoe[1]]
		value[shoe[0]] += 1
		count[shoe[1]] = value
	}

	for _, value := range count {
		if value[0] != value[1] {
			return false
		}
	}
	return true
}
