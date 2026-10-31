#!/bin/sh

cat << EOF > /dev/null

This is perhaps one of the classical coding challenges that got some resonance in 1986, when columnist Jon Bentley asked Donald Knuth to write a program that would find k most frequent words in a file. Knuth implemented a fast solution using hash tries in an 8-pages-long program to illustrate his literate programming technique. Douglas McIlroy of Bell Labs criticized Knuth's solution as not even able to process a full text of the Bible, and replied with a one-liner, that is not as quick, but gets the job done:

tr -cs A-Za-z '\n' | tr A-Z a-z | sort | uniq -c | sort -rn | sed 10q
In 1987, a follow up article was published with yet another solution, this time by a Princeton professor. But it also couldn't even return result for a single Bible!

Problem description
Original problem description:

Given a text file and an integer k, you are to print the k most common words in the file (and the number of their occurrences) in decreasing frequency.

Additional problem clarifications:

Knuth defined a words as a string of Latin letters: [A-Za-z]+
all other characters are ignored
uppercase and lowercase letters are considered equivalent (WoRd == word)
no limit on file size nor word length
distances between consecutive words can be arbitrarily large
fastest program is the one that uses least total CPU time (multithreading probably won't help)
Sample test cases
Test 1: Ulysses by James Joyce concatenated 64 times (96 MB file).

Download Ulysses from Project Gutenberg: wget http://www.gutenberg.org/files/4300/4300-0.txt
Concatenate it 64 times: for i in {1..64}; do cat 4300-0.txt >> ulysses64; done
Most frequent word is “the” with 968832 appearances.
Test 2: Specially generated random text giganovel (around 1 GB).

Python 3 generator script here.
The text contains 148391 distinct words appearing similarly to natural languages.
Most frequent words: “e” (11309 appearances) and “ihit” (11290 appearances).
Generality test: arbitrarily large words with arbitrarily large gaps.

EOF

tr -cs A-Za-z '\n' | tr A-Z a-z | sort | uniq -c | sort -rn | sed 10q
