/*

Given an array of 3 integers a, b and c, determine if they form a pythagorean triple.

A pythagorean triple is formed when:
> c^2 = a^2 + b^2

where c is the largest value of a, b, c.


For example: a = 3, b = 4, c = 5
forms a pythagorean triple, because
5^2 = 3^2 + 4^2

## Return Values

* 1 if a, b and c form a pythagorean triple
* 0 if a, b and c do not form a pythagorean triple
* For Python: return True or False

*/

func pythagoreanTriple(_ a: Int, _ b: Int, _ c: Int) -> Bool {
    return (a * a) + (b * b) == (c * c)
}

assert(pythagoreanTriple(3, 4, 5) == true)
assert(pythagoreanTriple(3, 5, 7) == false)
