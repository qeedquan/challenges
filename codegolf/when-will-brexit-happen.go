/*

Well, Brexit happened. And Sky News, being the geniuses they are, have decided to create a countdown on the side of a bus.

https://i.sstatic.net/MCAE7.png

Your job is to do something similar. The UK leaves the the EU on 31st of March 2019 and you have to create a digital countdown for this that changes every second (with a 0.05 second deviation allowed).

Input
Your program should take absolutely no input. It is banned!

Output
It should output the time until Brexit in the format ddd:hh:mm:ss. Leading and trailing newlines are allowed but the display should stay in the same place each time. It should look as though it is actually decreasing in place. As pointed out by @AnthonyPham this doesn't mean printing enough newlines to "clear" the screen, this means that you must actually clear the screen.

An output like this isn't allowed:

100:20:10:05
100:20:10:04
Neither is this

100:20:10:05
*A thousand newlines*
100:20:10:04
as they're on more than one line.

You don't have to worry about after Brexit. Your program only has to work up to 31/3/2019

Rules
Standard loopholes are disallowed
This is code-golf so shortest code in bytes wins.
Error messages (although I can't think how) are disallowed
The code should be able to be run in 2 years time (when the UK leaves the EU) and should display the actual time and not start from 730 again (see below)
Countdown rule
The countdown should not be hard-coded and should be able to run at any time before Brexit finishes and still produce the correct result. When a new day is begun the hour should follow the below format

712:00:00:01
712:00:00:00
711:23:59:59
Let me say again, the date Brexit finishes is 31/3/2019 at midnight for convenience (31:3:19 00:00:00 or 31:3:2019 00:00:00 or any other format you want)

NB: I think I have everything but I didn't post this in the Sandbox, otherwise the timing could have been off. Feel free to post any suggestions for improvements because it isn't perfect.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	brexit()
}

func brexit() {
	T := time.Date(2019, time.March, 31, 0, 0, 0, 0, time.UTC)
	for {
		t := time.Now()
		if t.After(T) {
			fmt.Println("000:00:00:00")
		} else {
			fmt.Println(T.Sub(t))
		}
		time.Sleep(1 * time.Second)
	}
}
