#!/usr/bin/env python3

"""

I have a stupid old alarm clock with two buttons: hour and minute. The hour button increments the hour of a set alarm, and minute increments the minute time of a set alarm. However, some smart designers realized that pressing both buttons at the same time should have a meaning, and decided that pressing hour and minute simultaneously would cause the alarm to be set to 12:00 am/0:00. Your task is to simulate this behavior.

Task
Given a start time and a sequence of button states, figure out the end time.

Starting from the start time, increment the hour for each occurrence of (1,0), increment the minute for each occurrence of (0,1), and set the time to 0:00 for each occurrence of (1,1). The states (0,0) should be ignored because they correspond to neither button being pressed.

When adding to minutes and hours, if the minute/hour goes above the maximum, set it to 0, i.e. incrementing a minute value of 59 should set the minute value to 0 and incrementing an hour value of 23 should set the hour value to 0. Incrementing minute/hour values above their limits do not affect the other value, for example incrementing the minute of 10:59 yields 10:00, not 11:00.

Example
Given the input time 13:58 and steps [(0,1),(0,1),(0,1),(0,0),(1,1),(1,0)],

(0,1). This corresponds to minute being pressed. The time is now 13:59.
(0,1). This corresponds to minute being pressed. The time is now 13:00.
(0,1). This corresponds to minute being pressed. The time is now 13:01.
(0,0). This corresponds to neither button being pressed. The time,unaffected, is now 13:01
(1,1). This corresponds to both buttons being pressed. The time is now 0:00.
(1,0) This corresponds to hour being pressed. The time is now 1:00.
Since we end with 1:00, it is the output.

I/O
The input will consist of a time and a sequence of button states. The output is a single time.

The input time and output time may be

a 2-tuple of (hour, minute) or (minute, hour) in 24-hour time such as (13, 30) (hour ranges from 0 to 23 and minute ranges from 0 to 59)
same as the previous but in 12-hour time and a Boolean am/pm switch (hour ranges from 0 to 11 or 12 and 1 to 11 with minute from 0 to 59).
a number of minutes since 0:00 such as 810 (from 0 to 1439, inclusive)
any other format which encodes the same information
The sequence of button states is a representation of a list of Boolean 2-tuples, for example:

a list of tuples: [(0,1),(1,0),(0,0),(1,1)]
a space-delimited string: "01 10 00 11"
a string: "01100011"
in Quaternary: [1,2,0,3]
converted to an integer: 99
any other format which encodes the same information

Test Cases
time,steps -> output
06:49,[(0, 1)] -> 06:50
12:23,[(1, 0)] -> 13:23
02:23,[(0, 1), (1, 0)] -> 03:24
21:40,[(0, 1), (0, 1), (0, 1), (0, 1)] -> 21:44
13:10,[(0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (1, 1), (0, 1), (0, 1)] -> 00:02
21:33,[(1, 0), (0, 1), (1, 0), (0, 1)] -> 23:35
14:21,[(0, 1), (0, 1), (0, 1)] -> 14:24
02:39,[(0, 0), (0, 1)] -> 02:40
16:07,[(0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (1, 0), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (0, 1)] -> 19:16
17:55,[(0, 1), (1, 0), (0, 1)] -> 18:57
15:55,[(1, 0), (1, 0), (1, 0), (0, 1), (0, 1), (0, 1), (1, 0), (1, 0), (0, 1), (1, 0), (1, 0), (0, 1), (1, 0)] -> 23:00
22:11,[(0, 1), (1, 0), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1)] -> 00:19
03:58,[(1, 0), (0, 0), (0, 0), (0, 1), (0, 1), (1, 0), (1, 0), (0, 1), (0, 1), (1, 0), (0, 1)] -> 07:03
13:02,[(0, 1), (1, 0), (0, 1), (1, 0), (0, 1), (0, 1), (1, 0)] -> 16:06
04:37,[(1, 0), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (1, 0), (0, 1), (1, 0)] -> 08:47
00:01,[(0, 1), (1, 0), (1, 0), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (0, 1)] -> 03:08
02:58,[(1, 0), (1, 0), (0, 1)] -> 04:59
01:43,[(0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (1, 0), (0, 1)] -> 04:52
07:54,[(1, 0), (0, 1), (1, 0), (1, 0), (1, 1)] -> 00:00
09:33,[(0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1)] -> 10:38
09:01,[(0, 1), (0, 1)] -> 09:03
19:04,[(0, 1), (1, 0), (0, 1), (1, 0)] -> 21:06
11:17,[(0, 1), (1, 0), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (1, 1), (0, 1), (0, 1)] -> 00:02
19:32,[(0, 1), (1, 0), (0, 1), (1, 0), (1, 0), (1, 0)] -> 23:34
17:31,[(0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (1, 0), (0, 1), (0, 0), (1, 1), (0, 1)] -> 00:01
06:46,[(0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (1, 0), (1, 0), (0, 1), (0, 1), (0, 1), (1, 0), (1, 0), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (1, 0), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (0, 1), (1, 0), (1, 0), (0, 1), (1, 0), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1)] -> 18:16

"""

