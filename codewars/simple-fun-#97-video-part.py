#!/usr/bin/env python3

"""

Task
You have been watching a video for some time. Knowing the total video duration find out what portion of the video you have already watched.

Example
For part = "02:20:00" and total = "07:00:00", the output should be [1, 3].

You have watched 1 / 3 of the whole video.

Input/Output
[input] string part

A string of the following format "hh:mm:ss" representing the time you have been watching the video.

[input] string total

A string of the following format "hh:mm:ss" representing the total video duration.

[output] an integer array

An array of the following format [a, b] (where a / b is a reduced fraction).

"""

from math import gcd

def parsetime(time):
    fields = time.split(':')
    hour = int(fields[0])
    minute = int(fields[1])
    second = int(fields[2])
    return hour*3600 + minute*60 + second


def videopart(part, total):
    try:
        time0 = parsetime(part)
        time1 = parsetime(total)
        multiple = gcd(time0, time1)
        time0 //= multiple
        time1 //= multiple
        return (time0, time1)
    except:
        return (-1, -1)

def main():
    assert(videopart("02:20:00", "07:00:00") == (1, 3))
    assert(videopart("25:26:20", "25:26:20") == (1, 1))
    assert(videopart("00:02:20", "00:10:00") == (7, 30))

main()

