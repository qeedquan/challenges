/*

To mark the anniversary of World IPv6 day, the Internet Society has published a campaign to Turn Off IPv4 on 6 June 2014 for One Day.

IPv6 addresses may be represented in their long form as eight colon-separated 16-bit hex values. Depending on the address, they may also be shortened as described in item 2 of section 2.2 Text Representation of Addresses of RFC 3513:

In order to make writing addresses containing zero bits easier a special syntax is available to compress the zeros. The use of "::" indicates one or more groups of 16 bits of zeros. The "::" can only appear once in an address. The "::" can also be used to compress leading or trailing zeros in an address.

Entries to this challenge will be programs that accept exactly one IPv6 address formatted in either the long or shortened format, and will display the same address in both the long and short formats, in that order.

The input may come from command-line arguments, STDIN, or any other input source that suits your choice of language.

Libraries or utilities specifically for parsing IPv6 addresses are banned (e.g. inet_{ntop,pton}()).

If the input address is invalid, the output will be empty (or some suitable error message indicating the address is invalid is given)

In cases where :: shortening occurs, only one shortening operation may happen for a given address. If there are more than one potential shortening operations for a given address, the operation that gives the overall shortest address must be used. If there is a tie in this regard, the first operation will be used. This is illustrated in the examples below.

Standard loopholes to be avoided

Examples:

Input                         Output

1080:0:0:0:8:800:200C:417A    1080:0:0:0:8:800:200C:417A
                              1080::8:800:200C:417A

FF01::101                     FF01:0:0:0:0:0:0:101
                              FF01::101

0:0:0:0:0:0:0:1               0:0:0:0:0:0:0:1
                              ::1

::                            0:0:0:0:0:0:0:0
                              ::

1:0:0:2:0:0:0:3               1:0:0:2:0:0:0:3
                              1:0:0:2::3

1:0:0:8:8:0:0:3               1:0:0:8:8:0:0:3
                              1::8:8:0:0:3

1:2:3:4:5:6:7:8               1:2:3:4:5:6:7:8
                              1:2:3:4:5:6:7:8

ABCD:1234                     <Invalid address format - no output>

ABCDE::1234                   <Invalid address format - no output>

1:2:3:4:5:6:7:8:9             <Invalid address format - no output>

:::1                          <Invalid address format - no output>

codegolf puzzle               <Invalid address format - no output>

This is codegolf, so the shortest answer in bytes on June 6th 2014 will be accepted as the winner.

*/

package main

import (
	"encoding/binary"
	"fmt"
	"net"
	"strings"
)

func main() {
	test("1080:0:0:0:8:800:200C:417A", "1080:0:0:0:8:800:200C:417A", "1080::8:800:200C:417A")
	test("FF01::101", "FF01:0:0:0:0:0:0:101", "FF01::101")
	test("0:0:0:0:0:0:0:1", "0:0:0:0:0:0:0:1", "::1")
	test("::", "0:0:0:0:0:0:0:0", "::")
	test("1:0:0:2:0:0:0:3", "1:0:0:2:0:0:0:3", "1:0:0:2::3")
	test("1:0:0:8:8:0:0:3", "1:0:0:8:8:0:0:3", "1::8:8:0:0:3")
	test("1:2:3:4:5:6:7:8", "1:2:3:4:5:6:7:8", "1:2:3:4:5:6:7:8")
	test("ABCD:1234", "", "")
	test("ABCDE::1234", "", "")
	test("1:2:3:4:5:6:7:8:9", "", "")
	test("::::1", "", "")
	test("codegolf puzzle", "", "")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(addr, expected_long, expected_short string) {
	long, short := ipv6(addr)
	assert(long == expected_long)
	assert(short == expected_short)
}

func ipv6(addr string) (long, short string) {
	ip := net.ParseIP(addr)
	if ip == nil {
		return
	}
	ip = ip.To16()

	short = ip.String()
	short = strings.ToUpper(short)
	for i := 0; i+1 < len(ip); i += 2 {
		value := binary.BigEndian.Uint16(ip[i:])
		long += fmt.Sprintf("%X:", value)
	}
	long = long[:len(long)-1]
	return
}
