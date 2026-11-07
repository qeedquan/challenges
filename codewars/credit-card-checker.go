/*

Description
Write a function that checks whether a credit card number is correct or not, using the Luhn algorithm.

The algorithm is as follows:

From the rightmost digit, which is the check digit, moving left, double the value of every second digit; if the product of this doubling operation is greater than 9 (e.g., 8 × 2 = 16), then checksum the digits of the products (e.g., 16: 1 + 6 = 7, 18: 1 + 8 = 9) or alternatively subtract 9 from the product (e.g., 16: 16 - 9 = 7, 18: 18 - 9 = 9).
Take the checksum of all the digits.
If the total modulo 10 is equal to 0 (if the total ends in zero) then the number is valid according to the Luhn formula; else it is not valid.
The input is a string with the full credit card number, in groups of 4 digits separated by spaces, i.e. "1234 5678 9012 3456"
Don´t worry about wrong inputs, they will always be a string with 4 groups of 4 digits each separated by space.

Examples
valid_card?("5457 6238 9823 4311") # True

valid_card?("5457 6238 9323 4311") # False

for reference check: https://en.wikipedia.org/wiki/Luhn_algorithm

*/

package main

func main() {
	assert(validcard("8895 6238 9323 4311") == false)
	assert(validcard("5457 6238 5568 4311") == false)
	assert(validcard("5457 6238 9323 4311") == false)
	assert(validcard("2222 2222 2222 2224") == true)
	assert(validcard("5457 1125 9323 4311") == false)
	assert(validcard("1252 6238 9323 4311") == false)
	assert(validcard("9999 9999 9999 9995") == true)
	assert(validcard("0000 0300 0000 0000") == false)
	assert(validcard("4444 4444 4444 4448") == true)
	assert(validcard("5457 6238 9323 1252") == false)
	assert(validcard("5457 6238 1251 4311") == false)
	assert(validcard("3333 3333 3333 3331") == true)
	assert(validcard("6666 6666 6666 6664") == true)
	assert(validcard("5457 6238 0254 4311") == false)
	assert(validcard("0000 0000 0000 0000") == true)
	assert(validcard("5457 1111 9323 4311") == false)
	assert(validcard("5457 6238 9823 4311") == true)
	assert(validcard("1145 6238 9323 4311") == false)
	assert(validcard("8888 8888 8888 8888") == true)
	assert(validcard("0025 2521 9323 4311") == false)
	assert(validcard("5457 6238 9323 4311") == false)
	assert(validcard("1111 1111 1111 1117") == true)
	assert(validcard("1234 5678 9012 3452") == true)
	assert(validcard("5458 4444 9323 4311") == false)
	assert(validcard("5457 6238 3333 4311") == false)
	assert(validcard("0123 4567 8901 2345") == false)
	assert(validcard("5555 5555 5555 5557") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func validcard(card string) bool {
	const format = "xxxx xxxx xxxx xxxx"

	if len(card) != len(format) {
		return false
	}

	checksum := 0
	position := 0
	for index, kind := range format {
		symbol := card[len(card)-index-1]
		switch kind {
		case 'x':
			if !('0' <= symbol && symbol <= '9') {
				return false
			}

			symbol -= '0'
			if position&1 != 0 {
				symbol *= 2
				if symbol > 9 {
					symbol -= 9
				}
			}
			checksum += int(symbol)
			position += 1

		case ' ':
			if symbol != ' ' {
				return false
			}
		}
	}
	return checksum%10 == 0
}
