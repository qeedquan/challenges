/*

LeetCode company workers use key-cards to unlock office doors. Each time a worker uses their key-card, the security system saves the worker's name and the time when it was used.
The system emits an alert if any worker uses the key-card three or more times in a one-hour period.

You are given a list of strings keyName and keyTime where [keyName[i], keyTime[i]] corresponds to a person's name and the time when their key-card was used in a single day.

Access times are given in the 24-hour time format "HH:MM", such as "23:51" and "09:49".

Return a list of unique worker names who received an alert for frequent keycard use. Sort the names in ascending order alphabetically.

Notice that "10:00" - "11:00" is considered to be within a one-hour period, while "22:51" - "23:52" is not considered to be within a one-hour period.

Example 1:

Input: keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
Output: ["daniel"]
Explanation: "daniel" used the keycard 3 times in a one-hour period ("10:00","10:40", "11:00").

Example 2:

Input: keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
Output: ["bob"]
Explanation: "bob" used the keycard 3 times in a one-hour period ("21:00","21:20", "21:30").

Constraints:

1 <= keyName.length, keyTime.length <= 10^5
keyName.length == keyTime.length
keyTime[i] is in the format "HH:MM".
[keyName[i], keyTime[i]] is unique.
1 <= keyName[i].length <= 10
keyName[i] contains only lowercase English letters.

Hint 1
Group the times by the name of the card user, then sort each group

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(
		[]string{"daniel", "daniel", "daniel", "luis", "luis", "luis", "luis"},
		[]string{"10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00"},
		[]string{"daniel"},
	)

	test(
		[]string{"alice", "alice", "alice", "bob", "bob", "bob", "bob"},
		[]string{"12:01", "12:00", "18:00", "21:00", "21:20", "21:30", "23:00"},
		[]string{"bob"},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(names, times, expected []string) {
	result := alert(names, times)
	fmt.Println(result)
	assert(reflect.DeepEqual(result, expected))
}

func alert(names, times []string) []string {
	records := map[string][]int{}
	for index, name := range names {
		var hour, minute int
		fmt.Sscanf(times[index], "%d:%d", &hour, &minute)
		records[name] = append(records[name], hour*60+minute)
	}

	result := []string{}
	for name, time := range records {
		sort.Ints(time)
		for index := range len(time) - 2 {
			if time[index+2]-time[index] <= 60 {
				result = append(result, name)
				break
			}
		}
	}
	sort.Strings(result)
	return result
}
