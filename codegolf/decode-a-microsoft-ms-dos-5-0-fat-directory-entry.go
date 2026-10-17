/*

The Microsoft FAT file system has a directory table to represent which "files" are in which "folders" on the disk. For the time, these entries crammed a lot of information into a small amount of bits. There are a bunch of technical specifications over on Wiki for the curious, but the challenge here is going to focus on a "simple" decoding of an entry.

Each entry consists of a 32-byte binary word, broken up into several sections. For consistency in this challenge, we'll be using the MS-DOS 5.0 version, the bytes are ordered as big endian, and we're calling byte 0x00 as the left-most, and byte 0x1F as the right-most.

Below is a brief schematic of the relevant sections, and what should be the output for each section (in bold).

The first 11 bytes are the file name in ASCII format (this is where the famous 8.3 filename comes from -- 8 bytes for the file name, 3 bytes for the extension). These are straight ASCII encoding, and should be output as ASCII with a period (.) between.
Note: both the 8 and the 3 parts are padded with spaces to make a full-length entry. The output should ignore spaces (i.e., don't output them).
The file extension may be empty (i.e., all spaces), in which case the output should not output the dot.
Since ASCII only uses the lower 7 bits, the bytes will all have a leading 0.
The next byte (0x0b) is a bitmask of the following:
0x01 Read Only - output RO
0x02 Hidden - output H
0x04 System - output S
0x08 Volume Label - output VL. File size (below) should be output as 0, regardless of its actual entry.
0x10 Subdirectory - output SD. File size (below) should be output as 0, regardless of its actual entry.
0x20 Archive - output A
0x40 Device - ignored for this challenge.
0x80 Reserved - ignored for this challenge.
Since this is a bitmask, multiple flags are possible - all applicable outputs should be concatenated together in any order. For example, 0xff could be ROHSVLSDA (or any other combination).
The next two bytes (0x0c and 0x0d) are not used under MS-DOS 5.0.
The next two bytes (0x0e and 0x0f) are the creation time as follows:
Bits 15 to 11 are the hours in 24-hour format - output 00 to 23
Bits 10 to 5 are the minutes - output 00 to 59
Bits 4 to 0 are the seconds/2 - output 00 to 58 (note that seconds are only in two-second resolution)
For clarification: hhhhhmmmmmmsssss when written big-endian.
The next two bytes (0x10 and 0x11) are the creation date as follows:
Bits 15 to 9 are the year - output 1980 for 0 up to 2107 for 127
Bits 8 to 5 are the months - output 1 to 12 (with or without leading zero)
Bits 4 to 0 are the day - output 0 to 31 (with or without leading zero)
For clarification: yyyyyyymmmmddddd when written big-endian.
The next two bytes (0x12 and 0x13) are the last access date. While used in MS-DOS 5.0, we're ignoring this portion for this challenge.
The next two bytes (0x14 and 0x15) are not used by MS-DOS 5.0.
The next two bytes (0x16 and 0x17) are the last modified time, following the same format as the creation time, above.
The next two bytes (0x18 and 0x19) are the last modified date, following the same format as the creation date, above.
The next two bytes (0x1a and 0x1b) are the cluster location of the file on disk. We're ignoring this portion for this challenge.
The final four bytes (0x1c, 0x1d, 0x1e, and 0x1f) are the file size - output as an unsigned integer, unless the VL or SD flags are set (above), in which case output 0.
Visual representation

0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
\______________________________FILENAME________________________________________________/\_ATTR_/\___NOTUSED____/\_CREATIONTIME_/\_CREATIONDATE_/\__LASTACCESS__/\___NOTUSED____/\_MODIFIEDTIME_/\_MODIFIEDDATE_/\___NOTUSED____/\___________FILESIZE___________/
Input
A single 32-byte word (i.e., 256 bits), in whatever format is convenient.
This could be as a string of 1 and 0, as several unsigned ints, an array of Boolean values, etc.
Please specify in your answer what format you're using for input.
You cannot take multiple input (i.e., an array pre-broken into the relevant byte sizes) unless that is the only way for your language to take input. Parsing the input is part of the challenge.
You can assume input to be valid (for example, you don't need to perform date checking to verify that the date is valid).
Bytes that are unused can be all 0, all 1, etc., just so long as they are present. In the below examples, I used all 0 for the unused bytes.
Output
Either printed to screen or returned, the following:

The filename as an ASCII string
The file attributes as an ASCII string
The creation time and creation date, with appropriate separators (colons, slashes, something to distinguish the components)
The modified time and modified date, again with appropriate separators
The file size
The output can be a space-separated or newline-separated single string, separate elements in an array, etc. Please specify in your answer how your output is formatted.

Rules
Standard I/O formats are acceptable.
Either a full program or a function are acceptable.
Standard loopholes are forbidden.
This is code-golf, so all usual golfing rules apply, and the shortest code wins.
Built-ins that perform exactly this function are forbidden.
Examples
0111000001110010011011110110011101110010011000010110110101101101011010010110111001100111000001100000000000000000101000100100010001001000110101000000000000000000000000000000000010100010010001000100100011010100000000000000000000000000000000001101000000000000

programm.ing HS 20:18:08 2016/06/20 20:18:08 2016/06/20 53248

0010000000100000001000000010000001110000011100000110001101100111001000000010000000100000000101000000000000000000010111010110110000111101100111110000000000000000000000000000000010100010010001000100100011010100000000000000000011110000000100111111001011100001

ppcg SDS 11:43:24 2010/12/31 20:18:08 2016/06/20 0

*/

