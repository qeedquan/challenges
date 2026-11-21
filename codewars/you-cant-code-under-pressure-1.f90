! Code as fast as you can! You need to double the integer and return it.

program main
  implicit none
  real :: x = 3.5

  print *, x, double(x)

  contains
      function double(x) result (r)
          implicit none
          real, intent(in) :: x
          real             :: r
          r = x * 2
      end function
end program main
