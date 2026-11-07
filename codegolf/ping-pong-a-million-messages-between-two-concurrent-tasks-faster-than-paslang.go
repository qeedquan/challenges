/*

Two concurrent tasks pass an integer back and forth one million times. The reference implementation is written in paslang, a Pascal dialect with a Go-style runtime. It does the million round trips in 0.071 s on my machine; the same program in Go takes 0.229 s. Can a compiled language beat it?

Disclosure: I am the author of paslang (https://github.com/garacil/paslang).

The task
Start a second task, B, from the main task, A. A task is any independent flow of control with its own stack: an OS thread, a green thread, a goroutine, a fiber, a coroutine or a process.
The tasks exchange values through a synchronous, one-slot handoff (a rendezvous): the sender cannot run on until the receiver has taken the value.
A starts with x = 0 and repeats 1,000,000 times: send x to B, then receive the reply into x.
For each value n it receives, B sends back n + 1.
A then tells B to stop (for example, by sending -1), B ends, and A prints x, which must be 1000000.
Rules:

Every round trip must go through the handoff. No batching, no computing the result directly, and no merging A and B into one loop.
Any language compiled ahead of time to native code: C, C++, Rust, Zig, Go, Nim, D, Pascal, and so on.
You may use the language's standard library, a well-known library, or your own code for the tasks and the handoff.
Scoring
I will time every answer on the same machine: an AMD Ryzen 9 5950X (16 cores, 32 threads) running Linux, compiled with the flags you give. Your score is the median wall-clock time of 10 runs of the whole process; lower wins. I will also report the CPU time (user + system), as information only.

Reference timings on that machine (median of 9 runs):

Program	Wall	CPU
paslang 1.1.1	0.071 s	0.142 s
Go (goroutines and unbuffered channels)	0.229 s	0.254 s
Reference implementation (paslang)
program pingpong;

var
  a, b: chan of Integer;
  i, x: Integer;

procedure Pong;
var
  n: Integer;
begin
  repeat
    n := Recv(a);
    if n >= 0 then
      Send(b, n + 1);
  until n < 0;
end;

begin
  a := MakeChan();
  b := MakeChan();
  pas Pong;
  x := 0;
  for i := 1 to 1000000 do
  begin
    Send(a, x);
    x := Recv(b);
  end;
  Send(a, -1);
  WriteLn(x);
end.
The same program in Go
package main

import "fmt"

func main() {
    a := make(chan int)
    b := make(chan int)
    go func() {
        for {
            n := <-a
            if n < 0 {
                return
            }
            b <- n + 1
        }
    }()
    x := 0
    for i := 0; i < 1000000; i++ {
        a <- x
        x = <-b
    }
    a <- -1
    fmt.Println(x)
}

*/

package main

import "fmt"

func main() {
	a := make(chan int)
	b := make(chan int)
	go func() {
		for {
			n := <-a
			if n < 0 {
				return
			}
			b <- n + 1
		}
	}()
	x := 0
	for i := 0; i < 1000000; i++ {
		a <- x
		x = <-b
	}
	a <- -1
	fmt.Println(x)
}
