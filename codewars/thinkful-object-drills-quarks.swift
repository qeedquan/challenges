/*

Background
You're modelling the interaction between a large number of quarks and have decided to create a Quark class so you can generate your own quark objects.

Quarks are fundamental particles and the only fundamental particle to experience all four fundamental forces.

Your task
Your Quark class should allow you to create quarks of any valid color ("red", "blue", and "green") and any valid flavor ('up', 'down', 'strange', 'charm', 'top', and 'bottom').

Every quark has the same baryon_number (BaryonNumber in C#): 1/3.

Every quark should have an .interact() (.Interact() in C#) method that allows any quark to interact with another quark via the strong force. When two quarks interact they exchange colors.

Example

>>> q1 = Quark("red", "up")
>>> q1.color
"red"
>>> q1.flavor
"up"
>>> q2 = Quark("blue", "strange")
>>> q2.color
"blue"
>>> q2.baryon_number
0.3333333333333333
>>> q1.interact(q2)
>>> q1.color
"blue"
>>> q2.color
"red"

*/

public class Quark {
    public var color: String
    public var flavor: String
    public var baryon_number: Double = 1 / 3

    public init(_ color: String, _ flavor: String) {
        self.color = color
        self.flavor = flavor
    }

    public func interact(_ other: inout Quark) {
        (self.color, other.color) = (other.color, self.color)
    }
}

var q1 = Quark("red", "up")
print(q1.color)
print(q1.flavor)
var q2 = Quark("blue", "strange")
print(q2.color)
print(q2.baryon_number)
q1.interact(&q2)
print(q1.color)
print(q2.color)
