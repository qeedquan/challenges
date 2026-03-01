/*

Caesar Ciphers are one of the most basic forms of encryption. It consists of a message and a key, and it shifts the letters of the message for the value of the key.

Read more about it here: https://en.wikipedia.org/wiki/Caesar_cipher

Your task
Your task is to create a function encryptor that takes 2 arguments - key and message - and returns the encrypted message.

Make sure to only shift letters, and be sure to keep the cases of the letters the same. All punctuation, numbers, spaces, and so on should remain the same.

Also be aware of keys greater than 26 and less than -26. There's only 26 letters in the alphabet!

Examples
A message 'Caesar Cipher' and a key of 1 returns 'Dbftbs Djqifs'.

A message 'Caesar Cipher' and a key of -1 returns 'Bzdrzq Bhogdq'.

*/

import Foundation

func mod(_ x: Int, _ m: Int) -> Int {
    var x = x % m
    if x < 0 {
        x += m
    }
    return x
}

func caesar(_ message: String, _ shift: Int) -> String {
    var output = ""
    for character in message {
        var symbol = character
        if "a" <= character && character <= "z" {
            let value = mod(Int(character.asciiValue!) - 97 + shift, 26) + 97
            symbol = Character(UnicodeScalar(value)!)
        } else if "A" <= character && character <= "Z" {
            let value = mod(Int(character.asciiValue!) - 65 + shift, 26) + 65
            symbol = Character(UnicodeScalar(value)!)
        }
        output += String(symbol)
    }
    return output
}

assert(caesar("Caesar Cipher", 1) == "Dbftbs Djqifs")
assert(caesar("Caesar Cipher", -1) == "Bzdrzq Bhogdq")
