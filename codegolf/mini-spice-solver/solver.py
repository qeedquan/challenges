#!/usr/bin/env python3

"""

SPICE is an electrical circuit simulation program originating from UC Berkeley. Your goal is to implement a minimalistic version which can solve for the nodal voltages and branch currents of a circuit composed of resistors and DC current sources.

Input Format
The input may come from a file, io stream, or the nearest equivalent in your language of choice. However, it cannot be a function input or hard-coded string. The format should be a subset of what the original SPICE used. A quick summary of what is required for the input format:

First line is a title line
Following the title is the description of circuit components and their connectivity. This may be in any order (i.e. you can't assume all resistors come before current sources/vice-versa). See component descriptors below for how component descriptions are formatted.
Following the circuit components is the command control block. The only solver you need to implement is the DC operating point solver (.OP)
Following the command control block are the values to output (nodal voltages/branch currents). See output descriptors below for how these should be formatted.
The last line is .END (you may choose whether an ending carriage return is required or optional)
Any line beginning with * denotes a comment and must be skipped by your parser.
Component Descriptors
All component descriptors are in the form:

XN A B C
Where:

X is R for resistor or I for a current source
XN is the name of the component. N may be any alphanumeric sequence.
A is a non-negative integer indicating which node the positive terminal for the component is connected.
B is a non-negative integer indicating which node the negative terminal for the component is connected.
C is a decimal value (for a resistor this is the resistance, and for a current source this is the current from this source)
By convention, node 0 is considered ground and is at 0V. All other nodal voltages are referenced from ground.
By convention, positive current flows from the positive terminal to the negative terminal.
Output descriptors
The only output format you need to support is .PRINT. This may output to a file, output stream, or the nearest equivalent in your language of choice. It may not be just a function return string.

Format of .PRINT statements:

.PRINT X(N)
X is V for printing a nodal voltage or I for printing the current through a component.
N is the name of the quantity being outputted. For a nodal voltage, this is any non-negative number. For a current, this is the component name.
For each print statement, you should output the argument and the appropriate value v:

X(N) v
You may print the output in any order so long as there's one output per line.

Things you don't have to support
Subcircuits
"Line continuations" (i.e. any lines starting with a +)
"SI" suffixes (e.g. 1k instead of 1000). However, your code should be able to handle decimal input (you may specify the format)
Error handling (i.e. you may assume the input is properly formatted and has a unique solution)
You may specify any case requirements (all upper case, all lower case, case insensitive, case sensitive, etc.)
You may choose to require that the nodes may be ordered sequentially without skipping any integers.
You may use any solver algorithm you want.
Scoring and Misc.
This is code golf, shortest code in bytes wins.
You may use any libraries you wish provided it wasn't designed specifically for handling circuits. Ex.: Using BLAS/LAPACK for matrix math is ok, but you can't use Ngspice because it is a SPICE circuit simulator already.
Any other standard loop holes are prohibited.
For guidance on how to implement a solver, here's a quick guide on modified nodal analysis. Note that because there are no voltage sources you can implement only the basic nodal analysis part (I link this resource because it has some good insights on how to implement such a solver). Additional resources on MNA and another another approach, sparse tableau analysis, can be found here.
Example inputs and expected outputs
Ex. 1
Example 1
* this is a comment
R1 1 0 1
I1 0 1 1
.OP
.PRINT I(R1)
.PRINT V(1)
.END
Output:

I(R1) 1
V(1) 1
Ex. 2
Example 2
I1 1 0 1
* this is a comment
R1 1 0 1
.OP
.PRINT V(0)
.PRINT I(R1)
.PRINT I(I1)
.PRINT V(1)
.END
Output:

V(0) 0
I(R1) -1
I(I1) 1
V(1) -1
Ex. 3
Example 2
ISINK 1 0 1.0
ISOURCE 0 2 2
R1 1 0 10
R2 1 2 1
.OP
.PRINT V(1)
.PRINT V(2)
.PRINT I(R1)
.PRINT I(ISOURCE)
.PRINT I(R2)
.END
Output:

V(1) 10
V(2) 12
I(R1) 1
I(ISOURCE) 2
I(R2) -2

"""

