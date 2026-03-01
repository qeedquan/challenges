/*

Given a compressed string s made of printable ASCII characters (32 to 126), your task is to print or return the original text by applying this simple decompression algorithm:

Start with k=0
Look for the first occurrence of the digit k in s and the sub-string s′ consisting of the 2 characters preceding it. If the pattern is not found, stop here.
Remove the first occurrence of the digit k.
Replace all other occurrences with s′.
Increment k. If it's less than or equal to 9, resume at step 2.

Example 1
Input: bl3a2h1 00001!

The first occurrence of "0" is preceded by "1 ". We remove the first occurrence of "0" and replace all other ones with "1 ", leading to "bl3a2h1 1 1 1 1!".

We do the same thing for "1", with the sub-string "2h". This gives "bl3a2h 2h 2h 2h 2h!".

We do the same thing for "2", with the sub-string "3a". This gives "bl3ah 3ah 3ah 3ah 3ah!".

We do the same thing for "3", with the sub-string "bl". This gives "blah blah blah blah blah!", which is the final output because there are no more digits in s.

Example 2
Input: Peter Pipe1r pick0ed a 10 of pi0led 1p1rs.

The first step uses the sub-string "ck" and gives:

Peter Pipe1r picked a 1ck of pickled 1p1rs.
The second and final step uses the sub-string "pe" and gives:

Peter Piper picked a peck of pickled peppers.

Rules
The input string is guaranteed to be valid. In particular, there will always be at least 2 characters before the first occurrence of a digit.
However, the input string may not be compressed at all, in which case it must be returned as-is.
The uncompressed text is guaranteed not to contain any digit.
This is code-golf.
Test cases

Input
Short test cases (one per line):

Hello, World!
antidis0establ0hmentarian0m
bl3a2h1 00001!
A AB4 43C22D11E00F0FG
Peter Pipe1r pick0ed a 10 of pi0led 1p1rs.
The 7first 9rul7of Fi6g5h98C3l2ub1 is: You4 do no9talk ab495210. Th7second rul7of 50 is: Y4 do no9talk ab4950.
Longer test case (first paragraph of the Adventures of Sherlock Holmes / A Scandal in Bohemia, from Project Gutenberg):

To Sher6lock Holmes 3she 9i3a8lway3_the_ woman. I h4av9seldom4eard4im mention246 und68ny oth6 name. In4i3eye3sh9eclipses8nd predomin5ate3t7h19whol9of46 sex. It 0wa3not1at49felt8ny emoti28k57o lov9for Iren9Adl6. All emoti2s,8nd1a029particularly, w69abhorrent7o4i3cold, precise, but8dmirably balanced m5d. H9was, I7ak9it,19mos0p6fec0reas25g8nd obs6v5g mach59that19world4a3seen; but,8s8 lov6,49would4av9placed4imself 58 fals9positi2. H9nev6 spok9of19soft6 passi2s, sav9with8 gib9and8 sne6. They w69admirabl9th5g3for19obs6v6--excellen0for draw5g19veil from men'3motives8nd8cti2s. Bu0for19tra5ed reas267o8dmi0such 5trusi235to4i3own delicat9and f5ely8djusted7emp6amen0was7o 5troduc9a distract5g factor which might1row8 doub0up28ll4i3mental results. Gri058 sensitiv95strument, or8 crack 5 29of4i3own4igh-pow6 lenses, would no0b9mor9disturb5g1an8 str2g emoti2 58 natur9such8s4is. And yet169wa3bu029woman7o4im,8nd1a0woman was19lat9Iren9Adl6, of dubious8nd questi2abl9memory.

Output
Hello, World!
antidisestablishmentarianism
blah blah blah blah blah!
A AB ABC ABCD ABCDE ABCDEF ABCDEFG
Peter Piper picked a peck of pickled peppers.
The first rule of Fight Club is: You do not talk about Fight Club. The second rule of Fight Club is: You do not talk about Fight Club.
Longer one:

To Sherlock Holmes she is always _the_ woman. I have seldom heard him mention her under any other name. In his eyes she eclipses and predominates the whole of her sex. It was not that he felt any emotion akin to love for Irene Adler. All emotions, and that one particularly, were abhorrent to his cold, precise, but admirably balanced mind. He was, I take it, the most perfect reasoning and observing machine that the world has seen; but, as a lover, he would have placed himself in a false position. He never spoke of the softer passions, save with a gibe and a sneer. They were admirable things for the observer--excellent for drawing the veil from men's motives and actions. But for the trained reasoner to admit such intrusions into his own delicate and finely adjusted temperament was to introduce a distracting factor which might throw a doubt upon all his mental results. Grit in a sensitive instrument, or a crack in one of his own high-power lenses, would not be more disturbing than a strong emotion in a nature such as his. And yet there was but one woman to him, and that woman was the late Irene Adler, of dubious and questionable memory.

*/

