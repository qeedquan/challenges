#!/usr/bin/env python3

"""

Implement a function that receives two IPv4 addresses, and returns the number of addresses between them (including the first one, excluding the last one).

All inputs will be valid IPv4 addresses in the form of strings. The last address will always be greater than the first one.

Examples
ipsBetween("10.0.0.0", "10.0.0.50")  ===   50
ipsBetween("10.0.0.0", "10.0.1.0")   ===  256
ipsBetween("20.0.0.10", "20.0.1.0")  ===  246

"""

def parseip(ip):
    addr = ip.split(".")
    return int(addr[0])<<24 | int(addr[1])<<16 | int(addr[2])<<8 | int(addr[3])

def ips(ip0, ip1):
    addr0 = parseip(ip0)
    addr1 = parseip(ip1)
    return abs(addr1 - addr0)

def main():
    assert(ips("10.0.0.0", "10.0.0.50") == 50)
    assert(ips("10.0.0.0", "10.0.1.0") == 256)
    assert(ips("20.0.0.10", "20.0.1.0") == 246)

main()
