/*

My mom really wants me to eat broccoli, but I hate it and never want to eat it. Mom wants to trick me so she cuts it into small pieces, puts it in a salad and mixes it. Help me find out if the salad contains broccoli!

Input:

Array of mixed letters of all the ingredients. For a single broccoli ingredient it could be:

[c,o,r,b,l,c,i,o]
Output:

Boolean or other convienient output allowing to distinguish if a salad contains broccoli or not.

Rules:

all possible ingredients are onion, broccoli, celery and beans
input array is always formed of mixing valid ingredients (meaning that it can be always decoded back to the original ingredients array)
input array cannot be decoded into more than one valid ingredient combination
each ingredient can occur 0 or more times in the salad
Sample test cases:

true stands for a salad with broccoli

[c,o,r,b,l,c,i,o] //true
[o,b,n,o,i,i,e,l,n,a,o,r,n,s,b,o,c,c] //true
[l,c,b,r,r,o,r,c,i,i,c,o,c,b,o,c,c,b,i,o,l,o,l,o] //true

[] //false
[o,n,i,o,n] //false
[b,n,s,i,a,o,n,b,a,s,e,e,n,o,n] //false
[b,r,o,c,c,o,l,i,e,y,e,r,l,a,e,e,n,s,y] //false
[e,n,s,o,e,n,i,o,a,o,o,e,n,n,e,l,n,l,e,o,e,r,c,l,o,y,i,r,y,r,y,b,e,l,n,n,c,c,r,c,e,y,i,e] //false
This is code-golf so the shortest code in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*

@Jonah

Idea of invariant based on letter counts from mathjunkie's clever answer -- be sure to upvote him.

Tests if the number cs is equal to the number of ys. This will only be true when no broccoli is present.

*/

bool
broccoli(const char *s)
{
	size_t h[256];

	memset(h, 0, sizeof(h));
	for (; *s; s++)
		h[*s & 0xff] += 1;
	return h['c'] != h['y'];
}

int
main()
{
	assert(broccoli("corblcio") == true);
	assert(broccoli("obnoiielnaornsbocc") == true);
	assert(broccoli("lcbrrorciicocboccbiololo") == true);

	assert(broccoli("") == false);
	assert(broccoli("onion") == false);
	assert(broccoli("bnsiaonbaseenon") == false);
	assert(broccoli("broccolieyerlaeensy") == false);
	assert(broccoli("ensoenioaooennelnleoercloyiryrybelnnccrceyie") == false);

	return 0;
}
