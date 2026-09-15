/*

Timmy & Sarah think they are in love, but around where they live, they will only know once they pick a flower each. If one of the flowers has an even number of petals and the other has an odd number of petals it means they are in love.

Write a function that will take the number of petals of each flower and return true if they are in love and false if they aren't.

*/

fn main() {
    assert_eq!(lovefunc(1, 2), true);
    assert_eq!(lovefunc(0, 3), true);
    assert_eq!(lovefunc(99, 198), true);
    assert_eq!(lovefunc(0, 0), false);
    assert_eq!(lovefunc(2, 2), false);
    assert_eq!(lovefunc(101, 101), false);
}

fn lovefunc(flower1: isize, flower2: isize) -> bool {
    ((flower1 - flower2).abs() % 2) == 1
}
