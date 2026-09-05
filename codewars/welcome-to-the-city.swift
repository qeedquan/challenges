/*

Create a method that takes as input a name, city, and state to welcome a person. Note that name will be an array consisting of one or more values that should be joined together with one space between each, and the length of the name array in test cases will vary.

Example:

['John', 'Smith'], 'Phoenix', 'Arizona'
This example will return the string Hello, John Smith! Welcome to Phoenix, Arizona!

*/

import Foundation

func sayHello(_ name: [String], _ city: String, _ state: String) -> String {
    return "Hello, \(name[0]) \(name[1])! Welcome to \(city), \(state)!"
}

assert(sayHello(["John", "Smith"], "Phoenix", "Arizona") == "Hello, John Smith! Welcome to Phoenix, Arizona!")
