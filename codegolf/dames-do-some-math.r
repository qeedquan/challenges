#!/usr/bin/env Rscript

# The order of operations, PEMDAS, is a basic rule in mathematics telling us which order operations should be performed:
#
# "Parentheses, Exponents, Multiplication and Division, and Addition and Subtraction"
#
# The problem is, PEMDAS is not very versatile! What if you wanted to do it in another order? We won't mess with the parentheses, so we keep them where they are (first).
#
# Create a program that takes two arguments:
#
# A string, telling which order the operations should follow. Some examples are "DAMES", "SAD, ME", "ME SAD", "MEADS". Yes, spaces and commas are OK, as it makes the order easier to remember.
# Following suggestions in chat: Supporting spaces and commas is now optional.
# If one of the letters is missing, or if there are additional letters that shouldn't be there, you can consider the input invalid and treat it however you like.
# A string, or an expression containing the expression that should be evaluated.
# Return the result of the expression as either a decimal number, or an integer. If the answer is not an integer, it has to be returned as a decimal number.
#
# Rules:
#
# It's OK to combine the two input arguments into one, if that's easier in your language.
# It doesn't have to be a string, but it has to have letters. You can't substitute Addition with 1, Division with 2, etc.
# You can choose which input is first.
# The expression is evaluated right to left left to right. (Change of rule. Any submissions poster the first 12 hours that have this the other way around are accepted).
# The operations use the symbols: ( ) ^ * / + -. For instance, you can't use ¤ instead of + for addition.
# Spaces in the input expression is not valid as input
# Unary +/- is not valid as input if it directly follows + or -. Consider 3+-2 as invalid input. It can be treated however you like (doesn't have to produce an error). If + or - follows any other operator than plus or minus, it's treated the usual way: 3*-3 = -9, sin(-2)=-0.909
# The program must strictly follow the letters, so "EMDAS", 1-3+4 => -6, and "EMDSA", 1-3+4 => 2.
# Examples:
#
# Input:   "EMDAS", "3+6*2/4-1"   // -> 3+12/4-1 -> 3+3-1 -> 6-1 -> 5
# Output:  5
#
# Input:   "DAMES", "3+6*2/4-1"   // -> 3+6*0.5-1 -> 9*0.5-1 -> 4.5-1 -> 3.5
# Output:  3.5
#
# Input:   "SAD, ME", "3+6*2/4-1"  // -> 3+6*2/3 -> 9*2/3 -> 9*0.66667 -> 6
# Output:  6
#
# Input:   "ME ADS", "3+5^4/2-3*2 // -> 3+5^4/2-6 -> 3+625/2-6 -> 628/2-6 -> 314-6 -> 308
# Output:  308
#
# Input:   "AM EDS", "4*3-sin(0.5^2)*3+1" // -> 4*3-sin(0.5^2)*4 -> 12-sin(0.5^2)*4 -> 4*3-(4*sin(0.5^2)) -> 12-(4*sin(0.5^2)) -> 12-(4*sin(0.25)) -> 12-(4*0.24740) -> 12-0.98961 -> 11.01038
# Output:  11.01038
#
# Input:   "DAMES", "4-5-6"   // -> (4-5)-6 -> = -7
# Output:  -7                  // NOT: -> 4-(5-6) -> 4-(-1) -> 5
# Note, the parentheses where added to show that the multiplication 4*sin(0.5^2) is evaluated before the exponentiation.
#
# This is code golf, so the shortest code in bytes win.

# @Patrick Roocks
# The idea is to "misuse" the non-arithmetic operators <, &, |, ~, ? where we know the precedence (see ?Syntax in R - but before the override ;))
# and overriding them with the given arithmetic operators. The mapping is according to the desired order of operations.
#
# Spaces and commas in the input are not supported.

f = function(a,b) {
	ops = list(E = '^', M = '*', D = '/', A = '+', S = '-')
	rep = "<&|~?"
	for (i in 1:5) {
		x = substr(rep, i, i)
		y = ops[[substr(a, i, i)]]
		assign(x, .Primitive(y))
		b = gsub(y, x, b, , , T)
	}
	eval(parse(text = b))
}

f("EMDAS", "3+6*2/4-1")
f("DAMES", "3+6*2/4-1")
f("SADME", "3+6*2/4-1")
f("MEADS", "3+5^4/2-3*2")
f("AMEDS", "4*3-sin(0.5^2)*3+1")
f("DAMES", "4-5-6")

