/*

Create a function that accepts a number n as a parameter and returns true if the number is even and false if the number is odd.

Notes:
```javascript 1 <= n <= 1000 ``` The length of your code must be less than or equal to 19 characters.
You are not allowed to use %.

*/

func evenCheck(_ n: Int) -> Bool {
    return (n & 1) == 0
}

for i in 0...10 {
    if evenCheck(i) {
        print(i)
    }
}
