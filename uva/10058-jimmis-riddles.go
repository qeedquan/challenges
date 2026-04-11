/*

Little Jimmy is only three years old but appears to be more intelligent than even Sir Isaac Newton at
the age of three. People say that Jimmy could count up to ten when he was a child of ten months.
His field of interest changes with his age and at present he is researching on how to trouble his mother
scientifically. He has a book of 5000 riddles and applies them every now and then. For example, if his
mother asks him Will you stop watching Tom and Jerry? he will say tom hates jerry, jimmy hates tom
which means, yes I will. Obviously his mother is in all sorts of trouble.
However, Jimmy is considerate. After all, he knows that his days will not be very smooth if he
continues annoying his mother this way. So he taught her a number of ridiculous (riddle calculus)
formulas so that she can quickly interpret Jimmys riddles. But, she was a student of history and doesnt
know much about ridiculous formulas. So, you are to help her to get out of this trouble. You are
to write a program that will read a number of riddles and, by using a number of ridiculous formulas,
determine what they mean. The formulas are given below:
STATEMENT = ACTION | STATEMENT , ACTION
ACTION = ACTIVE_LIST VERB ACTIVE_LIST
ACTIVE_LIST = ACTOR | ACTIVE_LIST and ACTOR
ACTOR = NOUN | ARTICLE NOUN
ARTICLE = a | the
NOUN = tom | jerry | goofy | mickey | jimmy | dog | cat | mouse
VERB = hate | love | know | like | VERBs
If a riddle is a valid ridiculous calculus statement, it means “YES I WILL”; otherwise it means “NO
I WON’T”.

Input
Input file will contain a number of riddles each on a different line. Each riddle will consist of lowercase
alphabetic characters and comma(s) only. The riddle may contain words not mentioned in the formulas.
For each riddle, you are to determine what it means.
Output
For each riddle the output will be ‘YES I WILL’ if the riddle is a valid ridiculous calculus statement
and ‘NO I WON'T’ otherwise.
The output for each riddle is to be on a separate line.

Sample Input
the dog and a cat know goofy
jimmy kills tom
goofy hate mouse jerry
tom hates jerry , jimmy hates tom

Sample Output
YES I WILL
NO I WON'T
NO I WON'T
YES I WILL

*/

package main

import (
	"regexp"
)

func main() {
	assert(match("the dog and a cat know goofy") == "YES I WILL")
	assert(match("jimmy kills tom") == "NO I WON'T")
	assert(match("goofy hate mouse jerry") == "NO I WON'T")
	assert(match("tom hates jerry , jimmy hates tom") == "YES I WILL")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func match(input string) string {
	regex := generate()
	if regex.MatchString(input) {
		return "YES I WILL"
	}
	return "NO I WON'T"
}

func generate() *regexp.Regexp {
	const (
		VERB        = "(hate|love|know|like)s*"
		NOUN        = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)"
		ARTICLE     = "(a|the)"
		ACTOR       = "(" + NOUN + "|" + ARTICLE + " " + NOUN + ")"
		ACTIVE_LIST = "(" + ACTOR + " and )*" + ACTOR
		ACTION      = ACTIVE_LIST + " " + VERB + " " + ACTIVE_LIST
		STATEMENT   = ACTION + "( , " + ACTION + ")*"
	)
	return regexp.MustCompile("^" + STATEMENT + "$")
}
