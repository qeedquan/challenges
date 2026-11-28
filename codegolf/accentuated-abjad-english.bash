#!/bin/bash

cat << EOF >/dev/null

An Abjad is a writing system where each symbol stands for a consonant, and where vowels are omitted. An impure Abjad is an abjad in which there are additional symbols for vowels, usually diacritics.

Write a program or function that, given a string of lowercase text (i.e. nothing but ASCII letters from a to z, commas and spaces), outputs a corresponding impure abjad English transcript with the following rules:

Representation of vowels
Each vowel (i.e. a e i o u) is represented as an accent on the immediately preceding consonant. For instance, assuming the accent representing the vowel e is ́, the word wet will be transcribed as ẃt.

If a vowel is not preceded by a consonant (two or more vowels in a row, or a word starting with a vowel), the symbol o is used as a "blank consonant". For example, the word peep will be transcribed as ṕóp

Accent placement
Consonants that have ascenders are unpleasant to read when accentuated. Therefore, for those consonants, the symmetric accent will be displayed below the symbol instead of above. For instance, the letter combination te will be written t̖ rather than ́t

Those consonants are b d f h k l t.

Accents for vowels
We are using Unicode combining characters to display accents on every consonant possible. The combining characters used can be found here. Combining accents are placed directly after the symbol they are to be put on.

The accents are presented on arbitrary consonants in this list.

a

Above accent: U+0x0304 Combining Macron, example: c̄

Below accent: U+0x0320 Combining Minus Sign Below, example: d̠

e

Above accent: U+0x0301 Combining Acute Accent, example: ć

Below accent: U+0x0316 Combining Grave Accent Below, example: d̖

i

Above accent: U+0x0307 Combining Dot Above, example: ċ

Below accent: U+0x0323 Combining Circumflex Accent Below, example: ḍ

o

Above accent: U+0x030c Combining Caron, example: č

Below accent: U+0x032d Combining Circumflex Accent Below, example: ḓ

u

Above accent: U+0x0311 Combining Inverted Breve, example: c̑

Below accent: U+0x032e Combining Breve Below, example: d̮

Here is the list of all possible characters:

b̠ b̖ ḅ b̭ b̮
c̄ ć ċ č c̑
d̠ d̖ ḍ ḓ d̮
f̠ f̖ f̣ f̭ f̮
ḡ ǵ ġ ǧ g̑
h̠ h̖ ḥ h̭ ḫ
j̄ j́ j̇ ǰ j̑
k̠ k̖ ḳ k̭ k̮
l̠ l̖ ḷ ḽ l̮
m̄ ḿ ṁ m̌ m̑
n̄ ń ṅ ň n̑
p̄ ṕ ṗ p̌ p̑
q̄ q́ q̇ q̌ q̑
r̄ ŕ ṙ ř ȓ
s̄ ś ṡ š s̑
t̠ t̖ ṭ ṱ t̮
v̄ v́ v̇ v̌ v̑
w̄ ẃ ẇ w̌ w̑
x̄ x́ ẋ x̌ x̑
ȳ ý ẏ y̌ y̑
z̄ ź ż ž z̑
ō ó ȯ ǒ ȏ
Test cases
Input: programming puzzles and code golf
Output: přgr̄mṁng p̑zzl̖s ōnd čd̖ ǧlf

Input: the quick brown fox jumps over the lazy dog
Output: th̖ q̑ȯck břwn f̭x j̑mps ǒv́r th̖ l̠zy ḓg

Input: beautiful
Outpu: b̖ōȏṭf̮l

Input: one ring to rule them all, one ring to find them, one ring to bring them all and in the darkness bind them
Output: ǒń ṙng ṱ ȓl̖ th̖m ōll, ǒń ṙng ṱ f̣nd th̖m, ǒń ṙng ṱ bṙng th̖m ōll ōnd ȯn th̖ d̠rkńss ḅnd th̖m

Scoring
This is code-golf, so the shortest program or function in bytes wins.

EOF

# ported from @Toby Speight solution
convert() {
	echo $@ | sed -r 's/([bdfhklt])([aeiou])/\1\u\2/g;y/aeiouAEIOU/̠̖̣̭̮̄́̇̌̑/;s/\B[^ ,a-z]/o&/g'
}

convert "programming puzzles and code golf"
convert "the quick brown fox jumps over the lazy dog"
convert "beautiful"
convert "one ring to rule them all, one ring to find them, one ring to bring them all and in the darkness bind them"

