#!/usr/bin/env julia

#=

The problem is the title of the post. You may use any language and built-in library the language supports.

immediately I think of Julia because it has many constant defined in it's standard library. However, the solution I came up with: setprecision(9000)print(string(BigFloat(MathConstants.γ))[1:1002]) pale in comparison to the solution other came up with. I really don't know what could be further optimized. Please help.

=#

setprecision(9000)
println(string(BigFloat(MathConstants.γ))[1:1002])
