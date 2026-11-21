/*

Given an input of a single positive integer, output the "cross-alternate sum" that corresponds to that integer.

Take the example of the input n=5. To find the cross-alternate sum, first create a square grid of width and height n that, reading from left to right and top to bottom, starts at 1 and increases by one each position:

 1  2  3  4  5
 6  7  8  9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
Then, take the sums from the grid that form a "cross" (that is, both diagonals combined):

 1           5
    7     9
      13
   17    19
21          25

1 5 7 9 13 17 19 21 25
Finally, take the alternating sum of this sequence:

1+5-7+9-13+17-19+21-25

-11
Another example, for n=6 (just to show what the cross looks like for even-numbered n):

 1  2  3  4  5  6
 7  8  9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24
25 26 27 28 29 30
31 32 33 34 35 36

 1              6
    8       11
      15 16
      21 22
   26       29
31             36

1+6-8+11-15+16-21+22-26+29-31+36

20
Since this is code-golf, the shortest code in bytes will win.

Here are the correct outputs for n=1 to n=100, which you can use as test cases:

1
4
-3
10
-11
20
-23
34
-39
52
-59
74
-83
100
-111
130
-143
164
-179
202
-219
244
-263
290
-311
340
-363
394
-419
452
-479
514
-543
580
-611
650
-683
724
-759
802
-839
884
-923
970
-1011
1060
-1103
1154
-1199
1252
-1299
1354
-1403
1460
-1511
1570
-1623
1684
-1739
1802
-1859
1924
-1983
2050
-2111
2180
-2243
2314
-2379
2452
-2519
2594
-2663
2740
-2811
2890
-2963
3044
-3119
3202
-3279
3364
-3443
3530
-3611
3700
-3783
3874
-3959
4052
-4139
4234
-4323
4420
-4511
4610
-4703
4804
-4899
5002

*/

package main

func main() {
	tab := []int{
		1, 4, -3, 10, -11, 20, -23, 34, -39, 52, -59, 74, -83, 100, -111, 130,
		-143, 164, -179, 202, -219, 244, -263, 290, -311, 340, -363, 394, -419,
		452, -479, 514, -543, 580, -611, 650, -683, 724, -759, 802, -839, 884,
		-923, 970, -1011, 1060, -1103, 1154, -1199, 1252, -1299, 1354, -1403,
		1460, -1511, 1570, -1623, 1684, -1739, 1802, -1859, 1924, -1983, 2050,
		-2111, 2180, -2243, 2314, -2379, 2452, -2519, 2594, -2663, 2740, -2811,
		2890, -2963, 3044, -3119, 3202, -3279, 3364, -3443, 3530, -3611, 3700,
		-3783, 3874, -3959, 4052, -4139, 4234, -4323, 4420, -4511, 4610, -4703,
		4804, -4899, 5002,
	}

	for i, v := range tab {
		assert(crossaltsum(i+1) == v)
	}

	for i := 0; i <= 10000; i++ {
		assert(crossaltsum(i) == crossaltsumbf(i))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func crossaltsum(n int) int {
	if n < 1 {
		return 0
	}

	if n == 1 {
		return 1
	}

	x := n >> 1
	if n&1 != 0 {
		return -2*x*x - 2*x + 1
	}
	return 2*x*x + 2
}

func crossaltsumbf(n int) int {
	if n < 1 {
		return 0
	}

	r := 2
	if n&1 != 0 {
		r -= (n+1)*(n-1)/2 + 1
	}

	for i := 0; i < n/2; i++ {
		r += diag(i, n)
	}

	s := 1 - 2*(n&1)
	for i := n / 2; i < n; i++ {
		r += s * diag(i, n)
	}

	return r
}

func diag(i, n int) int {
	x := (n+1)*i + 1
	y := (n-1)*(i+1) + 1
	if x > y {
		x, y = y, x
	}
	return -x + y
}
