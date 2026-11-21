\ Problem Statement
\ Calculate the sum of several decimal values, given in input as a single line. Print the result. Do this in Forth.
\ 
\ Details
\ While Forth provides . (dot) word for printing out numbers, it doesn't generally have ready word for reading numbers from input.
\ So you'll need to construct it.
\ 
\ Word key reads single character from input and leaves its ASCII code on stack.
\ Reading char "2" for example will push 50 onto the stack. So it would be good to read characters inside a loop, subtract 48 (code for "0") from them, and add to previously collected result multiplied by 10.
\ E.g. we can define the word for reading single digit and read two-digit value:
\ 
\ : dig key 48 - ;
\ dig 10 * dig +
\ .
\ In our more general case stop reading number when space is encountered (its code is 32, anyway less than any of digits).
\ 
\ Input contains a sequence of decimal numbers to be summed, in a single line. It ends with zero (and newline).
\ 
\ Answer should give just a single value - sum of the sequence.
\ 
\ Example
\ 
\ input:
\ 1 4 9 16 25 0
\ 
\ answer:
\ 55

\ Define a constant for the number of elements
5 constant ARR-SIZE

\ Allocate memory for the array (5 cells)
create my-array ARR-SIZE cells allot

\ Helper word to populate the array with sample data
: init-array ( -- )
    1 my-array 0 cells + !
    4 my-array 1 cells + !
    9 my-array 2 cells + !
    16 my-array 3 cells + !
    25 my-array 4 cells + ! ;

\ Word to sum the array elements
\ Stack signature: ( addr count -- sum )
: sum-array ( addr count -- sum )
    0 -rot                 \ Initialize sum to 0 -> ( 0 addr count )
    0 ?do                  \ Loop from 0 to count-1
        dup @              \ Fetch the value at the current address
        rot + swap         \ Add it to our running sum, fix stack order
        cell+              \ Move to the next cell address
    loop
    drop ;                 \ Drop the remaining address pointer, leaving sum

\ --- Test the Implementation ---
init-array
my-array ARR-SIZE sum-array .
CR
