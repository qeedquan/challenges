#!/usr/bin/env python3

r"""

Characters
Let’s call these Unicode characters English IPA consonants:

bdfhjklmnprstvwzðŋɡʃʒθ
And let’s call these Unicode characters English IPA vowels:

aeiouæɑɔəɛɜɪʊʌː
(Yes, ː is just the long vowel mark, but treat it as a vowel for the purpose of this challenge.)

Finally, these are primary and secondary stress marks:

ˈˌ
Note that ɡ (U+0261) is not a lowercase g, and the primary stress marker ˈ (U+02C8) is not an apostrophe, and ː (U+02D0) is not a colon.

Your task
Given a word, stack the vowels on top of the consonants they follow, and place the stress markers beneath the consonants they precede. (As the question title hints, such a writing system, where consonant-vowel sequences are packed together as a unit, is called an abugida.) Given the input ˈbætəlʃɪp, produce the output:

æə ɪ
btlʃp
ˈ
A word is guaranteed to be a string of consonants, vowels, and stress marks, as defined above. There will never be consecutive stress marks, and they will always be placed at the start of the word and/or before a consonant.

Test cases
There may be consecutive vowels. For example, kənˌɡrætjʊˈleɪʃən becomes

      ɪ
ə  æ ʊeə
knɡrtjlʃn
  ˌ   ˈ
If a word starts with a vowel, print it on the “baseline” with the consonants: əˈpiːl becomes

 ː
 i
əpl
 ˈ
A test case with an initial, stressed vowel: ˈælbəˌtrɔs becomes

  ə ɔ 
ælbtrs
ˈ  ˌ  
A long word: ˌsuːpərˌkaləˌfrædʒəˌlɪstɪˌkɛkspiːæləˈdoʊʃəs becomes

               æ    
ː              ː ʊ  
uə aə æ əɪ ɪɛ  iəoə 
sprklfrdʒlstkkspldʃs
ˌ  ˌ ˌ   ˌ  ˌ    ˈ  
A nonsense example with an initial diphthong, lots of vowel stacking, and no stress markers: eɪbaeioubaabaaa becomes

 u
 o
 i a
 eaa
ɪaaa
ebbb
Reference implementation
Your program should produce the same output as this Python script:

consonants = 'bdfhjklmnprstvwzðŋɡʃʒθ'
vowels = 'aeiouæɑɔəɛɜɪʊʌː'
stress_marks = 'ˈˌ'

def abugidafy(word):
    tiles = dict()
    x = y = 0

    is_first = True
    for c in word:
        if c in stress_marks:
            tiles[x + 1, 1] = c
        elif c in consonants or is_first:
            y = 0
            x += 1
            tiles[x, y] = c
            is_first = False
        elif c in vowels:
            y -= 1
            tiles[x, y] = c
            is_first = False
        else:
            raise ValueError('Not an IPA character: ' + c)

    xs = [x for (x, y) in tiles.keys()]
    ys = [y for (x, y) in tiles.keys()]
    xmin, xmax = min(xs), max(xs)
    ymin, ymax = min(ys), max(ys)

    lines = []
    for y in range(ymin, ymax + 1):
        line = [tiles.get((x, y), ' ') for x in range(xmin, xmax + 1)]
        lines.append(''.join(line))
    return '\n'.join(lines)

print(abugidafy(input()))
Try it on Ideone.

Rules
You may write a function or a full program.

If your program has a Unicode character/string type, you can assume inputs and outputs use those. If not, or you read/write from STDIN, use the UTF-8 encoding.

You may produce a string containing newlines, or a list of strings representing rows, or an array of Unicode characters.

Each row of output may contain any amount of trailing spaces. If you produce a string, it may have a single trailing newline.

Your program should produce the correct output for arbitrarily long words with arbitrarily long vowel chains, but may assume that the input word is always valid.

If there are no stress markers, your output may optionally include a final empty row (containing nothing, or spaces).

The shortest answer (in bytes) wins.

"""

consonants = 'bdfhjklmnprstvwzðŋɡʃʒθ'
vowels = 'aeiouæɑɔəɛɜɪʊʌː'
stress_marks = 'ˈˌ'

def abugidafy(word):
    tiles = dict()
    x = y = 0

    is_first = True
    for c in word:
        if c in stress_marks:
            tiles[x + 1, 1] = c
        elif c in consonants or is_first:
            y = 0
            x += 1
            tiles[x, y] = c
            is_first = False
        elif c in vowels:
            y -= 1
            tiles[x, y] = c
            is_first = False
        else:
            raise ValueError('Not an IPA character: ' + c)

    xs = [x for (x, y) in tiles.keys()]
    ys = [y for (x, y) in tiles.keys()]
    xmin, xmax = min(xs), max(xs)
    ymin, ymax = min(ys), max(ys)

    lines = []
    for y in range(ymin, ymax + 1):
        line = [tiles.get((x, y), ' ') for x in range(xmin, xmax + 1)]
        lines.append(''.join(line))
    return '\n'.join(lines)

def main():
    print(abugidafy("kənˌɡrætjʊˈleɪʃən"))
    print(abugidafy("əˈpiːl"))
    print(abugidafy("ˈælbəˌtrɔs"))
    print(abugidafy("ˌsuːpərˌkaləˌfrædʒəˌlɪstɪˌkɛkspiːæləˈdoʊʃəs"))
    print(abugidafy("eɪbaeioubaabaaa"))

main()
