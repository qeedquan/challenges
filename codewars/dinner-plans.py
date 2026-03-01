#!/usr/bin/env python3

"""

Two samurai generals are discussing dinner plans after a battle, but they can't seem to agree.
The discussion gets heated and you are cannot risk favoring either of them as this might damage your political standing with either of the two clans the samurai generals belong to. Thus, the only thing left to do is find what the common ground of what they are saying is.

Compare the proposals with the following function:

function commonGround(s1, s2)
The parameters s1 and s2 are the strings representing what each of the generals said. You should output a string containing the words in s1 that also occur in s2.

Each word in the resulting string shall occur once, and the order of the words need to follow the order of the first occurence of each word in s2.

If they are saying nothing in common, kill both samurai and blame a ninja. (output "death")

"""

def common_ground(s1, s2):
    w1 = s1.split(" ")
    w2 = s2.split(" ")
    r = []
    for w in w2:
        if w != "" and w in w1 and w not in r:
            r.append(w)
    if len(r) == 0:
        return "death"
    return " ".join(r)

def main():
    assert(common_ground("eat chicken", "eat chicken and rice") == "eat chicken")
    assert(common_ground("eat a burger and drink a coke", "drink a coke") == "drink a coke")
    assert(common_ground("i like turtles", "what are you talking about") == "death")
    assert(common_ground("aa bb", "aa bb cc") == "aa bb")
    assert(common_ground("aa bb cc", "bb cc") == "bb cc")
    assert(common_ground("aa bb cc", "bb cc bb aa") == "bb cc aa")
    assert(common_ground("aa bb", "cc dd") == "death")
    assert(common_ground("aa bb", "") == "death")
    assert(common_ground("", "cc dd") == "death")
    assert(common_ground("", "") == "death")

main()
