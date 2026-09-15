#!/usr/bin/env python3

"""

Background
Recently, I was installing updates on my pc with Pacman (I use arch btw) and noticed the order it downloaded files was like this

Start with the largest 4 downloads
When a download completes, start downloading the next biggest file.
Since the biggest file takes the longest to download, you'll often see the second or third biggest actually complete first. Interesting.

Challenge
Given a list of download sizes, eg 50, 40, 30, 20, 11, and the amount of downloads that can be running simultaneously, output the order the downloads will complete (eg 4). Assume all downloads run at the same speed.

Output should be a the sizes of the downloads in the order they complete. The ways to represent a list or the numbers in the list is very flexible.

Worked Out Example
Suppose we have files 50mb, 40mb, 30mb, 20mb, 11mb and an allowed parallelism of 4.

We start downloading the 4 largest, which is the 50, 40, 30, and 20.
The 20mb will complete first. At this point, we start downloading the 11mb file.
The 30mb file now has just 10 megabytes left so it will complete next. Now the 11 mb file has just 1 mb left, so it will finish next.
Now the 40 mb file has 9 mb left, so it will complete second to last.
Finally, the 50 mb file finishes downloading.
Allowed assumptions
You may assume no two downloads will complete at the same time.

You may assume all the sizes will be unique

You may assume all sizes are positive, nonzero integers

You may assume the length of the input list is not less than the given maximum parallelism

Test Cases
[5,4,3,2], 4 -> [2, 3, 4, 5]
[50,40,30,20,11], 4 -> [20, 30, 11, 40, 50]
[50,40,30,20,11,12], 4 -> [20, 30, 12, 40, 11, 50]
[51,40,30,20,11,12,106], 4 -> [30, 40, 20, 51, 12, 11, 106]
[51,40,30,20,11,13,106,500,401,302,201,116,121,1068,1], 6 -> [121, 201, 116, 51, 302, 106, 20, 40, 30, 1, 11, 13, 401, 500, 1068]
[60,50,30,29,20], 4 -> [29, 30, 20, 50, 60]
Feel free to suggest more test cases

Example Code
def download_sort(numbers: list[int], parallelism: int):
    numbers.sort()
    initial = [numbers.pop() for i in range(parallelism)]
    active = [[i,i] for i in initial]
    while len(numbers)>0 or len(active)>0:
        active.sort(key=lambda i:i[1], reverse=True)
        next = active.pop()
        yield next[0]
        for i in active:
            i[1]-=next[1]
        if len(numbers)>0:
            next_value = numbers.pop()
            active.append([next_value, next_value])

"""

def download_sort(numbers: list[int], parallelism: int):
    numbers.sort()
    initial = [numbers.pop() for i in range(parallelism)]
    active = [[i, i] for i in initial]
    while len(numbers) > 0 or len(active) > 0:
        active.sort(key=lambda i:i[1], reverse=True)
        next = active.pop()
        yield next[0]
        for i in active:
            i[1] -= next[1]
        if len(numbers) > 0:
            next_value = numbers.pop()
            active.append([next_value, next_value])

assert(list(download_sort([5, 4, 3, 2], 4)) == [2, 3, 4, 5])
assert(list(download_sort([50, 40, 30, 20, 11], 4)) == [20,  30,  11,  40,  50])
assert(list(download_sort([50, 40, 30, 20, 11, 12], 4)) == [20,  30,  12,  40,  11,  50])
assert(list(download_sort([51, 40, 30, 20, 11, 12, 106], 4)) == [30,  40,  20,  51,  12,  11,  106])
assert(list(download_sort([51, 40, 30, 20, 11, 13, 106, 500, 401, 302, 201, 116, 121, 1068, 1],  6)) == [121,  201,  116,  51,  302,  106,  20,  40,  30,  1,  11,  13,  401,  500,  1068])
assert(list(download_sort([60, 50, 30, 29, 20], 4)) == [29,  30,  20,  50,  60])

