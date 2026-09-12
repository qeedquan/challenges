/*

Unicode Transformation Format – 8-bit
As the name suggests UTF-8 was designed to encode data in a stream of bytes.

It works by splitting the bits up in multiples of eight. This is achieved by inserting headers to mark in how many bytes the bits were split. If the bits need to be split in two, the header 110 is added as prefix leaving five bits of the byte for the rest of the data. Followed by a continuation byte.

A continuation byte always start with 10 leaving six bits for data. For a three-way split: the header 1110 is added with two continuation bytes and for four: 11110 with three continuation bytes. The number of ones at the start of the first byte denotes the number of bytes the data was split in.

Task
Your task is to write two functions:

to_utf8_binary: which encodes a string to a bitstring using UTF-8 encoding.
from_utf8_binary: which does the reverse.
Layout of UTF-8 byte sequences:
# BYTES  FIRST CODE POINT  LAST CODE POINT    BYTE 1      BYTE 2      BYTE 3      BYTE 4
  1                   0              127    0xxxxxxx
  2                 128             2047    110xxxxx    10xxxxxx
  3                2048            65535    1110xxxx    10xxxxxx    10xxxxxx
  4               65536          1114111    11110xxx    10xxxxxx    10xxxxxx    10xxxxxx
Examples
ENCODE
 A  -> 1000001         -> 01000001
 八 -> 101000101101011 -> 1110-0101 10-000101 10-101011

DECODE
 110-00010 10-100111                     -> 10100111          -> §
 11110-000 10-010000 10-001010 10-001100 -> 10000001010001100 -> 𐊌
Spaces and hyphens just for clarity
https://en.wikipedia.org/wiki/UTF-8#Encoding

*/

package main

import (
	"bytes"
	"fmt"
	"unicode/utf8"
)

func main() {
	chartoutf8 := []struct {
		char rune
		enc  string
	}{
		{'A', "01000001"},
		{'§', "1100001010100111"},
		{'八', "111001011000010110101011"},
		{'𐊌', "11110000100100001000101010001100"},
	}

	utf8tochar := []struct {
		enc  string
		char rune
	}{
		{"01000010", 'B'},
		{"1100001010100011", '£'},
		{"111000101001110010001000", '✈'},
		{"11110000100100101000000010110001", '𒀱'},
	}

	for _, p := range chartoutf8 {
		var b [utf8.UTFMax]byte
		n := utf8.EncodeRune(b[:], p.char)
		assert(bytestr(b[:n]) == p.enc)
	}
	for _, p := range utf8tochar {
		b := strbyte(p.enc)
		r, _ := utf8.DecodeRune(b[:])
		assert(p.char == r)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bytestr(b []byte) string {
	w := new(bytes.Buffer)
	for i := range b {
		fmt.Fprintf(w, "%08b", b[i])
	}
	return w.String()
}

func strbyte(s string) []byte {
	w := new(bytes.Buffer)
	for i := 0; i < len(s); {
		v := byte(0)
		for j := 0; i < len(s) && j < 8; i, j = i+1, j+1 {
			if v <<= 1; s[i] == '1' {
				v |= 1
			}
		}
		w.WriteByte(v)
	}
	return w.Bytes()
}
