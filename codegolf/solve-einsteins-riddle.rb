#!/usr/bin/env ruby

=begin

Einstein wrote a riddle. He said that 98% of the world could not solve it.

I solved this riddle in about 25 minutes while on the train to work. It's basically just deduction.

The riddle
There are 5 houses in 5 different colors in a row.
In each house lives a person with a different nationality.
The 5 owners drink a certain type of beverage, smoke a certain brand of cigar, and keep a certain pet.
No owners have the same pet, smoke the same brand of cigar, or drink the same beverage.
Question: Who owns the fish?

To solve this riddle Einstein provides 15 hints:

The Brit lives in the red house.
The Swede keeps dogs as pets.
The Dane drinks tea.
The green house is on the immediate left of the white house.
The green house's owner drinks coffee.
The owner who smokes Pall Mall rears birds.
The owner of the yellow house smokes Dunhill.
The owner living in the center house drinks milk.
The Norwegian lives in the first house.
The owner who smokes Blends lives next to the one who keeps cats.
The owner who keeps the horse lives next to the one who smokes Dunhill.
The owner who smokes Bluemasters drinks beer.
The German smokes Prince.
The Norwegian lives next to the blue house.
The owner who smokes Blends lives next to the one who drinks water.
With these hints you can come to a solution.

Your task: Make a program that will solve this riddle for you. Hard coding the solution isn't allowed (duh)

It is allowed to hardcode the hints in any format.
Example format:

//Hints in order
(Nationality:Brit)==(Color:Red)
(Nationality:Swede)==(Pet:Dogs)
(Nationality:Dane)==(Drink: Tea)
(Color:Green)/(Color:White)
(Color:Green)==(Drink:Coffee)
(Smoke:PallMall)==(Pet:Birds)
(Color:Yellow)==(Smoke:Dunhill)
(House:3)==(Drink:Milk)
(Nationality:Norwegian)==(House:1)
(Smoke:Blend)/\(Pet:Cats)
== means equals to
/ means on left side of
\ means on right side of
/\ means left or right of

Like I said its allowed to either hardcode hints or have them as input.

Output: Output should be in the following format (With the correct values, just saying for the trolls ;) )

 _____________    _____________    _____________    _____________    _____________
|   Number    |  |   Number    |  |   Number    |  |   Number    |  |   Number    |
| Nationality |  | Nationality |  | Nationality |  | Nationality |  | Nationality |
|    Color    |  |    Color    |  |    Color    |  |    Color    |  |    Color    |
|    Drink    |  |    Drink    |  |    Drink    |  |    Drink    |  |    Drink    |
|    Smoke    |  |    Smoke    |  |    Smoke    |  |    Smoke    |  |    Smoke    |
|     Pet     |  |     Pet     |  |     Pet     |  |     Pet     |  |     Pet     |
---------------  ---------------  ---------------  ---------------  ---------------

The <Nationality> in the <Color> house owns the fish!
Ascii art boxes can be changed by you, as long as they are boxes, doesn't matter what symbols you use.

Any knowledge on this riddle and solution can not be used in the program. It should use pure logic and deduction to solve the riddle.

Tagged this as a codegolf but might be a code challenge, not sure. Any thoughts on winning criteria for a code challenge feel free to share :)

For now this is code-golf so the program with the lowest bytecount wins.

Good luck and Happy coding :)

=end

# Ported from @seanh solution

@colors        = [:white, :yellow, :blue, :red, :green].shuffle.permutation
@cigars        = [:blends, :pall_mall, :prince, :bluemasters, :dunhill].shuffle.permutation
@nationalities = [:german, :swedish, :british, :norwegian, :danish,].shuffle.permutation
@drinks        = [:beer, :water, :tea, :milk, :coffee].shuffle.permutation
@pets          = [:birds, :cats, :horses, :fish, :dogs].shuffle.permutation

def next_to?(set_a, val_a, set_b, val_b)
    left_of?(set_a, val_a, set_b, val_b) ||
    left_of?(set_b, val_b, set_a, val_a)
end

def left_of?(set_a, val_a, set_b, val_b)
    (0..4).any? do |i|
      set_a[i]   == val_a &&
      set_b[i+1] == val_b
    end
end

def implies?(set_a, val_a, set_b, val_b)
    (0..4).any? do |i|
      set_a[i] == val_a &&
      set_b[i] == val_b
    end
end

def solve
    i = 0
    @colors.each do |colors|
      i += 1
      next unless left_of?(colors, :green, colors, :white)
      @nationalities.each do |nationalities|
        i += 1
        next unless implies?(nationalities, :british, colors, :red)
        next unless nationalities[0] == :norwegian
        next unless next_to?(nationalities, :norwegian, colors, :blue)
        @pets.each do |pets|
          i += 1
          next unless implies?(nationalities, :swedish, pets, :dogs) 
          @drinks.each do |drinks|
            i += 1
            next unless drinks[2] == :milk
            next unless implies?(colors, :green, drinks, :coffee)
            next unless implies?(nationalities, :danish, drinks, :tea)
            @cigars.each do |cigars|
              i += 1
              next unless next_to?(pets, :horses, cigars, :dunhill)
              next unless implies?(cigars, :pall_mall, pets, :birds)
              next unless next_to?(cigars, :blends, drinks, :water)
              next unless next_to?(cigars, :blends, pets, :cats)
              next unless implies?(nationalities , :german, cigars, :prince)
              next unless implies?(colors, :yellow, cigars, :dunhill)
              next unless implies?(cigars, :bluemasters,  drinks, :beer)
              return [colors, nationalities, pets, drinks, cigars], i
            end
          end
        end
      end
    end
end

class Symbol
    def humanize
      result = self.to_s
      result.gsub!('_', ' ')
      result.split(' ').collect{|part| part.capitalize }.join(' ')
    end
end

solution, attempts = solve

puts "\nSolved in #{attempts} attempts.\n\n"

for i in (0..4)
    number, color, nationality, cigar, drink, pet = i+1, solution[0][i], solution[1][i].humanize, solution[4][i].humanize, solution[3][i], solution[2][i]
    puts "House #{number} is #{color}. The owner is #{nationality}, smokes #{cigar}, drinks #{drink}, and keeps #{pet}."
end

puts "\n"
