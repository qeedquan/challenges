/*

Background
Some holidays have fixed, easy-to-remember dates, like Oct 31, Dec 25, etc. Some, however, want to be troublesome. They're specified as things like "the first Monday in September" or "the fourth Thursday in November". How am I supposed to know when that is?

All I know is that Thanksgiving is fast approaching, so I need a program to help me figure out when it is. Some people even say that it's tomorrow, so your program needs to be as short as possible to make sure I can re-type it in time.

The Challenge
Create a program or function that, given an up-to-four-digit year (e.g. 2015 or 1984), outputs or returns the date of the United States' Thanksgiving in that year. Thanksgiving is defined as the fourth Thursday of November according to the Wikipedia page. (Hint: that page also includes some interesting information on the date pattern.)

Input: a decimal number with a maximum of four digits representing a year in the Common Era (C.E.). Examples: 987, 1984, 2101

Output: the date, including month and day, on which Thanksgiving falls, or would fall if it existed, in that year. This may be in any reasonable format; use your best judgment. Use the Gregorian Calendar in all cases, even if it was not in use at the time.

(Note: Make sure to handle leap years correctly!)

Test cases Input 1:

2015
Output 1:

Nov 26
Input 2:

1917
Output 2:

Nov 22
Scoring
Submissions will be scored in bytes. I recommend this website to keep track of your byte count, though you can use any counter you like.

Bonuses
-25% to your score if you handle B.C.E. dates as negative numbers (e.g. -480 would be the year of the battle of Thermopylae).

Negative test case input:

-480
Corresponding output:

Nov 25
This is code-golf, so the lowest score wins!

Edit: I am marking Thomas Kwa's TI-BASIC submission as accepted. Don't let this discourage you from submitting new entries!

Leaderboards
Here is a Stack Snippet to generate both a regular leaderboard and an overview of winners by language.

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

# Language Name, N bytes
where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

# Ruby, <s>104</s> <s>101</s> 96 bytes
If there you want to include multiple numbers in your header (e.g. because your score is the sum of two files or you want to list interpreter flag penalties separately), make sure that the actual score is the last number in the header:

# Perl, 43 + 2 (-p flag) = 45 bytes
You can also make the language name a link which will then show up in the leaderboard snippet:

# [><>](http://esolangs.org/wiki/Fish), 121 bytes

*/

package main

import (
	"time"
)

func main() {
	assert(thanksgiving(2015) == "Nov 26")
	assert(thanksgiving(1917) == "Nov 22")
	assert(thanksgiving(-480) == "Nov 25")
	assert(thanksgiving(1950) == "Nov 23")
	assert(thanksgiving(1952) == "Nov 27")
	assert(thanksgiving(1970) == "Nov 26")
	assert(thanksgiving(2023) == "Nov 23")
	assert(thanksgiving(1984) == "Nov 22")
	assert(thanksgiving(1985) == "Nov 28")
	assert(thanksgiving(1986) == "Nov 27")
	assert(thanksgiving(1987) == "Nov 26")
	assert(thanksgiving(1988) == "Nov 24")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func thanksgiving(y int) string {
	off := []int{4, 3, 2, 1, 0, 6, 5}
	t := time.Date(y, time.November, 1, 0, 0, 0, 0, time.UTC)
	w := t.Weekday()
	t = t.AddDate(0, 0, off[w]+3*7)
	return t.Format("Jan 02")
}
