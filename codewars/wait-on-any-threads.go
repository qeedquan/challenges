/*

Create a method called wait_for_thread that accepts an array of threads (can be empty), waits until any of them finishes and returns that thread. Exit immediately and return nil if an empty array is given.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	execute([]func(){
		sleeper(1),
		sleeper(2),
		sleeper(3),
	})
}

func sleeper(n time.Duration) func() {
	return func() {
		time.Sleep(n * time.Second)
		fmt.Printf("%d: done\n", n)
	}
}

func execute(f []func()) {
	if len(f) == 0 {
		return
	}

	ch := make(chan int, len(f))
	for i := range f {
		go func() {
			f[i]()
			ch <- 1
		}()
	}
	<-ch
}
