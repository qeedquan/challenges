{-

Objective
Given a positive integer, spell it out in the conlang I made.

Specification
Let n be the inputted integer. n shall be spelled out in the following specification. The entire spelling is case sensitive.

With the decimal expansion of n, let d be the least significant nonzero digit of  n.

First, d shall be spelled out like this:

1 = Qun

2 = Pis

3 = Tel

4 = Kal

5 = Pan

6 = Soh

7 = Set

8 = Qok

9 = Nof

Second, an appropriate suffix (or a "particle" in linguistic sense?) will immediately follow. This is judged by two boolean conditions: (A) Whether d has any trailing zeros, and (B) whether d is not the only nonzero digit.

If neither holds, the suffix shall be em.

If only (A) holds, the suffix shall be eh.

If only (B) holds, the suffix shall be at.

If both hold, the suffix shall be om.

Third, if (A) held, the length of the trailing zeros shall be spelled out recursively.

Finally, if (B) held, d and the trailing zeros shall be stripped off, and the remaining digits shall be spelled out recursively.

All words shall be intercalated by a single ASCII 0x20 whitespace.

Examples
1 = Qunem

2 = Pisem

7 = Setem

10 = Quneh Qunem

11 = Qunat Qunem

12 = Pisat Qunem

19 = Nofat Qunem

20 = Piseh Qunem

42 = Pisat Kalem

69 = Nofat Sohem

100 = Quneh Pisem

109 = Nofat Quneh Qunem

440 = Kalom Qunem Kalem

666 = Sohat Sohat Sohem

1945 = Panat Kalat Nofat Qunem

2000 = Piseh Telem

2022 = Pisat Pisat Piseh Qunem

44100 = Qunom Pisem Kalat Kalem

144000 = Kalom Telem Kalat Qunem

1060 = Quneh Soheh Qunem

1063 = Quneh Telat Sohem

Rules
I/O format is flexible. Standard loopholes apply.

As for input, those that are not positive integers fall in don't care situation.

As for output, trailing whitespaces are permitted, but leading whitespaces are not.

Ungolfed solution
Haskell
import Data.List
import Numeric.Natural

spellNDos :: Natural -> String
spellNDos 0 = ""
spellNDos n = go (reverse (show n)) where
    go "" = ""
    go str = let
        (zeros, digit:remaining) = partition ('0'==) str
        digitSpell = case digit of
            '1' -> "Qun"
            '2' -> "Pis"
            '3' -> "Tel"
            '4' -> "Kal"
            '5' -> "Pan"
            '6' -> "Soh"
            '7' -> "Set"
            '8' -> "Qok"
            _   -> "Nof"
        suffix = case (null zeros, null remaining) of
            (False, False) -> "om "
            (False, _    ) -> "eh "
            (_    , False) -> "at "
            _              -> "em "
        in digitSpell ++ suffix ++ spellNDos (genericLength zeros) ++ go remaining

-}

import Data.List
import Numeric.Natural

spellNDos :: Natural -> String
spellNDos 0 = ""
spellNDos n = go (reverse (show n)) where
    go "" = ""
    go str = let
        (zeros, digit:remaining) = partition ('0'==) str
        digitSpell = case digit of
            '1' -> "Qun"
            '2' -> "Pis"
            '3' -> "Tel"
            '4' -> "Kal"
            '5' -> "Pan"
            '6' -> "Soh"
            '7' -> "Set"
            '8' -> "Qok"
            _   -> "Nof"
        suffix = case (null zeros, null remaining) of
            (False, False) -> "om "
            (False, _    ) -> "eh "
            (_    , False) -> "at "
            _              -> "em "
        in digitSpell ++ suffix ++ spellNDos (genericLength zeros) ++ go remaining
