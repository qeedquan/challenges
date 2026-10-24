/*

Are you a file extension master? Let's find out by checking if Bill's files are images or audio files. Please use regex if available natively for your language.

You will create 2 string methods:

isAudio/is_audio, matching 1 or + uppercase/lowercase letter(s) (combination possible), with the extension .mp3, .flac, .alac, or .aac.

isImage/is_image, matching 1 or + uppercase/lowercase letter(s) (combination possible), with the extension .jpg, .jpeg, .png, .bmp, or .gif.

Note that this is not a generic image/audio files checker. It's meant to be a test for Bill's files only. Bill doesn't like punctuation. He doesn't like numbers, neither. Thus, his filenames are letter-only

Rules

It should return true or false, simply.
File extensions should consist of lowercase letters and numbers only.
File names should consist of letters only (uppercase, lowercase, or both)
Good luck!

*/

package main

import (
	"regexp"
)

func main() {
	assert(isaudio.MatchString("a.mp3") == true)
	assert(isaudio.MatchString(".flac") == false)
	assert(isimage.MatchString("a.mp3") == false)
	assert(isimage.MatchString("a.jpg") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var (
	isaudio = regexp.MustCompile(`^[^\s\d]+\.((mp3)|(flac)|(alac)|(aac))$`)
	isimage = regexp.MustCompile(`^[^\s\d]+\.((jpg)|(jpeg)|(png)|(bmp)|(gif))$`)
)
