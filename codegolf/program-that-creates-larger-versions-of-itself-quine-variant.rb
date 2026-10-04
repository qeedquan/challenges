#!/usr/bin/env ruby

=begin

You are to write a program that will output source code that is

Larger than the original program (character wise)
Will print another program larger than itself when run (i.e. the new program is also a valid answer to this challenge) indefinitely
This is code-golf, so shortest answer wins.

=end

=begin

Ported from @daniero solution

The number of times that puts-line is printed grows exponentially.

$ ruby quine.rb | ruby | ruby
puts <<3*3,3
puts <<3*3,3
puts <<3*3,3
puts <<3*3,3
puts <<3*3,3
puts <<3*3,3
puts <<3*3,3
puts <<3*3,3
puts <<3*3,3
puts <<3*3,3
puts <<3*3,3
puts <<3*3,3
puts <<3*3,3
puts <<3*3,3
puts <<3*3,3
3

$ ruby quine.rb | ruby | ruby | ruby | ruby | ruby | ruby | ruby | wc -l
    3283

=end

puts <<3*3,3
puts <<3*3,3
3
