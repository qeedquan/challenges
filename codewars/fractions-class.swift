/*

You are provided with a skeleton of the class 'Fraction', which accepts two arguments (numerator, denominator).

## Example

```
Fraction fraction1 = new Fraction(4, 5);
```

Your task is to make this class string representable, and addable while keeping the result in the minimum representation possible.

```
System.out.println(fraction1.add(new Fraction(1, 8)));
// Outputs: 37/40
```

NB: DON'T use the built_in class 'fractions.Fraction'

*/

import Foundation

class Fraction: CustomStringConvertible {
    public var n = 0
    public var d = 1

    public init(_ n: Int, _ d: Int) {
        self.n = n
        self.d = d
    }

    public func canon() -> Fraction {
        let m = gcd(self.n, self.d)
        return Fraction(self.n / m, self.d / m)
    }

    public var description: String { return "\(n)/\(d)" }

    static func + (a: Fraction, b: Fraction) -> Fraction {
        let n = (a.n * b.d) + (b.n * a.d)
        let d = a.d * b.d
        let m = gcd(n, d)
        return Fraction(n / m, d / m)
    }

    static func += (a: inout Fraction, b: Fraction) {
        a = a + b
    }

    static func == (a: Fraction, b: Fraction) -> Bool {
        let a = a.canon()
        let b = b.canon()
        return a.n == b.n && a.d == b.d
    }
}

func gcd(_ m: Int, _ n: Int) -> Int {
    var a = 0
    var b = max(m, n)
    var r = min(m, n)
    while r != 0 {
        a = b
        b = r
        r = a % b
    }
    return b
}

assert((Fraction(4, 5) + Fraction(1, 8)).description == "37/40")
assert((Fraction(3, 4) + Fraction(1, 4)).description == "1/1")
assert((Fraction(911, 920) + Fraction(980, 906)).description == "863483/416760")
assert((Fraction(610, 941) + Fraction(253, 985)).description == "838923/926885")
assert((Fraction(956, 798) + Fraction(662, 189)).description == "16880/3591")
assert((Fraction(694, 485) + Fraction(853, 861)).description == "1011239/417585")
assert((Fraction(982, 111) + Fraction(219, 561)).description == "191737/20757")
assert((Fraction(344, 873) + Fraction(658, 486)).description == "41201/23571")
assert((Fraction(662, 361) + Fraction(322, 382)).description == "184563/68951")
assert((Fraction(740, 813) + Fraction(184, 348)).description == "33926/23577")
assert((Fraction(579, 441) + Fraction(543, 807)).description == "78524/39543")
assert((Fraction(212, 979) + Fraction(46, 580)).description == "83997/283910")

assert(Fraction(1, 2) == Fraction(2, 4))
