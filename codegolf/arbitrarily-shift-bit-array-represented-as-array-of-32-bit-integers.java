/*

Given an array of 32-bit integers which represent a bit array, shift the values by a specified amount in either direction. Positive shifts go to the left and negative values go to the right. This is a bit array so bits should wrap across values in the array.

For example, given the following data:

a[2] = 11110000 11110000 11110000 11110000
a[1] = 11110000 11110000 11110000 11110000
a[0] = 11110000 11110000 11110000 11110000 <-- 0th bit
Shifting the original by 2 should result in:

a[3] = 00000000 00000000 00000000 00000011
a[2] = 11000011 11000011 11000011 11000011
a[1] = 11000011 11000011 11000011 11000011
a[0] = 11000011 11000011 11000011 11000000 <-- 0th bit
Shifting the original by -3 should result in:

a[2] = 00011110 00011110 00011110 00011110
a[1] = 00011110 00011110 00011110 00011110
a[0] = 00011110 00011110 00011110 00011110 <-- 0th bit
There's no restriction on shift amount (i.e., can be greater than 32) so be mindful of where your bits are going!

Here's the method signature:

int[] bitArrayShift(int[] bits, int shift)
Implementations should:

Return an array whose contents represented the original bit array's contents shifted by the supplied number.
Return an array whose size is the minimum amount required to hold the values after the shift. You should not wrap back around to the 0th bit but rather expand to hold it.
Not mutate the input array. It should be treated as being passed by reference (therefore having mutable contents). Basically, don't put any new values at any position in the input array.
The following assertion should always return true for any value of 'bit' and 'shift':

// Given 'originalBits' as incoming bit array.
// Given 'bit' as a number between [0, originalBits.length * 32).
// Given 'shift' as any integer value.

// Get the value in the array at the index of 'bit'
bool original = ((originalBits[bit / 32] & (1 << (bit % 32)) != 0
// Shift the original bits by the specified 'shift'
int[] shiftedBits = bitArrayShift(originalBits, shift)
// Offset the original 'bit' by the specified 'shift'
int shiftedBit = bit + shift
// Get the value in the shifted array at the index of 'shiftedBit'
bool shifted = ((shiftedBits[shiftedBit / 32] & (1 << (shiftedBit % 32)) != 0
// They should be equal.
assert original == shifted
Smallest character count wins. Count method body contents ONLY sans leading and trailing whitespace. That is, the method declaration up to and including the block start (if any) and ending exclusively at the block end (if any).

E.g., for Java:

public static int[] shiftBitArray(int[] bits, int shift) {
  << COUNT THIS ONLY >>>
}

*/

import java.math.BigInteger;

class Shifter {
    public static void main(String[] args) {
		var value0 = new int[]{
			0b11110000_11110000_11110000_11110000,
			0b11110000_11110000_11110000_11110000,
			0b11110000_11110000_11110000_11110000,
		};

		var value1 = shiftBitArray(value0, 2);
		var value2 = shiftBitArray(value0, -3);
		
		printBinary(value0);
		printBinary(value1);
		printBinary(value2);
	}

	public static void printBinary(int[] values) {
		for (var index = values.length - 1; index >= 0; index--) {
			var value = values[index];
			var string0 = "";
			var string1 = Integer.toBinaryString(value);
			if (string1.length() < 32) {
				string0 = "0".repeat(32 - string1.length());
			}
			System.out.printf("%s%s\n", string0, string1);
		}
		System.out.println();
	}

	// ported from @sanjary solution
	public static int[] shiftBitArray(int[] bits, int shift) {
		var value = BigInteger.ZERO;
		for (var index = bits.length - 1; index >= 0; index--) {
			var lower = BigInteger.valueOf(0xffffffffL & bits[index]);
			value = value.shiftLeft(32);
			value = value.or(lower);
		}
		value = value.shiftLeft(shift);
 
		var length = roundup(value.bitLength(), 32) / 32;
		var result = new int[length];
		for (var index = 0; index < length; index++) {
			result[index] = value.intValue();
			value = value.shiftRight(32);
		}
		return result;
	}

	public static int roundup(int number, int multiple) {
		if (multiple == 0)
			return number;
		
		var remainder = number % multiple;
		if (remainder == 0)
			return number;

		return number + multiple - remainder;
	}
}
