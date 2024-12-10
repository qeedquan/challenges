#!/usr/bin/env python3

"""

This challenge is a search for the shortest implementation of a hash function that is collision resistant, i.e., it should be infeasible to find two different messages with the same hash.

As a cop, you try to invent and implement a hash function finding the best compromise between code size and collision resistance. Use too many bytes and another cop will outgolf you!

As a robber, you try to foil the cops' attempts by cracking their functions, proving that they are unsuitable. This will force them to use more bytes to strengthen their algorithms!

Cops challenge
Task
Implement a cryptographic hash function H : I -> O of your choice, where I is the set of all non-negative integers below 2230 and O is the set of all non-negative integers below 2128.

You can either implement H as an actual function that accepts and returns a single integer, a string representation of an integer or an array of integers or a full program that reads from STDIN and prints to STDOUT in base 10 or 16.

Scoring
H that it has to resist the robbers challenge defined below.

If a robber defeats your submission in the first 168 hours after posting it, it is considered cracked.

The implementation of H should be as short as possible. The shortest uncracked submission will be the winner of the cops challenge.

Additional rules
If you implement H as a function, please provide a wrapper to execute the function from within a program that behaves as explained above.

Please provide at least three test vectors for your program or wrapper (example inputs and their corresponding outputs).

H can be your novel design (preferred) or a well-known algorithm, as long as you implement it yourself. It is forbidden to use any kind in-built hash function, compression function, cipher, PRNG, etc.

Any built-in commonly used to implement hashing functions (e.g., base conversion) is fair game.

The output of your program or function must be deterministic.

There should be a free (as in beer) compiler/interpreter that can be run on a x86 or x64 platform or from within a web browser.

Your program or function should be reasonably efficient and has to hash any message in I below 2219 in less than a second.

For edge cases, the (wall) time taken on my machine (Intel Core i7-3770, 16 GiB of RAM) will be decisive.

Given the nature of this challenge, it is forbidden to change the code of your answer in any way, whether it alters the output or not.

If your submission has been cracked (or even if it hasn't), you can post an additional answer.

If your answer is invalid (e.g., it doesn't comply with the I/O specification), please delete it.

Example

Python 2.7, 22 bytes
def H(M):
 return M%17
Wrapper
print H(int(input()))
Robbers challenge

Task
Crack any of the cops' submissions by posting the following in the robbers' thread: two messages M and N in I such that H(M) = H(N) and M ≠ N.

Scoring
Cracking each cop submissions gains you one point. The robber with the most points wins.

In the case of a tie, the tied robber that cracked the longest submission wins.

Additional rules
Every cop submission can only be cracked once.

If a cop submission relies on implementation-defined or undefined behavior, you only have to find a crack that works (verifiably) on your machine.

Each crack belongs to a separate answer in the robbers' thread.

Posting an invalid cracking attempt bans you from cracking that particular submission for 30 minutes.

You may not crack your own submission.

Example
Python 2.7, 22 bytes by user8675309
1
and

18

"""

"""

@aaaaaaaaaaaa

In pseudocode:

hash = 1
3 times:
    for i in input:
        hash = hash + i
        hash = hash xor hash * 14^14
        hash = hash mod (26^26 + 1)
output hash
Example hashes:

"" (empty string) -> 1
"Test" -> 2607833638733409808360080023081587841
"test" -> 363640467424586895504738713637444713

It may be a bit on the simple side, the output range is only a little more than 122 bits, the triple iteration strengthening is already a bit broken as it does exactly the same thing every time, so input that hash to 1 in the first iteration will be a full break. But it is short, and there is no fun in being too safe.

"""

def hash(s):
    h = 1
    for _ in range(3):
        for i in s:
            h += i
            h ^= h*11112006825558016
            h %= 6156119580207157310796674288400203777
    return h

def main():
    assert(hash(b"") == 1)
    assert(hash(b"Test") == 2607833638733409808360080023081587841)
    assert(hash(b"test") == 363640467424586895504738713637444713)

main()
