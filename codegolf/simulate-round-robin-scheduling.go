/*

Alternatively, guess who's doing a course on operating systems

Round Robin scheduling is a way to schedule ready processes in an operating system. Each process in the queue is run for a certain amount of time (quantum), interrupted after that time (if not yet finished), and then added back to the ready queue for another round.

Your task today is to print the order that tasks are executed in a round robin simulation.

The Challenge
Given a list of [int, int] (both > 0), as well as a quantum, return a list of int representing the order that processes were executed. Assume that all the processes arrive at the same time.

The list of [int, int] represents a (simplified) list of processes. The two ints are the process id and service time (the time the process needs to fully run).

For example:

[[1, 5], [2, 10], [3, 3], [4, 12]]
Represents the following processes

Process ID	Service Time
1	5
2	10
3	3
4	12
The quantum is an integer > 0 that represents the time slice dedicated to each process. A quantum of 4 means that each process is executed for 4 time units before being interrupted and then added to the ready queue.

If a quantum is larger than the time left on a process, then the next process is selected after the running process ends.

Worked Example
Using the above process list ([[1, 5], [2, 10], [3, 3], [4, 12]]), and a quantum of 4, the process execution order will be:

t = 0
             (head)     (tail)
ready queue = [1, 2, 3, 4]
time left = [5, 10, 3, 12]
Select process 1 to run for 4 time units

t = 4
interrupt process 1
              (head)  (tail)
ready queue = [2, 3, 4, 1]
time left = [10, 3, 12, 1]
Select process 2 to run for 4 time units.

t = 8
interrupt process 2
              (head)   (tail)
ready queue = [3, 4, 1, 2]
time left = [3, 12, 1, 6]
Select process 3 to run for 3 time units

t = 11
process 3 finished
             (head)  (tail)
ready queue = [4, 1, 2]
time left = [12, 1, 6]
Select process 4 to run for 4 time units

t = 15
interrupt process 4
             (head)  (tail)
ready queue = [1, 2, 4]
time left = [1, 6, 8]
Select process 1 to run for 1 time unit

t = 16
process 1 finished
              h    t
ready queue = [2, 4]
time left = [6, 8]
Select process 2 to run for 4 time units

t = 20
interrupt process 2
              h     t
ready queue = [4, 2]
time left = [8, 2]
Select process 4 to run for 4 time units

t = 24
interrupt process 4
              h     t
ready queue = [2, 4]
time left = [2, 4]
Select process 2 to run for 2 time units

t = 26
process 2 finished
              h    t
ready queue = [4]
time left = [4]
Select process 4 to run for 4 time units

t = 30
process 4 finished
no more proceses in the queue.
Therefore, the order of processes executed is:

[1, 2, 3, 4, 1, 2, 4, 2, 4]
Rules
Input can be taken as list[list[int, int]], int, list[int], list[int], int, or some other reasonable input method.
The processes and quantum can be taken in any order.
For example:
list[int: processIds]
list[int: serviceTimes]
int: quantum
or

list[int: serviceTimes]
int: quantum
list[int: processIds]
or any other combination.

Output can be list[int], str (joined on newlines, or spaces, or any constant delimiter) or some other reasonable output method.
There will always be at least one process.
The process ids list will always be a permutation of the range [1, number of processes].
The process ids can be 0-indexed if you want it to be for some reason. Using 0-indexing, the ids list will always be a permutation of the range [0, number of processes].
The order of the process ids list is important - processes are executed in the order they arrive (in a first come first serve manner). That is how the ready queue in an actual RR simulation works after all (FCFS selection strategy, with pre-emption on time quantums).

Test Cases
processes, times, quantum => order
[1, 2, 3, 4], [5, 10, 3, 12], 4 => [1, 2, 3, 4, 1, 2, 4, 2, 4]
[5, 4, 3, 2, 1], [20, 20, 20, 20, 20], 4 => [5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1]
[1, 2, 3, 4, 5], [3, 3, 3, 3, 8], 4 => [1, 2, 3, 4, 5, 5]
[1, 2, 3, 4, 5], [3, 3, 10, 3, 8], 2 => [1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 3, 5, 3, 5, 3]
[1], [20], 5 => [1, 1, 1, 1]
[1], [19], 4 => [1, 1, 1, 1, 1]
This is code-golf, so the shortest answer in each language wins.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 2, 3, 4}, []int{5, 10, 3, 12}, 4, []int{1, 2, 3, 4, 1, 2, 4, 2, 4})
	test([]int{5, 4, 3, 2, 1}, []int{20, 20, 20, 20, 20}, 4, []int{5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1, 5, 4, 3, 2, 1})
	test([]int{1, 2, 3, 4, 5}, []int{3, 3, 3, 3, 8}, 4, []int{1, 2, 3, 4, 5, 5})
	test([]int{1, 2, 3, 4, 5}, []int{3, 3, 10, 3, 8}, 2, []int{1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 3, 5, 3, 5, 3})
	test([]int{1}, []int{20}, 5, []int{1, 1, 1, 1})
	test([]int{1}, []int{19}, 4, []int{1, 1, 1, 1, 1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(p, t []int, q int, r []int) {
	x := roundrobin(p, t, q)
	fmt.Println(x)
	assert(reflect.DeepEqual(x, r))
}

func roundrobin(p, t []int, q int) []int {
	r := []int{}
	n := len(p)
	if n == 0 {
		return r
	}

	f, i := true, 0
	for {
		if t[i] > 0 {
			t[i] = max(t[i]-q, 0)
			r = append(r, p[i])
			f = false
		}

		if i++; i >= n {
			if f {
				break
			}
			f, i = true, 0
		}
	}
	return r
}