def sim(time, insts):
    try:
        tok = time.split(':')
        if len(tok) != 2:
            raise Exception()
        hour = int(tok[0])
        minute = int(tok[1])
    except:
        return "invalid time"

    for inst in insts:
        if inst == (0, 1):
            minute = (minute + 1) % 60
        elif inst == (1, 0):
            hour = (hour + 1) % 24
        elif inst == (1, 1):
            hour, minute = 0, 0

    return "%02d:%02d" % (hour, minute)

def main():
    assert(sim("06:49", [(0, 1)]) == "06:50")
    assert(sim("12:23", [(1, 0)]) == "13:23")
    assert(sim("02:23", [(0, 1), (1, 0)]) == "03:24")
    assert(sim("21:40", [(0, 1), (0, 1), (0, 1), (0, 1)]) == "21:44")
    assert(sim("13:10", [(0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (1, 1), (0, 1), (0, 1)]) == "00:02")
    assert(sim("21:33", [(1, 0), (0, 1), (1, 0), (0, 1)]) == "23:35")
    assert(sim("14:21", [(0, 1), (0, 1), (0, 1)]) == "14:24")
    assert(sim("02:39", [(0, 0), (0, 1)]) == "02:40")
    assert(sim("16:07", [(0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (1, 0), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (0, 1)]) == "19:16")
    assert(sim("17:55", [(0, 1), (1, 0), (0, 1)]) == "18:57")
    assert(sim("15:55", [(1, 0), (1, 0), (1, 0), (0, 1), (0, 1), (0, 1), (1, 0), (1, 0), (0, 1), (1, 0), (1, 0), (0, 1), (1, 0)]) == "23:00")
    assert(sim("22:11", [(0, 1), (1, 0), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1)]) == "00:19")
    assert(sim("03:58", [(1, 0), (0, 0), (0, 0), (0, 1), (0, 1), (1, 0), (1, 0), (0, 1), (0, 1), (1, 0), (0, 1)]) == "07:03")
    assert(sim("13:02", [(0, 1), (1, 0), (0, 1), (1, 0), (0, 1), (0, 1), (1, 0)]) == "16:06")
    assert(sim("04:37", [(1, 0), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (1, 0), (0, 1), (1, 0)]) == "08:47")
    assert(sim("00:01", [(0, 1), (1, 0), (1, 0), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (0, 1)]) == "03:08")
    assert(sim("02:58", [(1, 0), (1, 0), (0, 1)]) == "04:59")
    assert(sim("01:43", [(0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (1, 0), (0, 1)]) == "04:52")
    assert(sim("07:54", [(1, 0), (0, 1), (1, 0), (1, 0), (1, 1)]) == "00:00")
    assert(sim("09:33", [(0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1)]) == "10:38")
    assert(sim("09:01", [(0, 1), (0, 1)]) == "09:03")
    assert(sim("19:04", [(0, 1), (1, 0), (0, 1), (1, 0)]) == "21:06")
    assert(sim("11:17", [(0, 1), (1, 0), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (1, 1), (0, 1), (0, 1)]) == "00:02")
    assert(sim("19:32", [(0, 1), (1, 0), (0, 1), (1, 0), (1, 0), (1, 0)]) == "23:34")
    assert(sim("17:31", [(0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (1, 0), (0, 1), (0, 0), (1, 1), (0, 1)]) == "00:01")
    assert(sim("06:46", [(0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (1, 0), (1, 0), (0, 1), (0, 1), (0, 1), (1, 0), (1, 0), (0, 1), (0, 1), (0, 1), (1, 0), (0, 1), (1, 0), (0, 1), (0, 1), (1, 0), (0, 1), (0, 1), (0, 1), (1, 0), (1, 0), (0, 1), (1, 0), (0, 1), (0, 1), (0, 1), (0, 1), (0, 1)]) == "18:16")

main()
