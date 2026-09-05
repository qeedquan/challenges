/*

Introduction
Write a program to output the outgoing spiral of the famous pangram following given rules.

Challenge
A pangram is a sentence using every letter of a given alphabet at least once. One of the most famous pangrams is the one used extensively in Windows font viewer, namely "The quick brown fox jumps over the lazy dog". The challenge is to output a spiral based on this text.

Your task is output this exact text:

heeeeellllllllllllazzzzzzzzzzz
hummmmmmmmmmmmmppppppppppppppy
hubrrrrrrrrrrrrrrrrrrooooooosy
hukyddddoooooooooooooooggggwsy
hukyveeeeerrrrrrrrrrrrrrrrtwsy
hukyvxjjjjjjjjjjuuuuuuuuuttwsy
hukyvxkbbrrrrrrrrrrrrrrrmttwsy
hukyvxkogggggggttttttttomttwsy
tukyvokoellllllllllllahomttwsy
tukyvokoeovvvvvvvvvvvzhomttwsy
tukyvocoeoummmmmmmmmezhomttwsy
tukyvocoeoufooooooopezhomttwsy
tukyvocohoufroooooxpezhomttwsy
tukyvoiohoufrquuuwxpezhomttwsy
tucyvoiohoufbqttiwxpezhomttwsy
tucyvoiohoufbeehiwxprzhomttwsy
tucyvoiohoufkccciwxprzeomttwsy
tjiyvoidhounnnnnnwxprzeomttwsy
tjiyvoidhojjjjjjjjxprzeomttwsy
tjiyvoidhssssssssssprzeopttwsy
tjiyvoidttttttttttttrzeopttwsy
tjiyvoiyyyyyyyyyyyyyyzqopttwoy
tjiyvouuuuuuuuuuuuuuuuqwpttwoy
tjiyvffffnnnnnnnnnnnnnnwpttwoy
tjiyossssssssssssssssssspthwoy
tjizzzzalllllllllllleeeeehhwoy
tjuuqqqqqqqqqqqqqqqqqeeeeehnod
txxxxxoooooooooooooooffffffnod
reeeeevvvvvvvvvvvvvvvvvvvvvvod
       gggggggoooooooooooooood
Here is how it is generated,

There was a zealous fox who enjoyed the pangram "The quick brown fox jumps over the lazy dog". One day he was in the center of an outward spiral and decided to jump in it and paint along.
He would like to go through the pangram from the beginning to the end, and if a letter is the n-th letter in the alphabet he would like to paint it n times.
However, the fox was not very good at making turns on corners, so upon reaching each corner he also had to stop and switch to the next letter.
He also decided to repeat the pangram thrice to emphasize that he is the quick brown fox.
Your job is to show how the spiral would look like after the fox painted all those letters.
(Plain version without story-telling)

The famous pangram "The quick brown fox jumps over the lazy dog" is repeated thrice, with the spaces removed and all letters in lower case, to generate

thequickbrownfoxjumpsoverthelazydogthequickbrownfoxjumpsoverthelazydogthequickbrownfoxjumpsoverthelazydog
The spiral starts from the center and begins with the letter "t", it starts by going to the right, and goes outward clockwise. If the current character is the n-th letter in the alphabet, then it switches to the next character whenever

the spiral reaches a corner, or
the current letters is printed exactly n times.
To better illustrate it, I will explain how the spiral related to the first three words "thequickbrown" is generated.

 rooooo
 rquuuw
 bqttiw
 beehiw
 kccciw
nnnnnnw
The fox starts from "t", goes right, reaches the 1st corner, paints it with the "t" and then switches to "h" and goes down, reaches the 2nd corner, switches to "e" and goes left, reaches the 3rd corner, switches to "q" and goes up, reaches the 4th corner, switches to "u" and goes right, reaches a corner and switches to "i", goes down, reaches a corner and switches to "c", goes left, successfully paints 3 "c"s before reaching the next corner, switches to "k" and goes on to the left, reaches a corner right away, switches to "b" and goes up, paints 2 "b"s before reaching the next corner, switches to "r" and goes on upwards, reaches a corner and switches to "o", goes right, then "w", down, "n", left.

Specs
You can take an optional input that contains any standard form of the string

thequickbrownfoxjumpsoverthelazydogthequickbrownfoxjumpsoverthelazydogthequickbrownfoxjumpsoverthelazydog
Your output must be formatted as a string, and must go to STDOUT instead of files or STDERR, with newlines placed correctly. Heading and trailing empty lines do not matter. Heading and trailing spaces in each line are allowed, but need to be be consistent. So if you add 5 spaces before one line of the given text, you'll need to add exactly 5 spaces before each line so that the spiral looks the same.

This is code-golf, the lowest number of bytes wins.

As usual, default loopholes apply here.

Explanations are welcome, although not necessary.

Title edited to make it a pangram per comment by caird coinheringaahing.

The lazy dog is too lazy to appear in the story.

I am aiming at creating a string challenge in which the letter to output cannot be computed by simple functions of the coordinates.

*/

#include <stdio.h>

void
output()
{
	static const char *spiral[] = {
		"heeeeellllllllllllazzzzzzzzzzz",
		"hummmmmmmmmmmmmppppppppppppppy",
		"hubrrrrrrrrrrrrrrrrrrooooooosy",
		"hukyddddoooooooooooooooggggwsy",
		"hukyveeeeerrrrrrrrrrrrrrrrtwsy",
		"hukyvxjjjjjjjjjjuuuuuuuuuttwsy",
		"hukyvxkbbrrrrrrrrrrrrrrrmttwsy",
		"hukyvxkogggggggttttttttomttwsy",
		"tukyvokoellllllllllllahomttwsy",
		"tukyvokoeovvvvvvvvvvvzhomttwsy",
		"tukyvocoeoummmmmmmmmezhomttwsy",
		"tukyvocoeoufooooooopezhomttwsy",
		"tukyvocohoufroooooxpezhomttwsy",
		"tukyvoiohoufrquuuwxpezhomttwsy",
		"tucyvoiohoufbqttiwxpezhomttwsy",
		"tucyvoiohoufbeehiwxprzhomttwsy",
		"tucyvoiohoufkccciwxprzeomttwsy",
		"tjiyvoidhounnnnnnwxprzeomttwsy",
		"tjiyvoidhojjjjjjjjxprzeomttwsy",
		"tjiyvoidhssssssssssprzeopttwsy",
		"tjiyvoidttttttttttttrzeopttwsy",
		"tjiyvoiyyyyyyyyyyyyyyzqopttwoy",
		"tjiyvouuuuuuuuuuuuuuuuqwpttwoy",
		"tjiyvffffnnnnnnnnnnnnnnwpttwoy",
		"tjiyossssssssssssssssssspthwoy",
		"tjizzzzalllllllllllleeeeehhwoy",
		"tjuuqqqqqqqqqqqqqqqqqeeeeehnod",
		"txxxxxoooooooooooooooffffffnod",
		"reeeeevvvvvvvvvvvvvvvvvvvvvvod",
		"       gggggggoooooooooooooood",
		NULL,
	};

	size_t index;

	for (index = 0; spiral[index]; index++)
		puts(spiral[index]);
}

int
main()
{
	output();
	return 0;
}
