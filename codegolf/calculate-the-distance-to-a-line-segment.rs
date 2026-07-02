/*

The Challenge
Given two vertexes and a point calculate the distance to the line segment defined by those points.

This can be calculated with the following psudocode

def dist(point, v1, v2):
    direction       := normalize(v2-v1)
    distance        := length(v2-v1)
    difference      := point - v1
    pointProgress   := dot(difference, direction)
    if (pointProgress <= 0):
        return magnitude(point - v1)
    else if (pointProgress >= distance):
        return magnitude(point - v2)
    else
        normal := normalize(difference - (direction * pointProgress))
        return dot(difference, normal)
Answers may support either 2 dimensions, or 3, and may optionally support any number of higher or lower dimensions.

As it does not substantially change the difficulty of the challenge, answers need only be accurate to the whole number, and I/O can be assumed to fit within the [0,127] range. This is to allow more languages to focus only on the challenge spec, rather than implementing floating points.

Test Cases
1: point=[005,005], v1=[000,000] v2=[010,000] :: distance=005.00 # Horizontal
2: point=[005,005], v1=[010,000] v2=[010,010] :: distance=005.00 # Vertical
3: point=[000,010], v1=[000,000] v2=[010,010] :: distance=007.07 # Diagonal
4: point=[010,000], v1=[000,000] v2=[010,010] :: distance=007.07 # Diagonal, Clockwise
5: point=[000,000], v1=[002,002] v2=[004,008] :: distance=002.83 # Not near the normal
6: point=[000,002], v1=[002,002] v2=[002,002] :: distance=002.00 # Zero length segment

Rules
Standard IO Applies
Standard Loopholes Apply
This is code-golf so fewest bytes wins!

*/

use std::ops::*;

#[derive(Copy, Clone)]
struct Vec2 {
    x: f64,
    y: f64,
}

impl Sub<Vec2> for Vec2 {
    type Output = Self;

    fn sub(self, other: Vec2) -> Vec2 {
        Vec2 {
            x: self.x - other.x,
            y: self.y - other.y,
        }
    }
}

impl Mul<f64> for Vec2 {
    type Output = Self;

    fn mul(self, scale: f64) -> Vec2 {
        Vec2 {
            x: self.x * scale,
            y: self.y * scale,
        }
    }
}

fn main() {
    println!(
        "{:?}",
        distance(
            Vec2 { x: 5.0, y: 5.0 },
            Vec2 { x: 0.0, y: 0.0 },
            Vec2 { x: 10.0, y: 0.0 },
        )
    );

    println!(
        "{:?}",
        distance(
            Vec2 { x: 5.0, y: 5.0 },
            Vec2 { x: 10.0, y: 0.0 },
            Vec2 { x: 10.0, y: 10.0 },
        )
    );

    println!(
        "{:?}",
        distance(
            Vec2 { x: 0.0, y: 10.0 },
            Vec2 { x: 0.0, y: 0.0 },
            Vec2 { x: 10.0, y: 10.0 },
        )
    );

    println!(
        "{:?}",
        distance(
            Vec2 { x: 10.0, y: 0.0 },
            Vec2 { x: 0.0, y: 0.0 },
            Vec2 { x: 10.0, y: 10.0 },
        )
    );

    println!(
        "{:?}",
        distance(
            Vec2 { x: 0.0, y: 0.0 },
            Vec2 { x: 2.0, y: 2.0 },
            Vec2 { x: 4.0, y: 8.0 },
        )
    );

    println!(
        "{:?}",
        distance(
            Vec2 { x: 0.0, y: 2.0 },
            Vec2 { x: 2.0, y: 2.0 },
            Vec2 { x: 2.0, y: 2.0 },
        )
    );
}

fn distance(point: Vec2, v1: Vec2, v2: Vec2) -> f64 {
    let direction = normalize(v2 - v1);
    let distance = length(v2 - v1);
    let difference = point - v1;
    let point_progress = dot(difference, direction);

    if point_progress <= 0.0 {
        length(point - v1)
    } else if point_progress >= distance {
        length(point - v2)
    } else {
        let normal = normalize(difference - (direction * point_progress));
        dot(difference, normal)
    }
}

fn dot(p: Vec2, q: Vec2) -> f64 {
    (p.x * q.x) + (p.y * q.y)
}

fn length(p: Vec2) -> f64 {
    ((p.x * p.x) + (p.y * p.y)).sqrt()
}

fn normalize(p: Vec2) -> Vec2 {
    let l = length(p);
    if l == 0.0 {
        Vec2 { x: 0.0, y: 0.0 }
    } else {
        Vec2 {
            x: p.x / l,
            y: p.y / l,
        }
    }
}
