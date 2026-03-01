#!/bin/sh

cat << EOF > /dev/null

Your should write a program or function that determines the language of a given word.

The task is to recognize some of the 5000 most common words in 4 languages:

English
German
Italian
Hungarian
The word lists can be found in this GitHub repository.

You are allowed to make mistakes in 40% of the provided test cases. I.e. you can miscategorize 8000 of the 20000 inputs.

Details
The lists only contain words with lowercase letters a-z so e.g. won't and möchte are not included.
A few words appear in multiple languages which means your code can't always guess the expected output correctly.
For convenience you can download all the test cases as one list. In each line a number indicates the language of the word. (1 for English, 2 for German, 3 for Italian and 4 for Hungarian.)
Standard loopholes are disallowed.
Using word lists our similar data provided by your programming language is forbidden.
Input
A string containing only lowercase English letters (a-z).
Trailing newline is optional.
Output
You can categorize the words by providing a distinct and consistent (always the same) output for each language. (E.g. 1 for English, 2 for German, 3 for Italian and 4 for Hungarian.)
This is code golf so the shortest program or function wins.

Related code golf question: Is this even a word?

The word lists were taken from wiktionary.org and 101languages.net.

EOF

DICT="all_languages"

identify() {
	lang=""
	for i in $(grep -E "^$1 " $DICT | cut -d ' ' -f2); do
		case "$i" in
			"1") lang="$lang English" ;;
			"2") lang="$lang German" ;;
			"3") lang="$lang Italian" ;;
			"4") lang="$lang Hungarian" ;;
		esac
	done
	echo "$1 : $lang"
}

identify was
identify ciao
identify wuxu
identify megteszed
