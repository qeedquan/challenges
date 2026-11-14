/*

In this code-golf challenge, you must output an ascii-art of a random die roll.

like this:

   ________
  /\       \
 /  \   6   \
{ 4  }-------}
 \  /   5   /
  \/_______/
Please note that:

   ________
  /\       \
 /  \   3   \
{ 4  }-------}
 \  /   5   /
  \/_______/
is invalid output, because that is not a possible result on a die

There are 6(faces that could be up)*4(faces that could be the left face after the top is determined)*1(faces that could be the right face after the other two are determined)=24 possibilities of die rolls.

Your program must output one of these die rolls in the form of an ascii art (modeled like the one below, with the x y and zs replaced with numbers) like above, with each output having >0 probability of occurring, but the probabilities do not have to be even (they are allowed to be trick dice, unlike in real life). Your program cannot output an invalid die roll, or a non die roll. Your program must have a probability of 1 of outputting a valid roll

Please note that your die does not necessarily have to be a right handed die like shown in the first image. (right- and left-handed describe the die's net)

right-handed die
   ________
  /\       \    net
 /  \   z   \     _|4|_ _
{ x  }-------}   |6|2|1|5|
 \  /   y   /      |3|
  \/_______/


left handed die
   ________
  /\       \    net
 /  \   y   \     _|3|_ _
{ x  }-------}   |6|2|1|5|
 \  /   z   /      |4|
  \/_______/
If your die is left handed, the following is valid output, but not if your die is right handed:

   ________
  /\       \
 /  \   2   \
{ 1  }-------}
 \  /   3   /
  \/_______/
While you can choose left handed or right handed, your die has to be consistent: it cannot change from left to right or vice versa

the following is a list of valid outputs for the die. Refer to the pictures above for positions of X-Y-Z:

X-Y-Z
-----
5-4-1
1-5-4
4-1-5

5-6-4
4-5-6
6-4-5

5-3-6
6-5-3
3-6-5

5-1-3
3-5-1
1-3-5

2-6-3
3-2-6
6-3-2

2-4-6
6-2-4
4-6-2

2-1-4
4-2-1
1-4-2

2-3-1
1-2-3
3-1-2
again this is code-golf, so fewer bytes is better

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
roll()
{
	static const char sym[] = "123513653263154214624564";

	int b, o, r;

	r = rand() % 24;
	o = r % 3;
	b = r - o;

	printf("   ________\n");
	printf("  /\\       \\\n");
	printf(" /  \\   %c   \\\n", sym[r]);
	printf("{ %c  }-------}\n", sym[b + (o + 1) % 3]);
	printf(" \\  /   %c   /\n", sym[b + (o + 2) % 3]);
	printf("  \\/_______/\n");
}

int
main()
{
	srand(time(NULL));
	roll();

	return 0;
}
