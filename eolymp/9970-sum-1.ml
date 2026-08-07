(*

Calculate the sum of the first n numbers in the sequence 1+2+3+4+5+…

Input
A natural number n, 1≤n≤100.

Output
A single number representing the sum of the first n numbers in the sequence.

Examples
Input #1
7

Answer #1
28

*)

let triangular(n: int) : int = n * (n + 1) / 2

let () = 
    print_int(triangular(7));
    print_newline();

