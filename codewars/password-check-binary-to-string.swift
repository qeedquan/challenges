/*

A wealthy client has forgotten the password to his business website, but he has a list of possible passwords. His previous developer has left a file on the server with the name password.txt. You open the file and realize it's in binary format.

Write a script that takes an array of possible passwords and a string of binary representing the possible password. Convert the binary to a string and compare to the password array. If the password is found, return the password string, else return false;

decodePass(['password123', 'admin', 'admin1'], '01110000 01100001 01110011 01110011 01110111 01101111 01110010 01100100 00110001 00110010 00110011');    => 'password123'
decodePass(['password321', 'admin', 'admin1'], '01110000 01100001 01110011 01110011 01110111 01101111 01110010 01100100 00110001 00110010 00110011');    => false
decodePass(['password456', 'pass1', 'test12'], '01110000 01100001 01110011 01110011 01110111 01101111 01110010 01100100 00110001 00110010 00110011');    => false

*/

import Foundation

func decode(_ passwords: [String], _ bitstring: String) -> (String, Bool) {
    var password = ""
    for binary in bitstring.components(separatedBy: " ") {
        if let number = Int(binary, radix: 2) {
            if let character = UnicodeScalar(number) {
                password += String(character)
            }
        }
    }
    if !passwords.contains(password) {
        return ("", false)
    }
    return (password, true)
}

assert(decode(["password123", "admin", "admin1"], "01110000 01100001 01110011 01110011 01110111 01101111 01110010 01100100 00110001 00110010 00110011") == ("password123", true))
assert(decode(["password321", "admin", "admin1"], "01110000 01100001 01110011 01110011 01110111 01101111 01110010 01100100 00110001 00110010 00110011") == ("", false))
assert(decode(["password456", "pass1", "test12"], "01110000 01100001 01110011 01110011 01110111 01101111 01110010 01100100 00110001 00110010 00110011") == ("", false))
