/*

This riddle was inspired by that thread. Consider that you are super-hacker and try to break MD5 hashing algorithm by looking for a hash collisions for a given hash string which your friend gave to you. But this is a non-trivial task and you have a migraine disorder so you try to break the problem into smaller parts. First thing which you try is to look for a hamming distance patterns in a repeated execution of MD5() feeding it's last output to an input. For example, if your friend gave to you a hash bb2afeb932cc5aafff4a3e7e31d6d3fb, then you will notice a such pattern :

e3b86f8d25e5a71a88eabef0d7ed9840=md5(bb2afeb932cc5aafff4a3e7e31d6d3fb), hamming 95
45fcdb59517b39f18d1622a84be0a301=md5(e3b86f8d25e5a71a88eabef0d7ed9840), hamming 91
0b3f2eac737b916f3b78f240e7fc97ec=md5(45fcdb59517b39f18d1622a84be0a301), hamming 77
fe56b1802722cc30b936186aacce1e01=md5(0b3f2eac737b916f3b78f240e7fc97ec), hamming 95
So after 4 iterations you arrived at hamming distance 95 between an output and a first input, which is the same 95 number which you have started from. So nearest hamming cycle period of MD5(bb2afeb932cc5aafff4a3e7e31d6d3fb) is 4. You have found a hamming collision !

Your task is to write a program which takes an arbitrary MD5 hash from the standard input, and outputs it's nearest hamming cycle period on standard output. For example:

Input:  45fcdb59517b39f18d1622a84be0a301, Output: 3
Input:  1017efa1722ba21873d79c3a215da44a, Output: 7
Input:  edc990163ff765287a4dd93ee48a1107, Output: 90
Input:  c2ca818722219e3cc5ec6197ef967f5d, Output: 293
Shortest code wins.

Notes:

1. If your language doesn't have an md5() built-in, feel free to implement that yourself and then write in the solution total byte count and byte count without md5() sub-program implementation, the later will be considered as an answer.

2. Hamming distance is defined as number of differing bits between two strings. If strings converted to binary (by character ASCII code) has different lengths - smaller one is padded from the left with 0. Example:

Word1: nice Binary1: 01101110011010010110001101100101
Word2: car  Binary2: 00000000011000110110000101110010
Hamming distance (differing bits): 12

3. In this task you should calculate hamming distance between a FIRST input in a cycle and current output. So according to a given hamming cycle example above you should calculate
hamming(bb2afeb932cc5aafff4a3e7e31d6d3fb,e3b86f8d25e5a71a88eabef0d7ed9840)
hamming(bb2afeb932cc5aafff4a3e7e31d6d3fb,45fcdb59517b39f18d1622a84be0a301)
hamming(bb2afeb932cc5aafff4a3e7e31d6d3fb,0b3f2eac737b916f3b78f240e7fc97ec)
hamming(bb2afeb932cc5aafff4a3e7e31d6d3fb,fe56b1802722cc30b936186aacce1e01)

*/

package main

import (
	"bytes"
	"crypto/md5"
	"fmt"
	"strings"
)

func main() {
	assert(cycle("bb2afeb932cc5aafff4a3e7e31d6d3fb") == 4)
	assert(cycle("45fcdb59517b39f18d1622a84be0a301") == 3)
	assert(cycle("1017efa1722ba21873d79c3a215da44a") == 7)
	assert(cycle("edc990163ff765287a4dd93ee48a1107") == 90)
	assert(cycle("c2ca818722219e3cc5ec6197ef967f5d") == 293)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cycle(s string) int {
	r := 1
	t := strmd5(s)
	d := hamming(s, t)
	for {
		r, t = r+1, strmd5(t)
		if d == hamming(s, t) {
			break
		}
	}
	return r
}

func hamming(s, t string) int {
	a := str2bin(s)
	b := str2bin(t)
	n := max(len(a), len(b))

	a = strpad(a, n)
	b = strpad(b, n)

	r := 0
	for i := 0; i < n; i++ {
		if a[i] != b[i] {
			r++
		}
	}

	return r
}

func str2bin(s string) string {
	w := new(bytes.Buffer)
	for i := range s {
		fmt.Fprintf(w, "%08b", s[i])
	}
	return w.String()
}

func strpad(s string, n int) string {
	m := len(s)
	if m < n {
		s = strings.Repeat("0", n-m) + s
	}
	return s
}

func strmd5(s string) string {
	return fmt.Sprintf("%x", md5.Sum([]byte(s)))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
