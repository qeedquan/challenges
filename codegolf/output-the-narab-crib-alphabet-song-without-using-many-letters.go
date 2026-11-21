/*

Your goal is to write a program that takes no input and outputs the following text:

ca e na ŋa va o sa;
þa ša ra la ła.
ma a pa fa ga ta ča;
în ja i da ða.
ar ħo ên ôn ân uħo;
carþ taŋ neŋ es nem.
elo cenvos.
But there's a catch: for each letter (any character whose general category in Unicode starts with L) in your source, you get a penalty of 20 characters! (For reference, the text to be printed has 81 letters.)

The Perl 6 code below has 145 bytes and 84 letters, so it gets a score of 1,845:

say "ca e na ŋa va o sa;
þa ša ra la ła.
ma a pa fa ga ta ča;
în ja i da ða.
ar ħo ên ôn ân uħo;
carþ taŋ neŋ es nem.
elo cenvos."
The code below has 152 bytes and 70 letters, so it gets a score of 1,552:

$_="C e N ŋa V o S;
Þ Š R L Ł.
M a P F G T Č;
în J i D Ð.
ar ħo ên ôn ân uħo;
Crþ Tŋ neŋ es nem.
elo cenvos.";s:g/<:Lu>/{$/.lc~'a'}/;.say
Standard loopholes are forbidden.

Originally, I thought of forbidding letters altogether, but I don't think there are many languages that make this possible. You're more than welcome to try.

(ŋarâþ crîþ [ˈŋaɹa̰θ kɹḭθ] is one of my conlangs. I wanted to capitalise its name here, but I get the ugly big eng here. Oh well, the language doesn't use capital letters in its romanisation anyway.)

Edit: realised that one of the lines is wrong, but I'll keep it since there are already answers. The correct version of the third line is ma a fa ga pa ta ča; at your choice, you may choose to produce the corrected text instead.

*/

package main

import "fmt"

func main() {
	fmt.Println(POEM)
}

const POEM = `ca e na ŋa va o sa;
þa ša ra la ła.
ma a pa fa ga ta ča;
în ja i da ða.
ar ħo ên ôn ân uħo;
carþ taŋ neŋ es nem.
elo cenvos.`
