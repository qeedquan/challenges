#!/usr/bin/env python3

"""

Description
In combinatorial mathematics, a k-ary De Bruijn sequence B(k, n) of order n, named after the Dutch mathematician Nicolaas Govert de Bruijn, is a cyclic sequence of a given alphabet A with size k for which every possible subsequence of length n in A appears as a sequence of consecutive characters exactly once. At the terminus, you "wrap" the end of the sequence around to the beginning to get any remaining subsequences.

Each B(k, n) has length k^n.

A De Bruijn sequence B(2, 3) (with alphabet 0 and 1) is therefore:

00010111
Similarly, B("abcd", 2) (with alphabet "a", "b", "c", and "d") is therefore:

aabacadbbcbdccdd
For those sequences of length, every trigram (for the former case) or bigram (for the latter case) is represented in the result.

De Bruijn sequences have various applications, including in PIN pad testing and rotor angle calculation.

Input Description
You'll be given two inputs k and n, the first is an integer or a a string of unique characters, the second is the length of the subsequences to ensure are encoded.

Output Description
Your program should emit a string that encodes the De Bruijn sequence.

Input
5 3
2 4
abcde 4

Output
The outputs expected for those (in order) are:

00010020030040110120130140210220230240310320330340410420430441112113114122123124132133134142143144222322423323424324433343444
0000100110101111
aaaabaaacaaadaaaeaabbaabcaabdaabeaacbaaccaacdaaceaadbaadcaaddaadeaaebaaecaaedaaeeababacabadabaeabbbabbcabbdabbeabcbabccabcdabceabdbabdcabddabdeabebabecabedabeeacacadacaeacbbacbcacbdacbeaccbacccaccdacceacdbacdcacddacdeacebacecacedaceeadadaeadbbadbcadbdadbeadcbadccadcdadceaddbaddcadddaddeadebadecadedadeeaeaebbaebcaebdaebeaecbaeccaecdaeceaedbaedcaeddaedeaeebaeecaeedaeeebbbbcbbbdbbbebbccbbcdbbcebbdcbbddbbdebbecbbedbbeebcbcbdbcbebcccbccdbccebcdcbcddbcdebcecbcedbceebdbdbebdccbdcdbdcebddcbdddbddebdecbdedbdeebebeccbecdbecebedcbeddbedebeecbeedbeeeccccdccceccddccdeccedcceecdcdcecdddcddecdedcdeececeddcedeceedceeeddddeddeededeeee

"""

def next_lyndon(previous, length, alphabet):
    next = [None] * length
    for i in range(0, length):
        next[i] = previous[i % len(previous)]
    while next[-1] == alphabet[-1]:
        next.pop()
    next[-1] = alphabet[alphabet.find(next[-1]) + 1]
    return next

def num2seq(alphabet):
    return ''.join([str(i) for i in range(int(alphabet))])

def debruijn(alphabet, length):
    if isinstance(alphabet, int):
        alphabet = num2seq(alphabet)

    sequence = alphabet[0]
    previous = sequence
    while len(sequence) < len(alphabet)**length:
        next = next_lyndon(previous, length, alphabet)
        if length % len(next) == 0:
            sequence += ''.join(next)
        previous = next
    return sequence

def main():
    assert(debruijn(5, 3) == "00010020030040110120130140210220230240310320330340410420430441112113114122123124132133134142143144222322423323424324433343444")
    assert(debruijn(2, 4) == "0000100110101111")
    assert(debruijn("abcde", 4) == "aaaabaaacaaadaaaeaabbaabcaabdaabeaacbaaccaacdaaceaadbaadcaaddaadeaaebaaecaaedaaeeababacabadabaeabbbabbcabbdabbeabcbabccabcdabceabdbabdcabddabdeabebabecabedabeeacacadacaeacbbacbcacbdacbeaccbacccaccdacceacdbacdcacddacdeacebacecacedaceeadadaeadbbadbcadbdadbeadcbadccadcdadceaddbaddcadddaddeadebadecadedadeeaeaebbaebcaebdaebeaecbaeccaecdaeceaedbaedcaeddaedeaeebaeecaeedaeeebbbbcbbbdbbbebbccbbcdbbcebbdcbbddbbdebbecbbedbbeebcbcbdbcbebcccbccdbccebcdcbcddbcdebcecbcedbceebdbdbebdccbdcdbdcebddcbdddbddebdecbdedbdeebebeccbecdbecebedcbeddbedebeecbeedbeeeccccdccceccddccdeccedcceecdcdcecdddcddecdedcdeececeddcedeceedceeeddddeddeededeeee")

main()

