/*

You have a function printNumber that can be called with an integer parameter and prints it to the console.

For example, calling printNumber(7) prints 7 to the console.
You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A: calls zero() that should only output 0's.
Thread B: calls even() that should only output even numbers.
Thread C: calls odd() that should only output odd numbers.
Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

Implement the ZeroEvenOdd class:

ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
void zero(printNumber) Calls printNumber to output one zero.
void even(printNumber) Calls printNumber to output one even number.
void odd(printNumber) Calls printNumber to output one odd number.


Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously.
One of them calls zero(), the other calls even(), and the last one calls odd().
"0102" is the correct output.
Example 2:

Input: n = 5
Output: "0102030405"


Constraints:

1 <= n <= 1000

*/

package main

import (
	"bytes"
	"fmt"
	"sync"
)

func main() {
	test(2, "0102")
	test(5, "0102030405")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r string) {
	s := NewString()
	z := NewZEO(n, s)

	wg := new(sync.WaitGroup)
	wg.Add(3)
	go z.Zero(wg)
	go z.Even(wg)
	go z.Odd(wg)
	wg.Wait()

	fmt.Println(s)
	assert(s.String() == r)
}

type Printer interface {
	Print(n int)
}

type ZEO struct {
	l0, l1, l2 sync.Mutex
	n          int
	p          Printer
}

func NewZEO(n int, p Printer) *ZEO {
	z := &ZEO{
		n: n,
		p: p,
	}
	z.l1.Lock()
	z.l2.Lock()
	return z
}

func (z *ZEO) Zero(wg *sync.WaitGroup) {
	for i := 0; i < z.n; i++ {
		z.l0.Lock()
		z.p.Print(0)
		if i&1 == 0 {
			z.l1.Unlock()
		} else {
			z.l2.Unlock()
		}
	}
	wg.Done()
}

func (z *ZEO) Even(wg *sync.WaitGroup) {
	for i := 2; i <= z.n; i += 2 {
		z.l2.Lock()
		z.p.Print(i)
		z.l0.Unlock()
	}
	wg.Done()
}

func (z *ZEO) Odd(wg *sync.WaitGroup) {
	for i := 1; i <= z.n; i += 2 {
		z.l1.Lock()
		z.p.Print(i)
		z.l0.Unlock()
	}
	wg.Done()
}

type String struct {
	*bytes.Buffer
}

func NewString() *String {
	return &String{
		Buffer: new(bytes.Buffer),
	}
}

func (s *String) Print(n int) {
	fmt.Fprint(s, n)
}
