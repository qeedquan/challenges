/*

You have an 8-wind compass, like this:

https://image.shutterstock.com/image-vector/compass-rose-eight-abbreviated-initials-260nw-1453270079.jpg

You receive the direction you are facing (one of the 8 directions: N, NE, E, SE, S, SW, W, NW) and a certain degree to turn (a multiple of 45, between -1080 and 1080); positive means clockwise, and negative means counter-clockwise.

Return the direction you will face after the turn.

Examples
"S",  180  -->  "N"
"SE", -45  -->  "E"
"W",  495  -->  "NE"

*/

import Foundation

func mod(_ x: Int, _ m: Int) -> Int {
    var x = x % m
    if x < 0 {
        x += m
    }
    return x
}

func direction(_ facing: String, _ turn: Int) -> String {
    let POSITION = [
        "N": 0,
        "NE": 45,
        "E": 90,
        "SE": 135,
        "S": 180,
        "SW": 225,
        "W": 270,
        "NW": 315,
    ]
    let DEGREE = [
        0: "N",
        45: "NE",
        90: "E",
        135: "SE",
        180: "S",
        225: "SW",
        270: "W",
        315: "NW",
    ]

    var angle = POSITION[facing] ?? -1
    if angle < 0 {
        return "N/A"
    }

    angle = mod(angle + turn, 360)
    return DEGREE[angle] ?? "N/A"
}

assert(direction("S", 180) == "N")
assert(direction("SE", -45) == "E")
assert(direction("W", 495) == "NE")
assert(direction("N", -450) == "W")
