#!/usr/bin/env python3

"""

You can send messages that consists only of the first K small letters of the English alphabet. Among the messages of minimal length that guarantee that an unknown phrase of length N is a substring of the message, find the lexicographically smallest.

Input: Two integers K and N.
Answer: Lexicographically smallest among messages of minimal length according to aforementioned rules.

Example:

input:
2 2

answer:
aabba

"""

"""

https://www.geeksforgeeks.org/dsa/hierholzers-algorithm-directed-graph/
https://www.geeksforgeeks.org/dsa/min-length-string-with-all-substrings-of-size-n/
https://charlesreid1.github.io/graphs-for-bioinformatics-part-2-finding-eulerian-paths.html

"""

def lexicographically_smallest_message(K, N):
    alphabet = [chr(97 + i) for i in range(K)]
    seen = set()
    edges = []
    
    # Standard Hierholzer's DFS to find the Eulerian path
    def dfs(node):
        for char in alphabet:
            next_edge = node + char
            if next_edge not in seen:
                seen.add(next_edge)
                dfs(next_edge[1:])
                edges.append(char)

    # Start from the string of (N-1) 'a's
    start_node = 'a' * (N - 1)
    dfs(start_node)
    
    # The reversed edges gives the Eulerian path body
    return start_node + "".join(edges[::-1])

def main():
    assert(lexicographically_smallest_message(2, 2) == "aabba")
    assert(lexicographically_smallest_message(2, 3) == "aaababbbaa")

main()
