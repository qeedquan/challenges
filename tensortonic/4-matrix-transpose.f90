! Implement the transpose of a matrix, where each element at position (i, j) is swapped to (j, i).
!
! Mathematical Definition
!
! Transpose Operation:
! (A^T)[ji] = A[ij]
!
! An n×m matrix becomes an m×n matrix.
!
! Function Arguments
! A is a two-dimensional Python list of shape (N, M) representing the input matrix
!
! Examples
! Input: A = [[1, 2, 3], [4, 5, 6]]
!
! Output: [[1, 4], [2, 5], [3, 6]]
!
! Input: A = [[1, 2], [3, 4]]
!
! Output: [[1, 3], [2, 4]]
!
! Input: A = [[1, 2, 3, 4]]
!
! Output: [[1], [2], [3], [4]]
!
! Hint 1
! Hint 2
! Requirements
! Return a new NumPy array of shape (M, N)
! Must not modify the original matrix
! Must work for non-square, rectangular matrices
! Do not use .T or np.transpose()
! Use manual indexing with loops or array operations
! Constraints
! 1 ≤ N, M ≤ 1000
! Matrix elements can be any float or int
! Time limit: 200ms

program transpose_program
    implicit none
    integer :: A1(2, 3), B1(3, 2)
    integer :: A2(2, 2), B2(2, 2)
    integer :: A3(1, 4), B3(4, 1)

    A1 = reshape([1, 4, 2, 5, 3, 6], [2, 3])
    A2 = reshape([1, 2, 3, 4], [2, 2])
    A3 = reshape([1, 2, 3, 4], [1, 4])

    B1 = transpose(A1)
    B2 = transpose(A2)
    B3 = transpose(A3)
end program transpose_program
