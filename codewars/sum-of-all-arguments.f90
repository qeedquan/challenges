! Write a function that finds the sum of all its arguments.
!
! eg:
!
! sum(1, 2, 3) // => 6
! sum(8, 2) // => 
! sum(1, 2, 3, 4, 5) // => 15

PROGRAM main
    IMPLICIT NONE
    INTEGER :: array1(3) = (/1, 2, 3/)
    INTEGER :: array2(2) = (/8, 2/)
    INTEGER :: array3(5) = (/1, 2, 3, 4, 5/)
    INTEGER :: sum1
    INTEGER :: sum2
    INTEGER :: sum3

    sum1 = SUM(array1)
    sum2 = SUM(array2)
    sum3 = SUM(array3)
    PRINT *, sum1
    PRINT *, sum2
    PRINT *, sum3
END PROGRAM
