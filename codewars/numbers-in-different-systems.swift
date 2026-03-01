/*

Translate number to the selected number system. If the number consists just of digits - return number, else - return string.

  SysNums(5,2) // 101
  SysNums(5,8) // 5
  SysNums(250,2) // 11111010
  SysNums(250,16) // "fa"

#####Hint: System can be 2, 8, 10, 16.

*/

func sysnums(_ n: UInt, _ b: Int) -> String {
    return String(n, radix: b)
}

assert(sysnums(5, 2) == "101")
assert(sysnums(5, 8) == "5")
assert(sysnums(250, 2) == "11111010")
assert(sysnums(250, 16) == "fa")
