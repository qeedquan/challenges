/*

Background
I was working on a system where for convenience (not security) people could use four digit codes to identify themselves. I figured this is something that may actually be useful in many real cases, yet is well enough defined that it could make a nice challenge!

Explanation of pin codes and typo resistant sets
EDIT: Based on the comments, this is probably a more formal definition:

I think a mathematical way of specifying what you are looking for is a maximal set of strings with length 4 over the alphabet {0,1,2,3,4,5,6,7,8,9} with minimum pairwise hamming distance 2, if it helps others.

There are 10000 possible pin codes (0000-9999).

Example pin code

1234
However, since a typo is easily made you are to generate a set of pincodes that is resistant to a single typo.

Example of set that is NOT resistant to single typo:

0000
0005 (if you mistype the last digit as 0 instead of 5, you get another code in the set)
Example of set that IS resistant to single typo

0000
0011
0101
0202
Allowed outputs
The allowed output can be a bit flexible, specifically:

A pincode may be a string or a number
You may always have separators (e.g. comma, newline), however if your codes are always represented as 4 digits separators are optional
The codes should be represented by 0-9, not other characters
Example sets:

0011,0022: OK
00220011: OK
11,22,33: OK
112233: NOT OK
abcd,abef: NOT OK
{'1111',/n'2222'}: OK
Scoring system
The primary score is the number of unique pin codes generated (note that 0001,1000 would count as 2).

Edit: If your code does not always generate the same amount of unique pin codes you must estimate the amount it will at least generate in 95% of the cases and you may use that as your score. So for example if you uniformly randomly generate between 300 and 400 unique pincodes, your score would be 395.

In case there is a tie, the shortest code wins!

Please post your score as: Language, #Unique codes generated with bytes (e.g. Python, 30 codes generated with 123 bytes)

(I guess formally this could be rewritten to 'generate X typo resistant pin codes' but as I have no idea what X is I will keep it like this, this also allows simpler solutions to compete against each other on lenght for 'third place' and beyond.)

In principle no inputs are needed and for simplicity sake I will not make it part of the challenge and scoring, but it would be interesting to see how the code would need to be changed to allow for various length pin codes.

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	pins()
}

/*

@Sisyphus

I suspect 1000 pin codes is optimal. You can check the verification program.

def dist(a, b):
	return sum(x != y for x, y in zip("%04d" % a, "%04d" % b))

l = list(map(int, open(0).readlines()))

for item in l:
	assert all(k == item or dist(k, item) >= 2 for k in l)
print('Done!')

How was this discovered?
The process for discovering this rather simple formula was quite messy for me. The first insight I had was that you can transform this into a graph problem - let the PIN numbers be nodes and connect edges if and only if the hamming distance between the PIN numbers is greater than 1. Then the problem boils down to finding a maximum clique of the graph. From reading some papers apparently there was a simple C program available in the web archive that solves the maximal clique problem for small instances, so I downloaded it (and patched it a little bit since it doesn't compile on a modern compiler). I wrote a simple driver program to generate input in the format it expected and ran it. It was too slow for the full problem but I noticed something odd about its output for smaller instances:


...
level = 9997(10000) best = 100 time =     0.65
level = 9998(10000) best = 100 time =     0.65
level = 9999(10000) best = 100 time =     0.65
level = 10000(10000) best = 100 time =     0.65
Record: 9 10 21 32 43 54 65 76 87 98 100 111 122 133 144 155 166 177 188 199 201 212 220 234 245 253 267 278 289 296 302 313 324 330 341 356 368 379 385 397 403 414 425 431 447 458 469 470 486 492 504 515 526 537 548 559 560 571 582 593 605 616 623 638 649 657 661 672 680 694 706 717 728 739 740 751 762 773 784 795 807 818 829 835 846 852 863 874 881 890 908 919 927 936 942 950 964 975 983 991
For the first 1000 PINs, the optimal clique had 100 nodes, which suspiciously looks like just the number of PINs divided by 10. And also, every prefix from 000..099 appeared once. This led me to hypothesize that there was some closed form solution of the form:

10 * i + f(i) % 10
It looks like f is almost just f(i) = i but occasionally it jumps some extra.

After toying around a little bit, I came across the formula (i + i / 10 + i / 100) % 10, which passes. But (i + i / 10 + i / 100) % 10 is just int(str(i), 11) % 10, that is, reinterpreting the digits of i in base 11! This gives the final answer.

*/

func pins() {
	i := int64(0)
	for range 1000 {
		p := i + int11(i)%10
		fmt.Println(p)
		i += 10
	}
}

func int11(n int64) int64 {
	s := fmt.Sprint(n)
	x, _ := strconv.ParseInt(s, 11, 64)
	return x
}
