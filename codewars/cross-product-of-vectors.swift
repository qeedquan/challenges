/*

Make a function called crossProduct that takes two 3 dimensional vectors (in the form of two arrays) and returns their cross product. You need to check if the passed arguments are of the expected format, otherwise throw the message: "Arguments are not 3D vectors!".

crossProduct([1,0,0],[0,1,0]) //should return [0,0,1]
crossProduct('gobbledigook', [1,1,1]) //should throw the string "Arguments are not 3D vectors!"

Your function should handle non integers.

More info on cross products: https://en.wikipedia.org/wiki/Cross_product

crossprod([1,0,0], [0,1,0], 3, 3)         /* should return [0,0,1] */
crossprod([1,2,3,4,5], [5,4,3,2,1], 5, 5) /* should return NULL */
crossprod([6,6,6], NULL, 3, 3)            /* should return NULL */
crossprod(NULL, NULL, 3, 3)               /* should return NULL */

*/

struct Vec3 {
    var x: Float64
    var y: Float64
    var z: Float64

    init(_ x: Float64, _ y: Float64, _ z: Float64) {
        self.x = x
        self.y = y
        self.z = z
    }
}

func cross(_ a: Vec3, _ b: Vec3) -> Vec3 {
    return Vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    )
}

print(cross(Vec3(1, 0, 0), Vec3(0, 1, 0)))
