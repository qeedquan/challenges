/*

Consider the infinite table of the nonnegative integers with width 12:

 0  1  2  3  4  5  6  7  8  9 10 11
12 13 14 15 16 17 18 19 20 21 22 23
24 25 26 27 28 29 30 31 32 33 34 35
36 37 38 39 40 41 42 43 44 45 46 47
48 49 50 51 52 53 54 55 56 57 58 59
60 61 62 63 64 65 66 67 68 69 70 71...
This can be divided into rectangular chunks 3 wide and 4 tall:

+----------+----------+----------+----------+
|  0  1  2 |  3  4  5 |  6  7  8 |  9 10 11 |
| 12 13 14 | 15 16 17 | 18 19 20 | 21 22 23 |
| 24 25 26 | 27 28 29 | 30 31 32 | 33 34 35 |
| 36 37 38 | 39 40 41 | 42 43 44 | 45 46 47 |
+----------+----------+----------+----------+
| 48 49 50 | 51 52 53 | 54 55 56 | 57 58 59 |
| 60 61 62 | 63 64 65 | 66 67 68 | 69 70 71 |
| 72 73 74 | 75 76 77 | 78 79 80 | 81 82 83 |
| 84 85 86 | 87 88 89 | 90 91 92 | 93 94 95 |
+----------+----------+----------+----------+
|   ....   |   ....   |   ....   |   ....   |
Take the sum of each number in each chunk:

 228  264  300  336
 804  840  876  912
1380 1416 1452 1488...
If you flatten this table, you get an infinite sequence:

228 264 300 336 804 840 876 912 1380 1416 1452 ...
This type of sequence can be found for any positive X, Y, and W where W is the width of the table, X is the width of each chunk, Y is the height of each chunk, and X evenly divides W. In this example, X is 3, Y is 4, and W is 12.

Given X, Y, and W (in any order), output the infinite sequence of the form described above. Alternatively, rather than taking W, you may take W ÷ X, or in other words the number of X-wide chunks in each row. You can assume you will never receive invalid input.

The sequence can be represented by any of the default sequence rules:

Given n, output the nth term of the sequence.
Given n, output the first n terms of the sequence.
Output the sequence indefinitely.
This is code-golf, so the solution with the shortest code in each language wins.

Here are the first few terms of some sample cases:

X Y W  -> seq

3 4 12 -> 228 264 300 336 804 840 876 912 1380 1416 1452
5 4 20 -> 640 740 840 940 2240 2340 2440 2540 3840 3940 4040
1 1 6  -> 0 1 2 3 4 5 6 7 8 9 10
4 2 24 -> 108 140 172 204 236 268 492 524 556 588 620
4 5 24 -> 990 1070 1150 1230 1310 1390 3390 3470 3550 3630 3710
3 5 9  -> 285 330 375 960 1005 1050 1635 1680 1725 2310 2355
3 4 9  -> 174 210 246 606 642 678 1038 1074 1110 1470 1506

*/

package main

func main() {
	test(3, 4, 12, []int{228, 264, 300, 336, 804, 840, 876, 912, 1380, 1416, 1452})
	test(5, 4, 20, []int{640, 740, 840, 940, 2240, 2340, 2440, 2540, 3840, 3940, 4040})
	test(1, 1, 6, []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
	test(4, 2, 24, []int{108, 140, 172, 204, 236, 268, 492, 524, 556, 588, 620})
	test(3, 5, 9, []int{285, 330, 375, 960, 1005, 1050, 1635, 1680, 1725, 2310, 2355})
	test(3, 4, 9, []int{174, 210, 246, 606, 642, 678, 1038, 1074, 1110, 1470, 1506})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, y, w int, r []int) {
	for i := range r {
		assert(f(i, x, y, w) == r[i])
	}
}

/*

@emanresu A

(n,x,y,w)=>x*y*(n*x*y+(--y*w+x-1)/2-n*x%w*y)

Simple numeric formula. They say a picture speaks a thousand words:
https://i.sstatic.net/53cUFrDH.png

This is not an integer division so use formula below to avoid floating point

@G B
Short explanation: first get the first and last number of a chunk, then sum and multiply by x"y/2

*/

func f(n, x, y, w int) int {
	return ((n*x/w)*w*y*2 + ((n*x)%w)*2 + y*w - w - 1 + x) * x * y / 2
}
