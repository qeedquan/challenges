/*

Implement String#ipv4_address?, which should return true if given object is an IPv4 address - four numbers (0-255) separated by dots.

It should only accept addresses in canonical representation, so no leading 0s, spaces etc.

*/

var assert = require('assert');

function ipv4(string) {
	return /^(([1-9]?\d|1\d\d|2[0-4]\d|25[0-5])(\.(?!$)|$)){4}$/.test(string);
}

assert(ipv4("") == false);
assert(ipv4("127.0.0.1") == true);
assert(ipv4("0.0.0.0") == true);
assert(ipv4("255.255.255.255") == true);
assert(ipv4("10.20.30.40") == true);
assert(ipv4("10.256.30.40") == false);
assert(ipv4("10.20.030.40") == false);
assert(ipv4("127.0.1") == false);
assert(ipv4("127.0.0.0.1") == false);
assert(ipv4("..255.255") == false);
assert(ipv4("127.0.0.1\n") == false);
assert(ipv4("\n127.0.0.1") == false);
assert(ipv4(" 127.0.0.1") == false);
assert(ipv4("127.0.0.1 ") == false);
assert(ipv4(" 127.0.0.1 ") == false);
assert(ipv4("127.0.0.1.") == false);
assert(ipv4(".127.0.0.1") == false);
assert(ipv4("127..0.1") == false);
