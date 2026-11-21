/*

I found another sequence not yet in the OEIS

The binary expansion sequence is defines as follows, assuming 0 indexing:

The even numbers of the sequence are how often 0 has appeared in the binary expansion of all previous items in the sequence
The odd elements are the same, but for 1s.
If you choose to 1-index, reverse "even" and "odd" in the description above to get the same sequence.

Leave at least one digit in the binary expansion.

Thus the first terms are:

0, because this is even, we count the numbers of 0s. There are none
0, because this is odd, we count the 1s. There are none
2, because this is even, we count the 0s, there has been 2 zeros
1 next, the number 2 had 1 1
3, two zeros from the first 2 terms, 1 from 2
4, 1 from 2, 1 from 1, 2 from 3
First 200 terms:

0
0
2
1
3
4
5
7
6
12
9
16
15
21
17
26
22
32
29
37
33
42
40
47
45
56
50
62
54
71
59
80
65
84
74
90
81
97
89
104
96
109
103
119
106
129
115
136
123
144
130
148
141
155
148
163
157
172
164
179
172
188
179
198
186
207
191
220
195
229
202
238
208
247
214
259
223
269
229
278
237
288
246
296
254
306
260
312
272
318
282
328
293
335
301
346
309
356
318
366
324
375
332
386
343
395
350
406
357
416
367
426
373
437
379
450
386
457
396
466
405
476
412
487
418
498
426
509
431
524
440
532
451
540
461
550
470
560
480
567
489
579
498
589
506
601
513
608
528
613
541
623
549
634
559
646
569
655
578
664
591
674
601
683
610
693
620
704
632
712
643
720
655
730
663
742
671
755
677
767
683
782
692
792
703
804
711
814
719
827
725
840
735
852
742
863
748
877
755
891

Sequence rules apply, you may either:

Given n, output the nth element of the sequence
Given n, output the first N terms
Output the sequence infinity
Either 0 or 1 based indexing is acceptable.

*/

package main

import (
	"math/bits"
)

func main() {
	tab := []int{
		0, 0, 2, 1, 3, 4, 5, 7, 6, 12, 9, 16, 15, 21, 17, 26, 22, 32,
		29, 37, 33, 42, 40, 47, 45, 56, 50, 62, 54, 71, 59, 80, 65,
		84, 74, 90, 81, 97, 89, 104, 96, 109, 103, 119, 106, 129,
		115, 136, 123, 144, 130, 148, 141, 155, 148, 163, 157, 172,
		164, 179, 172, 188, 179, 198, 186, 207, 191, 220, 195, 229,
		202, 238, 208, 247, 214, 259, 223, 269, 229, 278, 237, 288,
		246, 296, 254, 306, 260, 312, 272, 318, 282, 328, 293, 335,
		301, 346, 309, 356, 318, 366, 324, 375, 332, 386, 343, 395,
		350, 406, 357, 416, 367, 426, 373, 437, 379, 450, 386, 457,
		396, 466, 405, 476, 412, 487, 418, 498, 426, 509, 431, 524,
		440, 532, 451, 540, 461, 550, 470, 560, 480, 567, 489, 579,
		498, 589, 506, 601, 513, 608, 528, 613, 541, 623, 549, 634,
		559, 646, 569, 655, 578, 664, 591, 674, 601, 683, 610, 693,
		620, 704, 632, 712, 643, 720, 655, 730, 663, 742, 671, 755,
		677, 767, 683, 782, 692, 792, 703, 804, 711, 814, 719, 827,
		725, 840, 735, 852, 742, 863, 748, 877, 755, 891,
	}

	for i, v := range tab {
		assert(seq(i) == v)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var cache = make(map[int]int)

/*

@Arnauld

c0 = count number of zeroes in value
c1 = count number of ones in value

a(0) = a(1) = 0
a(n) = c[n%2](a(n - 1)) + c[n%2](a(n - 2)) + a(n - 2)

*/

func seq(n int) int {
	if n < 2 {
		return 0
	}

	if r, ok := cache[n]; ok {
		return r
	}

	f := count0
	if n&1 != 0 {
		f = count1
	}

	x := seq(n - 1)
	y := seq(n - 2)
	cache[n] = f(x) + f(y) + y
	return cache[n]
}

func count0(n int) int {
	if n == 0 {
		return 1
	}

	m := 1<<(bits.UintSize-bits.LeadingZeros(uint(n))) - 1
	return bits.OnesCount(uint(^n & m))
}

func count1(n int) int {
	return bits.OnesCount(uint(n))
}
