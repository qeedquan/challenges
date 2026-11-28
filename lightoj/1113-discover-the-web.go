/*

Standard web browsers contain features to move backward and forward among the pages recently visited. One way to implement these features is to use two stacks to keep track of the pages that can be reached by moving backward and forward. You are asked to implement this.

The commands are:

BACK: If the backward stack is empty, the command is ignored. Otherwise, push the current page on the top of the forward stack. Pop the page from the top of the backward stack, making it the new current page.
FORWARD: If the forward stack is empty, the command is ignored. Otherwise, push the current page on the top of the backward stack. Pop the page from the top of the forward stack, making it the new current page.
VISIT <url>: Push the current page on the top of the backward stack, and make the URL specified the new current page. The forward stack is emptied.
QUIT: Quit the browser.
The browser initially loads the web page at the URL 'http://www.lightoj.com/'

Input
Input starts with an integer T (≤ 100), denoting the number of test cases.

Each case contains some commands. The keywords BACK, FORWARD, VISIT, and QUIT are all in uppercase. URLs have no whitespace and have at most 50 characters. The end of case is indicated by the QUIT command and it shouldn't be processed. Each case contains at most 100 lines.

Output
For each case, print the case number first. For each command, print the URL of the current page (in a line) after the command is executed if the command is not ignored. Otherwise, print Ignored.

Sample
Input	Output
1
VISIT http://uva.onlinejudge.org/
VISIT http://topcoder.com/
BACK
BACK
BACK
FORWARD
VISIT http://acm.sgu.ru/
BACK
BACK
FORWARD
FORWARD
FORWARD
QUIT

Case 1:
http://uva.onlinejudge.org/
http://topcoder.com/
http://uva.onlinejudge.org/
http://www.lightoj.com/
Ignored
http://uva.onlinejudge.org/
http://acm.sgu.ru/
http://uva.onlinejudge.org/
http://www.lightoj.com/
http://uva.onlinejudge.org/
http://acm.sgu.ru/
Ignored

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	browse([]string{
		"VISIT http://uva.onlinejudge.org/",
		"VISIT http://topcoder.com/",
		"BACK",
		"BACK",
		"BACK",
		"FORWARD",
		"VISIT http://acm.sgu.ru/",
		"BACK",
		"BACK",
		"FORWARD",
		"FORWARD",
		"FORWARD",
		"QUIT",
	})
}

func browse(commands []string) {
	forward := []string{"http://www.lightoj.com/"}
	back := []string{}
loop:
	for _, command := range commands {
		fields := strings.Split(command, " ")
		switch fields[0] {
		case "VISIT":
			if len(forward) == 0 || len(fields) < 2 {
				fmt.Println("Ignored")
				continue loop
			}

			back = append(back, top(forward))
			forward = append(forward[:0], fields[1])

		case "BACK":
			if len(back) == 0 {
				fmt.Println("Ignored")
				continue
			}

			forward = append(forward, top(back))
			back = pop(back)

		case "FORWARD":
			if len(forward) < 2 {
				fmt.Println("Ignored")
				continue loop
			}

			back = append(back, top(forward))
			forward = pop(forward)

		case "QUIT":
			return
		}

		fmt.Println(top(forward))
	}
}

func top(stack []string) string {
	return stack[len(stack)-1]
}

func pop(stack []string) []string {
	return stack[:len(stack)-1]
}
