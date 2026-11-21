/*

Description
Here's a very superstitious hotel elevator in Shanghai:

https://i.stack.imgur.com/cqpmlm.jpg

It avoids the number 13, because thirteen is unlucky in the Western world, and it avoids the digit 4, because four is unlucky in parts of Asia. What if this hotel was taller?

Read a positive even integer n from STDIN, representing the number of floors, and print what the button layout would look like to STDOUT: -1, followed by the next n-1 positive integers that aren't equal to 13 and don't contain digit 4. Arrange these numbers in two columns such as in the above image: print two floor numbers per line, separated by a horizontal tab, so that reading the lines in reverse order from left-to-right yields the sequence in ascending order. (You may optionally print a trailing newline character, too.)

Test cases
For the input 14, output should be as in the above image:

15  16
11  12
9   10
7   8
5   6
2   3
-1  1
where the whitespace in each line is a single horizontal tab character.

For the input 2, you should print -1  1.

For the input 100, you should print:

120 121
118 119
116 117
113 115
111 112
109 110
107 108
105 106
102 103
100 101
98  99
96  97
93  95
91  92
89  90
87  88
85  86
82  83
80  81
78  79
76  77
73  75
71  72
69  70
67  68
65  66
62  63
60  61
58  59
56  57
53  55
51  52
39  50
37  38
35  36
32  33
30  31
28  29
26  27
23  25
21  22
19  20
17  18
15  16
11  12
9   10
7   8
5   6
2   3
-1  1

Goal
This is code-golf. Shortest answer in bytes wins.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	fmt.Println(elevator(14))
	fmt.Println(elevator(100))
}

func elevator(n int) string {
	x := []int{-1}
	for i := 1; i <= 2*n; i++ {
		if strings.Index(fmt.Sprint(i), "4") < 0 && i != 13 {
			x = append(x, i)
		}
	}

	w := new(bytes.Buffer)
	for i := n - 1; i >= 0; i -= 2 {
		fmt.Fprintf(w, "%d\t%d\n", x[i-1], x[i])
	}
	return w.String()
}
