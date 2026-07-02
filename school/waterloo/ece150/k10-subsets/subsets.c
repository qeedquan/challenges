/*

Write a function that prints all the set of all integers from 1 to n.

For example, the following are the subsets of the set {1,2,3,4}:

{}
{1}
{2}
{1,2}
{3}
{1,3}
{2,3}
{1,2,3}
{4}
{1,4}
{2,4}
{1,2,4}
{3,4}
{1,3,4}
{2,3,4}
{1,2,3,4}

Notice that the order of these subsets correspond to the bits of the integers from 0 to 15:

   0000     {}
   0001     {1}
   0010     {2}
   0011     {1,2}
   0100     {3}
   0101     {1,3}
   0110     {2,3}
   0111     {1,2,3}
   1000     {4}
   1001     {1,4}
   1010     {2,4}
   1011     {1,2,4}
   1100     {3,4}
   1101     {1,3,4}
   1110     {2,3,4}
   1111     {1,2,3,4}
Thus, you could simply iterate through the numbers from 0 to 2^n-1 and only print those numbers corresponding to bits that are set to 1.

One issue with this approach is that there is no relationship between the subsequent sets. For example, the set following {1,2,3} is the singleton {4}.
One way to avoid this is to use Gray codes (see a previous project) in which case, there is only the addition or removal of an integer in the set with each subsequent entry:

             0    0000    {}
             1    0001    {1}
             3    0011    {1,2}
             2    0010    {2}
             6    0110    {2,3}
             7    0111    {1,2,3}
             5    0101    {1,3}
             4    0100    {3}
            12    1100    {3,4}
            13    1101    {1,3,4}
            15    1111    {1,2,3,4}
            14    1110    {2,3,4}
            10    1010    {2,4}
            11    1011    {1,2,4}
             9    1001    {1,4}
             8    1000    {4}

Your function should have the declaration

void print_subsets( unsigned int n, bool use_gray_codes = false );

*/

#include <stdio.h>

unsigned
dec2gray(unsigned value)
{
	return value ^ (value >> 1);
}

void
subsets(unsigned length, bool gray)
{
	unsigned bit, comma, index, size, value;

	printf("length=%u gray=%u\n", length, gray);
	size = 1u << length;
	for (index = 0; index < size; index++) {
		comma = 0;
		value = (gray) ? dec2gray(index) : index;
		printf("%u {", value);
		for (bit = 0; bit < size; bit++) {
			if (!(value & (1u << bit)))
				continue;

			if (comma)
				printf(",");

			printf("%u", bit + 1);
			comma = 1;
		}
		printf("}\n");
	}
	printf("\n");
}

int
main(void)
{
	subsets(4, false);
	subsets(4, true);

	subsets(5, false);
	subsets(5, true);

	return 0;
}
