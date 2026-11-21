/*

7 Wonders is a board game where each player can score points by building stages of their Wonder, by war, and by building structures. This challenge focuses on the points scored by building a specific type of structures, the scientific ones.

Each scientific structure, once built, provides the player a symbol, which can be either a gear, a compass, or a tablet1. There are two different ways in which victory points are scored: from sets of identical symbols and from sets of 3 different symbols:

for each of the three existing scientific symbols, the player gains a number of points equal to the number of symbols squared;
for each group of three different symbols, the player scores 7 victory points.
Moreover, there are some special actions that grant the player an additional scientific symbol of their choice.

1: a clay tablet, not a computing device

Challenge
Given the number of scientific symbols of the three kinds and the number of completed special actions, calculate the score.

Formally, given four non-negative integer numbers a,b,c,z, where a,b,c are the number of scientific symbols and z is the number of completed special actions, compute

f(a,b,c,z)=
a^2 + b^2 + c^2 + 7*min(a,b,c)
max(f(a+1,b,c,z-1), f(a,b+1,c,z-1), f(a,b,c+1,z-1)) if z=0 otherwise

You may assume z≤2, since a player cannot do more than 2 special actions. You may not assume the three numbers a,b,c are given in any particular order.

Shortest solution wins, I/O format is flexible, standard rules apply.

Examples
(0, 5, 0, 0) -> 25
(0, 0, 6, 0) -> 36
(0, 5, 0, 1) -> 36
(3, 2, 1, 0) -> 21
(4, 2, 1, 0) -> 28
(3, 3, 1, 0) -> 26
(3, 2, 2, 0) -> 31
(3, 2, 1, 1) -> 31
(5, 2, 1, 0) -> 37
(4, 3, 1, 0) -> 33
(4, 2, 2, 0) -> 38
(4, 2, 1, 1) -> 38
(4, 3, 1, 0) -> 33
(3, 4, 1, 0) -> 33
(3, 3, 2, 0) -> 36
(3, 3, 1, 1) -> 36
(4, 2, 2, 0) -> 38
(3, 3, 2, 0) -> 36
(3, 2, 3, 0) -> 36
(3, 2, 2, 1) -> 38
(3, 2, 1, 2) -> 38

Sample ungolfed solution in Haskell

import qualified Data.Text as T

f :: Int -> [Int] -> Int
f 0 xs = sum (map (\x -> x * x) xs) + minimum xs * 7
f n xs = maximum [f (n-1) [x + fromEnum (i == j) | (j, x) <- zip [0..] xs] | i <- [0..length xs-1]]

raw_testcases :: T.Text
raw_testcases = T.pack  "\
  \ (0, 5, 0, 0) -> 25 ; \
  \ (0, 0, 6, 0) -> 36 ; \
  \ (0, 5, 0, 1) -> 36 ; \
  \ (3, 2, 1, 0) -> 21 ; \
  \ (4, 2, 1, 0) -> 28 ; \
  \ (3, 3, 1, 0) -> 26 ; \
  \ (3, 2, 2, 0) -> 31 ; \
  \ (3, 2, 1, 1) -> 31 ; \
  \ (5, 2, 1, 0) -> 37 ; \
  \ (4, 3, 1, 0) -> 33 ; \
  \ (4, 2, 2, 0) -> 38 ; \
  \ (4, 2, 1, 1) -> 38 ; \
  \ (4, 3, 1, 0) -> 33 ; \
  \ (3, 4, 1, 0) -> 33 ; \
  \ (3, 3, 2, 0) -> 36 ; \
  \ (3, 3, 1, 1) -> 36 ; \
  \ (4, 2, 2, 0) -> 38 ; \
  \ (3, 3, 2, 0) -> 36 ; \
  \ (3, 2, 3, 0) -> 36 ; \
  \ (3, 2, 2, 1) -> 38 ; \
  \ (3, 2, 1, 2) -> 38 ; \
  \ "

splitOn :: String -> T.Text -> [T.Text]
splitOn x = filter (/= T.empty) . map T.strip . T.splitOn (T.pack x)

r :: T.Text -> Int
r = read . T.unpack

testcases :: [([Int], Int)]
testcases = [(map r $ splitOn "," $ T.dropAround (`elem` "()") x, r y) | [x, y] <- map (splitOn "->") $ splitOn ";" raw_testcases]

main = print [(x, y, z) | (x, y) <- testcases, z <- [f (last x) (init x)], y /= z]

*/

package main

func main() {
	assert(f(0, 5, 0, 0) == 25)
	assert(f(0, 0, 6, 0) == 36)
	assert(f(0, 5, 0, 1) == 36)
	assert(f(3, 2, 1, 0) == 21)
	assert(f(4, 2, 1, 0) == 28)
	assert(f(3, 3, 1, 0) == 26)
	assert(f(3, 2, 2, 0) == 31)
	assert(f(3, 2, 1, 1) == 31)
	assert(f(5, 2, 1, 0) == 37)
	assert(f(4, 3, 1, 0) == 33)
	assert(f(4, 2, 2, 0) == 38)
	assert(f(4, 2, 1, 1) == 38)
	assert(f(4, 3, 1, 0) == 33)
	assert(f(3, 4, 1, 0) == 33)
	assert(f(3, 3, 2, 0) == 36)
	assert(f(3, 3, 1, 1) == 36)
	assert(f(4, 2, 2, 0) == 38)
	assert(f(3, 3, 2, 0) == 36)
	assert(f(3, 2, 3, 0) == 36)
	assert(f(3, 2, 2, 1) == 38)
	assert(f(3, 2, 1, 2) == 38)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func f(a, b, c, z int) int {
	if z == 0 {
		return a*a + b*b + c*c + 7*min(a, b, c)
	}
	return max(f(a+1, b, c, z-1), f(a, b+1, c, z-1), f(a, b, c+1, z-1))
}
