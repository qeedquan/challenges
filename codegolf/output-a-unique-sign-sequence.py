#!/usr/bin/env python3

"""

A sign sequence is an infinite sequence consisting entirely of 1 and −1. These can be constructed a number of ways, for example:

Alternating signs:  1,−1,1,−1,...

−1 for primes, 1 for non-primes:  1,−1,−1,1,−1,1,−1,...

All 1s:  1,1,1,...

Your task is to write a piece of code that outputs a deterministic sign sequence that no other answer already outputs. You must include a proof that your sequence is unique from all sequences posted before yours and that your sequence only contains 1 and −1 . You do not have to worry about keeping up to date for newer answers, as they must ensure their sequences are unique, not you.

You may output in any reasonable manner, including (but not limited to):

Outputting an infinite list/generator/tuple of values
Outputting the next value in the sequence each time your code is run
Outputting the sequence infinitely
You may not take any input (unless necessary), so outputing the first n terms or the nth term is not allowed.

I've included my implementation of a sequence as the first answer, to ensure that all answers have to provide a proof of uniqueness.

This is a popularity-contest, so the answer with the most votes wins. You should aim to do the following things in your answer:

Be creative. Avoid simply outputting constant runs of 1s or −1s or outputting one value when a number is insert common numeric property here and the other when not (e.g. primes or Fibonacci numbers).
Avoid copying others. While all sequences must be unique, aim to be innovative, rather than simply slightly modify another user's sequence (for example, swapping the placements of 1 and −1)
Make it clear what your program is doing. Not everyone can read a Jelly, R or Java answer, but they can read an explanation of the answer, as well as an explanation of how/why you chose this specific sequence and the proof of uniqueness included in your answer
Voters should consider the following when casting their votes:

How creative is the sequence? Has it been done to death before, or is it something you've never seen before?

Is the sequence using some properties of 1 and −1 to be generated, or is it just applying the sgn function to other sequences?
Is it unique, or is it simply a slight modification on a sequence that many other users have done? If it is a modification, is it uncreative, or has the author seen a property that others haven't?

How clever is the implementation of the sequence, and how well explained is it? For this, consider both the actual code of the answer and the algorithm it implements. If the code uses a language specific trick you find particularly impressive, it may be worth an upvote. If the implementation of the algorithm is so general than any language could be used, yet is still creative and unique, it's probably worth an upvote. However, if the code is overly convoluted when a simpler method would work, or if the algorithm is incredibly inefficient when a better version exists, consider casting a downvote.

Furthermore, while you may not be able to understand the 10 bytes of 05AB1E posted, if explained well, you should be able to get a solid understanding of how those 10 bytes implement the chosen sequence, and how clever it is. And while you may be able to fluently read Python, if poorly coded with no explanation, you may not be able to fully understand how that program works. Consider this factor when voting.

Voters should not vote for an answer for any of the following reasons:

The program is written in your favourite/least favourite language
Voting for the use of tricks within a language are fine. Voting for an answer because of the language, is not an acceptable reason
The program is short/long/written with ASCII characters/written without ASCII characters
You recognize the user who wrote the answer and you love/hate them
Any other reason not specified above (e.g. "This answer uses the e character, I love it!")

"""

"""

Ported from @pxeger solution

Quine, which outputs 1 or -1 according to the last bit of each byte of the quine, repeating infinitely. Starts 1 1 -1 1 1 1 1 -1 -1 -1

"""

s = b"s=%r\nwhile[print(c%%2*2-1)for c in s%%s]: pass"
while [print(c % 2 * 2 - 1) for c in s % s]:
    pass

