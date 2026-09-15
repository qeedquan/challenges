/*

Problem
You are tasked with creating a program that performs emoji encryption on a given string of emojis. In this encryption scheme, each emoji is replaced by a unique character (from a to z). Your program should take an emoji string as input and output the corresponding encrypted string.

The mapping of emojis to characters is up to you and can vary each time the program is run. For example:

Input: 🌟🌟🌟🌺🌺🐘🎉🐘🍔
Output 1: aaabbcdce
Output 2: xxxiikbkg
Both outputs are valid.

Your task is to write a program that produces encrypted strings for given emoji inputs. Your program will be evaluated based on its average result value and size of code (in bytes).

Value of the Result
Each letter from a to z has a value from 0 to 25 in ascending order. ie.

a = 0
b = 1
c = 2
  .
  .
  .
y = 24
z = 25
The value of the result is calculated as the summation of the values of all characters in the resulting string. For example:

aaabbcdce
0 + 0 + 0 + 1 + 1 + 2 + 3 + 2 + 4 = 13
Scoring Criteria:
Run the program 10,000 times, each time generating a random 25-emoji string, and calculate the average value of the results. Your score will be determined by this average value in comparison with the size of the code.

The goal is to create a program that, on average, produces encrypted strings with the lowest possible value based on the emoji-to-character mapping chosen for each run (a run is considered converting 25 emojis to a string hence there will be 10,000 unique runs considered in your score)

Create and submit a program that generates encrypted strings as described above, and your score will be the average result value obtained from the 10,000 runs and multiply by the size of the code in bytes. A lower Score is better.

average value of results over 10,000 runs×size of code in bytes
LOWER SCORE IS BETTER

Notes:
Ignore decryption

This problem emphasizes randomness and the ability to produce low-value results on average, so figuring out which emoji has been repeated the most in the input and giving it the character a will improve the program's result.

Input restrictions
Input Emoji string will contain 25 emojis without any spaces.
There will only be 10 unique emojis in the Input at maximum.
The 10 valid emojis in the Input are 🗓🙏📗💻📇🚢🐉💘😪🎉
some example inputs:

Invalid input: 🗓🙏🚁🍿💻🍏💣📡📇📓🐉🙅🎗♿️👼⛷🔔💘5️⃣⏏📗🌑😪👒🚢 (it has more than 10 unique emojis)
               🗓🙏🚁🍿💻🍏 📡📇📓🐉🙅🎗♿️👼⛷  5️⃣⏏📗🌑😪👒🚢 (invalid for including spaces)

Valid input: 🗓🙏📗📗💻🗓📇🚢📇🗓🐉🗓🗓🗓📇🚢📇💘📗📗📗🗓😪📇🚢 ( Valid since it has only 9 unique emojis (<= 10) and no spaces)
Valid output to this Input: abccdaefeagaaaefehcccaief
example random Input generators
Python
import random

input_string = ''.join(random.choice("🗓🙏📗💻📇🚢🐉💘😪🎉") for _ in range(25))

print("Emoji String:", input_string)

*/

package main

import (
	"bytes"
	"fmt"
	"math/rand"
)

func main() {
	fmt.Println(encrypt(rand.Perm(26), "🌟🌟🌟🌺🌺🐘🎉🐘🍔"))
	fmt.Println(encrypt(rand.Perm(26), "🗓🙏📗📗💻🗓 📇🚢📇🗓 🐉🗓 🗓 🗓 📇🚢📇💘📗📗📗🗓 😪📇🚢"))
}

func encrypt(p []int, s string) string {
	w := new(bytes.Buffer)
	m := make(map[rune]int)
	c := 0
	for _, r := range s {
		if _, ok := m[r]; !ok {
			m[r], c = c, c+1
		}
		i := m[r]
		if i >= len(p) {
			return "invalid string"
		}
		w.WriteRune('a' + rune(p[i]))
	}
	return w.String()
}
