# You must write a program to evaluate a string that would be entered into a calculator.
#
# The program must accept input and output the correct answer. For languages that do not have standard input/output functions, you may assume the functions readLine and print.
#
# Requirements
#
# Does not use any kind of "eval" functions
# Can handle floating point and negative numbers
# Supports at least the +, -, *, and / operators
# Can handle input containing one or more spaces between the operators and numbers
# Evaluates the expression from left to right
# The program that is the shortest wins. In the event of a tie, the program that was submitted first wins.
#
# You can assume that the input is valid and follows the correct format
#
#
# Test Cases
# Input
#
# -4 + 5
# Output
#
# 1
# Input
# -7.5 / 2.5
# Output
#
# -3
# Input
# -2 + 6 / 2 * 8 - 1 / 2.5 - 18
# Output
#
# -12

package require Tk
wm title . "Calculator"

entry .e -textvar e -justify right -font {Helvetica 16 bold}
grid .e -columnspan 5 -padx 5 -pady 5 -sticky we

bind .e <Return> {= }

set keys {
    {7 8 9 + -}
    {4 5 6 * /}
    {1 2 3 ( )}
    {C 0 . = }
}

set n 0
set keys_list [list]
foreach row $keys {
    foreach key $row {
        switch -- $key {
            = {set cmd {=}}
            C {set cmd {set clear 1; set e ""}}
            default {set cmd "hit $key"}
        }
        lappend keys_list [button .b[incr n] -text $key -command $cmd -font {Helvetica 12}]
    }
    eval grid $keys_list -sticky we -padx 2 -pady 2
    set keys_list [list]
}

set clear 0

proc hit {key} {
    if {$::clear} {
        set ::e ""
        set ::clear 0
    }
    append ::e $key
}

proc = {} {
    if {[catch {set res [expr [string map {/ *1.0/} $::e]]}]} {
        .e configure -fg red
        set ::res "Error"
    } else {
        .e configure -fg black
        set ::res $res
        set ::e $res
    }
    set ::clear 1
}
