/*

You will write a simple program that prints exactly 1 2 3 4 5 6 7 8 9 10 to STDOUT, Console, or your language's closest output method. No other visible output should be seen. Any other code executed must be back-end only.

This is answer-chaining, so the catch is that you must include the previous answer's source code in your code ("included code"), comments and all. I have started the first answer down below.

Included code must be an exact replica of the previous code, unchanged and whole. To keep this challenge fair, the included code must not be in a comment. No language may be used twice. You may use languages created after this contest, but it must not be made for this challenge specifically. Please do not use any libraries or frameworks made for this challenge specifically, either.

This is a popularity-contest, so most vote score wins! Please vote on creativeness of code inclusion, which means that if someone who puts included code in a string and throws it away should not score very high. To make sure everyone gets a chance, discourage answers that do not follow the rules. Also, if you give an answer, please do not downvote other answers if they do not deserve it.

Please use the following draft for your answer:

#Answer Number: (your number in the chain)
##Language: (programming language used, hyperlinked to official website of language or hyperlink to download compiler)

**Previous Answer:**
(prev answer language)
(link to prev answer)

code

Any additional info. Try it on web and an explanation are highly encouraged.

Bytes Added: (optional, just for my musings. how many bytes you added to previous person's code)

*/

fn main() {
    count(10);
}

fn count(n: isize) {
    for i in 1..n + 1 {
        print!("{i}");
        if i < n {
            print!(" ");
        }
    }
    println!();
}
