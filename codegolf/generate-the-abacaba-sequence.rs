/*

This challenge is about printing the abacaba sequence of a specific depth.

Here is a diagram of the first 5 sequences (a(N) is the abacaba sequence of depth N, upper/lowercase is just to show the pattern, this is not needed in the output of your program):

a(0) = A
a(1) = aBa
a(2) = abaCaba
a(3) = abacabaDabacaba
a(4) = abacabadabacabaEabacabadabacaba
...
a(25) = abacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabagabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabahabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabagabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabaiabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabagabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabahabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabagabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabajabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabagabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabahabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabagabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabaia...

As you can probably tell, the n'th abacaba sequence is the last one with the n'th letter and itself again added to it.
(a(n) = a(n - 1) + letter(n) + a(n - 1))

Your task is to make a program or function that takes an integer and prints the abacaba sequence of that depth.
The output has to be correct at least for values up to and including 15.

*/

fn main() {
    assert_eq!(a(0), "a");
    assert_eq!(a(1), "aba");
    assert_eq!(a(2), "abacaba");
    assert_eq!(a(3), "abacabadabacaba");
    assert_eq!(a(4), "abacabadabacabaeabacabadabacaba");
    assert_eq!(a(25).starts_with("abacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabagabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabahabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabagabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabaiabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabagabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabahabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabagabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabajabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabagabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabahabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabagabacabadabacabaeabacabadabacabafabacabadabacabaeabacabadabacabaia"), true);
}

fn a(n: usize) -> String {
    if n == 0 {
        return format!("{}", letter(n));
    }

    let string = a(n - 1);
    return format!("{}{}{}", string, letter(n), string);
}

fn letter(n: usize) -> char {
    let c = 'a' as usize;
    let c = c + (n % 26);
    char::from_u32(c as u32).unwrap()
}
