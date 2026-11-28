/*

My last puzzle has generated some confusion and controversy so I decided to give up, for now, on those "replace one character"-type puzzles.

Hope this 4th puzzle will redeem myself after all the edits in puzzle 3 and will put your brains at work once more.

I've really put up all the effort to make this one as clear as possible and hope you will enjoy it!

So here it goes:

We start from a very short C program:

int main() {
   int a = 93;
   int b = 11;
   int c = 22528;

   // insert your code here

}
Your job will be to swap the values of the variables a,b,c like this: a <= b, b <= c, c <= a. To make it even more clear: new a = old b, new b = old c, new c = old a.

You are required to do this by inserting one single instruction in the line indicated by the comment in the code. To be clear once again, this line will contain only one semicolon (;) indicating the end of the lone instruction. After the execution of this program, a will contain 11, b will contain 22528, c will contain 93. However, there are some conditions that need to be met. So we'll have 4 different puzzles with different cryteria.

4.1. Do it by using whatever you want. Just one statement. -> most creative solution wins this one.

4.2. Do it without using any comma (,). -> most creative wins

4.3. Do it without any comma and with no more than 4 letters (+any other characters). -> shortest code wins

4.4. Do it without any comma and with no more than 4 letters and no more than 4 digits (+any other characters). -> shortest code wins

To make sure you understood, here's some code that is valid under the condition required but does not solve the problem:

4.1:

I_hereby_call_my_beautiful_function(nice_argument), int q=w, who_the_hell_is(w)+1;
4.2:

one = single + assignment;
4.3:

int w=12345678;
4.4:

int w=1234;
P.S. In case you haven't already noticed, 4.4 is the tough one here (I hope :D).

*/

#include <assert.h>

/*

@AMK

Classic inplace exchange (20 chars without spaces, category 4.1, 4.2):

c ^= b ^= c ^= b ^= a ^= b ^= a;
Total exist 9 xor-chains that implement this 3-way exchange

c ^= b ^= c ^= b ^= a ^= b ^= a;
c ^= a ^= c ^= b ^= c ^= b ^= a;
c ^= b ^= a ^= b ^= a ^= c ^= a;
a ^= c ^= b ^= c ^= b ^= a ^= b;
a ^= b ^= a ^= c ^= a ^= c ^= b;
a ^= c ^= a ^= c ^= b ^= c ^= b;
b ^= c ^= b ^= a ^= b ^= a ^= c;
b ^= a ^= b ^= a ^= c ^= a ^= c;
b ^= a ^= c ^= a ^= c ^= b ^= c;
and to continue of Gareth idea (No commas, 3 letters, 4 digits)

c=(b<<=a>>=3)/242;

*/

void
swap3(int *a, int *b, int *c)
{
	*b ^= *a;
	*a ^= *b;
	*b ^= *a;
	*c ^= *b;
	*b ^= *c;
	*c ^= *b;
}

void
test(int a0, int b0, int c0)
{
	int a, b, c;

	a = a0;
	b = b0;
	c = c0;

	swap3(&a, &b, &c);

	assert(a == b0);
	assert(b == c0);
	assert(c == a0);
}

int
main(void)
{
	test(93, 11, 22528);

	return 0;
}
