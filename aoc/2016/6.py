#!/usr/bin/env python3

"""

--- Day 6: Signals and Noise ---
Something is jamming your communications with Santa. Fortunately, your signal is only partially jammed, and protocol in situations like this is to switch to a simple repetition code to get the message through.

In this model, the same message is sent repeatedly. You've recorded the repeating message signal (your puzzle input), but the data seems quite corrupted - almost too badly to recover. Almost.

All you need to do is figure out which character is most frequent for each position. For example, suppose you had recorded the following messages:

eedadn
drvtee
eandsr
raavrd
atevrs
tsrnev
sdttsa
rasrtv
nssdts
ntnada
svetve
tesnvt
vntsnd
vrdear
dvrsen
enarar
The most common character in the first column is e; in the second, a; in the third, s, and so on. Combining these characters returns the error-corrected message, easter.

Given the recording in your puzzle input, what is the error-corrected version of the message being sent?

--- Part Two ---
Of course, that would be the message - if you hadn't agreed to use a modified repetition code instead.

In this modified code, the sender instead transmits what looks like random data, but for each character, the character they actually want to send is slightly less likely than the others. Even after signal-jamming noise, you can look at the letter distributions in each column and choose the least common letter to reconstruct the original message.

In the above example, the least common character in the first column is a; in the second, d, and so on. Repeating this process for the remaining characters produces the original message, advent.

Given the recording in your puzzle input and this new decoding methodology, what is the original message that Santa is trying to send?

"""

from collections import Counter

def load_words(name):
    words = []
    file = open(name)
    for line in file.readlines():
        words.append(line.strip())
    file.close()
    return words

def generate(words, position):
    if len(words) == 0:
        return ""

    result = ""
    for index in range(len(words[0])):
        combined = []
        for word in words:
            combined.append(word[index])
        
        counter = Counter(combined)
        common = counter.most_common()
        result += common[position][0]
    return result

def main():
    words = load_words("6.txt")
    print(generate(words, 0))
    print(generate(words, -1))

main()

