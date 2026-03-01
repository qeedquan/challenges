/*

I want to avoid responding to illegal or spoofed addresses. One type that's easy to detect is an address that should not exist on a packet received by my router: a special-use address.

Challenge
Given an IPv4 32-bit address, identify whether it is valid general-use address.

Challenge rules
Special-use addresses, as defined by the Internet Engineering Task Force, are considered invalid.
Special-use addresses are listed at https://en.wikipedia.org/wiki/IPv4#Special-use_addresses. A copy of the list (omitting explanatory columns) is below.
Input will be a character sequence in the dot-decimal notation, consisting of four positive decimal numbers (called "octets") each in the range 0–255 separated by periods (e.g., 169.254.0.31). Each octet represents an 8-bit segment of the address.
Output must indicate true or false, using any two indicators of your choice for true and false.

General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer with default I/O rules, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code (i.e. TIO).
Also, adding an explanation for your answer is highly recommended.

Test cases:
192.0.0.254 false
192.0.1.254 true
0.255.0.0 false
128.2.3.82 true
253.8.22.37 false
203.0.114.201 true

Special-use addresses
Address Block	Address Range
0.0.0.0/8	0.0.0.0–0.255.255.255
10.0.0.0/8	10.0.0.0–10.255.255.255
100.64.0.0/10	100.64.0.0–100.127.255.255
127.0.0.0/8	127.0.0.0–127.255.255.255
169.254.0.0/16	169.254.0.0–169.254.255.255
172.16.0.0/12	172.16.0.0–172.31.255.255
192.0.0.0/24	192.0.0.0–192.0.0.255
192.0.2.0/24	192.0.2.0–192.0.2.255
192.88.99.0/24	192.88.99.0–192.88.99.255
192.168.0.0/16	192.168.0.0–192.168.255.255
198.18.0.0/15	198.18.0.0–198.19.255.255
198.51.100.0/24	198.51.100.0–198.51.100.255
203.0.113.0/24	203.0.113.0–203.0.113.255
224.0.0.0/4	224.0.0.0–239.255.255.255
240.0.0.0/4	240.0.0.0–255.255.255.255

Note on address blocks. This is a shortcut method of listing an address range, called CIDR notation. The notation is four octets followed by a slash and a decimal number. The decimal number is the count of leading 1 bits in the network mask, and indicates how many leading bits in the underlying 32-bit address range are specified as fixed. For example, a mask of 24 indicates that only the last 8 bits of the address range vary. Thus writing 192.0.2.0/24 indicates that only the last octet varies. The range for 192.0.2.0/24 is 192.0.2.0–192.0.2.255.

*/

package main

import "net"

func main() {
	assert(checkip("192.0.0.254") == false)
	assert(checkip("192.0.1.254") == true)
	assert(checkip("0.255.0.0") == false)
	assert(checkip("128.2.3.82") == true)
	assert(checkip("253.8.22.37") == false)
	assert(checkip("203.0.114.201") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func checkip(addr string) bool {
	ip := net.ParseIP(addr)
	if ip == nil {
		return false
	}

	for _, ipn := range IPNS {
		if ipn.Contains(ip) {
			return false
		}
	}
	return true
}

func mkipn(addr string) *net.IPNet {
	_, ipn, err := net.ParseCIDR(addr)
	if err != nil {
		panic(err)
	}
	return ipn
}

var IPNS = []*net.IPNet{
	mkipn("0.0.0.0/8"),
	mkipn("10.0.0.0/8"),
	mkipn("100.64.0.0/10"),
	mkipn("127.0.0.0/8"),
	mkipn("169.254.0.0/16"),
	mkipn("172.16.0.0/12"),
	mkipn("192.0.0.0/24"),
	mkipn("192.0.2.0/24"),
	mkipn("192.88.99.0/24"),
	mkipn("192.168.0.0/16"),
	mkipn("198.18.0.0/15"),
	mkipn("198.51.100.0/24"),
	mkipn("203.0.113.0/24"),
	mkipn("224.0.0.0/4"),
	mkipn("240.0.0.0/4"),
}
