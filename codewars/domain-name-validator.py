#!/usr/bin/env python3

"""

this kata you have to create a domain name validator mostly compliant with RFC 1035, RFC 1123, and RFC 2181

For purposes of this kata, following rules apply:

Domain name may contain subdomains (levels), hierarchically separated by . (period) character
Domain name must not contain more than 127 levels, including top level (TLD) ( https://en.wikipedia.org/wiki/Top-level_domain )
Domain name must not be longer than 253 characters (RFC specifies 255, but 2 characters are reserved for trailing dot and null character for root level)
Level names must be composed out of lowercase and uppercase ASCII letters, digits and - (minus sign) character
Level names must not start or end with - (minus sign) character
Level names must not be longer than 63 characters
Top level (TLD) must not be fully numerical

Additionally, in this kata

Domain name must contain at least one subdomain (level) apart from TLD
Top level validation must be naive - ie. TLDs nonexistent in IANA register are still considered valid as long as they adhere to the rules given above.
The validation function accepts string with the full domain name and returns boolean value indicating whether the domain name is valid or not.

Examples:

validate('codewars') == False
validate('g.co') == True
validate('codewars.com') == True
validate('CODEWARS.COM') == True
validate('sub.codewars.com') == True
validate('codewars.com-') == False
validate('.codewars.com') == False
validate('example@codewars.com') == False
validate('127.0.0.1') == False

"""

import re

def validate(domain):
    pattern = r'(?=.{1,253}$)(?:[A-Za-z0-9](?:[A-Za-z0-9-]{0,61}[A-Za-z0-9])?\.){1,126}(?!\d+$)[A-Za-z0-9](?:[A-Za-z0-9-]{0,61}[A-Za-z0-9])?'
    return bool(re.fullmatch(pattern, domain))

def main():
    assert(validate('codewars') == False)
    assert(validate('g.co') == True)
    assert(validate('codewars.com') == True)
    assert(validate('CODEWARS.COM') == True)
    assert(validate('sub.codewars.com') == True)
    assert(validate('codewars.com-') == False)
    assert(validate('.codewars.com') == False)
    assert(validate('example@codewars.com') == False)
    assert(validate('127.0.0.1') == False)

main()
