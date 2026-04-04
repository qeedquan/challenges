#!/bin/sh

cat << EOF >/dev/null

Write a program or function which receives as input a string representing a Welsh word (UTF-8 unless otherwise specified by you).

The following are all single letters in Welsh:

a, b, c, ch, d, dd, e, f, ff, g, ng, h, i, j, l, ll, m, n, o, p, ph, r, rh, s, t, th, u, w, y

To quote Wikipedia,

While the digraphs ch, dd, ff, ng, ll, ph, rh, th are each written with two symbols, they are all considered to be single letters. This means, for example that Llanelli (a town in South Wales) is considered to have only six letters in Welsh, compared to eight letters in English.

These letters also exist in Welsh, though they are restricted to technical vocabulary borrowed from other languages:

k, q, v, x, z

Letters with diacritics are not regarded as separate letters, but your function must accept them and be able to count them. Possible such letters are:

â, ê, î, ô, û, ŷ, ŵ, á, é, í, ó, ú, ý, ẃ, ä, ë, ï, ö, ü, ÿ, ẅ, à, è, ì, ò, ù, ẁ

(This means that ASCII is not an acceptable input encoding, as it cannot encode these characters.)

Notes:
This is code golf.
You do not have to account for words like llongyfarch, in which the ng is not a digraph, but two separate letters. This word has nine letters, but you can miscount it as eight. (If you can account for such words, that's kind of awesome, but outside the scope of this challenge.)
The input is guaranteed to have no whitespace (unless you prefer it with a single trailing newline (or something more esoteric), in which case that can be provided). There will certainly be no internal whitespace.
Test cases:
Llandudno, 8
Llanelli, 6
Rhyl, 3
Llanfairpwllgwyngyllgogerychwyrndrobwllllantysiliogogogoch, 50 (really 51, but we'll count 50)
Tŷr, 3
Cymru, 5
Glyndŵr, 7

EOF

welsh() {
	echo -n $@ | sed -r 's,dd|ff|ng|ll|[cprt]h,1,gi' | wc -m
}

welsh "Llandudno"
welsh "Llanelli"
welsh "Rhyl"
welsh "Llanfairpwllgwyngyllgogerychwyrndrobwllllantysiliogogogoch"
welsh "Tŷr"
welsh "Cymru"
welsh "Glyndŵr"

