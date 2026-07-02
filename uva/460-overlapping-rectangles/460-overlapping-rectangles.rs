use std::cmp::*;

#[derive(PartialEq, Debug)]
struct Rect {
    xll: isize,
    yll: isize,
    xur: isize,
    yur: isize,
}

impl Rect {
    fn new(xll: isize, yll: isize, xur: isize, yur: isize) -> Rect {
        Rect {
            xll: xll,
            yll: yll,
            xur: xur,
            yur: yur,
        }
    }
}

fn main() {
    assert_eq!(
        overlap(Rect::new(0, 20, 100, 120), Rect::new(80, 0, 500, 60)),
        Rect::new(80, 20, 100, 60)
    );
}

fn overlap(r1: Rect, r2: Rect) -> Rect {
    let l = max(r1.xll, r2.xll);
    let r = min(r1.xur, r2.xur);
    let b = max(r1.yll, r2.yll);
    let t = min(r1.yur, r2.yur);
    if l >= r || t <= b {
        return Rect::new(-1, -1, -1, -1);
    }
    return Rect::new(l, b, r, t);
}
