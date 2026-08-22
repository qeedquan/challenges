/*

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

Tips:

The idea is to keep the sum so far and update the sum just by replacing the oldest number with the new entry.

*/

package main

import "fmt"

func main() {
	var m SMA
	m.Init(3)
	fmt.Println(m.Next(1))
	fmt.Println(m.Next(10))
	fmt.Println(m.Next(3))
	fmt.Println(m.Next(5))
}

type SMA struct {
	window []int
	length int
	index  int
	sum    int
}

func (c *SMA) Init(size int) {
	*c = SMA{
		window: make([]int, size),
	}
}

func (c *SMA) Next(value int) float64 {
	if c.length < len(c.window) {
		c.length++
	}

	c.sum = c.sum - c.window[c.index] + value
	c.window[c.index] = value
	c.index = (c.index + 1) % len(c.window)
	return float64(c.sum) / float64(c.length)
}
