/*

Challenge
There is an old, popular riddle:

Find an English word with 8 letters that, taken away one letter, creates a new valid word. Repeat that until there are no letters left.

Example solution:

starting
staring
string
sting
sing
sin
in
I
Your task is to write a program, which takes a dictionary and outputs the longest word, that still occurs in the dictionary after repeatedly taking away a letter.

Rules
All words will be lower case and contain only ASCII-letters
If multiple valid words have the same length you can output any one of those
The dictionary will never be empty
If there isn't any solution in the dictionary, then you have to output nothing/return an empty list/a falsey value
You're allowed to output a list representing the process of removing each letter (eg.['this', 'his', 'is', 'i'])
Default Loopholes apply
This is code-golf, so the shortest answer wins!
Examples
In: ['this', 'hat', 'his', 'hi', 'is', 'i', 'a', 'at']
Out: this

In: ['pings', 'aid', 'ping', 'ad', 'i', 'in', 'a']
Out: aid

In: ['a', 'ab', 'bac']
Out: ab

In: ['a', 'aa', 'aaaa']
Out: aa

In: ['as', 'i', 'his', 'that', 'ping', 'pin', 'in', 'was', 'at', 'this', 'what', 'is', 'it', 'and', 'a', 'in', 'can', 'if', 'an', 'hand', 'land', 'act', 'ask', 'any', 'part', 'man', 'mean', 'many', 'has', 'stand', 'farm', 'eat', 'main', 'wind', 'boat', 'ran', 'heat', 'east', 'warm', 'fact', 'fast', 'rain', 'art', 'heart', 'am', 'arm', 'sit', 'train', 'sat', 'gas', 'least', 'fit', 'flat', 'cat', 'bit', 'coast', 'sand', 'beat', 'hit', 'party', 'wing', 'wash', 'bat', 'meat', 'suit', 'fat', 'meant', 'coat', 'band', 'win', 'seat', 'hat', 'salt']
Possible outputs:
1. stand (stand -> sand -> and -> an -> a)
2. heart (heart -> heat -> eat -> at -> a)
3. train (train -> rain -> ran -> an -> a)
4. least (least -> east -> eat -> at -> a)
5. coast (coast -> coat -> cat -> at -> a)
6. party (party -> part -> art -> at -> a)
7. meant (meant -> meat -> eat -> at -> a)

*/

package main

import (
	"sort"
	"strings"
)

func main() {
	assert(longestword(map[string]bool{
		"this": true,
		"hat":  true,
		"his":  true,
		"hi":   true,
		"is":   true,
		"i":    true,
		"a":    true,
		"at":   true,
	}) == "this")

	assert(longestword(map[string]bool{
		"pings": true,
		"aid":   true,
		"ping":  true,
		"ad":    true,
		"i":     true,
		"in":    true,
		"a":     true,
	}) == "aid")

	assert(longestword(map[string]bool{
		"a":   true,
		"ab":  true,
		"bac": true,
	}) == "ab")

	assert(longestword(map[string]bool{
		"a":    true,
		"aa":   true,
		"aaaa": true,
	}) == "aa")

	assert(longestword(map[string]bool{
		"as":    true,
		"i":     true,
		"his":   true,
		"that":  true,
		"ping":  true,
		"pin":   true,
		"in":    true,
		"was":   true,
		"at":    true,
		"this":  true,
		"what":  true,
		"is":    true,
		"it":    true,
		"and":   true,
		"a":     true,
		"can":   true,
		"if":    true,
		"an":    true,
		"hand":  true,
		"land":  true,
		"act":   true,
		"ask":   true,
		"any":   true,
		"part":  true,
		"man":   true,
		"mean":  true,
		"many":  true,
		"has":   true,
		"stand": true,
		"farm":  true,
		"eat":   true,
		"main":  true,
		"wind":  true,
		"boat":  true,
		"ran":   true,
		"heat":  true,
		"east":  true,
		"warm":  true,
		"fact":  true,
		"fast":  true,
		"rain":  true,
		"art":   true,
		"heart": true,
		"am":    true,
		"arm":   true,
		"sit":   true,
		"train": true,
		"sat":   true,
		"gas":   true,
		"least": true,
		"fit":   true,
		"flat":  true,
		"cat":   true,
		"bit":   true,
		"coast": true,
		"sand":  true,
		"beat":  true,
		"hit":   true,
		"party": true,
		"wing":  true,
		"wash":  true,
		"bat":   true,
		"meat":  true,
		"suit":  true,
		"fat":   true,
		"meant": true,
		"coat":  true,
		"band":  true,
		"win":   true,
		"seat":  true,
		"hat":   true,
		"salt":  true,
	}) == "coast")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func longestword(dictionary map[string]bool) string {
	words := []string{}
	for word := range dictionary {
		words = append(words, word)
	}
	sort.Strings(words)

	result := ""
	maxlength := 0
	for _, word := range words {
		length := len(wordpath(dictionary, word))
		if length > maxlength {
			result, maxlength = word, length
		}
	}
	return result
}

func wordpath(dictionary map[string]bool, word string) []string {
	if len(word) == 0 {
		return []string{}
	}

	match, ok := lookup(dictionary, word)
	if !ok {
		return []string{}
	}

	result := []string{match}
	maxpath := []string{}
	for i := 0; i < len(word); i++ {
		nextword := word[:i] + word[i+1:]
		path := wordpath(dictionary, nextword)
		if len(path) > len(maxpath) {
			maxpath = path
		}
	}
	if len(maxpath) != 0 {
		result = append(result, maxpath...)
	}
	return result
}

func lookup(dictionary map[string]bool, word string) (string, bool) {
	if dictionary[word] {
		return word, true
	}

	upper := strings.ToUpper(word)
	if dictionary[upper] {
		return upper, true
	}

	lower := strings.ToLower(word)
	if dictionary[lower] {
		return lower, true
	}

	return "", false
}
