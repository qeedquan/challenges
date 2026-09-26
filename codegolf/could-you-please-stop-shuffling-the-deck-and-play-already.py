#!/usr/bin/env python3

"""

Challenge:
Input: A list of distinct positive integers within the range [1,list-size].

Output: An integer: the amount of times the list is riffle-shuffled. For a list, this means the list is split in two halves, and these halves are interleaved (i.e. riffle-shuffling the list [1,2,3,4,5,6,7,8,9,10] once would result in [1,6,2,7,3,8,4,9,5,10], so for this challenge the input [1,6,2,7,3,8,4,9,5,10] would result in 1).

Challenge rules:
You can assume the list will only contain positive integers in the range [1,list-size] (or [0,list-size−1] if you choose to have 0-indexed input-lists).
You can assume all input-lists will either be a valid riffle-shuffled list, or a sorted list which isn't shuffled (in which case the output is 0).
You can assume the input-list will contain at least three values.

Step-by-step example:
Input: [1,3,5,7,9,2,4,6,8]

Unshuffling it once becomes: [1,5,9,4,8,3,7,2,6], because every even 0-indexed item comes first [1, ,5, ,9, ,4, ,8], and then all odd 0-indexed items after that [ ,3, ,7, ,2, ,6, ].
The list isn't ordered yet, so we continue:

Unshuffling the list again becomes: [1,9,8,7,6,5,4,3,2]
Again becomes: [1,8,6,4,2,9,7,5,3]
Then: [1,6,2,7,3,8,4,9,5]
And finally: [1,2,3,4,5,6,7,8,9], which is an ordered list, so we're done unshuffling.

We unshuffled the original [1,3,5,7,9,2,4,6,8] five times to get to [1,2,3,4,5,6,7,8,9], so the output is 5 in this case.

General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (i.e. TIO).
Also, adding an explanation for your answer is highly recommended.

Test cases:
Input                                                   Output

[1,2,3]                                                 0
[1,2,3,4,5]                                             0
[1,3,2]                                                 1
[1,6,2,7,3,8,4,9,5,10]                                  1
[1,3,5,7,2,4,6]                                         2
[1,8,6,4,2,9,7,5,3,10]                                  2
[1,9,8,7,6,5,4,3,2,10]                                  3
[1,5,9,4,8,3,7,2,6,10]                                  4
[1,3,5,7,9,2,4,6,8]                                     5
[1,6,11,5,10,4,9,3,8,2,7]                               6
[1,10,19,9,18,8,17,7,16,6,15,5,14,4,13,3,12,2,11,20]    10
[1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20]    17
[1,141,32,172,63,203,94,234,125,16,156,47,187,78,218,109,249,140,31,171,62,202,93,233,124,15,155,46,186,77,217,108,248,139,30,170,61,201,92,232,123,14,154,45,185,76,216,107,247,138,29,169,60,200,91,231,122,13,153,44,184,75,215,106,246,137,28,168,59,199,90,230,121,12,152,43,183,74,214,105,245,136,27,167,58,198,89,229,120,11,151,42,182,73,213,104,244,135,26,166,57,197,88,228,119,10,150,41,181,72,212,103,243,134,25,165,56,196,87,227,118,9,149,40,180,71,211,102,242,133,24,164,55,195,86,226,117,8,148,39,179,70,210,101,241,132,23,163,54,194,85,225,116,7,147,38,178,69,209,100,240,131,22,162,53,193,84,224,115,6,146,37,177,68,208,99,239,130,21,161,52,192,83,223,114,5,145,36,176,67,207,98,238,129,20,160,51,191,82,222,113,4,144,35,175,66,206,97,237,128,19,159,50,190,81,221,112,3,143,34,174,65,205,96,236,127,18,158,49,189,80,220,111,2,142,33,173,64,204,95,235,126,17,157,48,188,79,219,110,250]
                                                        45

"""

"""

@Arnauld

The solution can also be found by just looking at the 2nd card and the total number of cards in the deck.

Given a deck of length L, this code looks for n such that:

c[2] = ((k + 1) / 2)^n (mod k) where c[2] is the second card and k is defined as:
k = L     if L is odd
    L - 1 if L is even

Do this by the following method:

Given a deck of c[0], ..., c[L-1] of length L, we define:
x[n] = 2^n mod L       if L is odd
       2^n mod (L - 1) if L is even

Look for x[n] such that c[x] = 2

"""

def index(c):
    L = len(c)
    if L < 3:
        return 0

    m = L - ((L & 1 ) ^ 1)
    for n in range(L):
        x = pow(2, n, m)
        if c[x] == 2:
            return n
    return -1

def main():
    assert(index([1, 2, 3]) == 0)
    assert(index([1, 2, 3, 4, 5]) == 0)
    assert(index([1, 3, 2]) == 1)
    assert(index([1, 6, 2, 7, 3, 8, 4, 9, 5, 10]) == 1)
    assert(index([1, 3, 5, 7, 2, 4, 6]) == 2)
    assert(index([1, 8, 6, 4, 2, 9, 7, 5, 3, 10]) == 2)
    assert(index([1, 9, 8, 7, 6, 5, 4, 3, 2, 10]) == 3)
    assert(index([1, 5, 9, 4, 8, 3, 7, 2, 6, 10]) == 4)
    assert(index([1, 3, 5, 7, 9, 2, 4, 6, 8]) == 5)
    assert(index([1, 6, 11, 5, 10, 4, 9, 3, 8, 2, 7]) == 6)
    assert(index([1, 10, 19, 9, 18, 8, 17, 7, 16, 6, 15, 5, 14, 4, 13, 3, 12, 2, 11, 20]) == 10)
    assert(index([1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20]) == 17)
    assert(index([1, 141, 32, 172, 63, 203, 94, 234, 125, 16, 156, 47, 187, 78, 218, 109, 249, 140, 31, 171, 62, 202, 93, 233, 124, 15, 155, 46, 186, 77, 217, 108, 248, 139, 30, 170, 61, 201, 92, 232, 123, 14, 154, 45, 185, 76, 216, 107, 247, 138, 29, 169, 60, 200, 91, 231, 122, 13, 153, 44, 184, 75, 215, 106, 246, 137, 28, 168, 59, 199, 90, 230, 121, 12, 152, 43, 183, 74, 214, 105, 245, 136, 27, 167, 58, 198, 89, 229, 120, 11, 151, 42, 182, 73, 213, 104, 244, 135, 26, 166, 57, 197, 88, 228, 119, 10, 150, 41, 181, 72, 212, 103, 243, 134, 25, 165, 56, 196, 87, 227, 118, 9, 149, 40, 180, 71, 211, 102, 242, 133, 24, 164, 55, 195, 86, 226, 117, 8, 148, 39, 179, 70, 210, 101, 241, 132, 23, 163, 54, 194, 85, 225, 116, 7, 147, 38, 178, 69, 209, 100, 240, 131, 22, 162, 53, 193, 84, 224, 115, 6, 146, 37, 177, 68, 208, 99, 239, 130, 21, 161, 52, 192, 83, 223, 114, 5, 145, 36, 176, 67, 207, 98, 238, 129, 20, 160, 51, 191, 82, 222, 113, 4, 144, 35, 175, 66, 206, 97, 237, 128, 19, 159, 50, 190, 81, 221, 112, 3, 143, 34, 174, 65, 205, 96, 236, 127, 18, 158, 49, 189, 80, 220, 111, 2, 142, 33, 173, 64, 204, 95, 235, 126, 17, 157, 48, 188, 79, 219, 110, 250]) == 45)

main()
