#!/usr/bin/env python3

"""

When stacking books you usually want to put the largest ones at the bottom and the smallest ones at the top. However, my latent OCD makes me feel very uneasy if I've got two books where one is shorter (in height) but wider than the other. No matter which order I place them in, the top book will extend beyond the bottom book on one side.

As an example, say one book has dimensions (10,15) and another has dimensions (11,14). No matter which way around I put them, I get an overhang. But if I have books with dimensions (4,3) and (5,6), I can avoid an overhanging by placing the latter below the former.

For the purposes of this challenge we will consider overhangs only in relation to the book immediately below. E.g. if I have a stack (5,5), (3,3), (4,4) (not that any sane person would do that), the top book counts as an overhang, although it does not extend beyond the bottom book. Similarly, the stack (3,3), (3,3), (4,4) also has only one overhang, despite the top book extending beyond the bottom one.

The Challenge
Given a list of integer pairs for book dimensions, sort those pairs/books such that the number of overhangs is minimal. You must not rotate the books - I want all the spines facing the same direction. If there are multiple solutions with the same number of overhangs, you may choose any such order. Your sorting algorithm does not have to be stable. Your implementation may assume that book dimensions are less than 216 each.

Time complexity: To make this a bit more interesting, the asymptotic worst-case complexity of your algorithm must be polynomial in the size of the stack. So you can't just test every possible permutation. Please include a short proof of your algorithm's optimality and complexity and optionally a plot that shows the scaling for large random inputs. Of course, you can't use the maximum size of the input as argument that your code runs in O(1).

You may write a program or function, take input via STDIN, ARGV or function argument in any convenient (not preprocessed) list format and either print or return the result.

This is code golf, so the shortest answer (in bytes) wins.

I am confident that a polynomial-solution exists, but if you can prove me wrong, you may submit such a proof instead of a golfed submission. In this case, you may assume P ≠ NP. I will accept the first correct such proof and award a bounty to it.

Examples
In:  [[1, 1], [10, 10], [4, 5], [7, 5], [7, 7], [10, 10], [9, 8], [7, 5], [7, 5], [3, 1]]
Out: [[10, 10], [10, 10], [9, 8], [7, 7], [7, 5], [7, 5], [7, 5], [4, 5], [3, 1], [1, 1]]

In:  [[4, 5], [5, 4], [5, 4], [5, 4], [5, 4], [4, 5], [4, 5], [4, 5], [5, 4], [4, 5]]
Out: [[4, 5], [4, 5], [4, 5], [4, 5], [4, 5], [5, 4], [5, 4], [5, 4], [5, 4], [5, 4]]
  or [[5, 4], [5, 4], [5, 4], [5, 4], [5, 4], [4, 5], [4, 5], [4, 5], [4, 5], [4, 5]]

In:  [[2, 3], [1, 1], [5, 5], [7, 1]]
Out: [[5, 5], [2, 3], [7, 1], [1, 1]]
 or  [[5, 5], [2, 3], [1, 1], [7, 1]]
 or  [[7, 1], [5, 5], [2, 3], [1, 1]]
 or  [[7, 1], [1, 1], [5, 5], [2, 3]]
I created these by hand, so let me know if you spot any mistakes.

"""

"""

@grc

After sorting the list of books in descending order (by width first and then height), this partitions the books into piles without overlaps. To determine where to place each book, its height is compared with the height of the top book in each pile. It is placed on the first pile possible, or else a new pile is created.

I'm not very good with time complexity, but I believe it would have a worst case of O(N2). There are two loops, each with at most N iterations. I also use Python's builtin sort, which is O(n log n).

My first proof that this algorithm produces optimal solutions did turn out to be incorrect. A huge thanks goes to @xnor and @Sp3000 for a great discussion in the chat about proving this (which you can read starting here). After working out a correct proof, @xnor found that part of it had already been done (Dilworth's theorem).

Here's an overview of the proof anyway (credit to @xnor and @Sp3000).

First, we define the notion of an antipile, or antichain, (quoted from @xnor):

An antipile is a sequence of books of decreasing height, but increasing width
So, each successive book is strictly taller but strictly less wide
Note that any book in an antipile overhangs over any other book in an antipile
So, no two books within an antipile can be in the same pile
As a consequence, if you can find an antipile of x books, then those books must be in different piles
So, the size of the largest antipile is a lower bound on the number of piles

Then, we sort the books in descending order by their width (first) and their height (second)*.

For each book B, we do as follows:

If B can fit on the first pile, we place it there and move on.
Otherwise, we find the earliest* pile x which B can be placed on top of. This can be a new pile if necessary.
Next, we link B to P, where P is the top book on the previous pile x - 1.
We now know that:
B is strictly* smaller in width than P, since the books are sorted in descending order by width
B is strictly greater in height than P, or we would have placed B on top of P
Now, we have constructed a link from every book (except those in the first pile), to a book in the previous pile that is greater in width and lower in height.

@Sp3000's excellent diagram illustrates this well:

https://i.sstatic.net/knANP.jpg

By following any path from the last pile (on the right), to the first pile (on the left), we get an antipile. Importantly, this antipile's length is equal to the number of piles. Hence, the number of piles used is minimal.

Finally, since we have organised the books into the minimum number of piles without overlaps, we can stack them on top of each other to get one pile with the minimum number of overlaps.

"""
def solve(a):
    r = []
    for n in sorted(a)[::-1]:
        for p in r:
            if p[-1][1] >= n[1]:
                p += [n]
                break
        else:
            r += [[n]]
    return sum(r, [])

def main():
    assert(solve([[1, 1], [10, 10], [4, 5], [7, 5], [7, 7], [10, 10], [9, 8], [7, 5], [7, 5], [3, 1]]) == [[10, 10], [10, 10], [9, 8], [7, 7], [7, 5], [7, 5], [7, 5], [4, 5], [3, 1], [1, 1]])
    assert(solve([[4, 5], [5, 4], [5, 4], [5, 4], [5, 4], [4, 5], [4, 5], [4, 5], [5, 4], [4, 5]]) == [[5, 4], [5, 4], [5, 4], [5, 4], [5, 4], [4, 5], [4, 5], [4, 5], [4, 5], [4, 5]])
    assert(solve([[2, 3], [1, 1], [5, 5], [7, 1]]) == [[7, 1], [1, 1], [5, 5], [2, 3]])

main()
