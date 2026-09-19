/*

Being a bald man myself, I know the feeling of needing to keep it clean shaven. Nothing worse that a stray hair waving in the wind.

You will be given a string(x). Clean shaved head is shown as "-" and stray hairs are shown as "/". Your task is to check the head for stray hairs and get rid of them.

You should return the original string, but with any stray hairs removed. Keep count ot them though, as there is a second element you need to return:

0 hairs --> "Clean!"
1 hair --> "Unicorn!"
2 hairs --> "Homer!"
3-5 hairs --> "Careless!"
>5 hairs --> "Hobo!"

So for this head: "------/------" you shoud return:

["-------------", "Unicorn"]

*/

package main

import (
	"strings"
)

func main() {
	assert(bald("-----") == [2]string{"-----", "Clean!"})
	assert(bald("/---------") == [2]string{"----------", "Unicorn!"})
	assert(bald("/------/---") == [2]string{"-----------", "Homer!"})
	assert(bald("/----/--/---") == [2]string{"------------", "Careless!"})
	assert(bald("//////---------") == [2]string{"---------------", "Hobo!"})
	assert(bald("") == [2]string{"", "Clean!"})
	assert(bald("------/------") == [2]string{"-------------", "Unicorn!"})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bald(cut string) [2]string {
	kind := []string{"Clean!", "Unicorn!", "Homer!", "Careless!", "Careless!", "Careless!"}
	tokens := strings.Split(cut, "/")
	length := len(tokens) - 1
	if length < 0 {
		return [2]string{}
	}
	style := "Hobo!"
	if length < len(kind) {
		style = kind[length]
	}
	return [2]string{
		strings.Repeat("-", len(cut)),
		style,
	}
}
