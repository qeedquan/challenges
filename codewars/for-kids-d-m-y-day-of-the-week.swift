/*

#~For Kids Challenges~#
Your task is easy, write a function that takes an date in format d/m/Y(String) and return what day of the week it was(String).
Example: "21/01/2017" -> "Saturday", "31/03/2017" -> "Friday"

Have fun!

*/

import Foundation

func weekday(_ date: String) -> String {
    let formatter = DateFormatter()
    formatter.dateFormat = "d/MM/yyyy"

    let date = formatter.date(from: date)
    if date == nil {
        return ""
    }

    let weekday = Calendar.current.component(.weekday, from: date!)
    return formatter.weekdaySymbols[weekday - 1]
}

assert(weekday("21/01/2017") == "Saturday")
assert(weekday("31/03/2017") == "Friday")