package main

import (
	"strings"
)

func main() {
	assert(decompress("Hello, World!") == "Hello, World!")
	assert(decompress("antidis0establ0hmentarian0m") == "antidisestablishmentarianism")
	assert(decompress("bl3a2h1 00001!") == "blah blah blah blah blah!")
	assert(decompress("A AB4 43C22D11E00F0FG") == "A AB ABC ABCD ABCDE ABCDEF ABCDEFG")
	assert(decompress("Peter Pipe1r pick0ed a 10 of pi0led 1p1rs.") == "Peter Piper picked a peck of pickled peppers.")
	assert(decompress("The 7first 9rul7of Fi6g5h98C3l2ub1 is: You4 do no9talk ab495210. Th7second rul7of 50 is: Y4 do no9talk ab4950.") == "The first rule of Fight Club is: You do not talk about Fight Club. The second rule of Fight Club is: You do not talk about Fight Club.")
	assert(decompress("To Sher6lock Holmes 3she 9i3a8lway3_the_ woman. I h4av9seldom4eard4im mention246 und68ny oth6 name. In4i3eye3sh9eclipses8nd predomin5ate3t7h19whol9of46 sex. It 0wa3not1at49felt8ny emoti28k57o lov9for Iren9Adl6. All emoti2s,8nd1a029particularly, w69abhorrent7o4i3cold, precise, but8dmirably balanced m5d. H9was, I7ak9it,19mos0p6fec0reas25g8nd obs6v5g mach59that19world4a3seen; but,8s8 lov6,49would4av9placed4imself 58 fals9positi2. H9nev6 spok9of19soft6 passi2s, sav9with8 gib9and8 sne6. They w69admirabl9th5g3for19obs6v6--excellen0for draw5g19veil from men'3motives8nd8cti2s. Bu0for19tra5ed reas267o8dmi0such 5trusi235to4i3own delicat9and f5ely8djusted7emp6amen0was7o 5troduc9a distract5g factor which might1row8 doub0up28ll4i3mental results. Gri058 sensitiv95strument, or8 crack 5 29of4i3own4igh-pow6 lenses, would no0b9mor9disturb5g1an8 str2g emoti2 58 natur9such8s4is. And yet169wa3bu029woman7o4im,8nd1a0woman was19lat9Iren9Adl6, of dubious8nd questi2abl9memory.") == "To Sherlock Holmes she is always _the_ woman. I have seldom heard him mention her under any other name. In his eyes she eclipses and predominates the whole of her sex. It was not that he felt any emotion akin to love for Irene Adler. All emotions, and that one particularly, were abhorrent to his cold, precise, but admirably balanced mind. He was, I take it, the most perfect reasoning and observing machine that the world has seen; but, as a lover, he would have placed himself in a false position. He never spoke of the softer passions, save with a gibe and a sneer. They were admirable things for the observer--excellent for drawing the veil from men's motives and actions. But for the trained reasoner to admit such intrusions into his own delicate and finely adjusted temperament was to introduce a distracting factor which might throw a doubt upon all his mental results. Grit in a sensitive instrument, or a crack in one of his own high-power lenses, would not be more disturbing than a strong emotion in a nature such as his. And yet there was but one woman to him, and that woman was the late Irene Adler, of dubious and questionable memory.")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func decompress(s string) string {
	for i := '0'; i <= '9'; i++ {
		n := strings.IndexRune(s, i)
		if n >= 2 {
			t := s[n-2 : n]
			s = s[:n] + s[n+1:]
			s = strings.Replace(s, string(i), t, -1)
		}
	}
	return s
}
