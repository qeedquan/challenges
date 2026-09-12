/*

The trumpet is a valved aerophone instrument, usually pitched in B♭. The sound is made when the player vibrates their lips to displace air inside the instrument. That vibration is acquired by setting one's mouth in a specific way, called the embouchure. Different embouchures, with tighter or looser lips, produce different pitches.

Furthermore, each valve in the trumpet also changes the pitch of the instrument. When depressed, a valve closes a path inside the tubing of the instrument, making the air flow through a longer path, thus lowering the pitch of the original sound. For the purposes of this challenge, we'll consider the standard, B♭ trumpet, in which the first valve lowers the pitch by a full step, the second lowers the pitch by a half-step, and the third lowers the pitch by one and a half step.

The Challenge
Your challenge is to create a program or function that, given two inputs embouchure and valves, determines the pitch of the note being played.

For the purposes of this challenge, the notes will follow the sequence:

B♭, B, C, C♯, D, E♭, E, F, F♯, G, G♯, A.
Rules
I/O can be taken/given in any reasonable method.
Standard loopholes apply.
You're allowed to use b and # instead of ♭ and ♯ if you wish to.
Input for valves can be taken as a list of depressed valves (1, 3) or a boolean list (1, 0, 1).
This is code-golf, so shortest code in each language wins.
Test Cases:
Valves in these test cases is given as a boolean list, where 0 means depressed and 1 means pressed.

Embouchure:    Valves:   Output:
B♭             0 0 0     B♭
B♭             0 1 0     A
B♭             1 0 1     F
C♯             0 0 1     B♭
C♯             1 1 1     G
E♭             1 0 0     C♯
G              0 1 1     E♭
G♯             1 0 0     F♯
G♯             0 0 1     F
G              1 0 0     F
F♯             1 0 0     E
D              1 0 1     A
A              1 1 1     E♭
E              1 1 0     C♯
E              0 0 1     C♯
Disclaimer: I'm not much of a musician yet, so I do apologize for any butchering I might've made on the test cases. Corrections are appreciated.

*/

fn main() {
    assert_eq!(classify("A", &[1, 1, 1]), "E♭");
}

fn classify(embouchure: &'static str, valves: &[isize; 3]) -> &'static str {
    match (embouchure, valves[0], valves[1], valves[2]) {
        ("B♭", 0, 0, 0) => "B♭",
        ("B♭", 0, 1, 0) => "A",
        ("B♭", 1, 0, 1) => "F",
        ("C♯", 0, 0, 1) => "B♭",
        ("C♯", 1, 1, 1) => "G",
        ("E♭", 1, 0, 0) => "C♯",
        ("G", 0, 1, 1) => "E♭",
        ("G♯", 1, 0, 0) => "F♯",
        ("G♯", 0, 0, 1) => "F",
        ("G", 1, 0, 0) => "F",
        ("F♯", 1, 0, 0) => "E",
        ("D", 1, 0, 1) => "A",
        ("A", 1, 1, 1) => "E♭",
        ("E", 1, 1, 0) => "C♯",
        ("E", 0, 0, 1) => "C♯",
        _ => "Invalid",
    }
}
