/*

The objective of this question is to create a program that pushes your computer's internal fan speed to its maximum RPM. Upon exiting the program, your fan should return to the normal operating RPM.

Rules:

You may not perform a CPU intensive task in order to modify the fan's speed.
Exiting the program may be via user input, a timeout period, or a response to a SIGTERM or SIGEXIT signal.
Avoid the standard loopholes.

*/

package main

import (
	"flag"
	"runtime"
	"time"
)

var (
	delay = flag.Duration("delay", 0, "delay time")
)

func main() {
	flag.Parse()
	for range runtime.NumCPU() {
		go worker()
	}
	worker()
}

func worker() {
	for {
		if *delay > 0 {
			time.Sleep(*delay)
		}
	}
}
