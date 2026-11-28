#!/usr/bin/env python3

"""

Goal:
A tree can be represented as a nested list: the list elements represent nodes, and a node is a pair of the node name and node children.

Your program takes as input a nested list of pairs, and should output a pretty tree.

Examples:
Here are four example test cases below

["stump",[]]

["trunk",[["branch",[["leaf",[]],["leaf",[]]]],["branch",[]]]]

[".",[["bin",[]],["usr",[["bin",[]],["local",[["bin",[]],["lib",[]]]]]]]]

["kingdom",[["mineral",[]],["animal",[["dog",[["schnauzer",[]],["whippet",[]]]]]],["vegetable",[["cabbage",[]]]]]]
And these are the corresponding outputs

1

stump
2

trunk
├── branch
│   ├── leaf
│   └── leaf
└── branch
3

.
├── bin
└── usr
    ├── bin
    └── local
        ├── bin
        └── lib
4

kingdom
├── mineral
├── animal
│   └── dog
│       ├── schnauzer
│       └── whippet
└── vegetable
    └── cabbage

Notes:
If the characters │, ├, └, ─ are not conveniently available in your language, you may substitute with the ASCII characters |, +, L, - respectively.

You may assume there is one unique root node. You may assume the input will be "nice", it doesn't matter what your program does if the input is not well-formed.

To avoid unfair advantages to any particular language, some flexibility in the input format is allowed within reason. For example, specifying the nesting with parens () or braces {} is OK. If it's more convenient for the node labels to be integers instead of strings, that's OK. Extra whitespace in the input is OK, as long as it's not being used to define structure. If you take the input as a string literal and parse it directly, that's OK.

No messing with the underlying structure of the tree! E.g., you may not change how a leaf node is represented.

Tip: the representation used in the examples is valid json, so you can paste it into a json linter to better see the nesting.

Scoring:
This is code golf, shortest code wins.

"""

# ported from @jeptguy solution
def walk(links, string, nest, lastnode):
    (top, nodes) = links
    
    prefix = "├── "
    if lastnode:
        prefix = "└── "
    print(string + (prefix * nest) + top)

    for node in nodes:
        anchor = "│   "  
        if lastnode:
            anchor = "    "
        walk(node, string + (anchor * nest), 1, nodes[-1] is node)

    if nest == 0:
        print()

def tree(links):
    walk(links, "", 0, False)

def main():
    tree(["stump", []])
    tree(["trunk", [["branch", [["leaf", []], ["leaf", []]]], ["branch", []]]])
    tree([".", [["bin" ,[]], ["usr", [["bin",[]], ["local", [["bin", []], ["lib", []]]]]]]])
    tree(["kingdom", [["mineral", []], ["animal", [["dog", [["schnauzer", []], ["whippet", []]]]]], ["vegetable", [["cabbage", []]]]]])

main()
