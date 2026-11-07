/*

Given a matrix represented as a list of string, such as

###.....
..###...
....###.
.....###
.....###
....###.
..###...
###.....

write a function

rotateClockwise(matrix)

that return its 90° clockwise rotation, for our example:

#......#
#......#
##....##
.#....#.
.##..##.
..####..
..####..
...##...

 /!\ You must return a rotated copy of matrix! (matrix must be the same before and after calling your function)
Note that the matrix isn't necessarily a square, though it's always a rectangle!
Please also note that the equality m == rotateClockwise(rotateClockwise(rotateClockwise(rotateClockwise(m)))); (360° clockwise rotation), is not always true because rotateClockwise(['']) => [] and rotateClockwise(['','','']) => [] (empty lines information is lost)

*/

func at(_ string: String, _ offset: Int) -> String {
    let index = string.index(string.startIndex, offsetBy: offset)
    return String(string[index])
}

func rot90(_ matrix: [String]) -> [String] {
    var rotated: [String] = []
    let length = matrix.count
    for row in 0..<length {
        var string = ""
        for column in (0...length - 1).reversed() {
            string += at(matrix[column], row)
        }
        rotated.append(string)
    }
    return rotated
}

func draw(_ matrix: [String]) {
    for string in matrix {
        print(string)
    }
}

draw(
    rot90([
        "###.....",
        "..###...",
        "....###.",
        ".....###",
        ".....###",
        "....###.",
        "..###...",
        "###.....",
    ])
)
