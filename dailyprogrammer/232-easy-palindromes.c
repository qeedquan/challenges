/*

Description
A palindrome is a word or sentence that is spelled the same backwards and forwards. A simple of example of this is Swedish pop sensation ABBA, which, when written backwards, is also ABBA. Their hit song (and winner of the 1974 Eurovision Song Contest!) "Waterloo" is not a palindrome, because "Waterloo" backwards is "Oolretaw".

Palindromes can be longer than one word as well. "Solo gigolos" (the saddest of all gigolos) is a palindrome, because if you write it backwards it becomes "Sologig olos", and if you move the space three places back (which you are allowed to do), that becomes "Solo gigolos".

Today, you are going to write a program that detects whether or not a particular input is a valid palindrome.

Formal inputs & outputs
Inputs
On the first line of the input, you will receive a number specifying how many lines of input to read. After that, the input consists of some number of lines of text that you will read and determine whether or not it is a palindrome or not.

The only important factor in validating palindromes is whether or not a sequence of letters is the same backwards and forwards. All other types of characters (spaces, punctuation, newlines, etc.) should be ignored, and whether a character is lower-case or upper-case is irrelevant.

Outputs
Output "Palindrome" if the input is a palindrome, "Not a palindrome" if it's not.

Sample inputs
Input 1
3
Was it a car
or a cat
I saw?
Output 1
Palindrome
Input 2
4
A man, a plan,
a canal, a hedgehog,
a podiatrist,
Panama!
Output 2
Not a palindrome
Challenge inputs
Input 1
2
Are we not drawn onward,
we few, drawn onward to new area?
Input 2
Comedian Demitri Martin wrote a famous 224 palindrome, test your code on that.

Bonus
A two-word palindrome is (unsurprisingly) a palindrome that is two words long. "Swap paws", "Yell alley" and "sex axes" (don't ask) are examples of this.

Using words from r/dailyprogrammer's favorite wordlist enable1.txt, how many two-word palindromes can you find? Note that just repeating the same palindromic word twice (i.e. "tenet tenet") does not count as proper two-word palindromes.

Notes
A version of this problem was suggested by u/halfmonty on r/dailyprogrammer_ideas, and we thank him for his submission! He has been rewarded with a gold medal for his great deeds!

If you have a problem you'd like to suggest, head on over to r/dailyprogrammer_ideas and suggest it! Thanks!

*/

#include <assert.h>
#include <stdio.h>
#include <ctype.h>

typedef unsigned _BitInt(128) xlong;

/*

Ported from @skeeto solution

https://stackoverflow.com/questions/4963560/how-to-compute-palindrome-from-a-stream-of-characters-in-sub-linear-space-time/4964438#4964438
https://en.wikipedia.org/wiki/Rolling_hash

If the input is a palindrome, the hashes will match. The catch is that there will be false positives, in which we have to check normally.
Try to minimize collisions by using large integer types.

*/

bool
palindrome(const char *s)
{
	xlong c, k;
	xlong l, r;

	l = r = 0;
	for (k = 1; *s; s++) {
		if (!isalnum(*s))
			continue;

		c = tolower(*s);
		l = (3 * l) + c;
		r = r + (k * c);
		k *= 3;
	}
	return l == r;
}

int
main()
{
	const char *s1 = "Was it a car\n"
	                 "or a cat\n"
	                 "I saw?";
	const char *s2 = "A man, a plan, \n"
	                 "a canal, a hedgehog, \n"
	                 "a podiatrist, \n"
	                 "Panama!";
	const char *s3 = "Are we not drawn onward,\n"
	                 "we few, drawn onward to new area?";
	const char *s4 =
	    "Dammit I'm mad.\n"
	    "Evil is a deed as I live.\n"
	    "God, am I reviled? I rise, my bed on a sun, I melt.\n"
	    "To be not one man emanating is sad. I piss.\n"
	    "Alas, it is so late. Who stops to help?\n"
	    "Man, it is hot. I'm in it. I tell.\n"
	    "I am not a devil. I level \"Mad Dog\".\n"
	    "Ah, say burning is, as a deified gulp,\n"
	    "In my halo of a mired rum tin.\n"
	    "I erase many men. Oh, to be man, a sin.\n"
	    "Is evil in a clam? In a trap?\n"
	    "No. It is open. On it I was stuck.\n"
	    "Rats peed on hope. Elsewhere dips a web.\n"
	    "Be still if I fill its ebb.\n"
	    "Ew, a spider... eh?\n"
	    "We sleep. Oh no!\n"
	    "Deep, stark cuts saw it in one position.\n"
	    "Part animal, can I live? Sin is a name.\n"
	    "Both, one... my names are in it.\n"
	    "Murder? I’m a fool.\n"
	    "A hymn I plug, deified as a sign in ruby ash,\n"
	    "A Goddam level I lived at.\n"
	    "On mail let it in. I'm it.\n"
	    "Oh, sit in ample hot spots. Oh wet!\n"
	    "A loss it is alas (sip). I'd assign it a name.\n"
	    "Name not one bottle minus an ode by me:\n"
	    "\"Sir, I deliver. I'm a dog\"\n"
	    "Evil is a deed as I live.\n"
	    "Dammit I’m mad.";
	const char *s5 = "ABBA";
	const char *s6 = "Waterloo";
	const char *s7 = "Solo gigolos";
	const char *s8 = "kayak";
	const char *s9 = "rotator";
	const char *s10 = "repaper";
	const char *s11 = "tattarrattat";
	const char *s12 = "saippuakivikauppias";
	const char *s13 = "saippuakivikauppiaz";
	const char *s14 = "abcba";
	const char *s15 = "oooouxooo";

	assert(palindrome(s1) == true);
	assert(palindrome(s2) == false);
	assert(palindrome(s3) == false);
	assert(palindrome(s4) == true);
	assert(palindrome(s5) == true);
	assert(palindrome(s6) == false);
	assert(palindrome(s7) == true);
	assert(palindrome(s8) == true);
	assert(palindrome(s9) == true);
	assert(palindrome(s10) == true);
	assert(palindrome(s11) == true);
	assert(palindrome(s12) == true);
	assert(palindrome(s13) == false);
	assert(palindrome(s14) == true);
	assert(palindrome(s15) == false);

	return 0;
}
