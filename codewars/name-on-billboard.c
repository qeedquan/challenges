/*

You can print your name on a billboard ad. Find out how much it will cost you.
Each character has a default price of £30, but that can be different if you are given 2 parameters instead of 1.

You can not use multiplier "*" operator.

If your name would be Jeong-Ho Aristotelis, ad would cost £600.
20 leters * 30 = 600 (Space counts as a character).

*/

#include <assert.h>
#include <string.h>

int
billboard(const char *name, int price)
{
	return strlen(name) * price;
}

int
main()
{
	assert(600 == billboard("Jeong-Ho Aristotelis", 30));
	assert(570 == billboard("Abishai Charalampos", 30));
	assert(420 == billboard("Idwal Augustin", 30));
	assert(260 == billboard("Hadufuns John", 20));
	assert(570 == billboard("Zoroaster Donnchadh", 30));
	assert(450 == billboard("Claude Miljenko", 30));
	assert(165 == billboard("Werner Vigi", 15));
	assert(420 == billboard("Anani Fridumar", 30));
	assert(270 == billboard("Paolo Oli", 30));
	assert(600 == billboard("Hjalmar Liupold", 40));
	assert(390 == billboard("Simon Eadwulf", 30));

	return 0;
}
