{-

Write a program that will test the primality of a specified number, and give the output as a Boolean value (True is prime). Your prime test can (but doesn't have to) be valid for the number 1.

Here's the catch: your program itself has to sum to a prime number. Convert every character (including spaces) to its Unicode/ASCII value (table). Then, add all those numbers together to get the sum of your program.

For example, take this not-so-great program I wrote in Python 3.3:

q=None
y=int(input())
for x in range(2,int(y**0.5)+1):
    if y%x==0:
        q=False
if not q:
    q=True
print(q)
If you convert all the characters to their corresponding Unicode/ASCII value, you get:

113 61 78 111 110 101 10 121 61 105 110 116 40 105 110 112 117 116 40 41 41 10 102 111 114 32 120 32 105 110 32 114 97 110 103 101 40 50 44 105 110 116 40 121 42 42 48 46 53 41 43 49 41 58 10 32 32 32 32 105 102 32 121 37 120 61 61 48 58 10 32 32 32 32 32 32 32 32 113 61 70 97 108 115 101 10 105 102 32 110 111 116 32 113 58 10 32 32 32 32 113 61 84 114 117 101 10 112 114 105 110 116 40 113 41 
You can then find the sum of those numbers manually or with your own program. This specific program sums to 8293, which is a prime number.

Of course, this is Code Golf, so the smaller you can make your program, the better. As pointed out by other users, this program is not very golfy.

A few rules:

Valid inputs include STDIN and prompts (no functions, it's just a way to add free extra code). Spaces are permitted, but only if they are crucial to the functionality of your program. Output must be an output, not just stored in a variable or returned (use print, STDOUT, etc.)

Flags can be used and should be counted literally, not expanded. Comments are not allowed. As for non-ASCII characters, they should be assigned to the value in their respective encoding.

Make sure to list your program's size and the sum of the program. I will test to make sure programs are valid.

Good luck!

Here is a snippet to count the sum of your program and check if it is prime:

function isPrime(number) { var start = 2; while (start <= Math.sqrt(number)) { if (number % start++ < 1) return false; } return number > 1; } var inp = document.getElementById('number'); var text = document.getElementById('input'); var out = document.getElementById('output'); function onInpChange() { var msg; var val = +inp.value; if (isNaN(val)) { msg = inp.value.toSource().slice(12, -2) + ' is not a valid number.'; } else if (isPrime(val)) { msg = val + ' is a prime number!'; } else { msg = val + ' is not a prime number.'; } out.innerText = msg; } function onTextChange() { var val = text.value; var total = new Array(val.length).fill().map(function(_, i) { return val.charCodeAt(i); }).reduce(function(a, b) { return a + b; }, 0); inp.value = '' + total; onInpChange(); } text.onkeydown = text.onkeyup = onTextChange; inp.onkeydown = inp.onkeyup = onInpChange;

body { background: #fffddb; } textarea, input, div { border: 5px solid white; -webkit-box-shadow: inset 0 0 8px  rgba(0,0,0,0.1), 0 0 16px rgba(0,0,0,0.1); -moz-box-shadow:  inset 0 0 8px  rgba(0,0,0,0.1), 0 0 16px rgba(0,0,0,0.1); box-shadow:  inset 0 0 8px  rgba(0,0,0,0.1), 0 0 16px rgba(0,0,0,0.1);  padding: 15px; background: rgba(255,255,255,0.5); margin: 0 0 10px 0; font-family: 'Roboto Mono', monospace; font-size: 0.9em; width: 75%; }</style><meta charset="utf-8"><style>/**/

<link href="https://fonts.googleapis.com/css?family=Roboto+Mono" rel="stylesheet"><textarea id="input" tabindex="0">Insert your (UTF-8 encoded) code here
Or directly input a number below</textarea><br><input id="number" value="6296" tabindex="1"><br><div id="output">6296 is not a prime number.</div>

-}

{- https://en.wikipedia.org/wiki/Wilson%27s_theorem -}
main = do
    k <- readLn
    print $ product[1..k-1] `rem` k == k-1
