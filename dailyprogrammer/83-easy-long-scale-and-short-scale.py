#!/usr/bin/env python3

"""

One of the most annoying and confusing differences between English and basically every other language in the world is that English uses a weird way to name very large numbers.

For instance, if you wanted to translate "one trillion" from English to French, you might think it would be "un trillion", but that is wrong. The correct translation of "one trillion" to French is "un billion". Well, then, you might ask, what is "one billion" in French? It is, in fact, "un milliard". And "un trillion" in French is equal to english "one quintillion". Confusing, no?

The reason for this is that there are two so-called scales for large numbers, the long scale and the short scale. English uses the short scale, almost everyone else uses the long scale (though the Arabic languages also apparently use the short scale). The two systems can be summarized as follows:

In the short scale, you get a "new word" for the numbers every time the number increases by a factor of 1,000. So "a thousand millions" is "one billion" and "a thousand billions" is "one trillion".

In the long scale, you get a "new word" for the numbers every time the number increases by a factor of 1,000,000. So "a million millions" is the same as "one billion" and "a million billions" is the same as "one trillion". If we just increase by a factor of 1,000, the "-on" ending on the word is replaced by "-ard". So "a thousand millions" is "one milliard", "a thousand billions" is "one billiard".

Here's a table summarizing the words for different numbers:

Actual number	Short scale name	Long scale name
106	million	million
109	billion	milliard
1012	trillion	billion
1015	quadrillion	billiard
1018	quintillion	trillion
1021	sextillion	trilliard
And it goes on like that.

Your task today is to write a program that will print out the name of a number in both long-scale and short-scale. So, for instance, given 1234567891111, it should print out

Short scale: 1 trillion, 234 billion, 567 million, 891 thousand and 111
Long scale:  1 billion, 234 milliard, 567 million, 891 thousand and 111
Bonus points if it prints out everything in letters, i.e.:

Short scale: one trillion, two hundred and thirty-four billion, five hundred
and sixty-seven million, eight hundred and ninety-one thousand and one
hundred and eleven

Long scale:  one billion, two hundred and thirty-four milliard, five hundred
and sixty-seven million, eight hundred and ninety-one thousand and one
hundred and eleven
The program should be able to handle all numbers that can fit into an unsigned 64-bit integers, i.e. all numbers up to 264 - 1 ("18 trillion, 446 billiard, 744 billion, 73 milliard, 709 million, 551 thousand and 615" in long scale, though it's something completely different in short scale.), or 263 - 1 if you're using signed 64-bit integers. Of course, you can write your program so it can handle bigger numbers if you want, but it's not necessary.

"""

import sys

def print_scale(number, scale):
    text = []
    for name, quotient in sorted(scale.items(), key=lambda value: value[1], reverse=True):
        mod = divmod(number, quotient)
        if mod[0] > 0:
            text.append('%d %s, ' % (mod[0], name))
            number -= mod[0] * quotient
    if len(text) > 0:
        text.append('and %d' % number)
    else:
        text.append('%d' % number)
    return ''.join(text)

def main():
    if len(sys.argv) < 2:
        print("usage: number")
        exit(2)

    long_scale = { 'trilliard': 1e21, 'trillion': 1e18, 'billiard': 1e15, 'billion': 1e12, 'milliard': 1e9, 'million': 1e6, 'thousand': 1e3}
    short_scale = { 'sextillion': 1e21, 'quintillion': 1e18, 'quadrillion': 1e15, 'trillion': 1e12, 'billion': 1e9, 'million': 1e6, 'thousand': 1e3}
    num = int(sys.argv[1])
    print("Short scale: %s" % print_scale(num, short_scale))
    print("Long scale: %s" % print_scale(num, long_scale))

main()
