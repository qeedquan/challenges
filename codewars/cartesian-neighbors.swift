/*

A Cartesian coordinate system is a coordinate system that specifies each point uniquely in a plane by a pair of numerical coordinates, which are the signed distances to the point from two fixed perpendicular directed lines, measured in the same unit of length.

The сoordinates of a point in the grid are written as (x,y). Each point in a coordinate system has eight neighboring points. Provided that the grid step = 1.

It is necessary to write a function that takes a coordinate on the x-axis and y-axis and returns a list of all the neighboring points. Points inside your returned list need not be sorted (any order is valid).

For Example:

cartesianNeighbor(2,2) -> [[1,1],[1,2],[1,3],[2,1],[2,3],[3,1],[3,2],[3,3]]
cartesianNeighbor(5,7) -> [[6,7],[6,6],[6,8],[4,7],[4,6],[4,8],[5,6],[5,8]]

*/

func neighbors(_ x: Int, _ y: Int) -> [[Int]] {
    var r = [[Int]]()
    for X in x - 1...x + 1 {
        for Y in y - 1...y + 1 {
            if x != X || y != Y {
                r.append([X, Y])
            }
        }
    }
    return r
}

print(neighbors(2, 2))
print(neighbors(5, 7))
