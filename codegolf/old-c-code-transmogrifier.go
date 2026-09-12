/*

*What is a transmogrifier?

In the C programming language, there are formations called digraphs and trigraphs that are two and three characters sequences that evaluate to less common characters. For example, you can use ??- if your keyboard doesn't have ~.

Given text, replace all instances of the following digraphs and trigraphs (left side) with the correct, shorter, golfed character (right side).

??=  #
??/  \
??'  ^
??(  [
??)  ]
??!  |
??<  {
??>  }
??-  ~
<:   [
:>   ]
<%   {
%>   }
%:   #
Source

Input
Input is ASCII text. Trailing newline allowed. Does not need to be valid C code.

Output
Output is the same text, with all instances of the above digraphs and trigraphs replaced with the shortened version, evaluated left to right. Trailing newline allowed. Does not need to be valid C code.

Test Cases
=> separates input and output.

if (true ??!??! false) { => if (true || false) {

??-arr.indexOf(n) => ~arr.indexOf(n)

function f(??) { console.log('test??'); } => function f(] { console.log('test^); }

/* comment :> :) *??/ => /* comment ] :) *\

%:What am I doing??!!??` => `#What am I doing|!??

??(??)??(??) <:-- not a palindrome => [][] [-- not a palindrome

?????????? => ??????????

int f(int??(??) a) ??< return a??(0??)??'a??(1??) + "??/n"; ??> => int f(int[] a) { return a[0]^a[1] + "\n"; }

??<:>??<% => {]{%

<:> => [>

<::> => []

:>> => ]>

#\^[]|{}~ => #\^[]|{}~

: > => : >

??=%: => ##

*/

package main

import "strings"

func main() {
	assert(expand(`if (true ??!??! false) {`) == `if (true || false) {`)
	assert(expand(`??-arr.indexOf(n)`) == `~arr.indexOf(n)`)
	assert(expand(`function f(??) { console.log('test??'); }`) == `function f(] { console.log('test^); }`)
	assert(expand(`/* comment :> :) *??/`) == `/* comment ] :) *\`)
	assert(expand("%:What am I doing??!!??") == "#What am I doing|!??")
	assert(expand(`??(??)??(??) <:-- not a palindrome`) == `[][] [-- not a palindrome`)
	assert(expand(`??????????`) == `??????????`)
	assert(expand(`int f(int??(??) a) ??< return a??(0??)??'a??(1??) + "??/n"; ??>`) == `int f(int[] a) { return a[0]^a[1] + "\n"; }`)
	assert(expand(`??<:>??<%`) == `{]{%`)
	assert(expand(`<:>`) == `[>`)
	assert(expand(`<::>`) == `[]`)
	assert(expand(`:>>`) == `]>`)
	assert(expand(`#\^[]|{}~`) == `#\^[]|{}~`)
	assert(expand(`: >`) == `: >`)
	assert(expand(`??=%:`) == `##`)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func expand(s string) string {
	tab := [][2]string{
		{"??=", "#"},
		{"??/", "\\"},
		{"??'", "^"},
		{"??(", "["},
		{"??)", "]"},
		{"??!", "|"},
		{"??<", "{"},
		{"??>", "}"},
		{"??-", "~"},
		{"<:", "["},
		{":>", "]"},
		{"<%", "{"},
		{"%>", "}"},
		{"%:", "#"},
	}

	for _, t := range tab {
		s = strings.Replace(s, t[0], t[1], -1)
	}
	return s
}
