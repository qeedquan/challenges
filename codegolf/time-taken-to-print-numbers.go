/*

Summary
Write a program or function, which doesn't take any input, and outputs all the integer numbers, between -1000 and 1000 in ascending order, to the stdout, one per line, like this:

-1000
-999
-998
-997
...
And after that you need to print the time taken to print these numbers, or the time from the start of the program's execution in milliseconds (if necessary, it can also contain some other things, for example: time taken:xxxms is ok). It can be a float, or an integer (if you print an integer, you need to round down to the nearest).

Example code
using System;
using System.Diagnostics;
class P
{
    static void Main(string[] args)
    {
        Stopwatch st = Stopwatch.StartNew();
        for (int i = -1000; i <= 1000; i++)
        {
            Console.WriteLine(i);
        }
        Console.WriteLine(st.ElapsedMilliseconds);
    }
}
Restrictions
Standard loopholes are not allowed

Other infos
It's code golf, so the shortest submission wins.

*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"time"
)

func main() {
	wrote(bufio.NewWriter(os.Stdout), 1000)
}

func wrote(w *bufio.Writer, n int) {
	t := time.Now()
	for i := -n; i <= n; i++ {
		fmt.Fprintln(w, i)
	}
	fmt.Fprintln(w, "took", time.Since(t))
	w.Flush()
}
