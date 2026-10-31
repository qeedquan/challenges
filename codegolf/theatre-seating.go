/*

Task
A theatre has 10 rows, labelled A to J from front to back, and 15 seats in each row, numbered 1 to 15 from left to right.

The program uses the following rules to choose the best seats.

Rule 1: All seats in one booking must be in the same row, next to each other.
Rule 2: The seats must be as close to the front as possible, then as close to the left as possible (lowest letter, then lowest number)
Write a function which takes the number of tickets wanted as an integer input (n), and outputs the best seats available in a list of length n.

Your program should:

Output -1 if 1 > Input or Input > 15*
Output -1 if the seats aren't available*
Have a function B(n) that the user can use to input the desired number of seats.
*You can output the -1 in a list if it makes it easier

Examples
I/O
Calling B(5) on a new array should return [A1, A2, A3, A4, A5]
Calling B(2) after that should then return [A6, A7]
Calling B(10) after that should then return [B1, B2, ... B9, B10]
Calling B(-1) should always return -1

Un-golfed Solution Python
Theatre = [ [False] * 16 ] * 11

def B(n):
    if 0 <= n <= 15:
        for i in range(10):
            for j in range(15-n+1):
                try:
                    if not Theatre[i][j]:
                        if not Theatre[i][j + n]:
                            row = i
                            start = j
                            List = []
                            for q in range(n):
                                List.append(chr(row + 65) + str(start + q + 1))
                                Theatre[row][start + q] = True
                            return List
                except:
                    break
    return -1

*/

package main

import "fmt"

func main() {
	var s Seats
	fmt.Println(s.Assign(5))
	fmt.Println(s.Assign(2))
	fmt.Println(s.Assign(10))
	fmt.Println(s.Assign(-1))
}

// Ported from @celie56 solution
type Seats [10]int

func (s *Seats) Assign(n int) []string {
	r := []string{}
	for i := 0; i < 10 && (0 < n && n < 16); i++ {
		if 15-s[i] < n {
			continue
		}

		l := 'A' + i
		for j := s[i]; j < n+s[i]; j++ {
			r = append(r, fmt.Sprintf("%c%d", l, j+1))
		}
		s[i], n = s[i]+n, 0
	}

	if len(r) == 0 {
		r = append(r, "-1")
	}

	return r
}
