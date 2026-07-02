/*

Overview
I have a sample of 10 quotes. You will receive as input to your program one of these quotes, however all the vowels (aeiou) will be replaced with the letter e.

You must output the original quote as it appears in the below code block. Newlines can be included or excluded at your discretion.

Code golf rules / scoring.

Quotes
when in doubt, say nothing and move on.
what if every day, every human had a 1 percent chance of being turned into a turkey, and every turkey had a 1 percent chance of being turned into a human?
if you were going to work today to a factory that you owned to lay off all of your staff, my car would not be the car to make that journey in.
i've always wanted to kick a duck up the arse.
your affection is not meaningless to me, puny one. i shall devour you another day.
good. proud. i am scary space monster. you are leaky space blob.
i started the day with some nothin' tea. nothin' tea is easy to make. first, get some hot water, then add nothin'.
why do today what you can still do in a quarter of a million years?
i don't know why, because it's one of those things i'm not contractually obligated to care about.
nobody wanted to think about the limited range of fates possible for such a speck of human dust in the vast face of the cosmos.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	tests := []string{
		"when en deebt, sey netheng end meve en.",
		"whet ef every dey, every hemen hed e 1 percent chence ef beeng terned ente e terkey, end every terkey hed e 1 percent chence ef beeng terned ente e hemen?",
		"ef yee were geeng te werk tedey te e fectery thet yee ewned te ley eff ell ef yeer steff, my cer weeld net be the cer te meke thet jeerney en.",
		"e've elweys wented te keck e deck ep the erse.",
		"yeer effecteen es net meenengless te me, peny ene. e shell deveer yee enether dey.",
		"geed. preed. e em scery spece menster. yee ere leeky spece bleb.",
		"e sterted the dey weth seme nethen' tee. nethen' tee es eesy te meke. ferst, get seme het weter, then edd nethen'.",
		"why de tedey whet yee cen stell de en e qeerter ef e melleen yeers?",
		"e den't knew why, beceese et's ene ef these thengs e'm net centrecteelly eblegeted te cere ebeet.",
		"nebedy wented te thenk ebeet the lemeted renge ef fetes pesseble fer sech e speck ef hemen dest en the vest fece ef the cesmes.",
	}

	for _, test := range tests {
		fmt.Println(TABLE[test])
	}
}

func build() map[string]string {
	quotes := []string{
		"when in doubt, say nothing and move on.",
		"what if every day, every human had a 1 percent chance of being turned into a turkey, and every turkey had a 1 percent chance of being turned into a human?",
		"if you were going to work today to a factory that you owned to lay off all of your staff, my car would not be the car to make that journey in.",
		"i've always wanted to kick a duck up the arse.",
		"your affection is not meaningless to me, puny one. i shall devour you another day.",
		"good. proud. i am scary space monster. you are leaky space blob.",
		"i started the day with some nothin' tea. nothin' tea is easy to make. first, get some hot water, then add nothin'.",
		"why do today what you can still do in a quarter of a million years?",
		"i don't know why, because it's one of those things i'm not contractually obligated to care about.",
		"nobody wanted to think about the limited range of fates possible for such a speck of human dust in the vast face of the cosmos.",
	}

	replacer := strings.NewReplacer("a", "e", "i", "e", "o", "e", "u", "e")
	table := make(map[string]string)
	for _, value := range quotes {
		key := replacer.Replace(value)
		table[key] = value
	}
	return table
}

var TABLE = build()
