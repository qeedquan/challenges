#!/usr/bin/env python3

"""

Description

You have devised a new encryption technique which encodes a message by inserting between its characters randomly generated strings in a clever way. Because of pending patent issues we will not discuss in detail how the strings are generated and inserted into the original message. To validate your method, however, it is necessary to write a program that checks if the message is really encoded in the final string.

Given two strings s and t, you have to decide whether s is a subsequence of t, i.e. if you can remove characters from t such that the concatenation of the remaining characters is s.

Input

The input contains several testcases. Each is specified by two strings s, t of alphanumeric ASCII characters separated by whitespace.The length of s and t will no more than 100000.

Output

For each test case output "Yes", if s is a subsequence of t,otherwise output "No".

Sample Input

sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter

Sample Output

Yes
No
Yes
No

Source

Ulm Local 2002

"""

def subsequence(s, t):
    n = len(s)
    m = len(t)
    i = 0
    j = 0
    while i < n and j < m:
        if s[i] == t[j]:
            i += 1
        j += 1
    
    if i == n:
        return "Yes"
    return "No"

def main():
    assert(subsequence("sequence", "subsequence") == "Yes")
    assert(subsequence("person", "compression") == "No")
    assert(subsequence("VERDI", "vivaVittorioEmanueleReDiItalia") == "Yes")
    assert(subsequence("caseDoesMatter", "CaseDoesMatter") == "No")

main()
