/*

Kate likes to count words in text blocks. By words she means continuous sequences of English alphabetic characters (from a to z ). Here are examples:

Hello there, little user5453 374 ())$. I’d been using my sphere as a stool. Slow-moving target 839342 was hit by OMGd-63 or K4mp. contains "words" ['Hello', 'there', 'little', 'user', 'I', 'd', 'been', 'using', 'my','sphere', 'as', 'a', 'stool', 'Slow', 'moving', 'target', 'was', 'hit', 'by', 'OMGd', 'or', 'K', 'mp']

Kate doesn't like some of words and doesn't count them. Words to be excluded are "a", "the", "on", "at", "of", "upon", "in" and "as", case-insensitive.

Today Kate's too lazy and have decided to teach her computer to count "words" for her.

Example Input 1
Hello there, little user5453 374 ())$.

Example Output 1
4

Example Input 2
I’d been using my sphere as a stool. I traced counterclockwise circles on it with my fingertips and it shrank until I could palm it. My bolt had shifted while I’d been sitting. I pulled it up and yanked the pleats straight as I careered around tables, chairs, globes, and slow-moving fraas. I passed under a stone arch into the Scriptorium. The place smelled richly of ink. Maybe it was because an ancient fraa and his two fids were copying out books there. But I wondered how long it would take to stop smelling that way if no one ever used it at all; a lot of ink had been spent there, and the wet smell of it must be deep into everything.

Example Output 2
112

*/

import Foundation

func countWords(_ string: String) -> Int {
    let excluded = ["a", "the", "on", "at", "of", "upon", "in", "as"]
    var count = 0
    var word = ""
    for symbol in string {
        let symbol = symbol.lowercased()
        if "a" <= symbol && symbol <= "z" {
            word += String(symbol)
        } else {
            if word.count > 0 && !excluded.contains(word) {
                count += 1
            }
            word = ""
        }
    }
    if word.count > 0 && !excluded.contains(word) {
        count += 1
    }
    return count
}

assert(countWords("Hello there, little user5453 374 ())$. I’d been using my sphere as a stool. Slow-moving target 839342 was hit by OMGd-63 or K4mp.") == 21)

assert(countWords("Hello there, little user5453 374 ())$.") == 4)
assert(countWords("I’d been using my sphere as a stool. I traced counterclockwise circles on it with my fingertips and it shrank until I could palm it. My bolt had shifted while I’d been sitting. I pulled it up and yanked the pleats straight as I careered around tables, chairs, globes, and slow-moving fraas. I passed under a stone arch into the Scriptorium. The place smelled richly of ink. Maybe it was because an ancient fraa and his two fids were copying out books there. But I wondered how long it would take to stop smelling that way if no one ever used it at all; a lot of ink had been spent there, and the wet smell of it must be deep into everything.") == 112)

assert(countWords("Hello") == 1)
assert(countWords("Hello, World!") == 2)
assert(countWords("Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.") == 19)
assert(countWords("") == 0)
assert(countWords("With! Symbol@ #Around! (Every) %Word$") == 5)
assert(countWords("Dear   Victoria, I love  to press   space button.") == 8)

assert(countWords(" Arthur ") == 1)
assert(countWords(" David") == 1)
assert(countWords("Nelson ") == 1)
assert(countWords("  Hello Gomer  ") == 2)
assert(countWords("  Hello     Bart  ") == 2)

assert(countWords(" Hello World ") == 2)
assert(countWords("Hello World") == 2)
