%{

The goal of this challenge is to create a program that takes in a matrix and outputs its reduced row-echelon form.

A matrix is in reduced row-echelon form if it meets all of the following conditions:

If there is a row where every entry is zero, then this row lies below any other row that contains a nonzero entry.
The leftmost nonzero entry of a row is equal to 1.
The leftmost nonzero entry of a row is the only nonzero entry in its column.
Consider any two different leftmost nonzero entries, one located in row i, column j and the other located in row s, column t. If s>i, then t>j.
Source

The general process to transform the matrix is:

Deal with each row i from 1 to n in turn, and work across the columns j from 1 to m skipping any column of all zero entries.
Find the next column j with a nonzero entry.
Interchange rows, if necessary, so that the pivot element A(i,j) is nonzero.
Make the pivot equal to 1 by dividing each element in the pivot row by the value of the pivot.
Make all elements above and below the pivot equal to 0 by subtracting a suitable multiple of the pivot row from each other row.
Repeat for all rows.
If you want to read more on this type of matrix, view the Wikipedia article on it and a tool and article(steps above) that shows the steps to transform the matrix.

As for the actual challenge, here it goes:

The input can be given in any way you wish through STDIN or equivalent, just please explain it in your answer. The output will be the reduced row-echelon form of the input in the same form as the input through STDOUT or equivalent. Standard loopholes are not allowed and external libraries or functions that do this task are also not allowed (TI-BASIC's rref( command, for example). You may write a full program or function. This is code golf, lowest BYTES wins. Good luck!

Example Input: [[2,1,1,14][-1,-3,2,-2][4,-6,3,-5]]

Example Output: [[1,0,0,1][0,1,0,5][0,0,1,7]]

%}

rref([[2, 1, 1, 14]; [-1, -3, 2, -2]; [4, -6, 3, -5]])
