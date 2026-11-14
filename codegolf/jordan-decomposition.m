%{

Important note: Because this challenge only applies to square matrices, any time I use the term "matrix", it is assumed that I am referring to a square matrix. I am leaving off the "square" description for brevity's sake.

Background
Many matrix-related operations, such as computing the determinant, solving a linear system, or extending scalar-valued functions to matrices are made easier by using a diagonal matrix (one whose elements that are not on the main diagonal are 0) that is similar to the original matrix (meaning, for the input matrix A and the diagonal matrix D, there exists some invertible matrix P such that D = P^(-1) * A * P; also, D and A share some important properties, like eigenvalues, determinant, and trace). For matrices with distinct eigenvalues (the roots to the matrix's characteristic polynomial, given by solving det(A-λI) = 0 for λ, where I is the identity matrix with the same dimensions as A), diagonalization is simple: D is a matrix with the eigenvalues on the main diagonal, and P is a matrix formed from eigenvectors corresponding to those eigenvalues (in the same order). This process is called eigendecomposition.

However, matrices with repeated eigenvalues cannot be diagonalized in this manner. Luckily, the Jordan normal form of any matrix can be computed rather easily, and is not much harder to work with than a regular diagonal matrix. It also has the nice property that, if the eigenvalues are unique, then Jordan decomposition is identical to eigendecomposition.

Jordan decomposition explained
For a square matrix A whose eigenvalues all have a geometric multiplicity of 1, the process of Jordan decomposition can be described as such:

Let λ = {λ_1, λ_2, ... λ_n} be the list of eigenvalues of A, with multiplicity, with repeated eigenvalues appearing consecutively.
Create a diagonal matrix J whose elements are the elements of λ, in the same order.
For each eigenvalue with multiplicity greater than 1, place a 1 to the right of each of the repetitions of the eigenvalue in the main diagonal of J, except the last.
The resulting matrix J is a Jordan normal form of A (there can be multiple Jordan normal forms for a given matrix, depending on the order of the eigenvalues).

A worked example
Let A be the following matrix:

A matrix

The eigenvalues of A, with multiplicity, are λ = {1, 2, 4, 4}. By putting these into a diagonal matrix, we get this result:

step 2

Next, we place 1s to the right of all but one of each of the repeated eigenvalues. Since 4 is the only repeated eigenvalue, we place a single 1 next to the first 4:

jordan form

This is a Jordan normal form of A (a single matrix can potentially have several valid Jordan normal forms, but I'm glossing over that detail for the purpose of explanation).

The task
Given a square matrix A as input, output a valid Jordan normal form of A.

The input and output may be in any reasonable format (2D array/list/whatever, list/array/whatever of column or row vectors, a builtin matrix data type, etc.).
The elements and eigenvalues of A will always be integers in the range [-200, 200].
For the sake of simplicity, all of the eigenvalues will have a geometric multiplicity of 1 (and thus the above process holds).
A will at most be a 10x10 matrix and at least a 2x2 matrix.
Builtins that compute eigenvalues and/or eigenvectors or perform eigendecomposition, Jordan decomposition, or any other kind of decomposition/diagonalization are not allowed. Matrix arithmetic, matrix inversion, and other matrix builtins are allowed.

Test cases
[[1, 0], [0, 1]] -> [[1, 1], [0, 1]]
[[3, 0], [0, 3]] -> [[1, 1], [0, 1]]
[[4, 2, 2], [1, 2, 2],[0, 3, 3]] -> [[6, 0, 0], [0, 3, 0], [0, 0, 0]]
[[42, 48, 40, 64, 64], [41, 47, 31, 58, 42], [-55, -47, -27, -74, -46], [-46, -58, -46, -70, -68], [30, 20, 12, 34, 18]] -> [[10, 0, 0, 0, 0], [0, -18, 0, 0, 0], [0, 0, 6, 1, 0], [0, 0, 0, 6, 1], [0, 0, 0, 0, 6]]

%}

% @miles
function r = jordan(a)
	v = round(roots(poly(a)));
	r = diag(1 - sign(diff(v).^2), 1) + diag(v);
end

jordan([1 0; 0 1])
jordan([3 0; 0 3])
jordan([4, 2, 2; 1, 2, 2; 0, 3, 3])
jordan([42, 48, 40, 64, 64; 41, 47, 31, 58, 42; -55, -47, -27, -74, -46; -46, -58, -46, -70, -68; 30, 20, 12, 34, 18])
