#!/usr/bin/env ruby

=begin

You should write a program or function which given a starting order of distinct one-digit positive integers and the length of the track as input outputs or returns the finish order of the numbers.

The input [5,1,2,6,7] and 14 defines the following race:

--------------
76215 ->
--------------
Rules of the race
The track wraps around and digits can go multiple laps.
Order of steps is cyclic and based on the starting position. In our example 5 1 2 6 7 5 1 2 ....
There can be no multiple digits in the same position.
Every digit has a speed of digit_value cell per step. Overtaking a digit or a continuous block of digits costs one extra step. If the digit doesn't have the necessary speed for that it will stop before the (block of) digit(s). Examples:

[41   ] => [ 1 4 ]  4 overtakes 1

[2 1  ] => [ 21  ]  2 can only move 1 as it can't move 3 to overtake 1

[4 12 ] => [ 412 ]  4 can only move 1 as it can't move 5 to overtake 12     

[   3 ] => [ 3   ]  3 starting a new lap
Every digit has to go digit_value laps before it finishes. A lap is completed when the last cell of the track is left. A finished digit is removed from the track.

Note that a digit might reach its starting position multiple times through a step and complete multiple laps.
Input
A list of distinct one-digit positive integers (1..9) with at least one element and a single positive integer, greater than the length of the list, the length of the track.
Output
A list of digits in the order they finished in any unambiguous format.
Examples
A visual step-by-step example for the input starting_order = [5,9,2] and length = 6

295   | Start position
29   5| digit 5 moves
2  9 5| digit 9 moves, finishing lap #1
  29 5| digit 2 moves
 529  | digit 5 moves, finishing lap #1
 52  9| digit 9 moves, finishing lap #2
 5  29| digit 2 moves
   529| digit 5 moves
 9 52 | digit 9 moves, finishing laps #3 and #4
29 5  | digit 2 moves, finishing lap #1
29   5| digit 5 moves
2  9 5| digit 9 moves, finishing lap #5
  29 5| digit 2 moves
 529  | digit 5 moves, finishing lap #2
 52  9| digit 9 moves, finishing lap #6
 5  29| digit 2 moves
   529| digit 5 moves
 9 52 | digit 9 moves, finishing laps #7 and #8
 9 5  | digit 2 moves, finishing lap #2 --> remove 2 from the track
59    | digit 5 moves, finishing lap #3
5     | digit 9 moves, finishing lap #9 --> remove 9 from the track
     5| digit 5 moves
    5 | digit 5 moves, finishing lap #4
      | digit 5 moves, finishing lap #5 --> remove 5 from the track
------
Finish order: 2 9 5
Examples in format Input => Output

[3], 2  =>  [3]

[9, 5], 3  =>  [9, 5]

[5, 9, 2], 6  =>  [2, 9, 5]

[5, 9, 2], 10  =>  [5, 9, 2]

[5, 7, 8, 1, 2], 10  =>  [1, 5, 7, 8, 2]

[5, 1, 6, 8, 3, 2], 17  =>  [1, 6, 8, 2, 3, 5]

[1, 2, 3, 7, 8, 9], 15  =>  [1, 7, 8, 9, 2, 3]

[9, 8, 7, 3, 2, 1], 15  =>  [8, 7, 9, 1, 2, 3]

[1, 2, 3, 4, 5, 6, 7, 8, 9], 20  =>  [1, 2, 3, 4, 5, 6, 7, 8, 9]

[9, 8, 7, 6, 5, 4, 3, 2, 1], 20  =>  [8, 7, 5, 9, 6, 1, 2, 4, 3]
This is code-golf so the shortest entry wins.

=end

# Ported from @Cristian Lupascu solution
F =-> digits, length {
  digit_positions = digits.map.with_index{|d,i|[d,digits.size-i-1] }
  result = []
  digits.cycle.map{|n|
    break if digit_positions==[]
    crt = digit_positions.find{|x,_|x==n}
    next unless crt

    steps_left = n
    pos = crt[1]
    taking_over = false

    while steps_left > 0
      other_pos = (digit_positions-[crt]).map{|_,p|p%length}

      steps_left-=1
      pos += 1

      if other_pos.include? (pos%length)
        steps_left -= 1 unless taking_over
        taking_over = true
      else
        taking_over = false
        crt[1] = pos
      end
    end

    if crt[1] >= n*length
      digit_positions.delete(crt)
      result<<n
    end
  }
  result
}

p F[[3], 2]
p F[[9, 5], 3]
p F[[5, 9, 2], 6]
p F[[5, 9, 2], 10]
p F[[5, 7, 8, 1, 2], 10]
p F[[5, 1, 6, 8, 3, 2], 17]
p F[[1, 2, 3, 7, 8, 9], 15]
p F[[9, 8, 7, 3, 2, 1], 15]
p F[[1, 2, 3, 4, 5, 6, 7, 8, 9], 20]
p F[[9, 8, 7, 6, 5, 4, 3, 2, 1], 20]
