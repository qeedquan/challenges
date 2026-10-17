/*

In this challenge, you'll print out the SBCS of Jelly, a popular golfing language. Its code page looks like this:

_0	_1	_2	_3	_4	_5	_6	_7	_8	_9	_A	_B	_C	_D	_E	_F
0_	¡	¢	£	¤	¥	¦	©	¬	®	µ	½	¿	€	Æ	Ç	Ð
1_	Ñ	×	Ø	Œ	Þ	ß	æ	ç	ð	ı	ȷ	ñ	÷	ø	œ	þ
2_	 	!	"	#	$	%	&	'	(	)	*	+	,	-	.	/
3_	0	1	2	3	4	5	6	7	8	9	:	;	<	=	>	?
4_	@	A	B	C	D	E	F	G	H	I	J	K	L	M	N	O
5_	P	Q	R	S	T	U	V	W	X	Y	Z	[	\	]	^	_
6_	`	a	b	c	d	e	f	g	h	i	j	k	l	m	n	o
7_	p	q	r	s	t	u	v	w	x	y	z	{	|	}	~	¶
8_	°	¹	²	³	⁴	⁵	⁶	⁷	⁸	⁹	⁺	⁻	⁼	⁽	⁾	Ɓ
9_	Ƈ	Ɗ	Ƒ	Ɠ	Ƙ	Ɱ	Ɲ	Ƥ	Ƭ	Ʋ	Ȥ	ɓ	ƈ	ɗ	ƒ	ɠ
A_	ɦ	ƙ	ɱ	ɲ	ƥ	ʠ	ɼ	ʂ	ƭ	ʋ	ȥ	Ạ	Ḅ	Ḍ	Ẹ	Ḥ
B_	Ị	Ḳ	Ḷ	Ṃ	Ṇ	Ọ	Ṛ	Ṣ	Ṭ	Ụ	Ṿ	Ẉ	Ỵ	Ẓ	Ȧ	Ḃ
C_	Ċ	Ḋ	Ė	Ḟ	Ġ	Ḣ	İ	Ŀ	Ṁ	Ṅ	Ȯ	Ṗ	Ṙ	Ṡ	Ṫ	Ẇ
D_	Ẋ	Ẏ	Ż	ạ	ḅ	ḍ	ẹ	ḥ	ị	ḳ	ḷ	ṃ	ṇ	ọ	ṛ	ṣ
E_	ṭ	§	Ä	ẉ	ỵ	ẓ	ȧ	ḃ	ċ	ḋ	ė	ḟ	ġ	ḣ	ŀ	ṁ
F_	ṅ	ȯ	ṗ	ṙ	ṡ	ṫ	ẇ	ẋ	ẏ	ż	«	»	‘	’	“	”
Or, in a code block:

¡¢£¤¥¦©¬®µ½¿€ÆÇÐ
Ñ×ØŒÞßæçðıȷñ÷øœþ
 !"#$%&'()*+,-./
0123456789:;<=>?
@ABCDEFGHIJKLMNO
PQRSTUVWXYZ[\]^_
`abcdefghijklmno
pqrstuvwxyz{|}~¶
°¹²³⁴⁵⁶⁷⁸⁹⁺⁻⁼⁽⁾Ɓ
ƇƊƑƓƘⱮƝƤƬƲȤɓƈɗƒɠ
ɦƙɱɲƥʠɼʂƭʋȥẠḄḌẸḤ
ỊḲḶṂṆỌṚṢṬỤṾẈỴẒȦḂ
ĊḊĖḞĠḢİĿṀṄȮṖṘṠṪẆ
ẊẎŻạḅḍẹḥịḳḷṃṇọṛṣ
ṭ§Äẉỵẓȧḃċḋėḟġḣŀṁ
ṅȯṗṙṡṫẇẋẏż«»‘’“”
Rules:

You can substitute ¶ with \n (0x10), § with ụ, or Ä with ṿ if you wish
You may use combining diacritics if these can be normalized to the correct character
You may represent characters with their Unicode code points or UTF-8/16/32 representations
You may output the characters with any reasonable formatting, as long as they are in order (e.g., a 256 character string, an array of characters, a 2d array representing a table with any dimensions, a string with newlines delimiting each character, etc.)
This is code-golf, so shortest answer in bytes (per language) wins.

*/

package main

import "fmt"

func main() {
	fmt.Println(CODEPAGE)
}

const CODEPAGE = `¡¢£¤¥¦©¬®µ½¿€ÆÇÐ
Ñ×ØŒÞßæçðıȷñ÷øœþ
 !"#$%&'()*+,-./
0123456789:;<=>?
@ABCDEFGHIJKLMNO
PQRSTUVWXYZ[\]^_` + "`\n" + `abcdefghijklmno
pqrstuvwxyz{|}~¶
°¹²³⁴⁵⁶⁷⁸⁹⁺⁻⁼⁽⁾Ɓ
ƇƊƑƓƘⱮƝƤƬƲȤɓƈɗƒɠ
ɦƙɱɲƥʠɼʂƭʋȥẠḄḌẸḤ
ỊḲḶṂṆỌṚṢṬỤṾẈỴẒȦḂ
ĊḊĖḞĠḢİĿṀṄȮṖṘṠṪẆ
ẊẎŻạḅḍẹḥịḳḷṃṇọṛṣ
ṭ§Äẉỵẓȧḃċḋėḟġḣŀṁ
ṅȯṗṙṡṫẇẋẏż«»‘’“”`
