/*

Output the provided table of English pronouns exactly, in as few bytes as possible.

Code rules
The code will take no input
The table is tab-delimited
Each line begins with a single tab \t if there is no row heading
Each line ends in a single newline \n (not \r\n), including the last line
There are four tabs between "Plural" and the newline (Plural\t\t\t\t\n) because it refers to the next four columns as well, but no other line has trailing tabs or spaces
Spelling rules
There is no Possessive Pronoun for "it", so the data is "-"
The only pronoun to use an apostrophe is "one's". "It's" means "it is" or "is has" and is a contraction, not a pronoun
Some people use "themself" for the singular, gender non-specific, third person, but in this table it is "themselves"
This table is not complete; other non-standard, alternate and rare forms are not included

Output
Use this link to check your output.

Pretty-printed (do not output this!)
                Singular                                                  Plural
                                   Possessive   Possessive                                   Possessive   Possessive
                Subject   Object   Determiner   Pronoun      Reflexive    Subject   Object   Determiner   Pronoun      Reflexive
First Person    I         me       my           mine         myself       we        us       our          ours         ourselves
Second Person   you       you      your         yours        yourself     you       you      your         yours        yourselves
Third Person    he        him      his          his          himself      they      them     their        theirs       themselves
                she       her      her          hers         herself
                it        it       its          -            itself
                one       one      one's        one's        oneself
                they      them     their        theirs       themselves

*/

package main

import "fmt"

func main() {
	fmt.Println(TABLE)
}

const TABLE = `
	Singular					Plural
	Subject	Object	Possessive Determiner	Possessive Pronoun	Reflexive	Subject	Object	Possessive Determiner	Possessive Pronoun	Reflexive
First Person	I	me	my	mine	myself	we	us	our	ours	ourselves
Second Person	you	you	your	yours	yourself	you	you	your	yours	yourselves
Third Person	he	him	his	his	himself	they	them	their	theirs	themselves
	she	her	her	hers	herself
	it	it	its	-	itself
	one	one	one's	one's	oneself
	they	them	their	theirs	themselves
`
