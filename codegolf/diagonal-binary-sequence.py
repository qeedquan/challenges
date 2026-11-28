#!/usr/bin/env python3

"""

Challenge:
Given a positive number n, convert it to binary, and output a sequence where all 1s form a top-left to bottom-right diagonal line, including a leading column of 1s. To give two examples:

n=1 will result in [1,3,5,9,17,33,65,129,...], with binary values:

1
11
101
1001
10001
100001
1000001
10000001
↓       ↘
n=89 will result in [89,153,281,537,1049,2073,4121,8217,...], with binary values:

1011001
10011001
100011001
1000011001
10000011001
100000011001
1000000011001
10000000011001
↓         ↘↘  ↘
In general, the binary sequences are formed by replacing the leading 1 with 10 in every iteration, with the exception of n=1.

Challenge rules:
The input n is guaranteed to be positive.
Default sequence rules apply, so you're allowed to:
Take an additional input k and output the kth value of the sequence, either 0-index or 1-index.
Take an additional input k and output the first k values of the sequence.
Output the values of the sequence indefintely.
Of course, any reasonable output format can be used. Could be as strings/integers/decimals/etc.; could be as an (infinite) list/array/stream/generator/etc.; could be output with space/comma/newline/other delimiter to STDOUT; etc. etc.
I/O as binary isn't allowed for this challenge, since it's already easy enough as is.
Please state what I/O and sequence output-option you're using in your answer!

General Rules:
This is code-golf, so the shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (e.g. TIO or ATO).
Also, adding an explanation for your answer is highly recommended.

Test Cases:
n     First 10 values of the output sequence

1     [1,3,5,9,17,33,65,129,257,513,...]
2     [2,4,8,16,32,64,128,256,512,1024,...]
3     [3,5,9,17,33,65,129,257,513,1025,...]
6     [6,10,18,34,66,130,258,514,1026,2050,...]
7     [7,11,19,35,67,131,259,515,1027,2051,...]
12    [12,20,36,68,132,260,516,1028,2052,4100,...]
31    [31,47,79,143,271,527,1039,2063,4111,8207,...]
89    [89,153,281,537,1049,2073,4121,8217,16409,32793,...]
111   [111,175,303,559,1071,2095,4143,8239,16431,32815,...]
1000  [1000,1512,2536,4584,8680,16872,33256,66024,131560,262632,...]

"""

def gen(x, n):
    r = []
    for i in range(n):
        r.append(x)
        b = bin(x)[2:]
        s = '1' + b
        if len(b) > 1:
            s = '10' + b[1:]
        x = int(s, 2)
    return r

def main():
    tab = [[1, [1, 3, 5, 9, 17, 33, 65, 129, 257, 513]],
           [2, [2, 4, 8, 16, 32, 64, 128, 256, 512, 1024]],
           [3, [3, 5, 9, 17, 33, 65, 129, 257, 513, 1025]],
           [6, [6, 10, 18, 34, 66, 130, 258, 514, 1026, 2050]],
           [7, [7, 11, 19, 35, 67, 131, 259, 515, 1027, 2051]],
           [12, [12, 20, 36, 68, 132, 260, 516, 1028, 2052, 4100]],
           [31, [31, 47, 79, 143, 271, 527, 1039, 2063, 4111, 8207]],
           [89, [89, 153, 281, 537, 1049, 2073, 4121, 8217, 16409, 32793]],
           [111, [111, 175, 303, 559, 1071, 2095, 4143, 8239, 16431, 32815]],
           [1000, [1000, 1512, 2536, 4584, 8680, 16872, 33256, 66024, 131560, 262632]]]

    for (i, r) in tab:
        assert(gen(i, len(r)) == r)

main()
