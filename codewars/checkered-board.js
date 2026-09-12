/*

Write a function which takes one parameter representing the dimensions of a checkered board. The board will always be square, so 5 means you will need a 5x5 board.

The dark squares will be represented by a unicode white square, while the light squares will be represented by a unicode black square (the opposite colours ensure the board doesn't look reversed on code wars' dark background). It should return a string of the board with a space in between each square and taking into account new lines.

An even number should return a board that begins with a dark square. An odd number should return a board that begins with a light square.

Examples
Input: 5

Output:
■ □ ■ □ ■
□ ■ □ ■ □
■ □ ■ □ ■
□ ■ □ ■ □
■ □ ■ □ ■
There should be no trailing white space at the end of each line, or new line characters at the end of the string.

Note
The squares are characters ■ and □ with codes \u25A0 and \u25A1.
Do not use HTML entities for the squares (e.g. □ for white square) as the code doesn't consider it a valid square. A good way to check is if your solution prints a correct checker board on your local terminal.

Ruby note: CodeWars has encoding issues with rendered unicode in Ruby. You'll need to use unicode source code (e.g. "\u25A0") instead of rendered unicode (e.g "■").

*/

function checkerboard(n) {
	for (let y = 0; y < n; y++) {
		for (let x = 0; x < n; x++) {
			if ((x ^ y) & 1)
				process.stdout.write("□");
			else
				process.stdout.write("■");

			if (x + 1 < n)
				process.stdout.write(" ");
		}
		console.log();
	}
}

function main() {
	checkerboard(5);
	checkerboard(16);
}

main();
