/*

Print the dates of all the Sundays in 2017 in the following format : dd.mm.yyyy.
Expected Output:

01.01.2017
08.01.2017
15.01.2017
22.01.2017
29.01.2017
05.02.2017
12.02.2017
19.02.2017
26.02.2017
05.03.2017
12.03.2017
19.03.2017
26.03.2017
02.04.2017
09.04.2017
16.04.2017
23.04.2017
30.04.2017
07.05.2017
14.05.2017
21.05.2017
28.05.2017
04.06.2017
11.06.2017
18.06.2017
25.06.2017
02.07.2017
09.07.2017
16.07.2017
23.07.2017
30.07.2017
06.08.2017
13.08.2017
20.08.2017
27.08.2017
03.09.2017
10.09.2017
17.09.2017
24.09.2017
01.10.2017
08.10.2017
15.10.2017
22.10.2017
29.10.2017
05.11.2017
12.11.2017
19.11.2017
26.11.2017
03.12.2017
10.12.2017
17.12.2017
24.12.2017
31.12.2017

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	sundays(2017)
}

func sundays(y int) {
	t := time.Date(y, time.January, 1, 0, 0, 0, 0, time.UTC)
	for t.Weekday() != time.Sunday {
		t = t.AddDate(0, 0, 1)
	}

	for {
		fmt.Printf("%02d.%02d.%04d\n", t.Day(), t.Month(), t.Year())
		t = t.AddDate(0, 0, 7)
		if t.Year() != y {
			break
		}
	}
}