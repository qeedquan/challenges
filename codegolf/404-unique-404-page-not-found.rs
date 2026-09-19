/*

Inspired by a polyglot on the Stack Overflow 404 page:

https://cdn.sstatic.net/Sites/stackoverflow/img/polyglot-404.png

Goal
Your goal is simple, to create a polyglot that outputs the number 404, and then terminate, in as many languages as possible.

Restrictions
Here's the twist, there's a restriction to make it harder:

You have to write N programs and pick N languages in a particular order. the ith program needs to print 404 in the first i languages, but not in any language after the ith. This is to prevent very simple solutions from destroying competition

Scoring:
The first criterion for determining a winner is the number of languages the main program runs in.
The second criterion is byte count, where the programs with more languages have more importance for this criterion.
The third and final criterion is time of submission
Clarifications:
The source codes of the programs do not need to have any relation. They're run as separate programs. Any of the programs can output trailing and/or leading whitespace. THE PROGRAMS DO NOT HAVE TO BE SUBSEQUENCES OF EACH OTHER!

Thanks to @MartinEnder for a better explanation!

*/

macro_rules! v {
    () => {
        println!()
    };

    ($x: expr) => {{
        print!("{}", $x as char);
        $x
    }};
}

fn main() {
    v!(v!(52u8) - 4u8);
    v!();
}
