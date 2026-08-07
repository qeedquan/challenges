/*

Lots of people on this site use esoteric languages, and since these languages are unusual and hard to understand, they will frequently write an explanation in a certain format. For example, if the code was

abcdefghijklmnop
And this languages uses # for comments, they would write an explanation like this:

a                #Explanation of what 'a' does
 bc              #Bc
   d             #d
    e            #Explanation of e
     fgh         #foobar
        ij       #hello world
          k      #etc.
           l     #so on
            mn   #and
              op #so forth
I frequently do this too, but every time I do this, I feel like creating the layout of text is really obnoxious and time-consuming. So I want you to create a "Esolang-Comment-Template-Generator" for me. For example, if we ignore the comments, the previous code has this template:

a                #
 bc              #
   d             #
    e            #
     fgh         #
        ij       #
          k      #
           l     #
            mn   #
              op #
The Challenge:
You must write a program or function that takes two strings as input, and outputs this "Esolang-Comment-Template". The first input will be the code, but with bars (|) inserted where the newlines go. The second input is what we will use for comments. So our last example would have this for input:

"a|bc|d|e|fgh|ij|k|l|mn|op", "#"
Unfortunately this excludes bars from being part of the code input, but that's OK. You can assume that the comment input will be a single character. For simplicity's sake, the comment char will not be a bar. The code input will only contain printable ASCII, and it will not contain any newlines.

Hopefully you can infer what to do from the testcases, but I'll try to clarify some things.

You must split the code input up into "code-sections" on every bar. Then, each section of code is output on its own line and left-padded with the length of all the previous code (not including the bars). Then, each line is right-padded with enough spaces so that the last two characters on every line are "One additional space" + "The comment character".

One trailing newline is allowed.

Here is another example. For the input

"Hello|World", "/"
The first section of code is "Hello" and the second is "World". So it should give the output:

Hello      /
     World /
Here are some more samples:

Input:
"a|b|c|d|e|f|g", ","

Output:
a       ,
 b      ,
  c     ,
   d    ,
    e   ,
     f  ,
      g ,

Input:
"abcdefg", ":"

Output:
abcdefg :

Input:
"4|8|15|16|23|42", "%"

Output:
4          %
 8         %
  15       %
    16     %
      23   %
        42 %

Input:
"E|ac|h s|ecti|on is| one c|haracte|r longer| than the| last!", "!"

Output:
E                                                   !
 ac                                                 !
   h s                                              !
      ecti                                          !
          on is                                     !
                one c                               !
                     haracte                        !
                            r longer                !
                                     than the       !
                                              last! !

Input:
"This|Code|has||empty||sections", "@"

Output:
This                     @
    Code                 @
        has              @
                         @
           empty         @
                         @
                sections @
Rules:
You may take these inputs and outputs in any reasonable format. For example, reading/writing a file, STDIN/STOUT, function arguments/return value, etc. As usual, this is code-golf, so try to make your code as short as possible and you win if you can get the shortest solution in your language! I will also select the shortest solution as the overall winner. Standard loopholes are banned.

*/

#include <stdio.h>

void
length(const char *s, size_t *n, size_t *l)
{
	size_t i;

	*n = *l = 0;
	for (i = 0; s[i]; i++) {
		if (s[i] == '|')
			*l += 1;
	}
	*n = i;
}

void
repeat(const char *s, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%s", s);
}

size_t
statement(const char *s)
{
	size_t i;

	for (i = 0; s[i] && s[i] != '|'; i++)
		putchar(s[i]);
	return i;
}

void
format(const char *s, const char *m)
{
	size_t i, j, k;
	size_t n, l;

	length(s, &n, &l);
	for (i = k = 0; s[i]; i += j) {
		repeat(" ", k);
		j = statement(s + i);
		k += j;
		if (s[i + j])
			j++;
		repeat(" ", n - l - k + 1);
		printf("%s\n", m);
	}
	printf("\n");
}

int
main(void)
{
	format("", "-");
	format("Hello|World", "/");
	format("a|bc|d|e|fgh|ij|k|l|mn|op", "#");
	format("abcdefg", ":");
	format("4|8|15|16|23|42", "%");
	format("E|ac|h s|ecti|on is| one c|haracte|r longer| than the| last!", "!");
	format("This|Code|has||empty||sections", "@");

	return 0;
}
