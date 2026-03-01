/*

Introduction
In Chinese, each chemical element is named with one Chinese character.

(A brief history of the chemical element naming in Chinese can be looked up in Wikipedia.)

Your goal: Print a periodic table of Chinese names of the elements.

At the time of making this challenge, 118 elements have been discovered, so your code has to print element names up to 118.

You may choose to print either in Simplified Chinese or Traditional Chinese (Taiwan). The tables are presented below:

Simplified Chinese (Mainland China)
氢　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　氦
锂铍　　　　　　　　　　　　　　　　　　　　　　　　硼碳氮氧氟氖
钠镁　　　　　　　　　　　　　　　　　　　　　　　　铝硅磷硫氯氩
钾钙　　　　　　　　　　　　　　钪钛钒铬锰铁钴镍铜锌镓锗砷硒溴氪
铷锶　　　　　　　　　　　　　　钇锆铌钼锝钌铑钯银镉铟锡锑碲碘氙
铯钡镧铈镨钕钷钐铕钆铽镝钬饵铥镱镥铪钽钨铼锇铱铂金汞铊铅铋钋砹氡
钫镭锕钍镤铀镎钚镅锔锫锎锿镄钔锘铹𬬻𬭊𬭳𬭛𬭶鿏𫟼𬬭鿔鿭𫓧镆𫟷鿬鿫
Traditional Chinese (Taiwan)
氫　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　氦
鋰鈹　　　　　　　　　　　　　　　　　　　　　　　　硼碳氮氧氟氖
鈉鎂　　　　　　　　　　　　　　　　　　　　　　　　鋁矽磷硫氯氬
鉀鈣　　　　　　　　　　　　　　鈧鈦釩鉻錳鐵鈷鎳銅鋅鎵鍺砷硒溴氪
銣鍶　　　　　　　　　　　　　　釔鋯鈮鉬鎝釕銠鈀銀鎘銦錫銻碲碘氙
銫鋇鑭鈰鐠釹鉕釤銪釓鋱鏑鈥鉺銩鐿鎦鉿鉭鎢錸鋨銥鉑金汞鉈鉛鉍釙砈氡
鍅鐳錒釷鏷鈾錼鈽鋂鋦鉳鉲鑀鐨鍆鍩鐒鑪𨧀𨭎𨨏𨭆䥑鐽錀鎶鉨鈇鏌鉝鿬鿫
The key thing I would like to see in this challenge is how people can creatively compress the list of Chinese characters (code points), given the fact that they have similar radicals. Unfortunately some of the characters are located under CJK Ideograph Extension blocks, so good luck finding a solution for those. 🙂

Informative notes
There are differences between the use of characters as elements name between Mainland China and Taiwan (and also Hong Kong, but I'm not bringing the Hong Kong version into this challenge). Therefore it's not just a simple transformation of glyph shapes between Simplified Chinese and Traditional Chinese. The difference table is shown below (I also added the Mandarin pronunciations because I can, but I don't know Cantonese, sorry):
Z	Sym.	English	S. Chinese	Hong Kong	Taiwan
14	Si	silicon	硅 (guī)	矽	矽 (xì)
43	Tc	technetium	锝 (dé)	鍀	鎝 (tǎ)
71	Lu	lutetium	镥 (lǔ)	鑥	鎦 (liú)
85	At	astatine	砹 (ài)	砹	砈 (è)
87	Fr	francium	钫 (fāng)	鈁	鍅 (fǎ)
93	Np	neptunium	镎 (ná)	鎿	錼 (nài)
94	Pu	plutonium	钚 (bù)	鈈	鈽 (bù)
95	Am	americium	镅 (méi)	鎇	鋂 (méi)
97	Bk	berkelium	锫 (péi)	錇	鉳 (běi)
98	Cf	californium	锎 (kāi)	鐦	鉲 (kǎ)
99	Es	einsteinium	锿 (āi)	鎄	鑀 (ài)
Some element name characters are outside of the URO (Unified Repertoire and Ordering) block (U+4E00 – U+9FA5), therefore your font might not display the characters properly. I show the Unicode code points of these characters, as well as their compositions, in the table below, for convenience:
Z	Sym.		Comp.	Unicode		Comp.	Unicode
104	Rf	𬬻	⿰钅卢	U+2CB3B	鑪		U+946A
105	Db	𬭊	⿰钅杜	U+2CB4A	𨧀	⿰釒杜	U+289C0
106	Sg	𬭳	⿰钅喜	U+2CB73	𨭎	⿰釒喜	U+28B4E
107	Bh	𬭛	⿰钅波	U+2CB5B	𨨏	⿰釒波	U+28A0F
108	Hs	𬭶	⿰钅黑	U+2CB76	𨭆	⿰釒黑	U+28B46
109	Mt	鿏	⿰钅麦	U+9FCF	䥑	⿰釒麥	U+4951
110	Ds	𫟼	⿰钅达	U+2B7FC	鐽		U+943D
111	Rg	𬬭	⿰钅仑	U+2CB2D	錀		U+9300
112	Cn	鿔	⿰钅哥	U+9FD4	鎶		U+93B6
113	Nh	鿭	⿰钅尔	U+9FED	鉨		U+9268
114	Fl	𫓧	⿰钅夫	U+2B4E7	鈇		U+9207
116	Lv	𫟷	⿰钅立	U+2B7F7	鉝		U+93CC
117	Ts	鿬	⿰石田	U+9FEC	鿬	⿰石田	U+9FEC
118	Og	鿫	⿹气奥	U+9FEB	鿫	⿹气奧	U+9FEB
The 鿫 U+9FEB is unified despite the difference in composition between Simplified Chinese and Traditional Chinese.

Output requirements
The Chinese element names have to be arranged exactly as shown, with 32 columns and whitespace. (The periodic table is usually presented as 18 columns in textbooks, with the f-block taken out. The 32-column version has an advantage that the element names are ordered by their atomic numbers.)
You may use either U+3000 Ideographic Space or ASCII space (U+0020) to space the characters in the first 5 rows (periods). If you use ASCII space, be careful of East Asian Widths: An ASCII space takes half of a Chinese character width on the terminal screen. Thus you have to use two ASCII spaces for the same width as the Ideographic Space.
It's optional to number the rows (periods) and/or columns (groups).
Other requirements
Please mention in the first line of your submission entry: Programming language, Simp. or Trad. output, Code size
Your program must not fetch any external data source (from file, from the internet, or whatever).
code-golf. Aim for code size as small as possible.
There is no bonus if your program supports both Simplified Chinese and Traditional Chinese output, but you can do it for fun anyway. (It's more recommended to submit them as two separate entires. You can make both entries in the same answer.)

*/

package main

import "fmt"

func main() {
	fmt.Println(TABLE)
}

const TABLE = `
氢　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　氦
锂铍　　　　　　　　　　　　　　　　　　　　　　　　硼碳氮氧氟氖
钠镁　　　　　　　　　　　　　　　　　　　　　　　　铝硅磷硫氯氩
钾钙　　　　　　　　　　　　　　钪钛钒铬锰铁钴镍铜锌镓锗砷硒溴氪
铷锶　　　　　　　　　　　　　　钇锆铌钼锝钌铑钯银镉铟锡锑碲碘氙
铯钡镧铈镨钕钷钐铕钆铽镝钬饵铥镱镥铪钽钨铼锇铱铂金汞铊铅铋钋砹氡
钫镭锕钍镤铀镎钚镅锔锫锎锿镄钔锘铹𬬻𬭊𬭳𬭛𬭶鿏𫟼𬬭鿔鿭𫓧镆𫟷鿬鿫
`
