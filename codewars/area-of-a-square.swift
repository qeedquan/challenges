/*

Complete the function that calculates the area of the red square, when the length of the circular arc A is given as the input. Return the result rounded to two decimals.

https://imgur.com/nJrae8n

Graph

Note: use the π value provided in your language (Math::PI, M_PI, math.pi, etc)

*/

func squarearea(_ A: Double) -> Double {
    let R = (A * 2) / Double.pi
    return R * R
}

print(squarearea(2))
print(squarearea(0))
print(squarearea(14.05))
print(squarearea(100))
