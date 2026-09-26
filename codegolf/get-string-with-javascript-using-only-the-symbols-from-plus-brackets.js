/*

Challenge: Get the JavaScript string value containing only the "-" character using code only containing the following three symbols: +[]. Note: I'm not sure if this is possible.

Scoring criterion: The number of bytes of code used.

Why? I've set myself a challenge to be able to write code using only the above three characters that can evaluate to ANY JavaScript number. The only thing left I am missing is having access to the "-" character. Once I have this, everything else becomes possible. This question is what gave me inspiration for this.

Definitions
Here is a list of definitions I've so far come up with to write a JavaScript expression (on the left) using only the +[] symbols (on the right). Most definitions reuse existing definitions.

0: +[]
1: ++[[]][0]
(EXPR): [EXPR][0]
1: (1)
2: 1+1
3: 1+2
4: 1+3
5: 1+4
6: 1+5
7: 1+6
8: 1+7
9: 1+8
POSITIVE_INTEGER: +((DIGIT1+"")+DIGIT2+DIGIT3+...)
"": []+[]
EXPR+"": EXPR+[]
undefined: [][0]
"undefined": undefined+""
"undefined": ("undefined")
"u": "undefined"[0]
"n": "undefined"[1]
"d": "undefined"[2]
"e": "undefined"[3]
"f": "undefined"[4]
"i": "undefined"[5]
NaN: +undefined
"NaN": NaN+""
"N": "NaN"[0]
"a": "NaN"[1]
Infinity: +(1+"e"+3+1+0)
"Infinity": Infinity+""
"I": "Infinity"[0]
"t": "Infinity"[6]
"y": "Infinity"[7]
"function find() { [native code] }": ([]["f"+"i"+"n"+"d"]+"")
"c": "function find() { [native code] }"[3]
"(": "function find() { [native code] }"[13]
")": "function find() { [native code] }"[14]
"{": "function find() { [native code] }"[16]
"[": "function find() { [native code] }"[18]
"a": "function find() { [native code] }"[19]
"v": "function find() { [native code] }"[22]
"o": "function find() { [native code] }"[17]
Unfinished definitions
These definitions contain missing pieces, highlighted in red (never mind, I can't figure out how to change the color, I'll use italics for now).

Number: 0["constructor"]
OBJ.FUNC(): +{valueOf:OBJ.FUNC}
OBJ.FUNC(): {toString:OBJ.FUNC}+""
"-": (Number.MIN_SAFE_INTEGER+"")[0]
"-": (Number.NEGATIVE_INFINITY+"")[0]
"-": (Number.MIN_VALUE+"")[2]
"-": ("".indexOf()+"")[0]
".": (+"1e-1")[1]
Thanks to the amazing answers to this question, I've created a JSFiddle that can generate any JavaScript number using those 3 characters. Input a number, tap "Go!", and then copy and paste the JavaScript into your devtools console to see it in action. You can also hover over the generated output in the explanation section for details on how it works.

*/

// ported from @Arnauld solution
console.log([+[[+[++[[]][+[]]+[++[[]][+[]]]+[[+[][[]]]+[][[]]][+[]][++[[]][+[]]+[+[]]]+[++[[]][+[]]]+[+[]]+[+[]]]+[]][+[]][++[[]][+[]]]+[+[]]+[+[]]+[+[]]+[+[]]+[+[]]+[+[]]+[++[[]][+[]]]]+[]][+[]][++[++[[]][+[]]][+[]]]);
