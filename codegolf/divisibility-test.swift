/*

Task
Given two strictly positive integers n and d as input, determine whether n is evenly divisible by d, i.e., if there exists an integer q such that n = qd.

You may write a program or a function and use any of the our standard methods of receiving input and providing output.

The output should be a truthy or a falsy value; truthy if n is divisible by d, and falsy otherwise.

Your code only has to handle integers it can represent natively, as long as it works for all signed 8-bit integers. However, your algorithm has to work for arbitrarily large integers.

You may use any programming language, but note that these loopholes are forbidden by default.

This is code-golf, so the shortest valid answer – measured in bytes – wins.

Test cases
 n,  d    output

 1,  1    truthy
 2,  1    truthy
 6,  3    truthy
17, 17    truthy
22,  2    truthy
 1,  2    falsy
 2,  3    falsy
 2,  4    falsy
 3,  9    falsy
15, 16    falsy

*/

func divisible(_ n: Int, _ d: Int) -> Bool {
    return d != 0 && n % d == 0
}

assert(divisible(1, 1) == true)
assert(divisible(2, 1) == true)
assert(divisible(6, 3) == true)
assert(divisible(17, 17) == true)
assert(divisible(22, 2) == true)
assert(divisible(1, 2) == false)
assert(divisible(2, 3) == false)
assert(divisible(2, 4) == false)
assert(divisible(3, 9) == false)
assert(divisible(15, 16) == false)
