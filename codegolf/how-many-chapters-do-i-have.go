/*

The Bible is one of the most influential books ever written, and commonly cited as the best selling book of all time. It was written by approximately 40 different authors over hundreds of years before being compiled into it's current form. But what's interesting about The Bible is the way it's divided up. It is split up into 2 different testaments, which are split up into 66 smaller books, which are each split up into smaller chapters, which are each split up into individual verses.

I thought it would be a fun challenge to try to encode the number of chapters in each book in the shortest code possible. So for today's challenge, you must write a program or function that takes one of the books as input, and outputs the number of chapters in that book according to The King James Version.

You may take IO in any reasonable format, for example reading/writing STDIN/STDOUT or a file, function arguments/return values, prompting the user, etc. are all allowed. The input will always be one of the 66 books of The Bible, and only lowercase. This means that if you are given any other input, undefined behavior is allowed. Since there are only 66 possible inputs and outputs, they are all provided here, according to Wikipedia's page on Bible chapters in The King James Version:

genesis         50
exodus          40
leviticus       27
numbers         36
deuteronomy     34
joshua          24
judges          21
ruth            4
1 samuel        31
2 samuel        24
1 kings         22
2 kings         25
1 chronicles    29
2 chronicles    36
ezra            10
nehemiah        13
esther          10
job             42
psalms          150
proverbs        31
ecclesiastes    12
song of solomon 8
isaiah          66
jeremiah        52
lamentations    5
ezekiel         48
daniel          12
hosea           14
joel            3
amos            9
obadiah         1
jonah           4
micah           7
nahum           3
habakkuk        3
zephaniah       3
haggai          2
zechariah       14
malachi         4
matthew         28
mark            16
luke            24
john            21
acts            28
romans          16
1 corinthians   16
2 corinthians   13
galatians       6
ephesians       6
philippians     4
colossians      4
1 thessalonians 5
2 thessalonians 3
1 timothy       6
2 timothy       4
titus           3
philemon        1
hebrews         13
james           5
1 peter         5
2 peter         3
1 john          5
2 john          1
3 john          1
jude            1
revelation      22
Since this challenge is about finding the optimal way to encode every book name and chapter count, using any builtins that give information about The Bible are not permitted. However, since it would be interesting to see which languages have such builtins, feel free to share a second non-competing version along with your answer. Fetching information from external sources is also not permitted (none of the standard loopholes are allowed, but I thought it would be useful to explicitly mention that one).

As usual, this is a code-golf challenge, so try to make the shortest possible program (measured in bytes) as you can. Have fun golfing!

*/

package main

import "fmt"

func main() {
	for book, chapter := range BOOKS {
		fmt.Printf("%-18q: %d\n", book, chapter)
	}
}

var BOOKS = map[string]int{
	"genesis":         50,
	"exodus":          40,
	"leviticus":       27,
	"numbers":         36,
	"deuteronomy":     34,
	"joshua":          24,
	"judges":          21,
	"ruth":            4,
	"1 samuel":        31,
	"2 samuel":        24,
	"1 kings":         22,
	"2 kings":         25,
	"1 chronicles":    29,
	"2 chronicles":    36,
	"ezra":            10,
	"nehemiah":        13,
	"esther":          10,
	"job":             42,
	"psalms":          150,
	"proverbs":        31,
	"ecclesiastes":    12,
	"song of solomon": 8,
	"isaiah":          66,
	"jeremiah":        52,
	"lamentations":    5,
	"ezekiel":         48,
	"daniel":          12,
	"hosea":           14,
	"joel":            3,
	"amos":            9,
	"obadiah":         1,
	"jonah":           4,
	"micah":           7,
	"nahum":           3,
	"habakkuk":        3,
	"zephaniah":       3,
	"haggai":          2,
	"zechariah":       14,
	"malachi":         4,
	"matthew":         28,
	"mark":            16,
	"luke":            24,
	"john":            21,
	"acts":            28,
	"romans":          16,
	"1 corinthians":   16,
	"2 corinthians":   13,
	"galatians":       6,
	"ephesians":       6,
	"philippians":     4,
	"colossians":      4,
	"1 thessalonians": 5,
	"2 thessalonians": 3,
	"1 timothy":       6,
	"2 timothy":       4,
	"titus":           3,
	"philemon":        1,
	"hebrews":         13,
	"james":           5,
	"1 peter":         5,
	"2 peter":         3,
	"1 john":          5,
	"2 john":          1,
	"3 john":          1,
	"jude":            1,
	"revelation":      22,
}
