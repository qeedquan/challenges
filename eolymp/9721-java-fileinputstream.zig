// Input is a data file. Read bytes and find their sum.
//
// Input
// Sequence of bytes.
//
// Output
// Print the sum of bytes.
//
// Examples
//
// Input #1
// 1 2 3
//
// Answer #1
// 6
//
// Note
// Sample input has three bytes with ASCII codes 1, 2 and 3. Their sum is 6.

const std = @import("std");

pub fn main() !void {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    defer _ = gpa.deinit();
    const allocator = gpa.allocator();

    const args = try std.process.argsAlloc(allocator);
    defer std.process.argsFree(allocator, args);

    if (args.len < 2) {
        std.debug.print("usage: {s} <file>\n", .{args[0]});
        std.process.exit(1);
    }
    const path = args[1];

    const file = try std.fs.cwd().openFile(path, .{});
    defer file.close();

    const buffer = try file.readToEndAlloc(allocator, std.math.maxInt(usize));
    defer allocator.free(buffer);

    var sum: u1024 = 0;
    for (buffer) |byte| {
        sum += byte;
    }

    const stdout = std.io.getStdOut().writer();
    try stdout.print("{d}\n", .{sum});
}
