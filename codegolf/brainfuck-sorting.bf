@JesterBLUE

How it works
Read all numbers
Decrement each number, keep count of how many times you do this.
When something hits zero, print the count
Repeat until count rolls over.
Details
Memory: 0(start padding),[input],...,count,0(padding),0 (more padding)

> (start padding)
,[>,] read input
+ count=1
[ while count !=0
    <[-<] decrement all inputs
    >[>] go to an input that was just decremented to zero, or padding
    > point to next input or more padding
    [ if not padding
         <- change the 0 to 255 so it doesn't stop the next decrement pass
         [>]<. point to and print count
         >> point to more padding
    ]
    <<+ increment count
]

