#!/usr/bin/env python3

"""

We will use the Flesch–Kincaid Grade Level to evaluate the readability of a piece of text. This grade level is an approximation for what schoolchildren are able to understand a piece of text. For example, a piece of text with a grade level of 7 can be read by seventh-graders and beyond.

The way to calculate the grade level is as follows:

(0.39 * average number of words per sentence) + (11.8 * average number of syllables per word) - 15.59

Write a function that will calculate the Flesch–Kincaid grade level for any given string. Return the grade level rounded to two decimal points.

Ignore hyphens, dashes, apostrophes, parentheses, ellipses and abbreviations.

Remember that the text can contain more than one sentence: code accordingly!

HINT: Count the number of vowels as an approximation for the number of syllables, but count groups of vowels as one (e.g. deal is one syllable). Do not count y as a vowel!

Example
"The turtle is leaving." ==> 3.67
The average number of words per sentence is 4 and the average number of syllables per word is 1.5. The score is then (0.39 * 4) +  (11.8 * 1.5) - 15.59 = 3.67import re

"""

import re

def flesch_kincaid(text):
    num_words = 0
    num_syllables = 0
    sentences = re.split("[.!?] ", text)
    for sentence in sentences:
        words = sentence.split(" ")
        num_words += len(words)
        for word in words:
            num_syllables += len(re.findall("[aeuio]+", word, flags=re.IGNORECASE))
    return round((0.39 * (num_words/len(sentences))) + (11.8*(num_syllables/num_words)) - 15.59, 2)

def main():
    print(flesch_kincaid("The turtle is leaving."))

main()

