/*

Create a Vector class with x and a y attributes that represent component magnitudes in the x and y directions.

Your vectors should handle vector additon with an .add() method that takes a second vector as an argument and returns a new vector equal to the sum of the vector you call .add() on and the vector you pass in.

For example:

>>> a = Vector(3, 4)
>>> a.x
3
>>> a.y
4
>>> b = Vector(1, 2)
>>> c = a.add(b)
>>> c.x
4
>>> c.y
6

Adding vectors when you have their components is easy: just add the two x components together and the two y components together to get the x and y components for the vector sum.

*/

import Foundation

public class Vector: CustomStringConvertible {
    public var x, y: Double

    public init(_ x: Double, _ y: Double) {
        self.x = x
        self.y = y
    }

    public var description: String { return "Vector(\(x), \(y))" }

    static func + (left: Vector, right: Vector) -> Vector {
        return Vector(left.x + right.x, left.y + right.y)
    }
}

var v1 = Vector(1, 2)
var v2 = Vector(3, 4)
var v3 = v1 + v2
print(v3)
