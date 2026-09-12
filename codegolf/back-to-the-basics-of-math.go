/*

Introduction:
We all know these three basic arithmetic math tables I assume.

ADDITION:
 + | 1  2  3  4  5  6  7  8  9  10
----------------------------------
1  | 2  3  4  5  6  7  8  9  10 11
2  | 3  4  5  6  7  8  9  10 11 12
3  | 4  5  6  7  8  9  10 11 12 13
4  | 5  6  7  8  9  10 11 12 13 14
5  | 6  7  8  9  10 11 12 13 14 15
6  | 7  8  9  10 11 12 13 14 15 16
7  | 8  9  10 11 12 13 14 15 16 17
8  | 9  10 11 12 13 14 15 16 17 18
9  | 10 11 12 13 14 15 16 17 18 19
10 | 11 12 13 14 15 16 17 18 19 20

SUBTRACTION:
 - | 1  2  3  4  5  6  7  8  9  10
---------------------------------
1  | 0  1  2  3  4  5  6  7  8  9
2  | -1 0  1  2  3  4  5  6  7  8
3  | -2 -1 0  1  2  3  4  5  6  7
4  | -3 -2 -1 0  1  2  3  4  5  6
5  | -4 -3 -2 -1 0  1  2  3  4  5
6  | -5 -4 -3 -2 -1 0  1  2  3  4
7  | -6 -5 -4 -3 -2 -1 0  1  2  3
8  | -7 -6 -5 -4 -3 -2 -1 0  1  2
9  | -8 -7 -6 -5 -4 -3 -2 -1 0  1
10 | -9 -8 -7 -6 -5 -4 -3 -2 -1 0

MULTIPLICATION:
 * | 1  2  3  4  5  6  7  8  9  10
----------------------------------
1  | 1  2  3  4  5  6  7  8  9  10
2  | 2  4  6  8  10 12 14 16 18 20
3  | 3  6  9  12 15 18 21 24 27 30
4  | 4  8  12 16 20 24 28 32 36 40
5  | 5  10 15 20 25 30 35 40 45 50
6  | 6  12 18 24 30 36 42 48 54 60
7  | 7  14 21 28 35 42 49 56 63 70
8  | 8  16 24 32 40 48 56 64 72 80
9  | 9  18 27 36 45 54 63 72 81 90
10 | 10 20 30 40 50 60 70 80 90 100

For the sake of this challenge, division is excluded.

Sequence definition:

We will follow the same steps for both a 0-indexed and 1-indexed sequence. So the resulting sequence will become f(0)+g(1), f(1)+g(2), etc.

Both f (0-indexed) and g (1-indexed) start in the ADDITION table at (1,1). So f(0) = 1+1 = 2 and g(1) = 1+1 = 2.
We then go to the SUBTRACTION table, and we either go n steps down if n is odd, or n steps to the right if n is even. So f(1) = 1-2 = -1 (it went to the down, because n=1 is odd); and g(2) = 3-1 = 2 (it went right, because n=2 is even).
Then we go to the MULTIPLICATION table, and do the same: f(2) = 3*2 = 6 and g(3) = 3*4 = 12.
And then we go back to the ADDITION table again. Also, when we go beyond the borders of the 10x10 table, we wrap around from the bottom to the top, or from the right to the left. So going from (7,9) six steps right, will end up at (3,9).
The resulting sequence will be f(n)+g(n+1) (with n being 0-indexed).

Here the first six in colors, in the order green → blue → purple → grey → red → orange:

f (0-indexed): (1+1) → (1-2) → (3*2) → (3+5) → (7-5) → (7*10)

enter image description here

g (1-indexed): (1+1) → (3-1) → (3*4) → (7+4) → (7-9) → (3*9)

enter image description here

The resulting sequence is the sum of both these sequences.

Here are the first 100 items of the 0-indexed sequence f:

2,-1,6,8,2,70,13,-4,7,7,-5,7,10,-7,70,12,-2,6,3,0,1,3,1,15,12,-3,30,10,-6,6,7,-6,21,13,-3,35,8,1,2,2,0,2,5,-2,35,17,-7,21,8,-5,6,8,-4,30,17,2,15,5,-1,1,2,-1,6,8,2,70,13,-4,7,7,-5,7,10,-7,70,12,-2,6,3,0,1,3,1,15,12,-3,30,10,-6,6,7,-6,21,13,-3,35,8,1,2,2
Here are the first 100 items of the 1-indexed sequence g:

2,2,12,11,-2,27,9,-5,5,6,-5,18,12,-2,28,7,2,1,11,-9,1,4,-1,28,16,-6,18,7,-4,5,7,-3,27,16,3,12,4,0,10,11,0,3,7,3,63,12,-3,6,6,-4,6,9,-6,63,11,-1,3,2,-9,10,2,2,12,11,-2,27,9,-5,5,6,-5,18,12,-2,28,7,2,1,11,-9,1,4,-1,28,16,-6,18,7,-4,5,7,-3,27,16,3,12,4,0,10,11

Here are the first 100 items of the result sequence:

4,1,18,19,0,97,22,-9,12,13,-10,25,22,-9,98,19,0,7,14,-9,2,7,0,43,28,-9,48,17,-10,11,14,-9,48,29,0,47,12,1,12,13,0,5,12,1,98,29,-10,27,14,-9,12,17,-10,93,28,1,18,7,-10,11,4,1,18,19,0,97,22,-9,12,13,-10,25,22,-9,98,19,0,7,14,-9,2,7,0,43,28,-9,48,17,-10,11,14,-9,48,29,0,47,12,1,12,13

Challenge:
Given an integer n, output the n'th number of the above result sequence (which sums both the 0-indexed and 1-indexed sequences). So calculate h(n) = f(n)+g(n+1).

Challenge rules:
The result-sequence is always 0-indexed. I know some languages are 1-indexed by default, in which case you'll have to do n-1 right after entering the function/program so f(n)+g(n+1) will start at f(0)+g(1) (and not f(1)+g(2)).
Output can be in any reasonable format, so a String or decimal with .0 instead of an integer is allowed.
As you may or may not have noted; in the tables above the number at the top is taken first, then the number at the left.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.
Test cases (0-indexed):
0       4
1       1
2       18
3       19
4       0
5       97
10      -10
50      12
60      4
61      1
62      18
63      19
100     0
111     17
1000    0
1994    98
2497    1
2498    12
2499    13
2500    0

Note/tip: The sequences are self-repeating every 60 items.

*/

