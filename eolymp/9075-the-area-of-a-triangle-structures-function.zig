//
// Create a function:
//
// double solve(point a, point b, point c)
//
// This function takes as input the coordinates of points a, b, and c, which are instances of the following structure:
//
// struct point
// {
//   int x;
//   int y;
// };
//
// The function should return the area of the triangle formed by these three points. Implement this in C++.

const std = @import("std");

const Point = struct {
    x: f64,
    y: f64,
};

pub fn main() void {
    std.debug.print("{d}\n", .{solve(Point{ .x = 1, .y = 6 }, Point{ .x = 4, .y = 3 }, Point{ .x = 1, .y = 2 })});
    std.debug.print("{d}\n", .{solve(Point{ .x = 34, .y = 2 }, Point{ .x = 68, .y = 34 }, Point{ .x = 10, .y = 220 })});
}

pub fn solve(a: Point, b: Point, c: Point) f64 {
    return 0.5 * @abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}
