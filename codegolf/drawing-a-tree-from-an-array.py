#!/usr/bin/env python3

"""

Given a possibly nested, non-empty array of single-digit positive integers (not guaranteed unique), output the ASCII-art representation as a tree, using the box-drawing characters ┌ ┴ ┐ ─ │ ┬ ┼. (These were copied from Code Page 437, but you can use any equivalent representation).

Every integer of the array should be a leaf of the tree. Elements the same level deep in the array should be present at the same level of the tree. All elements should be separated by enough whitespace to be distinct (up to you to determine how wide, minimum of one space between).

For example, given array [[1, [2]], [3, [4, 5]]], output the following tree

 ┌─┴─┐
┌┴┐ ┌┴─┐
1 │ 3 ┌┴┐
  2   4 5
For array [1, 2, 3] the tree could look like

┌─┼─┐
1 2 3
But the array [[1, 2, 3]] would look like

  │
┌─┼─┐
1 2 3
While the array [1, [1, [1, [1]]]] could look like

 ┌─┴┐
 1 ┌┴─┐
   1 ┌┴┐
     1 │
       1
As a more complicated example, [1, [[[2, 3], 4], 5]] could be

┌┴───┐
1  ┌─┴┐
 ┌─┴┐ 5
┌┴┐ 4
2 3
or several other variations.

Input and output can be given by any convenient method.
You can print it to STDOUT or return it as a function result.
Either a full program or a function are acceptable.
Any amount of extraneous whitespace is acceptable, so long as the characters line up appropriately.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

"""

# ported from @Beefster solution
def layer(item):
    if isinstance(item, int):
        return [str(item)]

    subs = [layer(sub) for sub in item]
    longest = max(map(len, subs))
    for sub in subs:
        sub += [' ' * len(sub[0])] * (longest - len(sub))
    below = [' '.join(l) for l in zip(*subs)]
    top = below[0]
    l = len(top)
    if len(subs) == 1:
        return ['│'.center(l), *below]
    seen = 0
    expected = len(subs)
    builder = [' '] * l
    for i in range(l):
        c = top[i]
        if c in '┴┼│123456789':
            seen += 1
            if seen == 1:
                builder[i] = '┌'
            elif seen == expected:
                builder[i] = '┐'
            else:
                builder[i] = '┬'
        elif 0 < seen < expected:
            builder[i] = '─'
    center = l // 2
    if builder[center] == '┬':
        builder[center] = '┼'
    else:
        builder[center] = '┴'
    return [''.join(builder), *below]

def output(tree):
    for line in tree:
        print(line)
    print()

def main():
    output(layer([[1, [2]], [3, [4, 5]]]))
    output(layer([1, 2, 3]))
    output(layer([[1, 2, 3]]))
    output(layer([1, [1, [1, [1]]]]))
    output(layer([1, [[[2, 3], 4], 5]]))

main()
