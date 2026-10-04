/*

Task
Your task is to write a program that will take input, and then output the lyrics to We Are Number One, changing specific words. The input will contain both the words to be changed, and the replacement word.

Input
The input will be in the following format:

one, two\n
net, villain\n
(\n is a newline, it's not actually visible.) The input is assured to be this format, and the first word will always be a word the lyrics contains. But you can take input in whatever format you prefer the most.

Output
Your output will be the entire We Are Number One lyrics, but with the words that are given in the input swapped.

Original lyrics:

Hey!
We are Number One
Hey!
We are Number One


Now listen closely
Here's a little lesson in trickery
This is going down in history
If you wanna be a Villain Number One
You have to chase a superhero on the run
Just follow my moves, and sneak around
Be careful not to make a sound
(Shh)
(CRUNCH)
(No, don't touch that!)



We are Number One
Hey!
We are Number One
We are Number One



Ha ha ha
Now look at this net, that I just found
When I say go, be ready to throw
Go!
(Throw it on him, not me!)
(Ugh, let's try something else)
Now watch and learn, here's the deal
He'll slip and slide on this banana peel!
(Ha ha ha, gasp! what are you doing!?)



Ba-ba-biddly-ba-ba-ba-ba, ba-ba-ba-ba-ba-ba-ba
We are Number One
Hey!
Ba-ba-biddly-ba-ba-ba-ba, ba-ba-ba-ba-ba-ba-ba
We are Number One
Ba-ba-biddly-ba-ba-ba-ba, ba-ba-ba-ba-ba-ba-ba
We are Number One
Hey!
Ba-ba-biddly-ba-ba-ba-ba, ba-ba-ba-ba-ba-ba-ba
We are Number One
Hey!
Hey!

Source
Rules
The first word per input is assured to be in the lyrics.
Your code must be case-insensitve (one as input will replace One)
Trailing newlines are allowed.
The input may be lower and uppercase, and the resulting output must have the same casing as the provided input.
The input can try to replace e.g. one with one. If you replace it or not, is your choice.
"Words" are sequences of characters seperated by space or commas, not by anything else (e.g. Hyphens), therefore Ba is not a valid input, but Ba-ba-biddly-ba-ba-ba-ba is.
Example case
Input:

one, three
net, villain
Output:

Hey!
We are Number three
Hey!
We are Number three


Now listen closely
Here's a little lesson in trickery
This is going down in history
If you wanna be a Villain Number three
You have to chase a superhero on the run
Just follow my moves, and sneak around
Be careful not to make a sound
(Shh)
(CRUNCH)
(No, don't touch that!)



We are Number three
Hey!
We are Number three
We are Number three



Ha ha ha
Now look at this villain, that I just found
When I say go, be ready to throw
Go!
(Throw it on him, not me!)
(Ugh, let's try something else)
Now watch and learn, here's the deal
He'll slip and slide on this banana peel!
(Ha ha ha, gasp! what are you doing!?)



Ba-ba-biddly-ba-ba-ba-ba, ba-ba-ba-ba-ba-ba-ba
We are Number three
Hey!
Ba-ba-biddly-ba-ba-ba-ba, ba-ba-ba-ba-ba-ba-ba
We are Number three
Ba-ba-biddly-ba-ba-ba-ba, ba-ba-ba-ba-ba-ba-ba
We are Number three
Hey!
Ba-ba-biddly-ba-ba-ba-ba, ba-ba-ba-ba-ba-ba-ba
We are Number three
Hey!
Hey!

Winner
This is code-golf, so the author of the shortest code in bytes wins!

*/

package main

import (
	"fmt"
	"regexp"
	"strings"
)

func main() {
	fmt.Println(rewrite([][2]string{
		{"one", "three"},
		{"net", "villain"},
	}))
}

func rewrite(reps [][2]string) string {
	if len(reps) == 0 {
		return LYRICS
	}

	lut := make(map[string]string)
	pat := "(?i)("
	for _, rep := range reps {
		pat += rep[0] + "|"
		key := strings.ToLower(rep[0])
		lut[key] = rep[1]
	}
	pat = pat[:len(pat)-1] + ")"

	re := regexp.MustCompile(pat)
	return re.ReplaceAllStringFunc(LYRICS, func(match string) string {
		key := strings.ToLower(match)
		return lut[key]
	})
}

const LYRICS = `
Hey!
We are Number One
Hey!
We are Number One


Now listen closely
Here's a little lesson in trickery
This is going down in history
If you wanna be a Villain Number One
You have to chase a superhero on the run
Just follow my moves, and sneak around
Be careful not to make a sound
(Shh)
(CRUNCH)
(No, don't touch that!)



We are Number One
Hey!
We are Number One
We are Number One



Ha ha ha
Now look at this net, that I just found
When I say go, be ready to throw
Go!
(Throw it on him, not me!)
(Ugh, let's try something else)
Now watch and learn, here's the deal
He'll slip and slide on this banana peel!
(Ha ha ha, gasp! what are you doing!?)



Ba-ba-biddly-ba-ba-ba-ba, ba-ba-ba-ba-ba-ba-ba
We are Number One
Hey!
Ba-ba-biddly-ba-ba-ba-ba, ba-ba-ba-ba-ba-ba-ba
We are Number One
Ba-ba-biddly-ba-ba-ba-ba, ba-ba-ba-ba-ba-ba-ba
We are Number One
Hey!
Ba-ba-biddly-ba-ba-ba-ba, ba-ba-ba-ba-ba-ba-ba
We are Number One
Hey!
Hey!
`
