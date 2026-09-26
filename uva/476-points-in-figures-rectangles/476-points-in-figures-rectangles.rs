#[derive(Debug, Copy, Clone)]
struct Point {
    x: f64,
    y: f64,
}

#[derive(Debug, Copy, Clone)]
struct Rectangle {
    min: Point,
    max: Point,
}

impl Point {
    fn new(x: f64, y: f64) -> Point {
        Point { x: x, y: y }
    }

    fn inside(&self, r: Rectangle) -> bool {
        r.min.x <= self.x && self.x <= r.max.x && r.min.y <= self.y && self.y <= r.max.y
    }
}

impl Rectangle {
    fn new(x0: f64, y0: f64, x1: f64, y1: f64) -> Rectangle {
        Rectangle {
            min: Point {
                x: x0.min(x1),
                y: y0.min(y1),
            },
            max: Point {
                x: x0.max(x1),
                y: y0.max(y1),
            },
        }
    }
}

fn main() {
    solve(
        &[
            Rectangle::new(8.5, 17.0, 25.5, -8.5),
            Rectangle::new(0.0, 10.3, 5.5, 0.0),
            Rectangle::new(2.5, 12.5, 12.5, 2.5),
        ],
        &[
            Point::new(2.0, 2.0),
            Point::new(4.7, 5.3),
            Point::new(6.9, 11.2),
            Point::new(20.0, 20.0),
            Point::new(17.3, 3.2),
            Point::new(-5.2, -7.8),
        ],
    );
}

fn solve(rectangles: &[Rectangle], points: &[Point]) {
    for i in 0..points.len() {
        let mut matched = 0;
        for j in 0..rectangles.len() {
            if points[i].inside(rectangles[j]) {
                println!("Point {} is contained in figure {}", i + 1, j + 1);
                matched += 1;
            }
        }
        if matched == 0 {
            println!("Point {} is not contained in any figure", i + 1);
        }
    }
}
