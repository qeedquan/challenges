#!/usr/bin/env python3

"""

Given an IPv4 address in dotted-quad notation, and an IPv4 subnet in CIDR notation, determine if the address is in the subnet. Output a distinct and consistent value if it is in the subnet, and a separate distinct and consistent value if it is not in the subnet. The output values do not necessarily need to be truthy/falsey in your language.

CIDR subnet notation brief primer
IPv4 network addresses are 32 bits in length, split into four groups of 8 bits for ease of reading. CIDR subnet notation is a mask of the specified number of bits, starting leftmost. For example, for a /24 subnet, this means the right-most 8 bits of the address are available in that subnet. Thus two addresses that are separated by at most 255, and have the same subnet mask, are in the same subnet. Note that valid CIDR have all the host-bits (the right hand side) unset (zeros).

xxxxxxxx xxxxxxxx xxxxxxxx 00000000
^---    subnet mask   ---^ ^-hosts-^
For another example, a /32 subnet specifies that all of the bits are the subnet mask, essentially meaning that only one host is allowed per /32.

xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxxx
^---        subnet mask        ---^
Examples:
Using True for "in the subnet" and False for "not in the subnet" as output:

127.0.0.1
127.0.0.0/24
True

127.0.0.55
127.0.0.0/23
True

127.0.1.55
127.0.0.0/23
True

10.4.1.33
10.4.0.0/16
True

255.255.255.255
0.0.0.0/0
True

127.1.2.3
127.0.0.0/24
False

127.1.2.3
127.1.2.1/32
False

10.10.83.255
10.10.84.0/22
False

Rules and Clarifications
Since input parsing isn't the interesting point of this challenge, you're guaranteed to get valid IPv4 addresses and subnet masks.
Input and output can be given by any convenient method.
You can print the result to STDOUT or return it as a function result. Please state in your submission what values the output can take.
Either a full program or a function are acceptable.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

"""

from ipaddress import *

def subnet(ip, network):
    try:
        return ip_address(ip) in ip_network(network)
    except:
        pass
    return False

def main():
    assert(subnet("127.0.0.1", "127.0.0.0/24") == True)
    assert(subnet("127.0.0.55", "127.0.0.0/23") == True)
    assert(subnet("127.0.1.55", "127.0.0.0/23") == True)
    assert(subnet("10.4.1.33", "10.4.0.0/16") == True)
    assert(subnet("255.255.255.255", "0.0.0.0/0") == True)

    assert(subnet("127.1.2.3", "127.0.0.0/24") == False)
    assert(subnet("127.1.2.3", "127.1.2.1/32") == False)
    assert(subnet("10.10.83.255", "10.10.84.0/22") == False)

main()
