/*

You have to write a function that describe Leo:

function leo(oscar) {

}

if oscar was (integer) 88, you have to return "Leo finally won the oscar! Leo is happy".
if oscar was 86, you have to return "Not even for Wolf of wallstreet?!"
if it was not 88 or 86 (and below 88) you should return "When will you give Leo an Oscar?"
if it was over 88 you should return "Leo got one already!"

*/

#include <stdio.h>

const char *
leo(int oscar)
{
	if (oscar == 88)
		return "Leo finally won the oscar! Leo is happy";
	if (oscar == 86)
		return "Not even for Wolf of wallstreet?!";
	if (oscar < 88)
		return "When will you give Leo an Oscar?";
	return "Leo got one already!";
}

int
main()
{
	int i;

	for (i = 0; i <= 100; i++)
		printf("%d: %s\n", i, leo(i));

	return 0;
}
