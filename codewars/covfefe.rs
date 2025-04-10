/*

Covfefe
Your are given a string. You must replace any occurence of the sequence coverage by covfefe, however, if you don't find the word coverage in the string, you must add covfefe at the end of the string with a leading space.

For the languages where the string is not immutable (such as ruby), don't modify the given string, otherwise this will break the test cases.

*/

fn main() {
    println!("{}", covfefe("keke"));
    println!("{}", covfefe("coverage under coverage"));
}

fn covfefe(s: &'static str) -> String {
    let t = s.replace("coverage", "covfefe");
    if t == s {
        return t + " covfefe";
    }
    return t;
}
