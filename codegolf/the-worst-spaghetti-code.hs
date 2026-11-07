{-

Objective
Write a full program that works exactly like the flow chart below.

Each output, which is an integer, shall be through stdout, followed by a line feed.

Each input shall be a line of string fed through stdin, and shall be judged to a predicate you choose for branching. The same predicate must be used for all branches.

The predicate must be able to judge every possible input, and must not be always truthy nor always falsy. Possible choices of the predicate include:

Truthy if the inputted string is nonempty
Truthy if the inputted string consists of whitespaces
Truthy if the inputted string can be parsed into an integer
Truthy if the inputted string is exactly Hello, world!
The flow chart

https://i.sstatic.net/lzD5J.png

Rule
Your submission need not to follow the definition above exactly, as long as the visible side-effects are the same. This rule is present to aid functional languages.

Ungolfed solution
Haskell
Truthy if the string is empty.

main :: IO ()
main = procedure1 where
    genProcedure :: Int -> IO () -> IO () -> IO ()
    genProcedure output branch1 branch2 = do
        print output
        str <- getLine
        if null str
            then branch1
            else branch2
    procedure1, procedure2, procedure3 :: IO ()
    procedure1 = genProcedure 1 procedure3 procedure2
    procedure2 = genProcedure 2 procedure1 procedure3
    procedure3 = genProcedure 3 procedure2 (pure ())

-}

main :: IO ()
main = procedure1 where
    genProcedure :: Int -> IO () -> IO () -> IO ()
    genProcedure output branch1 branch2 = do
        print output
        str <- getLine
        if null str
            then branch1
            else branch2
    procedure1, procedure2, procedure3 :: IO ()
    procedure1 = genProcedure 1 procedure3 procedure2
    procedure2 = genProcedure 2 procedure1 procedure3
    procedure3 = genProcedure 3 procedure2 (pure ())
