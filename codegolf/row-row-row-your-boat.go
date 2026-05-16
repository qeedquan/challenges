/*

Everyone is likely familiar with the following song, which is a musical round:

https://i.stack.imgur.com/q5hML.png

Background
Fewer people might recall trying to sing the 4-person version of this with a few friends and failing. Offsetting the lyrics of a song with different harmonious pitches is known as singing a "round" and that's what we're here to simulate today using static output. Here's an example of someone actually performing the piece (link to audio/video, will have sound).

The Challenge
This challenge is to output the text as follows exactly as it follows:

Row, row, row your boat,           |-----------------------------------|-----------------------------------|-----------------------------------
Gently down the stream.            |Row, row, row your boat,           |-----------------------------------|-----------------------------------
Merrily, merrily, merrily, merrily,|Gently down the stream.            |Row, row, row your boat,           |-----------------------------------
Life is but a dream.               |Merrily, merrily, merrily, merrily,|Gently down the stream.            |Row, row, row your boat,
-----------------------------------|Life is but a dream.               |Merrily, merrily, merrily, merrily,|Gently down the stream.
-----------------------------------|-----------------------------------|Life is but a dream.               |Merrily, merrily, merrily, merrily,
-----------------------------------|-----------------------------------|-----------------------------------|Life is but a dream.

Rules
Trailing whitespace is acceptable, but not required, this includes newlines.
Hyphens and bars are part of the required output, yes.
Commas, periods, capitalization and all syntactical elements related to grammar are required.
This is code-golf, the lowest byte-count code without using standard loopholes is the winner.

*/

package main

import "fmt"

func main() {
	fmt.Println(MUSICAL)
}

const MUSICAL = `
Row, row, row your boat,           |-----------------------------------|-----------------------------------|-----------------------------------
Gently down the stream.            |Row, row, row your boat,           |-----------------------------------|-----------------------------------
Merrily, merrily, merrily, merrily,|Gently down the stream.            |Row, row, row your boat,           |-----------------------------------
Life is but a dream.               |Merrily, merrily, merrily, merrily,|Gently down the stream.            |Row, row, row your boat,
-----------------------------------|Life is but a dream.               |Merrily, merrily, merrily, merrily,|Gently down the stream.
-----------------------------------|-----------------------------------|Life is but a dream.               |Merrily, merrily, merrily, merrily,
-----------------------------------|-----------------------------------|-----------------------------------|Life is but a dream.               
`
