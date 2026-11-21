/*

I only very recently discovered code golf and just found this part of the Stackexchange network, and naturally after looking at so many clever answers, I feel inferior. Inner me knows I'll get better over time, but inner me is also vain and needs validation.

At the same time, I don't take kindly to pandering, so you'd better not write me a program that looks like it took 15 seconds. You have to mean it.

Goal:
Print the phrase "you're pretty!" or write a function that returns that string. All letters can be upper-case or lower-case, but the punctuation and the spacing must be the same.

How to mean it:
If you're sensitive and can sympathize with all the emotions associated with feeling like a noobie, you should aim to make your program look like it does something entirely different and innocuous. I like to be surprised :) You may achieve this by not using any of the alphabetical characters in "you're pretty".

Winner is decided by shortest byte count. -5 bytes for each positive or neutral adjective you extend the phrase by, i.e. "you're pretty and effulgent and green", up to a possible 20 byte reduction.

*/

#include <stdio.h>

const char *
pretty()
{
	return "you're pretty!";
}

int
main()
{
	puts(pretty());
	return 0;
}
