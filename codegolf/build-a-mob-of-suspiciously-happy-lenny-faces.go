/*

I was going through a bizarre thread on Reddit, and came across this:

( ͡°( ͡° ͜ʖ( ͡° ͜ʖ ͡°)ʖ ͡°) ͡°)

It's representing a group of people smiling somewhat suspiciously.

(In the challenge below though, spaces to the left of the right eyes were dropped somehow while I was writing the challenge. Note the spec).

Your goal is to create a group of smiling lenny faces n deep with the following rules:

    At depth one, a full face (( ͡° ͜ʖ ͡°)) is shown.
    At depth two, half faces are shown. On the left side, a little over half the face (( ͡° ͜ʖ) is represented. On the right however, the right side is shown, and the mouth is omitted (ʖ ͡°))
    Any deeper, and only the sides of head and eyes are shown (( ͡° and ͡°). There's a space between the eye and left side of the head, but there are, despite appearances, no spaces on the right side. The spacing is due the ͡ character which messes with things a bit.

Input:

    n, showing how many layers deep of faces to show.
    n will always be in the range 0 <= n <= 500. You are not required to handle anything outside of this range.
    n may be offset by 1 so that 0 means one face instead of no faces. You'll need to handle -1 then though.

Output:

    A string, or character array, or anything remotely comparable (like a list of single-character strings in Python/Javascript). It can also be printed directly. Trailing white-space is fine.

You can submit a complete program, or a function.

Since it's difficult to see what characters are involved, here's it laid out in Python:

>> [ord(c) for c in '( ͡° ͜ʖ ͡°)']
[40, 32, 865, 176, 32, 860, 662, 32, 865, 176, 41]

>> [ord(c) for c in '( ͡°( ͡°( ͡° ͜ʖ( ͡° ͜ʖ ͡°)ʖ ͡°)͡°)͡°)']
[40, 32, 865, 176, 40, 32, 865, 176, 40, 32, 865, 176, 32, 860, 662, 40, 32, 865, 176, 32, 860, 662, 32, 865, 176, 41, 662, 32, 865, 176, 41, 865, 176, 41, 865, 176, 41]

Test Cases:

face_crowd(0)
''

face_crowd(1)
'( ͡° ͜ʖ ͡°)'

face_crowd(2)
'( ͡° ͜ʖ( ͡° ͜ʖ ͡°)ʖ ͡°)'

face_crowd(5)
'( ͡°( ͡°( ͡°( ͡° ͜ʖ( ͡° ͜ʖ ͡°)ʖ ͡°)͡°)͡°)͡°)'

face_crowd(10)
'( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡° ͜ʖ( ͡° ͜ʖ ͡°)ʖ ͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)'

face_crowd(500)
'( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡° ͜ʖ( ͡° ͜ʖ ͡°)ʖ ͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)'

Here's an extraordinarily naive recursive reference implementation (posted on my Github). I tried to keep it as plain as possible for clarity; but there's a lot of duplication

I posted it externally because I wanted to wrap it in a spoiler in case people don't want to see a reference, but that complicates copying the code. I figure it's not important to the challenge really, so it isn't a big deal if it goes down I can paste it here if it's deemed important.

    def face_crowd(n: int) -> str:
        def rec(depth: int, left: bool = False) -> str:
            if depth >= n:
                return ""

            elif depth == 0:
                return rec(depth + 1, True) + '( ͡° ͜ʖ ͡°)' + rec(depth + 1, False)

            elif depth == 1:
                return (rec(depth + 1, True) + '( ͡° ͜ʖ') if left else ('ʖ ͡°)' + rec(depth + 1, False))

            else:
                return (rec(depth + 1, True) + '( ͡°') if left else ('͡°)' + rec(depth + 1, False))

        return rec(0)

This is code-golf, so the least number of bytes in each language wins.

*/

package main

func main() {
	assert(facecrowd(0) == ``)
	assert(facecrowd(1) == `( ͡° ͜ʖ ͡°)`)
	assert(facecrowd(2) == `( ͡° ͜ʖ( ͡° ͜ʖ ͡°)ʖ ͡°)`)
	assert(facecrowd(5) == `( ͡°( ͡°( ͡°( ͡° ͜ʖ( ͡° ͜ʖ ͡°)ʖ ͡°)͡°)͡°)͡°)`)
	assert(facecrowd(10) == `( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡° ͜ʖ( ͡° ͜ʖ ͡°)ʖ ͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)`)
	assert(facecrowd(500) == `( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡°( ͡° ͜ʖ( ͡° ͜ʖ ͡°)ʖ ͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)͡°)`)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func facecrowd(n int) string {
	return recurse(0, false, n)
}

func recurse(depth int, left bool, n int) string {
	switch {
	case depth >= n:
		return ""
	case depth == 0:
		return recurse(depth+1, true, n) + `( ͡° ͜ʖ ͡°)` + recurse(depth+1, false, n)
	case depth == 1:
		if left {
			return recurse(depth+1, true, n) + `( ͡° ͜ʖ`
		}
		return `ʖ ͡°)` + recurse(depth+1, false, n)
	default:
		if left {
			return recurse(depth+1, true, n) + `( ͡°`
		}
		return `͡°)` + recurse(depth+1, false, n)
	}
}