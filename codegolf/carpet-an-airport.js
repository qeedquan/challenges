/*

In 2015 the Portland International Airport began the replacement of their iconic carpet. I want you to write a program to draw their old carpet in as few bytes as possible.

The carpet:

https://i.sstatic.net/SaxOD.png

Specifications
Here is a link to a scalable pdf image of one tile. Your output should match the relative dimensions and placement of that image.

All colors in your final image should be within 15 of every RGB value in the specified image. These are listed below for your convenience.

            Red   Green Blue
Teal:       0,    168,  142
Magenta:    168,  108,  185
Orange:     247,  58,   58
Light Blue: 90,   166,  216
Dark Blue:  0,    77,   117
Your output must be at least 150x150 pixels and should be square. If you choose to output in a scalable format like a vector image you should match the image exactly.

You may output the image in any preexisting image format.

This is code-golf so you should aim to minimize the number of bytes in your code.

*/

const ENCODING = `iVBORw0KGgoAAAANSUhEUgAAAJgAAACYBAMAAADq7D0SAAAAD1BMVEUAqI4ATXWobLn3Ojpapthl
S7nNAAAAj0lEQVR4Ae3ThRHCQBQGYVqgBVq4Fui/Jt4ILks8/80uLvkyOTlkd67EILHojtWEyxQT
Sw6uFS5TTCw/uFa+TDGx/PjS3z+KiS2GcRtgzIqJdboDPomteniCxMTyatXtMiExMcB22amCJ7wG
MbHpBWBiYmJiYmJwAjGx/ncAn0VMrP8dwL+KieXHFyImltoF6oWZiblRTNQAAAAASUVORK5CYII=`;

function main() {
	let data = Buffer.from(ENCODING, 'base64');
	process.stdout.write(data);
}

main();
