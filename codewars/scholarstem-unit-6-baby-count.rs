/*

A local birthing center is interested in names!

They have arrays of all the baby names they see each year, but the lists are sooo long! They don’t know how to calculate how many times one name is used.

Given an array of names and a specific name string, return the number of times that specific name appears in the array.

countName( ["Tom","Bob","Harry","Bob"] , "Bob") //should return 2, since "Bob" shows up 2 times in the array

*/

fn main() {
    assert_eq!(count_names(&vec!["Tom", "Bob", "Harry", "Bob"], "Bob"), 2);
}

fn count_names(names: &Vec<&'static str>, query: &'static str) -> usize {
    let mut count = 0;
    for &name in names {
        if name == query {
            count += 1;
        }
    }
    count
}
