#!/usr/bin/env python3

"""

Count token frequencies across a list of tokenized sentences. Each sentence is a list of strings. Return one dictionary whose keys are tokens and whose integer values are their total counts across every sentence.

Examples
Input: sentences = [["i", "love", "ml"], ["i", "love", "coding"]]

Output: {"i": 2, "love": 2, "ml": 1, "coding": 1}

Explanation: Counts accumulate across both sentences while first-seen key order is preserved.

Input: sentences = [["hello", "hello"], ["world"]]

Output: {"hello": 2, "world": 1}

Input: sentences = []

Output: {}

Hint 1
Initialize an empty dictionary before traversing the nested lists.

Hint 2
Update with counts[word] = counts.get(word, 0) + 1.

Requirements
Visit every token in every sentence
Accumulate counts across sentence boundaries
Leave the nested input lists unchanged
Return a dictionary from strings to integers
Constraints
sentences is a list of string lists
Sentences and the outer list may be empty
Use Python only

"""

def word_count_dict(sentences: list) -> dict:
    counts = {}
    for sentence in sentences:
        for word in sentence:
            counts[word] = counts.get(word, 0) + 1
    return counts

print(word_count_dict([["i", "love", "ml"], ["i", "love", "coding"]]))
print(word_count_dict([["hello", "hello"], ["world"]]))
print(word_count_dict([]))
