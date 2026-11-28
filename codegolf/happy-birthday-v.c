/*

Thanks to @KritixiLithos for helping me out with this challenge!

V is a programming language that I wrote so that I could use and extend vim for code-golf challenges. The very first commit was on March 3rd, 2016, meaning that today V turns one year old! Woo-hoo

Over V's first year of existence, there have been 176 commits from four different contributors, 140 answers from 12 different users, and too many broken duplicate operators to count. It has an online interpreter, generously hosted by @Dennis, which has been run almost 8,000 times since December.

Let's have a challenge to celebrate V's birthday! Since most features in V are designed with string manipulation and ascii-art in mind, it just seems natural that any challenge celebrating V should be about ascii art. So your challenge for today is to take a word as input, and reshape that word in the shape of a V. For example, the input "Hello" should give the following V:

Hello         olleH
 Hello       olleH
  Hello     olleH
   Hello   olleH
    Hello olleH
     HellolleH
      HellleH
       HeleH
        HeH
         H
Here are some details about what your V should look like. If the input string is n characters long, the V should be n*2 lines tall. The very first line should consist of:

<input string><(n*2) - 1 spaces><input string reversed>
On each new line, one space is added to the beginning, and the two sides of the string move towards each other, removing any overlapping characters. Until the very last line, which is just the first character of input. Trailing whitespace on each line is acceptable, and a trailing newline is allowed too.

You can assume that the input will always be printable ASCII without any whitespace in it, and you may take input and output in any reasonable method. Here are some more sample inputs:

Happy:

Happy         yppaH
 Happy       yppaH
  Happy     yppaH
   Happy   yppaH
    Happy yppaH
     HappyppaH
      HapppaH
       HapaH
        HaH
         H

Birthday:

Birthday               yadhtriB
 Birthday             yadhtriB
  Birthday           yadhtriB
   Birthday         yadhtriB
    Birthday       yadhtriB
     Birthday     yadhtriB
      Birthday   yadhtriB
       Birthday yadhtriB
        BirthdayadhtriB
         BirthdadhtriB
          BirthdhtriB
           BirthtriB
            BirtriB
             BiriB
              BiB
               B

V!:

V!   !V
 V! !V
  V!V
   V

~:

~ ~
 ~
Of course, since this is code-golf, standard loopholes are banned and your goal is to write the shortest possible program to complete this task. Happy golfing!

For what it's worth, I have a soft spot for vim answers, so imaginary bonus points for using vim or V, although any language is acceptable. :)

*/

#include <stdio.h>
#include <string.h>

int
clamp(int x, int a, int b)
{
	if (x < a)
		x = a;
	else if (x > b)
		x = b;
	return x;
}

void
repeat(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%s", s);
}

void
forward(const char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		putchar(s[i]);
}

void
backward(const char *s, int n)
{
	int i;

	for (i = n; i >= 0; i--)
		putchar(s[i]);
}

void
draw(const char *s)
{
	int i, n, w, x, y;

	n = strlen(s);
	if (n == 0) {
		printf("\n");
		return;
	}

	w = (2 * n) - 1;
	for (i = 0; i < w; i++) {
		x = clamp(w - i + 1, 0, n);
		y = clamp(w - i - 1, 0, n);

		repeat(" ", i);
		forward(s, x);
		repeat(" ", w - (2 * i));
		backward(s, y);
		printf("\n");
	}
	repeat(" ", w);
	putchar(s[0]);
	printf("\n\n");
}

int
main()
{
	draw("Happy");
	draw("Birthday");
	draw("V!");
	draw("~");

	return 0;
}
