/*

The Western Suburbs Croquet Club has two categories of membership, Senior and Open. They would like your help with an application form that will tell prospective members which category they will be placed.

To be a senior, a member must be at least 55 years old and have a handicap greater than 7. In this croquet club, handicaps range from -2 to +26; the better the player the lower the handicap.

Input
Input will consist of a list of pairs. Each pair contains information for a single potential member. Information consists of an integer for the person"s age and an integer for the person"s handicap.

Output
Output will consist of a list of string values (in Haskell: Open or Senior) stating whether the respective member is to be placed in the senior or open category.

Example
input =  [(18, 20), (45, 2), (61, 12), (37, 6), (21, 21), (78, 9)]
output = ["Open", "Open", "Senior", "Open", "Open", "Senior"]

*/

fn main() {
    assert_eq!(
        categorize(&vec![
            (18, 20),
            (45, 2),
            (61, 12),
            (37, 6),
            (21, 21),
            (78, 9)
        ]),
        vec!["Open", "Open", "Senior", "Open", "Open", "Senior"]
    );

    assert_eq!(
        categorize(&vec![(45, 12), (55, 21), (19, -2), (104, 20)]),
        vec!["Open", "Senior", "Open", "Senior"]
    );

    assert_eq!(
        categorize(&vec![(16, 23), (73, 1), (56, 20), (1, -1)]),
        vec!["Open", "Open", "Senior", "Open"],
    );
}

fn categorize(input: &Vec<(isize, isize)>) -> Vec<String> {
    let mut result = vec![];
    for value in input {
        if value.0 >= 55 && value.1 > 7 {
            result.push(format!("Senior"));
        } else {
            result.push(format!("Open"));
        }
    }
    result
}
