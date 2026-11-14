#=

Given natural numbers a, b, and n, your task is to determine the discrete logarithm of b with base a modulo n.
Specifically, you need to find a number x (0≤x<n) such that a^x≡b(modn).

Input
The input consists of a single line containing three integers a, b, and n, separated by spaces (0≤a,b,n≤10^12), with the condition that n=0.

Output
Output −1 on the first line if the discrete logarithm does not exist.
Otherwise, print the value of the discrete logarithm.
If there are multiple possible answers, any one of them can be printed.

Examples
Input #1
2 4 6

Answer #1
2

=#

function discrete_log(g, h, p)
    for x in 0:p-2
        if powermod(g, x, p) == h
            return x
        end
    end
    return -1
end

println(discrete_log(2, 4, 6))
