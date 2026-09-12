#!/usr/bin/env python3

"""

For the purpose of this challenge, Morse code represents every letter as a sequence of 1-4 characters, each of which is either . (dot) or - (dash). The code for the letter a is .-, for b is -..., etc. The codes for each letter a through z are:

.- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..
Normally, you would indicate where one letter ends and the next begins, for instance with a space between the letters' codes, but for this challenge, just smoosh all the coded letters together into a single string consisting of only dashes and dots.

Examples
smorse("sos") => "...---..."
smorse("daily") => "-...-...-..-.--"
smorse("programmer") => ".--..-.-----..-..-----..-."
smorse("bits") => "-.....-..."
smorse("three") => "-.....-..."
An obvious problem with this system is that decoding is ambiguous. For instance, both bits and three encode to the same string, so you can't tell which one you would decode to without more information.

Optional bonus challenges
For these challenges, use the enable1 word list. It contains 172,823 words. If you encode them all, you would get a total of 2,499,157 dots and 1,565,081 dashes.

The sequence -...-....-.--. is the code for four different words (needing, nervate, niding, tiling). Find the only sequence that's the code for 13 different words.

autotomous encodes to .-..--------------..-..., which has 14 dashes in a row. Find the only word that has 15 dashes in a row.

Call a word perfectly balanced if its code has the same number of dots as dashes. counterdemonstrations is one of two 21-letter words that's perfectly balanced. Find the other one.

protectorate is 12 letters long and encodes to .--..-.----.-.-.----.-..--., which is a palindrome (i.e. the string is the same when reversed). Find the only 13-letter word that encodes to a palindrome.

--.---.---.-- is one of five 13-character sequences that does not appear in the encoding of any word. Find the other four.

Thanks to u/Separate_Memory for inspiring this challenge on r/dailyprogrammer_ideas!

"""

from collections import Counter, defaultdict

# ported from @dang3rous solution

codes = ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..".split(" ")
morsed = {chr(ord("a") + i): code for i, code in enumerate(codes)}

with open("enable1.txt", "r") as f:
    enablelst = f.read().splitlines()

test_cases = [
    ("sos", "...---..."),
    ("daily", "-...-...-..-.--"),
    ("programmer", ".--..-.-----..-..-----..-."),
    ("bits", "-.....-..."),
    ("three", "-.....-...")
]

def encode(word: str) -> str:
    return "".join([morsed[char] for char in word])

def palindrome(word: str) -> True:
    for i in range(0, len(word) // 2):
        if word[i] != word[len(word) - 1 - i]:
            return False
    return True

def bonus_1() -> str:
    d = Counter([encode(word) for word in enablelst])
    for k, cnt in d.items():
        if cnt == 13:
            print("bonus 1: ", k)
            return k

def bonus_2() -> str:
    enc = [encode(word) for word in enablelst]
    target = "-" * 15
    for morse in enc:
        if target in morse:
            print(morse)
            return morse

def bonus_3() -> str:
    words = [word for word in enablelst if len(word) == 21 and word != "counterdemonstrations"]
    for word in words:
        enc = encode(word)
        if enc.count(".") == enc.count("-"):
            print(word)
            return word

def bonus_4() -> str:
    words = [word for word in enablelst if len(word) == 13 and palindrome(encode(word))]
    assert len(words) == 1
    return words[0]

def bonus_5() -> list:
    _enc = lambda x: int(con.replace("-", "0").replace(".", "1"), base=2)
    _dec = lambda x: str(x).replace("0", "-").replace("1", ".")
    nums = set(list(range(2**13)))
    for word in enablelst:
        enc = encode(word)
        if len(enc) < 13:
            continue
        for i in range(0, len(enc) - 13):
            con = enc[i:i+13]
            _int = _enc(con)
            if _int in nums:
                nums.remove(_int)
    return [_dec(num) for num in nums]

def main():
    for test in test_cases:
        assert(encode(test[0]) == test[1])
    print(bonus_1())
    print(bonus_2())
    print(bonus_3())
    print(bonus_4())
    print(bonus_5())

main()
