/*

The presents have been opened. The mince-pies have been eaten. The Star Wars have been watched. The Christmas Season is beginning to wind down. By now you may well have pulled a few Christmas Crackers. If you're lucky, instead of the usual useless plastic toys, you may have won a Mystery Calculator with which you can amaze your friends and relatives.

https://i.sstatic.net/5NAPr.jpg

This trick consists of 6 cards each with a 4x8 grid of numbers printed on it. Each card contains a different subset of the integers [1,63]. The magician will ask you to pick a number from one card and keep that number secret. The magician will then ask which cards have that number. With that knowledge, the magician will magically be able to determine and disclose the original number guessed.

Output the full set of 6 Mystery Calculator cards exactly as follows:

 1  3  5  7  9 11 13 15
17 19 21 23 25 27 29 31
33 35 37 39 41 43 45 47
49 51 53 55 57 59 61 63
 - - - - - - - - - - -
 2  3  6  7 10 11 14 15
18 19 22 23 26 27 30 31
34 35 38 39 42 43 46 47
50 51 54 55 58 59 62 63
 - - - - - - - - - - -
 4  5  6  7 12 13 14 15
20 21 22 23 28 29 30 31
36 37 38 39 44 45 46 47
52 53 54 55 60 61 62 63
 - - - - - - - - - - -
 8  9 10 11 12 13 14 15
24 25 26 27 28 29 30 31
40 41 42 43 44 45 46 47
56 57 58 59 60 61 62 63
 - - - - - - - - - - -
16 17 18 19 20 21 22 23
24 25 26 27 28 29 30 31
48 49 50 51 52 53 54 55
56 57 58 59 60 61 62 63
 - - - - - - - - - - -
32 33 34 35 36 37 38 39
40 41 42 43 44 45 46 47
48 49 50 51 52 53 54 55
56 57 58 59 60 61 62 63
Output may or may not contain one final trailing newline. There must be no trailing whitespace. Each card is separated by 11 - perforations.

md5sum with final newline: 7aa2d9339b810ec62a2b90c5e11d6f4a
md5sum without final newline: e9abe4e32dca3e8fbfdaa4886fc5efd2
For those of you of more of a windows orientation, I will also allow CRLF style line endings. In that case, the md5s are:

md5sum with final newline: e4f16ff9752eee2cedb5f97c7b5aec6d
md5sum without final newline: 78c560eed3b83513e3080117ab5dc5fa

*/

package main

import "fmt"

func main() {
	fmt.Println(OUTPUT)
}

const OUTPUT = ` 1  3  5  7  9 11 13 15
17 19 21 23 25 27 29 31
33 35 37 39 41 43 45 47
49 51 53 55 57 59 61 63
 - - - - - - - - - - -
 2  3  6  7 10 11 14 15
18 19 22 23 26 27 30 31
34 35 38 39 42 43 46 47
50 51 54 55 58 59 62 63
 - - - - - - - - - - -
 4  5  6  7 12 13 14 15
20 21 22 23 28 29 30 31
36 37 38 39 44 45 46 47
52 53 54 55 60 61 62 63
 - - - - - - - - - - -
 8  9 10 11 12 13 14 15
24 25 26 27 28 29 30 31
40 41 42 43 44 45 46 47
56 57 58 59 60 61 62 63
 - - - - - - - - - - -
16 17 18 19 20 21 22 23
24 25 26 27 28 29 30 31
48 49 50 51 52 53 54 55
56 57 58 59 60 61 62 63
 - - - - - - - - - - -
32 33 34 35 36 37 38 39
40 41 42 43 44 45 46 47
48 49 50 51 52 53 54 55
56 57 58 59 60 61 62 63`
