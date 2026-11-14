#!/usr/bin/env python3

"""

A family of sets is called laminar if for any two sets A and B in the family one of the following is true:

A⊆B
A⊇B
A∩B=∅

Or less mathematical:

A laminar set is a list of lists that satisfies the following condition: If two elements of the top level list have at least one element in common, one of them has to be completely contained in the other one.

Examples:

laminar:
{}
{{1,2,3},{1,2},{1},{}}
{{1,2,3,4},{1,2,3},{1,2},{3},{4}}
{{1,2,3,4},{1,2},{3,4},{1},{3}}
{{1,2,3,4},{1,3},{2,4},{1},{2},{3},{4},{}}
{{1,2,3},{4,5},{7,8},{3},{5},{7}}

not laminar:

{{1,2},{2,3}}
{{1,2,3,4},{1,2,3},{1,2},{3,4}}
{{1,2,3,4},{1,2},{3,4},{2,3},{1},{2},{3},{4}}
{{1,2,3,4,5},{1,2,3},{4,5,6}}
Your goal is to write a program of function that takes a set of set as input and returns truthy if the set is laminar and falsey if is it not laminar.

Rules:

You can take lists instead of sets as Input
If you use lists as input you can assume that the lists (top-level and/or sub-lists) are sorted (in any convenient order) and each element appear only once
Your solution should be able to handle Inputs lists with at least 250 distinct element values
You are allowed to use any type to represent the elements of the list (as long as it has enough distinct values)
This is code-golf the shortest solution (per language) wins.

"""

# Ported from @mousetail solution
def laminar(L):
    return all(a&b in (a, b, a-a) for a in L for b in L)

def main():
    truthy=[[],
        [{1, 2, 3}, {1, 2}, {1}, set()],
        [{1, 2, 3, 4}, {1, 2, 3}, {1, 2}, {3}, {4}],
        [{1, 2, 3, 4}, {1, 2}, {3, 4}, {1}, {3}],
        [{1, 2, 3, 4}, {1, 3}, {2, 4}, {1}, {2}, {3}, {4}, set()],
        [{1, 2, 3}, {4, 5}, {7, 8}, {3}, {5}, {7}],
    ]

    falsy = [
        [{1, 2}, {2, 3}],
        [{1, 2, 3, 4}, {1, 2, 3}, {1, 2}, {3, 4}],
        [{1, 2, 3, 4}, {1, 2}, {3, 4}, {2, 3}, {1}, {2}, {3}, {4}],
        [{1, 2, 3, 4, 5}, {1, 2, 3}, {4, 5, 6}],
    ]

    for i in truthy:
	    assert(laminar(i) == True)

    for i in falsy:
        assert(laminar(i) == False)

main()
