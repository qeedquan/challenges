#!/usr/bin/env python3

"""

Description

Once upon a time in a country far away lived a king and he had a big kingdom. He was a very clever king but he had one weakness -- he could count only up to three.
Nevertheless, he did not consider this to be a really great drawback, since he had a lot of wizards who could count up to one hundred (and some of them, people said, even up to one thousand), so it was all right. But one day the grief came to the kingdom as the outnumbering barbarians started to approach from all sides. And the king then had to make the most important decision in his life. He had to choose which of his sons to make generals that he would send to the borders of the country to lead the army.
However, the king knew that though some of his sons were clever, just like he was, some of them were quite stupid and could only lower army spirits with their wrong decisions. More precisely, he knew about each of his sons his mental potential -- an integer number ranging from minus three to three (remember, that the king could count only up to three). He also knew that the chance of his army defeating barbarians was proportional to the sum of some powers of mental potentials of those of his sons that he would make generals (the power exponent was a positive integer number, the same for all his sons and not exceeding three either). Thus he had to choose such a combination of his sons to lead
the army, that this sum would be maximal possible.
However, the king himself could not make all apropriate calculations since, for example, the second power of the number not exceeding three (which is its square) could be greater than three, and therefore he asked you, his most intellegent wizard, to solve this problem.

Input

The first line of the input file contains the number of the sons of the king (integer number less or equal to one hundred). The second line contains the positive integer number not exceeding three, the exponent in the formula used to calculate the chance of defeating barbarians. The third line contains the list of mental potentials of king’s sons -- all integer numbers, not greater than three by their absolute value.

Output

Output the only number -- the maximal possible chance of defeating barbarians measured as the sum described.

Sample Input

3
3
2 -1 1

Sample Output

9

Hint

In the example above the king should choose his first and third sons to be the generals. In this case the chance to defeat barbarians, which is the sum of cubes of mental potentials of these sons, is eight plus one, that is nine.

Source

Northeastern Europe 2002, Northern Subregion

"""

def chance(a, p):
    a.sort(reverse=True)
    r = 0
    for x in a:
        v = x**p
        if v >= 0:
            r += v
        else:
            break
    return r

def main():
    assert(chance([2, -1, 1], 3) == 9)

main()
