#!/usr/bin/env python3

"""

You are the electoral strategist for a sudden late entrant in the 2020 US presidental election.

Your task: print out the names of states* your candidate will win, totalling at least 270 electoral college votes.

Background
Each state (and Washington DC) in the US system has an arbitrary number of "electoral college votes". A candidate has to win a majority of the 538 votes available, so at least 270 votes.

The number of votes for each state is:

[['Alabama', 9], ['Alaska', 3], ['Arizona', 11], ['Arkansas', 6], ['California', 55], ['Colorado', 9], ['Connecticut', 7], ['Delaware', 3], ['Florida', 29], ['Georgia', 16], ['Hawaii', 4], ['Idaho', 4], ['Illinois', 20], ['Indiana', 11], ['Iowa', 6], ['Kansas', 6], ['Kentucky', 8], ['Louisiana', 8], ['Maine', 4], ['Maryland', 10], ['Massachusetts', 11], ['Michigan', 16], ['Minnesota', 10], ['Mississippi', 6], ['Missouri', 10], ['Montana', 3], ['Nebraska', 5], ['Nevada', 6], ['New Hampshire', 4], ['New Jersey', 14], ['New Mexico', 5], ['New York', 29], ['North Carolina', 15], ['North Dakota', 3], ['Ohio', 18], ['Oklahoma', 7], ['Oregon', 7], ['Pennsylvania', 20], ['Rhode Island', 4], ['South Carolina', 9], ['South Dakota', 3], ['Tennessee', 11], ['Texas', 38], ['Utah', 6], ['Vermont', 3], ['Virginia', 13], ['Washington', 12], ['Washington DC', 3], ['West Virginia', 5], ['Wisconsin', 10], ['Wyoming', 3]]

Input
None

Output
A list (or similar) containing just the names of the states in your winning strategy. If a string, there must be separators between state names. States must be capitalised as in the list provided above.

You must not output anything other than valid state names and separators. The number of states in your strategy is up to you.

Rules
You may not use any external (or built-in) list of US state names. Standard loopholes are forbidden.

This is code golf. Shortest code in bytes wins, with the electoral college score as a tie-breaker.

Since there is no input, your code can be a program/script/statement rather than a function.

If you are using space as a separator, then you can't include any states with spaces in the name. Or you would have to do something like enclosing each state name in double quotes. (A separator has to be something that could be used to automatically split the string up into the correct elements.)

* For the purpose of this challenge, Washington DC is considered a state.

"""

STATES = [['Alabama', 9], ['Alaska', 3], ['Arizona', 11], ['Arkansas', 6], ['California', 55], ['Colorado', 9], ['Connecticut', 7], ['Delaware', 3], ['Florida', 29], ['Georgia', 16], ['Hawaii', 4], ['Idaho', 4], ['Illinois', 20], ['Indiana', 11], ['Iowa', 6], ['Kansas', 6], ['Kentucky', 8], ['Louisiana', 8], ['Maine', 4], ['Maryland', 10], ['Massachusetts', 11], ['Michigan', 16], ['Minnesota', 10], ['Mississippi', 6], ['Missouri', 10], ['Montana', 3], ['Nebraska', 5], ['Nevada', 6], ['New Hampshire', 4], ['New Jersey', 14], ['New Mexico', 5], ['New York', 29], ['North Carolina', 15], ['North Dakota', 3], ['Ohio', 18], ['Oklahoma', 7], ['Oregon', 7], ['Pennsylvania', 20], ['Rhode Island', 4], ['South Carolina', 9], ['South Dakota', 3], ['Tennessee', 11], ['Texas', 38], ['Utah', 6], ['Vermont', 3], ['Virginia', 13], ['Washington', 12], ['Washington DC', 3], ['West Virginia', 5], ['Wisconsin', 10], ['Wyoming', 3]]

def main():
    for p in STATES:
        print(p[0], p[1])

main()
