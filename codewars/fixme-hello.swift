/*

The code provided has a method hello which is supposed to show only those attributes which have been explicitly set. Furthermore, it is supposed to say them in the same order they were set.

But it's not working properly.

Notes
There are 3 attributes

name
age
sex ('M' or 'F')
When the same attribute is assigned multiple times the hello method shows it only once. If this happens the order depends on the first assignment of that attribute, but the value is from the last assignment.

Examples
Hello.
Hello. My name is Bob. I am 27. I am male.
Hello. I am 27. I am male. My name is Bob.
Hello. My name is Alice. I am female.
Hello. My name is Batman.
Task
Fix the code so we can all go home early.

*/

import Foundation

class Person {
    private var age = 0
    private var sex = ""
    private var name = ""

    private var order: [Int] = []

    init() {
    }

    private func updateOrder(_ value: Int) {
        if !self.order.contains(value) {
            self.order.append(value)
        }
    }

    @discardableResult
    func setAge(_ age: Int) -> Person {
        self.age = age
        self.updateOrder(0)
        return self
    }

    @discardableResult
    func setSex(_ sex: String) -> Person {
        self.sex = sex
        self.updateOrder(1)
        return self
    }

    @discardableResult
    func setName(_ name: String) -> Person {
        self.name = name
        self.updateOrder(2)
        return self
    }

    func hello() -> String {
        let descriptions = [
            String(format: "I am %d.", self.age),
            String(format: "I am %1$@.", (self.sex == "M") ? "Male" : "Female"),
            String(format: "My name is %1$@.", self.name),
        ]

        var result = "Hello."
        for index in self.order {
            result += " " + descriptions[index]
        }

        return result
    }
}

var bob = Person()
bob.setName("Bob")
bob.setAge(27)
bob.setSex("M")
print(bob.hello())

bob = Person()
bob.setAge(27)
bob.setSex("M")
bob.setName("Bob")
print(bob.hello())

var alice = Person()
alice.setName("Alice")
alice.setSex("F")
print(alice.hello())

var batman = Person()
batman.setName("Batman")
print(batman.hello())
