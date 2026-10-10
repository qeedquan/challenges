/*

In this challenge, you must take a string matching the regex ^[a-zA-Z]+$ or whatever is reasonable (you don't have to consider uppercase or lowercase letters if you want) (you may assume the string is long enough, and has the right structure for all the operations), and output another string, produced similarly to word at the end of a recent dadaist tweet by the POTUS ("Despite the constant negative press covfefe").

How to covfefify a string:
First, get the first sound group (made up terminology).
How do you do this? Well:

Find the first vowel (y is also a vowel)

  v
creation
Find the first consonant after that

    v
creation
Remove the rest of the string

creat
That is your first sound group.

Next step:
Get the last consonant of the sound group

t
and replace it with the voiced or voiceless version. To do this, find the letter in this table. Replace with the letter given (which may be the same letter)

b: p
c: g
d: t
f: v
g: k
h: h
j: j
k: g
l: l
m: m
n: n
p: b
q: q
r: r
s: z
t: d
v: f
w: w
x: x
z: s
so, we get

d
Then, take the next vowel after that consonant. You can assume that this consonant is not at the end of the string. Join these two together, then repeat it twice:

didi
Concatenate this to the first sound group:

creatdidi
You're done: the string is covfefified, and you can now output it.

Test cases:

coverage: covfefe

example: exxaxa

programming: progkaka (the a is the first vowel after the g, even though it is not immediately after)
code: codtete

president: preszizi
This is code-golf, so please make your program as short as possible!

*/

class Covfefe {
	public static void main(String[] args) {
		System.out.println(solve("coverage"));
		System.out.println(solve("example"));
		System.out.println(solve("programming"));
		System.out.println(solve("president"));
	}

	// Ported from @Kevin Cruijssen solution
	public static String solve(String input) {
		var filter1 = "[a-z&&[^aeiouy]]";
		var filter2 = "bcdfghjklmnpqrstvwxz";
		var filter3 = "pgtvkhjglmnbqrzdfwxs";

		var output1 = input.replaceAll("(^" + filter1 + "*[aeiouy]+" + filter1 + ").*", "$1");
		
		var char0 = output1.charAt(output1.length() - 1);
		var char1 = filter3.charAt(filter2.indexOf(char0));
		var output2 = char1 + input.replaceAll(output1 + filter1 + "*([aeiouy]).*", "$1");
		
		return output1 + output2 + output2;
	}
}
