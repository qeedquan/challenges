/*

Write a function that returns the total surface area and volume of a box as an array: [area, volume]

*/

fn main() {
    assert_eq!(size(4, 2, 6), (88, 48));
    assert_eq!(size(10, 10, 10), (600, 1000));
    assert_eq!(size(4, 2, 6), (88, 48));
}

fn size(width: isize, height: isize, depth: isize) -> (isize, isize) {
    let area = 2 * ((width * height) + (width * depth) + (height * depth));
    let volume = width * height * depth;
    (area, volume)
}
