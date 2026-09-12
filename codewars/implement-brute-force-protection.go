/*

You are tasked with protecting an important application against hackers.

The first defense you have to implement is brute force protection.

Some inexperienced (or lazy) hackers may try to break in by simply guessing the admin password over and over again.

Design a function which will block a login attempt if it comes from an IP address which failed to login 20 times in a row.

The function will receive a single parameter - an object containing two properties:

loginAttempt.sourceIP // the IP of the person trying to log in
loginAttempt.successful // whether the log-in attempt succeeded
The bruteForceDetected function should return true when the IP should be blocked and false otherwise.

Note: A successful login should reset the number of counts.

*/

package main

import (
	"fmt"
	"net/netip"
)

type Firewall map[netip.Addr]int

func main() {
	addr := netip.AddrFrom4([4]byte{127, 0, 0, 1})
	firewall := Firewall{}
	for i := range 21 {
		fmt.Println(i, firewall.Blocked(addr, false))
	}
}

func (f Firewall) Blocked(ip netip.Addr, success bool) bool {
	switch {
	case f[ip] >= 20:
		return true
	case success:
		f[ip] = 0
	default:
		f[ip] += 1
	}
	return false
}
