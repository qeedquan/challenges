/*

Your task is very easy!!! The target is practising conversion "by hand" from base 10 to 16.

Develop a method public String convertToHex(int number) which allows converting number to Hexadecimal. Note that 0<number<=4294967295.
The final result must concat at the start 0x. Letters must be in upperCase since the tests are expecting upperCases.

In this kata you have to programme "by hand" the conversion. What make sense is making your own method!!

These solutions are not the target of this kata.

Integer.toString(a, 16)
String.format("0x%X", a)
Integer.toHexString(a)

and same structures 

*/

class Hexadecimal {
	static String convertToHex(long number) {
		return String.format("%#x", number);
	}

	public static void main(String[] args) {
		for (long i = 0; i <= 32; i++)
			System.out.println(convertToHex(i));
	}
}
