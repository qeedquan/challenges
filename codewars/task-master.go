/*

While writing some code, you ran into a problem. Your code runs very slowly, because you need to run many functions.

You do a bit of troubleshooting and notice that you are not draining your system's resources.

Write a function that, given a list of "slow" functions, will return the sum of the results without waiting for each function to complete individually.

*/

package main

import (
	"fmt"
	"math/rand"
	"sync"
	"sync/atomic"
)

type fn func() int64

func main() {
	ftab := []fn{one, two, three, four, five, six, seven, eight, nine, ten}
	f := []fn{}
	for range 1000 {
		i := rand.Intn(len(ftab))
		f = append(f, ftab[i])
	}
	fmt.Println(sum(f))
}

func sum(f []fn) int64 {
	var (
		wg sync.WaitGroup
		r  int64
	)
	wg.Add(len(f))
	for i := range f {
		go func() {
			atomic.AddInt64(&r, f[i]())
			wg.Done()
		}()
	}
	wg.Wait()
	return r
}

func one() int64   { fmt.Println("one"); return 1 }
func two() int64   { fmt.Println("two"); return 2 }
func three() int64 { fmt.Println("three"); return 3 }
func four() int64  { fmt.Println("four"); return 4 }
func five() int64  { fmt.Println("five"); return 5 }
func six() int64   { fmt.Println("six"); return 6 }
func seven() int64 { fmt.Println("seven"); return 7 }
func eight() int64 { fmt.Println("eight"); return 8 }
func nine() int64  { fmt.Println("nine"); return 9 }
func ten() int64   { fmt.Println("ten"); return 10 }
