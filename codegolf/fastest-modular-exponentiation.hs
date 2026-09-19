{-

The challenge is to write code in any open source, available on linux, language of your choice to perform modular exponentiation. The input will be two randomly chosen 2048 bit positive integers numbers x and y and a 2048 bit prime z. Here is a sample snippet of python to compare to.

def pow_mod(x, y, z):
    n = 1
    while y:
        if y & 1:
            n = n * x % z
        y >>= 1
        x = x * x % z
    return n
The code should accept a file with each of the three numbers on separate lines and output the result to standard out. You may not use any libraries for modular exponentiation of course.

The code that runs the fastest on average over 100 runs on my computer wins.

For those who want really accurate timing, the best way may be for the timing code to actually be in the code you provide and for your code to simply repeat 100 times (without cheating :) ). This avoids any problems with start up overheads.

-}

module Main where

import Data.Bits

{-

Ported from @Olathe solution

Prime modulus optimization
If the modulus is guaranteed to be a prime, but the exponent might be greater than or equal to the modulus, the last line should be changed to:

          print $ modExp b (mod p (m - 1)) m
Handling multiple inputs
If you'd like it to handle multiple inputs per run, add import System.IO under the other import and the following two lines just under the print line:

          isDone <- isEOF
          if isDone then return () else main
Running
Once it's compiled, it can be run as modexp < file.

-}

seqI :: Integer -> Integer
seqI x = seq x x

seqB :: Bool -> Bool
seqB x = seq x x

getInteger :: IO Integer
getInteger = fmap (seqI . read) getLine

modExp' :: Integer -> Integer -> Integer -> Integer -> Integer
modExp' r b p m = let nextR = seqI $ mod (seqI $ r*b) m
                      nextB = seqI $ mod (seqI $ b*b) m
                      nextP = seqI $ shiftR  p 1
                      incl  = seqB $ testBit p 0
                      cont  = seqB $ nextP  /= 0
                  in  if incl
                         then if cont
                                 then modExp' nextR nextB nextP m
                                 else nextR
                         else if cont
                                 then modExp' r     nextB nextP m
                                 else r

modExp :: Integer -> Integer -> Integer -> Integer
{-# INLINE modExp #-}
modExp !b !p !m = modExp' 1 b p m

main = do
          b <- getInteger
          p <- getInteger
          m <- getInteger
          print $ modExp b p m
