/*

Introduction

Ordinal numbers are used to tell the position of something in a list. Unlike regular numbers, they have a special suffix added to the end of them.

Task

Your task is to write the ordinal(number, brief) function. number will be an integer. You need to find the ordinal suffix of said number.

brief is an optional parameter and defaults to false. When using brief notation, nd and rd use d instead. All others are the same.

ordinal(number, brief) should return a string containing those two characters (or one character) that would be tagged onto the end of the number.

The last two digits determine the ordinal suffix.

Notation for general notation

0  1  2  3  4  5  6  7  8  9
th st nd rd th th th th th th
Notation for brief notation

0  1  2  3  4  5  6  7  8  9
th st d  d th th th th th th
However, when the last two digits of the number are 11, 12, or 13, th is used instead of st,nd,rd respectively.

Examples

*General
1 - 1st
2 - 2nd
3 - 3rd
5 - 5th
11- 11th
149 - 149th
903 - 903rd
*Brief
1 - 1st
2 - 2d
3 - 3d
5 - 5th
11- 11th
149 - 149th
903 - 903d
Notes

Numbers might be passed in replacement of booleans, so false may be passed in as 0 and true may be passed in as 1.

*/

fn main() {
    assert_eq!(ordinal(1, false), "st");
    assert_eq!(ordinal(2, false), "nd");
    assert_eq!(ordinal(3, false), "rd");
    assert_eq!(ordinal(5, false), "th");
    assert_eq!(ordinal(11, false), "th");
    assert_eq!(ordinal(20, false), "th");
    assert_eq!(ordinal(52, false), "nd");
    assert_eq!(ordinal(111, false), "th");
    assert_eq!(ordinal(121, false), "st");
    assert_eq!(ordinal(149, false), "th");
    assert_eq!(ordinal(903, false), "rd");

    assert_eq!(ordinal(1, true), "st");
    assert_eq!(ordinal(2, true), "d");
    assert_eq!(ordinal(3, true), "d");
    assert_eq!(ordinal(5, true), "th");
    assert_eq!(ordinal(11, true), "th");
    assert_eq!(ordinal(20, true), "th");
    assert_eq!(ordinal(52, true), "d");
    assert_eq!(ordinal(111, true), "th");
    assert_eq!(ordinal(121, true), "st");
    assert_eq!(ordinal(149, true), "th");
    assert_eq!(ordinal(903, true), "d");
    assert_eq!(ordinal(149, true), "th");
    assert_eq!(ordinal(903, true), "d");
}

fn ordinal(number: usize, brief: bool) -> &'static str {
    let tens = number % 100;
    let ones = number % 10;

    if tens > 10 && tens < 14 {
        return "th";
    }
    if ones == 1 {
        return "st";
    }
    if ones == 2 {
        if brief {
            return "d";
        }
        return "nd";
    }
    if ones == 3 {
        if brief {
            return "d";
        }
        return "rd";
    }
    return "th";
}
