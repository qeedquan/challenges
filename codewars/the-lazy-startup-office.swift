/*

A startup office has an ongoing problem with its bin. Due to low budgets, they don't hire cleaners. As a result, the staff are left to voluntarily empty the bin. It has emerged that a voluntary system is not working and the bin is often overflowing. One staff member has suggested creating a rota system based upon the staff seating plan.

Create a function binRota that accepts a 2D array of names. The function will return a single array containing staff names in the order that they should empty the bin.

Adding to the problem, the office has some temporary staff. This means that the seating plan changes every month. Both staff members' names and the number of rows of seats may change. Ensure that the function binRota works when tested with these changes.

Notes:

All the rows will always be the same length as each other.
There will be no empty spaces in the seating plan.
There will be no empty arrays.
Each row will be at least one seat long.

An example seating plan is as follows:

http://i.imgur.com/aka6lh0l.png

Or as an array:

[ ["Stefan", "Raj",    "Marie"],
  ["Alexa",  "Amy",    "Edward"],
  ["Liz",    "Claire", "Juan"],
  ["Dee",    "Luke",   "Katie"] ]

The rota should start with Stefan and end with Dee, taking the left-right zigzag path as illustrated by the red line:

http://i.imgur.com/JKlcPKxl.jpg

As an output you would expect in this case:

["Stefan", "Raj", "Marie", "Edward", "Amy", "Alexa", "Liz", "Claire", "Juan", "Katie", "Luke", "Dee"])

*/

func binrota(_ arrays: [[String]]) -> [String] {
    var result: [String] = []
    var index = 0
    for array in arrays {
        if index == 0 {
            result += array
        } else {
            result += array.reversed()
        }
        index ^= 1
    }
    return result
}

assert(
    binrota([
        ["Stefan", "Raj", "Marie"],
        ["Alexa", "Amy", "Edward"],
        ["Liz", "Claire", "Juan"],
        ["Dee", "Luke", "Katie"],
    ]) == [
        "Stefan", "Raj", "Marie", "Edward", "Amy", "Alexa", "Liz", "Claire", "Juan", "Katie",
        "Luke", "Dee",
    ]
)

assert(binrota([["Bob", "Nora"], ["Ruby", "Carl"]]) == ["Bob", "Nora", "Carl", "Ruby"])

assert(binrota([["Billy"]]) == ["Billy"])
assert(binrota([["Billy", "Nancy"]]) == ["Billy", "Nancy"])
assert(
    binrota([
        ["Billy"],
        ["Megan"],
        ["Aki"],
        ["Arun"],
        ["Joy"],
    ]) == ["Billy", "Megan", "Aki", "Arun", "Joy"]
)

assert(
    binrota([
        ["Sam", "Nina", "Tim", "Helen", "Gurpreet", "Edward", "Holly", "Eliza"],
        ["Billy", "Megan", "Aki", "Arun", "Joy", "Anish", "Lee", "Maryan"],
        ["Nick", "Josh", "Pete", "Kavita", "Daisy", "Francesca", "Alfie", "Macy"],
    ]) == [
        "Sam", "Nina", "Tim", "Helen", "Gurpreet", "Edward", "Holly", "Eliza", "Maryan", "Lee",
        "Anish", "Joy", "Arun", "Aki", "Megan", "Billy", "Nick", "Josh", "Pete", "Kavita", "Daisy",
        "Francesca", "Alfie", "Macy",
    ]
)

assert(
    binrota([
        ["Stefan", "Raj", "Marie"],
        ["Alexa", "Amy", "Edward"],
        ["Liz", "Claire", "Juan"],
        ["Dee", "Luke", "Elle"],
    ]) == [
        "Stefan", "Raj", "Marie", "Edward", "Amy", "Alexa", "Liz", "Claire", "Juan", "Elle", "Luke",
        "Dee",
    ]
)
