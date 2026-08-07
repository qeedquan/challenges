/*

Task
Write a function that receives a non-negative integer n ( n >= 0 ) and returns the next higher multiple of five of that number, obtained by concatenating the shortest possible binary string to the end of this number's binary representation.

Examples
1.  nextMultipleOfFive(8)
Steps:

8 to binary == '1000'
concatenate shortest possible string '11' to obtain '1000' + '11' == '100011'
'100011' to decimal == 35 => the answer
('001' would do the job too, but '11' is the shortest string here)

2.  nextMultipleOfFive(5)
Steps:

5 to binary =='101'
concatenate shortest possible string '0' to obtain '101' + '0' == '1010'
'1010' to decimal == 10
(5 is already a multiple of 5, obviously, but we're looking for the next multiple of 5)

Note
Numbers up to 1e10 will be tested, so you need to come up with something smart.

*/

package main

func main() {
	assert(next5(0) == 5)
	assert(next5(2) == 5)
	assert(next5(5) == 10)
	assert(next5(8) == 35)
	assert(next5(13) == 55)
	assert(next5(27) == 55)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func next5(num uint64) uint64 {
	bits := []uint64{0b0, 0b1, 0b01, 0b11, 0b011}
	shift := []uint64{1, 1, 2, 2, 3}
	for i := range bits {
		val := num<<shift[i] | bits[i]
		if val > 0 && val%5 == 0 {
			return val
		}
	}
	return 5
}
