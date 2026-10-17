#!/usr/bin/env python3

"""

I'm making a page selector for my super cool terminal-based blog program. In order for it to fit correctly into the design, it has to have some constraints.

The page selector can only display a certain number of numbers at a time due to the constraints of the UI system. If there are more characters then can fit, they must be removed and replaced with an ellipsis (which itself counts as a number). The system will try to display up to three numbers around the selected one (which is displayed surrounded by square brackets) and distribute the rest of the numbers evenly at the ends.

Your task is to, given a number of pages, selector width (always more than or equal to 3, and always odd), and currently selected number, all of which are both required and positive, print to STDOUT the resulting page selector.

Examples
In: 5 5 1
Out: < [1] 2 3 4 5 >

In: 5 3 1
Out: < [1] ... 5 >

In: 7 5 3
Out: < 1 ... [3] ... 7 >

In: 11 7 4
Out: < 1 ... 3 [4] 5 ... 11 >

In: 11 7 7
Out: < 1 ... 6 [7] 8 ... 11 >

In: 11 9 7
Out: < 1 2 ... 6 [7] 8 ... 10 11 >

In: 7 3 3
Out: < ... [3] ... >

"""

ELLIPSIS = ["..."]

def window(items, limit):
    if limit < 2 and len(items) > 1:
        return ELLIPSIS
    if limit == len(items):
        return items
    return items[:limit - 2] + ELLIPSIS + [items[-1]]

def page_window(items, start, length, remaining):
    if length == 1 and remaining > 1:
        return items[:start - 1] + ELLIPSIS

    if start < 2 and len(items) > 1:
        return ELLIPSIS

    if start == len(items):
        if length - 2 or items == []:
            return items
        return items[:-1] + ELLIPSIS

    if length - 2:
        return [items[0], *ELLIPSIS, items[-1]]

    return items[:start - 1] + ELLIPSIS


# Ported from @Ajax1234 solution
def pagination(total, width, current):
    left = min(
        (width - 1) // 2 + (width - 1) % 2,
        current - 1,
    )
    before = list(range(1, current))
    after = list(range(current + 1, total + 1))
    remaining_width = width - left - 1

    pages = (
        page_window(
            before,
            left,
            remaining_width,
            len(after),
        )
        + [f"[{current}]"]
        + window(after, remaining_width)
    )
    return "< " + " ".join(map(str, pages)) + " >"

def main():
    print(pagination(5, 5, 1))
    print(pagination(5, 3, 1))
    print(pagination(7, 5, 3))
    print(pagination(11, 7, 4))
    print(pagination(11, 7, 7))
    print(pagination(11, 9, 7))
    print(pagination(7, 3, 3))

main()