package main

func main() {
	tab := []int{
		4, 1, 18, 19, 0, 97, 22, -9, 12, 13, -10, 25, 22, -9, 98,
		19, 0, 7, 14, -9, 2, 7, 0, 43, 28, -9, 48, 17, -10, 11,
		14, -9, 48, 29, 0, 47, 12, 1, 12, 13, 0, 5, 12, 1, 98, 29,
		-10, 27, 14, -9, 12, 17, -10, 93, 28, 1, 18, 7, -10, 11, 4,
		1, 18, 19, 0, 97, 22, -9, 12, 13, -10, 25, 22, -9, 98, 19,
		0, 7, 14, -9, 2, 7, 0, 43, 28, -9, 48, 17, -10, 11, 14, -9,
		48, 29, 0, 47, 12, 1, 12, 13,
	}

	assert(solve(0) == 4)
	assert(solve(1) == 1)
	assert(solve(2) == 18)
	assert(solve(3) == 19)
	assert(solve(4) == 0)
	assert(solve(5) == 97)
	assert(solve(10) == -10)
	assert(solve(50) == 12)
	assert(solve(60) == 4)
	assert(solve(61) == 1)
	assert(solve(62) == 18)
	assert(solve(63) == 19)
	assert(solve(100) == 0)
	assert(solve(111) == 17)
	assert(solve(1000) == 0)
	assert(solve(1994) == 98)
	assert(solve(2497) == 1)
	assert(solve(2498) == 12)
	assert(solve(2499) == 13)
	assert(solve(2500) == 0)

	for i := range tab {
		assert(solve(i) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solve(x int) int {
	lut := []int{
		4, 1, 18, 19, 0, 97, 22, -9, 12, 13, -10, 25, 22, -9, 98, 19,
		0, 7, 14, -9, 2, 7, 0, 43, 28, -9, 48, 17, -10, 11, 14, -9,
		48, 29, 0, 47, 12, 1, 12, 13, 0, 5, 12, 1, 98, 29, -10, 27,
		14, -9, 12, 17, -10, 93, 28, 1, 18, 7, -10, 11,
	}
	return lut[x%len(lut)]
}
