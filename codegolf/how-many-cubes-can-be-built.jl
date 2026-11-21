#!/usr/bin/env julia

#=

task
Your task is to build a structure with n cubes. The volume of cubes follow the following sequence (bottom -> top)

n^3, (n-1)^3, (n-2)^3, ..., 1^3

input
The total volume of the structure (V).

output
value of (n), i.e : The total number of cubes.

V=n^3+(n-1)^3+....+1^3

notes
Input will always be an integer.
Sometimes it isn't possible to follow the sequence, i.e : V doesn't represent a specific value for n.
In that event return -1, or a falsy value of your choosing (consistency is required though).
This is code-golf so shortest answer in bytes for each language wins.
No answer will be marked accepted for the above mentioned reason.
requests
This is my first challenge on the site so bear with me, and forgive (and tell me about) any mistakes that I made.
Kindly provide a link so your code can be tested.
If you can, kindly write an explanation on how your code works, so others can understand and appreciate your work.

examples
input  : 4183059834009
output : 2022

input  : 2391239120391902
output : -1

input  : 40539911473216
output : 3568

Thanks to @Arnauld for the link to this :
https://upload.wikimedia.org/wikipedia/commons/thumb/2/26/Nicomachus_theorem_3D.svg/1024px-Nicomachus_theorem_3D.svg.png

=#

#=

@Arnauld

How?

The sum Sn of the first n cubes is given by:
Sn = ((n^2 + n)/2)^2

(This is A000537. This formula can easily be proved by induction. Here is a nice graphical representation of S5.)

Reciprocally, if v is the sum of the first x cubes, the following equation admits a positive, integer solution:

((x^2 + x)/2)^2 = v

Because (x^2+x)/2 is positive, this leads to:
x^2 + x - 2sqrt(v) = 0

Whose positive solution is given by:

d = 1 + 8sqrt(v)
x = (-1 + sqrt(d)) / 2

If r = sqrt(d) is an integer, it is guaranteed to be an odd one, because d itself is odd.
Therefore, the solution can be expressed as:
x = floor(r/2)

=#

function cubes(v)
	d = (1 + 8*sqrt(v))
	s = sqrt(d)
	if !isinteger(s)
		return -1
	end

	return Int(floor(s/2))
end

@assert(cubes(4183059834009) == 2022)
@assert(cubes(2391239120391902) == -1)
@assert(cubes(40539911473216) == 3568)
