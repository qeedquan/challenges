/*

Setting the Scene:
It is an average afternoon, as you unwind after a long day by engaging in your favorite pastime: answering the plethora of captivating questions on PPCG. It hasn't been a good day for you; those damned Pyth programmers keep getting best answer and it's killing your vibe. Suddenly, you notice a new question has been posted! You make up your mind; not this time CJammers. Furiously, you begin to type, birthing a stream of characters; a fetus of the glorious BrainFuck loop that your end product will be. You type and type. Faster! Faster still! You're so focused you don't even notice the lights on your screen start to flicker on and off. Suddenly, the monitor glows green, an alien like symbol branded upon the desktop. Using your impeccable skills you cat ~/Desktop/aliensymbol and get presented with a bunch of numbers, a message! Being the shrewd PPCG programmer that you are, you notice that it looks like ASCII. No matter for you, you print(chr(i) for i in file) and decipher the message. Your first thought: "I need to share this with the community!".

...

Who would've thought it? That the first people to make contact with aliens would be the humble programmers of PPCG. Why us? Maybe it is because we are the epitome of human intelligence. Or maybe because BrainFuck is about as close as we have to an alien language. Nevertheless, the aliens - being the ultra-intelligent life forms that they are - want to test whether they should classify the human race as intelligent or not. As a test of our mental prowess, the aliens have asked us to send them a few computer programs to demonstrate that we are technologically cultured. The issue is, the only human language they understand is numerical ASCII!

Help humankind show those creatures who the real intellectual alpha is. We need to send them a script that will convert our text based source codes into their numerical ASCII versions. Unfortunately, due to our underdeveloped technology (thanks Obama), we must send as small a translating program as possible. Good thing they chose to contact PPCG!

The Challenge:
The premise of this challenge is simple: you are to write a program that will take any program's source code (or any general text file for that matter), and output a space separated version of it with an ASCII translation below each line. That is, given an input of a text file, you need to output each line of that file followed by a line containing the ASCII representation of each character in the line above it (with each number lining up with the character it represents).

An example will greatly clarify this. Taking the source code of the infamous hello world as the input:

#include <stdio.h>

int main() {
    printf("hello, world\n");
    return 0;
}
your program should output:

#   i   n   c   l   u   d   e       <   s   t   d   i   o   .   h   >
35  105 110 99  108 117 100 101 32  60  115 116 100 105 111 46  104 62  10

10
i   n   t       m   a   i   n   (   )       {
105 110 116 32  109 97  105 110 40  41  32  123 10
                p   r   i   n   t   f   (   "   h   e   l   l   o   ,       w   o   r   l   d   \   n   "   )   ;
32  32  32  32  112 114 105 110 116 102 40  34  104 101 108 108 111 44  32  119 111 114 108 100 92  110 34  41  59  10
                r   e   t   u   r   n       0   ;
32  32  32  32  114 101 116 117 114 110 32  48  59  10
}
125 10
Implementation Details:
You may choose to take the input in whatever form you wish (opening file, command line pipe, function parameter etc.) and you should output to stdout or return the output from a function.

Things to note

Each character in the output is separated by a '\t' to allow for the space of 3 digits in the line below to line up (we are going to assume your tab is set to 4 spaces or more).
The newlines are displayed on the line that the return key was pressed (notice the 10's in the example)
The '\t' and '\n' printing requirements are lax. Your output must, in the general sense, look pleasing to the eye (need to show those aliens we have aesthetic sense as well), and if you can bend the previous two points while maintaining visual integrity, you will be forgiven.
You can choose to assume whether or not there is a newline at the end of the last line.
Scoring
This is code-golf so shortest program wins. Note, even if your program isn't the shortest, but uses really neat tricks relative to the language you are using, many +1's to you!

Good luck. The intergalactic intelligence ranking of humanity rests on your shoulders.

Note: Please forgive the plot holes. I'm not a writer :D

*/

#include <stdio.h>

void
output(const char *s)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (s[i] != '\n') {
			printf("%-4c", s[i]);
			continue;
		}

		printf("\n");

		for (; j <= i; j++)
			printf("%-4d", s[j]);
		printf("\n\n");

		j = i + 1;
	}
}

int
main(void)
{
	static const char code[] =
	    "#include <stdio.h>\n"
	    "\n"
	    "int main() {\n"
	    "    printf(\"hello, world\\n\");\n"
	    "    return 0;\n"
	    "}\n";

	output(code);

	return 0;
}
