/*

A group of students of Computer Science were studying the performance of the following generator in Python 2 and Python 3.

def permut(iterable):
    if len(iterable) <=1: yield iterable
    else:
        for perm in permut(iterable[1:]):
            for i in range(len(iterable)):
                yield perm[:i] + iterable[0:1] + perm[i:]
As you can see, the code above may generate in a "lazy" way, all the permutations for a string or an array(iterable input). In order to estimate how the runtime goes up when the length of the iterable increases, they introduced a counter as it follows below.

counter = 0
def permut(iterable):
    global counter
    if len(iterable) <=1: yield iterable
    else:
        for perm in permut(iterable[1:]):
            for i in range(len(iterable)):
                counter += 1
                yield perm[:i] + iterable[0:1] + perm[i:]
For the string abc they got 6 different permutations, as expected, but the counter went up to 8    .

They also tried the code in a super computer for the array = [1,2,3,4,5,6,7,8,9,10,11,12,13] and the counter value for the run reached up to 6749977112.

Could you create a code that can predict the value of the counter for different entries?

Random tests will include arrays or strings of length up to 200.

*/

package main

import (
	"fmt"
	"math/big"
)

func main() {
	tab := []int64{
		1, 2, 8, 32, 152, 872, 5912, 46232, 409112, 4037912, 43954712,
		522956312, 6749977112, 93928268312, 1401602636312, 22324392524312,
		378011820620312, 6780385526348312, 128425485935180312, 2561327494111820312,
	}

	test([]int{'a', 'b', 'c'}, 8)
	test([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}, 6749977112)
	for i := range tab {
		assert(count(int64(i)+1).Int64() == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, r int64) {
	x := count(int64(len(a)))
	fmt.Println(x)
	assert(x.Int64() == r)
}

// https://oeis.org/A054116
func count(n int64) *big.Int {
	if n < 1 {
		return big.NewInt(0)
	}
	if n == 1 {
		return big.NewInt(1)
	}
	if n == 2 {
		return big.NewInt(2)
	}

	u1 := big.NewRat(1, 1)
	u2 := big.NewRat(0, 1)
	z := big.NewRat(-1, 1)
	f := big.NewRat(2, 1)
	r := new(big.Rat)
	for i := int64(3); i <= n+1; i++ {
		ut := big.NewRat(i, 1)
		u3 := new(big.Rat)
		u3.Set(z)
		u3.Quo(u3, ut)
		u3.Mul(u3, u1)
		u3.Add(u3, u2)
		u1 = u2
		u2 = u3

		f.Mul(f, ut)
		r.Set(u3)
		r.Neg(r)
		r.Mul(r, f)
	}
	return r.Num()
}
