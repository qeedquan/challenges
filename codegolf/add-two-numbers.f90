! Input: Two integers. Preferably decimal integers, but other forms of numbers can be used. These can be given to the code in standard input, as arguments to the program or function, or as a list.
!
! Output: Their sum. Use the same format for output integers as input integers. For example, the input 5 16 would lead to the output 21.
!
! Restrictions: No standard loopholes please. This is code-golf, answer in lowest amount of bytes wins.
!
! Notes: This should be fairly trivial, however I'm interested to see how it can be implemented. The answer can be a complete program or a function, but please identify which one it is.
!
! Test cases:
!
! 1 2 -> 3
! 14 15 -> 29
! 7 9 -> 16
! -1 8 -> 7
! 8 -9 -> -1
! -8 -9 -> -17
! Or as CSV:
!
! a,b,c
! 1,2,3
! 14,15,29
! 7,9,16
! -1,8,7
! 8,-9,-1
! -8,-9,-17

program main
    implicit none

    real :: x1, y1
    real :: x2, y2
    real :: x3, y3
    real :: x4, y4
    real :: x5, y5
    real :: x6, y6

    x1 = 1
    y1 = 2

    x2 = 14
    y2 = 15

    x3 = 7
    y3 = 9

    x4 = -1
    y4 = 8

    x5 = 8
    y5 = -9

    x6 = -8
    y6 = -9

    print *, x1 + y1
    print *, x2 + y2
    print *, x3 + y3
    print *, x4 + y4
    print *, x5 + y5
    print *, x6 + y6
end program
