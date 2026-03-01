/*

Challenge
Find an expression, at most 100 bytes long, with the longest type signature.

Rules
Any statically typed language with type inference is allowed
The type must be non-ambiguous, but otherwise may include types without defined instances. For example Num [a] and Eq [a] are allowed, even without a defined instance
No imports other than the minimum required to compile a program with STDIN/STDOUT
Infinite types are not allowed
If an answer has more than one expression, only one may contribute to the score. For example, although the type signature of composition is (.) :: (b -> c) -> (a -> b) -> a -> c, having a score of 20, the answer with 25 copies of (.)\n would have a score of 20, not 500
The expression must be, at most, 100 bytes
The score is the number of characters in the type signature, excluding the name of the function and any whitespace. For example, f :: (a -> b) -> a -> b would have a score of 12
The highest score wins!

Examples
Although other languages are allowed, the following examples are in Haskell:

Score: 112
map.map.map.map.map.map.map.map.map.map.map.map.map.map.map.map.map.map.map.map.map.map.map.map.map
f :: (a -> b)
 -> [[[[[[[[[[[[[[[[[[[[[[[[[a]]]]]]]]]]]]]]]]]]]]]]]]]
 -> [[[[[[[[[[[[[[[[[[[[[[[[[b]]]]]]]]]]]]]]]]]]]]]]]]]

Score: 240
(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.).(.)
f :: (b->c)->(a->a1->a2->a3->a4->a5->a6->a7->a8->a9->a10->a11->a12->a13->a14->a15->a16->a17->a18->a19->a20->a21->a22->a23->a24->b)->a1->a2->a3->a4->a5->a6->a7->a8->a9->a10->a11->a12->a13->a14->a15->a16->a17->a18->a19->a20->a21->a22->a23->a24->c

Score: 313
foldl$foldl$foldl$foldl$foldl$foldl$foldl$foldl$foldl$foldl$foldl$foldl$foldl$foldl$foldl$foldl(.)
f :: (Foldable t, Foldable t1, Foldable t2, Foldable t3, Foldable t4,
  Foldable t5, Foldable t6, Foldable t7, Foldable t8, Foldable t9,
  Foldable t10, Foldable t11, Foldable t12, Foldable t13,
  Foldable t14, Foldable t15) =>
 (b -> c)
 -> t (t1 (t2 (t3 (t4 (t5 (t6 (t7 (t8 (t9 (t10 (t11 (t12 (t13 (t14 (t15 (b
 -> b))))))))))))))))
 -> b
 -> c

Score: 538
lex.show.foldl1.mapM.traverse.sum.mapM.sum.traverse.(.).mapM.scanl.zipWith3((.traverse).(.traverse))
 (Num
    (a -> ([[c]] -> t3 [[a1 -> f b]]) -> [[c]] -> t3 [[a1 -> f b]]),
  Num
    (([[c]] -> t3 [[a1 -> f b]])
     -> t1 (t2 ([[c]] -> t3 [[a1 -> f b]]))
     -> [[c]]
     -> t3 [[a1 -> f b]]),
  Show
    (t (t1 (t2 ([[c]] -> t3 [[a1 -> f b]])))
     -> t1 (t2 ([[c]] -> t3 [[a1 -> f b]]))),
  Applicative f, Foldable t,
  Foldable ((->) (t1 (t2 ([[c]] -> t3 [[a1 -> f b]])) -> a)),
  Foldable
    ((->) (([[c]] -> t3 [[a1 -> f b]]) -> a -> t3 [a1 -> f b])),
  Traversable t1, Traversable t2, Traversable t3, Traversable t4,
  Traversable t5,
  Traversable ((->) (t1 (t2 ([[c]] -> t3 [[a1 -> f b]])))),
  Traversable ((->) ([[c]] -> t3 [[a1 -> f b]]))) =>
 [(t5 (t4 a1) -> f (t5 (t4 b))) -> c -> a1 -> f b]
 -> [(String, String)]

*/

#define a int, int, int, int
#define b a, a, a, a, a, a, a
#define c b, b, b, b, b, b, b
#define d c, c, c, c, c, c, c
#define e d, d, d, d, d, d, d
#define g e, e, e, e, e, e, e
#define h g, g, g, g, g, g, g
#define i h, h, h, h, h, h, h

void
f(i)
{
}

int
main()
{
	return 0;
}
