#!/usr/bin/env python3

r"""

Given a list of 2d (x, y) coordinates, determine how many unit squares (edge length 1 unit) can be formed using the coordinates.

Input will be an array of 0 or more pairs of coordinates:
e.g. in JavaScript: numofsq([[0,0], [1,0], [1,1], [0,1]])
No duplicate coordinates in input
Input order will be random (random 2d coordinates).
Coordinate form: [x-coordinate, y-coordinate] (duh)
Order of coordinates: [0,0], [1,0], [1,1], [0,1] and [0,0], [0,1], [1,1], [1,0] denote the same unit square (to be counted just once)
Coordinates can be negative or positive integers (duh)
Function will return just the number of unit squares possible, 0 or more.
Test cases:

Input Coordinates Pairs                                               Expected Output
[0,0], [0,1], [1,1], [1,0], [0,2], [1,2]                              2
[0,0], [0,1], [1,1], [1,0], [0,2], [1,2], [2,2], [2,1]                3
[0,0], [0,1], [1,1], [1,0], [0,2], [1,2], [2,2], [2,1], [2,0]         4
[0,0], [0,1], [1,1], [1,0], [0,2], [1,2], [2,2], [2,1], [2,0], [9,9]  4
Spoiler Alert: Solution stuff here-onwards [JS]
Non-Golfed, quick and dirty, brute-force approach (included to provide some directions).

//cartesian distance function
function dist(a, b) {
    if (b === undefined) {
        b = [0, 0];
    }
    return Math.sqrt((b[0] - a[0]) * (b[0] - a[0]) + (b[1] - a[1]) * (b[1] - a[1]));
}
//accepts 4 coordinate pairs and checks if they form a unit square
//this could be optimized by matching x,y coordinates of the 4 coordinates
function isUnitSquare(a) {
    var r = a.slice(),
        d = [],
        c = [],
        i,
        j = 0,
        counter = 0;

    for (i = 1; i < 4; i++) {
        if (dist(a[0], a[i]) === 1) {
            d.push(a[i]);
            r[i] = undefined;
            counter++;
        }
    }
    r[0] = undefined;
    c = d.concat(r.filter(function(a) {return undefined !== a}));

    if (dist(c[0], c[1]) === 1) {j++};
    if (dist(c[1], c[2]) === 1) {j++};
    if (dist(c[2], c[0]) === 1) {j++};
    return counter === 2 && j === 2;
}
//a powerset function (from rosetta code)
//however, we will need only "sets of 4 coordinates"
//and not all possible length combinations (sets of 3 coords or
//sets of 5 coords not required). Also, order doesn't matter.
function powerset(ary) {
    var ps = [[]];
    for (var i=0; i < ary.length; i++) {
        for (var j = 0, len = ps.length; j < len; j++) {
            ps.push(ps[j].concat(ary[i]));
        }
    }
    return ps;
}

//so to capture only sets of 4 coordinates, we do
var res = powerset([[0,0], [0,1], [1,1], [1,0], [0,2], [1,2], [2,2], [2,1], [2,0]])
          .filter(function (a) {return a.length === 8;});

//and a little bit of hoopla to have a nice set of sets of 4 coordinates.
//(Dizzy yet? Wait for the generalized, 3D, cube of any edge length version ;))
var squareQuads = res.map(function(ary) {
    return ary.join().match(/\d\,\d/g)
       .map(function(e) {
           return [+e.split(',')[0], +e.split(',')[1]];
        });
});
//Finally, the last bit
var howManyUnitSquares = 0;
squareQuads.map(function(quad) {
    if (isUnitSquare(quad)) {
        howManyUnitSquares++;
    }
});

console.log(howManyUnitSquares);
//Cleaning up and putting those in-line stuff into a function
function howManySquares(r) { //r = [[x,y], [x,y], [x,y], [x,y], ......];
    var res = powerset(r)
          .filter(function (a) {return a.length === 8;});
    var squareQuads = res.map(function(ary) {
        return ary.join().match(/\d\,\d/g)
               .map(function(e) {
                   return [+e.split(',')[0], +e.split(',')[1]];
                });
    });

    var answer = 0;
    squareQuads.map(function(quad) {
        if (isUnitSquare(quad)) {
            answer++;
        }
    });

    return answer;
}

"""

# ported from @Daniel Lubarov solution
def solve(p):
    s = set()
    for x, y in p:
        s.add((x, y))

    r = 0
    for x, y in s:
        if {(x + 1,y), (x, y + 1), (x + 1, y + 1)} < s:
            r += 1
    return r

def main():
  assert(solve([[0, 0], [0, 1], [1, 1], [1, 0], [0, 2], [1, 2]]) == 2)
  assert(solve([[0, 0], [0, 1], [1, 1], [1, 0], [0, 2], [1, 2], [2, 2], [2, 1]]) == 3)
  assert(solve([[0, 0], [0, 1], [1, 1], [1, 0], [0, 2], [1, 2], [2, 2], [2, 1], [2, 0]]) == 4)
  assert(solve([[0, 0], [0, 1], [1, 1], [1, 0], [0, 2], [1, 2], [2, 2], [2, 1], [2, 0], [9, 9]]) == 4)

main()
