#!/bin/bash

cat << EOF >/dev/null

Input description
As input, you should give a word list for your program to scout through to find viable matches. The most popular word list is good ol' enable1.txt

u/G33kDude has supplied an even bigger text file. I've hosted it on my site over here , I recommend 'saving as' to download the file.

Output description
Both outputs should contain the 'truncated' version of the word and the original word. For example.

@tack : attack
There are two outputs that we are interested in:

The 10 longest twitter handles sorted by length in descending order.

The 10 shortest twitter handles sorted by length in ascending order.

Bonus
I think it would be even better if we could find words that have 'at' in them at any point of the word and replace it with the @ symbol. Most of these wouldn't be valid in Twitter but that's not the point here.

For example

r@@a -> (ratata)

r@ic@e ->(raticate)

dr@ ->(drat)

Finally
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

Thanks to u/jnazario for the challenge!

Remember to check out our IRC channel. Check the sidebar for a link -->

EOF

# ported from @13467 solution
twitterize() {
	sed -n 's/^at\(.*\)/@\1 : &/p' | awk '{ print -length, $0 }' | sort -g | cut -d '\' -f2- | tee >(head) >(tac|head) > /dev/null
}

twitterize < enable1.txt
