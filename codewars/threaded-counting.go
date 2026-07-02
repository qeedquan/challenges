/*

Your task is simple. You have to call counter.count(int) with the numbers 1 to 100 inclusive. So a simple solution might look like this:

for (int i = 1; i <= 100; i++) {
  counter.count(i);
}

But there's a catch. Your solution also has to satisfy the following conditions:

Three different threads must be used
Numbers of the form 3n (multiples of 3) must be called in one thread
Numbers of the form 3n + 1 must be called in a second
Numbers of the form 3n + 2 must be called in a third
The numbers have to be called in sequence 1 to 100
Also, make sure your method doesn't return until all three threads have completed. Otherwise the tests may not work even if your solution is correct.

*/

package main

import "fmt"

func main() {
	for range 5 {
		solve()
	}
}

func solve() {
	limit := 100
	input1 := make(chan int)
	input2 := make(chan int)
	input3 := make(chan int)
	done := make(chan int)

	go count(limit, input1, done)
	go count(limit, input2, done)
	go count(limit, input3, done)

	for i := 1; i <= limit; i++ {
		switch i % 3 {
		case 0:
			input1 <- i
		case 1:
			input2 <- i
		case 2:
			input3 <- i
		}
		<-done
	}
	input1 <- limit + 1
	input2 <- limit + 1
	input3 <- limit + 1
}

func count(limit int, input, done chan int) {
	for {
		value := <-input
		if value > limit {
			break
		}
		fmt.Println(value)
		done <- 1
	}
}
