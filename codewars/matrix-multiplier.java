/*

In mathematics, a matrix (plural matrices) is a rectangular array of numbers. Matrices have many applications in programming, from performing transformations in 2D space to machine learning.

One of the most useful operations to perform on matrices is matrix multiplication, which takes a pair of matrices and produces another matrix – known as the dot product. Multiplying matrices is very different to multiplying real numbers, and follows its own set of rules.

Unlike multiplying real numbers, multiplying matrices is non-commutative: in other words, multiplying matrix a by matrix b will not give the same result as multiplying matrix b by matrix a.

Additionally, not all pairs of matrix can be multiplied. For two matrices to be multipliable, the number of columns in matrix a must match the number of rows in matrix b.

There are many introductions to matrix multiplication online, including at Khan Academy, and in the classic MIT lecture series by Herbert Gross.

To complete this kata, write a function that takes two matrices - a and b - and returns the dot product of those matrices. If the matrices cannot be multiplied, return null/None/Nothing or similar.

Each matrix will be represented by a two-dimensional list (a list of lists). Each inner list will contain one or more numbers, representing a row in the matrix.

For example, the following matrix:

|1 2|
|3 4|

Would be represented as:

[[1, 2], [3, 4]]

It can be assumed that all lists will be valid matrices, composed of lists with equal numbers of elements, and which contain only numbers. The numbers may include integers and/or decimal points.

*/

import java.io.*;
import java.util.*;

class MatrixMultiplier {
	static double[][] matmul(double[][] a, double[][] b) {
		if (a.length == 0 || b.length == 0 || a[0].length == 0 || b[0].length == 0)
			return null;

		var n0 = a.length;
		var n1 = b[0].length;
		var n2 = a[0].length;
		var c = new double[n0][n1];
		for (var i = 0; i < n0; i++) {
			for (var j = 0; j < n1; j++) {
				for (var k = 0; k < n2; k++)
					c[i][j] += a[i][k] * b[k][j];
			}
		}
		return c;
	}

	public static void dump(double[][] m) {
		for (double[] r : m) {
			System.out.println(Arrays.toString(r));
		}
		System.out.println();
	}

	public static void main(String[] args) {
		dump(matmul(new double[][]{{2}}, new double[][]{{3}}));
		dump(matmul(new double[][]{{1, 2}, {3, 4}}, new double[][]{{5, 6}, {7, 8}}));
		dump(matmul(new double[][]{{0.5, 1}, {1.5, 2}}, new double[][]{{0.2, 0.4}, {0.6, 0.8}}));
		dump(matmul(new double[][]{{7, 3}, {2, 5}, {6, 8}, {9, 0}}, new double[][]{{7, 4, 9}, {8, 1, 5}}));
	}
}
