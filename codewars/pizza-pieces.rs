/*

In her trip to Italy, Elizabeth Gilbert made it her duty to eat perfect pizza. One day she ordered one for dinner, and then some Italian friends appeared at her room. The problem is that there were many people who ask for a piece of pizza at that moment, and she had a knife that only cuts straight.

Given the number of pizza cuts, find the maximum amount of pieces of pizza that you can get (not necessarily of equal size). If the number of cuts is negative, return -1 instead (or Nothing in Haskell).

*/

fn main() {
    assert_eq!(-1, maxpizza(-2));
    assert_eq!(1, maxpizza(0));
    assert_eq!(7, maxpizza(3));
    assert_eq!(11, maxpizza(4));
    assert_eq!(16, maxpizza(5));
    assert_eq!(22, maxpizza(6));
}

fn maxpizza(cuts: isize) -> isize {
    if cuts < 0 {
        -1
    } else {
        ((cuts * cuts) + cuts + 2) / 2
    }
}
