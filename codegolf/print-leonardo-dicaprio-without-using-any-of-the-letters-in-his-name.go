/*

The Oscars are coming up soon and we all know who's going to win Best Actor in a Leading Role this year right? The great Leonardo DiCaprio of course! Despite his superb performances in all of his films during his career, he has yet to win an Academy Award. So as tribute and as a way to wish him luck during the Awards Ceremony this year, your task is to print "Leonardo DiCaprio" (without quotes and case-sensitive) without using any letters in his name in your code. This is code-golf so the shortest code wins. Score is based on your code in bytes. Any language is acceptable.

-100 Points if you can print his name on an ascii plate like so (Best Actor not required):

 _____________________________
|                             |
|      Leonardo DiCaprio      |
|         Best Actor          |
|_____________________________|
Edit For clarification, the rule for not "using any letters in his name in your code" is case-insensitive.

Also another edit you may use spaces.

*/

package main

import (
	"fmt"
	"html"
)

func main() {
	fmt.Println(html.UnescapeString(GUY))
}

const GUY = `
╔═════════════════╗
║&#76;&#101;&#111;&#110;&#97;&#114;&#100;&#111;&#32;&#68;&#105;&#67;&#97;&#112;&#114;&#105;&#111;║
╚═════════════════╝
`
