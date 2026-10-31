/*

Problem

You are given a binary string A of length N.

You can perform the following type of operation on the string A:

Choose two different indices i and j (1≤i, j≤N)
Change Ai and  Aj to Ai⊕Aj. Here ⊕ represents the bitwise XOR operation.
Input

A binary string consisting of 0's and 1's

Output

The minimum number of operations required to make the binary string a palindrome

Reference

Here's the link of the problem.
https://www.codechef.com/problems/XOR_PAL

Actual Doubt

I tried solving it by the logic that the number of operations required would be equal to the number of inequalities of characters in the string when traversing from left and right. simultaneously.

My code:

for(int i=0,j=n-1;i<n/2;i++,j--) {
    if(b[i]!=b[j]) count++;
 }
Where b is the binary string and n is it's length.

But, it turns out the solution is this:

for(int i=0,j=n-1;i<n/2;i++,j--) {
    if(b[i]!=b[j]) count++;
  }

cout<<(count+1)/2<<endl;
And I don't understand why.

Can someone explain this? Thanks.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>

/*

@Command Master

The solution is correct because if  a≠b and c≠d then a⊕c=b⊕d (if a,b,c,d are bits), so you can pair the values on each side.

*/

size_t
xorpal(const char *s)
{
	ssize_t i, j, n;
	size_t c;

	c = 0;
	n = strlen(s);
	for (i = 0, j = n - 1; i < n / 2; i++, j--) {
		if (s[i] != s[j])
			c += 1;
	}
	return (c + 1) / 2;
}

int
main()
{
	assert(xorpal("11011") == 0);
	assert(xorpal("0111010") == 1);
	assert(xorpal("1") == 0);
	assert(xorpal("1100") == 1);

	return 0;
}
