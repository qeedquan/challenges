{-

Hutton's Razor is a very standard minimum viable interpreted language. It's a language which contains exactly two things: integer constants and addition. This task asks you to write an interpreter for it.

The abstract syntax tree of Hutton's Razor can be expressed in Haskell using a recursive ADT:

data Razor
  = Lit Int
  | Add Razor Razor
and so we can write a few simple "programs" like

ex1 :: Razor
ex1 = Add (Lit 1) (Lit 2)

ex2 :: Razor
ex2 = Add (Lit 1) (Add (Lit 2) (Add (Lit 3) (Lit 4)))
or even "program rewriters" like

ex3 :: Razor -> Razor
ex3 r = Add (Lit 1000000) r
The first task is to write an interpreter for Hutton's Razor

interpret :: Razor -> Int
interpret = error "todo"
The second task is to write a pretty-printer. For simplicity and canonicity, always surround Add applications with parentheses, use no spaces, and print whole number literals.

pretty :: Razor -> String
pretty = error "todo"
For intance

pretty (Add (Lit 1) (Lit 2)) == "(1+2)"

-}

module Razor where

data Razor
  = Lit Int
  | Add Razor Razor
  
interpret :: Razor -> Int
interpret (Lit n) = n
interpret (Add r1 r2) = (interpret r1) + (interpret r2)

pretty :: Razor -> String
pretty r = case r of
  Lit n -> show n
  Add r1 r2 -> "(" ++ pretty r1 ++ "+" ++ pretty r2 ++ ")"