import sys

"""

Ported from @matteo_c solution

Generates a MiniZinc constraint file to pass to the MiniZinc solver

https://www.minizinc.org/

What is MiniZinc?
Minizinc is a constraint programming modelling language; the homonymous command line tool compiles the model, runs a solver, and outputs the solution in the desired format. It is not a proper programming language (since it is not Turing complete), but it can be considered a library since one could replace it by using its proper native python interface.

How it works
The Python code just handles the input format, translating it into a MiniZinc model. The model imposes the following constraints:

the voltage of node 0 must be 0;
Kirchhoff's current law must be respected in all nodes;
Ohm's law must be respected in all resistors.
Here's an ungolfed version of the MiniZinc model (without the actual parameters):

% n is the number of nodes (excluding the ground node)
% m is the number of edges (resistors and current sources)

array[0..n] of var float: voltage;
array[1..m] of var float: current;

array[1..m] of 0..n: start; % the first  node of each edge
array[1..m] of 0..n: end;   % the second node of each edge

enum T = {R, I}; % the two types of edge: resistors and current sources

array[1..m] of T: t; % the type of each edge
array[1..m] of float: x; % the value (resistance or current) associated with each edge

% 0 is ground
constraint volt[0]=0;

% source current is equal to current
constraint forall (i in 1..m where t[i]==I) (x[i] == current[i]);

% V = R * I
constraint forall (i in 1..m where t[i]==R) (voltage[start[i]] - voltage[end[i]] = x[i] * current[i]);

% sum of currents is zero
constraint forall (j in 0..n)
  ( sum([current[i] | i in 1..m where start[i]==j]) ==
    sum([current[i] | i in 1..m where end[i]==j]));

"""

lines = sys.stdin.readlines()[1:]
records = [line.split() for line in lines]
rows = [
    fields
    for line, fields in zip(lines, records)
    if line[0] not in ".*"
]

columns = list(zip(*rows))
if len(columns) == 0:
    sys.exit(0)

types = [value[0] for value in columns[0]]
starts, ends = columns[1], columns[2]
values = columns[3]

items = []
for line in lines:
    if line[:2] != ".P":
        continue

    name = line[7:-1]
    index = line[9:-2]

    component = "voltage"
    if line[7] == "I":
        index = str(columns[0].index(index) + 1)
        component = "current"
    items.append(f'"{name} \\({component}[{index}])\\n"')

print('output[')
for i in range(len(items)):
    print(items[i], end='')
    if i+1 < len(items):
        print(",")
print()
print('];')

print()
print(f"int: m = {len(types)};")
print(f"int: n = {max(map(int, starts + ends))};")

print("""
% n is the number of nodes (excluding the ground node)
% m is the number of edges (resistors and current sources)

array[0..n] of var float: voltage;
array[1..m] of var float: current;

array[1..m] of 0..n: start; % the first  node of each edge
array[1..m] of 0..n: end;   % the second node of each edge

enum T = { R, I }; % the two types of edge: resistors and current sources

array[1..m] of T: t;     % the type of each edge
array[1..m] of float: x; % the value (resistance or current) associated with each edge

% 0 is ground
constraint voltage[0] = 0;

% source current is equal to current
constraint forall (i in 1..m where t[i] == I) (x[i] == current[i]);

% V = R * I
constraint forall (i in 1..m where t[i] == R) (voltage[start[i]] - voltage[end[i]] = x[i] * current[i]);

% sum of currents is zero
constraint forall (j in 0..n)
  ( sum([current[i] | i in 1..m where start[i] == j]) ==
    sum([current[i] | i in 1..m where end[i] == j]));
""")

for name, column in zip(("start", "end", "t", "x"), (starts, ends, types, values)):
    print(f"{name} = [{', '.join(column)}];")
