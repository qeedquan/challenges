/*

The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal representation being returned. Valid decimal values for RGB are 0 - 255. Any values that fall out of that range must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.

The following are examples of expected output values:

rgb(255, 255, 255) // returns FFFFFF
rgb(255, 255, 300) // returns FFFFFF
rgb(0,0,0) // returns 000000
rgb(148, 0, 211) // returns 9400D3

*/

func rgb(_ r: UInt32, _ g: UInt32, _ b: UInt32) -> UInt32 {
    let r = min(r, 255)
    let g = min(g, 255)
    let b = min(b, 255)
    return (r << 16) | (g << 8) | b
}

assert(rgb(255, 255, 255) == 0xFFFFFF)
assert(rgb(255, 255, 300) == 0xFFFFFF)
assert(rgb(0, 0, 0) == 0x000000)
assert(rgb(148, 0, 211) == 0x9400D3)
