/*

Introduction
Everyone should know IPv6 by now. IPv6 has very long, cumbersome addresses. In 1996 some very intelligent people created a scheme to encode them much better in RFC 1924. For reasons I cannot understand, this hasn't been widely adopted. To help adoption, it is your task to implement a converter in the language of your choice. Because storage is very expensive, especially in source code repositories, you obviously have to use as little of it as possible.

Challenge
Write an encoder for the address format specified in RFC1924. The input is a IPv6 address in the boring standard format.

Stolen from Wikipedia this is:

An IPv6 address is represented as eight groups of four hexadecimal digits, each group representing 16 bits (two octets). The groups are separated by colons (:). An example of an IPv6 address is:

2001:0db8:85a3:0000:0000:8a2e:0370:7334
The hexadecimal digits are case-insensitive, but IETF recommendations suggest the use of lower case letters. The full representation of eight 4-digit groups may be simplified by several techniques, eliminating parts of the representation.

Leading zeroes

Leading zeroes in a group may be omitted. Thus, the example address may be written as:

2001:db8:85a3:0:0:8a2e:370:7334
Groups of zeroes

One or more consecutive groups of zero value may be replaced with a single empty group using two consecutive colons (::). Thus, the example address can be further simplified:

2001:db8:85a3::8a2e:370:7334
The localhost (loopback) address, 0:0:0:0:0:0:0:1, and the IPv6 unspecified address, 0:0:0:0:0:0:0:0, are reduced to ::1 and ::, respectively. This two-colon replacement may only be applied once in an address, because multiple occurrences would create an ambiguous representation.

You must handle omitted zeroes in the representation correctly!

The output is a IPv6 address in the superior RFC1924 format.

As in the RFC this is:

The new standard way of writing IPv6 addresses is to treat them as a 128 bit integer, encode that in base 85 notation, then encode that using 85 ASCII characters. The character set to encode the 85 base85 digits, is defined to be, in ascending order:

         '0'..'9', 'A'..'Z', 'a'..'z', '!', '#', '$', '%', '&', '(',
         ')', '*', '+', '-', ';', '<', '=', '>', '?', '@', '^', '_',
         '`', '{', '|', '}', and '~'.
The conversion process is a simple one of division, taking the remainders at each step, and dividing the quotient again, then reading up the page, as is done for any other base conversion.

You can use the suggested conversion algorithm in the RFC or any other you can think of. It just has to result in the correct output!

Example Input and Output
Here is the one from the RFC:

Input:

1080:0:0:0:8:800:200C:417A or 1080::8:800:200C:417A

Output:

4)+k&C#VzJ4br>0wv%Yp

Your program can take input and return the output in any standard way. So it is ok to read from stdin and output to stdout or you can implement your code as a function that takes the input as argument and returns the output.

Winning criteria
As always standard loopholes are disallowed

This is code-golf so shortest correct code in bytes wins!

This is my first challenge, so please do notify me about any problems/ambiguities in the description.

*/

package main

import (
	"bytes"
	"math/big"
	"net"
)

func main() {
	assert(ip2b85("1080:0:0:0:8:800:200C:417A") == "4)+k&C#VzJ4br>0wv%Yp")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ip2b85(s string) string {
	const sym = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&()*+-;<=>?@^_`{|}~"
	var (
		zero       = big.NewInt(0)
		eightyfive = big.NewInt(85)
	)

	x := ip2int(s)
	y := new(big.Int)
	b := []byte{}
	for x.Cmp(zero) != 0 {
		y.Mod(x, eightyfive)
		x.Quo(x, eightyfive)
		i := y.Int64()
		b = append(b, sym[i])
	}

	w := new(bytes.Buffer)
	for i := len(b) - 1; i >= 0; i-- {
		w.WriteByte(b[i])
	}
	return w.String()
}

func ip2int(s string) *big.Int {
	ip := net.ParseIP(s)
	if ip == nil {
		return nil
	}

	ip6 := ip.To16()
	if ip6 == nil {
		return nil
	}

	r := new(big.Int)
	for _, x := range ip6 {
		r.Lsh(r, 8)
		r.Or(r, big.NewInt(int64(x)))
	}
	return r
}
