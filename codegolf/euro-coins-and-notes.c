/*

As the majority of nations using the Euro have the , as the decimal separator, you must use it also.

The task is to output all the values of the Euro coins and notes in ascending order. You must also put the trailing ,00 on the integer values.

0,01 0,02 0,05 0,10 0,20 0,50 1,00 2,00 5,00 10,00 20,00 50,00 100,00 200,00 500,00

I accept both output to stdout or a function returning an array/list. If output is to stdout, the acceptable separators between values are: space, tab, or newline.

There will be no accepted answer, unless I see some one I find very creative.

code-golf, so I want to know shortest answer by language.

Update:
Leading 0 zeros are not acceptable. Sorry, I should make it clear before.

Update 2:
It is also acceptable a function returning a string.

*/

#include <stdio.h>

const char *
eurocoins(void)
{
	return "0,01 0,02 0,05 0,10 0,20 0,50 1,00 2,00 5,00 10,00 20,00 50,00 100,00 200,00 500,00";
}

int
main(void)
{
	printf("%s\n", eurocoins());
	return 0;
}
