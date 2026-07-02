/*

Fix this function so that it correctly outputs a list of the next five days (starting after the input date). Each date should be in the format M/D/YYYY. i.e. March 12th 2013 would be 3/12/2013.

Example output: "3/14/2013, 3/15/2013, 3/16/2013, 3/17/2013, 3/18/2013"

There's a hard way to do this and there's a right way.

*/

import Foundation

func dates(_ date: Date) -> String {
    let formatter = DateFormatter()
    formatter.dateFormat = "M/d/yyyy"

    var result = ""
    for day in 0..<5 {
        let current = Calendar.current.date(byAdding: .day, value: day, to: date)!
        let string = formatter.string(from: current)
        result += string
        if day < 4 {
            result += ", "
        }
    }
    return result
}

print(dates(Date()))
