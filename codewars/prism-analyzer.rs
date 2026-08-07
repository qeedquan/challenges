/*

For an N-sided prism:

Vertices (V): The total number of vertices.

Edges (E): The total number of edges.

Faces (F): The total number of faces.

Base sides (B): The number of sides of the base of the prism.

Given the sum s = V + E + F return the tuple (V, E, F, B).

Constraints:

1. The number of sides of the base B is an integer greater than or equal to 3.

2. The sum s is an integer in the range 4 ≤ 𝑠 ≤ 1000

*/

fn main() {
    assert_eq!(prism(26), (8, 12, 6, 4));
    assert_eq!(prism(44), (14, 21, 9, 7));
    assert_eq!(prism(74), (24, 36, 14, 12));
}

/*

https://www.quora.com/How-many-vertices-faces-and-edges-does-a-prism-have
https://byjus.com/maths/eulers-formula-for-polyhedra/

A prism whose bases are n-gons have n+2 faces, 3n edges, and 2n vertices.

*/

fn prism(s: isize) -> (isize, isize, isize, isize) {
    for b in 3..s {
        let v = 2 * b;
        let e = 3 * b;
        let f = b + 2;
        if v + e + f == s {
            return (v, e, f, b);
        }
    }
    (-1, -1, -1, -1)
}
