/*

Create a method called wait_on_threads that accepts an array of threads (can be empty) and waits until all of them finish. For example:

thread1 = Thread.new do
  # do somethng
end
thread2 = Thread.new do
  # do somethng else
end

wait_on_threads( [thread1,thread2] )
# Should wait inside the method until both thread1 and thread2
# finish whatever they were doing and exit.
You can read more about threads in wikipedia: http://en.wikipedia.org/wiki/Thread_(computing)

*/

package main

import (
	"fmt"
	"sync"
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
	var wg sync.WaitGroup
	wg.Add(len(f))
	for i := range f {
		go func() {
			f[i]()
			wg.Done()
		}()
	}
	wg.Wait()
}
