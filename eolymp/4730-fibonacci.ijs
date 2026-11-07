NB. Fibonacci numbers is a sequence of numbers f(n), defined by the formula:
NB.
NB. f(0)=1,
NB.
NB. f(1)=1,
NB.
NB. f(n)=f(n−1)+f(n−2)
NB.
NB. Given a value of n, find the n-th Fibonacci number.
NB.
NB. Input
NB. One nonnegative integer n (n≤45), representing the Fibonacci number to be printed.
NB.
NB. Output
NB. Print the n-th Fibonacci number.
NB.
NB. Examples
NB. Input #1
NB. 4
NB.
NB. Answer #1
NB. 5

fib =: 3 : '<. 0.5 + (%:5) %~ (2 %~ 1+%:5)^(y+1)'

1!:2&2 fib"0 i.4 10

