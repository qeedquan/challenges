#!/usr/bin/env julia

#=

The gravitational force between two objects is given by the formula

F=G*m1*m2/r^2 where G is the gravitational constant while the variables in the numerator represent the masses of the two objects. Your function declaration should be:

double gravitational_force( double mass_1, double position_1[3],
                            double mass_2, double position_2[3] );

The position vectors give two points in 3-dimensional space, and the distance between these two points is the quantity r in the formula.

If either mass is negative, throw a std::domain_error exception.

Your documentation should be clear as to the units of each of the parameters and the units of the return value.

Write a similar function, but now for Coulomb's law:

F=ke*q1*q2/r^2 where ke is Coulomb's constant where the variables in the numerator represent the charge on each of the two objects. Your function declaration should be:

double coulombs_law( double charge_1, double position_1[3],
                     double charge_2, double position_2[3] );

Again, you should document the units of the parameters and the return value.

=#

using LinearAlgebra

function inverse_square_law(K, k1, position_1, k2, position_2)
	d = position_2 - position_1
	r = sqrt(dot(d, d))
	return (K * k1 * k2) / r^2
end

function gravitational_force(mass_1, position_1, mass_2, position_2)
	G = 6.6743015e-11
	return inverse_square_law(G, mass_1, position_1, mass_2, position_2)
end

function coulombs_force(charge_1, position_1, charge_2, position_2)
	Ke = 8.98755172314e9
	return inverse_square_law(Ke, charge_1, position_1, charge_2, position_2)
end

println(gravitational_force(7.5, 60000, 70, 0))
println(gravitational_force(7.5, [1, 2, 3], 70, [4, 5, 6]))
println(coulombs_force(7.5, 60000, 70, 0))
println(coulombs_force(7.5, [1, 2, 3], 70, [4, 5, 6]))
