/*

Let me introduce you to GAU numbers
GAU(1) = 1
GAU(2) = 1122
GAU(3) = 1122122333
GAU(4) = 11221223331223334444
GAU(6) = 11221223331223334444122333444455555122333444455555666666
...
GAU(10) = 11221223331223334444122333444455555122333444455555666666122333444455555666666777777712233344445555566666677777778888888812233344445555566666677777778888888899999999912233344445555566666677777778888888899999999910101010101010101010
This challenge is pretty simple!
Given an integer n>0, find the number of digits of GAU(n)

Example
Let's make GAU(4)
we take the following steps (until we get to 4) and concatenate them

[1][122][122333][1223334444]
you must write every number as many times as its value, but you have to count every time from 1

Let's try to make GAU(5)
we will have to count from 1 to 1

[1]
then from 1 to 2 (but repeating every number as many times as its value)

[122]
then from 1 to 3

[122333]
then from 1 to 4

[1223334444]
and finally from 1 to 5 (this is the last step because we want to find GAU(5))

[122333444455555]
Now we take all these steps and concatenate them
the result is GAU(5)

11221223331223334444122333444455555
We are interested in the number of digits of these GAU numbers.

Test cases
Input⟼Output

n   ⟼ Length(GAU(n))

1   ⟼ 1
2   ⟼ 4
3   ⟼ 10
10  ⟼ 230
50  ⟼ 42190
100 ⟼ 339240
150 ⟼ 1295790

This is a code-golf challenge.
Shortest code in bytes will win.

If you still have any questions please let me know.
I really want everyone here to understand this magic-hidden-complex pattern

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	assert(gaulen(1) == 1)
	assert(gaulen(2) == 4)
	assert(gaulen(3) == 10)
	assert(gaulen(10) == 230)
	assert(gaulen(50) == 42190)
	assert(gaulen(100) == 339240)
	assert(gaulen(150) == 1295790)
	for i := 0; i <= 100; i++ {
		assert(gaulen(i) == gaulenbf(i))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gaulen(n int) int {
	r := 0
	for i := 1; i <= n; i++ {
		s := fmt.Sprint(i)
		r += len(s) * i * (n - i + 1)
	}
	return r
}

func gau(n int) string {
	w := new(bytes.Buffer)
	for i := 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			fmt.Fprint(w, strings.Repeat(fmt.Sprint(j), j))
		}
	}
	return w.String()
}

func gaulenbf(n int) int {
	return len(gau(n))
}
