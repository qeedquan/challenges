/*

I know it's 1.5 weeks after Christmas but trying to print an isosceles triangle in a monospaced font makes it look weird.

Challenge
Print the alphabet from A to Z so that it forms a filled triangle in the output. For each line in the output, starting from "A", add the next letter.

No inputs, only outputs. Pad the leading edge of the triangle with spaces.

Best answer is the code with the least bytes.

Output
            A
            AB
           ABC
           ABCD
          ABCDE
          ABCDEF
         ABCDEFG
         ABCDEFGH
        ABCDEFGHI
        ABCDEFGHIJ
       ABCDEFGHIJK
       ABCDEFGHIJKL
      ABCDEFGHIJKLM
      ABCDEFGHIJKLMN
     ABCDEFGHIJKLMNO
     ABCDEFGHIJKLMNOP
    ABCDEFGHIJKLMNOPQ
    ABCDEFGHIJKLMNOPQR
   ABCDEFGHIJKLMNOPQRS
   ABCDEFGHIJKLMNOPQRST
  ABCDEFGHIJKLMNOPQRSTU
  ABCDEFGHIJKLMNOPQRSTUV
 ABCDEFGHIJKLMNOPQRSTUVW
 ABCDEFGHIJKLMNOPQRSTUVWX
ABCDEFGHIJKLMNOPQRSTUVWXY
ABCDEFGHIJKLMNOPQRSTUVWXYZ

Sample Java Code (430 bytes)
public static void main(String args[]) {
    String spaces = "";
    String alpha = "";
    char A = 'A';

    for (int i = 0; i < 26; i++) {
        for (int j = 13 - (i/2); j > 0; j--) {
           spaces += " ";
        }

        alpha += (char)(A + i);

        System.out.println(spaces + alpha);
        spaces = "";
    } 
}

*/

function christmas() {
	let alpha = "";
	for (let i = 0; i < 26; i++) {
		let spaces = "";
		for (let j = 12 - Math.floor(i/2); j > 0; j--) {
			spaces += " ";
		}

		alpha += String.fromCharCode(65 + i);
		console.log(spaces + alpha);
	}
}

function main() {
	christmas();
}

main();
