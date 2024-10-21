/*

The challenge: compute the day of the week from a MM-DD representation of a day in this year (2021).

However, you have to write your program in the following subset of Python: (I chose Python because it's popular and easy to understand even to the people who doesn't know the language. Obviously you can use another program in another language to generate the program, and you're encouraged to post the source code of that program)

# This is the input. For example this represents the date 2021-01-28.
m1 = "0"
m2 = "1"
d1 = "2"
d2 = "8"


T = {
# `T` is a dict
# * each key must be a string of digits [0-9]
# * each value must be a single digit.
"1234": "1",
"5678": "2",
}

# The main program code.
# Each line must have the format:
# <variable_name> = T[<string formed by concatenating string literals or other variables>]
# Example:
variable_1 = T["12" + m1 + "3" + "4"]
output = T[variable_1]

# This must be exactly one `print` statement like this at the end of the program
print(output)
Background: This is basically the only way Preproc (the C/C++ preprocessor) can parse tokens. See how Boost's BOOST_PP_INC_I macro is implemented.

More info:

You can (and should!) submit multiple programs in one answer if the method that you use to generate these programs are similar.
You can reassign variables, but doing that will not make your score better (than labeling each usage of the variables a_1, a_2, a_3, ....
To be clear (this is implied by the rules), you're not allowed to do x = "0" or x = y + z; only x = T[...] is allowed.
The output should be 0 if the day is Monday, 1 if the day is Tuesday, ..., 6 if the day is Sunday.
The program must not raise an error given valid input data.
Winning criteria
Let A about the number of entries in the dict T, and B be the number of assignment instructions (excluding the input assignment instructions to m1, m2, d1, d2 but including the final assignment to output).

You should minimize both A and B.

Note that you can make the length of the keys of the dict T arbitrarily long and it doesn't make the score worse; however it doesn't make the score better either.

Because there isn't a consensus on whether it's allowed to have 2 separate winning criteria, the method to calculate the score is described in this meta answer ("Solution 2"), with the board size 10000 10000. -- For example, if you have a program with A=100 and B=100, enter into the input of the score calculation program

10000 10000
100 100
and the calculated result is 1970199.

Recommended header format
## Score: (5, 1), (4, 2), (3, 3) -> 999, Combined score: 999, Combined score improvement: 99
Score: The (A, B) parameters of your generated program(s), and (optionally) the computed score of all your generated programs.
Combined score: the computed score of all the generated programs of the whole community (all answers posted so far) (you can easily calculate the "combined score" by taking the most recent/best combined score answer, then modify the score-list to add your program's scores. Also you should add a link to the score calculation program with your generated programs' scores as input)
Combined score improvement: the difference between the most-recent computed score and the current combined score.
This is not a requirement, but just in case someone want to write a visualization/leaderboard script. (I intend to have it like this)

Table of all values
Program to verify submissions
Note that this program does not verify that the provided program is inside the subset, only if the output is valid.

import datetime
for month in range(1, 12+1):
    try:
        for day in range(1, 99):
            print(f"{month:02}{day:02} -> {datetime.date(2021, month, day).weekday()}")
    except ValueError: pass

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	for m := 1; m <= 12; m++ {
		for d := 1; d <= 31; d++ {
			t := time.Date(2021, time.Month(m), d, 0, 0, 0, 0, time.UTC)
			if time.Month(m) != t.Month() {
				continue
			}

			m1 := fmt.Sprint(m / 10)
			m2 := fmt.Sprint(m % 10)
			d1 := fmt.Sprint(d / 10)
			d2 := fmt.Sprint(d % 10)

			w1 := day(m1, m2, d1, d2)
			w2 := fmt.Sprint(mod(int(t.Weekday())-1, 7))

			assert(w1 == w2)
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

Ported from @ovs solution

import calendar
import sys

LB = '\n' + ' '*4
T = {}

program = 'T = {' + LB

program += '# three digits: first day of the month, 0-based (12 entries)' + LB
for month in range(1, 13):
    first_day, _ = calendar.monthrange(2021, month)
    key = f'0{month:02}'
    value = str(first_day)
    T[key] = value
    program += f'"{key}": "{value}", '

program += LB

program += '# two digits ab: lookup table for (a + b) % 7 (52 entries)' + LB
for i in range(7):
    for j in range(10 if i==6 else 7):
        key = f'{i}{j}'
        value = str((i+j) % 7)
        T[key] = value
        program += f'"{key}": "{value}", '
    program += LB

program = program.rstrip(' ') + '}'

program += '''

# (d2 + 6) % 7 = (d2 - 1) % 7
d2_0d1 = T["6" + d2]

# (d2 - 1 + 1*d1) % 7
d2_1d1 = T[d1 + d2_0d1]

# (d2 - 1 + 2*d1) % 7
d2_2d1 = T[d1 + d2_1d1]

# (d2 - 1 + 3*d1) % 7 = (d2 - 1 + 10*d1) % 7 = (d1d2 - 1) % 7
day_of_month = T[d1 + d2_2d1]

month_start = T["0" + m1 + m2]

output = T[month_start + day_of_month]'''

for month in range(1, 13):
    first_day, number_of_days = calendar.monthrange(2021, month)
    for day in range(number_of_days):
        target = str((first_day+day) % 7)
        m1, m2, _, d1, d2 = f'{month:02}-{day+1:02}'

        exec(program)

        assert output == target, f'{output} != {target} for {month:02}-{day:02}'

print('All tests passed', file=sys.stderr)
print(len(T), 'dictionary entries', file=sys.stderr)

print(program)

*/

func day(m1, m2, d1, d2 string) string {
	T := map[string]string{
		// three digits: first day of the month, 0-based (12 entries)
		"001": "4", "002": "0", "003": "0", "004": "3", "005": "5", "006": "1", "007": "3", "008": "6", "009": "2", "010": "4", "011": "0", "012": "2",
		// two digits ab: lookup table for (a + b) % 7 (52 entries)
		"00": "0", "01": "1", "02": "2", "03": "3", "04": "4", "05": "5", "06": "6",
		"10": "1", "11": "2", "12": "3", "13": "4", "14": "5", "15": "6", "16": "0",
		"20": "2", "21": "3", "22": "4", "23": "5", "24": "6", "25": "0", "26": "1",
		"30": "3", "31": "4", "32": "5", "33": "6", "34": "0", "35": "1", "36": "2",
		"40": "4", "41": "5", "42": "6", "43": "0", "44": "1", "45": "2", "46": "3",
		"50": "5", "51": "6", "52": "0", "53": "1", "54": "2", "55": "3", "56": "4",
		"60": "6", "61": "0", "62": "1", "63": "2", "64": "3", "65": "4", "66": "5", "67": "6", "68": "0", "69": "1",
	}

	// (d2 + 6) % 7 = (d2 - 1) % 7
	d2_0d1 := T["6"+d2]

	// (d2 - 1 + 1*d1) % 7
	d2_1d1 := T[d1+d2_0d1]

	// (d2 - 1 + 2*d1) % 7
	d2_2d1 := T[d1+d2_1d1]

	// (d2 - 1 + 3*d1) % 7 = (d2 - 1 + 10*d1) % 7 = (d1d2 - 1) % 7
	day_of_month := T[d1+d2_2d1]
	month_start := T["0"+m1+m2]

	return T[month_start+day_of_month]
}

func mod(x, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}
