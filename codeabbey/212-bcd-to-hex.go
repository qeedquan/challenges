/*

Early CPU's often lacked multiplication and especially division operation. This made conversion between binary and decimal systems quite a tough challenge - and lead to widespread of BCD format, when every 4-bit nibble stored one decimal digit.

In this problem we are to write code for Intel-4004, converting 4-digit value from BCD to Hexadecimal format.

Input will have 4-digit BCD value in r3:r0 (note that it is "reversed", i.e. r3 is the most significant).
Output should give 4-digit Hex value in r11:r8 (where r11 also is the most significant).

Example:

input:    1 2 3 9 0 0 0 0 0 0 0 0 0 0 0 0
answer:   0 0 0 0 0 0 0 0 9 6 4 2 0 0 0 0
Note that the checker will not care about registers other than r11:r8 so they could contain anything after calculations.

Answer is not tested by the checker and the input serves only as a sample. You rather need to supply working code which will be executed against several test-cases on the server.

The size of solution is measured in the bytes. Many instructions are single-byte, while some (especially jumps) are two byte long. Also if you add data in your program via db instruction - the size is of course increased. To check the size you may use our online emulator.

https://www.codeabbey.com/index/wiki/intel-4004-emulator

*/

package main

import "fmt"

func main() {
	fmt.Println(solve([16]int{1, 2, 3, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}))
}

func solve(reg [16]int) [16]int {
	val := reg[3]*1000 + reg[2]*100 + reg[1]*10 + reg[0]
	return [16]int{
		8:  val & 0xf,
		9:  (val >> 4) & 0xf,
		10: (val >> 8) & 0xf,
		11: (val >> 12) & 0xf,
	}
}
