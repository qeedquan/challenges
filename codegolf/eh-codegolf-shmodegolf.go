/*

This challenge is about implementing Shm-reduplication, originating in Yiddish, where one takes a word, duplicates it, and replaces the first syllable in the second word with "Shm" in order to indicate that one does not care. Some examples include:

"Isn't the baby cute?", "Eh, baby shmaby"
"Come buy from my store, we have a sale!", "Pff, sale shmale"
"I got this smartphone yesterday, isn't it cool?", "Meh, smartphone shmartphone"
Rules
In the real world there are a bunch of special cases, but for this challenge we will use rules that describe a simplified version of the full linguistic phenomenon that is more suitable for programming:

Consonants up to first vowel are replaced by "shm".
Prepend shm to words beginning with vowels.
If a word contains no vowels it is returned unchanged. No vowel, no shm.
The vowels are: a, e, i, o, u.
The input will be restricted to lowercase letters.
The output should be a lowercase string containing the reduplicated version of the input. If the input is "string" the output should be "shming".
This is code golf, shortest code wins!

Example solution (ungolfed python)
This is an example of code that would solve the challenge:

def function_shmunction(string):
    vowels = "aeiou"
    for letter in string:
        if letter in vowels:
            index = string.index(letter)
            shming = "shm" + string[index:]
            return shming
    return string

Test cases
function -> shmunction
stellar -> shmellar
atypical -> shmatypical
wwwhhhat -> shmat
aaaaaaaaaa -> shmaaaaaaaaaa
lrr -> lrr
airplane -> shmairplane
stout -> shmout
why -> why

An answer has been accepted since there haven't been any new responses in a while, but feel free to add more!

*/

package main

func main() {
	assert(shmunction("function") == "shmunction")
	assert(shmunction("stellar") == "shmellar")
	assert(shmunction("atypical") == "shmatypical")
	assert(shmunction("wwwhhhat") == "shmat")
	assert(shmunction("aaaaaaaaaa") == "shmaaaaaaaaaa")
	assert(shmunction("lrr") == "lrr")
	assert(shmunction("airplane") == "shmairplane")
	assert(shmunction("stout") == "shmout")
	assert(shmunction("why") == "why")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func shmunction(s string) string {
	for i, r := range s {
		switch r {
		case 'a', 'e', 'i', 'o', 'u':
			return "shm" + s[i:]
		}
	}
	return s
}
