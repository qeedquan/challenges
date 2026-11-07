/*

July 1st is Canada day (yay Canada)! Or is it? It seems that the Wikipedia page for this day has a lot of Canada related content, but is there another day which is more Canadian?

Your task is to write a program or function which takes a date (month and day) as input and returns or outputs the number of mentions of "Canada" on the Wikipedia page for the inputed date. Some rules:

Dates may be input in any reasonable format of your choice
Your submission must pull data from the url en.wikipedia.org/wiki/Month_Day.
Only "Canada" must be searched for and counted included substrings, and only in title case. "Canadian" does not count, however "Canada's" does count. As long as the exact, case-senstitive text "Canada" exists within a string, it is a match
Contents of the page are considered anything within the corresponding .html file (i.e. what shows up if you download as page as a .html and open it in Notepad)
Result may be output to STDOUT, returned, or displayed in any other reasonable manner
Test Cases:

July 1 => 34
May 14 => 1
Oct 31 => 2
July 4 => 2
This is code golf, so shortest submission wins

(As an unrewarded bonus, I'm interested to see what the day with the highest count is)

*/

package main

import (
	"fmt"
	"io"
	"net/http"
	"strings"
)

func main() {
	fmt.Println(canada("July", "1"))
	fmt.Println(canada("May", "14"))
	fmt.Println(canada("Oct", "31"))
	fmt.Println(canada("July", "4"))
}

func canada(month, day string) (int, error) {
	url := fmt.Sprintf("http://en.wikipedia.org/wiki/%v_%v", month, day)
	resp, err := http.Get(url)
	if err != nil {
		return 0, err
	}

	data, err := io.ReadAll(resp.Body)
	if err != nil {
		return 0, err
	}

	return strings.Count(string(data), "Canada"), nil
}
