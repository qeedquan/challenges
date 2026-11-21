NB. Determine whether a natural number n, where n>1, is a prime number. A prime number is only divisible by 1 and itself.
NB.
NB. Input
NB. A natural number n (1<n<2^31).
NB.
NB. Output
NB. Print 1 if n is a prime number, otherwise print 0.
NB.
NB. Examples
NB.
NB. Input #1
NB. 7
NB.
NB. Answer #1
NB. 1
NB.
NB. Input #2
NB. 15
NB.
NB. Answer #2
NB. 0

isprime =: 1: = #@q:

1!:2&2 isprime 7
1!:2&2 isprime 15
1!:2&2 isprime 23442
1!:2&2 isprime 65535
1!:2&2 isprime 65537
