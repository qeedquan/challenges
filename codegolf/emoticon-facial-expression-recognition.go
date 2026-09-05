/*

Write a program that accepts as input an emoticon and ouputs if the emoticon is happy or sad.

The program accepts a string as input or parameter, and should display the string "happy" if the input is in the happy emoticon list, or "sad" if the input is in the sad emoticon list.

You can assume the input is always a valid (happy or sad) emoticon, with no space or tabs around.

Here is a space separated list of happy emoticons:

:-) :) :D :o) :] :3 :c) :> =] 8) =) :} :^) :-D 8-D 8D x-D xD X-D XD =-D =D =-3 =3 B^D (-: (: (o: [: <: [= (8 (= {: (^:
Here is a space separated list of sad emoticons:

>:[ :-( :( :-c :c :-< :< :-[ :[ :{ 8( 8-( ]:< )-: ): >-: >: ]-: ]: }: )8 )-8
This is code-golf, so the shortest program wins.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(classify(":-)"))
	fmt.Println(classify(")-:"))
}

func classify(emoticon string) string {
	const HAPPY = `:-) :) :D :o) :] :3 :c) :> =] 8) =) :} :^) :-D 8-D 8D x-D xD X-D XD =-D =D =-3 =3 B^D (-: (: (o: [: <: [= (8 (= {: (^:`
	const SAD = `>:[ :-( :( :-c :c :-< :< :-[ :[ :{ 8( 8-( ]:< )-: ): >-: >: ]-: ]: }: )8 )-8`

	index := strings.Index(HAPPY, emoticon)
	if index >= 0 {
		return "happy"
	}

	index = strings.Index(SAD, emoticon)
	if index >= 0 {
		return "sad"
	}

	return "unknown"
}
