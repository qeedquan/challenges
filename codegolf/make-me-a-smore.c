/*

Make me a s'more! I tell you the width, the amount of graham cracker, the amount of chocolate, and the amount of marshmallow. An example:

Input:

Width: 10 Graham: 3 Chocolate: 2 Marshmallow: 1.

Output:

GGGGGGGGGG
GGGGGGGGGG
GGGGGGGGGG
CCCCCCCCCC
CCCCCCCCCC
MMMMMMMMMM
GGGGGGGGGG
GGGGGGGGGG
GGGGGGGGGG
Is it that easy? Um... yes.

Note that the input should be a list of arguments to a function or a program, not a string. You might choose the first being Width, then Graham, but any order is fine.

Full test cases if you are interested.

Stack snippet (for testing, etc.)
This is to test the output.

var smore = function(width, graham, chocolate, marshmallow){
        return ("G".repeat(width) + "\n").repeat(graham) +
        ("C".repeat(width) + "\n").repeat(chocolate) +
        ("M".repeat(width) + "\n").repeat(marshmallow) +
        ("G".repeat(width) + "\n").repeat(graham);
};
Snippetify(smore);
<script src="https://programmer5000.com/snippetify.min.js"></script>
Width: <input type = "number">
Graham: <input type = "number">
Chocolate: <input type = "number">
Marshmallow: <input type = "number">
<button>Try it out!</button>
<pre data-output></pre>

*/

#include <stdio.h>

void
output(int w, int h, char c)
{
	int x, y;

	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++)
			printf("%c", c);
		printf("\n");
	}
}

void
smore(int w, int g, int c, int m)
{
	output(w, g, 'G');
	output(w, c, 'C');
	output(w, m, 'M');
	output(w, g, 'G');
}

int
main(void)
{
	smore(10, 3, 2, 1);
	return 0;
}
