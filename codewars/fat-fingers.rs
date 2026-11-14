/*

Freddy has a really fat left pinky finger, and every time Freddy tries to type an A, he accidentally hits the CapsLock key!

Given a string that Freddy wants to type, emulate the keyboard misses where each A supposedly pressed is replaced with CapsLock, and return the string that Freddy actually types. It doesn't matter if the A in the string is capitalized or not. When CapsLock is enabled, capitalization is reversed, but punctuation is not affected.

Examples:

"The quick brown fox jumps over the lazy dog."
-> "The quick brown fox jumps over the lZY DOG."

"The end of the institution, maintenance, and administration of government, is to secure the existence of the body politic, to protect it, and to furnish the individuals who compose it with the power of enjoying in safety and tranquillity their natural rights, and the blessings of life: and whenever these great objects are not obtained, the people have a right to alter the government, and to take measures necessary for their safety, prosperity and happiness."
-> "The end of the institution, mINTENnce, ND dministrTION OF GOVERNMENT, IS TO SECURE THE EXISTENCE OF THE BODY POLITIC, TO PROTECT IT, nd to furnish the individuLS WHO COMPOSE IT WITH THE POWER OF ENJOYING IN Sfety ND TRnquillity their nTURl rights, ND THE BLESSINGS OF LIFE: nd whenever these greT OBJECTS re not obtINED, THE PEOPLE Hve  RIGHT TO lter the government, ND TO Tke meSURES NECESSry for their sFETY, PROSPERITY nd hPPINESS."

"aAaaaaAaaaAAaAa"
-> ""

(Adapted from https://codegolf.stackexchange.com/questions/158132/no-a-just-caps-lock)

*/

fn main() {
    assert_eq!(
        fat_fingers("The quick brown fox jumps over the lazy dog."),
        "The quick brown fox jumps over the lZY DOG."
    );

    assert_eq!(
        fat_fingers("The end of the institution, maintenance, and administration of government, is to secure the existence of the body politic, to protect it, and to furnish the individuals who compose it with the power of enjoying in safety and tranquillity their natural rights, and the blessings of life: and whenever these great objects are not obtained, the people have a right to alter the government, and to take measures necessary for their safety, prosperity and happiness."),
            "The end of the institution, mINTENnce, ND dministrTION OF GOVERNMENT, IS TO SECURE THE EXISTENCE OF THE BODY POLITIC, TO PROTECT IT, nd to furnish the individuLS WHO COMPOSE IT WITH THE POWER OF ENJOYING IN Sfety ND TRnquillity their nTURl rights, ND THE BLESSINGS OF LIFE: nd whenever these greT OBJECTS re not obtINED, THE PEOPLE Hve  RIGHT TO lter the government, ND TO Tke meSURES NECESSry for their sFETY, PROSPERITY nd hPPINESS."
    );

    assert_eq!(fat_fingers("aAaaaaAaaaAAaAa"), "");
    assert_eq!(fat_fingers(""), "");
    assert_eq!(fat_fingers("a99&a6/<a}"), "99&6/<}");
    assert_eq!(
        fat_fingers("Freddy is pretty good with his fingers right now!"),
        "Freddy is pretty good with his fingers right now!"
    );
    assert_eq!(fat_fingers("abABaBabAb"), "BBbbB");
    assert_eq!(fat_fingers("Important messaGe!"), "ImportNT MESSGe!");
}

fn fat_fingers(input: &'static str) -> String {
    let mut result = String::new();
    let mut capslock = false;
    for character in input.chars() {
        let lower = character.to_ascii_lowercase();
        let upper = character.to_ascii_uppercase();
        if lower == 'a' {
            capslock = !capslock;
        } else if capslock {
            if character == upper {
                result.push(lower);
            } else {
                result.push(upper);
            }
        } else {
            result.push(character);
        }
    }
    result
}