package main

import (
	"bytes"
	"encoding/binary"
	"fmt"
)

func main() {
	test("0111000001110010011011110110011101110010011000010110110101101101011010010110111001100111000001100000000000000000101000100100010001001000110101000000000000000000000000000000000010100010010001000100100011010100000000000000000000000000000000001101000000000000")
	test("0010000000100000001000000010000001110000011100000110001101100111001000000010000000100000000101000000000000000000010111010110110000111101100111110000000000000000000000000000000010100010010001000100100011010100000000000000000011110000000100111111001011100001")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(data string) {
	var entry Entry
	r := bytes.NewReader(bin2bytes(data))
	err := (binary.Read(r, binary.BigEndian, &entry))
	assert(err == nil)
	fmt.Println(entry)
}

func bin2bytes(data string) []byte {
	buf := make([]byte, len(data)/8)
	for i := range buf {
		val := byte(0)
		for j := 0; j < 8 && 8*i+j < len(data); j++ {
			if data[8*i+j] != '0' {
				val |= 1 << (7 - j)
			}
		}
		buf[i] = val
	}
	return buf
}

type Entry struct {
	Name           [11]byte
	Mode           byte
	_              [2]byte
	CreateTime     uint16
	CreateDate     uint16
	LastAccessDate uint16
	_              [2]byte
	ModTime        uint16
	ModDate        uint16
	Cluster        uint16
	Size           uint32
}

func (e Entry) String() string {
	name := e.getname()
	mode := e.getmode()
	ctime := e.gettime(e.CreateTime, e.CreateDate)
	mtime := e.gettime(e.ModTime, e.ModDate)
	size := e.getsize()
	return fmt.Sprintf("%s %s %s %s %d", name, mode, ctime, mtime, size)
}

func (e *Entry) getname() string {
	var name, ext string
	for i := 0; i < 8; i++ {
		if c := e.Name[i]; c != ' ' {
			name += string(c)
		}
	}
	for i := 8; i < 11; i++ {
		if c := e.Name[i]; c != ' ' {
			ext += string(c)
		}
	}
	if ext != "" {
		name = name + "." + ext
	}

	return name
}

func (e *Entry) getmode() string {
	tab := []string{"RO", "H", "S", "VL", "SD", "A"}
	mode := ""
	for i, v := range tab {
		if e.Mode&(1<<i) != 0 {
			mode += v
		}
	}
	return mode
}

func (e *Entry) getsize() uint32 {
	if e.Mode&0x18 != 0 {
		return 0
	}
	return e.Size
}

func (*Entry) gettime(time, date uint16) string {
	hour := (time >> 11) & 0x1f
	minute := (time >> 5) & 0x3f
	second := (time & 0x1f) << 1

	year := 1980 + (date>>9)&0x7f
	month := (date >> 5) & 0x1f
	day := date & 0x1f

	return fmt.Sprintf("%02d:%02d:%02d %04d/%02d/%02d", hour, minute, second, year, month, day)
}
